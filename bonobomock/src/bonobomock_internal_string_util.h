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

#ifndef INCLUDED_BONOBOMOCK_INTERNAL_STRING_UTIL
#define INCLUDED_BONOBOMOCK_INTERNAL_STRING_UTIL

#if !defined(INCLUDED_BONOBOMOCK_API) && !defined(BONOBO_MOCK_BUILDING_LIBRARY)
    #error "This is a private header. Directly including it is a contract violation and undefined behavior."
#endif

#include <bsl_string.h>

namespace BloombergLP {
namespace bonobomock {
    namespace StringUtil {

        // Remove all whitespace characters from the specified 'input' string and
        // return the result.  This is needed because the preprocessor stringify
        // operator (#) preserves whatever whitespace is present in the macro
        // argument, and clang-format may break long qualified names across multiple
        // lines, injecting spaces or newlines that would cause nm lookups to fail.
        inline bsl::string removeWhitespace(const bsl::string& input)
        {
            bsl::string result;
            result.reserve(input.size());
            for (bsl::string::size_type i = 0; i < input.size(); ++i) {
                char c = input[i];
                if (c != ' ' && c != '\t' && c != '\n' && c != '\r') {
                    result += c;
                }
            }
            return result;
        }

    } // namespace StringUtil
} // namespace bonobomock
} // namespace BloombergLP

#endif
