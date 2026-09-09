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

// Tests for BONOBO_MOCK auto-detection of virtual functions via the Itanium ABI.
// When the Itanium ABI and C++17 are available, BONOBO_MOCK can distinguish
// virtual from non-virtual member function pointers and resolve the real
// address via vtable lookup, without requiring BONOBO_MOCK_VIRTUAL.

namespace BloombergLP {
namespace bonobomock {
    namespace test {

        using namespace ::testing;

// Itanium ABI + C++17: BONOBO_MOCK auto-detects virtual functions and resolves
// them via vtable lookup.
#if BONOBO_MOCK_IS_ITANIUM_ABI && defined(BSLS_COMPILERFEATURES_FULL_CPP17)
        class AutoDetectVirtualClass {
        public:
            BONOBO_MOCK_DISABLE_FUNCTION_OPTIMIZATION_START(virtual_func)
            virtual int virtual_func(int x) { return x * 2; }
            BONOBO_MOCK_DISABLE_FUNCTION_OPTIMIZATION_END(virtual_func)
        };

        class AutoDetectNonVirtualClass {
        public:
            BONOBO_MOCK_DISABLE_FUNCTION_OPTIMIZATION_START(non_virtual_func)
            int non_virtual_func(int x) { return x + 1; }
            BONOBO_MOCK_DISABLE_FUNCTION_OPTIMIZATION_END(non_virtual_func)
        };

        class NonDefaultConstructibleVirtualClass {
        public:
            NonDefaultConstructibleVirtualClass(int x)
                : d_x(x)
            {
            }

            BONOBO_MOCK_DISABLE_FUNCTION_OPTIMIZATION_START(virtual_func)
            virtual int virtual_func(int x) { return x * d_x; }
            BONOBO_MOCK_DISABLE_FUNCTION_OPTIMIZATION_END(virtual_func)

        private:
            int d_x;
        };

        TEST(AutoDetectVirtual, auto_detects_and_mocks_virtual)
        {
            auto mock = BONOBO_MOCK(&AutoDetectVirtualClass::virtual_func);

            EXPECT_CALL(*mock, BONOBO_MOCK_FUNCTION(_, _)).Times(1).WillOnce(Return(99));

            AutoDetectVirtualClass obj;
            EXPECT_EQ(99, obj.virtual_func(1));

            mock->restore();

            EXPECT_EQ(2, obj.virtual_func(1));
        }

        TEST(AutoDetectVirtual, throws_for_non_default_constructible_virtual)
        {
            try {
                auto mock = BONOBO_MOCK(&NonDefaultConstructibleVirtualClass::virtual_func);
                FAIL() << "Expected bonobomock::BonoboMockError to be thrown";
            } catch (const bonobomock::BonoboMockError& e) {
                EXPECT_THAT(e.what(), HasSubstr("BONOBO_MOCK_VIRTUAL_ON"));
            }
        }

        // BONOBO_MOCK on a non-virtual member function works on all compilers.
        TEST(AutoDetectVirtual, non_virtual_continues_to_work)
        {
            auto mock = BONOBO_MOCK(&AutoDetectNonVirtualClass::non_virtual_func);

            EXPECT_CALL(*mock, BONOBO_MOCK_FUNCTION(_, _)).Times(1).WillOnce(Return(42));

            AutoDetectNonVirtualClass obj;
            EXPECT_EQ(42, obj.non_virtual_func(1));

            mock->restore();

            EXPECT_EQ(2, obj.non_virtual_func(1));
        }

#endif // BONOBO_MOCK_IS_ITANIUM_ABI && BSLS_COMPILERFEATURES_FULL_CPP17

    } // namespace test
} // namespace bonobomock
} // namespace BloombergLP
