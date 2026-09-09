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

#include <bonobomock_internal_error.h>
#include <bonobomock_internal_patch.h>

#include <bsls_compilerfeatures.h>
#include <bsls_platform.h>

#include <bsl_algorithm.h>
#include <bsl_iostream.h>

#ifdef BSLS_PLATFORM_OS_WINDOWS
    #include <windows.h>
#elif defined(BSLS_PLATFORM_OS_UNIX)
    #include <sys/mman.h>
    #include <unistd.h>
#else
    #error "No memory-management headers available -- implemented for Windows and Unix-like OSs only"
#endif

#include <cstddef>
#include <stdint.h>

namespace BloombergLP {
namespace bonobomock {

// Page size is needed to align addresses for memory protection calls during
// binary patching.
#ifdef BSLS_PLATFORM_OS_WINDOWS
    static size_t queryPageSize()
    {
        SYSTEM_INFO si;
        GetSystemInfo(&si);
        return static_cast<size_t>(si.dwPageSize);
    }
    const size_t Patch::s_pageSize = queryPageSize();
#elif defined(BSLS_PLATFORM_OS_UNIX)
    const size_t Patch::s_pageSize = sysconf(_SC_PAGE_SIZE);
#else
    #error "No page size query implemented for this platform"
#endif

    namespace {

        // ===================================================================
        // I-cache flush
        // ===================================================================

        // SPARC may have separate instruction and data caches that can
        // become inconsistent when data writes modify the instruction
        // stream. Without an explicit FLUSH, the CPU can execute stale
        // instructions from the I-cache instead of the patch we just wrote.
        // Ref: SPARC V9 Manual, Section 6.3.1.4 (Separate Instruction
        // Memory), p.75; Section A.20 (FLUSH), p.167; Section H.1.6
        // (Self-Modifying Code), p.309.
        // On x86 the I-cache is coherent with stores, so this is a no-op.
#ifdef BSLS_PLATFORM_CPU_SPARC
        void flushICache(void* addr, size_t len)
        {
            char* p = reinterpret_cast<char*>(addr);
            char* end = p + len;
            for (; p < end; p += 8) {
    #if defined(__SUNPRO_CC)
                asm volatile("flush %0" : : "r"(p) : "memory");
    #elif defined(__GNUC__) || defined(__clang__)
                __asm__ __volatile__("flush %0" : : "r"(p) : "memory");
    #else
        #error "No SPARC I-cache flush implementation for this compiler"
    #endif
            }
        }
#elif defined(BSLS_PLATFORM_CPU_X86) || defined(BSLS_PLATFORM_CPU_X86_64)
    #ifdef BSLS_PLATFORM_OS_WINDOWS
        void flushICache(void* addr, size_t len)
        {
            FlushInstructionCache(GetCurrentProcess(), addr, len);
        }
    #else
        // x86 I-cache is coherent with stores — no flush needed.
        void flushICache(void*, size_t) { }
    #endif
#else
    #error "No I-cache flush strategy implemented for this CPU architecture. " \
           "Check whether this architecture has a coherent I-cache (no-op) " \
           "or requires an explicit flush instruction."
#endif

    } // close unnamed namespace

    // Writes architecture-specific jump sequences into memory buffers.
    // Pure integer/byte math — no platform-specific APIs. All methods
    // compile on every architecture; each is called only from its
    // corresponding Patch::setup() branch.
    struct JumpEncoder {
        // --- Patch sizes ---
        static const size_t SPARC_INSN_BYTES = 4;
        static const size_t SPARC_BA_A_BYTES = 4;
        static const size_t SPARC_ABS_JUMP32_BYTES = 12;
        static const size_t SPARC_ABS_JUMP64_BYTES = 28;
        static const size_t SPARC_CALL_SEQ_BYTES = 12;
        static const size_t X86_JMP_REL32_BYTES = 5;
        static const size_t X86_FAR_JMP_BYTES = 14;
        static const size_t X86_TRAMPOLINE_BYTES = 16;

        // --- Max branch ranges (bytes) ---
        // SPARC branch/call displacement fields are counted in 4-byte
        // words (instructions are fixed-width 32-bit). The ISA encodes
        // target = PC + (4 * sign_ext(disp)), so the max byte range is
        // (2^(N-1) - 1) * 4 where N is the displacement field width.
        //
        // ba,a (Bicc): 22-bit signed disp → max ±(2^21 - 1) words = ±8,388,604 bytes.
        static const int32_t BA_A_MAX_BYTES = 8388604;
        // call: 30-bit signed disp → max ±(2^29 - 1) words = ±2,147,483,644 bytes.
        static const int32_t CALL_MAX_BYTES = 2147483644;

