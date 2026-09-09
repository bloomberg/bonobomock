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

#include <bonobomock_optimization_macros_api.h>

namespace BloombergLP {
namespace bonobomock {
    namespace test {

        using namespace ::testing;

        // Abstract base class
        class BaseClass {
        public:
            BaseClass(int x)
                : m_x(x)
            {
            }

            virtual int virtual_function(int& out, int in) = 0;
            virtual int const_virtual_function(bool) const = 0;

        protected:
            int m_x;
        };

        // The SampleClassVirtual class contains virtual member functions for us to mock.
        class SampleClassVirtual : public BaseClass {
        public:
            SampleClassVirtual(int x)
                : BaseClass(x)
            {
            }

            BONOBO_MOCK_DISABLE_FUNCTION_OPTIMIZATION_START(virtual_function)
            virtual int virtual_function(int& out, int in)
            {
                out = in;
                volatile int _r = m_x;
                return _r;
            }
            BONOBO_MOCK_DISABLE_FUNCTION_OPTIMIZATION_END(virtual_function)

            BONOBO_MOCK_DISABLE_FUNCTION_OPTIMIZATION_START(const_virtual_function)
            virtual int const_virtual_function(bool in) const
            {
                volatile int _r = in ? 10 : -10;
                return _r;
            }
            BONOBO_MOCK_DISABLE_FUNCTION_OPTIMIZATION_END(const_virtual_function)
        };

        namespace {

            // This function will be used to demonstrate that BonoboMock can
            // intercept virtual member function calls on objects the test does
            // not control: the object is created inside this function, yet the
            // mock still takes effect.
            int virtual_member_wrapper(int in)
            {
                int out = 0;
                SampleClassVirtual obj(0);
                BaseClass* base_ptr = &obj;
                int rc = base_ptr->virtual_function(out, in);
                if (rc) {
                    return -1;
                }

                if (out == 100) {
                    return 1;
                }

                return 0;
            }

            int const_virtual_member_wrapper()
            {
                const SampleClassVirtual obj(0);
                const BaseClass* base_ptr = &obj;
                return base_ptr->const_virtual_function(false);
            }

#if defined(__SUNPRO_CC)
            int define_virtual_function(int& out, int in)
            {
                SampleClassVirtual obj(0);
                return obj.virtual_function(out, in);
            }

            int define_const_virtual_function(bool in)
            {
                SampleClassVirtual obj(0);
                return obj.const_virtual_function(in);
            }
#endif

        }

        TEST(VirtualOnInstance, Mock_virtual)
        {
            // Mock the virtual function `virtual_function`.
            // To correctly mock virtual function, we need to use the specific derived class here.
#ifdef BSLS_COMPILERFEATURES_FULL_CPP11
            SampleClassVirtual instance(0);
            auto mock = BONOBO_MOCK_VIRTUAL_ON(instance, &SampleClassVirtual::virtual_function);
#else
            SampleClassVirtual instance(0);
            bsl::shared_ptr<GMock<int(void*, int&, int)> > mock = BONOBO_MOCK_VIRTUAL_ON(instance, &SampleClassVirtual::virtual_function);
#endif

            // Defined the 2nd mocked function for `virtual_function`.
            // BONOBO_MOCK_FUNCTION is taking any input; using _ as the first
            // argument matches calls on all instances.
            // Return -1.
            EXPECT_CALL(*mock, BONOBO_MOCK_FUNCTION(_, _, _))
                .Times(1)
                .WillOnce(Return(-1));

            SampleClassVirtual obj(0);
            // Defined the 1st mocked function for `member_function`.
            // BONOBO_MOCK_FUNCTION is taking any input; using &obj as the first
            // argument matches calls only on this specific instance.
            // Return -2.
            EXPECT_CALL(*mock, BONOBO_MOCK_FUNCTION(&obj, _, _))
                .Times(1)
                .WillOnce(Return(-2));

            int out = 0;
            EXPECT_EQ(-2, obj.virtual_function(out, 1));
            EXPECT_EQ(-1, virtual_member_wrapper(1));

            // Tell bonobomock to stop mocking, use the original sample_function.
            mock->restore();

            EXPECT_EQ(0, obj.virtual_function(out, 1));
            EXPECT_EQ(0, virtual_member_wrapper(1));
        }

