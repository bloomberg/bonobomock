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

#ifndef INCLUDED_BONOBOMOCK_INTERNAL_CREATOR
#define INCLUDED_BONOBOMOCK_INTERNAL_CREATOR

#if !defined(INCLUDED_BONOBOMOCK_API) && !defined(BONOBO_MOCK_BUILDING_LIBRARY)
    #error "This is a private header. Directly including it is a contract violation and undefined behavior."
#endif

#include <bonobomock_internal_mocker.h>
#include <bonobomock_internal_private_address_resolver.h>

#include <bsl_memory.h>
#include <bsl_string.h>

namespace BloombergLP {
namespace bonobomock {

    class MockCreator {
    public:
        // Create a mock for a global/free or fortran, or static function with arbitrary number of parameters
        template <int N, typename R, typename... P>
        static bsl::shared_ptr<Mock<R(P...), N> > createMock(R (*targetFunc)(P...), const bsl::string& funcName)
        {
            bsl::shared_ptr<Mock<R(P...), N> > l_mockObj = bsl::make_shared<Mock<R(P...), N> >(targetFunc, funcName);

            return l_mockObj;
        }

        // Create a mock for a global function for a variadic C function with fixed parameters (P...) and C-style variadic parameters (...)
        template <int N, typename R, typename... P>
        static bsl::shared_ptr<Mock<R(P...), N> > createMock(R (*targetFunc)(P..., ...), const bsl::string& funcName)
        {
            bsl::shared_ptr<Mock<R(P...), N> > l_mockObj = bsl::make_shared<Mock<R(P...), N> >(targetFunc, funcName);

            return l_mockObj;
        }

        // Create a mock for a NON-CONST member function with arbitrary number of parameters
        template <int N, typename R, typename C, typename... P>
        static bsl::shared_ptr<Mock<R (C::*)(P...), N> > createMock(R (C::*targetFunc)(P...), const bsl::string& funcName)
        {
            bsl::shared_ptr<Mock<R (C::*)(P...), N> > l_mockObj = bsl::make_shared<Mock<R (C::*)(P...), N> >(targetFunc, funcName);
            return l_mockObj;
        }

        // Create a mock for a CONST member function with arbitrary number of parameters
        template <int N, typename R, typename C, typename... P>
        static bsl::shared_ptr<Mock<R (C::*)(P...) const, N> > createMock(R (C::*targetFunc)(P...) const, const bsl::string& funcName)
        {
            bsl::shared_ptr<Mock<R (C::*)(P...) const, N> > l_mockObj = bsl::make_shared<Mock<R (C::*)(P...) const, N> >(targetFunc, funcName);
            return l_mockObj;
        }

        // Create a mock for a NON-CONST virtual member function with arbitrary number of parameters.
        // Will instantiate an object of class C using default (zero-arg) constructor to find the address of the virtual function.
        // If the class does not have a default constructor, use the overload that takes an instance of C as first parameter.
        template <int N, typename R, typename C, typename... P>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P...), N> > createVirtualMock(R (C::*targetFunc)(P...), const bsl::string& funcName)
        {
            bsl::shared_ptr<MockVirtual<R (C::*)(P...), N> > l_mockObj = bsl::make_shared<MockVirtual<R (C::*)(P...), N> >(targetFunc, funcName);
            return l_mockObj;
        }

        // Create a mock for a NON-CONST virtual member function with arbitrary number of parameters.
        // Will use the provided instance of class C to find the address of the virtual function.
        // Should be used when instantiation of class C is not possible using default (zero-arg) constructor.
        template <int N, typename R, typename C, typename... P>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P...), N> > createVirtualMock(C& inst, R (C::*targetFunc)(P...), const bsl::string& funcName)
        {
            bsl::shared_ptr<MockVirtual<R (C::*)(P...), N> > l_mockObj = bsl::make_shared<MockVirtual<R (C::*)(P...), N> >(inst, targetFunc, funcName);
            return l_mockObj;
        }

        // Create a mock for a CONST virtual member function with arbitrary number of parameters
        // Will instantiate an object of class C using default (zero-arg) constructor to find the address of the virtual function.
        // If the class does not have a default constructor, use the overload that takes an instance of C as first parameter.
        template <int N, typename R, typename C, typename... P>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P...) const, N> > createVirtualMock(R (C::*targetFunc)(P...) const, const bsl::string& funcName)
        {
            bsl::shared_ptr<MockVirtual<R (C::*)(P...) const, N> > l_mockObj = bsl::make_shared<MockVirtual<R (C::*)(P...) const, N> >(targetFunc, funcName);
            return l_mockObj;
        }

        // Create a mock for a CONST virtual member function with arbitrary number of parameters.
        // Will use the provided instance of class C to find the address of the virtual function.
        // Should be used when instantiation of class C is not possible using default (zero-arg) constructor.
        template <int N, typename R, typename C, typename... P>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P...) const, N> > createVirtualMock(const C& inst, R (C::*targetFunc)(P...) const, const bsl::string& funcName)
        {
            bsl::shared_ptr<MockVirtual<R (C::*)(P...) const, N> > l_mockObj = bsl::make_shared<MockVirtual<R (C::*)(P...) const, N> >(inst, targetFunc, funcName);
            return l_mockObj;
        }

        // Create a mock for a private static function with arbitrary number of parameters
        template <int N, typename R, typename... P>
        static bsl::shared_ptr<Mock<R(P...), N> > createPrivateStaticMock(R targetFunc(P...), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            bsl::shared_ptr<Mock<R(P...), N> > l_mockObj = bsl::make_shared<Mock<R(P...), N> >(funcName);
            return l_mockObj;
        }

        // Create a mock for a NON-CONST private member function with arbitrary number of parameters
        // The caller needs to use the macro appropriate to const-ness because there is no way for us to deduce it here.
        template <int N, typename C, typename R, typename... P>
        static bsl::shared_ptr<MockPrivate<R (C::*)(P...), N> > createPrivateMock(R targetFunc(P...), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            bsl::shared_ptr<MockPrivate<R (C::*)(P...), N> > l_mockObj = bsl::make_shared<MockPrivate<R (C::*)(P...), N> >(funcName);
            return l_mockObj;
        }

        // Create a mock for a CONST private member function with arbitrary number of parameters.
        // The caller needs to use the macro appropriate to const-ness because there is no way for us to deduce it here.
        template <int N, typename C, typename R, typename... P>
        static bsl::shared_ptr<MockPrivate<R (C::*)(P...) const, N> > createPrivateMockConst(R targetFunc(P...), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            bsl::shared_ptr<MockPrivate<R (C::*)(P...) const, N> > l_mockObj = bsl::make_shared<MockPrivate<R (C::*)(P...) const, N> >(funcName);
            return l_mockObj;
        }
    };

}
}

#endif
