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
#include <bonobomock_internal_patch_trampoline.h>

#include <bsls_platform.h>

#ifdef BSLS_PLATFORM_OS_WINDOWS
    #include <windows.h>
#elif defined(BSLS_PLATFORM_OS_UNIX)
    #include <sys/mman.h>
    #include <unistd.h>
#else
    #error "No memory-management headers available -- implemented for Windows and Unix-like OSs only"
#endif

#include <cstring>
#include <errno.h>
#include <stdint.h>

namespace BloombergLP {
namespace bonobomock {

    TrampolineManager& TrampolineManager::instance()
    {
        static TrampolineManager manager;
        return manager;
    }

    TrampolineManager::TrampolineManager()
        : d_numPages(0)
    {
    }

    // The trampoline allocator is used on 64-bit builds (x86-64,
    // SPARC-64), where inline patches may not reach the mock function.
    // On 32-bit builds these methods compile but are never called —
    // setupSparc32() and setupX86() use direct jumps that always reach.

    // Try to map an executable page at 'candidate' and verify it is within
    // 'maxRange' bytes of 'nearAddr'.  Returns the mapped page address on
    // success, or NULL on failure.
    void* TrampolineManager::tryMapPageNear(void* candidate, size_t pageSize,
        void* nearAddr, intptr_t maxRange)
    {
#if defined(BSLS_PLATFORM_OS_SOLARIS)
        // Solaris ignores mmap hints, so MAP_FIXED is required.
        // mincore()==ENOMEM confirms the page is unmapped before we claim it.
        char vec;
        if (mincore(static_cast<char*>(candidate), pageSize, &vec) != 0
            && errno == ENOMEM) {
            // NOLINTNEXTLINE(clang-analyzer-security.MmapWriteExec)
            void* page = mmap(candidate, pageSize,
                PROT_READ | PROT_WRITE | PROT_EXEC,
                MAP_PRIVATE | MAP_ANON | MAP_FIXED, -1, 0);
            if (page != MAP_FAILED) {
                return page;
            }
        }
        return NULL;
#elif defined(BSLS_PLATFORM_OS_LINUX)
        // Linux honours mmap hints; verify the returned page is in range.
        // NOLINTNEXTLINE(clang-analyzer-security.MmapWriteExec)
        void* page = mmap(candidate, pageSize,
            PROT_READ | PROT_WRITE | PROT_EXEC,
            MAP_PRIVATE | MAP_ANON, -1, 0);
        if (page != MAP_FAILED) {
            intptr_t dist = static_cast<char*>(page)
                - static_cast<char*>(nearAddr);
            if (dist >= -maxRange && dist <= maxRange) {
                return page;
            }
            munmap(page, pageSize);
        }
        return NULL;
#elif defined(BSLS_PLATFORM_OS_WINDOWS)
        // VirtualAlloc does not guarantee placement at the hint address, so
        // verify the returned page is within range before accepting it.
        void* page = VirtualAlloc(candidate, pageSize,
            MEM_RESERVE | MEM_COMMIT, PAGE_EXECUTE_READWRITE);
        if (page) {
            intptr_t dist = static_cast<char*>(page)
                - static_cast<char*>(nearAddr);
            if (dist >= -maxRange && dist <= maxRange) {
                return page;
            }
            VirtualFree(page, 0, MEM_RELEASE);
        }
        return NULL;
#else
    #error "No trampoline allocation strategy for this OS"
#endif
    }

