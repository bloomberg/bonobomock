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

#ifndef INCLUDED_BONOBOMOCK_INTERNAL_PRIVATE_ADDRESS_RESOLVER
#define INCLUDED_BONOBOMOCK_INTERNAL_PRIVATE_ADDRESS_RESOLVER

#if !defined(INCLUDED_BONOBOMOCK_API) && !defined(BONOBO_MOCK_BUILDING_LIBRARY)
    #error "This is a private header. Directly including it is a contract violation and undefined behavior."
#endif

#include <bsl_string.h>
#include <bsl_unordered_map.h>
#include <cstddef>

namespace BloombergLP {
namespace bonobomock {

    class PrivateAddressResolver {
    public:
        // Resolve (on first use) and return the cached address of the private
        // function 'funcName'. The two variants select the non-const or const
        // symbol respectively; a caller picks the one matching the mock type's
        // const-ness. The task path is auto-detected. Throw if the address
        // cannot be resolved.
        static size_t findNonConstPrivateAddress(const bsl::string& funcName);
        static size_t findConstPrivateAddress(const bsl::string& funcName);

        static bsl::unordered_map<bsl::string, size_t>& map()
        {
            return d_map;
        }

    private:
        static bsl::unordered_map<bsl::string, size_t> d_map;

        static size_t findPrivateFunctionAddress(const bsl::string& funcName, bool isFuncConst);
    };

}
}

#endif
