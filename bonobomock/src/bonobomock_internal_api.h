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

#ifndef INCLUDED_BONOBOMOCK_INTERNAL_API
#define INCLUDED_BONOBOMOCK_INTERNAL_API

#if !defined(INCLUDED_BONOBOMOCK_API) && !defined(BONOBO_MOCK_BUILDING_LIBRARY)
    #error "This is a private header. Directly including it is a contract violation and undefined behavior."
#endif

#include <bonobomock_internal_abi_detection.h>

#include <bsls_compilerfeatures.h>

#ifdef BSLS_COMPILERFEATURES_FULL_CPP11
    #include <bonobomock_internal_creator.h>
    #include <bonobomock_internal_nice_mock_creator.h>
    #include <bonobomock_internal_strict_mock_creator.h>
#else
    #include <bonobomock_internal_creator_cpp03.h>
    #include <bonobomock_internal_nice_mock_creator_cpp03.h>
    #include <bonobomock_internal_strict_mock_creator_cpp03.h>
#endif

// Unique number to ensure mocks of functions with identical signatures are
// instantiated as different template specializations. __COUNTER__ is preferred
// (unique per TU), with __LINE__ as fallback (may conflict if two mocks share
// a line). __LINE__ is guaranteed by all C/C++ standards and needs no guard.
#ifdef __COUNTER__
    #define BONOBO_MOCK_INTERNAL_UNIQUE_NUMBER __COUNTER__
#else
    #define BONOBO_MOCK_INTERNAL_UNIQUE_NUMBER __LINE__
#endif