        // --- Max branch ranges (bytes) — x86 ---
        // JMP rel32: 32-bit signed byte displacement → max ±(2^31 - 1) = ±2,147,483,647 bytes.
        static const int32_t REL32_MAX_BYTES = 2147483647;

        // SPARC ba,a (branch always, annulled delay slot).
        // 4 bytes. Branches to 'to' relative to 'from'.
        // Ref: SPARC V9 Manual, Section A.6 (Bicc), p.146 — disp22 field.
        static void encodeSparcBranchAlways(
            uint32_t* target, void* from, void* to)
        {
            intptr_t distance = reinterpret_cast<intptr_t>(to)
                - reinterpret_cast<intptr_t>(from);

            if (distance < -BA_A_MAX_BYTES || distance > BA_A_MAX_BYTES) {
                throwError("bonobomock ERROR: ba,a displacement out of "
                           "22-bit range.");
            }

            // SPARC branch displacements are counted in 4-byte
            // words (instructions are fixed-width). Dividing the
            // byte distance by 4 converts to the word offset that
            // the instruction encodes.
            int32_t disp22 = static_cast<int32_t>(
                distance / static_cast<intptr_t>(SPARC_INSN_BYTES));

            // ba,a: the 22-bit displacement field holds the branch
            // distance in 4-byte words.  & 0x3FFFFF keeps only the
            // low 22 bits of the word offset so it fits the field.
            //
            // Example: distance = 64 bytes → disp22 = 64/4 = 16
            //   16 & 0x3FFFFF = 0x000010
            //   instruction   = 0x30800000 | 0x000010 = 0x30800010
            target[0] = 0x30800000 // ba,a
                | (static_cast<uint32_t>(disp22) & 0x3FFFFF);
        }

        // SPARC 32-bit absolute jump (sethi + jmp + nop). 12 bytes.
        // Ref: SPARC V9 Manual, Section A.48 (SETHI), p.220 — imm22 field.
        // Ref: SPARC V9 Manual, Section A.24 (JMPL), p.172 — simm13 field.
        //
        // Three-instruction absolute jump to a 32-bit address:
        //
        //   1. sethi — loads bits [31:10] of the destination into the
        //      upper 22 bits of register %g1.  >> 10 shifts those bits
        //      down, & 0x3FFFFF keeps only 22 bits (the field width).
        //
        //   2. jmp %g1 + offset — jumps to the address formed by adding
        //      a 10-bit signed offset to %g1.  This offset carries
        //      bits [9:0] of the destination.  & 0x3FF keeps only
        //      those 10 bits.
        //
        //   3. nop — fills the mandatory delay slot (SPARC executes the
        //      instruction after a branch before the branch takes
        //      effect).
        //
        // Example: destAddr = 0xDEADBEEF
        //   sethi field: (0xDEADBEEF >> 10) & 0x3FFFFF = 0x37AB6F
        //     → %g1 = 0x37AB6F << 10 = 0xDEADBC00
        //   jmp   field:  0xDEADBEEF        & 0x3FF    = 0x2EF
        //     → jump target = 0xDEADBC00 + 0x2EF = 0xDEADBEEF
        static void encodeSparcAbsJump32(
            uint32_t* target, uintptr_t destAddr)
        {
            target[0] = 0x03000000 | ((destAddr >> 10) & 0x3FFFFF); // sethi %g1
            target[1] = 0x81C06000 | (destAddr & 0x3FF); // jmp %g1+imm
            target[2] = 0x01000000; // nop (delay slot)
        }

