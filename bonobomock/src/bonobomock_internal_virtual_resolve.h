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

#ifndef INCLUDED_BONOBOMOCK_INTERNAL_VIRTUAL_RESOLVE
#define INCLUDED_BONOBOMOCK_INTERNAL_VIRTUAL_RESOLVE

#if !defined(INCLUDED_BONOBOMOCK_API) && !defined(BONOBO_MOCK_BUILDING_LIBRARY)
    #error "This is a private header. Directly including it is a contract violation and undefined behavior."
#endif

#include <bonobomock_internal_abi_detection.h>
#include <bonobomock_internal_msvc_virtual_resolve.h>
#include <bonobomock_internal_sunpro_virtual_resolve.h>

#include <cstring>

namespace BloombergLP {
namespace bonobomock {

    // Given a vtable byte offset and a pointer to an object, look up the
    // actual function address from the object's vtable.
    //
    // C++03 compatible. No C++11 features used.
    inline void* resolveFromVtable(size_t vtableByteOffset, void* obj)
    {
        void** vtable = *reinterpret_cast<void***>(obj);
        typedef void (*FUNC_TYPE)(void*);
        size_t idx = vtableByteOffset / sizeof(FUNC_TYPE);
        return vtable[idx];
    }

    // Resolve a virtual member function pointer to the actual function address
    // using an existing object instance.
    //
    // 'pmfBytes' points to the raw bytes of a pointer-to-member-function.
    // 'obj' points to an instance of the class (used to access the vtable).
    //
    // C++03 compatible. No C++11 features used.
    inline void* resolveVirtualAddress(const void* pmfBytes, void* obj)
    {
#if BONOBO_MOCK_INTERNAL_IS_ITANIUM_ABI
        size_t vtableByteOffset;
        std::memcpy(&vtableByteOffset, pmfBytes, sizeof(size_t));
        return resolveFromVtable(vtableByteOffset, obj);
#elif defined(_MSC_VER) || (defined(__clang__) && defined(_MSC_EXTENSIONS))
        return resolveVirtualFromMsvcPmf(pmfBytes, obj);
#elif defined(__SUNPRO_CC)
        return resolveVirtualFromPmf(pmfBytes, obj);
#else
    #error "MockVirtual: virtual function address resolution not implemented for this ABI"
#endif
    }

} // namespace bonobomock
} // namespace BloombergLP

#endif // INCLUDED_BONOBOMOCK_INTERNAL_VIRTUAL_RESOLVE
