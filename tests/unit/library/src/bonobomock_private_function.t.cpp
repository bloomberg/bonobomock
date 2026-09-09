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
#include <bsl_unordered_set.h>
#include <bsls_compilerfeatures.h>

#include <bonobomock_optimization_macros_api.h>

namespace BloombergLP {
namespace bonobomock {
    namespace test {
        using namespace ::testing;

        // This class has a private virtual function for us to mock.
        class SampleClassPrivate {
        public:
            static int call_private_static(int* in)
            {
                return private_static_function(in);
            }

            int call_private(int* in)
            {
                return private_member_function(in);
            }

            int call_private_const(int* in) const
            {
                return private_member_function_const(in);
            }

            int call_private_virtual(int* in)
            {
                return private_member_function_virtual(in);
            }

            int call_private_virtual_const(int* in) const
            {
                return private_member_function_virtual_const(in);
            }

            int call_private_with_static_vars(int* in)
            {
                return private_member_func_with_static_vars(in);
            }

            int call_private_with_static_vars_const(int* in) const
            {
                return private_member_func_with_static_vars_const(in);
            }

        private:
            BONOBO_MOCK_DISABLE_FUNCTION_OPTIMIZATION_START(private_static_function)
            static int private_static_function(int* in)
            {
                volatile int _r = *in;
                return _r;
            }
            BONOBO_MOCK_DISABLE_FUNCTION_OPTIMIZATION_END(private_static_function)

            BONOBO_MOCK_DISABLE_FUNCTION_OPTIMIZATION_START(private_member_function)
            int private_member_function(int* in)
            {
                volatile int _r = *in;
                return _r;
            }
            BONOBO_MOCK_DISABLE_FUNCTION_OPTIMIZATION_END(private_member_function)

            BONOBO_MOCK_DISABLE_FUNCTION_OPTIMIZATION_START(private_member_function_const)
            int private_member_function_const(int* in) const
            {
                volatile int _r = *in;
                return _r;
            }
            BONOBO_MOCK_DISABLE_FUNCTION_OPTIMIZATION_END(private_member_function_const)

            BONOBO_MOCK_DISABLE_FUNCTION_OPTIMIZATION_START(private_member_function_virtual)
            virtual int private_member_function_virtual(int* in)
            {
                volatile int _r = *in;
                return _r;
            }
            BONOBO_MOCK_DISABLE_FUNCTION_OPTIMIZATION_END(private_member_function_virtual)

            BONOBO_MOCK_DISABLE_FUNCTION_OPTIMIZATION_START(private_member_function_virtual_const)
            virtual int private_member_function_virtual_const(int* in) const
            {
                volatile int _r = *in;
                return _r;
            }
            BONOBO_MOCK_DISABLE_FUNCTION_OPTIMIZATION_END(private_member_function_virtual_const)

            BONOBO_MOCK_DISABLE_FUNCTION_OPTIMIZATION_START(private_member_func_with_static_vars)
            int private_member_func_with_static_vars(int* in)
            {
                static bsl::unordered_set<int> someIntegerSet;
                someIntegerSet.insert(3);
                if (someIntegerSet.find(*in) == someIntegerSet.end()) {
                    someIntegerSet.insert(*in);
                }
                volatile int _r = *in;
                return _r;
            }
            BONOBO_MOCK_DISABLE_FUNCTION_OPTIMIZATION_END(private_member_func_with_static_vars)

            BONOBO_MOCK_DISABLE_FUNCTION_OPTIMIZATION_START(private_member_func_with_static_vars_const)
            int private_member_func_with_static_vars_const(int* in) const
            {
                static bsl::unordered_set<int> someIntegerSet;
                someIntegerSet.insert(3);
                if (someIntegerSet.find(*in) == someIntegerSet.end()) {
                    volatile int _r = *in;
                    return _r;
                }
                volatile int _r = *in + 1;
                return _r;
            }
            BONOBO_MOCK_DISABLE_FUNCTION_OPTIMIZATION_END(private_member_func_with_static_vars_const)
        };

        // Signature-conveying free functions: these are never called.
        // They exist only to provide BonoboMock with the function type
        // of the corresponding private function.
        int function_with_same_signature_as_private_static_function(int* in)
        {
            return *in;
        }

        int function_with_same_signature_as_private_member_function(int* in)
        {
            return *in;
        }

        BONOBO_MOCK_DISABLE_FUNCTION_OPTIMIZATION_START(function_with_same_signature_as_private_member_function_const)
        int function_with_same_signature_as_private_member_function_const(int* in)
        {
            volatile int _r = *in;
            return _r;
        }
        BONOBO_MOCK_DISABLE_FUNCTION_OPTIMIZATION_END(function_with_same_signature_as_private_member_function_const)