        // SPARC 64-bit absolute jump (7 instructions). 28 bytes.
        // Used as trampoline body.
        // Ref: SPARC V9 Manual, Section A.48 (SETHI), p.220 — imm22 field.
        // Ref: SPARC V9 Manual, Section A.24 (JMPL), p.172 — r[rs1] + r[rs2].
        //
        // Each 32-bit half of the 64-bit address is loaded into a
        // register in two steps (same split as the 32-bit
        // sethi/jmp/nop sequence, but here both halves use
        // sethi + or instead of sethi + jmp):
        //
        //   1. sethi — loads bits [31:10] into the register's
        //      upper 22 bits.  >> 10 shifts those bits down,
        //      & 0x3FFFFF keeps only 22 bits (the field width).
        //
        //   2. or — merges bits [9:0] into the register's lower
        //      10 bits.  & 0x3FF keeps only those 10 bits.
        //
        // Example for lo32 = 0xDEADBEEF:
        //   sethi field: (0xDEADBEEF >> 10) & 0x3FFFFF = 0x37AB6F
        //     → register = 0x37AB6F << 10 = 0xDEADBC00
        //   or    field:  0xDEADBEEF        & 0x3FF    = 0x2EF
        //     → register = 0xDEADBC00 | 0x2EF = 0xDEADBEEF
        static void encodeSparcAbsJump64(void* target, uintptr_t destAddr)
        {
            uint32_t* instr = reinterpret_cast<uint32_t*>(target);
            uint64_t dest64 = static_cast<uint64_t>(destAddr);
            uint32_t lo32 = static_cast<uint32_t>(dest64);
            uint32_t hi32 = static_cast<uint32_t>(dest64 >> 32);
            instr[0] = 0x03000000 | ((hi32 >> 10) & 0x3FFFFF); // sethi %hi(hi32), %g1
            instr[1] = 0x0B000000 | ((lo32 >> 10) & 0x3FFFFF); // sethi %hi(lo32), %g5
            instr[2] = 0x82106000 | (hi32 & 0x3FF); // or %g1, %lo(hi32), %g1
            instr[3] = 0x8A116000 | (lo32 & 0x3FF); // or %g5, %lo(lo32), %g5
            instr[4] = 0x83287020; // sllx %g1, 32, %g1
            instr[5] = 0x81C04005; // jmp %g1 + %g5
            instr[6] = 0x01000000; // nop (delay slot)
        }

        // SPARC call sequence (mov + call + mov), preserving %o7.
        // 12 bytes. Branches to 'to' relative to 'from'.
        // Ref: SPARC V9 Manual, Section A.8 (CALL), p.151 — disp30 field.
        //
        // %o7 (return address) is saved across the call so the patch
        // appears as a direct branch to the caller's return stack.
        static void encodeSparcCallSequence(
            uint32_t* target, void* from, void* to)
        {
            // The call instruction is the second instruction in the
            // sequence (after mov %o7, %g1), so its PC is one
            // instruction (SPARC_INSN_BYTES = 4 bytes) past 'from'.
            // SPARC call computes its target relative to its own PC,
            // not the start of the patch.
            uintptr_t callPC = reinterpret_cast<uintptr_t>(from)
                + SPARC_INSN_BYTES;

            // Convert the byte distance (to - callPC) to a word
            // offset by dividing by SPARC_INSN_BYTES (4), because the
            // call displacement field counts in instructions, not bytes.
            intptr_t distance = static_cast<intptr_t>(
                reinterpret_cast<uintptr_t>(to) - callPC);

            if (distance < -CALL_MAX_BYTES || distance > CALL_MAX_BYTES) {
                throwError("bonobomock ERROR: call displacement out of "
                           "30-bit range.");
            }

            int32_t callDisp = static_cast<int32_t>(
                distance / static_cast<intptr_t>(SPARC_INSN_BYTES));

            // mov %o7, %g1 — save caller return address
            target[0] = 0x8210000F;

            // call <target>
            // The SPARC call instruction has a 30-bit displacement
            // field that holds the distance in 4-byte words.
            // & 0x3FFFFFFF keeps only the low 30 bits of the word
            // offset so it fits into that field.
            //
            // Example: trampoline is 4096 bytes ahead of callPC
            //   callDisp = 4096 / 4 = 1024 words
            //   1024 & 0x3FFFFFFF = 0x00000400
            //   instruction = 0x40000000 | 0x00000400 = 0x40000400
            target[1] = 0x40000000
                | (static_cast<uint32_t>(callDisp) & 0x3FFFFFFF);

            // mov %g1, %o7 — restore return address (delay slot)
            target[2] = 0x9E100001;
        }

        // x86 JMP rel32: [E9] [4-byte signed displacement]. 5 bytes.
        //
        // The displacement is relative to the end of this instruction
        // (patchAddr + 5), hence subtracting X86_JMP_REL32_BYTES.
        static void encodeX86JmpRel32(void* patchAddr, void* jumpTarget)
        {
            unsigned char* bytes = reinterpret_cast<unsigned char*>(patchAddr);
            intptr_t distance = reinterpret_cast<intptr_t>(jumpTarget)
                - reinterpret_cast<intptr_t>(patchAddr)
                - static_cast<intptr_t>(X86_JMP_REL32_BYTES);

            if (distance < -REL32_MAX_BYTES || distance > REL32_MAX_BYTES) {
                throwError("bonobomock ERROR: JMP rel32 displacement out of "
                           "32-bit range.");
            }

            int32_t disp32 = static_cast<int32_t>(distance);
            unsigned char* dispBytes = reinterpret_cast<unsigned char*>(&disp32);
            bytes[0] = 0xE9;
            bsl::copy(dispBytes, dispBytes + 4, bytes + 1);
        }

