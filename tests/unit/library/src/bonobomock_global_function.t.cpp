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
#include <bslstl_string.h>
#include <gmock/gmock.h>
#include <gtest/gtest-spi.h>
#include <gtest/gtest.h>

#include <bsl_memory.h>
#include <bsl_string.h>
#include <bsls_compilerfeatures.h>

#include <sample_functions.h>

namespace BloombergLP {
namespace bonobomock {
    namespace test {

        using namespace ::testing;
        using namespace sample_functions;

        TEST(Global, mockGlobal)
        {
            // Declare the function you would like to mock
            // 'auto' type deduction requires C++11 or later.
#ifdef BSLS_COMPILERFEATURES_FULL_CPP11
            auto mock = BONOBO_MOCK(&foo);
#else
            bsl::shared_ptr<GMock<int(int&, int*, int)> > mock = BONOBO_MOCK(&foo);
#endif

            // Define what you would like the target function to behave.
            int x = 10;
            int y = 11;
            EXPECT_CALL(*mock, BONOBO_MOCK_FUNCTION(_, _, _))
                .WillOnce(DoAll(SetArgReferee<0>(x), SetArgPointee<1>(y), Return(100)));
            // Test the function
            int a = 1;
            int b = 2;
            EXPECT_EQ(100, foo(a, &b, 3));
            EXPECT_EQ(10, a);
            EXPECT_EQ(11, b);
        }

        TEST(Global, Mock)
        {
            // Mock sample_function
            EXPECT_FALSE(sample_function());
            // 'auto' type deduction requires C++11 or later.
#ifdef BSLS_COMPILERFEATURES_FULL_CPP11
            auto mock = BONOBO_MOCK(&sample_function);
#else
            bsl::shared_ptr<GMock<bool()> > mock = BONOBO_MOCK(&sample_function);
#endif

            // Define how we would like to mock sample_function
            // Because sample_function doesn't take any input, BONOBO_MOCK_FUNCTION's input is empty.
            // Mocked sample_function will return true instead of false.
            EXPECT_CALL(*mock, BONOBO_MOCK_FUNCTION()).Times(1).WillOnce(Return(true));

            EXPECT_TRUE(sample_function());

            // Tell bonobomock to stop mocking, use the original sample_function.
            mock->restore();

            EXPECT_FALSE(sample_function());
        }

        TEST(Global, Mock2)
        {
            // Mock sample_function_2
            // 'auto' type deduction requires C++11 or later.
#ifdef BSLS_COMPILERFEATURES_FULL_CPP11
            auto mock = BONOBO_MOCK(&sample_function_2);
#else
            bsl::shared_ptr<GMock<int(int, int)> > mock = BONOBO_MOCK(&sample_function_2);
#endif

            // Define the mocked sample_function_2 except the first 2 calls.
            // I use `_` here in BONOBO_MOCK_FUNCTION because I don't care about the inputs.
            // There are two `_` because sample_function_2 is expecting 2 inputs.
            // Return 100 always.
            EXPECT_CALL(*mock, BONOBO_MOCK_FUNCTION(_, _)).WillRepeatedly(Return(100));

            // Define the mocked sample_function_2 for the first 2 calls.
            // The inputs of sample_function_2 must be 100 and 150.
            // Return 150 for first call and return 250 for the 2nd.
            EXPECT_CALL(*mock, BONOBO_MOCK_FUNCTION(100, 150)).Times(2).WillOnce(Return(150)).WillOnce(Return(250));

            EXPECT_EQ(150, sample_function_2(100, 150));
            EXPECT_EQ(250, sample_function_2(100, 150));
            EXPECT_EQ(100, sample_function_2(1, 2));
            EXPECT_EQ(100, sample_function_2(3, 4));

            // Tell bonobomock to stop mocking, use the original sample_function.
            mock->restore();

            EXPECT_EQ(0, sample_function_2(1, 2));
            EXPECT_EQ(0, sample_function_2(3, 4));
        }