#define BONOBO_MOCK_INTERNAL(function, counter) \
    BloombergLP::bonobomock::MockCreator::createMock<counter>(function, #function)

#define BONOBO_MOCK_STRICT_INTERNAL(function, counter) \
    BloombergLP::bonobomock::StrictMockCreator::createMockStrict<counter>(function, #function)

#define BONOBO_MOCK_NICE_INTERNAL(function, counter) \
    BloombergLP::bonobomock::NiceMockCreator::createMockNice<counter>(function, #function)

// Virtual address resolution:
// - Itanium ABI (GCC/Clang): vtable lookup from PMF representation
// - SunPro: thunk parsing from PMF
#define BONOBO_MOCK_INTERNAL_VIRTUAL(function, counter) \
    BloombergLP::bonobomock::MockCreator::createVirtualMock<counter>(function, #function)
#define BONOBO_MOCK_INTERNAL_VIRTUAL_STRICT(function, counter) \
    BloombergLP::bonobomock::StrictMockCreator::createVirtualMockStrict<counter>(function, #function)
#define BONOBO_MOCK_INTERNAL_VIRTUAL_NICE(function, counter) \
    BloombergLP::bonobomock::NiceMockCreator::createVirtualMockNice<counter>(function, #function)

#define BONOBO_MOCK_INTERNAL_VIRTUAL_ON(instance, function, counter) \
    BloombergLP::bonobomock::MockCreator::createVirtualMock<counter>(instance, function, #function)
#define BONOBO_MOCK_INTERNAL_VIRTUAL_STRICT_ON(instance, function, counter) \
    BloombergLP::bonobomock::StrictMockCreator::createVirtualMockStrict<counter>(instance, function, #function)
#define BONOBO_MOCK_INTERNAL_VIRTUAL_NICE_ON(instance, function, counter) \
    BloombergLP::bonobomock::NiceMockCreator::createVirtualMockNice<counter>(instance, function, #function)

#define BONOBO_MOCK_INTERNAL_PRIVATE_STATIC(name, function, counter) \
    BloombergLP::bonobomock::MockCreator::createPrivateStaticMock<counter>(function, name)
#define BONOBO_MOCK_INTERNAL_PRIVATE_STATIC_STRICT(name, function, counter) \
    BloombergLP::bonobomock::StrictMockCreator::createPrivateStaticMockStrict<counter>(function, name)
#define BONOBO_MOCK_INTERNAL_PRIVATE_STATIC_NICE(name, function, counter) \
    BloombergLP::bonobomock::NiceMockCreator::createPrivateStaticMockNice<counter>(function, name)

#define BONOBO_MOCK_INTERNAL_PRIVATE_NON_CONST(class, name, function, counter) \
    BloombergLP::bonobomock::MockCreator::createPrivateMock<counter, class>(function, name)
#define BONOBO_MOCK_INTERNAL_PRIVATE_STRICT_NON_CONST(class, name, function, counter) \
    BloombergLP::bonobomock::StrictMockCreator::createPrivateMockStrict<counter, class>(function, name)
#define BONOBO_MOCK_INTERNAL_PRIVATE_NICE_NON_CONST(class, name, function, counter) \
    BloombergLP::bonobomock::NiceMockCreator::createPrivateMockNice<counter, class>(function, name)

#define BONOBO_MOCK_INTERNAL_PRIVATE_CONST(class, name, function, counter) \
    BloombergLP::bonobomock::MockCreator::createPrivateMockConst<counter, class>(function, name)
#define BONOBO_MOCK_INTERNAL_PRIVATE_STRICT_CONST(class, name, function, counter) \
    BloombergLP::bonobomock::StrictMockCreator::createPrivateMockStrictConst<counter, class>(function, name)
#define BONOBO_MOCK_INTERNAL_PRIVATE_NICE_CONST(class, name, function, counter) \
    BloombergLP::bonobomock::NiceMockCreator::createPrivateMockNiceConst<counter, class>(function, name)

// Constructor/destructor link dummying: these expand to empty out-of-line
// definitions. Unlike every other bonobomock macro, they emit definitions rather
// than runtime mock objects; the linker uses them in place of the real ones.
// 'signature' is a parenthesized parameter-type list, e.g. (int). The
// _WITH_INIT variant appends a member-initializer list (its trailing arguments)
// so classes with reference/const/non-default-constructible members can be
// dummied.
//
// These require the multiple-definition linker mode enabled by the
// ALLOW_CONSTRUCTOR_DUMMIES option of add_bonobomock_executable(), which also
// defines BONOBO_MOCK_ALLOW_CONSTRUCTOR_DUMMIES. Without it, using a dummy macro is a
// clear compile error instead of a cryptic multiple-definition link failure.
#ifdef BONOBO_MOCK_ALLOW_CONSTRUCTOR_DUMMIES
    #define BONOBO_DUMMY_INTERNAL_CONSTRUCTOR(qualified_class, leaf_name, signature) \
        qualified_class::leaf_name signature { }
    #define BONOBO_DUMMY_INTERNAL_CONSTRUCTOR_WITH_INIT(qualified_class, leaf_name, signature, ...) \
        qualified_class::leaf_name signature : __VA_ARGS__ { }
    #define BONOBO_DUMMY_INTERNAL_DESTRUCTOR(qualified_class, leaf_name) \
        qualified_class::~leaf_name() { }
#else
    // The ALLOW_CONSTRUCTOR_DUMMIES option was not passed, so
    // BONOBO_MOCK_ALLOW_CONSTRUCTOR_DUMMIES is undefined. Fail with a descriptive
    // compile error rather than the cryptic multiple-definition link error the
    // dummy definitions would otherwise cause. A negative-sized array typedef
    // (not static_assert) keeps the diagnostic working on pre-C++11 toolchains
    // such as SunPro/Solaris; the typedef name carries the explanation, and a
    // unique suffix lets several dummies in one file each report cleanly.
    #define BONOBO_DUMMY_INTERNAL_PASTE_(a, b) a##b
    #define BONOBO_DUMMY_INTERNAL_PASTE(a, b) BONOBO_DUMMY_INTERNAL_PASTE_(a, b)
    #define BONOBO_DUMMY_INTERNAL_REQUIRES_OPT_IN                                                 \
        typedef char BONOBO_DUMMY_INTERNAL_PASTE(                                                 \
            BONOBO_DUMMY_requires_ALLOW_CONSTRUCTOR_DUMMIES_option_of_add_bonobomock_executable_, \
            BONOBO_MOCK_INTERNAL_UNIQUE_NUMBER)[-1];
    #define BONOBO_DUMMY_INTERNAL_CONSTRUCTOR(qualified_class, leaf_name, signature) \
        BONOBO_DUMMY_INTERNAL_REQUIRES_OPT_IN
    #define BONOBO_DUMMY_INTERNAL_CONSTRUCTOR_WITH_INIT(qualified_class, leaf_name, signature, ...) \
        BONOBO_DUMMY_INTERNAL_REQUIRES_OPT_IN
    #define BONOBO_DUMMY_INTERNAL_DESTRUCTOR(qualified_class, leaf_name) \
        BONOBO_DUMMY_INTERNAL_REQUIRES_OPT_IN
#endif

#if defined(BSLS_COMPILERFEATURES_FULL_CPP11) && BONOBO_MOCK_INTERNAL_IS_ITANIUM_ABI

    #include <bsl_memory.h>

    #define BONOBO_MOCK_CLASS_MEMBER_(Class, method)                               \
        bsl::shared_ptr<                                                           \
            BloombergLP::bonobomock::MockClassTraits<                              \
                decltype(&Class::method)>::GMockType>                              \
            method##_bonobomock_ = BONOBO_MOCK(&Class::method);                    \
        template <typename... Matchers_>                                           \
        auto gmock_##method(const Matchers_&... matchers)                          \
            -> decltype(method##_bonobomock_->gmock_bonobomockInternalForwardFunc( \
                matchers...))                                                      \
        {                                                                          \
            return method##_bonobomock_->gmock_bonobomockInternalForwardFunc(      \
                matchers...);                                                      \
        }

    #define BONOBO_MOCK_STRICT_CLASS_MEMBER_(Class, method)                        \
        bsl::shared_ptr<                                                           \
            BloombergLP::bonobomock::MockClassTraits<                              \
                decltype(&Class::method)>::GMockType>                              \
            method##_bonobomock_ = BONOBO_MOCK_STRICT(&Class::method);             \
        template <typename... Matchers_>                                           \
        auto gmock_##method(const Matchers_&... matchers)                          \
            -> decltype(method##_bonobomock_->gmock_bonobomockInternalForwardFunc( \
                matchers...))                                                      \
        {                                                                          \
            return method##_bonobomock_->gmock_bonobomockInternalForwardFunc(      \
                matchers...);                                                      \
        }

    #define BONOBO_MOCK_NICE_CLASS_MEMBER_(Class, method)                          \
        bsl::shared_ptr<                                                           \
            BloombergLP::bonobomock::MockClassTraits<                              \
                decltype(&Class::method)>::GMockType>                              \
            method##_bonobomock_ = BONOBO_MOCK_NICE(&Class::method);               \
        template <typename... Matchers_>                                           \
        auto gmock_##method(const Matchers_&... matchers)                          \
            -> decltype(method##_bonobomock_->gmock_bonobomockInternalForwardFunc( \
                matchers...))                                                      \
        {                                                                          \
            return method##_bonobomock_->gmock_bonobomockInternalForwardFunc(      \
                matchers...);                                                      \
        }

    #define BONOBO_MOCK_CLASS_MEMBER_AS_(Class, method, alias, Signature)         \
        bsl::shared_ptr<                                                          \
            BloombergLP::bonobomock::MockClassTraits<Signature>::GMockType>       \
            alias##_bonobomock_ = BONOBO_MOCK(                                    \
                static_cast<Signature>(&Class::method));                          \
        template <typename... Matchers_>                                          \
        auto gmock_##alias(const Matchers_&... matchers)                          \
            -> decltype(alias##_bonobomock_->gmock_bonobomockInternalForwardFunc( \
                matchers...))                                                     \
        {                                                                         \
            return alias##_bonobomock_->gmock_bonobomockInternalForwardFunc(      \
                matchers...);                                                     \
        }

    #define BONOBO_MOCK_STRICT_CLASS_MEMBER_AS_(Class, method, alias, Signature)  \
        bsl::shared_ptr<                                                          \
            BloombergLP::bonobomock::MockClassTraits<Signature>::GMockType>       \
            alias##_bonobomock_ = BONOBO_MOCK_STRICT(                             \
                static_cast<Signature>(&Class::method));                          \
        template <typename... Matchers_>                                          \
        auto gmock_##alias(const Matchers_&... matchers)                          \
            -> decltype(alias##_bonobomock_->gmock_bonobomockInternalForwardFunc( \
                matchers...))                                                     \
        {                                                                         \
            return alias##_bonobomock_->gmock_bonobomockInternalForwardFunc(      \
                matchers...);                                                     \
        }

    #define BONOBO_MOCK_NICE_CLASS_MEMBER_AS_(Class, method, alias, Signature)    \
        bsl::shared_ptr<                                                          \
            BloombergLP::bonobomock::MockClassTraits<Signature>::GMockType>       \
            alias##_bonobomock_ = BONOBO_MOCK_NICE(                               \
                static_cast<Signature>(&Class::method));                          \
        template <typename... Matchers_>                                          \
        auto gmock_##alias(const Matchers_&... matchers)                          \
            -> decltype(alias##_bonobomock_->gmock_bonobomockInternalForwardFunc( \
                matchers...))                                                     \
        {                                                                         \
            return alias##_bonobomock_->gmock_bonobomockInternalForwardFunc(      \
                matchers...);                                                     \
        }

#endif // BSLS_COMPILERFEATURES_FULL_CPP11 && BONOBO_MOCK_INTERNAL_IS_ITANIUM_ABI

#endif
