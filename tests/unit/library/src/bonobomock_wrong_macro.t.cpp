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
#include <bonobomock_api.h>

// third party includes
#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <bsl_memory.h>
#include <bsls_compilerfeatures.h>

#include <bonobomock_optimization_macros_api.h>

// These tests verify BONOBO_MOCK behavior with virtual functions: auto-detection
// on GCC/Clang, and correct error for non-default-constructible classes.

namespace BloombergLP {
namespace bonobomock {
    namespace test {

        using namespace ::testing;

        class WrongMacroVirtualClass {
        public:
            BONOBO_MOCK_DISABLE_FUNCTION_OPTIMIZATION_START(virtual_func)
            virtual int virtual_func(int x)
            {
                volatile int _r = x * 2;
                return _r;
            }
            BONOBO_MOCK_DISABLE_FUNCTION_OPTIMIZATION_END(virtual_func)
        };

        class WrongMacroNonVirtualClass {
        public:
            BONOBO_MOCK_DISABLE_FUNCTION_OPTIMIZATION_START(non_virtual_func)
            int non_virtual_func(int x)
            {
                volatile int _r = x + 1;
                return _r;
            }
            BONOBO_MOCK_DISABLE_FUNCTION_OPTIMIZATION_END(non_virtual_func)
        };

        class WrongMacroNonDefaultConstructibleVirtualClass {
        public:
            WrongMacroNonDefaultConstructibleVirtualClass(int x)
                : d_x(x)
            {
            }

            BONOBO_MOCK_DISABLE_FUNCTION_OPTIMIZATION_START(virtual_func)
            virtual int virtual_func(int x)
            {
                volatile int _r = x * d_x;
                return _r;
            }
            BONOBO_MOCK_DISABLE_FUNCTION_OPTIMIZATION_END(virtual_func)

        private:
            int d_x;
        };

#if defined(__SUNPRO_CC)
        int define_wrong_macro_virtual_func(int x)
        {
            WrongMacroVirtualClass obj;
            return obj.virtual_func(x);
        }
#endif

// On GCC/Clang, BONOBO_MOCK now auto-detects virtual functions and resolves them
// via vtable lookup, so it works on virtual functions of default-constructible
// classes without needing BONOBO_MOCK_VIRTUAL.
#if BONOBO_MOCK_IS_ITANIUM_ABI && defined(BSLS_COMPILERFEATURES_FULL_CPP17)
        TEST(WrongMacroDeathTest, BONOBO_MOCK_on_virtual_function_auto_detects)
        {
            auto mock = BONOBO_MOCK(&WrongMacroVirtualClass::virtual_func);

            EXPECT_CALL(*mock, BONOBO_MOCK_FUNCTION(_, _))
                .Times(1)
                .WillOnce(Return(99));

            WrongMacroVirtualClass obj;
            EXPECT_EQ(99, obj.virtual_func(1));

            mock->restore();

            EXPECT_EQ(2, obj.virtual_func(1));
        }

        TEST(WrongMacroDeathTest,
            BONOBO_MOCK_on_virtual_non_default_constructible_throws)
        {
            try {
                auto mock = BONOBO_MOCK(
                    &WrongMacroNonDefaultConstructibleVirtualClass::virtual_func);
                FAIL() << "Expected bonobomock::BonoboMockError to be thrown";
            } catch (const bonobomock::BonoboMockError& e) {
                EXPECT_THAT(e.what(), HasSubstr("BONOBO_MOCK_VIRTUAL_ON"));
            }
        }
#endif

        // Test that BONOBO_MOCK on a non-virtual function works correctly (no abort)
        TEST(WrongMacroDeathTest, BONOBO_MOCK_on_non_virtual_function_succeeds)
        {
            // 'auto' type deduction requires C++11 or later.
#ifdef BSLS_COMPILERFEATURES_FULL_CPP11
            auto mock = BONOBO_MOCK(&WrongMacroNonVirtualClass::non_virtual_func);
#else
            bsl::shared_ptr<GMock<int(void*, int)> > mock = BONOBO_MOCK(&WrongMacroNonVirtualClass::non_virtual_func);
#endif

            EXPECT_CALL(*mock, BONOBO_MOCK_FUNCTION(_, _))
                .Times(1)
                .WillOnce(Return(42));

            WrongMacroNonVirtualClass obj;
            EXPECT_EQ(42, obj.non_virtual_func(1));

            mock->restore();

            EXPECT_EQ(2, obj.non_virtual_func(1));
        }

        // Test that BONOBO_MOCK_VIRTUAL on a virtual function works correctly (no abort)
        TEST(WrongMacroDeathTest, BONOBO_MOCK_VIRTUAL_on_virtual_function_succeeds)
        {
#ifdef BSLS_COMPILERFEATURES_FULL_CPP11
            auto mock = BONOBO_MOCK_VIRTUAL(&WrongMacroVirtualClass::virtual_func);
#else
            bsl::shared_ptr<GMock<int(void*, int)> > mock = BONOBO_MOCK_VIRTUAL(&WrongMacroVirtualClass::virtual_func);
#endif

            EXPECT_CALL(*mock, BONOBO_MOCK_FUNCTION(_, _))
                .Times(1)
                .WillOnce(Return(99));

            WrongMacroVirtualClass obj;
            EXPECT_EQ(99, obj.virtual_func(1));

            mock->restore();

            EXPECT_EQ(2, obj.virtual_func(1));
        }

    } // close test namespace
} // close package namespace
} // close enterprise namespace