        int function_with_same_signature_as_private_member_function_virtual(int* in)
        {
            return *in;
        }

        int function_with_same_signature_as_private_member_function_virtual_const(int* in)
        {
            return *in;
        }

        int function_with_same_signature_as_private_member_func_with_static_vars(int* in)
        {
            return *in;
        }

        int function_with_same_signature_as_private_member_func_with_static_vars_const(int* in)
        {
            return *in;
        }

        // This function will be used to demonstrate that BonoboMock can intercept
        // private member function calls on objects the test does not control:
        // the object is created inside this function, yet the mock still takes
        // effect.
        int call_private_via_local_object(int* in)
        {
            SampleClassPrivate obj;
            return obj.call_private(in);
        }

        BONOBO_MOCK_DISABLE_FUNCTION_OPTIMIZATION_START(call_private_const_via_local_object)
        int call_private_const_via_local_object(int* in)
        {
            SampleClassPrivate obj;
            return obj.call_private_const(in);
        }
        BONOBO_MOCK_DISABLE_FUNCTION_OPTIMIZATION_END(call_private_const_via_local_object)

        int call_private_virtual_via_local_object(int* in)
        {
            SampleClassPrivate obj;
            return obj.call_private_virtual(in);
        }

        int call_private_virtual_const_via_local_object(int* in)
        {
            SampleClassPrivate obj;
            return obj.call_private_virtual_const(in);
        }

        int call_private_with_static_vars_via_local_object(int* in)
        {
            SampleClassPrivate obj;
            return obj.call_private_with_static_vars(in);
        }

        int call_private_with_static_vars_const_via_local_object(int* in)
        {
            SampleClassPrivate obj;
            return obj.call_private_with_static_vars_const(in);
        }

        TEST(Private, Mock_non_const_private)
        {
            // Use macro `BONOBO_MOCK_PRIVATE_NON_CONST`
            // for non-const function. The inputs are the class full name, the private method full
            // name, and the function that has the same signature as the private one we are going
            // to mock.
            // 'auto' type deduction requires C++11 or later.
#ifdef BSLS_COMPILERFEATURES_FULL_CPP11
            auto mock = BONOBO_MOCK_PRIVATE_NON_CONST(
                BloombergLP::bonobomock::test::SampleClassPrivate::private_member_function,
                BloombergLP::bonobomock::test::SampleClassPrivate,
                &function_with_same_signature_as_private_member_function);
#else
            bsl::shared_ptr<GMock<int(void*, int*)> > mock = BONOBO_MOCK_PRIVATE_NON_CONST(
                BloombergLP::bonobomock::test::SampleClassPrivate::private_member_function,
                BloombergLP::bonobomock::test::SampleClassPrivate,
                &function_with_same_signature_as_private_member_function);
#endif

            SampleClassPrivate obj;
            // BONOBO_MOCK_FUNCTION is taking any input; using _ as the first
            // argument matches calls on all instances.
            // Return 100.
            EXPECT_CALL(*mock, BONOBO_MOCK_FUNCTION(_, _))
                .Times(1)
                .WillOnce(Return(100));

            // We want to mock the specific `obj` in this case.
            // We don't care about the input.
            // Return 100.
            EXPECT_CALL(*mock, BONOBO_MOCK_FUNCTION(&obj, _))
                .Times(1)
                .WillOnce(Return(200));

            int input = 10;
            EXPECT_EQ(200, obj.call_private(&input));
            EXPECT_EQ(100, call_private_via_local_object(&input));

            // Tell bonobomock to stop mocking, use the original sample_function.
            mock->restore();

            EXPECT_EQ(10, obj.call_private(&input));
            EXPECT_EQ(10, call_private_via_local_object(&input));
        }

