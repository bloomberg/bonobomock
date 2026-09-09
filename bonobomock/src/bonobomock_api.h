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

#ifndef INCLUDED_BONOBOMOCK_API
#define INCLUDED_BONOBOMOCK_API

#include <bonobomock_internal_api.h>
#include <bonobomock_internal_private_address_resolver.h>

#define BONOBO_MOCK_IS_ITANIUM_ABI BONOBO_MOCK_INTERNAL_IS_ITANIUM_ABI

//===============================================================================
// Macros for mocking global, static, public+protected non-virtual member functions,
// and Fortran functions.
// Note that these cannot be used for virtual or private functions.
//===============================================================================

// Creates a naggy mock (same semantics as gMock's NaggyMock,
// which is the default behavior when creating a gMock object).
#define BONOBO_MOCK(function) \
    BONOBO_MOCK_INTERNAL(function, BONOBO_MOCK_INTERNAL_UNIQUE_NUMBER)

// Equivalent to BONOBO_MOCK, but creates a strict mock (same semantics as gMock's StrictMock)
#define BONOBO_MOCK_STRICT(function) \
    BONOBO_MOCK_STRICT_INTERNAL(function, BONOBO_MOCK_INTERNAL_UNIQUE_NUMBER)

// Equivalent to BONOBO_MOCK, but creates a nice mock (same semantics as gMock's NiceMock)
#define BONOBO_MOCK_NICE(function) \
    BONOBO_MOCK_NICE_INTERNAL(function, BONOBO_MOCK_INTERNAL_UNIQUE_NUMBER)

//===============================================================================
// Macros for defining mock classes (C++11+).
// Use as member declarations in a struct to create a mock counterpart for a
// class, similar to gMock's MOCK_METHOD. Define one mock class per target
// class, listing its methods to mock:
//   struct ClassNameMock {
//       BONOBO_MOCK_METHOD(ClassName, method1);
//       BONOBO_MOCK_METHOD(ClassName, method2);
//   };
//   ClassNameMock mock;
//   EXPECT_CALL(mock, method1(args));
//===============================================================================
#if defined(BSLS_COMPILERFEATURES_FULL_CPP11) && BONOBO_MOCK_IS_ITANIUM_ABI
    #define BONOBO_MOCK_METHOD(Class, method) \
        BONOBO_MOCK_CLASS_MEMBER_(Class, method)
    #define BONOBO_MOCK_METHOD_STRICT(Class, method) \
        BONOBO_MOCK_STRICT_CLASS_MEMBER_(Class, method)
    #define BONOBO_MOCK_METHOD_NICE(Class, method) \
        BONOBO_MOCK_NICE_CLASS_MEMBER_(Class, method)

    // Disambiguate overloaded functions in a mock class by providing an alias
    // and the function pointer type (Signature).
    // If the signature contains commas, use a type alias for the Signature parameter.
    //   struct UtilityMock {
    //       BONOBO_MOCK_METHOD_AS(Utility, compute, computeInt, int(*)(int));
    //       using ComputeTwoPtr = int(*)(int, int);
    //       BONOBO_MOCK_METHOD_AS(Utility, compute, computeTwo, ComputeTwoPtr);
    //   };
    //   EXPECT_CALL(mock, computeInt(1));
    //   EXPECT_CALL(mock, computeTwo(1, 2));
    #define BONOBO_MOCK_METHOD_AS(Class, method, alias, Signature) \
        BONOBO_MOCK_CLASS_MEMBER_AS_(Class, method, alias, Signature)
    #define BONOBO_MOCK_METHOD_STRICT_AS(Class, method, alias, Signature) \
        BONOBO_MOCK_STRICT_CLASS_MEMBER_AS_(Class, method, alias, Signature)
    #define BONOBO_MOCK_METHOD_NICE_AS(Class, method, alias, Signature) \
        BONOBO_MOCK_NICE_CLASS_MEMBER_AS_(Class, method, alias, Signature)
#endif // BSLS_COMPILERFEATURES_FULL_CPP11 && BONOBO_MOCK_IS_ITANIUM_ABI

//===============================================================================
// Macros for mocking virtual functions
//===============================================================================