        TEST(Global, Mock3)
        {
            // 'auto' type deduction requires C++11 or later.
#ifdef BSLS_COMPILERFEATURES_FULL_CPP11
            auto mock = BONOBO_MOCK(&sample_function_3);
#else
            bsl::shared_ptr<GMock<int(bsl::string&)> > mock = BONOBO_MOCK(&sample_function_3);
#endif

            EXPECT_CALL(*mock, BONOBO_MOCK_FUNCTION(Eq("bar"))).WillRepeatedly(Return(100));

            EXPECT_CALL(*mock, BONOBO_MOCK_FUNCTION(Eq("foo"))).Times(2).WillOnce(Return(150)).WillOnce(Return(250));

            bsl::string foo("foo");
            bsl::string bar("bar");
            EXPECT_EQ(150, sample_function_3(foo));
            EXPECT_EQ(250, sample_function_3(foo));
            EXPECT_EQ(100, sample_function_3(bar));
            EXPECT_EQ(100, sample_function_3(bar));

            // Tell bonobomock to stop mocking, use the original sample_function.
            mock->restore();

            EXPECT_EQ(0, sample_function_3(foo));
            EXPECT_EQ(0, sample_function_3(bar));
        }

// Rvalue references require C++11 or later.
#ifdef BSLS_COMPILERFEATURES_FULL_CPP11
        TEST(Global, Mock4)
        {
            // 'auto' type deduction requires C++11 or later.
    #ifdef BSLS_COMPILERFEATURES_FULL_CPP11
            auto mock = BONOBO_MOCK(&sample_function_4);
    #else
            bsl::shared_ptr<GMock<int(bsl::string&&)> > mock = BONOBO_MOCK(&sample_function_4);
    #endif

            EXPECT_CALL(*mock, BONOBO_MOCK_FUNCTION(Eq("bar"))).WillRepeatedly(Return(100));

            EXPECT_CALL(*mock, BONOBO_MOCK_FUNCTION(Eq("foo"))).Times(2).WillOnce(Return(150)).WillOnce(Return(250));

            EXPECT_EQ(150, sample_function_4(makeFooStr()));
            EXPECT_EQ(250, sample_function_4(makeFooStr()));
            EXPECT_EQ(100, sample_function_4(makeBarStr()));
            EXPECT_EQ(100, sample_function_4(makeBarStr()));

            // Tell bonobomock to stop mocking, use the original sample_function.
            mock->restore();

            EXPECT_EQ(0, sample_function_4(makeFooStr()));
            EXPECT_EQ(0, sample_function_4(makeBarStr()));
        }

        TEST(Global, Mock5)
        {
            // 'auto' type deduction requires C++11 or later.
    #ifdef BSLS_COMPILERFEATURES_FULL_CPP11
            auto mock = BONOBO_MOCK(&sample_function_5<bsl::string>);
    #else
            bsl::shared_ptr<GMock<int(bsl::string&&)> > mock = BONOBO_MOCK(&sample_function_5<bsl::string>);
    #endif

            EXPECT_CALL(*mock, BONOBO_MOCK_FUNCTION(Eq("bar"))).WillRepeatedly(Return(100));

            EXPECT_CALL(*mock, BONOBO_MOCK_FUNCTION(Eq("foo"))).Times(2).WillOnce(Return(150)).WillOnce(Return(250));

            EXPECT_EQ(150, sample_function_5(makeFooStr()));
            EXPECT_EQ(250, sample_function_5(makeFooStr()));
            EXPECT_EQ(100, sample_function_5(makeBarStr()));
            EXPECT_EQ(100, sample_function_5(makeBarStr()));

            // Tell bonobomock to stop mocking, use the original sample_function.
            mock->restore();

            EXPECT_EQ(0, sample_function_5(makeFooStr()));
            EXPECT_EQ(0, sample_function_5(makeBarStr()));
        }
#endif

        //==============================================================================
        // NAGGY MOCK TESTS: GLOBAL FUNCTIONS
        // These tests verify that the default (naggy) mock DOES produce output about
        // uninteresting calls when no expectations are set.
        //==============================================================================

        TEST(NaggyMock_Global, NoParams)
        {
            testing::internal::CaptureStdout();
            testing::internal::CaptureStderr();
            {
                // 'auto' type deduction requires C++11 or later.
#ifdef BSLS_COMPILERFEATURES_FULL_CPP11
                auto mock = BONOBO_MOCK(&sample_function);
#else
                bsl::shared_ptr<GMock<bool()> > mock = BONOBO_MOCK(&sample_function);
#endif
                // No expectations set on the mock.
                // All calls to the mocked function will be "uninteresting".
                // Naggy mock (default) SHOULD report uninteresting calls.
                sample_function();
            }
            bsl::string stderrOutput = testing::internal::GetCapturedStderr();
            bsl::string stdoutOutput = testing::internal::GetCapturedStdout();
            EXPECT_TRUE(stderrOutput.find("Uninteresting") != bsl::string::npos || stdoutOutput.find("Uninteresting") != bsl::string::npos);
        }

        TEST(NaggyMock_Global, MultipleParams)
        {
            testing::internal::CaptureStdout();
            testing::internal::CaptureStderr();
            {
                // 'auto' type deduction requires C++11 or later.
#ifdef BSLS_COMPILERFEATURES_FULL_CPP11
                auto mock = BONOBO_MOCK(&sample_function_2);
#else
                bsl::shared_ptr<GMock<int(int, int)> > mock = BONOBO_MOCK(&sample_function_2);
#endif
                // No expectations set on the mock.
                // All calls to the mocked function will be "uninteresting".
                // Naggy mock (default) SHOULD report uninteresting calls.
                sample_function_2(true, 42);
            }
            bsl::string stderrOutput = testing::internal::GetCapturedStderr();
            bsl::string stdoutOutput = testing::internal::GetCapturedStdout();
            EXPECT_TRUE(stderrOutput.find("Uninteresting") != bsl::string::npos || stdoutOutput.find("Uninteresting") != bsl::string::npos);
        }