        TEST(Private, Mock_const_private)
        {
            // Use macro `BONOBO_MOCK_PRIVATE_NON_CONST`
            // for non-const function. The inputs are the class full name, the private method full
            // name, and the function that has the same signature as the private one we are going
            // to mock.
            // 'auto' type deduction requires C++11 or later.
#ifdef BSLS_COMPILERFEATURES_FULL_CPP11
            auto mock = BONOBO_MOCK_PRIVATE_CONST(
                BloombergLP::bonobomock::test::SampleClassPrivate::private_member_function_const,
                BloombergLP::bonobomock::test::SampleClassPrivate,
                &function_with_same_signature_as_private_member_function_const);
#else
            bsl::shared_ptr<GMock<int(const void*, int*)> > mock = BONOBO_MOCK_PRIVATE_CONST(
                BloombergLP::bonobomock::test::SampleClassPrivate::private_member_function_const,
                BloombergLP::bonobomock::test::SampleClassPrivate,
                &function_with_same_signature_as_private_member_function_const);
#endif

            SampleClassPrivate obj;
            // BONOBO_MOCK_FUNCTION is taking any input; using _ as the first
            // argument matches calls on all instances.
            // Return 100.
            EXPECT_CALL(*mock, BONOBO_MOCK_FUNCTION(_, _))
                .Times(1)
                .WillOnce(Return(100));

            // We want to mock the specific `obj` in this case.
            // We don't care about the input.
            // Return 100.
            EXPECT_CALL(*mock, BONOBO_MOCK_FUNCTION(&obj, _))
                .Times(1)
                .WillOnce(Return(200));

            int input = 10;
            EXPECT_EQ(200, obj.call_private_const(&input));
            EXPECT_EQ(100, call_private_const_via_local_object(&input));

            // Tell bonobomock to stop mocking, use the original sample_function.
            mock->restore();

            EXPECT_EQ(10, obj.call_private_const(&input));
            EXPECT_EQ(10, call_private_const_via_local_object(&input));
        }

        TEST(Private, Mock_non_const_virtual_private)
        {
            // Use macro `BONOBO_MOCK_PRIVATE_NON_CONST`
            // for non-const function. The inputs are the class full name, the private method full
            // name, and the function that has the same signature as the private one we are going
            // to mock.
            // 'auto' type deduction requires C++11 or later.
#ifdef BSLS_COMPILERFEATURES_FULL_CPP11
            auto mock = BONOBO_MOCK_PRIVATE_NON_CONST(
                BloombergLP::bonobomock::test::SampleClassPrivate::private_member_function_virtual,
                BloombergLP::bonobomock::test::SampleClassPrivate,
                &function_with_same_signature_as_private_member_function_virtual);
#else
            bsl::shared_ptr<GMock<int(void*, int*)> > mock = BONOBO_MOCK_PRIVATE_NON_CONST(
                BloombergLP::bonobomock::test::SampleClassPrivate::private_member_function_virtual,
                BloombergLP::bonobomock::test::SampleClassPrivate,
                &function_with_same_signature_as_private_member_function_virtual);
#endif

            SampleClassPrivate obj;
            // BONOBO_MOCK_FUNCTION is taking any input; using _ as the first
            // argument matches calls on all instances.
            // Return 100.
            EXPECT_CALL(*mock, BONOBO_MOCK_FUNCTION(_, _))
                .Times(1)
                .WillOnce(Return(100));

            // We want to mock the specific `obj` in this case.
            // We don't care about the input.
            // Return 100.
            EXPECT_CALL(*mock, BONOBO_MOCK_FUNCTION(&obj, _))
                .Times(1)
                .WillOnce(Return(200));

            int input = 10;
            EXPECT_EQ(200, obj.call_private_virtual(&input));
            EXPECT_EQ(100, call_private_virtual_via_local_object(&input));

            // Tell bonobomock to stop mocking, use the original sample_function.
            mock->restore();

            EXPECT_EQ(10, obj.call_private_virtual(&input));
            EXPECT_EQ(10, call_private_virtual_via_local_object(&input));
        }

        TEST(Private, Mock_const_virtual_private)
        {
            // Use macro `BONOBO_MOCK_PRIVATE_NON_CONST`
            // for non-const function. The inputs are the class full name, the private method full
            // name, and the function that has the same signature as the private one we are going
            // to mock.
            // 'auto' type deduction requires C++11 or later.
#ifdef BSLS_COMPILERFEATURES_FULL_CPP11
            auto mock = BONOBO_MOCK_PRIVATE_CONST(
                BloombergLP::bonobomock::test::SampleClassPrivate::private_member_function_virtual_const,
                BloombergLP::bonobomock::test::SampleClassPrivate,
                &function_with_same_signature_as_private_member_function_virtual_const);
#else
            bsl::shared_ptr<GMock<int(const void*, int*)> > mock = BONOBO_MOCK_PRIVATE_CONST(
                BloombergLP::bonobomock::test::SampleClassPrivate::private_member_function_virtual_const,
                BloombergLP::bonobomock::test::SampleClassPrivate,
                &function_with_same_signature_as_private_member_function_virtual_const);
#endif

            SampleClassPrivate obj;
            // BONOBO_MOCK_FUNCTION is taking any input; using _ as the first
            // argument matches calls on all instances.
            // Return 100.
            EXPECT_CALL(*mock, BONOBO_MOCK_FUNCTION(_, _))
                .Times(1)
                .WillOnce(Return(100));

            // We want to mock the specific `obj` in this case.
            // We don't care about the input.
            // Return 100.
            EXPECT_CALL(*mock, BONOBO_MOCK_FUNCTION(&obj, _))
                .Times(1)
                .WillOnce(Return(200));

            int input = 10;
            EXPECT_EQ(200, obj.call_private_virtual_const(&input));
            EXPECT_EQ(100, call_private_virtual_const_via_local_object(&input));

            // Tell bonobomock to stop mocking, use the original sample_function.
            mock->restore();

            EXPECT_EQ(10, obj.call_private_virtual_const(&input));
            EXPECT_EQ(10, call_private_virtual_const_via_local_object(&input));
        }

