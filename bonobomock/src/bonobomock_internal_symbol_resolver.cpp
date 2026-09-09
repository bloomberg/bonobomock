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

#include <bonobomock_internal_symbol_resolver.h>

#include <bsls_platform.h>

#ifdef BSLS_PLATFORM_OS_WINDOWS
    #include <bonobomock_internal_dbghelp_resolver.h>
#elif defined(BSLS_PLATFORM_OS_UNIX)
    #include <bonobomock_internal_nm_util.h>
#else
    #error "No symbol resolution implementation for this OS"
#endif

namespace BloombergLP {
namespace bonobomock {

    bsl::optional<size_t> SymbolResolver::findFunctionAddress(
        const bsl::string& funcName,
        const bsl::string& taskPath,
        bool isFuncConst)
    {
#ifdef BSLS_PLATFORM_OS_WINDOWS
        return DbgHelpResolver::findFunctionAddress(
            funcName, taskPath, isFuncConst);
#elif defined(BSLS_PLATFORM_OS_UNIX)
        return NmUtil::findFunctionAddress(funcName, taskPath, isFuncConst);
#else
    #error "No symbol resolution implementation for this OS"
#endif
    }

} // namespace bonobomock
} // namespace BloombergLP