        // x86-64 far jump: [FF 25 00 00 00 00] [8-byte absolute address].
        // 14 bytes.
        //
        // FF 25 with a zero RIP-relative displacement means "jump to
        // the absolute address stored immediately after this prefix."
        // The 8-byte destination pointer follows the 6-byte prefix.
        static void encodeX86FarJump(void* target, void* destAddr)
        {
            unsigned char* bytes = reinterpret_cast<unsigned char*>(target);
            unsigned char* dest = reinterpret_cast<unsigned char*>(&destAddr);
            bytes[0] = 0xFF;
            bytes[1] = 0x25;
            bytes[2] = 0x00;
            bytes[3] = 0x00;
            bytes[4] = 0x00;
            bytes[5] = 0x00;
            bsl::copy(dest, dest + 8, bytes + 6);
        }
    };

    Patch::Patch()
        : d_patchedAddr(NULL)
    {
    }

    Patch::~Patch()
    {
        restore();
    }

    // Overwrites the first few bytes of 'sourceAddr' with a jump to 'destAddr',
    // saving the displaced bytes internally.  On architectures where the full
    // jump does not fit in a short inline sequence, a trampoline bridges the
    // gap.  The number of bytes patched is kept as small as possible to avoid
    // overwriting code beyond the function's prologue.
    void Patch::setup(void* sourceAddr, void* destAddr)
    {
        d_savedInstructions.clear();
        d_trampolineEntry = TrampolineEntry();

        if (sourceAddr == NULL || destAddr == NULL) {
            throwError("bonobomock ERROR: function address is NULL.");
        }

        d_patchedAddr = sourceAddr;
        makeCurrentAndNextPagesWritable(sourceAddr);

#ifdef BSLS_PLATFORM_CPU_SPARC
    #ifdef BSLS_PLATFORM_CPU_32_BIT
        setupSparc32(sourceAddr, destAddr);
    #else
        setupSparc64(sourceAddr, destAddr);
    #endif
#elif defined(BSLS_PLATFORM_CPU_X86) || defined(BSLS_PLATFORM_CPU_X86_64)
        setupX86(sourceAddr, destAddr);
#else
    #error "No binary patching instructions implemented for this CPU architecture"
#endif

        makeCurrentAndNextPagesUnwritable(sourceAddr);
    }

    // SPARC 32-bit: try ba,a if mock is within +/-8 MB,
    // otherwise fall back to sethi+jmp+nop.
    void Patch::setupSparc32(void* sourceAddr, void* destAddr)
    {
        char* l_src = reinterpret_cast<char*>(sourceAddr);
        uint32_t* l_srcInsn = reinterpret_cast<uint32_t*>(sourceAddr);
        uintptr_t l_dst = reinterpret_cast<uintptr_t>(destAddr);

        intptr_t distance = reinterpret_cast<intptr_t>(destAddr)
            - reinterpret_cast<intptr_t>(sourceAddr);

        if (distance >= -JumpEncoder::BA_A_MAX_BYTES
            && distance <= JumpEncoder::BA_A_MAX_BYTES) {
            d_savedInstructions.assign(l_src, l_src + JumpEncoder::SPARC_BA_A_BYTES);
            JumpEncoder::encodeSparcBranchAlways(l_srcInsn, sourceAddr, destAddr);
            flushICache(sourceAddr, JumpEncoder::SPARC_BA_A_BYTES);
        } else {
            d_savedInstructions.assign(l_src, l_src + JumpEncoder::SPARC_ABS_JUMP32_BYTES);
            JumpEncoder::encodeSparcAbsJump32(l_srcInsn, l_dst);
            flushICache(sourceAddr, JumpEncoder::SPARC_ABS_JUMP32_BYTES);
        }
    }