        TEST(Private, Mock_non_const_private_func_with_static_vars)
        {
            // 'auto' type deduction requires C++11 or later.
#ifdef BSLS_COMPILERFEATURES_FULL_CPP11
            auto mock = BONOBO_MOCK_PRIVATE_NON_CONST(
                BloombergLP::bonobomock::test::SampleClassPrivate::private_member_func_with_static_vars,
                BloombergLP::bonobomock::test::SampleClassPrivate,
                &function_with_same_signature_as_private_member_func_with_static_vars);
#else
            bsl::shared_ptr<GMock<int(void*, int*)> > mock = BONOBO_MOCK_PRIVATE_NON_CONST(
                BloombergLP::bonobomock::test::SampleClassPrivate::private_member_func_with_static_vars,
                BloombergLP::bonobomock::test::SampleClassPrivate,
                &function_with_same_signature_as_private_member_func_with_static_vars);
#endif

            SampleClassPrivate obj;
            // Mock the function and verify the calls
            EXPECT_CALL(*mock, BONOBO_MOCK_FUNCTION(_, _))
                .Times(1)
                .WillOnce(Return(100));

            EXPECT_CALL(*mock, BONOBO_MOCK_FUNCTION(&obj, _))
                .Times(1)
                .WillOnce(Return(200));

            int input = 10;
            EXPECT_EQ(200, obj.call_private_with_static_vars(&input));
            EXPECT_EQ(100, call_private_with_static_vars_via_local_object(&input));

            mock->restore();

            EXPECT_EQ(10, obj.call_private_with_static_vars(&input));
            EXPECT_EQ(10, call_private_with_static_vars_via_local_object(&input));
        }

        TEST(Private, Mock_const_private_func_with_static_vars)
        {
            // 'auto' type deduction requires C++11 or later.
#ifdef BSLS_COMPILERFEATURES_FULL_CPP11
            auto mock = BONOBO_MOCK_PRIVATE_CONST(
                BloombergLP::bonobomock::test::SampleClassPrivate::private_member_func_with_static_vars_const,
                BloombergLP::bonobomock::test::SampleClassPrivate,
                &function_with_same_signature_as_private_member_func_with_static_vars_const);
#else
            bsl::shared_ptr<GMock<int(const void*, int*)> > mock = BONOBO_MOCK_PRIVATE_CONST(
                BloombergLP::bonobomock::test::SampleClassPrivate::private_member_func_with_static_vars_const,
                BloombergLP::bonobomock::test::SampleClassPrivate,
                &function_with_same_signature_as_private_member_func_with_static_vars_const);
#endif

            const SampleClassPrivate obj;
            // Mock the function and verify the calls
            EXPECT_CALL(*mock, BONOBO_MOCK_FUNCTION(_, _))
                .Times(1)
                .WillOnce(Return(100));

            EXPECT_CALL(*mock, BONOBO_MOCK_FUNCTION(&obj, _))
                .Times(1)
                .WillOnce(Return(200));

            int input = 10;
            EXPECT_EQ(200, obj.call_private_with_static_vars_const(&input));
            EXPECT_EQ(100, call_private_with_static_vars_const_via_local_object(&input));

            mock->restore();

            EXPECT_EQ(10, obj.call_private_with_static_vars_const(&input));
            EXPECT_EQ(10, call_private_with_static_vars_const_via_local_object(&input));
        }

        //==============================================================================
        // NAGGY MOCK TESTS: PRIVATE MEMBER FUNCTIONS
        // These tests verify that the default (naggy) mock DOES produce output about
        // uninteresting calls when no expectations are set.
        //==============================================================================

