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

#ifndef INCLUDED_BONOBOMOCK_INTERNAL_SYMBOL_RESOLVER
#define INCLUDED_BONOBOMOCK_INTERNAL_SYMBOL_RESOLVER

#if !defined(INCLUDED_BONOBOMOCK_API) && !defined(BONOBO_MOCK_BUILDING_LIBRARY)
    #error "This is a private header. Directly including it is a contract violation and undefined behavior."
#endif

#include <bsl_optional.h>
#include <bsl_string.h>
#include <cstddef>

namespace BloombergLP {
namespace bonobomock {

    class SymbolResolver {
    public:
        // Find the runtime address of 'funcName' in the binary at 'taskPath'.
        // 'isFuncConst' controls whether the const or non-const overload is
        // matched.  Returns the runtime address, or an empty optional if no
        // matching symbol is found.  Dispatches to the platform-specific
        // implementation (NmUtil on Unix, DbgHelpResolver on Windows).
        static bsl::optional<size_t> findFunctionAddress(
            const bsl::string& funcName,
            const bsl::string& taskPath,
            bool isFuncConst);
    };

} // namespace bonobomock
} // namespace BloombergLP

#endif