        TEST(NaggyMock_Global, LvalueReference)
        {
            testing::internal::CaptureStdout();
            testing::internal::CaptureStderr();
            {
                // 'auto' type deduction requires C++11 or later.
#ifdef BSLS_COMPILERFEATURES_FULL_CPP11
                auto mock = BONOBO_MOCK(&sample_function_3);
#else
                bsl::shared_ptr<GMock<int(bsl::string&)> > mock = BONOBO_MOCK(&sample_function_3);
#endif
                bsl::string str("test");
                // No expectations set on the mock.
                // All calls to the mocked function will be "uninteresting".
                // Naggy mock (default) SHOULD report uninteresting calls.
                sample_function_3(str);
            }
            bsl::string stderrOutput = testing::internal::GetCapturedStderr();
            bsl::string stdoutOutput = testing::internal::GetCapturedStdout();
            EXPECT_TRUE(stderrOutput.find("Uninteresting") != bsl::string::npos || stdoutOutput.find("Uninteresting") != bsl::string::npos);
        }

// Rvalue references require C++11 or later.
#ifdef BSLS_COMPILERFEATURES_FULL_CPP11
        TEST(NaggyMock_Global, RvalueReference)
        {
            testing::internal::CaptureStdout();
            testing::internal::CaptureStderr();
            {
                // 'auto' type deduction requires C++11 or later.
    #ifdef BSLS_COMPILERFEATURES_FULL_CPP11
                auto mock = BONOBO_MOCK(&sample_function_4);
    #else
                bsl::shared_ptr<GMock<int(bsl::string&&)> > mock = BONOBO_MOCK(&sample_function_4);
    #endif
                // No expectations set on the mock.
                // All calls to the mocked function will be "uninteresting".
                // Naggy mock (default) SHOULD report uninteresting calls.
                sample_function_4(makeFooStr());
            }
            bsl::string stderrOutput = testing::internal::GetCapturedStderr();
            bsl::string stdoutOutput = testing::internal::GetCapturedStdout();
            EXPECT_TRUE(stderrOutput.find("Uninteresting") != bsl::string::npos || stdoutOutput.find("Uninteresting") != bsl::string::npos);
        }
#endif

        //==============================================================================
        // STRICT MOCK TESTS: GLOBAL FUNCTIONS
        //==============================================================================

        TEST(StrictMock_Global, NoParams)
        {
            // 'auto' type deduction requires C++11 or later.
#ifdef BSLS_COMPILERFEATURES_FULL_CPP11
            auto mock = BONOBO_MOCK_STRICT(&sample_function);
#else
            bsl::shared_ptr<GMock<bool()> > mock = BONOBO_MOCK_STRICT(&sample_function);
#endif
            EXPECT_NONFATAL_FAILURE(
                {
                    // No expectations set on the mock.
                    // All calls to the mocked function will be "uninteresting".
                    // They should trigger the strict mock failure.
                    sample_function();
                },
                "Uninteresting mock function call");
        }

        TEST(StrictMock_Global, MultipleParams)
        {
            // 'auto' type deduction requires C++11 or later.
#ifdef BSLS_COMPILERFEATURES_FULL_CPP11
            auto mock = BONOBO_MOCK_STRICT(&sample_function_2);
#else
            bsl::shared_ptr<GMock<int(int, int)> > mock = BONOBO_MOCK_STRICT(&sample_function_2);
#endif
            EXPECT_NONFATAL_FAILURE(
                {
                    // No expectations set on the mock.
                    // All calls to the mocked function will be "uninteresting".
                    // They should trigger the strict mock failure.
                    sample_function_2(1, 2);
                },
                "Uninteresting mock function call");
        }

