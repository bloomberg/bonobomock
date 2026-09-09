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

#include <bonobomock_api.h>

#include <gmock/gmock.h>
#include <gtest/gtest-spi.h>
#include <gtest/gtest.h>

#include <bsl_memory.h>
#include <bsls_compilerfeatures.h>

#include <bonobomock_optimization_macros_api.h>

#if defined(BSLS_COMPILERFEATURES_FULL_CPP11) && BONOBO_MOCK_IS_ITANIUM_ABI

namespace BloombergLP {
namespace bonobomock {
    namespace test {

        using namespace ::testing;

        // ============================================================================
        // Test helpers: classes with methods to mock
        // ============================================================================

        class Utility {
        public:
            BONOBO_MOCK_DISABLE_FUNCTION_OPTIMIZATION_START(compute)
            static int compute(int a, int b)
            {
                return a + b;
            }
            BONOBO_MOCK_DISABLE_FUNCTION_OPTIMIZATION_END(compute)

            BONOBO_MOCK_DISABLE_FUNCTION_OPTIMIZATION_START(validate)
            static bool validate(int value)
            {
                return value > 0;
            }
            BONOBO_MOCK_DISABLE_FUNCTION_OPTIMIZATION_END(validate)
        };

        class Overloaded {
        public:
            BONOBO_MOCK_DISABLE_FUNCTION_OPTIMIZATION_START(process)
            static int process(int a)
            {
                return a;
            }
            BONOBO_MOCK_DISABLE_FUNCTION_OPTIMIZATION_END(process)

            // Separate optimization macro name to avoid redefinition
            BONOBO_MOCK_DISABLE_FUNCTION_OPTIMIZATION_START(processTwo)
            static int process(int a, int b)
            {
                return a + b;
            }
            BONOBO_MOCK_DISABLE_FUNCTION_OPTIMIZATION_END(processTwo)
        };

        class Logger {
        public:
            BONOBO_MOCK_DISABLE_FUNCTION_OPTIMIZATION_START(log)
            static void log(int level)
            {
                (void)level;
            }
            BONOBO_MOCK_DISABLE_FUNCTION_OPTIMIZATION_END(log)
        };

        class Widget {
        public:
            BONOBO_MOCK_DISABLE_FUNCTION_OPTIMIZATION_START(transform)
            int transform(int value)
            {
                return value * 2;
            }
            BONOBO_MOCK_DISABLE_FUNCTION_OPTIMIZATION_END(transform)

            BONOBO_MOCK_DISABLE_FUNCTION_OPTIMIZATION_START(name)
            int name() const
            {
                return 0;
            }
            BONOBO_MOCK_DISABLE_FUNCTION_OPTIMIZATION_END(name)
        };

        class Shape {
        public:
            BONOBO_MOCK_DISABLE_FUNCTION_OPTIMIZATION_START(area)
            virtual double area() const
            {
                return 0.0;
            }
            BONOBO_MOCK_DISABLE_FUNCTION_OPTIMIZATION_END(area)

            BONOBO_MOCK_DISABLE_FUNCTION_OPTIMIZATION_START(scale)
            virtual void scale(double factor)
            {
                (void)factor;
            }
            BONOBO_MOCK_DISABLE_FUNCTION_OPTIMIZATION_END(scale)

            virtual ~Shape() { }
        };

        template <typename T>
        class Container {
        public:
            BONOBO_MOCK_DISABLE_FUNCTION_OPTIMIZATION_START(size)
            static int size()
            {
                return 0;
            }
            BONOBO_MOCK_DISABLE_FUNCTION_OPTIMIZATION_END(size)

            BONOBO_MOCK_DISABLE_FUNCTION_OPTIMIZATION_START(get)
            T get(int index)
            {
                (void)index;
                return T();
            }
            BONOBO_MOCK_DISABLE_FUNCTION_OPTIMIZATION_END(get)
        };

