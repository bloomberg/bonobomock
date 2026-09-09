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

// Regression tests for in-process demangling of modern C++ symbols.
// Private function mocking resolves addresses via nm + demangling.
// Older system demanglers (e.g. binutils 2.27 on RHEL 7) crash on
// C++17/20/23 mangling.  These tests verify that our in-process
// demangler handles these symbols correctly.

#include <bonobomock_api.h>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <bsls_compilerfeatures.h>

#include <bonobomock_optimization_macros_api.h>

// ============================================================================
//                              C++17 TESTS
// ============================================================================

#ifdef BSLS_COMPILERFEATURES_FULL_CPP17

    #include <optional>
    #include <string_view>

namespace BloombergLP {
namespace bonobomock {
    namespace test {
        namespace cpp17 {
            using namespace ::testing;

            class SampleClassCpp17 {
            public:
                int call_optional(std::optional<int> in)
                {
                    return private_with_optional(in);
                }

                int call_string_view(std::string_view in)
                {
                    return private_with_string_view(in);
                }

            private:
                BONOBO_MOCK_DISABLE_FUNCTION_OPTIMIZATION_START(private_with_optional)
                int private_with_optional(std::optional<int> in)
                {
                    return in.value_or(0);
                }
                BONOBO_MOCK_DISABLE_FUNCTION_OPTIMIZATION_END(private_with_optional)

                BONOBO_MOCK_DISABLE_FUNCTION_OPTIMIZATION_START(private_with_string_view)
                int private_with_string_view(std::string_view in)
                {
                    return static_cast<int>(in.size());
                }
                BONOBO_MOCK_DISABLE_FUNCTION_OPTIMIZATION_END(private_with_string_view)
            };

            int sig_private_with_optional(std::optional<int> in)
            {
                return in.value_or(0);
            }

            int sig_private_with_string_view(std::string_view in)
            {
                return static_cast<int>(in.size());
            }

            TEST(PrivateModernCpp17, Mock_private_with_optional)
            {
                auto mock = BONOBO_MOCK_PRIVATE_NON_CONST(
                    BloombergLP::bonobomock::test::cpp17::SampleClassCpp17::
                        private_with_optional,
                    BloombergLP::bonobomock::test::cpp17::SampleClassCpp17,
                    &sig_private_with_optional);

                SampleClassCpp17 obj;
                EXPECT_CALL(*mock, BONOBO_MOCK_FUNCTION(_, _))
                    .Times(1)
                    .WillOnce(Return(42));

                EXPECT_EQ(42, obj.call_optional(std::optional<int>(10)));

                mock->restore();

                EXPECT_EQ(10, obj.call_optional(std::optional<int>(10)));
                EXPECT_EQ(0, obj.call_optional(std::nullopt));
            }

            TEST(PrivateModernCpp17, Mock_private_with_string_view)
            {
                auto mock = BONOBO_MOCK_PRIVATE_NON_CONST(
                    BloombergLP::bonobomock::test::cpp17::SampleClassCpp17::
                        private_with_string_view,
                    BloombergLP::bonobomock::test::cpp17::SampleClassCpp17,
                    &sig_private_with_string_view);

                SampleClassCpp17 obj;
                EXPECT_CALL(*mock, BONOBO_MOCK_FUNCTION(_, _))
                    .Times(1)
                    .WillOnce(Return(99));

                EXPECT_EQ(99, obj.call_string_view("hello"));

                mock->restore();

                EXPECT_EQ(5, obj.call_string_view("hello"));
            }

        } // namespace cpp17
    } // namespace test
} // namespace bonobomock
} // namespace BloombergLP

#endif // BSLS_COMPILERFEATURES_FULL_CPP17

// ============================================================================
//                              C++20 TESTS
// ============================================================================

#ifdef BSLS_COMPILERFEATURES_SUPPORT_CONCEPTS

    #include <span>

namespace BloombergLP {
namespace bonobomock {
    namespace test {
        namespace cpp20_span {
            using namespace ::testing;