        TEST(NaggyMock_Private, NonConstPrivate)
        {
            testing::internal::CaptureStdout();
            testing::internal::CaptureStderr();
            {
                // 'auto' type deduction requires C++11 or later.
#ifdef BSLS_COMPILERFEATURES_FULL_CPP11
                auto mock = BONOBO_MOCK_PRIVATE_NON_CONST(
                    BloombergLP::bonobomock::test::SampleClassPrivate::private_member_function,
                    BloombergLP::bonobomock::test::SampleClassPrivate,
                    &function_with_same_signature_as_private_member_function);
#else
                bsl::shared_ptr<GMock<int(void*, int*)> > mock = BONOBO_MOCK_PRIVATE_NON_CONST(
                    BloombergLP::bonobomock::test::SampleClassPrivate::private_member_function,
                    BloombergLP::bonobomock::test::SampleClassPrivate,
                    &function_with_same_signature_as_private_member_function);
#endif
                SampleClassPrivate obj;
                int val = 42;
                // No expectations set on the mock.
                // All calls to the mocked function will be "uninteresting".
                // Naggy mock (default) SHOULD report uninteresting calls.
                obj.call_private(&val);
            }
            bsl::string stderrOutput = testing::internal::GetCapturedStderr();
            bsl::string stdoutOutput = testing::internal::GetCapturedStdout();
            EXPECT_TRUE(stderrOutput.find("Uninteresting") != bsl::string::npos || stdoutOutput.find("Uninteresting") != bsl::string::npos);
        }

        TEST(NaggyMock_Private, ConstPrivate)
        {
            testing::internal::CaptureStdout();
            testing::internal::CaptureStderr();
            {
                // 'auto' type deduction requires C++11 or later.
#ifdef BSLS_COMPILERFEATURES_FULL_CPP11
                auto mock = BONOBO_MOCK_PRIVATE_CONST(
                    BloombergLP::bonobomock::test::SampleClassPrivate::private_member_function_const,
                    BloombergLP::bonobomock::test::SampleClassPrivate,
                    &function_with_same_signature_as_private_member_function_const);
#else
                bsl::shared_ptr<GMock<int(const void*, int*)> > mock = BONOBO_MOCK_PRIVATE_CONST(
                    BloombergLP::bonobomock::test::SampleClassPrivate::private_member_function_const,
                    BloombergLP::bonobomock::test::SampleClassPrivate,
                    &function_with_same_signature_as_private_member_function_const);
#endif
                const SampleClassPrivate obj;
                int val = 42;
                // No expectations set on the mock.
                // All calls to the mocked function will be "uninteresting".
                // Naggy mock (default) SHOULD report uninteresting calls.
                obj.call_private_const(&val);
            }
            bsl::string stderrOutput = testing::internal::GetCapturedStderr();
            bsl::string stdoutOutput = testing::internal::GetCapturedStdout();
            EXPECT_TRUE(stderrOutput.find("Uninteresting") != bsl::string::npos || stdoutOutput.find("Uninteresting") != bsl::string::npos);
        }

        //==============================================================================
        // STRICT MOCK TESTS: PRIVATE MEMBER FUNCTIONS
        //==============================================================================

        TEST(StrictMock_Private, NonConstPrivate)
        {
            // 'auto' type deduction requires C++11 or later.
#ifdef BSLS_COMPILERFEATURES_FULL_CPP11
            auto mock = BONOBO_MOCK_PRIVATE_STRICT_NON_CONST(
                BloombergLP::bonobomock::test::SampleClassPrivate::private_member_function,
                BloombergLP::bonobomock::test::SampleClassPrivate,
                &function_with_same_signature_as_private_member_function);
#else
            bsl::shared_ptr<GMock<int(void*, int*)> > mock = BONOBO_MOCK_PRIVATE_STRICT_NON_CONST(
                BloombergLP::bonobomock::test::SampleClassPrivate::private_member_function,
                BloombergLP::bonobomock::test::SampleClassPrivate,
                &function_with_same_signature_as_private_member_function);
#endif
            EXPECT_NONFATAL_FAILURE(
                {
                    SampleClassPrivate obj;
                    int val = 42;
                    // No expectations set on the mock.
                    // All calls to the mocked function will be "uninteresting".
                    // They should trigger the strict mock failure.
                    obj.call_private(&val);
                },
                "Uninteresting mock function call");
        }