    // SPARC 64-bit: two-layer trampoline approach.
    // Layer 1: try ba,a to trampoline within +/-8 MB.
    // Layer 2: try call sequence to trampoline within +/-2 GB.
    void Patch::setupSparc64(void* sourceAddr, void* destAddr)
    {
        char* l_src = reinterpret_cast<char*>(sourceAddr);
        uint32_t* l_srcInsn = reinterpret_cast<uint32_t*>(sourceAddr);
        uintptr_t l_dst = reinterpret_cast<uintptr_t>(destAddr);

        TrampolineEntry trampoline = TrampolineManager::instance().allocate(
            sourceAddr, JumpEncoder::BA_A_MAX_BYTES,
            JumpEncoder::SPARC_ABS_JUMP64_BYTES);

        if (trampoline.isValid()) {
            JumpEncoder::encodeSparcAbsJump64(trampoline.addr, l_dst);
            flushICache(trampoline.addr, JumpEncoder::SPARC_ABS_JUMP64_BYTES);
            d_savedInstructions.assign(l_src, l_src + JumpEncoder::SPARC_BA_A_BYTES);
            JumpEncoder::encodeSparcBranchAlways(l_srcInsn, sourceAddr, trampoline.addr);
            flushICache(sourceAddr, JumpEncoder::SPARC_BA_A_BYTES);
            d_trampolineEntry = trampoline;
        } else {
            trampoline = TrampolineManager::instance().allocate(
                sourceAddr, JumpEncoder::CALL_MAX_BYTES,
                JumpEncoder::SPARC_ABS_JUMP64_BYTES);
            if (!trampoline.isValid()) {
                throwError("bonobomock ERROR: unable to allocate trampoline "
                           "within call range for SPARC 64-bit mock.");
            }
            JumpEncoder::encodeSparcAbsJump64(trampoline.addr, l_dst);
            flushICache(trampoline.addr, JumpEncoder::SPARC_ABS_JUMP64_BYTES);
            d_savedInstructions.assign(l_src, l_src + JumpEncoder::SPARC_CALL_SEQ_BYTES);
            JumpEncoder::encodeSparcCallSequence(l_srcInsn, sourceAddr, trampoline.addr);
            flushICache(sourceAddr, JumpEncoder::SPARC_CALL_SEQ_BYTES);
            d_trampolineEntry = trampoline;
        }
    }

    void Patch::setupX86(void* sourceAddr, void* destAddr)
    {
        char* l_src = reinterpret_cast<char*>(sourceAddr);

#ifdef BSLS_PLATFORM_CPU_X86_64
        intptr_t distance = reinterpret_cast<intptr_t>(destAddr)
            - reinterpret_cast<intptr_t>(sourceAddr);
        if (distance > JumpEncoder::REL32_MAX_BYTES
            || distance < -JumpEncoder::REL32_MAX_BYTES) {
            // x86-64 far jump: try trampoline within +/-2 GB to keep inline
            // patch at rel32 size, otherwise fall back to inline far jump.
            TrampolineEntry trampoline = TrampolineManager::instance().allocate(
                sourceAddr, JumpEncoder::REL32_MAX_BYTES,
                JumpEncoder::X86_TRAMPOLINE_BYTES);

            if (trampoline.isValid()) {
                JumpEncoder::encodeX86FarJump(trampoline.addr, destAddr);
                flushICache(trampoline.addr, JumpEncoder::X86_TRAMPOLINE_BYTES);
                d_savedInstructions.assign(l_src, l_src + JumpEncoder::X86_JMP_REL32_BYTES);
                JumpEncoder::encodeX86JmpRel32(sourceAddr, trampoline.addr);
                d_trampolineEntry = trampoline;
            } else {
                d_savedInstructions.assign(l_src, l_src + JumpEncoder::X86_FAR_JMP_BYTES);
                JumpEncoder::encodeX86FarJump(sourceAddr, destAddr);
            }
        } else
#endif
        {
            // Near jump: destination is within +/-2 GB (or 32-bit), so a
            // JMP rel32 reaches directly.
            d_savedInstructions.assign(l_src, l_src + JumpEncoder::X86_JMP_REL32_BYTES);
            JumpEncoder::encodeX86JmpRel32(sourceAddr, destAddr);
        }
        flushICache(sourceAddr, d_savedInstructions.size());
    }

    void Patch::restore()
    {
        if (d_savedInstructions.empty()) {
            return;
        }
        makeCurrentAndNextPagesWritable(d_patchedAddr);
        bsl::copy(d_savedInstructions.begin(), d_savedInstructions.end(), reinterpret_cast<char*>(d_patchedAddr));
        flushICache(d_patchedAddr, d_savedInstructions.size());
        makeCurrentAndNextPagesUnwritable(d_patchedAddr);
        TrampolineManager::instance().free(d_trampolineEntry);
        d_savedInstructions.clear();
        d_trampolineEntry = TrampolineEntry();
    }

