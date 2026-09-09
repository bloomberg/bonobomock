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

// bonobomock_internal_windows_thunk_resolve.h
//
// Follow a single level of JMP thunk on x86/x86-64 to reach the real
// function entry point.  Currently used only on Windows, but the logic is
// purely x86 instruction decoding and would work on any x86/x86-64 platform
// that uses similar JMP-based indirection (e.g. ELF PLT stubs).
//
// With MSVC incremental linking (/INCREMENTAL), taking the address of a
// function may return an ILT thunk rather than the real function body.
// Patching the thunk instead of the real entry would miss direct calls that
// bypass the thunk.
//
// Two encodings are handled:
//   E9 XX XX XX XX        -> JMP rel32
//   FF 25 XX XX XX XX     -> JMP [RIP+rel32]  (x86-64 indirect / import thunk)
//   FF 25 XX XX XX XX     -> JMP [abs32]      (x86-32 indirect / import thunk)

#ifndef INCLUDED_BONOBOMOCK_INTERNAL_WINDOWS_THUNK_RESOLVE
#define INCLUDED_BONOBOMOCK_INTERNAL_WINDOWS_THUNK_RESOLVE

#if !defined(INCLUDED_BONOBOMOCK_API) && !defined(BONOBO_MOCK_BUILDING_LIBRARY)
    #error "This is a private header. Directly including it is a contract violation and undefined behavior."
#endif

#include <bsls_platform.h>

#if defined(BSLS_PLATFORM_CPU_X86) || defined(BSLS_PLATFORM_CPU_X86_64)
    #include <cstdint>
    #include <cstring>

namespace BloombergLP {
namespace bonobomock {

    // Follow one level of leading JMP instruction on x86/x86-64 and return
    // the target address.  If 'addr' does not begin with a recognised JMP
    // encoding, 'addr' is returned unchanged.
    inline void* resolveJmpThunk(void* addr)
    {
        const unsigned char* p = static_cast<const unsigned char*>(addr);

        // JMP rel32 (E9 XX XX XX XX)
        if (p[0] == 0xE9) {
            int32_t rel32;
            std::memcpy(&rel32, p + 1, sizeof(rel32));
            return const_cast<unsigned char*>(p) + 5 + rel32;
        }

        if (p[0] == 0xFF && p[1] == 0x25) {
    #if defined(BSLS_PLATFORM_CPU_X86_64)
            // JMP [RIP+rel32]: dereference the pointer stored in memory
            int32_t rel32;
            std::memcpy(&rel32, p + 2, sizeof(rel32));
            const void* const* slot = reinterpret_cast<const void* const*>(p + 6 + rel32);
            return const_cast<void*>(*slot);
    #else
            // JMP [abs32]: dereference the absolute pointer stored in memory
            uint32_t absAddr;
            std::memcpy(&absAddr, p + 2, sizeof(absAddr));
            const void* const* slot = reinterpret_cast<const void* const*>(
                static_cast<uintptr_t>(absAddr));
            return const_cast<void*>(*slot);
    #endif
        }

        return addr;
    }

} // namespace bonobomock
} // namespace BloombergLP

#endif // BSLS_PLATFORM_CPU_X86 || BSLS_PLATFORM_CPU_X86_64

#endif // INCLUDED_BONOBOMOCK_INTERNAL_WINDOWS_THUNK_RESOLVE
