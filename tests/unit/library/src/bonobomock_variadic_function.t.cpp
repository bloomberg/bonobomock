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

// include this header to use bonobomock
#include <bonobomock_api.h>

// third party includes
// include GoogleTest
#include <gmock/gmock.h>
#include <gtest/gtest-spi.h>
#include <gtest/gtest.h>

#include <bsls_compilerfeatures.h>

#include <bonobomock_optimization_macros_api.h>

#include <cstdarg>

namespace BloombergLP {
namespace bonobomock {
    namespace test {

        using namespace ::testing;

// Variadic templates require C++11 or later.
#ifdef BSLS_COMPILERFEATURES_FULL_CPP11
        template <typename T>
        BONOBO_MOCK_DISABLE_FUNCTION_OPTIMIZATION_START(internal_variadic_impl)
        int internal_variadic_impl(T a)
        {
            volatile int _r = static_cast<int>(a);
            return _r;
        }
        BONOBO_MOCK_DISABLE_FUNCTION_OPTIMIZATION_END(internal_variadic_impl)

        template <typename T, typename... Types>
        BONOBO_MOCK_DISABLE_FUNCTION_OPTIMIZATION_START(internal_variadic_impl)
        int internal_variadic_impl(T a, Types... args)
        {
            int val = static_cast<int>(a);
            volatile int _r = val + internal_variadic_impl(args...);
            return _r;
        }
        BONOBO_MOCK_DISABLE_FUNCTION_OPTIMIZATION_END(internal_variadic_impl)

        template <typename... Types>
        BONOBO_MOCK_DISABLE_FUNCTION_OPTIMIZATION_START(variadic_function_1)
        int variadic_function_1(Types... args)
        {
            volatile int _r = internal_variadic_impl(args...);
            return _r;
        }
        BONOBO_MOCK_DISABLE_FUNCTION_OPTIMIZATION_END(variadic_function_1)

        BONOBO_MOCK_DISABLE_FUNCTION_OPTIMIZATION_START(variadic_function_2)
        int variadic_function_2(const char* fmt, ...)
        {
            va_list args;
            va_start(args, fmt);

            int sum = 0;

            while (*fmt != '\0') {
                if (*fmt == 'd') {
                    int i = va_arg(args, int);
                    sum += i;
                }
                ++fmt;
            }

            va_end(args);
            volatile int _r = sum;
            return _r;
        }
        BONOBO_MOCK_DISABLE_FUNCTION_OPTIMIZATION_END(variadic_function_2)

        TEST(Variadic, variadic_template_function)
        {
            typedef int (*FUNC_TYPE_1)(int);
            typedef int (*FUNC_TYPE_2)(int, int);

            FUNC_TYPE_1 functor1 = &variadic_function_1<int>;
            FUNC_TYPE_2 functor2 = &variadic_function_1<int, int>;

            auto mock1 = BONOBO_MOCK(functor1);
            auto mock2 = BONOBO_MOCK(functor2);

            EXPECT_CALL(*mock1, BONOBO_MOCK_FUNCTION(_))
                .Times(1)
                .WillOnce(Return(100));

            EXPECT_CALL(*mock2, BONOBO_MOCK_FUNCTION(_, _))
                .Times(1)
                .WillOnce(Return(200));

            EXPECT_EQ(100, variadic_function_1(1));
            EXPECT_EQ(200, variadic_function_1(1, 2));

            mock1->restore();
            mock2->restore();

            EXPECT_EQ(1, variadic_function_1(1));
            EXPECT_EQ(3, variadic_function_1(1, 2));
        }

        TEST(Variadic, va_arg)
        {
            auto mock1 = BONOBO_MOCK(&variadic_function_2);

            EXPECT_CALL(*mock1, BONOBO_MOCK_FUNCTION(_))
                .Times(2)
                .WillOnce(Return(100))
                .WillOnce(Return(200));

            EXPECT_CALL(*mock1, BONOBO_MOCK_FUNCTION(StrEq("ddd")))
                .Times(1)
                .WillOnce(Return(300));

            EXPECT_EQ(100, variadic_function_2("d", 1));
            EXPECT_EQ(200, variadic_function_2("dd", 1, 2));
            EXPECT_EQ(300, variadic_function_2("ddd", 1, 2, 3));

            mock1->restore();

            EXPECT_EQ(1, variadic_function_2("d", 1));
            EXPECT_EQ(3, variadic_function_2("dd", 1, 2));
            EXPECT_EQ(6, variadic_function_2("ddd", 1, 2, 3));
        }

        //==============================================================================
        // STRICT MOCK TESTS: VARIADIC FUNCTIONS
        //==============================================================================

        TEST(StrictMock_Variadic, VariadicTemplate_SingleParam)
        {
            EXPECT_NONFATAL_FAILURE(
                {
                    typedef int (*FUNC_TYPE)(int);
                    FUNC_TYPE functor = &(variadic_function_1<int>);
                    auto mock = BONOBO_MOCK_STRICT(functor);
                    // No expectations set on the mock.
                    // All calls to the mocked function will be "uninteresting".
                    // They should trigger the strict mock failure.
                    {
                        variadic_function_1(1);
                    }
                },
                "Uninteresting mock function call");
        }

        // When using a C-style variadic function in the first argument of
        // EXPECT_NONFATAL_FAILURE macro, the comma between first and second
        // argument can be interpreted by the compiler as a continuation of
        // variadic function parameters instead of separating the two
        // arguments of the EXPECT_NONFATAL_FAILURE macro. To avoid this,
        // we use a helper function to create the strict mock and call the
        // variadic function inside that helper.
        void create_strict_mock_of_variadic_func_with_multi_param_and_call_it()
        {
            typedef int (*FUNC_TYPE)(int, int);
            FUNC_TYPE functor = &variadic_function_1<int, int>;
            auto mock = BONOBO_MOCK_STRICT(functor);
            // No expectations set on the mock.
            // All calls to the mocked function will be "uninteresting".
            // They should trigger the strict mock failure.
            variadic_function_1(1, 2);
        }

        TEST(StrictMock_Variadic, VariadicTemplate_MultiParam)
        {
            EXPECT_NONFATAL_FAILURE(
                {
                    create_strict_mock_of_variadic_func_with_multi_param_and_call_it();
                },
                "Uninteresting mock function call");
        }

        // When using a C-style variadic function in the first argument of
        // EXPECT_NONFATAL_FAILURE macro, the comma between first and second
        // argument can be interpreted by the compiler as a continuation of
        // variadic function parameters instead of separating the two
        // arguments of the EXPECT_NONFATAL_FAILURE macro. To avoid this,
        // we use a helper function to create the strict mock and call the
        // variadic function inside that helper.
        void create_strict_mock_of_variadic_va_arg_and_call_it()
        {
            auto mock = BONOBO_MOCK_STRICT(&variadic_function_2);
            // No expectations set on the mock.
            // All calls to the mocked function will be "uninteresting".
            // They should trigger the strict mock failure.
            variadic_function_2("d", 1);
        }

        TEST(StrictMock_Variadic, VaArg)
        {
            EXPECT_NONFATAL_FAILURE(
                create_strict_mock_of_variadic_va_arg_and_call_it(),
                "Uninteresting mock function call");
        }
#endif

    }
}
}