        TEST(VirtualOnInstance, Mock_virtual_setArgPointee)
        {
            // Mock the virtual function `virtual_function`.
            // To correctly mock virtual function, we need to use the specific derived class here.
#ifdef BSLS_COMPILERFEATURES_FULL_CPP11
            SampleClassVirtual instance(0);
            auto mock = BONOBO_MOCK_VIRTUAL_ON(instance, &SampleClassVirtual::virtual_function);
#else
            SampleClassVirtual instance(0);
            bsl::shared_ptr<GMock<int(void*, int&, int)> > mock = BONOBO_MOCK_VIRTUAL_ON(instance, &SampleClassVirtual::virtual_function);
#endif

            int out = 100;
            // Defined the 2nd mocked function for `virtual_function`.
            // BONOBO_MOCK_FUNCTION is taking any input; using _ as the first
            // argument matches calls on all instances.
            // SetArgReferee<1> represents the first `int& out` in virtual_function.
            // Use SetArgPointee if it is a pointer.
            // Return -1.
            EXPECT_CALL(*mock, BONOBO_MOCK_FUNCTION(_, _, _))
                .Times(1)
                .WillOnce(DoAll(SetArgReferee<1>(out), Return(0)));

            EXPECT_EQ(1, virtual_member_wrapper(1));

            // Tell bonobomock to stop mocking, use the original sample_function.
            mock->restore();

            EXPECT_EQ(0, virtual_member_wrapper(1));
        }

        TEST(VirtualOnInstance, Mock_virtual_const)
        {
            // Mock the virtual function `virtual_function`.
            // To correctly mock virtual function, we need to use the specific derived class here.
#ifdef BSLS_COMPILERFEATURES_FULL_CPP11
            SampleClassVirtual instance(0);
            auto mock = BONOBO_MOCK_VIRTUAL_ON(instance, &SampleClassVirtual::const_virtual_function);
#else
            SampleClassVirtual instance(0);
            bsl::shared_ptr<GMock<int(const void*, bool)> > mock = BONOBO_MOCK_VIRTUAL_ON(instance, &SampleClassVirtual::const_virtual_function);
#endif

            // Defined the 2nd mocked function for `virtual_function`.
            // BONOBO_MOCK_FUNCTION is taking any input; using _ as the first
            // argument matches calls on all instances.
            // Return -1.
            EXPECT_CALL(*mock, BONOBO_MOCK_FUNCTION(_, _))
                .Times(1)
                .WillOnce(Return(100));

            const SampleClassVirtual obj(0);
            const BaseClass* ptr = &obj;
            // Defined the 1st mocked function for `member_function`.
            // BONOBO_MOCK_FUNCTION is taking any input; using &obj as the first
            // argument matches calls only on this specific instance.
            // Return -2.
            EXPECT_CALL(*mock, BONOBO_MOCK_FUNCTION(&obj, _))
                .Times(1)
                .WillOnce(Return(200));

            EXPECT_EQ(200, ptr->const_virtual_function(true));
            EXPECT_EQ(100, const_virtual_member_wrapper());

            // Tell bonobomock to stop mocking, use the original sample_function.
            mock->restore();

            EXPECT_EQ(10, ptr->const_virtual_function(true));
            EXPECT_EQ(-10, const_virtual_member_wrapper());
        }

        //==============================================================================
        // NAGGY MOCK TESTS: VIRTUAL ON INSTANCE
        // These tests verify that the default (naggy) mock DOES produce output about
        // uninteresting calls when no expectations are set.
        //==============================================================================

