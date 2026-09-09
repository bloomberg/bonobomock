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

        // The SampleClassNonVirtual class contains static, non-virtual and const member functions for us to mock.
        class SampleClassNonVirtual {
        public:
            BONOBO_MOCK_DISABLE_FUNCTION_OPTIMIZATION_START(sample_function)
            static bool sample_function(bool in)
            {
                volatile bool _r = in;
                return _r;
            }
            BONOBO_MOCK_DISABLE_FUNCTION_OPTIMIZATION_END(sample_function)

            BONOBO_MOCK_DISABLE_FUNCTION_OPTIMIZATION_START(member_function)
            int member_function(bool in)
            {
                volatile int _r = in ? 1 : 0;
                return _r;
            }
            BONOBO_MOCK_DISABLE_FUNCTION_OPTIMIZATION_END(member_function)

            BONOBO_MOCK_DISABLE_FUNCTION_OPTIMIZATION_START(const_member_function)
            int const_member_function(bool in) const
            {
                volatile int _r = in ? 10 : -10;
                return _r;
            }
            BONOBO_MOCK_DISABLE_FUNCTION_OPTIMIZATION_END(const_member_function)
        };

        // This function will be used to demonstrate that BonoboMock can intercept
        // member function calls on objects the test does not control: the
        // object is created inside this function, yet the mock still takes
        // effect.
        BONOBO_MOCK_DISABLE_FUNCTION_OPTIMIZATION_START(non_virtual_member_wrapper)
        int non_virtual_member_wrapper()
        {
            bool flag = SampleClassNonVirtual::sample_function(false);
            SampleClassNonVirtual obj;
            return obj.member_function(flag);
        }
        BONOBO_MOCK_DISABLE_FUNCTION_OPTIMIZATION_END(non_virtual_member_wrapper)

        // Same as above, but with a const member function.
        int non_virtual_const_member_wrapper()
        {
            SampleClassNonVirtual obj;
            return obj.const_member_function(false);
        }

        class TestLink {
        public:
            TestLink()
            {
                x = 0;
            }
            int x;
        };

        BONOBO_MOCK_DISABLE_FUNCTION_OPTIMIZATION_START(test_linkage)
        TestLink test_linkage()
        {
            TestLink obj;
            return obj;
        }
        BONOBO_MOCK_DISABLE_FUNCTION_OPTIMIZATION_END(test_linkage)

        TEST(Nonvirtual, Mock_static)
        {
            // Only mock the static function `sample_function`
            // 'auto' type deduction requires C++11 or later.
#ifdef BSLS_COMPILERFEATURES_FULL_CPP11
            auto mock = BONOBO_MOCK(&SampleClassNonVirtual::sample_function);
#else
            bsl::shared_ptr<GMock<bool(bool)> > mock = BONOBO_MOCK(&SampleClassNonVirtual::sample_function);
#endif

            // Defined the mocked function for `sample_function`.
            // BONOBO_MOCK_FUNCTION is taking input `false`, which matches the signature in `non_virtual_member_wrapper`.
            // Return true.
            EXPECT_CALL(*mock, BONOBO_MOCK_FUNCTION(false))
                .Times(1)
                .WillOnce(Return(true));

            EXPECT_EQ(1, non_virtual_member_wrapper());

            // Tell bonobomock to stop mocking, use the original sample_function.
            mock->restore();

            EXPECT_EQ(0, non_virtual_member_wrapper());
        }

        TEST(Nonvirtual, Mock_static_and_nonvirtual)
        {
            // Mock the static function `sample_function`
            // 'auto' type deduction requires C++11 or later.
#ifdef BSLS_COMPILERFEATURES_FULL_CPP11
            auto mock1 = BONOBO_MOCK(&SampleClassNonVirtual::sample_function);
#else
            bsl::shared_ptr<GMock<bool(bool)> > mock1 = BONOBO_MOCK(&SampleClassNonVirtual::sample_function);
#endif

            // Mock the non-virtual function `member_function`
            // 'auto' type deduction requires C++11 or later.
#ifdef BSLS_COMPILERFEATURES_FULL_CPP11
            auto mock2 = BONOBO_MOCK(&SampleClassNonVirtual::member_function);
#else
            bsl::shared_ptr<GMock<int(void*, bool)> > mock2 = BONOBO_MOCK(&SampleClassNonVirtual::member_function);
#endif

            // Defined the mocked function for `sample_function`.
            // BONOBO_MOCK_FUNCTION is taking input `false`, which matches the signature in `non_virtual_member_wrapper`.
            // Return true.
            EXPECT_CALL(*mock1, BONOBO_MOCK_FUNCTION(false))
                .Times(1)
                .WillOnce(Return(true));

            // Defined the mocked function for `member_function`.
            // The first `_` of BONOBO_MOCK_FUNCTION's inputs means we want to mock all objects of class SampleClassNonVirtual.
            // BONOBO_MOCK_FUNCTION is taking input `true`, because the mocked sample_function returns true.
            // Return 100.
            EXPECT_CALL(*mock2, BONOBO_MOCK_FUNCTION(_, true))
                .Times(1)
                .WillOnce(Return(100));

            EXPECT_EQ(100, non_virtual_member_wrapper());

            // Tell bonobomock to stop mocking, use the original sample_function.
            mock1->restore();
            mock2->restore();

            EXPECT_EQ(0, non_virtual_member_wrapper());
        }

        TEST(Nonvirtual, Mock_nonvirtual)
        {
            // Mock the non-virtual function `member_function`
            // 'auto' type deduction requires C++11 or later.
#ifdef BSLS_COMPILERFEATURES_FULL_CPP11
            auto mock = BONOBO_MOCK(&SampleClassNonVirtual::member_function);
#else
            bsl::shared_ptr<GMock<int(void*, bool)> > mock = BONOBO_MOCK(&SampleClassNonVirtual::member_function);
#endif

            // Defined the 2nd mocked function for `member_function`.
            // BONOBO_MOCK_FUNCTION is taking any input; using _ as the first
            // argument matches calls on all instances.
            // Return 100.
            EXPECT_CALL(*mock, BONOBO_MOCK_FUNCTION(_, _))
                .Times(1)
                .WillOnce(Return(100));

            SampleClassNonVirtual obj;
            // Defined the 1st and 3rd mocked functions for `member_function`.
            // BONOBO_MOCK_FUNCTION is taking any input; using &obj as the first
            // argument matches calls only on this specific instance.
            // Return 200 and 250.
            EXPECT_CALL(*mock, BONOBO_MOCK_FUNCTION(&obj, _))
                .Times(2)
                .WillOnce(Return(200))
                .WillOnce(Return(250));

            EXPECT_EQ(200, obj.member_function(true));
            EXPECT_EQ(100, non_virtual_member_wrapper());
            EXPECT_EQ(250, obj.member_function(true));

            // Tell bonobomock to stop mocking, use the original sample_function.
            mock->restore();

            EXPECT_EQ(1, obj.member_function(true));
            EXPECT_EQ(0, non_virtual_member_wrapper());
        }

        TEST(Nonvirtual, Mock_nonvirtual_const_member)
        {
            // Mock the const non-virtual function `member_function`
            // 'auto' type deduction requires C++11 or later.
#ifdef BSLS_COMPILERFEATURES_FULL_CPP11
            auto mock = BONOBO_MOCK(&SampleClassNonVirtual::const_member_function);
#else
            bsl::shared_ptr<GMock<int(const void*, bool)> > mock = BONOBO_MOCK(&SampleClassNonVirtual::const_member_function);
#endif

            // Defined the 3rd mocked function for `member_function`.
            // BONOBO_MOCK_FUNCTION is taking any input; using _ as the first
            // argument matches calls on all instances.
            // Return 100.
            EXPECT_CALL(*mock, BONOBO_MOCK_FUNCTION(_, _))
                .Times(1)
                .WillOnce(Return(100));

            // Because we are mocking const member method, we need a const object.
            const SampleClassNonVirtual obj;
            // Defined the 1st and 2nd mocked function for `member_function`.
            // BONOBO_MOCK_FUNCTION is taking any input; using &obj as the first
            // argument matches calls only on this specific instance.
            // Return 200.
            EXPECT_CALL(*mock, BONOBO_MOCK_FUNCTION(&obj, _))
                .Times(2)
                .WillOnce(Return(200))
                .WillOnce(Return(250));

            EXPECT_EQ(200, obj.const_member_function(true));
            EXPECT_EQ(250, obj.const_member_function(true));
            EXPECT_EQ(100, non_virtual_const_member_wrapper());

            // Tell bonobomock to stop mocking, use the original sample_function.
            mock->restore();

            EXPECT_EQ(10, obj.const_member_function(true));
            EXPECT_EQ(-10, obj.const_member_function(false));
            EXPECT_EQ(-10, non_virtual_const_member_wrapper());
        }

        //==============================================================================
        // NAGGY MOCK TESTS: NON-VIRTUAL MEMBER FUNCTIONS
        // These tests verify that the default (naggy) mock DOES produce output about
        // uninteresting calls when no expectations are set.
        //==============================================================================

        TEST(NaggyMock_NonVirtual, MemberFunction)
        {
            testing::internal::CaptureStdout();
            testing::internal::CaptureStderr();
            {
                // 'auto' type deduction requires C++11 or later.
#ifdef BSLS_COMPILERFEATURES_FULL_CPP11
                auto mock = BONOBO_MOCK(&SampleClassNonVirtual::member_function);
#else
                bsl::shared_ptr<GMock<int(void*, bool)> > mock = BONOBO_MOCK(&SampleClassNonVirtual::member_function);
#endif
                SampleClassNonVirtual obj;
                // No expectations set on the mock.
                // All calls to the mocked function will be "uninteresting".
                // Naggy mock (default) SHOULD report uninteresting calls.
                obj.member_function(true);
            }
            bsl::string stderrOutput = testing::internal::GetCapturedStderr();
            bsl::string stdoutOutput = testing::internal::GetCapturedStdout();
            EXPECT_TRUE(stderrOutput.find("Uninteresting") != bsl::string::npos || stdoutOutput.find("Uninteresting") != bsl::string::npos);
        }

        TEST(NaggyMock_NonVirtual, ConstMemberFunction)
        {
            testing::internal::CaptureStdout();
            testing::internal::CaptureStderr();
            {
                // 'auto' type deduction requires C++11 or later.
#ifdef BSLS_COMPILERFEATURES_FULL_CPP11
                auto mock = BONOBO_MOCK(&SampleClassNonVirtual::const_member_function);
#else
                bsl::shared_ptr<GMock<int(const void*, bool)> > mock = BONOBO_MOCK(&SampleClassNonVirtual::const_member_function);
#endif
                const SampleClassNonVirtual obj;
                // No expectations set on the mock.
                // All calls to the mocked function will be "uninteresting".
                // Naggy mock (default) SHOULD report uninteresting calls.
                obj.const_member_function(true);
            }
            bsl::string stderrOutput = testing::internal::GetCapturedStderr();
            bsl::string stdoutOutput = testing::internal::GetCapturedStdout();
            EXPECT_TRUE(stderrOutput.find("Uninteresting") != bsl::string::npos || stdoutOutput.find("Uninteresting") != bsl::string::npos);
        }

        //==============================================================================
        // STRICT MOCK TESTS: NON-VIRTUAL MEMBER FUNCTIONS
        //==============================================================================

        TEST(StrictMock_NonVirtual, MemberFunction)
        {
            // 'auto' type deduction requires C++11 or later.
#ifdef BSLS_COMPILERFEATURES_FULL_CPP11
            auto mock = BONOBO_MOCK_STRICT(&SampleClassNonVirtual::member_function);
#else
            bsl::shared_ptr<GMock<int(void*, bool)> > mock = BONOBO_MOCK_STRICT(&SampleClassNonVirtual::member_function);
#endif
            EXPECT_NONFATAL_FAILURE(
                {
                    SampleClassNonVirtual obj;
                    // No expectations set on the mock.
                    // All calls to the mocked function will be "uninteresting".
                    // They should trigger the strict mock failure.
                    obj.member_function(true);
                },
                "Uninteresting mock function call");
        }

        TEST(StrictMock_NonVirtual, ConstMemberFunction)
        {
            // 'auto' type deduction requires C++11 or later.
#ifdef BSLS_COMPILERFEATURES_FULL_CPP11
            auto mock = BONOBO_MOCK_STRICT(&SampleClassNonVirtual::const_member_function);
#else
            bsl::shared_ptr<GMock<int(const void*, bool)> > mock = BONOBO_MOCK_STRICT(&SampleClassNonVirtual::const_member_function);
#endif
            EXPECT_NONFATAL_FAILURE(
                {
                    const SampleClassNonVirtual obj;
                    // No expectations set on the mock.
                    // All calls to the mocked function will be "uninteresting".
                    // They should trigger the strict mock failure.
                    obj.const_member_function(true);
                },
                "Uninteresting mock function call");
        }

        //==============================================================================
        // NICE MOCK TESTS: NON-VIRTUAL MEMBER FUNCTIONS
        //==============================================================================

        TEST(NiceMock_NonVirtual, MemberFunction)
        {
            testing::internal::CaptureStdout();
            testing::internal::CaptureStderr();
            {
                // 'auto' type deduction requires C++11 or later.
#ifdef BSLS_COMPILERFEATURES_FULL_CPP11
                auto mock = BONOBO_MOCK_NICE(&SampleClassNonVirtual::member_function);
#else
                bsl::shared_ptr<GMock<int(void*, bool)> > mock = BONOBO_MOCK_NICE(&SampleClassNonVirtual::member_function);
#endif
                SampleClassNonVirtual obj;
                // No expectations set on the mock.
                // All calls to the mocked function will be "uninteresting".
                // NiceMock should NOT report uninteresting calls.
                obj.member_function(true);
            }
            bsl::string stderrOutput = testing::internal::GetCapturedStderr();
            bsl::string stdoutOutput = testing::internal::GetCapturedStdout();
            EXPECT_THAT(stderrOutput, Not(HasSubstr("Uninteresting")));
            EXPECT_THAT(stdoutOutput, Not(HasSubstr("Uninteresting")));
        }

        TEST(NiceMock_NonVirtual, ConstMemberFunction)
        {
            testing::internal::CaptureStdout();
            testing::internal::CaptureStderr();
            {
                // 'auto' type deduction requires C++11 or later.
#ifdef BSLS_COMPILERFEATURES_FULL_CPP11
                auto mock = BONOBO_MOCK_NICE(&SampleClassNonVirtual::const_member_function);
#else
                bsl::shared_ptr<GMock<int(const void*, bool)> > mock = BONOBO_MOCK_NICE(&SampleClassNonVirtual::const_member_function);
#endif
                const SampleClassNonVirtual obj;
                // No expectations set on the mock.
                // All calls to the mocked function will be "uninteresting".
                // NiceMock should NOT report uninteresting calls.
                obj.const_member_function(true);
            }
            bsl::string stderrOutput = testing::internal::GetCapturedStderr();
            bsl::string stdoutOutput = testing::internal::GetCapturedStdout();
            EXPECT_THAT(stderrOutput, Not(HasSubstr("Uninteresting")));
            EXPECT_THAT(stdoutOutput, Not(HasSubstr("Uninteresting")));
        }

    } // close test namespace
} // close package namespace
} // close enterprise namespace
