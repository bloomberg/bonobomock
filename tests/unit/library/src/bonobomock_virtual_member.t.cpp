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
#include "gtest/gtest.h"
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
            virtual int virtual_function(int& out, int in) = 0;
            virtual int const_virtual_function(bool) const = 0;
        };

        // The SampleClassVirtual class contains virtual member functions for us to mock.
        class SampleClassVirtual : public BaseClass {
        public:
            BONOBO_MOCK_DISABLE_FUNCTION_OPTIMIZATION_START(virtual_function)
            virtual int virtual_function(int& out, int in)
            {
                out = in;
                volatile int _r = 0;
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

        // This function will be used to demonstrate that BonoboMock can intercept
        // virtual member function calls on objects the test does not control:
        // the object is created inside this function, yet the mock still takes
        // effect.
        BONOBO_MOCK_DISABLE_FUNCTION_OPTIMIZATION_START(virtual_member_wrapper)
        int virtual_member_wrapper(int in)
        {
            int out = 0;
            SampleClassVirtual obj;
            BaseClass* base_ptr = &obj;
            int rc = base_ptr->virtual_function(out, in);
            if (rc) {
                volatile int _r = -1;
                return _r;
            }

            if (out == 100) {
                volatile int _r = 1;
                return _r;
            }

            volatile int _r = 0;
            return _r;
        }
        BONOBO_MOCK_DISABLE_FUNCTION_OPTIMIZATION_END(virtual_member_wrapper)

        BONOBO_MOCK_DISABLE_FUNCTION_OPTIMIZATION_START(const_virtual_member_wrapper)
        int const_virtual_member_wrapper()
        {
            const SampleClassVirtual obj;
            const BaseClass* base_ptr = &obj;
            volatile int _r = base_ptr->const_virtual_function(false);
            return _r;
        }
        BONOBO_MOCK_DISABLE_FUNCTION_OPTIMIZATION_END(const_virtual_member_wrapper)

#if defined(__SUNPRO_CC)
        int define_virtual_function(int& out, int in)
        {
            SampleClassVirtual obj;
            return obj.virtual_function(out, in);
        }

        int define_const_virtual_function(bool in)
        {
            SampleClassVirtual obj;
            return obj.const_virtual_function(in);
        }
#endif

        TEST(Virtual, Mock_virtual)
        {
            // Mock the virtual function `virtual_function`.
            // To correctly mock virtual function, we need to use the specific derived class here.
#ifdef BSLS_COMPILERFEATURES_FULL_CPP11
            auto mock = BONOBO_MOCK_VIRTUAL(&SampleClassVirtual::virtual_function);
#else
            bsl::shared_ptr<GMock<int(void*, int&, int)> > mock = BONOBO_MOCK_VIRTUAL(&SampleClassVirtual::virtual_function);
#endif

            // Defined the 2nd mocked function for `virtual_function`.
            // BONOBO_MOCK_FUNCTION is taking any input; using _ as the first
            // argument matches calls on all instances.
            // Return -1.
            EXPECT_CALL(*mock, BONOBO_MOCK_FUNCTION(_, _, _))
                .Times(1)
                .WillOnce(Return(-1));

            SampleClassVirtual obj;
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

        TEST(Virtual, Mock_virtual_setArgPointee)
        {
            // Mock the virtual function `virtual_function`.
            // To correctly mock virtual function, we need to use the specific derived class here.
#ifdef BSLS_COMPILERFEATURES_FULL_CPP11
            auto mock = BONOBO_MOCK_VIRTUAL(&SampleClassVirtual::virtual_function);
#else
            bsl::shared_ptr<GMock<int(void*, int&, int)> > mock = BONOBO_MOCK_VIRTUAL(&SampleClassVirtual::virtual_function);
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

        TEST(Virtual, Mock_virtual_const)
        {
            // Mock the virtual function `virtual_function`.
            // To correctly mock virtual function, we need to use the specific derived class here.
#ifdef BSLS_COMPILERFEATURES_FULL_CPP11
            auto mock = BONOBO_MOCK_VIRTUAL(&SampleClassVirtual::const_virtual_function);
#else
            bsl::shared_ptr<GMock<int(const void*, bool)> > mock = BONOBO_MOCK_VIRTUAL(&SampleClassVirtual::const_virtual_function);
#endif

            // Defined the 2nd mocked function for `virtual_function`.
            // BONOBO_MOCK_FUNCTION is taking any input; using _ as the first
            // argument matches calls on all instances.
            // Return -1.
            EXPECT_CALL(*mock, BONOBO_MOCK_FUNCTION(_, _))
                .Times(1)
                .WillOnce(Return(100));

            const SampleClassVirtual obj;
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

        TEST(Virtual, Mock_virtual_without_taskname)
        {
#ifdef BSLS_COMPILERFEATURES_FULL_CPP11
            auto mock = BONOBO_MOCK_VIRTUAL(&SampleClassVirtual::virtual_function);
#else
            bsl::shared_ptr<GMock<int(void*, int&, int)> > mock = BONOBO_MOCK_VIRTUAL(&SampleClassVirtual::virtual_function);
#endif
            EXPECT_CALL(*mock, BONOBO_MOCK_FUNCTION(_, _, _))
                .Times(1)
                .WillOnce(Return(-1));

            SampleClassVirtual obj;
            EXPECT_CALL(*mock, BONOBO_MOCK_FUNCTION(&obj, _, _))
                .Times(1)
                .WillOnce(Return(-2));

            int out = 0;
            EXPECT_EQ(-2, obj.virtual_function(out, 1));
            EXPECT_EQ(-1, virtual_member_wrapper(1));

            mock->restore();

            EXPECT_EQ(0, obj.virtual_function(out, 1));
            EXPECT_EQ(0, virtual_member_wrapper(1));
        }

        TEST(Virtual, Mock_virtual_const_without_taskname)
        {
#ifdef BSLS_COMPILERFEATURES_FULL_CPP11
            auto mock = BONOBO_MOCK_VIRTUAL(&SampleClassVirtual::const_virtual_function);
#else
            bsl::shared_ptr<GMock<int(const void*, bool)> > mock = BONOBO_MOCK_VIRTUAL(&SampleClassVirtual::const_virtual_function);
#endif

            // Test that mocking works correctly on both platforms
            EXPECT_CALL(*mock, BONOBO_MOCK_FUNCTION(_, _))
                .Times(1)
                .WillOnce(Return(100));

            const SampleClassVirtual obj;
            const BaseClass* ptr = &obj;
            EXPECT_CALL(*mock, BONOBO_MOCK_FUNCTION(&obj, _))
                .Times(1)
                .WillOnce(Return(200));

            EXPECT_EQ(200, ptr->const_virtual_function(true));
            EXPECT_EQ(100, const_virtual_member_wrapper());

            mock->restore();

            EXPECT_EQ(10, ptr->const_virtual_function(true));
            EXPECT_EQ(-10, const_virtual_member_wrapper());
        }

        TEST(Virtual, Mixed_original_and_without_taskname_macros)
        {
            // Test that the new macros work alongside the original macros
#ifdef BSLS_COMPILERFEATURES_FULL_CPP11
            auto non_const_mock = BONOBO_MOCK_VIRTUAL(&SampleClassVirtual::virtual_function);
            auto const_mock = BONOBO_MOCK_VIRTUAL(&SampleClassVirtual::const_virtual_function);
#else
            bsl::shared_ptr<GMock<int(void*, int&, int)> > non_const_mock = BONOBO_MOCK_VIRTUAL(&SampleClassVirtual::virtual_function);
            bsl::shared_ptr<GMock<int(const void*, bool)> > const_mock = BONOBO_MOCK_VIRTUAL(&SampleClassVirtual::const_virtual_function);
#endif

            EXPECT_CALL(*non_const_mock, BONOBO_MOCK_FUNCTION(_, _, _))
                .Times(1)
                .WillOnce(DoAll(SetArgReferee<1>(100), Return(0)));

            EXPECT_CALL(*const_mock, BONOBO_MOCK_FUNCTION(_, _))
                .Times(1)
                .WillOnce(Return(24));

            EXPECT_EQ(1, virtual_member_wrapper(1));
            EXPECT_EQ(24, const_virtual_member_wrapper());

            non_const_mock->restore();
            const_mock->restore();
        }

        //==============================================================================
        // NAGGY MOCK TESTS: VIRTUAL MEMBER FUNCTIONS
        // These tests verify that the default (naggy) mock DOES produce output about
        // uninteresting calls when no expectations are set.
        //==============================================================================

        TEST(NaggyMock_Virtual, NonConstVirtualFunction)
        {
            testing::internal::CaptureStdout();
            testing::internal::CaptureStderr();
            {
#ifdef BSLS_COMPILERFEATURES_FULL_CPP11
                auto mock = BONOBO_MOCK_VIRTUAL(&SampleClassVirtual::virtual_function);
#else
                bsl::shared_ptr<GMock<int(void*, int&, int)> > mock = BONOBO_MOCK_VIRTUAL(&SampleClassVirtual::virtual_function);
#endif
                SampleClassVirtual obj;
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

        TEST(NaggyMock_Virtual, ConstVirtualFunction)
        {
            testing::internal::CaptureStdout();
            testing::internal::CaptureStderr();
            {
#ifdef BSLS_COMPILERFEATURES_FULL_CPP11
                auto mock = BONOBO_MOCK_VIRTUAL(&SampleClassVirtual::const_virtual_function);
#else
                bsl::shared_ptr<GMock<int(const void*, bool)> > mock = BONOBO_MOCK_VIRTUAL(&SampleClassVirtual::const_virtual_function);
#endif
                SampleClassVirtual obj;
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
        // STRICT MOCK TESTS: VIRTUAL MEMBER FUNCTIONS
        //==============================================================================

        // Helper function to create strict mock for virtual function and call it.
        // This avoids issues with complex code blocks inside EXPECT_NONFATAL_FAILURE.
        void create_strict_mock_of_nonconst_virtual_function_and_call_it()
        {
#ifdef BSLS_COMPILERFEATURES_FULL_CPP11
            auto mock = BONOBO_MOCK_VIRTUAL_STRICT(&SampleClassVirtual::virtual_function);
#else
            bsl::shared_ptr<GMock<int(void*, int&, int)> > mock = BONOBO_MOCK_VIRTUAL_STRICT(&SampleClassVirtual::virtual_function);
#endif
            SampleClassVirtual obj;
            int out = 0;
            // No expectations set on the mock.
            // All calls to the mocked function will be "uninteresting".
            // They should trigger the strict mock failure.
            obj.virtual_function(out, 10);
        }

        TEST(StrictMock_Virtual, NonConstVirtualFunction)
        {
            EXPECT_NONFATAL_FAILURE(
                create_strict_mock_of_nonconst_virtual_function_and_call_it(),
                "Uninteresting mock function call");
        }

        // Helper function to create strict mock for const virtual function and call it.
        // This avoids issues with complex code blocks inside EXPECT_NONFATAL_FAILURE.
        void create_strict_mock_of_const_virtual_function_and_call_it()
        {
#ifdef BSLS_COMPILERFEATURES_FULL_CPP11
            auto mock = BONOBO_MOCK_VIRTUAL_STRICT(&SampleClassVirtual::const_virtual_function);
#else
            bsl::shared_ptr<GMock<int(const void*, bool)> > mock = BONOBO_MOCK_VIRTUAL_STRICT(&SampleClassVirtual::const_virtual_function);
#endif
            const SampleClassVirtual obj;
            // No expectations set on the mock.
            // All calls to the mocked function will be "uninteresting".
            // They should trigger the strict mock failure.
            obj.const_virtual_function(true);
        }

        TEST(StrictMock_Virtual, ConstVirtualFunction)
        {
            EXPECT_NONFATAL_FAILURE(
                create_strict_mock_of_const_virtual_function_and_call_it(),
                "Uninteresting mock function call");
        }

        //==============================================================================
        // NICE MOCK TESTS: VIRTUAL MEMBER FUNCTIONS
        //==============================================================================

        TEST(NiceMock_Virtual, NonConstVirtualFunction)
        {
            testing::internal::CaptureStdout();
            testing::internal::CaptureStderr();
            {
#ifdef BSLS_COMPILERFEATURES_FULL_CPP11
                auto mock = BONOBO_MOCK_VIRTUAL_NICE(&SampleClassVirtual::virtual_function);
#else
                bsl::shared_ptr<GMock<int(void*, int&, int)> > mock = BONOBO_MOCK_VIRTUAL_NICE(&SampleClassVirtual::virtual_function);
#endif
                SampleClassVirtual obj;
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

        TEST(NiceMock_Virtual, ConstVirtualFunction)
        {
            testing::internal::CaptureStdout();
            testing::internal::CaptureStderr();
            {
#ifdef BSLS_COMPILERFEATURES_FULL_CPP11
                auto mock = BONOBO_MOCK_VIRTUAL_NICE(&SampleClassVirtual::const_virtual_function);
#else
                bsl::shared_ptr<GMock<int(const void*, bool)> > mock = BONOBO_MOCK_VIRTUAL_NICE(&SampleClassVirtual::const_virtual_function);
#endif
                const SampleClassVirtual obj;
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

        //==============================================================================
        // BONOBO_MOCK AUTO-DETECTION TESTS: VIRTUAL MEMBER FUNCTIONS
        // These tests verify that BONOBO_MOCK (not BONOBO_MOCK_VIRTUAL) auto-detects virtual
        // functions on GCC/Clang and resolves them via vtable lookup.
        //==============================================================================

#if BONOBO_MOCK_IS_ITANIUM_ABI && defined(BSLS_COMPILERFEATURES_FULL_CPP17)
        TEST(Virtual, BONOBO_MOCK_auto_detects_virtual)
        {
            auto mock = BONOBO_MOCK(&SampleClassVirtual::virtual_function);

            EXPECT_CALL(*mock, BONOBO_MOCK_FUNCTION(_, _, _))
                .Times(1)
                .WillOnce(Return(-1));

            SampleClassVirtual obj;
            EXPECT_CALL(*mock, BONOBO_MOCK_FUNCTION(&obj, _, _))
                .Times(1)
                .WillOnce(Return(-2));

            int out = 0;
            EXPECT_EQ(-2, obj.virtual_function(out, 1));
            EXPECT_EQ(-1, virtual_member_wrapper(1));

            mock->restore();

            EXPECT_EQ(0, obj.virtual_function(out, 1));
            EXPECT_EQ(0, virtual_member_wrapper(1));
        }

        TEST(Virtual, BONOBO_MOCK_auto_detects_const_virtual)
        {
            auto mock = BONOBO_MOCK(&SampleClassVirtual::const_virtual_function);

            EXPECT_CALL(*mock, BONOBO_MOCK_FUNCTION(_, _))
                .Times(1)
                .WillOnce(Return(100));

            const SampleClassVirtual obj;
            const BaseClass* ptr = &obj;
            EXPECT_CALL(*mock, BONOBO_MOCK_FUNCTION(&obj, _))
                .Times(1)
                .WillOnce(Return(200));

            EXPECT_EQ(200, ptr->const_virtual_function(true));
            EXPECT_EQ(100, const_virtual_member_wrapper());

            mock->restore();

            EXPECT_EQ(10, ptr->const_virtual_function(true));
            EXPECT_EQ(-10, const_virtual_member_wrapper());
        }
#endif

        //==============================================================================
        // MULTI-FUNCTION TEST: Mix of virtual and non-virtual member functions
        //==============================================================================

        class MultiFunc {
        public:
            BONOBO_MOCK_DISABLE_FUNCTION_OPTIMIZATION_START(virt_a)
            virtual int virt_a(int x)
            {
                volatile int _r = x + 1;
                return _r;
            }
            BONOBO_MOCK_DISABLE_FUNCTION_OPTIMIZATION_END(virt_a)

            BONOBO_MOCK_DISABLE_FUNCTION_OPTIMIZATION_START(virt_b)
            virtual int virt_b(int x, int y)
            {
                volatile int _r = x + y;
                return _r;
            }
            BONOBO_MOCK_DISABLE_FUNCTION_OPTIMIZATION_END(virt_b)

            BONOBO_MOCK_DISABLE_FUNCTION_OPTIMIZATION_START(virt_c)
            virtual int virt_c() const
            {
                volatile int _r = 42;
                return _r;
            }
            BONOBO_MOCK_DISABLE_FUNCTION_OPTIMIZATION_END(virt_c)

            BONOBO_MOCK_DISABLE_FUNCTION_OPTIMIZATION_START(virt_d)
            virtual int virt_d(int x) const
            {
                volatile int _r = x * 2;
                return _r;
            }
            BONOBO_MOCK_DISABLE_FUNCTION_OPTIMIZATION_END(virt_d)

            BONOBO_MOCK_DISABLE_FUNCTION_OPTIMIZATION_START(nonvirt_a)
            int nonvirt_a(int x)
            {
                volatile int _r = x + 100;
                return _r;
            }
            BONOBO_MOCK_DISABLE_FUNCTION_OPTIMIZATION_END(nonvirt_a)

            BONOBO_MOCK_DISABLE_FUNCTION_OPTIMIZATION_START(nonvirt_b)
            int nonvirt_b(int x, int y)
            {
                volatile int _r = x * y;
                return _r;
            }
            BONOBO_MOCK_DISABLE_FUNCTION_OPTIMIZATION_END(nonvirt_b)

            BONOBO_MOCK_DISABLE_FUNCTION_OPTIMIZATION_START(nonvirt_c)
            int nonvirt_c() const
            {
                volatile int _r = 99;
                return _r;
            }
            BONOBO_MOCK_DISABLE_FUNCTION_OPTIMIZATION_END(nonvirt_c)

            BONOBO_MOCK_DISABLE_FUNCTION_OPTIMIZATION_START(nonvirt_d)
            int nonvirt_d(int x) const
            {
                volatile int _r = x - 1;
                return _r;
            }
            BONOBO_MOCK_DISABLE_FUNCTION_OPTIMIZATION_END(nonvirt_d)
        };

        TEST(Virtual, MockAllFunctionsOnMultiFuncClass)
        {
            // Mock 4 virtual functions
#ifdef BSLS_COMPILERFEATURES_FULL_CPP11
            auto mock_va = BONOBO_MOCK_VIRTUAL(&MultiFunc::virt_a);
            auto mock_vb = BONOBO_MOCK_VIRTUAL(&MultiFunc::virt_b);
            auto mock_vc = BONOBO_MOCK_VIRTUAL(&MultiFunc::virt_c);
            auto mock_vd = BONOBO_MOCK_VIRTUAL(&MultiFunc::virt_d);
#else
            bsl::shared_ptr<GMock<int(void*, int)> > mock_va = BONOBO_MOCK_VIRTUAL(&MultiFunc::virt_a);
            bsl::shared_ptr<GMock<int(void*, int, int)> > mock_vb = BONOBO_MOCK_VIRTUAL(&MultiFunc::virt_b);
            bsl::shared_ptr<GMock<int(const void*)> > mock_vc = BONOBO_MOCK_VIRTUAL(&MultiFunc::virt_c);
            bsl::shared_ptr<GMock<int(const void*, int)> > mock_vd = BONOBO_MOCK_VIRTUAL(&MultiFunc::virt_d);
#endif

            // Mock 4 non-virtual functions (BONOBO_MOCK works on all platforms)
#ifdef BSLS_COMPILERFEATURES_FULL_CPP11
            auto mock_na = BONOBO_MOCK(&MultiFunc::nonvirt_a);
            auto mock_nb = BONOBO_MOCK(&MultiFunc::nonvirt_b);
            auto mock_nc = BONOBO_MOCK(&MultiFunc::nonvirt_c);
            auto mock_nd = BONOBO_MOCK(&MultiFunc::nonvirt_d);
#else
            bsl::shared_ptr<GMock<int(void*, int)> > mock_na = BONOBO_MOCK(&MultiFunc::nonvirt_a);
            bsl::shared_ptr<GMock<int(void*, int, int)> > mock_nb = BONOBO_MOCK(&MultiFunc::nonvirt_b);
            bsl::shared_ptr<GMock<int(const void*)> > mock_nc = BONOBO_MOCK(&MultiFunc::nonvirt_c);
            bsl::shared_ptr<GMock<int(const void*, int)> > mock_nd = BONOBO_MOCK(&MultiFunc::nonvirt_d);
#endif

            // Set expectations on all 8 mocks
            EXPECT_CALL(*mock_va, BONOBO_MOCK_FUNCTION(_, _)).WillRepeatedly(Return(-1));
            EXPECT_CALL(*mock_vb, BONOBO_MOCK_FUNCTION(_, _, _)).WillRepeatedly(Return(-2));
            EXPECT_CALL(*mock_vc, BONOBO_MOCK_FUNCTION(_)).WillRepeatedly(Return(-3));
            EXPECT_CALL(*mock_vd, BONOBO_MOCK_FUNCTION(_, _)).WillRepeatedly(Return(-4));
            EXPECT_CALL(*mock_na, BONOBO_MOCK_FUNCTION(_, _)).WillRepeatedly(Return(-5));
            EXPECT_CALL(*mock_nb, BONOBO_MOCK_FUNCTION(_, _, _)).WillRepeatedly(Return(-6));
            EXPECT_CALL(*mock_nc, BONOBO_MOCK_FUNCTION(_)).WillRepeatedly(Return(-7));
            EXPECT_CALL(*mock_nd, BONOBO_MOCK_FUNCTION(_, _)).WillRepeatedly(Return(-8));

            MultiFunc obj;
            const MultiFunc& cobj = obj;

            // All calls should return the mocked values, not the originals
            EXPECT_EQ(-1, obj.virt_a(10));
            EXPECT_EQ(-2, obj.virt_b(10, 20));
            EXPECT_EQ(-3, cobj.virt_c());
            EXPECT_EQ(-4, cobj.virt_d(10));
            EXPECT_EQ(-5, obj.nonvirt_a(10));
            EXPECT_EQ(-6, obj.nonvirt_b(10, 20));
            EXPECT_EQ(-7, cobj.nonvirt_c());
            EXPECT_EQ(-8, cobj.nonvirt_d(10));

            // Restore all mocks
            mock_va->restore();
            mock_vb->restore();
            mock_vc->restore();
            mock_vd->restore();
            mock_na->restore();
            mock_nb->restore();
            mock_nc->restore();
            mock_nd->restore();

            // After restore, original implementations should be called
            EXPECT_EQ(11, obj.virt_a(10));
            EXPECT_EQ(30, obj.virt_b(10, 20));
            EXPECT_EQ(42, cobj.virt_c());
            EXPECT_EQ(20, cobj.virt_d(10));
            EXPECT_EQ(110, obj.nonvirt_a(10));
            EXPECT_EQ(200, obj.nonvirt_b(10, 20));
            EXPECT_EQ(99, cobj.nonvirt_c());
            EXPECT_EQ(9, cobj.nonvirt_d(10));
        }

    } // close test namespace
} // close package namespace
} // close enterprise namespace