    void Patch::makeCurrentAndNextPagesWritable(void* addr)
    {
        // Round 'addr' down to the start of its memory page.
        // (s_pageSize - 1) produces a bitmask covering the in-page
        // offset bits.  Inverting it with ~ gives a mask that keeps
        // only the page-frame bits.  AND-ing clears the offset,
        // yielding the page-aligned base address that mprotect needs.
        //
        // Example for 4 KB pages (s_pageSize = 0x1000):
        //   s_pageSize - 1 = 0x0FFF
        //   ~0x0FFF        = 0xFFFFF000
        //   0xDEADB123 & 0xFFFFF000 = 0xDEADB000  (page start)
        uintptr_t addrInt = reinterpret_cast<uintptr_t>(addr);
        void* l_curPageFrameAddr = reinterpret_cast<void*>(addrInt & (~(s_pageSize - 1)));

#ifdef BSLS_PLATFORM_OS_WINDOWS
        DWORD l_oldProtect;
        if (!VirtualProtect(l_curPageFrameAddr, s_pageSize,
                PAGE_EXECUTE_READWRITE, &l_oldProtect)) {
            throwError("bonobomock make current page writable error!");
        }
        void* l_nextPageFrameAddr = reinterpret_cast<void*>(
            reinterpret_cast<uintptr_t>(l_curPageFrameAddr) + s_pageSize);
        if (!VirtualProtect(l_nextPageFrameAddr, s_pageSize,
                PAGE_EXECUTE_READWRITE, &l_oldProtect)) {
            throwError("bonobomock make next page writable error!");
        }
#elif defined(BSLS_PLATFORM_OS_UNIX)
        // NOLINTNEXTLINE(clang-analyzer-security.MmapWriteExec)
        int rcode = mprotect(l_curPageFrameAddr, s_pageSize, PROT_EXEC | PROT_READ | PROT_WRITE);
        if (rcode) {
            throwError("bonobomock make current page writable error!");
        }

        void* l_nextPageFrameAddr = reinterpret_cast<void*>(
            reinterpret_cast<uintptr_t>(l_curPageFrameAddr) + s_pageSize);
        // NOLINTNEXTLINE(clang-analyzer-security.MmapWriteExec)
        rcode = mprotect(l_nextPageFrameAddr, s_pageSize, PROT_EXEC | PROT_READ | PROT_WRITE);
        if (rcode) {
            throwError("bonobomock make next page writable error!");
        }
#else
    #error "No memory protection implementation for this OS"
#endif
    }

    void Patch::makeCurrentAndNextPagesUnwritable(void* addr)
    {
        // Round down to page boundary (see makeCurrentAndNextPagesWritable).
        uintptr_t addrInt = reinterpret_cast<uintptr_t>(addr);
        void* l_curPageFrameAddr = reinterpret_cast<void*>(addrInt & (~(s_pageSize - 1)));

#ifdef BSLS_PLATFORM_OS_WINDOWS
        DWORD l_oldProtect;
        if (!VirtualProtect(l_curPageFrameAddr, s_pageSize,
                PAGE_EXECUTE_READ, &l_oldProtect)) {
            throwError("bonobomock make current page unwritable error!");
        }
        void* l_nextPageFrameAddr = reinterpret_cast<void*>(
            reinterpret_cast<uintptr_t>(l_curPageFrameAddr) + s_pageSize);
        if (!VirtualProtect(l_nextPageFrameAddr, s_pageSize,
                PAGE_EXECUTE_READ, &l_oldProtect)) {
            throwError("bonobomock make next page unwritable error!");
        }
#elif defined(BSLS_PLATFORM_OS_UNIX)
        int rcode = mprotect(l_curPageFrameAddr, s_pageSize, PROT_EXEC | PROT_READ);
        if (rcode) {
            throwError("bonobomock make current page unwritable error!");
        }

        void* l_nextPageFrameAddr = reinterpret_cast<void*>(
            reinterpret_cast<uintptr_t>(l_curPageFrameAddr) + s_pageSize);
        rcode = mprotect(l_nextPageFrameAddr, s_pageSize, PROT_EXEC | PROT_READ);
        if (rcode) {
            throwError("bonobomock make next page unwritable error!");
        }
#else
    #error "No memory protection implementation for this OS"
#endif
    }

}
}
