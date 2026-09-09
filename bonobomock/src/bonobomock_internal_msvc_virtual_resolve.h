// SPDX-License-Identifier: Apache-2.0
//
// Copyright 2025 Bloomberg Finance LP
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

// bonobomock_internal_msvc_virtual_resolve.h
//
// Resolve virtual member function pointers to actual function addresses
// under the MSVC ABI (x86-64), covering both MSVC and clang-cl.
//
// Under the MSVC ABI, a pointer-to-member-function (PMF) for a virtual
// function holds the address of a compiler-generated "vcall thunk" rather
// than a vtable offset (as in the Itanium ABI).  The thunk loads the vptr
// from the object and dispatches through the vtable:
//
//   48 8B 01          mov rax, qword ptr [rcx]   ; load vptr from 'this'
//   FF 60 XX          jmp qword ptr [rax + XX]   ; 8-bit vtable byte offset
//   -- or --
//   48 8B 01          mov rax, qword ptr [rcx]
//   FF A0 XX XX XX XX jmp qword ptr [rax + XXXX] ; 32-bit vtable byte offset
//
// To find the vtable byte offset, we scan the thunk for these patterns and
// extract the displacement field.
//
// Limitations:
// - x86-64 only.
// - Single inheritance only.  Multiple and virtual inheritance thunks have
//   additional adjustment instructions and are not handled.
// - Assumes the 'mov rax, [rcx]' + 'jmp [rax+offset]' sequence appears
//   within the first 32 bytes of the thunk.

#ifndef INCLUDED_BONOBOMOCK_INTERNAL_MSVC_VIRTUAL_RESOLVE
#define INCLUDED_BONOBOMOCK_INTERNAL_MSVC_VIRTUAL_RESOLVE

#if !defined(INCLUDED_BONOBOMOCK_API) && !defined(BONOBO_MOCK_BUILDING_LIBRARY)
    #error "This is a private header. Directly including it is a contract violation and undefined behavior."
#endif

#if defined(_MSC_VER) || (defined(__clang__) && defined(_MSC_EXTENSIONS))

    #include <bonobomock_internal_error.h>
    #include <bonobomock_internal_windows_thunk_resolve.h>
    #include <bsl_optional.h>
    #include <bsls_platform.h>
    #include <cstdint>
    #include <cstring>

namespace BloombergLP {
namespace bonobomock {

    // Extract the vtable byte offset from an MSVC-generated vcall thunk.
    //
    // MSVC emits single-inheritance vcall thunks that load the vptr from the
    // object ('this') and then jump through the vtable.  The encoding differs
    // between 32-bit x86 (__thiscall: 'this' in ECX) and 64-bit x86-64
    // (Microsoft x64: 'this' in RCX).
    //
    // x86-64 patterns recognised (48 8B 01 = mov rax, [rcx]):
    //   48 8B 01  FF 20             -> offset 0   (jmp [rax])
    //   48 8B 01  FF 60 XX          -> 8-bit  offset XX
    //   48 8B 01  FF A0 XX XX XX XX -> 32-bit offset XXXX
    //   (optional REX 48 prefix on the JMP is also accepted)
    //
    // x86 (32-bit) patterns recognised (8B 01 = mov eax, [ecx]):
    //   8B 01  FF 20             -> offset 0
    //   8B 01  FF 60 XX          -> 8-bit  offset XX
    //   8B 01  FF A0 XX XX XX XX -> 32-bit offset XXXX
    //
    // Returns the vtable byte offset, or bsl::nullopt if not found within
    // the first 32 bytes of the thunk.
    inline bsl::optional<int32_t> extractVtableOffsetFromMsvcThunk(
        const void* thunkAddr)
    {
        const unsigned char* code = static_cast<const unsigned char*>(thunkAddr);

        for (int i = 0; i < 24; ++i) {
            int movLen = 0;

    #if defined(BSLS_PLATFORM_CPU_X86_64)
            // x86-64: 'mov rax, qword ptr [rcx]' = 48 8B 01
            if (code[i] == 0x48 && code[i + 1] == 0x8B && code[i + 2] == 0x01) {
                movLen = 3;
            }
    #elif defined(BSLS_PLATFORM_CPU_X86)
            // x86-32: 'mov eax, dword ptr [ecx]' = 8B 01
            if (code[i] == 0x8B && code[i + 1] == 0x01) {
                movLen = 2;
            }
    #endif
            if (movLen == 0) {
                continue;
            }

            const unsigned char* jmp = code + i + movLen;

            // Skip optional REX prefix (x86-64 only, redundant but sometimes emitted)
            if (jmp[0] == 0x48) {
                ++jmp;
            }

            // 'jmp [reg]' (no displacement) = FF 20  -> offset 0
            if (jmp[0] == 0xFF && jmp[1] == 0x20) {
                return 0;
            }

            // 'jmp [reg + disp8]' = FF 60 XX
            if (jmp[0] == 0xFF && jmp[1] == 0x60) {
                return static_cast<int32_t>(jmp[2]);
            }

            // 'jmp [reg + disp32]' = FF A0 XX XX XX XX
            if (jmp[0] == 0xFF && jmp[1] == 0xA0) {
                int32_t disp32;
                std::memcpy(&disp32, jmp + 2, sizeof(disp32));
                return disp32;
            }
        }

        return bsl::nullopt;
    }

    // Given a raw member function pointer (as a byte buffer) and a pointer to
    // an existing object of the class, resolve the virtual function to its
    // actual address.
    //
    // Reads the thunk address from the first word of the PMF, parses the thunk
    // to extract the vtable byte offset, then indexes into the object's vtable.
    // Throws if the thunk pattern is not recognised.
    inline void* resolveVirtualFromMsvcPmf(const void* pmfBytes, void* obj)
    {
        // Step 1: Read the thunk address from the first word of the PMF.
        void* thunkAddr;
        std::memcpy(&thunkAddr, pmfBytes, sizeof(thunkAddr));

        // Step 1b: With MSVC incremental linking, the PMF may point to an ILT
        // thunk (a JMP to the real vcall thunk) rather than the vcall thunk
        // directly.  Follow any leading JMP to reach the actual thunk code.
        thunkAddr = resolveJmpThunk(thunkAddr);

        // Step 2: Parse the thunk to extract the vtable byte offset.
        bsl::optional<int32_t> vtableOffset = extractVtableOffsetFromMsvcThunk(thunkAddr);
        if (!vtableOffset.has_value()) {
            throwError("bonobomock is unable to determine the vtable offset for "
                       "the virtual function under the MSVC ABI.  Only "
                       "single-inheritance virtual functions are supported.");
        }

        // Step 3: Read the vptr from the object (vptr is at offset 0).
        void** vtable = *static_cast<void***>(obj);

        // Step 4: Index into the vtable at the byte offset.
        return *reinterpret_cast<void**>(
            reinterpret_cast<char*>(vtable) + vtableOffset.value());
    }

} // namespace bonobomock
} // namespace BloombergLP

#endif // _MSC_VER || clang-cl

#endif // INCLUDED_BONOBOMOCK_INTERNAL_MSVC_VIRTUAL_RESOLVE