        TEST(StrictMock_Global, LvalueReference)
        {
            // 'auto' type deduction requires C++11 or later.
#ifdef BSLS_COMPILERFEATURES_FULL_CPP11
            auto mock = BONOBO_MOCK_STRICT(&sample_function_3);
#else
            bsl::shared_ptr<GMock<int(bsl::string&)> > mock = BONOBO_MOCK_STRICT(&sample_function_3);
#endif
            EXPECT_NONFATAL_FAILURE(
                {
                    bsl::string str("test");

                    // No expectations set on the mock.
                    // All calls to the mocked function will be "uninteresting".
                    // They should trigger the strict mock failure.
                    sample_function_3(str);
                },
                "Uninteresting mock function call");
        }

// Rvalue references require C++11 or later.
#ifdef BSLS_COMPILERFEATURES_FULL_CPP11
        TEST(StrictMock_Global, RvalueReference)
        {
            EXPECT_NONFATAL_FAILURE(
                {
                    auto mock = BONOBO_MOCK_STRICT(&sample_function_4);
                    // No expectations set on the mock.
                    // All calls to the mocked function will be "uninteresting".
                    // They should trigger the strict mock failure.
                    sample_function_4(makeFooStr());
                },
                "Uninteresting mock function call");
        }
#endif

        //============================================================================
        // NiceMock tests
        //============================================================================

        TEST(NiceMock_Global, NoParams)
        {
            testing::internal::CaptureStdout();
            testing::internal::CaptureStderr();
            {
                // 'auto' type deduction requires C++11 or later.
#ifdef BSLS_COMPILERFEATURES_FULL_CPP11
                auto mock = BONOBO_MOCK_NICE(&sample_function);
#else
                bsl::shared_ptr<GMock<bool()> > mock = BONOBO_MOCK_NICE(&sample_function);
#endif
                // No expectations set on the mock.
                // All calls to the mocked function will be "uninteresting".
                // NiceMock should NOT report uninteresting calls.
                sample_function();
            }
            bsl::string stderrOutput = testing::internal::GetCapturedStderr();
            bsl::string stdoutOutput = testing::internal::GetCapturedStdout();
            EXPECT_THAT(stderrOutput, Not(HasSubstr("Uninteresting")));
            EXPECT_THAT(stdoutOutput, Not(HasSubstr("Uninteresting")));
        }

        TEST(NiceMock_Global, MultipleParams)
        {
            testing::internal::CaptureStdout();
            testing::internal::CaptureStderr();
            {
                // 'auto' type deduction requires C++11 or later.
#ifdef BSLS_COMPILERFEATURES_FULL_CPP11
                auto mock = BONOBO_MOCK_NICE(&sample_function_2);
#else
                bsl::shared_ptr<GMock<int(int, int)> > mock = BONOBO_MOCK_NICE(&sample_function_2);
#endif
                // No expectations set on the mock.
                // All calls to the mocked function will be "uninteresting".
                // NiceMock should NOT report uninteresting calls.
                sample_function_2(1, 2);
            }
            bsl::string stderrOutput = testing::internal::GetCapturedStderr();
            bsl::string stdoutOutput = testing::internal::GetCapturedStdout();
            EXPECT_THAT(stderrOutput, Not(HasSubstr("Uninteresting")));
            EXPECT_THAT(stdoutOutput, Not(HasSubstr("Uninteresting")));
        }

        TEST(NiceMock_Global, LvalueReference)
        {
            testing::internal::CaptureStdout();
            testing::internal::CaptureStderr();
            {
                // 'auto' type deduction requires C++11 or later.
#ifdef BSLS_COMPILERFEATURES_FULL_CPP11
                auto mock = BONOBO_MOCK_NICE(&sample_function_3);
#else
                bsl::shared_ptr<GMock<int(bsl::string&)> > mock = BONOBO_MOCK_NICE(&sample_function_3);
#endif
                bsl::string str("test");

                // No expectations set on the mock.
                // All calls to the mocked function will be "uninteresting".
                // NiceMock should NOT report uninteresting calls.
                sample_function_3(str);
            }
            bsl::string stderrOutput = testing::internal::GetCapturedStderr();
            bsl::string stdoutOutput = testing::internal::GetCapturedStdout();
            EXPECT_THAT(stderrOutput, Not(HasSubstr("Uninteresting")));
            EXPECT_THAT(stdoutOutput, Not(HasSubstr("Uninteresting")));
        }

// Rvalue references require C++11 or later.
#ifdef BSLS_COMPILERFEATURES_FULL_CPP11
        TEST(NiceMock_Global, RvalueReference)
        {
            testing::internal::CaptureStdout();
            testing::internal::CaptureStderr();
            {
                auto mock = BONOBO_MOCK_NICE(&sample_function_4);
                // No expectations set on the mock.
                // All calls to the mocked function will be "uninteresting".
                // NiceMock should NOT report uninteresting calls.
                sample_function_4(makeFooStr());
            }
            bsl::string stderrOutput = testing::internal::GetCapturedStderr();
            bsl::string stdoutOutput = testing::internal::GetCapturedStdout();
            EXPECT_THAT(stderrOutput, Not(HasSubstr("Uninteresting")));
            EXPECT_THAT(stdoutOutput, Not(HasSubstr("Uninteresting")));
        }
#endif

    } // namespace test
} // namespace bonobomock
} // namespace BloombergLP
