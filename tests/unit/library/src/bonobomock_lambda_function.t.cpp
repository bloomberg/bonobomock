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
#include <gtest/gtest.h>

#include <bsls_compilerfeatures.h>

#include <bonobomock_optimization_macros_api.h>

#include <cstdarg>

namespace BloombergLP {
namespace bonobomock {
    namespace test {

        using namespace ::testing;

// Lambda expressions require C++11 or later. Lambda mocking is not supported on MSVC.
#if defined(BSLS_COMPILERFEATURES_FULL_CPP11) && !defined(_MSC_VER)
    // This test relies on the compiler inlining direct lambda calls so they
    // bypass bonobomock's entry-point patch.  At -O0 no inlining occurs: every
    // call (including the "direct" ones) goes through the patched operator(),
    // causing the mock to see more calls than expected.  __OPTIMIZE__ is
    // defined by GCC/Clang at -O1 and above.
    #if defined(BONOBO_MOCK_APPLY_OPTIMIZATION_RESTRICTIONS) && defined(__OPTIMIZE__)

        namespace {
            auto lambdaFunc = [](int a) { return a > 10; };

            BONOBO_MOCK_DISABLE_FUNCTION_OPTIMIZATION_START(lambda_wrapper)
            bool lambda_wrapper(int a)
            {
                return lambdaFunc(a);
            }
            BONOBO_MOCK_DISABLE_FUNCTION_OPTIMIZATION_END(lambda_wrapper)
        }

        TEST(Lambda, example_with_optimization)
        {
            // calling lambda function directly won't trigger the mocking behavior due to compiler optimization
            EXPECT_FALSE(lambdaFunc(10));
            // demonstrate existing behavior of our lambda in the wrapper function
            EXPECT_FALSE(lambda_wrapper(10));

            auto functor = &decltype(lambdaFunc)::operator();
            auto mock = BONOBO_MOCK(functor);

            EXPECT_CALL(*mock, BONOBO_MOCK_FUNCTION(_, _))
                .Times(2)
                .WillOnce(Return(true))
                .WillOnce(Return(true));
            // the behavior of the lambda is now overridden for our testing by calling the wrapper function
            EXPECT_TRUE(lambda_wrapper(10));
            EXPECT_TRUE(lambda_wrapper(10));
            // calling lambda function directly won't trigger the mocking behavior due to compiler optimization
            EXPECT_FALSE(lambdaFunc(10));

            mock->restore();

            // calling lambda function directly won't trigger the mocking behavior due to compiler optimization
            EXPECT_FALSE(lambdaFunc(10));
            // pre-existing behavior of the lambda is restored when wrapper function is called
            EXPECT_FALSE(lambda_wrapper(10));
        }
    #else
        TEST(Lambda, example_without_optimization)
        {
            auto lambdaFunc = [](int a) { return a > 10; };
            // demonstrate existing behavior of our lambda
            EXPECT_FALSE(lambdaFunc(10));

            auto functor = &decltype(lambdaFunc)::operator();
            auto mock = BONOBO_MOCK(functor);

            EXPECT_CALL(*mock, BONOBO_MOCK_FUNCTION(_, _))
                .Times(1)
                .WillOnce(Return(true));

            // the behavior of the lambda is now overridden for our testing
            EXPECT_TRUE(lambdaFunc(10));

            mock->restore();

            // pre-existing behavior of the lambda is restored
            EXPECT_FALSE(lambdaFunc(10));
        }
    #endif
#endif
    }
}
}
