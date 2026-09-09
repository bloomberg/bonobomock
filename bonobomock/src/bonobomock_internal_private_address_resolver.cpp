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
#include <bonobomock_internal_private_address_resolver.h>
#include <bonobomock_internal_process_util.h>
#include <bonobomock_internal_string_util.h>
#include <bonobomock_internal_symbol_resolver.h>
#include <bsl_iosfwd.h>
#include <bsl_optional.h>
#include <cstddef>

namespace BloombergLP {
namespace bonobomock {

    bsl::unordered_map<bsl::string, size_t> PrivateAddressResolver::d_map;

    size_t PrivateAddressResolver::findNonConstPrivateAddress(const bsl::string& funcName)
    {
        return findPrivateFunctionAddress(funcName, /* isFuncConst */ false);
    }

    size_t PrivateAddressResolver::findConstPrivateAddress(const bsl::string& funcName)
    {
        return findPrivateFunctionAddress(funcName, /* isFuncConst */ true);
    }

    size_t PrivateAddressResolver::findPrivateFunctionAddress(const bsl::string& funcName, bool isFuncConst)
    {
        // Resolve the function's address on first use and cache it in the
        // func_name->address map, returning the cached value thereafter.
        bsl::string cleanName = StringUtil::removeWhitespace(funcName);

        bsl::unordered_map<bsl::string, size_t>::const_iterator it = d_map.find(cleanName);
        if (it != d_map.end()) {
            return it->second;
        }

        bsl::optional<bsl::string> taskPathOpt = ProcessUtil::getCurrentExecutablePath();
        if (!taskPathOpt.has_value()) {
            throwError("bonobomock failed to automatically detect the executable path for function="
                + cleanName + ". Please contact the bonobomock maintainers.");
        }
        const bsl::string& taskPath = taskPathOpt.value();

        bsl::optional<size_t> addr = SymbolResolver::findFunctionAddress(
            cleanName, taskPath, isFuncConst);
        if (!addr) {
            throwError(bsl::string("bonobomock could not find the address of ")
                + (isFuncConst ? "const" : "non-const")
                + " function "
                + cleanName + " in taskPath=" + taskPath);
        }

        d_map[cleanName] = *addr;
        return *addr;
    }

} // bonobomock
} // BloombergLP
