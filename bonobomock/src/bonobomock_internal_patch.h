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

#ifndef INCLUDED_BONOBOMOCK_INTERNAL_PATCH
#define INCLUDED_BONOBOMOCK_INTERNAL_PATCH

#if !defined(INCLUDED_BONOBOMOCK_API) && !defined(BONOBO_MOCK_BUILDING_LIBRARY)
    #error "This is a private header. Directly including it is a contract violation and undefined behavior."
#endif

#include <bonobomock_internal_patch_trampoline.h>

#include <bsl_vector.h>

namespace BloombergLP {
namespace bonobomock {

    // Runtime binary patching engine.
    //
    // Each instance represents a single active patch: a function entry point
    // whose first bytes have been overwritten with a jump to a mock handler.
    // The original bytes are saved internally and restored either on explicit
    // request (restore()) or automatically when the Patch is destroyed.
    //
    // Patching lifecycle (see also docs/reference/internals.md):
    //   1. setup(): save the original bytes, mprotect the page(s) writable,
    //      write an architecture-specific jump to the mock handler, mprotect
    //      back to read+execute.
    //      - On x86-64: 5-byte JMP rel32 if within 2 GB, otherwise a
    //        trampoline or 14-byte inline far jump.
    //      - On SPARC-32: 4-byte ba,a or 12-byte sethi/jmp/nop.
    //      - On SPARC-64: short branch or call sequence through a
    //        trampoline allocated nearby via mmap.
    //   2. restore(): copy the saved bytes back, free any trampoline.
    //      Idempotent — safe to call more than once.
    //   3. Destructor calls restore() as a safety net.
    class Patch {
    public:
        Patch();
        ~Patch();

        // Overwrite 'sourceAddr' with a jump to 'destAddr'. The displaced
        // bytes are saved internally so they can be restored later.
        void setup(void* sourceAddr, void* destAddr);

        // Restore original bytes and free any trampoline. Idempotent.
        void restore();

        static size_t pageSize() { return s_pageSize; }

    private:
        // Non-copyable (C++03).
        Patch(const Patch&);
        Patch& operator=(const Patch&);

        bsl::vector<char> d_savedInstructions;
        void* d_patchedAddr;
        TrampolineEntry d_trampolineEntry;

        // Architecture-specific patching strategies, called by setup().
        // All three compile unconditionally; only the relevant one is
        // called (selected by #ifdef in setup()).
        void setupSparc32(void* sourceAddr, void* destAddr);
        void setupSparc64(void* sourceAddr, void* destAddr);
        void setupX86(void* sourceAddr, void* destAddr);

        // Toggle write permission on the page containing 'addr' and the
        // immediately following page (the patch may straddle a boundary).
        static void makeCurrentAndNextPagesWritable(void* addr);
        static void makeCurrentAndNextPagesUnwritable(void* addr);

        static const size_t s_pageSize;
    };

}
}

#endif
