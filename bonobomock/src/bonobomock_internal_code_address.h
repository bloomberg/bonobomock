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

#ifndef INCLUDED_BONOBOMOCK_INTERNAL_CODE_ADDRESS
#define INCLUDED_BONOBOMOCK_INTERNAL_CODE_ADDRESS

#if !defined(INCLUDED_BONOBOMOCK_API) && !defined(BONOBO_MOCK_BUILDING_LIBRARY)
    #error "This is a private header. Directly including it is a contract violation and undefined behavior."
#endif

#include <cstring>

namespace BloombergLP {
namespace bonobomock {

    // Extract the code address from a function pointer (free function pointer
    // or pointer-to-member-function) by reading its first sizeof(size_t)
    // bytes via memcpy. This avoids strict-aliasing violations that would
    // occur with reinterpret_cast directly on the pointer object.
    //
    // For non-virtual free/member functions, this yields the function's actual
    // address. For virtual member functions on Itanium ABI, this yields the
    // vtable byte offset (which must be resolved separately).
    //
    // C++03 compatible. No C++11 features used.
    template <typename T>
    inline void* toCodeAddress(const T& funcPtr)
    {
        size_t addr;
        std::memcpy(&addr, &funcPtr, sizeof(size_t));
        return reinterpret_cast<void*>(addr);
    }

} // namespace bonobomock
} // namespace BloombergLP

#endif // INCLUDED_BONOBOMOCK_INTERNAL_CODE_ADDRESS
