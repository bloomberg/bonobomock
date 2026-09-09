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

// component under test
// include this header to use bonobomock
#include <bonobomock_api.h>

// third party includes
// include GoogleTest
#include <gmock/gmock.h>
#include <gtest/gtest-spi.h>
#include <gtest/gtest.h>

#include <bsl_memory.h>
#include <bsls_compilerfeatures.h>

#include <bonobomock_optimization_macros_api.h>

namespace BloombergLP {
namespace bonobomock {
    namespace test {

        using namespace ::testing;

        // The SampleClass class contains a static method for us to mock.
        class SampleClass {
        public:
            BONOBO_MOCK_DISABLE_FUNCTION_OPTIMIZATION_START(sample_function)
            static bool sample_function(bool in)
            {
                volatile bool _r = in;
                return _r;
            }
            BONOBO_MOCK_DISABLE_FUNCTION_OPTIMIZATION_END(sample_function)
        };

        TEST(Static, Mock)
        {
            // Mock static function sample_function in class SampleClass
            // 'auto' type deduction requires C++11 or later.
#ifdef BSLS_COMPILERFEATURES_FULL_CPP11
            auto mock = BONOBO_MOCK(&SampleClass::sample_function);
#else
            bsl::shared_ptr<GMock<bool(bool)> > mock = BONOBO_MOCK(&SampleClass::sample_function);
#endif

            // Defined the mocked SampleClass::sample_function for the 1st call.
            // BONOBO_MOCK_FUNCTION is taking `false` as input, so it is expecting `false` to be passed in.
            // Return true even input is false.
            EXPECT_CALL(*mock, BONOBO_MOCK_FUNCTION(false))
                .Times(1)
                .WillOnce(Return(true));

            EXPECT_TRUE(SampleClass::sample_function(false));

            // Defined the mocked SampleClass::sample_function for the 2nd call.
            // BONOBO_MOCK_FUNCTION is taking `true` as input, so it is expecting `true` to be passed in.
            // Return false even input is true.
            EXPECT_CALL(*mock, BONOBO_MOCK_FUNCTION(true))
                .Times(1)
                .WillOnce(Return(false));

            EXPECT_FALSE(SampleClass::sample_function(true));

            // Defined the mocked SampleClass::sample_function for the rest call.
            // BONOBO_MOCK_FUNCTION is taking `_` as input, so it is anything to be passed in.
            // Return true always.
            EXPECT_CALL(*mock, BONOBO_MOCK_FUNCTION(_))
                .WillRepeatedly(Return(true));

            EXPECT_TRUE(SampleClass::sample_function(false));
            EXPECT_TRUE(SampleClass::sample_function(true));

            // Tell bonobomock to stop mocking, use the original sample_function.
            mock->restore();

            EXPECT_FALSE(SampleClass::sample_function(false));
            EXPECT_TRUE(SampleClass::sample_function(true));
        }

        //==============================================================================
        // NAGGY MOCK TESTS: STATIC METHODS
        // These tests verify that the default (naggy) mock DOES produce output about
        // uninteresting calls when no expectations are set.
        //==============================================================================

        TEST(NaggyMock_Static, StaticMethod)
        {
            testing::internal::CaptureStdout();
            testing::internal::CaptureStderr();
            {
                // 'auto' type deduction requires C++11 or later.
#ifdef BSLS_COMPILERFEATURES_FULL_CPP11
                auto mock = BONOBO_MOCK(&SampleClass::sample_function);
#else
                bsl::shared_ptr<GMock<bool(bool)> > mock = BONOBO_MOCK(&SampleClass::sample_function);
#endif
                // No expectations set on the mock.
                // All calls to the mocked function will be "uninteresting".
                // Naggy mock (default) SHOULD report uninteresting calls.
                SampleClass::sample_function(true);
            }
            bsl::string stderrOutput = testing::internal::GetCapturedStderr();
            bsl::string stdoutOutput = testing::internal::GetCapturedStdout();
            EXPECT_TRUE(stderrOutput.find("Uninteresting") != bsl::string::npos || stdoutOutput.find("Uninteresting") != bsl::string::npos);
        }

        //==============================================================================
        // STRICT MOCK TESTS: STATIC METHODS
        //==============================================================================

        TEST(StrictMock_Static, StaticMethod)
        {
            // 'auto' type deduction requires C++11 or later.
#ifdef BSLS_COMPILERFEATURES_FULL_CPP11
            auto mock = BONOBO_MOCK_STRICT(&SampleClass::sample_function);
#else
            bsl::shared_ptr<GMock<bool(bool)> > mock = BONOBO_MOCK_STRICT(&SampleClass::sample_function);
#endif
            EXPECT_NONFATAL_FAILURE(
                {
                    // No expectations set on the mock.
                    // All calls to the mocked function will be "uninteresting".
                    // They should trigger the strict mock failure.
                    SampleClass::sample_function(true);
                },
                "Uninteresting mock function call");
        }

        //==============================================================================
        // NICE MOCK TESTS: STATIC METHODS
        //==============================================================================

        TEST(NiceMock_Static, StaticMethod)
        {
            testing::internal::CaptureStdout();
            testing::internal::CaptureStderr();
            {
                // 'auto' type deduction requires C++11 or later.
#ifdef BSLS_COMPILERFEATURES_FULL_CPP11
                auto mock = BONOBO_MOCK_NICE(&SampleClass::sample_function);
#else
                bsl::shared_ptr<GMock<bool(bool)> > mock = BONOBO_MOCK_NICE(&SampleClass::sample_function);
#endif
                // No expectations set on the mock.
                // All calls to the mocked function will be "uninteresting".
                // NiceMock should NOT report uninteresting calls.
                SampleClass::sample_function(true);
            }
            bsl::string stderrOutput = testing::internal::GetCapturedStderr();
            bsl::string stdoutOutput = testing::internal::GetCapturedStdout();
            EXPECT_THAT(stderrOutput, Not(HasSubstr("Uninteresting")));
            EXPECT_THAT(stdoutOutput, Not(HasSubstr("Uninteresting")));
        }

    } // close test namespace
} // close package namespace
} // close enterprise namespace
