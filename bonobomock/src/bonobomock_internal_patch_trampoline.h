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

#ifndef INCLUDED_BONOBOMOCK_INTERNAL_PATCH_TRAMPOLINE
#define INCLUDED_BONOBOMOCK_INTERNAL_PATCH_TRAMPOLINE

#if !defined(INCLUDED_BONOBOMOCK_API) && !defined(BONOBO_MOCK_BUILDING_LIBRARY)
    #error "This is a private header. Directly including it is a contract violation and undefined behavior."
#endif

#include <stddef.h>
#include <stdint.h>

namespace BloombergLP {
namespace bonobomock {

    // A handle representing an allocated trampoline slot: an executable
    // code region at 'addr' of 'size' bytes.  Default-constructed entries
    // are invalid (addr=NULL) and represent "no trampoline."
    struct TrampolineEntry {
        void* addr;
        size_t size;

        TrampolineEntry()
            : addr(NULL)
            , size(0)
        {
        }
        bool isValid() const { return addr != NULL; }
    };

    // Singleton allocator for out-of-line trampoline slots.
    //
    // On 64-bit architectures the shortest inline branch may not reach the
    // mock function, and the full-range inline jump is too wide for small
    // functions.  A trampoline — executable code allocated nearby via
    // mmap — bridges the gap so the inline patch stays small.
    //
    // Each mmap'd page is subdivided into fixed-size slots. Slots are
    // reused across mocks; the page is munmap'd when its last slot is
    // freed.
    //
    // On 32-bit architectures the inline patch always reaches any address,
    // so allocate() returns an invalid entry and free() is a no-op.
    //
    // Not thread-safe: mock setup/teardown is single-threaded by design
    // (see limitations.md).
    class TrampolineManager {
    public:
        static TrampolineManager& instance();

        // Allocate a trampoline slot of 'entrySize' bytes within
        // 'maxRange' bytes of 'nearAddr'.  Returns an invalid entry
        // if no slot can be placed close enough.
        TrampolineEntry allocate(void* nearAddr, intptr_t maxRange,
            size_t entrySize);

        // Free a previously allocated trampoline slot.  No-op if the
        // entry is invalid.
        void free(const TrampolineEntry& entry);

    private:
        TrampolineManager();
        TrampolineManager(const TrampolineManager&);
        TrampolineManager& operator=(const TrampolineManager&);

        static const int MAX_PAGES = 64;
        static const int MAX_ENTRIES_PER_PAGE = 512;

        struct Page {
            void* addr;
            size_t entrySize;
            int totalEntries;
            int usedCount;
            bool entryInUse[MAX_ENTRIES_PER_PAGE];
        };

        Page d_pages[MAX_PAGES];
        int d_numPages;

        // Try to mmap an executable page at 'candidate' within
        // 'maxRange' bytes of 'nearAddr'. Returns NULL on failure.
        void* tryMapPageNear(void* candidate, size_t pageSize,
            void* nearAddr, intptr_t maxRange);
    };

}
}

#endif
