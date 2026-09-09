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

#include <bonobomock_optimization_macros_api.h>

// third party includes
#include <gmock/gmock.h>
#include <gtest/gtest.h>

namespace BloombergLP {
namespace bonobomock {
    namespace test {

        using namespace ::testing;

        // Purpose of the test is to make sure the file compiles without warnings
        // Warnings could come from incorrectly defined macros or pragmas not supported by the compiler
        BONOBO_MOCK_DISABLE_FUNCTION_OPTIMIZATION_START(sample_function)
        bool sample_function()
        {
            return true;
        }
        BONOBO_MOCK_DISABLE_FUNCTION_OPTIMIZATION_END(sample_function)

    } // close test namespace
} // close package namespace
} // close enterprise namespace
