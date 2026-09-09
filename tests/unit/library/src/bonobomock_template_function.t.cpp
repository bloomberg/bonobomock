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
#include <gtest/gtest.h>

#include <bsl_memory.h>
#include <bsls_compilerfeatures.h>

#include <bonobomock_optimization_macros_api.h>

namespace BloombergLP {
namespace bonobomock {
    namespace test {

        using namespace ::testing;

        extern int non_virtual_member_wrapper();

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

        class TestLink {
        public:
            TestLink()
            {
                x = 0;
            }
            int x;
        };

        extern TestLink test_linkage();

        template <typename A>
        class SampleTemplateClass {
        public:
            template <typename B>
            BONOBO_MOCK_DISABLE_FUNCTION_OPTIMIZATION_START(sample_function)
            long sample_function(B b, B c)
            {
                long res = b + c;
                if (b % 2 == 0) {
                    if (c % 2 != 0) {
                        res += c * 2;
                    } else {
                        res += b * 2;
                    }
                } else if (b > c) {
                    res -= c;
                } else {
                    res += b;
                }
                volatile long _r = res;
                return _r;
            }

            template <typename B>
            BONOBO_MOCK_DISABLE_FUNCTION_OPTIMIZATION_START(sample_function)
            long sample_function(B b, B c, A d)
            {
                long res = b + c + d;
                if (b % 2 == 0) {
                    if (c % 2 != 0) {
                        res += c * 2;
                    } else if (d % 2 != 0) {
                        res += d * 2;
                    } else {
                        res += b * 2;
                    }
                } else if (b > c) {
                    res -= c;
                } else if (d > b) {
                    res += d;
                } else {
                    res += b;
                }
                volatile long _r = res;
                return _r;
            }

            template <typename B>
            BONOBO_MOCK_DISABLE_FUNCTION_OPTIMIZATION_START(sample_function)
            long sample_function(B b, B c) const
            {
                long res = b + c;
                if (b % 2 != 0) {
                    if (c % 2 == 0) {
                        res += c * 2;
                    } else {
                        res += b * 2;
                    }
                } else if (b < c) {
                    res -= c;
                } else {
                    res += b;
                }
                volatile long _r = res;
                return _r;
            }
        };

        long sample_function_wrapper_for_template(long a, long b)
        {
            SampleTemplateClass<int> obj;
            return obj.sample_function(a, b, 0);
        }

        TEST(Template, Mock)
        {
            typedef long (SampleTemplateClass<int>::*FUNC_TYPE_1)(long, long);
            FUNC_TYPE_1 functor1 = &SampleTemplateClass<int>::sample_function;

            typedef long (SampleTemplateClass<int>::*FUNC_TYPE_2)(long, long, int);
            FUNC_TYPE_2 functor2 = &SampleTemplateClass<int>::sample_function;

            typedef long (SampleTemplateClass<int>::*FUNC_TYPE_3)(long, long) const;
            FUNC_TYPE_3 functor3 = &SampleTemplateClass<int>::sample_function;

            // 'auto' type deduction requires C++11 or later.
#ifdef BSLS_COMPILERFEATURES_FULL_CPP11
            auto mock1 = BONOBO_MOCK(functor1);
            auto mock2 = BONOBO_MOCK(functor2);
            auto mock3 = BONOBO_MOCK(functor3);
#else
            bsl::shared_ptr<GMock<long(void*, long, long)> > mock1 = BONOBO_MOCK(functor1);
            bsl::shared_ptr<GMock<long(void*, long, long, int)> > mock2 = BONOBO_MOCK(functor2);
            bsl::shared_ptr<GMock<long(const void*, long, long)> > mock3 = BONOBO_MOCK(functor3);
#endif

            EXPECT_CALL(*mock1, BONOBO_MOCK_FUNCTION(_, _, _))
                .Times(1)
                .WillOnce(Return(100));

            EXPECT_CALL(*mock2, BONOBO_MOCK_FUNCTION(_, _, _, _))
                .Times(2)
                .WillOnce(Return(101))
                .WillOnce(Return(102));

            EXPECT_CALL(*mock3, BONOBO_MOCK_FUNCTION(_, _, _))
                .Times(1)
                .WillOnce(Return(103));

            SampleTemplateClass<int> obj;

            EXPECT_EQ(100, obj.sample_function<long>(0, 0));
            EXPECT_EQ(101, obj.sample_function<long>(0, 0, 0));
            EXPECT_EQ(102, sample_function_wrapper_for_template(0, 0));

            const SampleTemplateClass<int> obj_const;
            EXPECT_EQ(103, obj_const.sample_function<long>(0, 0));

            // Tell bonobomock to stop mocking, use the original sample_function.
            mock1->restore();
            mock2->restore();
            mock3->restore();

            EXPECT_EQ(0, obj.sample_function<long>(0, 0));
            EXPECT_EQ(0, obj.sample_function<long>(0, 0, 0));
            EXPECT_EQ(0, sample_function_wrapper_for_template(0, 0));
            EXPECT_EQ(0, obj_const.sample_function<long>(0, 0));
        }

        TEST(Template, Mock_linkage)
        {
            // Mock the non-virtual function `member_function`
            // 'auto' type deduction requires C++11 or later.
#ifdef BSLS_COMPILERFEATURES_FULL_CPP11
            auto mock = BONOBO_MOCK(&SampleClassNonVirtual::member_function);
            auto mock2 = BONOBO_MOCK(&test_linkage);
#else
            bsl::shared_ptr<GMock<int(void*, bool)> > mock = BONOBO_MOCK(&SampleClassNonVirtual::member_function);
            bsl::shared_ptr<GMock<TestLink()> > mock2 = BONOBO_MOCK(&test_linkage);
#endif

            // Defined the 2nd mocked function for `member_function`.
            // BONOBO_MOCK_FUNCTION is taking any input; using _ as the first
            // argument matches calls on all instances.
            // Return 100.
            EXPECT_CALL(*mock, BONOBO_MOCK_FUNCTION(_, _))
                .Times(1)
                .WillOnce(Return(100));

            TestLink obj2;
            obj2.x = 3;
            EXPECT_CALL(*mock2, BONOBO_MOCK_FUNCTION())
                .Times(1)
                .WillOnce(Return(obj2));

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

            TestLink tl = test_linkage();
            EXPECT_EQ(3, tl.x);

            // Tell bonobomock to stop mocking, use the original sample_function.
            mock->restore();
            mock2->restore();

            EXPECT_EQ(1, obj.member_function(true));
            EXPECT_EQ(0, non_virtual_member_wrapper());
            TestLink tll = test_linkage();
            EXPECT_EQ(0, tll.x);
        }

    } // close test namespace
} // close package namespace
} // close enterprise namespace