        TEST(StrictMock_Private, ConstPrivate)
        {
            // 'auto' type deduction requires C++11 or later.
#ifdef BSLS_COMPILERFEATURES_FULL_CPP11
            auto mock = BONOBO_MOCK_PRIVATE_STRICT_CONST(
                BloombergLP::bonobomock::test::SampleClassPrivate::private_member_function_const,
                BloombergLP::bonobomock::test::SampleClassPrivate,
                &function_with_same_signature_as_private_member_function_const);
#else
            bsl::shared_ptr<GMock<int(const void*, int*)> > mock = BONOBO_MOCK_PRIVATE_STRICT_CONST(
                BloombergLP::bonobomock::test::SampleClassPrivate::private_member_function_const,
                BloombergLP::bonobomock::test::SampleClassPrivate,
                &function_with_same_signature_as_private_member_function_const);
#endif
            EXPECT_NONFATAL_FAILURE(
                {
                    const SampleClassPrivate obj;
                    int val = 42;
                    // No expectations set on the mock.
                    // All calls to the mocked function will be "uninteresting".
                    // They should trigger the strict mock failure.
                    obj.call_private_const(&val);
                },
                "Uninteresting mock function call");
        }

        TEST(StrictMock_Private, VirtualPrivate)
        {
            // 'auto' type deduction requires C++11 or later.
#ifdef BSLS_COMPILERFEATURES_FULL_CPP11
            auto mock = BONOBO_MOCK_PRIVATE_STRICT_NON_CONST(
                BloombergLP::bonobomock::test::SampleClassPrivate::private_member_function_virtual,
                BloombergLP::bonobomock::test::SampleClassPrivate,
                &function_with_same_signature_as_private_member_function_virtual);
#else
            bsl::shared_ptr<GMock<int(void*, int*)> > mock = BONOBO_MOCK_PRIVATE_STRICT_NON_CONST(
                BloombergLP::bonobomock::test::SampleClassPrivate::private_member_function_virtual,
                BloombergLP::bonobomock::test::SampleClassPrivate,
                &function_with_same_signature_as_private_member_function_virtual);
#endif
            EXPECT_NONFATAL_FAILURE(
                {
                    SampleClassPrivate obj;
                    int val = 42;
                    // No expectations set on the mock.
                    // All calls to the mocked function will be "uninteresting".
                    // They should trigger the strict mock failure.
                    obj.call_private_virtual(&val);
                },
                "Uninteresting mock function call");
        }

        TEST(StrictMock_Private, ConstVirtualPrivate)
        {
            // 'auto' type deduction requires C++11 or later.
#ifdef BSLS_COMPILERFEATURES_FULL_CPP11
            auto mock = BONOBO_MOCK_PRIVATE_STRICT_CONST(
                BloombergLP::bonobomock::test::SampleClassPrivate::private_member_function_virtual_const,
                BloombergLP::bonobomock::test::SampleClassPrivate,
                &function_with_same_signature_as_private_member_function_virtual_const);
#else
            bsl::shared_ptr<GMock<int(const void*, int*)> > mock = BONOBO_MOCK_PRIVATE_STRICT_CONST(
                BloombergLP::bonobomock::test::SampleClassPrivate::private_member_function_virtual_const,
                BloombergLP::bonobomock::test::SampleClassPrivate,
                &function_with_same_signature_as_private_member_function_virtual_const);
#endif
            EXPECT_NONFATAL_FAILURE(
                {
                    const SampleClassPrivate obj;
                    int val = 42;
                    // No expectations set on the mock.
                    // All calls to the mocked function will be "uninteresting".
                    // They should trigger the strict mock failure.
                    obj.call_private_virtual_const(&val);
                },
                "Uninteresting mock function call");
        }

        TEST(StrictMock_Private, NonConstPrivateFuncWithStaticVars)
        {
            // 'auto' type deduction requires C++11 or later.
#ifdef BSLS_COMPILERFEATURES_FULL_CPP11
            auto mock = BONOBO_MOCK_PRIVATE_STRICT_NON_CONST(
                BloombergLP::bonobomock::test::SampleClassPrivate::private_member_func_with_static_vars,
                BloombergLP::bonobomock::test::SampleClassPrivate,
                &function_with_same_signature_as_private_member_func_with_static_vars);
#else
            bsl::shared_ptr<GMock<int(void*, int*)> > mock = BONOBO_MOCK_PRIVATE_STRICT_NON_CONST(
                BloombergLP::bonobomock::test::SampleClassPrivate::private_member_func_with_static_vars,
                BloombergLP::bonobomock::test::SampleClassPrivate,
                &function_with_same_signature_as_private_member_func_with_static_vars);
#endif
            EXPECT_NONFATAL_FAILURE(
                {
                    // No expectations set on the mock.
                    // All calls to the mocked function will be "uninteresting".
                    // They should trigger the strict mock failure.
                    SampleClassPrivate obj;
                    int input = 10;
                    obj.call_private_with_static_vars(&input);
                },
                "Uninteresting mock function call");
        }

