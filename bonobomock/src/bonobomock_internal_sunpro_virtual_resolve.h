// SPDX-License-Identifier: Apache-2.0
//
// Copyright 2026 Bloomberg Finance LP
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

// bonobomock_internal_sunpro_virtual_resolve.h
//
// Resolve virtual member function pointers to actual function addresses
// on the SunPro compiler (SPARC architecture), using only C++03 features.
//
// On SunPro (SPARC), a member function pointer to a virtual function does
// NOT contain a vtable offset (unlike the Itanium ABI). Instead, word[0]
// is the address of a compiler-generated "thunk" -- a small trampoline
// function that loads the vtable from the object, reads the function
// pointer at a hardcoded offset, and jumps to it.
//
// To find the vtable offset, we parse the thunk's SPARC machine code:
//   1. Scan forward for the JMPL instruction (tail-call jump).
//   2. From the JMPL, extract its rs1 field -- the register that holds the
//      function pointer the thunk is jumping to.
//   3. Scan backwards from the JMPL for the ld/ldx instruction that loaded
//      that register. Its simm13 immediate field is the vtable byte offset.
//
// Why we scan backwards instead of reading the instruction immediately
// before the JMPL: SunPro generates two different thunk shapes depending
// on the optimization level.
//
// At -O2 (leaf thunk, no register window):
//     ld   [%o0 + 0x0],  %g5      ; vptr = *this
//     ld   [%g5 + OFFSET], %g4    ; func = vtable[OFFSET]  <-- target
//     jmpl [%g4 + %g0], %g0       ; jump to func
//     nop                          ; delay slot
//
// At -O0 (non-leaf thunk, uses save/restore for register window):
//     save %sp, -0x60, %sp         ; create stack frame + register window
//     mov  %i0, %o0                ; this: input reg -> output reg
//     st   %o0, [%fp + 0x44]       ; spill this
//     ld   [%fp + 0x44], %o0       ; reload this
//     ld   [%o0 + 0x0], %o1        ; vptr = *this
//     ld   [%o1 + OFFSET], %o1     ; func = vtable[OFFSET]  <-- target
//     mov  %o0, %i0                ; pass this to callee  <-- NOT a load!
//     jmpl [%o1 + %g0], %g0        ; jump to func
//     restore                       ; destroy stack frame
//
// In the -O0 case, code[jmpl - 1] is a MOV, not the vtable load. The
// MOV's low bits get misinterpreted as a vtable offset, causing bonobomock
// to patch the wrong vtable slot. By matching the JMPL's source register
// (rs1) against the load's destination register (rd) while scanning
// backwards, we find the correct vtable load in both cases.
//
// The same -O0 non-leaf pattern occurs on both 32-bit and 64-bit SPARC.
//
// Limitations:
// - SPARC V8+ and V9 architectures.
// - Assumes the vtable offset fits in a 13-bit signed immediate
//   (-4096 to +4095 bytes), covering vtables with up to ~512 virtual
//   functions on 64-bit.
// - Only handles single inheritance.
// - C++03 compatible. No C++11 features used.

#ifndef INCLUDED_BONOBOMOCK_INTERNAL_SUNPRO_VIRTUAL_RESOLVE
#define INCLUDED_BONOBOMOCK_INTERNAL_SUNPRO_VIRTUAL_RESOLVE

#if !defined(INCLUDED_BONOBOMOCK_API) && !defined(BONOBO_MOCK_BUILDING_LIBRARY)
    #error "This is a private header. Directly including it is a contract violation and undefined behavior."
#endif

#ifdef __SUNPRO_CC

    #include <bsl_optional.h>
    #include <cstring>
    #include <stdint.h>

    #include <bonobomock_internal_error.h>

namespace BloombergLP {
namespace bonobomock {