        // ============================================================================
        // Mock class definitions (must be at namespace scope, not inside TEST bodies,
        // because they contain template member functions)
        // ============================================================================

        struct SingleMethodMock {
            BONOBO_MOCK_METHOD(Utility, compute);
        };

        struct MultiMethodMock {
            BONOBO_MOCK_METHOD(Utility, compute);
            BONOBO_MOCK_METHOD(Utility, validate);
        };

        struct CombinedMock {
            BONOBO_MOCK_METHOD(Utility, compute);
            BONOBO_MOCK_METHOD(Logger, log);
        };

        struct ValidateMock {
            BONOBO_MOCK_METHOD(Utility, validate);
        };

        struct StrictComputeMock {
            BONOBO_MOCK_METHOD_STRICT(Utility, compute);
        };

        struct NiceComputeMock {
            BONOBO_MOCK_METHOD_NICE(Utility, compute);
        };

        struct OverloadedMock {
            BONOBO_MOCK_METHOD_AS(Overloaded, process, processOne, int (*)(int));
            using ProcessTwoPtr = int (*)(int, int);
            BONOBO_MOCK_METHOD_AS(Overloaded, process, processTwo, ProcessTwoPtr);
        };

        struct WidgetMock {
            BONOBO_MOCK_METHOD(Widget, transform);
            BONOBO_MOCK_METHOD(Widget, name);
        };

        struct ShapeMock {
            BONOBO_MOCK_METHOD(Shape, area);
            BONOBO_MOCK_METHOD(Shape, scale);
        };

        struct ContainerIntMock {
            BONOBO_MOCK_METHOD(Container<int>, size);
            BONOBO_MOCK_METHOD(Container<int>, get);
        };

        // ============================================================================
        // Mock class tests
        // ============================================================================

        TEST(MockClass, SingleStaticMethod)
        {
            SingleMethodMock mock;

            EXPECT_CALL(mock, compute(2, 3))
                .WillOnce(Return(42));

            EXPECT_EQ(42, Utility::compute(2, 3));
        }

        TEST(MockClass, MultipleStaticMethods)
        {
            MultiMethodMock mock;

            EXPECT_CALL(mock, compute(1, 2))
                .WillOnce(Return(100));
            EXPECT_CALL(mock, validate(-100))
                .WillOnce(Return(true));

            EXPECT_EQ(100, Utility::compute(1, 2));
            EXPECT_TRUE(Utility::validate(-100));
        }

        TEST(MockClass, MethodsFromDifferentClasses)
        {
            CombinedMock mock;

            EXPECT_CALL(mock, compute(_, _))
                .WillOnce(Return(0));
            EXPECT_CALL(mock, log(1));

            Utility::compute(5, 6);
            Logger::log(1);
        }

        TEST(MockClass, RAII)
        {
            EXPECT_EQ(5, Utility::compute(2, 3));

            {
                SingleMethodMock mock;

                EXPECT_CALL(mock, compute(2, 3))
                    .WillOnce(Return(99));
                EXPECT_EQ(99, Utility::compute(2, 3));
            }

            EXPECT_EQ(5, Utility::compute(2, 3));
        }

        TEST(MockClass, WillRepeatedly)
        {
            ValidateMock mock;

            EXPECT_CALL(mock, validate(_))
                .WillRepeatedly(Return(true));

            EXPECT_TRUE(Utility::validate(-1));
            EXPECT_TRUE(Utility::validate(0));
            EXPECT_TRUE(Utility::validate(100));
        }

        // ============================================================================
        // Strict mock class tests
        // ============================================================================

        TEST(MockClass_Strict, UninterestingCallFails)
        {
            EXPECT_NONFATAL_FAILURE(
                {
                    StrictComputeMock mock;

                    Utility::compute(1, 2);
                },
                "Uninteresting mock function call");
        }

        // ============================================================================
        // Nice mock class tests
        // ============================================================================