        TEST(NaggyMock_VirtualOnInstance, NonConstVirtualOnInstance)
        {
            testing::internal::CaptureStdout();
            testing::internal::CaptureStderr();
            {
#ifdef BSLS_COMPILERFEATURES_FULL_CPP11
                SampleClassVirtual instance(0);
                auto mock = BONOBO_MOCK_VIRTUAL_ON(instance, &SampleClassVirtual::virtual_function);
#else
                SampleClassVirtual instance(0);
                bsl::shared_ptr<GMock<int(void*, int&, int)> > mock = BONOBO_MOCK_VIRTUAL_ON(instance, &SampleClassVirtual::virtual_function);
#endif
                SampleClassVirtual obj(0);
                int out = 0;
                // No expectations set on the mock.
                // All calls to the mocked function will be "uninteresting".
                // Naggy mock (default) SHOULD report uninteresting calls.
                obj.virtual_function(out, 10);
            }
            bsl::string stderrOutput = testing::internal::GetCapturedStderr();
            bsl::string stdoutOutput = testing::internal::GetCapturedStdout();
            EXPECT_TRUE(stderrOutput.find("Uninteresting") != bsl::string::npos || stdoutOutput.find("Uninteresting") != bsl::string::npos);
        }

        TEST(NaggyMock_VirtualOnInstance, ConstVirtualOnInstance)
        {
            testing::internal::CaptureStdout();
            testing::internal::CaptureStderr();
            {
#ifdef BSLS_COMPILERFEATURES_FULL_CPP11
                SampleClassVirtual instance(0);
                auto mock = BONOBO_MOCK_VIRTUAL_ON(instance, &SampleClassVirtual::const_virtual_function);
#else
                SampleClassVirtual instance(0);
                bsl::shared_ptr<GMock<int(const void*, bool)> > mock = BONOBO_MOCK_VIRTUAL_ON(instance, &SampleClassVirtual::const_virtual_function);
#endif
                SampleClassVirtual obj(0);
                // No expectations set on the mock.
                // All calls to the mocked function will be "uninteresting".
                // Naggy mock (default) SHOULD report uninteresting calls.
                obj.const_virtual_function(true);
            }
            bsl::string stderrOutput = testing::internal::GetCapturedStderr();
            bsl::string stdoutOutput = testing::internal::GetCapturedStdout();
            EXPECT_TRUE(stderrOutput.find("Uninteresting") != bsl::string::npos || stdoutOutput.find("Uninteresting") != bsl::string::npos);
        }

        //==============================================================================
        // STRICT MOCK TESTS: VIRTUAL ON INSTANCE
        //==============================================================================

        // Helper function to create strict mock for virtual function on instance and call it.
        // This avoids issues with complex code blocks inside EXPECT_NONFATAL_FAILURE.
        void create_strict_mock_of_virtual_on_instance_and_call_it()
        {
#ifdef BSLS_COMPILERFEATURES_FULL_CPP11
            SampleClassVirtual instance(0);
            auto mock = BONOBO_MOCK_VIRTUAL_STRICT_ON(instance, &SampleClassVirtual::virtual_function);
#else
            SampleClassVirtual instance(0);
            bsl::shared_ptr<GMock<int(void*, int&, int)> > mock = BONOBO_MOCK_VIRTUAL_STRICT_ON(instance, &SampleClassVirtual::virtual_function);
#endif
            // No expectations set on the mock.
            // All calls to the mocked function will be "uninteresting".
            // They should trigger the strict mock failure.
            SampleClassVirtual obj(0);
            int out = 0;
            obj.virtual_function(out, 10);
        }

        TEST(StrictMock_VirtualOnInstance, NonConstVirtualOnInstance)
        {
            EXPECT_NONFATAL_FAILURE(
                create_strict_mock_of_virtual_on_instance_and_call_it(),
                "Uninteresting mock function call");
        }

