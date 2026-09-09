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

        class BaseClassProctected {
        protected:
            virtual bool protected_virtual_function(bool) = 0;
        };

        // The SampleClassProtected class contains a protected for us to mock.
        class SampleClassProtected : public BaseClassProctected {
        public:
            static bool sample_function(bool in)
            {
                return in;
            }

            int call_protected(int* in)
            {
                return protected_member_function(in);
            }

            bool call_protected_virtual(bool in)
            {
                return protected_virtual_function(in);
            }

        protected:
            BONOBO_MOCK_DISABLE_FUNCTION_OPTIMIZATION_START(protected_member_function)
            int protected_member_function(int* in)
            {
                volatile int _r = *in;
                return _r;
            }
            BONOBO_MOCK_DISABLE_FUNCTION_OPTIMIZATION_END(protected_member_function)

            virtual bool protected_virtual_function(bool in)
            {
                return !in;
            }
        };

        // To mock protected method, we need to get the pointer of it.
        // Using a derived class to get the pointer through public interface.
        class childClass : public SampleClassProtected {
        public:
            typedef int (childClass::*func_type)(int*);

            typedef bool (childClass::*func_type_virtual)(bool);

            static func_type get_func()
            {
                return &childClass::protected_member_function;
            }

            static func_type_virtual get_virtual_func()
            {
                return &childClass::protected_virtual_function;
            }

            static bool get_virtual_func_type(bool in)
            {
                childClass obj;
                return obj.protected_virtual_function(in);
            }
        };

        TEST(Protected, Mock_nonvirtual_protected)
        {
            // Mock the non-virtual function `protected_member_function`
            // 'auto' type deduction requires C++11 or later.
#ifdef BSLS_COMPILERFEATURES_FULL_CPP11
            auto functor = childClass::get_func();
            auto mock = BONOBO_MOCK(functor);
#else
            bsl::shared_ptr<GMock<int(void*, int*)> > mock = BONOBO_MOCK(childClass::get_func());
#endif

            SampleClassProtected obj;
            // Defined the mocked function for `protected_member_function`.
            // BONOBO_MOCK_FUNCTION is taking any input and object.
            // Return 100.
            EXPECT_CALL(*mock, BONOBO_MOCK_FUNCTION(_, _))
                .Times(1)
                .WillOnce(Return(100));

            int input = 10;
            EXPECT_EQ(100, obj.call_protected(&input));

            // Tell bonobomock to stop mocking, use the original sample_function.
            mock->restore();

            EXPECT_EQ(10, obj.call_protected(&input));
        }

        TEST(Protected, Mock_virtual_protected)
        {
            // Mock the virtual function `protected_virtual_function`
            // using a derived class to expose the PMF via get_virtual_func().
#ifdef BSLS_COMPILERFEATURES_FULL_CPP11
            auto mock = BONOBO_MOCK_VIRTUAL(childClass::get_virtual_func());
#else
            bsl::shared_ptr<GMock<bool(void*, bool)> > mock = BONOBO_MOCK_VIRTUAL(childClass::get_virtual_func());
#endif

            SampleClassProtected obj;
            // Defined the mocked function for `protected_virtual_function`.
            // BONOBO_MOCK_FUNCTION is taking any input and the object.
            // Return true.
            EXPECT_CALL(*mock, BONOBO_MOCK_FUNCTION(_, _))
                .Times(1)
                .WillOnce(Return(true));

            EXPECT_TRUE(obj.call_protected_virtual(true));

            // Tell bonobomock to stop mocking, use the original sample_function.
            mock->restore();

            EXPECT_FALSE(obj.call_protected_virtual(true));
        }

        //==============================================================================
        // NAGGY MOCK TESTS: PROTECTED MEMBER FUNCTIONS
        // These tests verify that the default (naggy) mock DOES produce output about
        // uninteresting calls when no expectations are set.
        //==============================================================================

        TEST(NaggyMock_Protected, NonVirtualProtected)
        {
            testing::internal::CaptureStdout();
            testing::internal::CaptureStderr();
            {
                // 'auto' type deduction requires C++11 or later.
#ifdef BSLS_COMPILERFEATURES_FULL_CPP11
                auto functor = childClass::get_func();
                auto mock = BONOBO_MOCK(functor);
#else
                bsl::shared_ptr<GMock<int(void*, int*)> > mock = BONOBO_MOCK(childClass::get_func());
#endif
                SampleClassProtected obj;
                int val = 42;
                // No expectations set on the mock.
                // All calls to the mocked function will be "uninteresting".
                // Naggy mock (default) SHOULD report uninteresting calls.
                obj.call_protected(&val);
            }
            bsl::string stderrOutput = testing::internal::GetCapturedStderr();
            bsl::string stdoutOutput = testing::internal::GetCapturedStdout();
            EXPECT_TRUE(stderrOutput.find("Uninteresting") != bsl::string::npos || stdoutOutput.find("Uninteresting") != bsl::string::npos);
        }

        TEST(NaggyMock_Protected, VirtualProtected)
        {
            testing::internal::CaptureStdout();
            testing::internal::CaptureStderr();
            {
#ifdef BSLS_COMPILERFEATURES_FULL_CPP11
                auto mock = BONOBO_MOCK_VIRTUAL(childClass::get_virtual_func());
#else
                bsl::shared_ptr<GMock<bool(void*, bool)> > mock = BONOBO_MOCK_VIRTUAL(childClass::get_virtual_func());
#endif
                SampleClassProtected obj;
                // No expectations set on the mock.
                // All calls to the mocked function will be "uninteresting".
                // Naggy mock (default) SHOULD report uninteresting calls.
                obj.call_protected_virtual(true);
            }
            bsl::string stderrOutput = testing::internal::GetCapturedStderr();
            bsl::string stdoutOutput = testing::internal::GetCapturedStdout();
            EXPECT_TRUE(stderrOutput.find("Uninteresting") != bsl::string::npos || stdoutOutput.find("Uninteresting") != bsl::string::npos);
        }

        //==============================================================================
        // STRICT MOCK TESTS: PROTECTED MEMBER FUNCTIONS
        //==============================================================================

        TEST(StrictMock_Protected, NonVirtualProtected)
        {
            // 'auto' type deduction requires C++11 or later.
#ifdef BSLS_COMPILERFEATURES_FULL_CPP11
            auto functor = childClass::get_func();
            auto mock = BONOBO_MOCK_STRICT(functor);
#else
            bsl::shared_ptr<GMock<int(void*, int*)> > mock = BONOBO_MOCK_STRICT(childClass::get_func());
#endif
            EXPECT_NONFATAL_FAILURE(
                {
                    SampleClassProtected obj;
                    int val = 42;
                    // No expectations set on the mock.
                    // All calls to the mocked function will be "uninteresting".
                    // They should trigger the strict mock failure.
                    obj.call_protected(&val);
                },
                "Uninteresting mock function call");
        }

        TEST(StrictMock_Protected, VirtualProtected)
        {
#ifdef BSLS_COMPILERFEATURES_FULL_CPP11
            auto mock = BONOBO_MOCK_VIRTUAL_STRICT(childClass::get_virtual_func());
#else
            bsl::shared_ptr<GMock<bool(void*, bool)> > mock = BONOBO_MOCK_VIRTUAL_STRICT(childClass::get_virtual_func());
#endif
            EXPECT_NONFATAL_FAILURE(
                {
                    SampleClassProtected obj;
                    // No expectations set on the mock.
                    // All calls to the mocked function will be "uninteresting".
                    // They should trigger the strict mock failure.
                    obj.call_protected_virtual(true);
                },
                "Uninteresting mock function call");
        }

        //==============================================================================
        // NICE MOCK TESTS: PROTECTED MEMBER FUNCTIONS
        //==============================================================================

        TEST(NiceMock_Protected, NonVirtualProtected)
        {
            testing::internal::CaptureStdout();
            testing::internal::CaptureStderr();
            {
                // 'auto' type deduction requires C++11 or later.
#ifdef BSLS_COMPILERFEATURES_FULL_CPP11
                auto functor = childClass::get_func();
                auto mock = BONOBO_MOCK_NICE(functor);
#else
                bsl::shared_ptr<GMock<int(void*, int*)> > mock = BONOBO_MOCK_NICE(childClass::get_func());
#endif
                SampleClassProtected obj;
                int val = 42;
                // No expectations set on the mock.
                // All calls to the mocked function will be "uninteresting".
                // NiceMock should NOT report uninteresting calls.
                obj.call_protected(&val);
            }
            bsl::string stderrOutput = testing::internal::GetCapturedStderr();
            bsl::string stdoutOutput = testing::internal::GetCapturedStdout();
            EXPECT_THAT(stderrOutput, Not(HasSubstr("Uninteresting")));
            EXPECT_THAT(stdoutOutput, Not(HasSubstr("Uninteresting")));
        }

        TEST(NiceMock_Protected, VirtualProtected)
        {
            testing::internal::CaptureStdout();
            testing::internal::CaptureStderr();
            {
#ifdef BSLS_COMPILERFEATURES_FULL_CPP11
                auto mock = BONOBO_MOCK_VIRTUAL_NICE(childClass::get_virtual_func());
#else
                bsl::shared_ptr<GMock<bool(void*, bool)> > mock = BONOBO_MOCK_VIRTUAL_NICE(childClass::get_virtual_func());
#endif
                SampleClassProtected obj;
                // No expectations set on the mock.
                // All calls to the mocked function will be "uninteresting".
                // NiceMock should NOT report uninteresting calls.
                obj.call_protected_virtual(true);
            }
            bsl::string stderrOutput = testing::internal::GetCapturedStderr();
            bsl::string stdoutOutput = testing::internal::GetCapturedStdout();
            EXPECT_THAT(stderrOutput, Not(HasSubstr("Uninteresting")));
            EXPECT_THAT(stdoutOutput, Not(HasSubstr("Uninteresting")));
        }

    } // close test namespace
} // close package namespace
} // close enterprise namespace