        TEST(MockClass_Nice, UninterestingCallSuppressed)
        {
            testing::internal::CaptureStdout();
            testing::internal::CaptureStderr();
            {
                NiceComputeMock mock;

                Utility::compute(1, 2);
            }
            bsl::string stderrOutput = testing::internal::GetCapturedStderr();
            bsl::string stdoutOutput = testing::internal::GetCapturedStdout();
            EXPECT_THAT(stderrOutput, Not(HasSubstr("Uninteresting")));
            EXPECT_THAT(stdoutOutput, Not(HasSubstr("Uninteresting")));
        }

        // ============================================================================
        // Overloaded function tests
        // ============================================================================

        TEST(MockClass, OverloadedFunctions)
        {
            OverloadedMock mock;

            EXPECT_CALL(mock, processOne(5))
                .WillOnce(Return(50));
            EXPECT_CALL(mock, processTwo(1, 2))
                .WillOnce(Return(99));

            EXPECT_EQ(50, Overloaded::process(5));
            EXPECT_EQ(99, Overloaded::process(1, 2));
        }

        // ============================================================================
        // Non-virtual member function tests
        // ============================================================================

        TEST(MockClass, NonVirtualMemberFunction)
        {
            WidgetMock mock;

            // First arg is the object pointer (this), matched with _
            EXPECT_CALL(mock, transform(_, 10))
                .WillOnce(Return(99));

            Widget w;
            EXPECT_EQ(99, w.transform(10));
        }

        TEST(MockClass, ConstMemberFunction)
        {
            WidgetMock mock;

            EXPECT_CALL(mock, name(_))
                .WillOnce(Return(42));

            const Widget w;
            EXPECT_EQ(42, w.name());
        }

        // ============================================================================
        // Virtual member function tests
        // ============================================================================

        TEST(MockClass, VirtualMemberFunction)
        {
            ShapeMock mock;

            EXPECT_CALL(mock, area(_))
                .WillOnce(Return(3.14));
            EXPECT_CALL(mock, scale(_, 2.0));

            Shape s;
            EXPECT_DOUBLE_EQ(3.14, s.area());
            s.scale(2.0);
        }

        // ============================================================================
        // Template class tests
        // ============================================================================

        TEST(MockClass, TemplateClassStaticMethod)
        {
            ContainerIntMock mock;

            EXPECT_CALL(mock, size())
                .WillOnce(Return(42));

            EXPECT_EQ(42, Container<int>::size());
        }

        TEST(MockClass, TemplateClassMemberFunction)
        {
            ContainerIntMock mock;

            // First arg is the object pointer (this), matched with _
            EXPECT_CALL(mock, get(_, 0))
                .WillOnce(Return(99));

            Container<int> c;
            EXPECT_EQ(99, c.get(0));
        }

        // ============================================================================
        // Regression: existing 1-arg BONOBO_MOCK still works
        // ============================================================================

        TEST(MockClass, OneArgFormStillWorks)
        {
            auto mock = BONOBO_MOCK(&Utility::compute);

            EXPECT_CALL(*mock, BONOBO_MOCK_FUNCTION(10, 20))
                .WillOnce(Return(999));

            EXPECT_EQ(999, Utility::compute(10, 20));
        }

        TEST(MockClass, OneArgStrictFormStillWorks)
        {
            auto mock = BONOBO_MOCK_STRICT(&Utility::compute);

            EXPECT_CALL(*mock, BONOBO_MOCK_FUNCTION(_, _))
                .WillOnce(Return(0));

            Utility::compute(1, 2);
        }

        TEST(MockClass, OneArgNiceFormStillWorks)
        {
            auto mock = BONOBO_MOCK_NICE(&Utility::compute);

            Utility::compute(1, 2);
        }

    } // close test namespace
} // close package namespace
} // close enterprise namespace

#endif // BSLS_COMPILERFEATURES_FULL_CPP11 && BONOBO_MOCK_IS_ITANIUM_ABI