        TEST(StrictMock_Private, ConstPrivateFuncWithStaticVars)
        {
            // 'auto' type deduction requires C++11 or later.
#ifdef BSLS_COMPILERFEATURES_FULL_CPP11
            auto mock = BONOBO_MOCK_PRIVATE_STRICT_CONST(
                BloombergLP::bonobomock::test::SampleClassPrivate::private_member_func_with_static_vars_const,
                BloombergLP::bonobomock::test::SampleClassPrivate,
                &function_with_same_signature_as_private_member_func_with_static_vars_const);
#else
            bsl::shared_ptr<GMock<int(const void*, int*)> > mock = BONOBO_MOCK_PRIVATE_STRICT_CONST(
                BloombergLP::bonobomock::test::SampleClassPrivate::private_member_func_with_static_vars_const,
                BloombergLP::bonobomock::test::SampleClassPrivate,
                &function_with_same_signature_as_private_member_func_with_static_vars_const);
#endif
            EXPECT_NONFATAL_FAILURE(
                {
                    // No expectations set on the mock.
                    // All calls to the mocked function will be "uninteresting".
                    // They should trigger the strict mock failure.
                    SampleClassPrivate obj;
                    int input = 10;
                    obj.call_private_with_static_vars_const(&input);
                },
                "Uninteresting mock function call");
        }

        //==============================================================================
        // NICE MOCK TESTS: PRIVATE MEMBER FUNCTIONS
        //==============================================================================

        TEST(NiceMock_Private, NonConstPrivate)
        {
            testing::internal::CaptureStdout();
            testing::internal::CaptureStderr();
            {
                // 'auto' type deduction requires C++11 or later.
#ifdef BSLS_COMPILERFEATURES_FULL_CPP11
                auto mock = BONOBO_MOCK_PRIVATE_NICE_NON_CONST(
                    BloombergLP::bonobomock::test::SampleClassPrivate::private_member_function,
                    BloombergLP::bonobomock::test::SampleClassPrivate,
                    &function_with_same_signature_as_private_member_function);
#else
                bsl::shared_ptr<GMock<int(void*, int*)> > mock = BONOBO_MOCK_PRIVATE_NICE_NON_CONST(
                    BloombergLP::bonobomock::test::SampleClassPrivate::private_member_function,
                    BloombergLP::bonobomock::test::SampleClassPrivate,
                    &function_with_same_signature_as_private_member_function);
#endif
                SampleClassPrivate obj;
                int val = 42;
                // No expectations set on the mock.
                // All calls to the mocked function will be "uninteresting".
                // NiceMock should NOT report uninteresting calls.
                obj.call_private(&val);
            }
            bsl::string stderrOutput = testing::internal::GetCapturedStderr();
            bsl::string stdoutOutput = testing::internal::GetCapturedStdout();
            EXPECT_THAT(stderrOutput, Not(HasSubstr("Uninteresting")));
            EXPECT_THAT(stdoutOutput, Not(HasSubstr("Uninteresting")));
        }

        TEST(NiceMock_Private, ConstPrivate)
        {
            testing::internal::CaptureStdout();
            testing::internal::CaptureStderr();
            {
                // 'auto' type deduction requires C++11 or later.
#ifdef BSLS_COMPILERFEATURES_FULL_CPP11
                auto mock = BONOBO_MOCK_PRIVATE_NICE_CONST(
                    BloombergLP::bonobomock::test::SampleClassPrivate::private_member_function_const,
                    BloombergLP::bonobomock::test::SampleClassPrivate,
                    &function_with_same_signature_as_private_member_function_const);
#else
                bsl::shared_ptr<GMock<int(const void*, int*)> > mock = BONOBO_MOCK_PRIVATE_NICE_CONST(
                    BloombergLP::bonobomock::test::SampleClassPrivate::private_member_function_const,
                    BloombergLP::bonobomock::test::SampleClassPrivate,
                    &function_with_same_signature_as_private_member_function_const);
#endif
                const SampleClassPrivate obj;
                int val = 42;
                // No expectations set on the mock.
                // All calls to the mocked function will be "uninteresting".
                // NiceMock should NOT report uninteresting calls.
                obj.call_private_const(&val);
            }
            bsl::string stderrOutput = testing::internal::GetCapturedStderr();
            bsl::string stdoutOutput = testing::internal::GetCapturedStdout();
            EXPECT_THAT(stderrOutput, Not(HasSubstr("Uninteresting")));
            EXPECT_THAT(stdoutOutput, Not(HasSubstr("Uninteresting")));
        }

        //==============================================================================
        // PRIVATE STATIC FUNCTION TESTS
        //==============================================================================

