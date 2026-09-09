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

#ifndef INCLUDED_BONOBOMOCK_INTERNAL_ABI_DETECTION
#define INCLUDED_BONOBOMOCK_INTERNAL_ABI_DETECTION

#if !defined(INCLUDED_BONOBOMOCK_API) && !defined(BONOBO_MOCK_BUILDING_LIBRARY)
    #error "This is a private header. Directly including it is a contract violation and undefined behavior."
#endif

// Determine whether the compiler uses the Itanium ABI.
//
// We resolve virtual function addresses from a pointer to member function (PMF).
// Different ABIs encode the function address inside a PMF differently:
//
//   Itanium ABI (GCC, Clang on non-MSVC targets):
//     A PMF is a 2-word struct { ptrdiff_t ptr; ptrdiff_t adj; }.
//     For virtual functions, 'ptr' holds a vtable offset (odd value); for
//     non-virtual functions it holds the function address directly.
//
//   MSVC ABI / SunPro:
//     PMF layout varies by inheritance model and is not Itanium-compatible.
//     Virtual address resolution uses a different mechanism.
//
// BONOBO_MOCK_INTERNAL_IS_ITANIUM_ABI is set to 1 when the Itanium PMF layout can
// be assumed, and 0 otherwise.
#if defined(__clang__)
    #if defined(_MSC_VER)
        #define BONOBO_MOCK_INTERNAL_IS_ITANIUM_ABI 0 // clang targeting MSVC ABI
    #elif defined(__GXX_ABI_VERSION)
        #define BONOBO_MOCK_INTERNAL_IS_ITANIUM_ABI 1 // clang in GNU/Itanium ABI family
    #else
        #error "Unknown Clang C++ ABI mode"
    #endif

// Both Clang and GCC define __GNUC__, here we check whether it's actually GCC.
#elif !defined(__clang__) && defined(__GNUC__)
    // GCC uses Itanium ABI across all platforms
    #if defined(__GXX_ABI_VERSION)
        #define BONOBO_MOCK_INTERNAL_IS_ITANIUM_ABI 1 // GCC C++ ABI family
    #else
        #error "Unknown GCC C++ ABI mode"
    #endif

#elif defined(_MSC_VER)
    #define BONOBO_MOCK_INTERNAL_IS_ITANIUM_ABI 0 // MSVC ABI

#elif defined(__SUNPRO_CC)
    #define BONOBO_MOCK_INTERNAL_IS_ITANIUM_ABI 0 // SunPro

#else
    #error "No ABI detection rule for this compiler"
#endif

#endif
