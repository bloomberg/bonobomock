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

#ifndef INCLUDED_BONOBOMOCK_INTERNAL_NM_UTIL
#define INCLUDED_BONOBOMOCK_INTERNAL_NM_UTIL

#if !defined(INCLUDED_BONOBOMOCK_API) && !defined(BONOBO_MOCK_BUILDING_LIBRARY)
    #error "This is a private header. Directly including it is a contract violation and undefined behavior."
#endif

#include <bsl_optional.h>
#include <bsl_string.h>
#include <cstddef>

namespace BloombergLP {
namespace bonobomock {
    namespace NmUtil {

        // Find the runtime address of 'funcName' in the binary at 'taskPath' by
        // parsing 'nm' output and demangling symbols in-process.  'isFuncConst'
        // controls whether the const or non-const overload is matched.  PIE
        // correction is applied automatically (calibrated on first call).
        // Returns the runtime address, or an empty optional if no matching
        // symbol is found.
        bsl::optional<size_t> findFunctionAddress(const bsl::string& funcName,
            const bsl::string& taskPath,
            bool isFuncConst);

        // Empty function used as a known reference point for PIE calibration.
        // Its address is taken at runtime and compared with the nm-reported address
        // to compute the PIE slide.  Must not be inlined or optimized away.
        void pieCalibrationAnchor();

    } // namespace NmUtil
} // namespace bonobomock
} // namespace BloombergLP

#endif