// Macros for creating a mock object for a virtual function.
// These work on all supported platforms (Itanium ABI and SunPro/SPARC).
// On Itanium, the PMF encodes a vtable offset directly. On SunPro, the PMF
// is resolved by parsing the compiler-generated thunk.
#define BONOBO_MOCK_VIRTUAL(function) \
    BONOBO_MOCK_INTERNAL_VIRTUAL(function, BONOBO_MOCK_INTERNAL_UNIQUE_NUMBER)
#define BONOBO_MOCK_VIRTUAL_STRICT(function) \
    BONOBO_MOCK_INTERNAL_VIRTUAL_STRICT(function, BONOBO_MOCK_INTERNAL_UNIQUE_NUMBER)
#define BONOBO_MOCK_VIRTUAL_NICE(function) \
    BONOBO_MOCK_INTERNAL_VIRTUAL_NICE(function, BONOBO_MOCK_INTERNAL_UNIQUE_NUMBER)

#define BONOBO_MOCK_VIRTUAL_ON(instance, function) \
    BONOBO_MOCK_INTERNAL_VIRTUAL_ON(instance, function, BONOBO_MOCK_INTERNAL_UNIQUE_NUMBER)
#define BONOBO_MOCK_VIRTUAL_STRICT_ON(instance, function) \
    BONOBO_MOCK_INTERNAL_VIRTUAL_STRICT_ON(instance, function, BONOBO_MOCK_INTERNAL_UNIQUE_NUMBER)
#define BONOBO_MOCK_VIRTUAL_NICE_ON(instance, function) \
    BONOBO_MOCK_INTERNAL_VIRTUAL_NICE_ON(instance, function, BONOBO_MOCK_INTERNAL_UNIQUE_NUMBER)

//===============================================================================
// Macros for mocking private static functions.
// These do not require a class parameter or const/non-const distinction.
//===============================================================================