            class SampleClassCpp20Span {
            public:
                int call_span(std::span<const int> in)
                {
                    return private_with_span(in);
                }

            private:
                BONOBO_MOCK_DISABLE_FUNCTION_OPTIMIZATION_START(private_with_span)
                int private_with_span(std::span<const int> in)
                {
                    int sum = 0;
                    for (int v : in) {
                        sum += v;
                    }
                    return sum;
                }
                BONOBO_MOCK_DISABLE_FUNCTION_OPTIMIZATION_END(private_with_span)
            };

            int sig_private_with_span(std::span<const int> in)
            {
                (void)in;
                return 0;
            }

            TEST(PrivateModernCpp20, Mock_private_with_span)
            {
                auto mock = BONOBO_MOCK_PRIVATE_NON_CONST(
                    BloombergLP::bonobomock::test::cpp20_span::SampleClassCpp20Span::
                        private_with_span,
                    BloombergLP::bonobomock::test::cpp20_span::SampleClassCpp20Span,
                    &sig_private_with_span);

                SampleClassCpp20Span obj;
                int data[] = { 1, 2, 3, 4, 5 };
                EXPECT_CALL(*mock, BONOBO_MOCK_FUNCTION(_, _))
                    .Times(1)
                    .WillOnce(Return(77));

                EXPECT_EQ(77, obj.call_span(std::span<const int>(data, 5)));

                mock->restore();

                EXPECT_EQ(15, obj.call_span(std::span<const int>(data, 5)));
            }

        } // namespace cpp20_span
    } // namespace test
} // namespace bonobomock
} // namespace BloombergLP

#endif // BSLS_COMPILERFEATURES_SUPPORT_CONCEPTS

// NOTE: char8_t (C++20) uses the new ABI mangling "Du" which
// abi::__cxa_demangle does not recognise on systems with older
// libstdc++ (e.g. libstdc++ 8.x on RHEL 8).  Private function
// mocking for signatures containing char8_t is therefore a known
// limitation on those platforms.

// ============================================================================
//                              C++23 TESTS
// ============================================================================

#if __cplusplus >= 202302L

    #include <expected>

namespace BloombergLP {
namespace bonobomock {
    namespace test {
        namespace cpp23 {
            using namespace ::testing;

            class SampleClassCpp23 {
            public:
                int call_expected(std::expected<int, int> in)
                {
                    return private_with_expected(in);
                }

            private:
                BONOBO_MOCK_DISABLE_FUNCTION_OPTIMIZATION_START(private_with_expected)
                int private_with_expected(std::expected<int, int> in)
                {
                    return in.value_or(-1);
                }
                BONOBO_MOCK_DISABLE_FUNCTION_OPTIMIZATION_END(private_with_expected)
            };

            int sig_private_with_expected(std::expected<int, int> in)
            {
                return in.value_or(-1);
            }

            TEST(PrivateModernCpp23, Mock_private_with_expected)
            {
                auto mock = BONOBO_MOCK_PRIVATE_NON_CONST(
                    BloombergLP::bonobomock::test::cpp23::SampleClassCpp23::
                        private_with_expected,
                    BloombergLP::bonobomock::test::cpp23::SampleClassCpp23,
                    &sig_private_with_expected);

                SampleClassCpp23 obj;
                EXPECT_CALL(*mock, BONOBO_MOCK_FUNCTION(_, _))
                    .Times(1)
                    .WillOnce(Return(88));

                EXPECT_EQ(88, obj.call_expected(std::expected<int, int>(42)));

                mock->restore();

                EXPECT_EQ(42, obj.call_expected(std::expected<int, int>(42)));
                EXPECT_EQ(-1,
                    obj.call_expected(std::unexpected<int>(99)));
            }

        } // namespace cpp23
    } // namespace test
} // namespace bonobomock
} // namespace BloombergLP

#endif // __cplusplus >= 202302L