    TrampolineEntry TrampolineManager::allocate(void* nearAddr,
        intptr_t maxRange, size_t entrySize)
    {
        if (entrySize == 0) {
            throwError("bonobomock ERROR: trampoline entry size is 0.");
        }

        const size_t pageSize = Patch::pageSize();

        // Search existing pages for a free entry within range.
        for (int i = 0; i < d_numPages; ++i) {
            Page& p = d_pages[i];
            if (p.entrySize != entrySize || p.usedCount >= p.totalEntries) {
                continue;
            }
            for (int j = 0; j < p.totalEntries; ++j) {
                if (p.entryInUse[j]) {
                    continue;
                }
                void* entryAddr = static_cast<char*>(p.addr)
                    + static_cast<size_t>(j) * entrySize;
                intptr_t dist = static_cast<char*>(entryAddr)
                    - static_cast<char*>(nearAddr);
                if (dist >= -maxRange && dist <= maxRange) {
                    p.entryInUse[j] = true;
                    p.usedCount++;
                    TrampolineEntry result;
                    result.addr = entryAddr;
                    result.size = entrySize;
                    return result;
                }
            }
        }

        if (d_numPages >= MAX_PAGES) {
            return TrampolineEntry();
        }

        // Allocate a new page within range.
        void* page = NULL;

        // Align down to page boundary: (pageSize-1) is a bitmask of
        // the in-page offset bits (e.g. 0xFFF for 4 KB pages); its
        // complement clears those bits, rounding the address down to
        // the start of its containing page.
        uintptr_t base = reinterpret_cast<uintptr_t>(nearAddr)
            & ~(pageSize - 1);

        for (size_t offset = pageSize;
            offset <= static_cast<size_t>(maxRange);
            offset += pageSize) {
            if (offset > static_cast<size_t>(maxRange) - pageSize
                && offset != static_cast<size_t>(maxRange)) {
                break;
            }

            // Try above the target.
            page = tryMapPageNear(reinterpret_cast<void*>(base + offset),
                pageSize, nearAddr, maxRange);
            if (page) {
                break;
            }

            // Try below the target.
            if (base >= offset) {
                page = tryMapPageNear(
                    reinterpret_cast<void*>(base - offset),
                    pageSize, nearAddr, maxRange);
                if (page) {
                    break;
                }
            }
        }

        if (!page) {
            return TrampolineEntry();
        }

        Page& tp = d_pages[d_numPages++];
        tp.addr = page;
        tp.entrySize = entrySize;
        tp.totalEntries = static_cast<int>(pageSize / entrySize);
        if (tp.totalEntries > MAX_ENTRIES_PER_PAGE) {
            tp.totalEntries = MAX_ENTRIES_PER_PAGE;
        }
        std::memset(tp.entryInUse, 0, sizeof(tp.entryInUse));
        tp.entryInUse[0] = true;
        tp.usedCount = 1;

        TrampolineEntry result;
        result.addr = page;
        result.size = entrySize;
        return result;
    }

    void TrampolineManager::free(const TrampolineEntry& entry)
    {
        if (!entry.isValid()) {
            return;
        }

        const size_t pageSize = Patch::pageSize();

        for (int i = 0; i < d_numPages; ++i) {
            Page& p = d_pages[i];
            uintptr_t pBase = reinterpret_cast<uintptr_t>(p.addr);
            uintptr_t e = reinterpret_cast<uintptr_t>(entry.addr);

            if (e >= pBase && e < pBase + pageSize) {
                int idx = static_cast<int>((e - pBase) / p.entrySize);
                // Silently bail out rather than throw: free() may run
                // from Mock destructors, and throwing from a destructor
                // calls std::terminate.  A leaked slot is harmless in a
                // test binary; a hard crash is not.
                if (idx < 0 || idx >= p.totalEntries) {
                    return;
                }
                p.entryInUse[idx] = false;
                p.usedCount--;

                if (p.usedCount == 0) {
#ifdef BSLS_PLATFORM_OS_WINDOWS
                    VirtualFree(p.addr, 0, MEM_RELEASE);
#elif defined(BSLS_PLATFORM_OS_UNIX)
                    munmap(p.addr, pageSize);
#else
    #error "No memory deallocation implementation for this OS"
#endif
                    // Swap with last to keep d_pages compact.
                    // Order doesn't matter — allocate() searches
                    // all pages by proximity, not by index.
                    d_pages[i] = d_pages[d_numPages - 1];
                    d_numPages--;
                }
                return;
            }
        }
    }

}
}