// Creates a naggy mock for a private static function.
#define BONOBO_MOCK_PRIVATE_STATIC(function, signature) \
    BONOBO_MOCK_INTERNAL_PRIVATE_STATIC(#function, signature, BONOBO_MOCK_INTERNAL_UNIQUE_NUMBER)

// Equivalent to BONOBO_MOCK_PRIVATE_STATIC, but creates a strict mock.
#define BONOBO_MOCK_PRIVATE_STATIC_STRICT(function, signature) \
    BONOBO_MOCK_INTERNAL_PRIVATE_STATIC_STRICT(#function, signature, BONOBO_MOCK_INTERNAL_UNIQUE_NUMBER)

// Equivalent to BONOBO_MOCK_PRIVATE_STATIC, but creates a nice mock.
#define BONOBO_MOCK_PRIVATE_STATIC_NICE(function, signature) \
    BONOBO_MOCK_INTERNAL_PRIVATE_STATIC_NICE(#function, signature, BONOBO_MOCK_INTERNAL_UNIQUE_NUMBER)

//===============================================================================
// Macros for mocking private member functions (non-static).
// These require a class parameter and const/non-const distinction.
//===============================================================================

// Macros for creating a mock object for a private function
#define BONOBO_MOCK_PRIVATE_NON_CONST(function, class, signature) \
    BONOBO_MOCK_INTERNAL_PRIVATE_NON_CONST(class, #function, signature, BONOBO_MOCK_INTERNAL_UNIQUE_NUMBER)
#define BONOBO_MOCK_PRIVATE_STRICT_NON_CONST(function, class, signature) \
    BONOBO_MOCK_INTERNAL_PRIVATE_STRICT_NON_CONST(class, #function, signature, BONOBO_MOCK_INTERNAL_UNIQUE_NUMBER)
#define BONOBO_MOCK_PRIVATE_NICE_NON_CONST(function, class, signature) \
    BONOBO_MOCK_INTERNAL_PRIVATE_NICE_NON_CONST(class, #function, signature, BONOBO_MOCK_INTERNAL_UNIQUE_NUMBER)

#define BONOBO_MOCK_PRIVATE_CONST(function, class, signature) \
    BONOBO_MOCK_INTERNAL_PRIVATE_CONST(class, #function, signature, BONOBO_MOCK_INTERNAL_UNIQUE_NUMBER)
#define BONOBO_MOCK_PRIVATE_STRICT_CONST(function, class, signature) \
    BONOBO_MOCK_INTERNAL_PRIVATE_STRICT_CONST(class, #function, signature, BONOBO_MOCK_INTERNAL_UNIQUE_NUMBER)
#define BONOBO_MOCK_PRIVATE_NICE_CONST(function, class, signature) \
    BONOBO_MOCK_INTERNAL_PRIVATE_NICE_CONST(class, #function, signature, BONOBO_MOCK_INTERNAL_UNIQUE_NUMBER)

//===============================================================================
// Macros for suppressing constructor side effects via link dummying.
// Constructors/destructors cannot be mocked (see the "Constructors and
// destructors" section in docs/reference/limitations.md), but these macros
// provide empty definitions that the linker uses in place of the real ones,
// preventing the real constructor/destructor bodies (and their side effects)
// from running. The real object still links, so the class's vtable and other
// methods remain intact and can be mocked with BONOBO_MOCK.
//
// Requires linking the test target with the multiple-definition linker mode;
// use the ALLOW_CONSTRUCTOR_DUMMIES option of add_bonobomock_executable(). Using a
// dummy macro without it is a compile error.
//
// Use at namespace scope. The leaf class name must be passed explicitly because
// the preprocessor cannot extract it from the qualified name. 'signature' is a
// parenthesized parameter-type list, e.g. (int).
//   BONOBO_DUMMY_CONSTRUCTOR(ns::Widget, Widget, (int))
//   BONOBO_DUMMY_DESTRUCTOR(ns::Widget, Widget)
//   BONOBO_DUMMY_CONSTRUCTOR_AND_DESTRUCTOR(ns::Widget, Widget, (int))
//
// The _WITH_INIT variants take a trailing member-initializer list, for classes
// with reference/const/non-default-constructible members that an empty body
// cannot initialize. The signature may name its parameters so they can be
// forwarded to members.
//   BONOBO_DUMMY_CONSTRUCTOR_WITH_INIT(ns::Widget, Widget, (int id), d_dep(id))
//   BONOBO_DUMMY_CONSTRUCTOR_AND_DESTRUCTOR_WITH_INIT(ns::Widget, Widget, (int id), d_dep(id))
//===============================================================================
#define BONOBO_DUMMY_CONSTRUCTOR(qualified_class, leaf_name, signature) \
    BONOBO_DUMMY_INTERNAL_CONSTRUCTOR(qualified_class, leaf_name, signature)

#define BONOBO_DUMMY_CONSTRUCTOR_WITH_INIT(qualified_class, leaf_name, signature, ...) \
    BONOBO_DUMMY_INTERNAL_CONSTRUCTOR_WITH_INIT(qualified_class, leaf_name, signature, __VA_ARGS__)

#define BONOBO_DUMMY_DESTRUCTOR(qualified_class, leaf_name) \
    BONOBO_DUMMY_INTERNAL_DESTRUCTOR(qualified_class, leaf_name)

#define BONOBO_DUMMY_CONSTRUCTOR_AND_DESTRUCTOR(qualified_class, leaf_name, signature) \
    BONOBO_DUMMY_INTERNAL_CONSTRUCTOR(qualified_class, leaf_name, signature)           \
    BONOBO_DUMMY_INTERNAL_DESTRUCTOR(qualified_class, leaf_name)

#define BONOBO_DUMMY_CONSTRUCTOR_AND_DESTRUCTOR_WITH_INIT(qualified_class, leaf_name, signature, ...) \
    BONOBO_DUMMY_INTERNAL_CONSTRUCTOR_WITH_INIT(qualified_class, leaf_name, signature, __VA_ARGS__)   \
    BONOBO_DUMMY_INTERNAL_DESTRUCTOR(qualified_class, leaf_name)

//===============================================================================
// When functions are mocked with bonobomock, a function named 'bonobomockInternalForwardFunc' is
// instantiated in the mock object with the same signature as the mocked function.
// Calls to the mocked function are redirected to this function.
// Use BONOBO_MOCK_FUNCTION as the matcher name in EXPECT_CALL macros:
//   Example: EXPECT_CALL(*mock, BONOBO_MOCK_FUNCTION(_,_)).WillRepeatedly(...);
//===============================================================================
#define BONOBO_MOCK_FUNCTION bonobomockInternalForwardFunc

using namespace BloombergLP::bonobomock;

#endif