        TEST(PrivateStatic, Mock_private_static)
        {
#ifdef BSLS_COMPILERFEATURES_FULL_CPP11
            auto mock = BONOBO_MOCK_PRIVATE_STATIC(
                BloombergLP::bonobomock::test::SampleClassPrivate::private_static_function,
                &function_with_same_signature_as_private_static_function);
#else
            bsl::shared_ptr<GMock<int(int*)> > mock = BONOBO_MOCK_PRIVATE_STATIC(
                BloombergLP::bonobomock::test::SampleClassPrivate::private_static_function,
                &function_with_same_signature_as_private_static_function);
#endif

            EXPECT_CALL(*mock, BONOBO_MOCK_FUNCTION(_))
                .Times(1)
                .WillOnce(Return(100));

            int input = 10;
            EXPECT_EQ(100, SampleClassPrivate::call_private_static(&input));

            mock->restore();

            EXPECT_EQ(10, SampleClassPrivate::call_private_static(&input));
        }

        //==============================================================================
        // NAGGY MOCK TESTS: PRIVATE STATIC FUNCTIONS
        //==============================================================================

        TEST(NaggyMock_PrivateStatic, PrivateStatic)
        {
            testing::internal::CaptureStdout();
            testing::internal::CaptureStderr();
            {
#ifdef BSLS_COMPILERFEATURES_FULL_CPP11
                auto mock = BONOBO_MOCK_PRIVATE_STATIC(
                    BloombergLP::bonobomock::test::SampleClassPrivate::private_static_function,
                    &function_with_same_signature_as_private_static_function);
#else
                bsl::shared_ptr<GMock<int(int*)> > mock = BONOBO_MOCK_PRIVATE_STATIC(
                    BloombergLP::bonobomock::test::SampleClassPrivate::private_static_function,
                    &function_with_same_signature_as_private_static_function);
#endif
                int val = 42;
                SampleClassPrivate::call_private_static(&val);
            }
            bsl::string stderrOutput = testing::internal::GetCapturedStderr();
            bsl::string stdoutOutput = testing::internal::GetCapturedStdout();
            EXPECT_TRUE(stderrOutput.find("Uninteresting") != bsl::string::npos || stdoutOutput.find("Uninteresting") != bsl::string::npos);
        }

        //==============================================================================
        // STRICT MOCK TESTS: PRIVATE STATIC FUNCTIONS
        //==============================================================================

        TEST(StrictMock_PrivateStatic, PrivateStatic)
        {
            // 'auto' type deduction requires C++11 or later.
#ifdef BSLS_COMPILERFEATURES_FULL_CPP11
            auto mock = BONOBO_MOCK_PRIVATE_STATIC_STRICT(
                BloombergLP::bonobomock::test::SampleClassPrivate::private_static_function,
                &function_with_same_signature_as_private_static_function);
#else
            bsl::shared_ptr<GMock<int(int*)> > mock = BONOBO_MOCK_PRIVATE_STATIC_STRICT(
                BloombergLP::bonobomock::test::SampleClassPrivate::private_static_function,
                &function_with_same_signature_as_private_static_function);
#endif
            EXPECT_NONFATAL_FAILURE(
                {
                    int val = 42;
                    SampleClassPrivate::call_private_static(&val);
                },
                "Uninteresting mock function call");
        }

        //==============================================================================
        // NICE MOCK TESTS: PRIVATE STATIC FUNCTIONS
        //==============================================================================

        TEST(NiceMock_PrivateStatic, PrivateStatic)
        {
            testing::internal::CaptureStdout();
            testing::internal::CaptureStderr();
            {
#ifdef BSLS_COMPILERFEATURES_FULL_CPP11
                auto mock = BONOBO_MOCK_PRIVATE_STATIC_NICE(
                    BloombergLP::bonobomock::test::SampleClassPrivate::private_static_function,
                    &function_with_same_signature_as_private_static_function);
#else
                bsl::shared_ptr<GMock<int(int*)> > mock = BONOBO_MOCK_PRIVATE_STATIC_NICE(
                    BloombergLP::bonobomock::test::SampleClassPrivate::private_static_function,
                    &function_with_same_signature_as_private_static_function);
#endif
                int val = 42;
                SampleClassPrivate::call_private_static(&val);
            }
            bsl::string stderrOutput = testing::internal::GetCapturedStderr();
            bsl::string stdoutOutput = testing::internal::GetCapturedStdout();
            EXPECT_THAT(stderrOutput, Not(HasSubstr("Uninteresting")));
            EXPECT_THAT(stdoutOutput, Not(HasSubstr("Uninteresting")));
        }

    } // close test namespace
} // close package namespace
} // close enterprise namespace