        // Helper function to create strict mock for const virtual function on instance and call it.
        // This avoids issues with complex code blocks inside EXPECT_NONFATAL_FAILURE.
        void create_strict_mock_of_const_virtual_on_instance_and_call_it()
        {
#ifdef BSLS_COMPILERFEATURES_FULL_CPP11
            SampleClassVirtual instance(0);
            auto mock = BONOBO_MOCK_VIRTUAL_STRICT_ON(instance, &SampleClassVirtual::const_virtual_function);
#else
            SampleClassVirtual instance(0);
            bsl::shared_ptr<GMock<int(const void*, bool)> > mock = BONOBO_MOCK_VIRTUAL_STRICT_ON(instance, &SampleClassVirtual::const_virtual_function);
#endif
            SampleClassVirtual obj(0);
            // No expectations set on the mock.
            // All calls to the mocked function will be "uninteresting".
            // They should trigger the strict mock failure.
            obj.const_virtual_function(true);
        }

        TEST(StrictMock_VirtualOnInstance, ConstVirtualOnInstance)
        {
            EXPECT_NONFATAL_FAILURE(
                create_strict_mock_of_const_virtual_on_instance_and_call_it(),
                "Uninteresting mock function call");
        }

        //==============================================================================
        // NICE MOCK TESTS: VIRTUAL MEMBER FUNCTIONS ON INSTANCE
        //==============================================================================

        TEST(NiceMock_VirtualOnInstance, NonConstVirtualOnInstance)
        {
            testing::internal::CaptureStdout();
            testing::internal::CaptureStderr();
            {
#ifdef BSLS_COMPILERFEATURES_FULL_CPP11
                SampleClassVirtual instance(0);
                auto mock = BONOBO_MOCK_VIRTUAL_NICE_ON(instance, &SampleClassVirtual::virtual_function);
#else
                SampleClassVirtual instance(0);
                bsl::shared_ptr<GMock<int(void*, int&, int)> > mock = BONOBO_MOCK_VIRTUAL_NICE_ON(instance, &SampleClassVirtual::virtual_function);
#endif
                SampleClassVirtual obj(0);
                int out = 0;
                // No expectations set on the mock.
                // All calls to the mocked function will be "uninteresting".
                // NiceMock should NOT report uninteresting calls.
                obj.virtual_function(out, 10);
            }
            bsl::string stderrOutput = testing::internal::GetCapturedStderr();
            bsl::string stdoutOutput = testing::internal::GetCapturedStdout();
            EXPECT_THAT(stderrOutput, Not(HasSubstr("Uninteresting")));
            EXPECT_THAT(stdoutOutput, Not(HasSubstr("Uninteresting")));
        }

        TEST(NiceMock_VirtualOnInstance, ConstVirtualOnInstance)
        {
            testing::internal::CaptureStdout();
            testing::internal::CaptureStderr();
            {
#ifdef BSLS_COMPILERFEATURES_FULL_CPP11
                SampleClassVirtual instance(0);
                auto mock = BONOBO_MOCK_VIRTUAL_NICE_ON(instance, &SampleClassVirtual::const_virtual_function);
#else
                SampleClassVirtual instance(0);
                bsl::shared_ptr<GMock<int(const void*, bool)> > mock = BONOBO_MOCK_VIRTUAL_NICE_ON(instance, &SampleClassVirtual::const_virtual_function);
#endif
                SampleClassVirtual obj(0);
                // No expectations set on the mock.
                // All calls to the mocked function will be "uninteresting".
                // NiceMock should NOT report uninteresting calls.
                obj.const_virtual_function(true);
            }
            bsl::string stderrOutput = testing::internal::GetCapturedStderr();
            bsl::string stdoutOutput = testing::internal::GetCapturedStdout();
            EXPECT_THAT(stderrOutput, Not(HasSubstr("Uninteresting")));
            EXPECT_THAT(stdoutOutput, Not(HasSubstr("Uninteresting")));
        }

    } // close test namespace
} // close package namespace
} // close enterprise namespace