    // Extract the vtable byte offset from a SunPro-generated virtual member
    // function thunk by scanning its SPARC instructions for a JMPL (jmp)
    // instruction, then scanning backwards for the load that supplies the
    // jump target register.
    //
    // This function should only be called on addresses that are expected to
    // be compiler-generated thunks for virtual member functions.  If called
    // on a non-thunk address the result is meaningless.
    //
    // Returns the vtable byte offset (e.g., 0x10, 0x18, ...), or
    // bsl::nullopt if no matching JMPL + load pair is found within the
    // first 16 instructions.
    //
    // SPARC instruction field layout (all formats share these top fields):
    //   bits 31-30: op    (operation category)
    //   bits 29-25: rd    (destination register)
    //   bits 24-19: op3   (operation selector within the category)
    //   bits 18-14: rs1   (first source register)
    //   bit  13:    i     (0 = register operand, 1 = 13-bit immediate)
    //   bits 12-0:  simm13 or rs2  (immediate value or second source reg)
    //
    // JMPL instruction (jump-and-link):
    //   op=10 (binary), rd=%g0 (discard return address => plain jump),
    //   op3=111000 (0x38).
    //   Combined mask for "jmpl ..., %g0": 0xFFF80000, value: 0x81C00000.
    //   rs1 tells us which register holds the function pointer to jump to.
    //
    // Load instructions we look for:
    //   op=11 (binary) with i=1 (immediate offset form):
    //     ld  (op3=0x00): 32-bit load, used in 32-bit thunks
    //     ldx (op3=0x0B): 64-bit load, used in 64-bit thunks
    //   rd is the destination register; simm13 is the vtable byte offset.
    //   We match rd == jmpl's rs1 to find the load that feeds the jump.
    inline bsl::optional<int32_t> extractVtableOffsetFromThunk(void* thunkAddr)
    {
        const uint32_t* code = static_cast<const uint32_t*>(thunkAddr);

        // Scan up to 16 instructions (thunks are typically 3-9 instructions).
        // Start at i=1 because we scan backwards from the JMPL.
        for (int i = 1; i < 16; i++) {
            if ((code[i] & 0xFFF80000) != 0x81C00000) {
                continue;
            }

            // Found JMPL to %g0.  Extract rs1: the register that holds the
            // function pointer being jumped to (bits 18-14).
            const uint32_t jmplRs1 = (code[i] >> 14) & 0x1F;

            // Scan backwards for the ld/ldx that loaded jmplRs1.
            // In -O2 thunks this is code[i-1]; in -O0 thunks there is an
            // intervening MOV instruction so we must look further back.
            for (int j = i - 1; j >= 0; --j) {
                const uint32_t insn = code[j];
                const uint32_t op = (insn >> 30) & 0x3; // bits 31-30
                const uint32_t rd = (insn >> 25) & 0x1F; // bits 29-25
                const uint32_t op3 = (insn >> 19) & 0x3F; // bits 24-19
                const uint32_t iBit = (insn >> 13) & 0x1; // bit 13

                // Match: op=11 (load/store category), i=1 (immediate form),
                // op3=0x00 (ld, 32-bit) or 0x0B (ldx, 64-bit),
                // rd matches the jmpl's source register.
                if (op == 3 && iBit == 1 && (op3 == 0x00 || op3 == 0x0B) && rd == jmplRs1) {
                    // Extract simm13 (low 13 bits, sign-extended)
                    int32_t offset = static_cast<int32_t>(insn & 0x1FFF);
                    if (offset & 0x1000) {
                        offset |= static_cast<int32_t>(~0x1FFF);
                    }
                    return offset;
                }
            }

            // JMPL found but no matching load — unexpected thunk shape
            return bsl::nullopt;
        }

        // No JMPL found in the first 16 instructions
        return bsl::nullopt;
    }

    // Given a raw member function pointer (as a byte buffer) and a pointer
    // to an existing object of the class, resolve the virtual function to
    // its actual address.
    //
    // If thunk parsing fails (e.g., did not find the expected pattern),
    // bonobomock throws an error.
    inline void* resolveVirtualFromPmf(const void* pmfBytes, void* obj)
    {
        // Step 1: Read the thunk address from the first word of the PMF.
        void* thunkAddr;
        std::memcpy(&thunkAddr, pmfBytes, sizeof(thunkAddr));

        // Step 2: Parse the thunk to extract the vtable byte offset.
        bsl::optional<int32_t> vtableOffset = extractVtableOffsetFromThunk(thunkAddr);
        if (!vtableOffset.has_value()) {
            throwError("bonobomock is unable to determine the offset of the virtual "
                       "function in the vtable on SunPro compiler.");
        }

        // Step 3: Read the vptr from the object (vptr is at offset 0).
        void** vtable = *static_cast<void***>(obj);

        // Step 4: Index into the vtable at the byte offset.
        void* funcAddr = *reinterpret_cast<void**>(
            reinterpret_cast<char*>(vtable) + vtableOffset.value());
        return funcAddr;
    }

} // namespace bonobomock
} // namespace BloombergLP

#endif // __SUNPRO_CC

#endif // INCLUDED_BONOBOMOCK_INTERNAL_SUNPRO_VIRTUAL_RESOLVE
