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

#ifndef INCLUDED_BONOBOMOCK_INTERNAL_STRICT_MOCK_CREATOR
#define INCLUDED_BONOBOMOCK_INTERNAL_STRICT_MOCK_CREATOR

#if !defined(INCLUDED_BONOBOMOCK_API) && !defined(BONOBO_MOCK_BUILDING_LIBRARY)
    #error "This is a private header. Directly including it is a contract violation and undefined behavior."
#endif

#include <bonobomock_internal_creator.h>
#include <bonobomock_internal_private_address_resolver.h>
#include <gmock/gmock.h>

#include <bsl_memory.h>
#include <bsl_string.h>

namespace BloombergLP {
namespace bonobomock {

    class StrictMockCreator {
    public:
        // Create a strict mock for a global/free or fortran, or static function with arbitrary number of parameters
        template <int N, typename R, typename... P>
        static bsl::shared_ptr<Mock<R(P...), N> > createMockStrict(R (*targetFunc)(P...), const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::StrictMock<Mock<R(P...), N> > > strictMock = bsl::make_shared<testing::StrictMock<Mock<R(P...), N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<Mock<R(P...), N> >(strictMock);
        }

        // Create a strict mock for a global function for a variadic C function with fixed parameters (P...) and C-style variadic parameters (...)
        template <int N, typename R, typename... P>
        static bsl::shared_ptr<Mock<R(P...), N> > createMockStrict(R (*targetFunc)(P..., ...), const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::StrictMock<Mock<R(P...), N> > > strictMock = bsl::make_shared<testing::StrictMock<Mock<R(P...), N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<Mock<R(P...), N> >(strictMock);
        }

        // Create a strict mock for a NON-CONST member function with arbitrary number of parameters
        template <int N, typename R, typename C, typename... P>
        static bsl::shared_ptr<Mock<R (C::*)(P...), N> > createMockStrict(R (C::*targetFunc)(P...), const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::StrictMock<Mock<R (C::*)(P...), N> > > strictMock = bsl::make_shared<testing::StrictMock<Mock<R (C::*)(P...), N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<Mock<R (C::*)(P...), N> >(strictMock);
        }

        // Create a strict mock for a CONST member function with arbitrary number of parameters
        template <int N, typename R, typename C, typename... P>
        static bsl::shared_ptr<Mock<R (C::*)(P...) const, N> > createMockStrict(R (C::*targetFunc)(P...) const, const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::StrictMock<Mock<R (C::*)(P...) const, N> > > strictMock = bsl::make_shared<testing::StrictMock<Mock<R (C::*)(P...) const, N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<Mock<R (C::*)(P...) const, N> >(strictMock);
        }

        // Create a strict mock for a NON-CONST virtual member function with arbitrary number of parameters
        template <int N, typename R, typename C, typename... P>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P...), N> > createVirtualMockStrict(R (C::*targetFunc)(P...), const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::StrictMock<MockVirtual<R (C::*)(P...), N> > > l_mockObj = bsl::make_shared<testing::StrictMock<MockVirtual<R (C::*)(P...), N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<MockVirtual<R (C::*)(P...), N> >(l_mockObj);
        }

        // Create a strict mock for a NON-CONST virtual member function with arbitrary number of parameters (with instance)
        template <int N, typename R, typename C, typename... P>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P...), N> > createVirtualMockStrict(C& inst, R (C::*targetFunc)(P...), const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::StrictMock<MockVirtual<R (C::*)(P...), N> > > l_mockObj = bsl::make_shared<testing::StrictMock<MockVirtual<R (C::*)(P...), N> > >(inst, targetFunc, funcName);
            return bsl::static_pointer_cast<MockVirtual<R (C::*)(P...), N> >(l_mockObj);
        }

        // Create a strict mock for a CONST virtual member function with arbitrary number of parameters
        template <int N, typename R, typename C, typename... P>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P...) const, N> > createVirtualMockStrict(R (C::*targetFunc)(P...) const, const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::StrictMock<MockVirtual<R (C::*)(P...) const, N> > > l_mockObj = bsl::make_shared<testing::StrictMock<MockVirtual<R (C::*)(P...) const, N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<MockVirtual<R (C::*)(P...) const, N> >(l_mockObj);
        }

        // Create a strict mock for a CONST virtual member function with arbitrary number of parameters (with instance)
        template <int N, typename R, typename C, typename... P>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P...) const, N> > createVirtualMockStrict(const C& inst, R (C::*targetFunc)(P...) const, const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::StrictMock<MockVirtual<R (C::*)(P...) const, N> > > l_mockObj = bsl::make_shared<testing::StrictMock<MockVirtual<R (C::*)(P...) const, N> > >(inst, targetFunc, funcName);
            return bsl::static_pointer_cast<MockVirtual<R (C::*)(P...) const, N> >(l_mockObj);
        }

        // Create a strict mock for a private static function with arbitrary number of parameters
        template <int N, typename R, typename... P>
        static bsl::shared_ptr<Mock<R(P...), N> > createPrivateStaticMockStrict(R targetFunc(P...), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            bsl::shared_ptr<testing::StrictMock<Mock<R(P...), N> > > strictMock = bsl::make_shared<testing::StrictMock<Mock<R(P...), N> > >(funcName);
            return bsl::static_pointer_cast<Mock<R(P...), N> >(strictMock);
        }

        // Create a strict mock for a NON-CONST private member function with arbitrary number of parameters
        template <int N, typename C, typename R, typename... P>
        static bsl::shared_ptr<MockPrivate<R (C::*)(P...), N> > createPrivateMockStrict(R targetFunc(P...), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            bsl::shared_ptr<testing::StrictMock<MockPrivate<R (C::*)(P...), N> > > strictMock = bsl::make_shared<testing::StrictMock<MockPrivate<R (C::*)(P...), N> > >(funcName);
            return bsl::static_pointer_cast<MockPrivate<R (C::*)(P...), N> >(strictMock);
        }

        // Create a strict mock for a CONST private member function with arbitrary number of parameters
        template <int N, typename C, typename R, typename... P>
        static bsl::shared_ptr<MockPrivate<R (C::*)(P...) const, N> > createPrivateMockStrictConst(R targetFunc(P...), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            bsl::shared_ptr<testing::StrictMock<MockPrivate<R (C::*)(P...) const, N> > > strictMock = bsl::make_shared<testing::StrictMock<MockPrivate<R (C::*)(P...) const, N> > >(funcName);
            return bsl::static_pointer_cast<MockPrivate<R (C::*)(P...) const, N> >(strictMock);
        }
    };

} // bonobomock
} // BloombergLP

#endif
