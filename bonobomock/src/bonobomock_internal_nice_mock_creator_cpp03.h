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

#ifndef INCLUDED_BONOBOMOCK_INTERNAL_NICE_MOCK_CREATOR_CPP03
#define INCLUDED_BONOBOMOCK_INTERNAL_NICE_MOCK_CREATOR_CPP03

#if !defined(INCLUDED_BONOBOMOCK_API) && !defined(BONOBO_MOCK_BUILDING_LIBRARY)
    #error "This is a private header. Directly including it is a contract violation and undefined behavior."
#endif

#include <bonobomock_internal_mocker_cpp03.h>
#include <bonobomock_internal_private_address_resolver.h>
#include <gmock/gmock.h>

#include <bsl_memory.h>
#include <bsl_string.h>

namespace BloombergLP {
namespace bonobomock {

    class NiceMockCreator {
    public:
        // =========================================================================
        // createMockNice - Global/free/static/fortran functions
        // =========================================================================

        // Create a nice mock for a global/free or fortran, or static function with 0 parameters
        template <int N, typename R>
        static bsl::shared_ptr<Mock<R(), N> > createMockNice(R targetFunc(), const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::NiceMock<Mock<R(), N> > > niceMock = bsl::make_shared<testing::NiceMock<Mock<R(), N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<Mock<R(), N> >(niceMock);
        }

        // Create a nice mock for a global/free or fortran, or static function with 1 parameter
        template <int N, typename R, typename P1>
        static bsl::shared_ptr<Mock<R(P1), N> > createMockNice(R targetFunc(P1), const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::NiceMock<Mock<R(P1), N> > > niceMock = bsl::make_shared<testing::NiceMock<Mock<R(P1), N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<Mock<R(P1), N> >(niceMock);
        }

        // Create a nice mock for a global/free or fortran, or static function with 2 parameters
        template <int N, typename R, typename P1, typename P2>
        static bsl::shared_ptr<Mock<R(P1, P2), N> > createMockNice(R targetFunc(P1, P2), const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::NiceMock<Mock<R(P1, P2), N> > > niceMock = bsl::make_shared<testing::NiceMock<Mock<R(P1, P2), N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<Mock<R(P1, P2), N> >(niceMock);
        }

        // Create a nice mock for a global/free or fortran, or static function with 3 parameters
        template <int N, typename R, typename P1, typename P2, typename P3>
        static bsl::shared_ptr<Mock<R(P1, P2, P3), N> > createMockNice(R targetFunc(P1, P2, P3), const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::NiceMock<Mock<R(P1, P2, P3), N> > > niceMock = bsl::make_shared<testing::NiceMock<Mock<R(P1, P2, P3), N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<Mock<R(P1, P2, P3), N> >(niceMock);
        }

        // Create a nice mock for a global/free or fortran, or static function with 4 parameters
        template <int N, typename R, typename P1, typename P2, typename P3, typename P4>
        static bsl::shared_ptr<Mock<R(P1, P2, P3, P4), N> > createMockNice(R targetFunc(P1, P2, P3, P4), const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::NiceMock<Mock<R(P1, P2, P3, P4), N> > > niceMock = bsl::make_shared<testing::NiceMock<Mock<R(P1, P2, P3, P4), N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<Mock<R(P1, P2, P3, P4), N> >(niceMock);
        }

        // Create a nice mock for a global/free or fortran, or static function with 5 parameters
        template <int N, typename R, typename P1, typename P2, typename P3, typename P4, typename P5>
        static bsl::shared_ptr<Mock<R(P1, P2, P3, P4, P5), N> > createMockNice(R targetFunc(P1, P2, P3, P4, P5), const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::NiceMock<Mock<R(P1, P2, P3, P4, P5), N> > > niceMock = bsl::make_shared<testing::NiceMock<Mock<R(P1, P2, P3, P4, P5), N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<Mock<R(P1, P2, P3, P4, P5), N> >(niceMock);
        }

        // Create a nice mock for a global/free or fortran, or static function with 6 parameters
        template <int N, typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6>
        static bsl::shared_ptr<Mock<R(P1, P2, P3, P4, P5, P6), N> > createMockNice(R targetFunc(P1, P2, P3, P4, P5, P6), const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::NiceMock<Mock<R(P1, P2, P3, P4, P5, P6), N> > > niceMock = bsl::make_shared<testing::NiceMock<Mock<R(P1, P2, P3, P4, P5, P6), N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<Mock<R(P1, P2, P3, P4, P5, P6), N> >(niceMock);
        }

        // Create a nice mock for a global/free or fortran, or static function with 7 parameters
        template <int N, typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7>
        static bsl::shared_ptr<Mock<R(P1, P2, P3, P4, P5, P6, P7), N> > createMockNice(
            R targetFunc(P1, P2, P3, P4, P5, P6, P7), const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::NiceMock<Mock<R(P1, P2, P3, P4, P5, P6, P7), N> > > niceMock = bsl::make_shared<testing::NiceMock<Mock<R(P1, P2, P3, P4, P5, P6, P7), N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<Mock<R(P1, P2, P3, P4, P5, P6, P7), N> >(niceMock);
        }

        // Create a nice mock for a global/free or fortran, or static function with 8 parameters
        template <int N, typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
            typename P7, typename P8>
        static bsl::shared_ptr<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8), N> > createMockNice(
            R targetFunc(P1, P2, P3, P4, P5, P6, P7, P8), const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::NiceMock<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8), N> > > niceMock = bsl::make_shared<testing::NiceMock<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8), N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8), N> >(niceMock);
        }

        // Create a nice mock for a global/free or fortran, or static function with 9 parameters
        template <int N, typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
            typename P7, typename P8, typename P9>
        static bsl::shared_ptr<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9), N> > createMockNice(
            R targetFunc(P1, P2, P3, P4, P5, P6, P7, P8, P9), const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::NiceMock<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9), N> > > niceMock = bsl::make_shared<testing::NiceMock<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9), N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9), N> >(niceMock);
        }

        // Create a nice mock for a global/free or fortran, or static function with 10 parameters
        template <int N, typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
            typename P7, typename P8, typename P9, typename P10>
        static bsl::shared_ptr<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10), N> > createMockNice(
            R targetFunc(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10), const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::NiceMock<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10), N> > > niceMock = bsl::make_shared<testing::NiceMock<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10), N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10), N> >(niceMock);
        }

        // Create a nice mock for a global/free or fortran, or static function with 11 parameters
        template <int N, typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
            typename P7, typename P8, typename P9, typename P10, typename P11>
        static bsl::shared_ptr<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11), N> > createMockNice(
            R targetFunc(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11), const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::NiceMock<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11), N> > > niceMock = bsl::make_shared<testing::NiceMock<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11), N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11), N> >(niceMock);
        }

        // Create a nice mock for a global/free or fortran, or static function with 12 parameters
        template <int N, typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
            typename P7, typename P8, typename P9, typename P10, typename P11, typename P12>
        static bsl::shared_ptr<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12), N> > createMockNice(
            R targetFunc(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12), const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::NiceMock<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12), N> > > niceMock = bsl::make_shared<testing::NiceMock<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12), N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12), N> >(niceMock);
        }

        // Create a nice mock for a global/free or fortran, or static function with 13 parameters
        template <int N, typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
            typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13>
        static bsl::shared_ptr<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13), N> > createMockNice(
            R targetFunc(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13), const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::NiceMock<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13), N> > > niceMock = bsl::make_shared<testing::NiceMock<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13), N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13), N> >(niceMock);
        }

        // Create a nice mock for a global/free or fortran, or static function with 14 parameters
        template <int N, typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
            typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13, typename P14>
        static bsl::shared_ptr<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14), N> > createMockNice(
            R targetFunc(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14), const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::NiceMock<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14), N> > > niceMock = bsl::make_shared<testing::NiceMock<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14), N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14), N> >(niceMock);
        }

        // Create a nice mock for a global/free or fortran, or static function with 15 parameters
        template <int N, typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
            typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13, typename P14, typename P15>
        static bsl::shared_ptr<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15), N> > createMockNice(
            R targetFunc(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15), const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::NiceMock<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15), N> > > niceMock = bsl::make_shared<testing::NiceMock<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15), N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15), N> >(niceMock);
        }

        // =========================================================================
        // createMockNice - Non-const non-virtual member functions
        // =========================================================================

        // Create a nice mock for a NON-CONST member function with 0 parameters
        template <int N, typename R, typename C>
        static bsl::shared_ptr<Mock<R (C::*)(), N> > createMockNice(R (C::*targetFunc)(), const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::NiceMock<Mock<R (C::*)(), N> > > niceMock = bsl::make_shared<testing::NiceMock<Mock<R (C::*)(), N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<Mock<R (C::*)(), N> >(niceMock);
        }

        // Create a nice mock for a NON-CONST member function with 1 parameter
        template <int N, typename R, typename C, typename P1>
        static bsl::shared_ptr<Mock<R (C::*)(P1), N> > createMockNice(R (C::*targetFunc)(P1), const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::NiceMock<Mock<R (C::*)(P1), N> > > niceMock = bsl::make_shared<testing::NiceMock<Mock<R (C::*)(P1), N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<Mock<R (C::*)(P1), N> >(niceMock);
        }

        // Create a nice mock for a NON-CONST member function with 2 parameters
        template <int N, typename R, typename C, typename P1, typename P2>
        static bsl::shared_ptr<Mock<R (C::*)(P1, P2), N> > createMockNice(R (C::*targetFunc)(P1, P2), const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::NiceMock<Mock<R (C::*)(P1, P2), N> > > niceMock = bsl::make_shared<testing::NiceMock<Mock<R (C::*)(P1, P2), N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<Mock<R (C::*)(P1, P2), N> >(niceMock);
        }

        // Create a nice mock for a NON-CONST member function with 3 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3>
        static bsl::shared_ptr<Mock<R (C::*)(P1, P2, P3), N> > createMockNice(
            R (C::*targetFunc)(P1, P2, P3), const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::NiceMock<Mock<R (C::*)(P1, P2, P3), N> > > niceMock = bsl::make_shared<testing::NiceMock<Mock<R (C::*)(P1, P2, P3), N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<Mock<R (C::*)(P1, P2, P3), N> >(niceMock);
        }

        // Create a nice mock for a NON-CONST member function with 4 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4>
        static bsl::shared_ptr<Mock<R (C::*)(P1, P2, P3, P4), N> > createMockNice(
            R (C::*targetFunc)(P1, P2, P3, P4), const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::NiceMock<Mock<R (C::*)(P1, P2, P3, P4), N> > > niceMock = bsl::make_shared<testing::NiceMock<Mock<R (C::*)(P1, P2, P3, P4), N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<Mock<R (C::*)(P1, P2, P3, P4), N> >(niceMock);
        }

        // Create a nice mock for a NON-CONST member function with 5 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5>
        static bsl::shared_ptr<Mock<R (C::*)(P1, P2, P3, P4, P5), N> > createMockNice(
            R (C::*targetFunc)(P1, P2, P3, P4, P5), const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::NiceMock<Mock<R (C::*)(P1, P2, P3, P4, P5), N> > > niceMock = bsl::make_shared<testing::NiceMock<Mock<R (C::*)(P1, P2, P3, P4, P5), N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<Mock<R (C::*)(P1, P2, P3, P4, P5), N> >(niceMock);
        }

        // Create a nice mock for a NON-CONST member function with 6 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6>
        static bsl::shared_ptr<Mock<R (C::*)(P1, P2, P3, P4, P5, P6), N> > createMockNice(
            R (C::*targetFunc)(P1, P2, P3, P4, P5, P6), const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::NiceMock<Mock<R (C::*)(P1, P2, P3, P4, P5, P6), N> > > niceMock = bsl::make_shared<testing::NiceMock<Mock<R (C::*)(P1, P2, P3, P4, P5, P6), N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<Mock<R (C::*)(P1, P2, P3, P4, P5, P6), N> >(niceMock);
        }

        // Create a nice mock for a NON-CONST member function with 7 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7>
        static bsl::shared_ptr<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7), N> > createMockNice(
            R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7), const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::NiceMock<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7), N> > > niceMock = bsl::make_shared<testing::NiceMock<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7), N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7), N> >(niceMock);
        }

        // Create a nice mock for a NON-CONST member function with 8 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
            typename P7, typename P8>
        static bsl::shared_ptr<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8), N> > createMockNice(
            R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8), const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::NiceMock<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8), N> > > niceMock = bsl::make_shared<testing::NiceMock<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8), N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8), N> >(niceMock);
        }

        // Create a nice mock for a NON-CONST member function with 9 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
            typename P7, typename P8, typename P9>
        static bsl::shared_ptr<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9), N> > createMockNice(
            R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9), const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::NiceMock<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9), N> > > niceMock = bsl::make_shared<testing::NiceMock<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9), N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9), N> >(niceMock);
        }

        // Create a nice mock for a NON-CONST member function with 10 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
            typename P7, typename P8, typename P9, typename P10>
        static bsl::shared_ptr<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10), N> > createMockNice(
            R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10), const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::NiceMock<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10), N> > > niceMock = bsl::make_shared<testing::NiceMock<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10), N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10), N> >(niceMock);
        }

        // Create a nice mock for a NON-CONST member function with 11 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
            typename P7, typename P8, typename P9, typename P10, typename P11>
        static bsl::shared_ptr<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11), N> > createMockNice(
            R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11), const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::NiceMock<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11), N> > > niceMock = bsl::make_shared<testing::NiceMock<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11), N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11), N> >(niceMock);
        }

        // Create a nice mock for a NON-CONST member function with 12 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
            typename P7, typename P8, typename P9, typename P10, typename P11, typename P12>
        static bsl::shared_ptr<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12), N> > createMockNice(
            R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12), const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::NiceMock<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12), N> > > niceMock = bsl::make_shared<testing::NiceMock<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12), N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12), N> >(niceMock);
        }

        // Create a nice mock for a NON-CONST member function with 13 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
            typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13>
        static bsl::shared_ptr<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13), N> > createMockNice(
            R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13), const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::NiceMock<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13), N> > > niceMock = bsl::make_shared<testing::NiceMock<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13), N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13), N> >(niceMock);
        }

        // Create a nice mock for a NON-CONST member function with 14 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
            typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13, typename P14>
        static bsl::shared_ptr<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14), N> > createMockNice(
            R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14), const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::NiceMock<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14), N> > > niceMock = bsl::make_shared<testing::NiceMock<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14), N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14), N> >(niceMock);
        }

        // Create a nice mock for a NON-CONST member function with 15 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
            typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13, typename P14, typename P15>
        static bsl::shared_ptr<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15), N> > createMockNice(
            R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15), const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::NiceMock<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15), N> > > niceMock = bsl::make_shared<testing::NiceMock<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15), N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15), N> >(niceMock);
        }

        // =========================================================================
        // createMockNice - Const non-virtual member functions
        // =========================================================================

        // Create a nice mock for a CONST member function with 0 parameters
        template <int N, typename R, typename C>
        static bsl::shared_ptr<Mock<R (C::*)() const, N> > createMockNice(R (C::*targetFunc)() const, const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::NiceMock<Mock<R (C::*)() const, N> > > niceMock = bsl::make_shared<testing::NiceMock<Mock<R (C::*)() const, N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<Mock<R (C::*)() const, N> >(niceMock);
        }

        // Create a nice mock for a CONST member function with 1 parameter
        template <int N, typename R, typename C, typename P1>
        static bsl::shared_ptr<Mock<R (C::*)(P1) const, N> > createMockNice(R (C::*targetFunc)(P1) const, const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::NiceMock<Mock<R (C::*)(P1) const, N> > > niceMock = bsl::make_shared<testing::NiceMock<Mock<R (C::*)(P1) const, N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<Mock<R (C::*)(P1) const, N> >(niceMock);
        }

        // Create a nice mock for a CONST member function with 2 parameters
        template <int N, typename R, typename C, typename P1, typename P2>
        static bsl::shared_ptr<Mock<R (C::*)(P1, P2) const, N> > createMockNice(R (C::*targetFunc)(P1, P2) const, const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::NiceMock<Mock<R (C::*)(P1, P2) const, N> > > niceMock = bsl::make_shared<testing::NiceMock<Mock<R (C::*)(P1, P2) const, N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<Mock<R (C::*)(P1, P2) const, N> >(niceMock);
        }

        // Create a nice mock for a CONST member function with 3 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3>
        static bsl::shared_ptr<Mock<R (C::*)(P1, P2, P3) const, N> > createMockNice(R (C::*targetFunc)(P1, P2, P3) const, const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::NiceMock<Mock<R (C::*)(P1, P2, P3) const, N> > > niceMock = bsl::make_shared<testing::NiceMock<Mock<R (C::*)(P1, P2, P3) const, N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<Mock<R (C::*)(P1, P2, P3) const, N> >(niceMock);
        }

        // Create a nice mock for a CONST member function with 4 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4>
        static bsl::shared_ptr<Mock<R (C::*)(P1, P2, P3, P4) const, N> > createMockNice(R (C::*targetFunc)(P1, P2, P3, P4) const, const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::NiceMock<Mock<R (C::*)(P1, P2, P3, P4) const, N> > > niceMock = bsl::make_shared<testing::NiceMock<Mock<R (C::*)(P1, P2, P3, P4) const, N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<Mock<R (C::*)(P1, P2, P3, P4) const, N> >(niceMock);
        }

        // Create a nice mock for a CONST member function with 5 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5>
        static bsl::shared_ptr<Mock<R (C::*)(P1, P2, P3, P4, P5) const, N> > createMockNice(R (C::*targetFunc)(P1, P2, P3, P4, P5) const, const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::NiceMock<Mock<R (C::*)(P1, P2, P3, P4, P5) const, N> > > niceMock = bsl::make_shared<testing::NiceMock<Mock<R (C::*)(P1, P2, P3, P4, P5) const, N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<Mock<R (C::*)(P1, P2, P3, P4, P5) const, N> >(niceMock);
        }

        // Create a nice mock for a CONST member function with 6 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6>
        static bsl::shared_ptr<Mock<R (C::*)(P1, P2, P3, P4, P5, P6) const, N> > createMockNice(R (C::*targetFunc)(P1, P2, P3, P4, P5, P6) const, const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::NiceMock<Mock<R (C::*)(P1, P2, P3, P4, P5, P6) const, N> > > niceMock = bsl::make_shared<testing::NiceMock<Mock<R (C::*)(P1, P2, P3, P4, P5, P6) const, N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<Mock<R (C::*)(P1, P2, P3, P4, P5, P6) const, N> >(niceMock);
        }

        // Create a nice mock for a CONST member function with 7 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7>
        static bsl::shared_ptr<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7) const, N> > createMockNice(R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7) const, const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::NiceMock<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7) const, N> > > niceMock = bsl::make_shared<testing::NiceMock<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7) const, N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7) const, N> >(niceMock);
        }

        // Create a nice mock for a CONST member function with 8 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8>
        static bsl::shared_ptr<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8) const, N> > createMockNice(R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8) const, const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::NiceMock<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8) const, N> > > niceMock = bsl::make_shared<testing::NiceMock<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8) const, N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8) const, N> >(niceMock);
        }

        // Create a nice mock for a CONST member function with 9 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8,
            typename P9>
        static bsl::shared_ptr<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9) const, N> > createMockNice(R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9) const, const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::NiceMock<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9) const, N> > > niceMock = bsl::make_shared<testing::NiceMock<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9) const, N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9) const, N> >(niceMock);
        }

        // Create a nice mock for a CONST member function with 10 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8,
            typename P9, typename P10>
        static bsl::shared_ptr<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10) const, N> > createMockNice(R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10) const, const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::NiceMock<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10) const, N> > > niceMock = bsl::make_shared<testing::NiceMock<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10) const, N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10) const, N> >(niceMock);
        }

        // Create a nice mock for a CONST member function with 11 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8,
            typename P9, typename P10, typename P11>
        static bsl::shared_ptr<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11) const, N> > createMockNice(R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11) const, const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::NiceMock<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11) const, N> > > niceMock = bsl::make_shared<testing::NiceMock<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11) const, N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11) const, N> >(niceMock);
        }

        // Create a nice mock for a CONST member function with 12 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8,
            typename P9, typename P10, typename P11, typename P12>
        static bsl::shared_ptr<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12) const, N> > createMockNice(R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12) const, const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::NiceMock<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12) const, N> > > niceMock = bsl::make_shared<testing::NiceMock<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12) const, N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12) const, N> >(niceMock);
        }

        // Create a nice mock for a CONST member function with 13 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8,
            typename P9, typename P10, typename P11, typename P12, typename P13>
        static bsl::shared_ptr<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13) const, N> > createMockNice(R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13) const, const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::NiceMock<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13) const, N> > > niceMock = bsl::make_shared<testing::NiceMock<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13) const, N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13) const, N> >(niceMock);
        }

        // Create a nice mock for a CONST member function with 14 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8,
            typename P9, typename P10, typename P11, typename P12, typename P13, typename P14>
        static bsl::shared_ptr<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14) const, N> > createMockNice(R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14) const, const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::NiceMock<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14) const, N> > > niceMock = bsl::make_shared<testing::NiceMock<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14) const, N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14) const, N> >(niceMock);
        }

        // Create a nice mock for a CONST member function with 15 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8,
            typename P9, typename P10, typename P11, typename P12, typename P13, typename P14, typename P15>
        static bsl::shared_ptr<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15) const, N> > createMockNice(R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15) const, const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::NiceMock<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15) const, N> > > niceMock = bsl::make_shared<testing::NiceMock<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15) const, N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15) const, N> >(niceMock);
        }

        // =========================================================================
        // createVirtualMockNice - Non-const virtual member functions
        // =========================================================================

        // Create a nice mock for a NON-CONST virtual member function with 0 parameters
        template <int N, typename R, typename C>
        static bsl::shared_ptr<MockVirtual<R (C::*)(), N> > createVirtualMockNice(
            R (C::*targetFunc)(), const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::NiceMock<MockVirtual<R (C::*)(), N> > > l_mockObj = bsl::make_shared<testing::NiceMock<MockVirtual<R (C::*)(), N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<MockVirtual<R (C::*)(), N> >(l_mockObj);
        }

        // Create a nice mock for a NON-CONST virtual member function with 1 parameter
        template <int N, typename R, typename C, typename P1>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1), N> > createVirtualMockNice(
            R (C::*targetFunc)(P1), const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::NiceMock<MockVirtual<R (C::*)(P1), N> > > l_mockObj = bsl::make_shared<testing::NiceMock<MockVirtual<R (C::*)(P1), N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<MockVirtual<R (C::*)(P1), N> >(l_mockObj);
        }

        // Create a nice mock for a NON-CONST virtual member function with 2 parameters
        template <int N, typename R, typename C, typename P1, typename P2>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2), N> > createVirtualMockNice(
            R (C::*targetFunc)(P1, P2), const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::NiceMock<MockVirtual<R (C::*)(P1, P2), N> > > l_mockObj = bsl::make_shared<testing::NiceMock<MockVirtual<R (C::*)(P1, P2), N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<MockVirtual<R (C::*)(P1, P2), N> >(l_mockObj);
        }

        // Create a nice mock for a NON-CONST virtual member function with 3 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3), N> > createVirtualMockNice(
            R (C::*targetFunc)(P1, P2, P3), const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::NiceMock<MockVirtual<R (C::*)(P1, P2, P3), N> > > l_mockObj = bsl::make_shared<testing::NiceMock<MockVirtual<R (C::*)(P1, P2, P3), N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<MockVirtual<R (C::*)(P1, P2, P3), N> >(l_mockObj);
        }

        // Create a nice mock for a NON-CONST virtual member function with 4 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4), N> > createVirtualMockNice(
            R (C::*targetFunc)(P1, P2, P3, P4), const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::NiceMock<MockVirtual<R (C::*)(P1, P2, P3, P4), N> > > l_mockObj = bsl::make_shared<testing::NiceMock<MockVirtual<R (C::*)(P1, P2, P3, P4), N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<MockVirtual<R (C::*)(P1, P2, P3, P4), N> >(l_mockObj);
        }

        // Create a nice mock for a NON-CONST virtual member function with 5 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5), N> > createVirtualMockNice(
            R (C::*targetFunc)(P1, P2, P3, P4, P5), const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::NiceMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5), N> > > l_mockObj = bsl::make_shared<testing::NiceMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5), N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<MockVirtual<R (C::*)(P1, P2, P3, P4, P5), N> >(l_mockObj);
        }

        // Create a nice mock for a NON-CONST virtual member function with 6 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6), N> > createVirtualMockNice(
            R (C::*targetFunc)(P1, P2, P3, P4, P5, P6), const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::NiceMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6), N> > > l_mockObj = bsl::make_shared<testing::NiceMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6), N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6), N> >(l_mockObj);
        }

        // Create a nice mock for a NON-CONST virtual member function with 7 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7), N> > createVirtualMockNice(
            R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7), const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::NiceMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7), N> > > l_mockObj = bsl::make_shared<testing::NiceMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7), N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7), N> >(l_mockObj);
        }

        // Create a nice mock for a NON-CONST virtual member function with 8 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8), N> > createVirtualMockNice(
            R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8), const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::NiceMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8), N> > > l_mockObj = bsl::make_shared<testing::NiceMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8), N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8), N> >(l_mockObj);
        }

        // Create a nice mock for a NON-CONST virtual member function with 9 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9), N> > createVirtualMockNice(
            R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9), const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::NiceMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9), N> > > l_mockObj = bsl::make_shared<testing::NiceMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9), N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9), N> >(l_mockObj);
        }

        // Create a nice mock for a NON-CONST virtual member function with 10 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9, typename P10>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10), N> > createVirtualMockNice(
            R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10), const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::NiceMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10), N> > > l_mockObj = bsl::make_shared<testing::NiceMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10), N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10), N> >(l_mockObj);
        }

        // Create a nice mock for a NON-CONST virtual member function with 11 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9, typename P10, typename P11>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11), N> > createVirtualMockNice(
            R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11), const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::NiceMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11), N> > > l_mockObj = bsl::make_shared<testing::NiceMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11), N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11), N> >(l_mockObj);
        }

        // Create a nice mock for a NON-CONST virtual member function with 12 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9, typename P10, typename P11, typename P12>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12), N> > createVirtualMockNice(
            R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12), const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::NiceMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12), N> > > l_mockObj = bsl::make_shared<testing::NiceMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12), N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12), N> >(l_mockObj);
        }

        // Create a nice mock for a NON-CONST virtual member function with 13 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13), N> > createVirtualMockNice(
            R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13), const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::NiceMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13), N> > > l_mockObj = bsl::make_shared<testing::NiceMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13), N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13), N> >(l_mockObj);
        }

        // Create a nice mock for a NON-CONST virtual member function with 14 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13, typename P14>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14), N> > createVirtualMockNice(
            R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14), const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::NiceMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14), N> > > l_mockObj = bsl::make_shared<testing::NiceMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14), N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14), N> >(l_mockObj);
        }

        // Create a nice mock for a NON-CONST virtual member function with 15 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13, typename P14, typename P15>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15), N> > createVirtualMockNice(
            R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15), const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::NiceMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15), N> > > l_mockObj = bsl::make_shared<testing::NiceMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15), N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15), N> >(l_mockObj);
        }

        // =========================================================================
        // createVirtualMockNice - Const virtual member functions
        // =========================================================================

        // Create a nice mock for a CONST virtual member function with 0 parameters
        template <int N, typename R, typename C>
        static bsl::shared_ptr<MockVirtual<R (C::*)() const, N> > createVirtualMockNice(
            R (C::*targetFunc)() const, const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::NiceMock<MockVirtual<R (C::*)() const, N> > > l_mockObj = bsl::make_shared<testing::NiceMock<MockVirtual<R (C::*)() const, N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<MockVirtual<R (C::*)() const, N> >(l_mockObj);
        }

        // Create a nice mock for a CONST virtual member function with 1 parameter
        template <int N, typename R, typename C, typename P1>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1) const, N> > createVirtualMockNice(
            R (C::*targetFunc)(P1) const, const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::NiceMock<MockVirtual<R (C::*)(P1) const, N> > > l_mockObj = bsl::make_shared<testing::NiceMock<MockVirtual<R (C::*)(P1) const, N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<MockVirtual<R (C::*)(P1) const, N> >(l_mockObj);
        }

        // Create a nice mock for a CONST virtual member function with 2 parameters
        template <int N, typename R, typename C, typename P1, typename P2>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2) const, N> > createVirtualMockNice(
            R (C::*targetFunc)(P1, P2) const, const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::NiceMock<MockVirtual<R (C::*)(P1, P2) const, N> > > l_mockObj = bsl::make_shared<testing::NiceMock<MockVirtual<R (C::*)(P1, P2) const, N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<MockVirtual<R (C::*)(P1, P2) const, N> >(l_mockObj);
        }

        // Create a nice mock for a CONST virtual member function with 3 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3) const, N> > createVirtualMockNice(
            R (C::*targetFunc)(P1, P2, P3) const, const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::NiceMock<MockVirtual<R (C::*)(P1, P2, P3) const, N> > > l_mockObj = bsl::make_shared<testing::NiceMock<MockVirtual<R (C::*)(P1, P2, P3) const, N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<MockVirtual<R (C::*)(P1, P2, P3) const, N> >(l_mockObj);
        }

        // Create a nice mock for a CONST virtual member function with 4 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4) const, N> > createVirtualMockNice(
            R (C::*targetFunc)(P1, P2, P3, P4) const, const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::NiceMock<MockVirtual<R (C::*)(P1, P2, P3, P4) const, N> > > l_mockObj = bsl::make_shared<testing::NiceMock<MockVirtual<R (C::*)(P1, P2, P3, P4) const, N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<MockVirtual<R (C::*)(P1, P2, P3, P4) const, N> >(l_mockObj);
        }

        // Create a nice mock for a CONST virtual member function with 5 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5) const, N> > createVirtualMockNice(
            R (C::*targetFunc)(P1, P2, P3, P4, P5) const, const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::NiceMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5) const, N> > > l_mockObj = bsl::make_shared<testing::NiceMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5) const, N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<MockVirtual<R (C::*)(P1, P2, P3, P4, P5) const, N> >(l_mockObj);
        }

        // Create a nice mock for a CONST virtual member function with 6 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6) const, N> > createVirtualMockNice(
            R (C::*targetFunc)(P1, P2, P3, P4, P5, P6) const, const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::NiceMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6) const, N> > > l_mockObj = bsl::make_shared<testing::NiceMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6) const, N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6) const, N> >(l_mockObj);
        }

        // Create a nice mock for a CONST virtual member function with 7 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7) const, N> > createVirtualMockNice(
            R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7) const, const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::NiceMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7) const, N> > > l_mockObj = bsl::make_shared<testing::NiceMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7) const, N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7) const, N> >(l_mockObj);
        }

        // Create a nice mock for a CONST virtual member function with 8 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8) const, N> > createVirtualMockNice(
            R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8) const, const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::NiceMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8) const, N> > > l_mockObj = bsl::make_shared<testing::NiceMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8) const, N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8) const, N> >(l_mockObj);
        }

        // Create a nice mock for a CONST virtual member function with 9 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9) const, N> > createVirtualMockNice(
            R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9) const, const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::NiceMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9) const, N> > > l_mockObj = bsl::make_shared<testing::NiceMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9) const, N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9) const, N> >(l_mockObj);
        }

        // Create a nice mock for a CONST virtual member function with 10 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9, typename P10>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10) const, N> > createVirtualMockNice(
            R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10) const, const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::NiceMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10) const, N> > > l_mockObj = bsl::make_shared<testing::NiceMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10) const, N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10) const, N> >(l_mockObj);
        }

        // Create a nice mock for a CONST virtual member function with 11 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9, typename P10, typename P11>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11) const, N> > createVirtualMockNice(
            R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11) const, const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::NiceMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11) const, N> > > l_mockObj = bsl::make_shared<testing::NiceMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11) const, N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11) const, N> >(l_mockObj);
        }

        // Create a nice mock for a CONST virtual member function with 12 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9, typename P10, typename P11, typename P12>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12) const, N> > createVirtualMockNice(
            R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12) const, const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::NiceMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12) const, N> > > l_mockObj = bsl::make_shared<testing::NiceMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12) const, N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12) const, N> >(l_mockObj);
        }

        // Create a nice mock for a CONST virtual member function with 13 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13) const, N> > createVirtualMockNice(
            R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13) const, const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::NiceMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13) const, N> > > l_mockObj = bsl::make_shared<testing::NiceMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13) const, N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13) const, N> >(l_mockObj);
        }

        // Create a nice mock for a CONST virtual member function with 14 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13, typename P14>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14) const, N> > createVirtualMockNice(
            R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14) const, const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::NiceMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14) const, N> > > l_mockObj = bsl::make_shared<testing::NiceMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14) const, N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14) const, N> >(l_mockObj);
        }

        // Create a nice mock for a CONST virtual member function with 15 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13, typename P14, typename P15>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15) const, N> > createVirtualMockNice(
            R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15) const, const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::NiceMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15) const, N> > > l_mockObj = bsl::make_shared<testing::NiceMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15) const, N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15) const, N> >(l_mockObj);
        }

        // =========================================================================
        // PMF-accepting with instance overloads (BONOBO_MOCK_VIRTUAL_ON)
        // =========================================================================

        // Create a nice mock with instance for a NON-CONST virtual member function with 0 parameters
        template <int N, typename R, typename C>
        static bsl::shared_ptr<MockVirtual<R (C::*)(), N> > createVirtualMockNice(
            const C& inst, R (C::*targetFunc)(), const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::NiceMock<MockVirtual<R (C::*)(), N> > > l_mockObj = bsl::make_shared<testing::NiceMock<MockVirtual<R (C::*)(), N> > >(inst, targetFunc, funcName);
            return bsl::static_pointer_cast<MockVirtual<R (C::*)(), N> >(l_mockObj);
        }

        // Create a nice mock with instance for a NON-CONST virtual member function with 1 parameter
        template <int N, typename R, typename C, typename P1>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1), N> > createVirtualMockNice(
            const C& inst, R (C::*targetFunc)(P1), const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::NiceMock<MockVirtual<R (C::*)(P1), N> > > l_mockObj = bsl::make_shared<testing::NiceMock<MockVirtual<R (C::*)(P1), N> > >(inst, targetFunc, funcName);
            return bsl::static_pointer_cast<MockVirtual<R (C::*)(P1), N> >(l_mockObj);
        }

        // Create a nice mock with instance for a NON-CONST virtual member function with 2 parameters
        template <int N, typename R, typename C, typename P1, typename P2>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2), N> > createVirtualMockNice(
            const C& inst, R (C::*targetFunc)(P1, P2), const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::NiceMock<MockVirtual<R (C::*)(P1, P2), N> > > l_mockObj = bsl::make_shared<testing::NiceMock<MockVirtual<R (C::*)(P1, P2), N> > >(inst, targetFunc, funcName);
            return bsl::static_pointer_cast<MockVirtual<R (C::*)(P1, P2), N> >(l_mockObj);
        }

        // Create a nice mock with instance for a NON-CONST virtual member function with 3 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3), N> > createVirtualMockNice(
            const C& inst, R (C::*targetFunc)(P1, P2, P3), const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::NiceMock<MockVirtual<R (C::*)(P1, P2, P3), N> > > l_mockObj = bsl::make_shared<testing::NiceMock<MockVirtual<R (C::*)(P1, P2, P3), N> > >(inst, targetFunc, funcName);
            return bsl::static_pointer_cast<MockVirtual<R (C::*)(P1, P2, P3), N> >(l_mockObj);
        }

        // Create a nice mock with instance for a NON-CONST virtual member function with 4 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4), N> > createVirtualMockNice(
            const C& inst, R (C::*targetFunc)(P1, P2, P3, P4), const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::NiceMock<MockVirtual<R (C::*)(P1, P2, P3, P4), N> > > l_mockObj = bsl::make_shared<testing::NiceMock<MockVirtual<R (C::*)(P1, P2, P3, P4), N> > >(inst, targetFunc, funcName);
            return bsl::static_pointer_cast<MockVirtual<R (C::*)(P1, P2, P3, P4), N> >(l_mockObj);
        }

        // Create a nice mock with instance for a NON-CONST virtual member function with 5 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5), N> > createVirtualMockNice(
            const C& inst, R (C::*targetFunc)(P1, P2, P3, P4, P5), const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::NiceMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5), N> > > l_mockObj = bsl::make_shared<testing::NiceMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5), N> > >(inst, targetFunc, funcName);
            return bsl::static_pointer_cast<MockVirtual<R (C::*)(P1, P2, P3, P4, P5), N> >(l_mockObj);
        }

        // Create a nice mock with instance for a NON-CONST virtual member function with 6 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6), N> > createVirtualMockNice(
            const C& inst, R (C::*targetFunc)(P1, P2, P3, P4, P5, P6), const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::NiceMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6), N> > > l_mockObj = bsl::make_shared<testing::NiceMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6), N> > >(inst, targetFunc, funcName);
            return bsl::static_pointer_cast<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6), N> >(l_mockObj);
        }

        // Create a nice mock with instance for a NON-CONST virtual member function with 7 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7), N> > createVirtualMockNice(
            const C& inst, R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7), const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::NiceMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7), N> > > l_mockObj = bsl::make_shared<testing::NiceMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7), N> > >(inst, targetFunc, funcName);
            return bsl::static_pointer_cast<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7), N> >(l_mockObj);
        }

        // Create a nice mock with instance for a NON-CONST virtual member function with 8 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8), N> > createVirtualMockNice(
            const C& inst, R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8), const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::NiceMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8), N> > > l_mockObj = bsl::make_shared<testing::NiceMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8), N> > >(inst, targetFunc, funcName);
            return bsl::static_pointer_cast<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8), N> >(l_mockObj);
        }

        // Create a nice mock with instance for a NON-CONST virtual member function with 9 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9), N> > createVirtualMockNice(
            const C& inst, R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9), const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::NiceMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9), N> > > l_mockObj = bsl::make_shared<testing::NiceMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9), N> > >(inst, targetFunc, funcName);
            return bsl::static_pointer_cast<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9), N> >(l_mockObj);
        }

        // Create a nice mock with instance for a NON-CONST virtual member function with 10 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9, typename P10>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10), N> > createVirtualMockNice(
            const C& inst, R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10), const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::NiceMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10), N> > > l_mockObj = bsl::make_shared<testing::NiceMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10), N> > >(inst, targetFunc, funcName);
            return bsl::static_pointer_cast<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10), N> >(l_mockObj);
        }

        // Create a nice mock with instance for a NON-CONST virtual member function with 11 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9, typename P10, typename P11>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11), N> > createVirtualMockNice(
            const C& inst, R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11), const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::NiceMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11), N> > > l_mockObj = bsl::make_shared<testing::NiceMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11), N> > >(inst, targetFunc, funcName);
            return bsl::static_pointer_cast<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11), N> >(l_mockObj);
        }

        // Create a nice mock with instance for a NON-CONST virtual member function with 12 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9, typename P10, typename P11, typename P12>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12), N> > createVirtualMockNice(
            const C& inst, R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12), const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::NiceMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12), N> > > l_mockObj = bsl::make_shared<testing::NiceMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12), N> > >(inst, targetFunc, funcName);
            return bsl::static_pointer_cast<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12), N> >(l_mockObj);
        }

        // Create a nice mock with instance for a NON-CONST virtual member function with 13 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13), N> > createVirtualMockNice(
            const C& inst, R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13), const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::NiceMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13), N> > > l_mockObj = bsl::make_shared<testing::NiceMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13), N> > >(inst, targetFunc, funcName);
            return bsl::static_pointer_cast<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13), N> >(l_mockObj);
        }

        // Create a nice mock with instance for a NON-CONST virtual member function with 14 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13, typename P14>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14), N> > createVirtualMockNice(
            const C& inst, R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14), const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::NiceMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14), N> > > l_mockObj = bsl::make_shared<testing::NiceMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14), N> > >(inst, targetFunc, funcName);
            return bsl::static_pointer_cast<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14), N> >(l_mockObj);
        }

        // Create a nice mock with instance for a NON-CONST virtual member function with 15 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13, typename P14, typename P15>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15), N> > createVirtualMockNice(
            const C& inst, R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15), const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::NiceMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15), N> > > l_mockObj = bsl::make_shared<testing::NiceMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15), N> > >(inst, targetFunc, funcName);
            return bsl::static_pointer_cast<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15), N> >(l_mockObj);
        }

        // Create a nice mock with instance for a CONST virtual member function with 0 parameters
        template <int N, typename R, typename C>
        static bsl::shared_ptr<MockVirtual<R (C::*)() const, N> > createVirtualMockNice(
            const C& inst, R (C::*targetFunc)() const, const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::NiceMock<MockVirtual<R (C::*)() const, N> > > l_mockObj = bsl::make_shared<testing::NiceMock<MockVirtual<R (C::*)() const, N> > >(inst, targetFunc, funcName);
            return bsl::static_pointer_cast<MockVirtual<R (C::*)() const, N> >(l_mockObj);
        }

        // Create a nice mock with instance for a CONST virtual member function with 1 parameter
        template <int N, typename R, typename C, typename P1>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1) const, N> > createVirtualMockNice(
            const C& inst, R (C::*targetFunc)(P1) const, const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::NiceMock<MockVirtual<R (C::*)(P1) const, N> > > l_mockObj = bsl::make_shared<testing::NiceMock<MockVirtual<R (C::*)(P1) const, N> > >(inst, targetFunc, funcName);
            return bsl::static_pointer_cast<MockVirtual<R (C::*)(P1) const, N> >(l_mockObj);
        }

        // Create a nice mock with instance for a CONST virtual member function with 2 parameters
        template <int N, typename R, typename C, typename P1, typename P2>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2) const, N> > createVirtualMockNice(
            const C& inst, R (C::*targetFunc)(P1, P2) const, const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::NiceMock<MockVirtual<R (C::*)(P1, P2) const, N> > > l_mockObj = bsl::make_shared<testing::NiceMock<MockVirtual<R (C::*)(P1, P2) const, N> > >(inst, targetFunc, funcName);
            return bsl::static_pointer_cast<MockVirtual<R (C::*)(P1, P2) const, N> >(l_mockObj);
        }

        // Create a nice mock with instance for a CONST virtual member function with 3 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3) const, N> > createVirtualMockNice(
            const C& inst, R (C::*targetFunc)(P1, P2, P3) const, const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::NiceMock<MockVirtual<R (C::*)(P1, P2, P3) const, N> > > l_mockObj = bsl::make_shared<testing::NiceMock<MockVirtual<R (C::*)(P1, P2, P3) const, N> > >(inst, targetFunc, funcName);
            return bsl::static_pointer_cast<MockVirtual<R (C::*)(P1, P2, P3) const, N> >(l_mockObj);
        }

        // Create a nice mock with instance for a CONST virtual member function with 4 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4) const, N> > createVirtualMockNice(
            const C& inst, R (C::*targetFunc)(P1, P2, P3, P4) const, const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::NiceMock<MockVirtual<R (C::*)(P1, P2, P3, P4) const, N> > > l_mockObj = bsl::make_shared<testing::NiceMock<MockVirtual<R (C::*)(P1, P2, P3, P4) const, N> > >(inst, targetFunc, funcName);
            return bsl::static_pointer_cast<MockVirtual<R (C::*)(P1, P2, P3, P4) const, N> >(l_mockObj);
        }

        // Create a nice mock with instance for a CONST virtual member function with 5 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5) const, N> > createVirtualMockNice(
            const C& inst, R (C::*targetFunc)(P1, P2, P3, P4, P5) const, const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::NiceMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5) const, N> > > l_mockObj = bsl::make_shared<testing::NiceMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5) const, N> > >(inst, targetFunc, funcName);
            return bsl::static_pointer_cast<MockVirtual<R (C::*)(P1, P2, P3, P4, P5) const, N> >(l_mockObj);
        }

        // Create a nice mock with instance for a CONST virtual member function with 6 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6) const, N> > createVirtualMockNice(
            const C& inst, R (C::*targetFunc)(P1, P2, P3, P4, P5, P6) const, const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::NiceMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6) const, N> > > l_mockObj = bsl::make_shared<testing::NiceMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6) const, N> > >(inst, targetFunc, funcName);
            return bsl::static_pointer_cast<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6) const, N> >(l_mockObj);
        }

        // Create a nice mock with instance for a CONST virtual member function with 7 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7) const, N> > createVirtualMockNice(
            const C& inst, R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7) const, const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::NiceMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7) const, N> > > l_mockObj = bsl::make_shared<testing::NiceMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7) const, N> > >(inst, targetFunc, funcName);
            return bsl::static_pointer_cast<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7) const, N> >(l_mockObj);
        }

        // Create a nice mock with instance for a CONST virtual member function with 8 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8) const, N> > createVirtualMockNice(
            const C& inst, R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8) const, const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::NiceMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8) const, N> > > l_mockObj = bsl::make_shared<testing::NiceMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8) const, N> > >(inst, targetFunc, funcName);
            return bsl::static_pointer_cast<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8) const, N> >(l_mockObj);
        }

        // Create a nice mock with instance for a CONST virtual member function with 9 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9) const, N> > createVirtualMockNice(
            const C& inst, R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9) const, const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::NiceMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9) const, N> > > l_mockObj = bsl::make_shared<testing::NiceMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9) const, N> > >(inst, targetFunc, funcName);
            return bsl::static_pointer_cast<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9) const, N> >(l_mockObj);
        }

        // Create a nice mock with instance for a CONST virtual member function with 10 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9, typename P10>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10) const, N> > createVirtualMockNice(
            const C& inst, R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10) const, const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::NiceMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10) const, N> > > l_mockObj = bsl::make_shared<testing::NiceMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10) const, N> > >(inst, targetFunc, funcName);
            return bsl::static_pointer_cast<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10) const, N> >(l_mockObj);
        }

        // Create a nice mock with instance for a CONST virtual member function with 11 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9, typename P10, typename P11>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11) const, N> > createVirtualMockNice(
            const C& inst, R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11) const, const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::NiceMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11) const, N> > > l_mockObj = bsl::make_shared<testing::NiceMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11) const, N> > >(inst, targetFunc, funcName);
            return bsl::static_pointer_cast<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11) const, N> >(l_mockObj);
        }

        // Create a nice mock with instance for a CONST virtual member function with 12 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9, typename P10, typename P11, typename P12>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12) const, N> > createVirtualMockNice(
            const C& inst, R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12) const, const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::NiceMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12) const, N> > > l_mockObj = bsl::make_shared<testing::NiceMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12) const, N> > >(inst, targetFunc, funcName);
            return bsl::static_pointer_cast<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12) const, N> >(l_mockObj);
        }

        // Create a nice mock with instance for a CONST virtual member function with 13 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13) const, N> > createVirtualMockNice(
            const C& inst, R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13) const, const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::NiceMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13) const, N> > > l_mockObj = bsl::make_shared<testing::NiceMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13) const, N> > >(inst, targetFunc, funcName);
            return bsl::static_pointer_cast<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13) const, N> >(l_mockObj);
        }

        // Create a nice mock with instance for a CONST virtual member function with 14 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13, typename P14>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14) const, N> > createVirtualMockNice(
            const C& inst, R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14) const, const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::NiceMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14) const, N> > > l_mockObj = bsl::make_shared<testing::NiceMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14) const, N> > >(inst, targetFunc, funcName);
            return bsl::static_pointer_cast<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14) const, N> >(l_mockObj);
        }

        // Create a nice mock with instance for a CONST virtual member function with 15 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13, typename P14, typename P15>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15) const, N> > createVirtualMockNice(
            const C& inst, R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15) const, const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::NiceMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15) const, N> > > l_mockObj = bsl::make_shared<testing::NiceMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15) const, N> > >(inst, targetFunc, funcName);
            return bsl::static_pointer_cast<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15) const, N> >(l_mockObj);
        }

        // =========================================================================
        // createPrivateStaticMockNice - Private static functions
        // =========================================================================

        // Create a nice mock for a private static function with 0 parameters
        template <int N, typename R>
        static bsl::shared_ptr<Mock<R(), N> > createPrivateStaticMockNice(R targetFunc(), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            bsl::shared_ptr<testing::NiceMock<Mock<R(), N> > > niceMock = bsl::make_shared<testing::NiceMock<Mock<R(), N> > >(funcName);
            return bsl::static_pointer_cast<Mock<R(), N> >(niceMock);
        }

        // Create a nice mock for a private static function with 1 parameter
        template <int N, typename R, typename P1>
        static bsl::shared_ptr<Mock<R(P1), N> > createPrivateStaticMockNice(R targetFunc(P1), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            bsl::shared_ptr<testing::NiceMock<Mock<R(P1), N> > > niceMock = bsl::make_shared<testing::NiceMock<Mock<R(P1), N> > >(funcName);
            return bsl::static_pointer_cast<Mock<R(P1), N> >(niceMock);
        }

        // Create a nice mock for a private static function with 2 parameters
        template <int N, typename R, typename P1, typename P2>
        static bsl::shared_ptr<Mock<R(P1, P2), N> > createPrivateStaticMockNice(R targetFunc(P1, P2), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            bsl::shared_ptr<testing::NiceMock<Mock<R(P1, P2), N> > > niceMock = bsl::make_shared<testing::NiceMock<Mock<R(P1, P2), N> > >(funcName);
            return bsl::static_pointer_cast<Mock<R(P1, P2), N> >(niceMock);
        }

        // Create a nice mock for a private static function with 3 parameters
        template <int N, typename R, typename P1, typename P2, typename P3>
        static bsl::shared_ptr<Mock<R(P1, P2, P3), N> > createPrivateStaticMockNice(R targetFunc(P1, P2, P3), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            bsl::shared_ptr<testing::NiceMock<Mock<R(P1, P2, P3), N> > > niceMock = bsl::make_shared<testing::NiceMock<Mock<R(P1, P2, P3), N> > >(funcName);
            return bsl::static_pointer_cast<Mock<R(P1, P2, P3), N> >(niceMock);
        }

        // Create a nice mock for a private static function with 4 parameters
        template <int N, typename R, typename P1, typename P2, typename P3, typename P4>
        static bsl::shared_ptr<Mock<R(P1, P2, P3, P4), N> > createPrivateStaticMockNice(R targetFunc(P1, P2, P3, P4), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            bsl::shared_ptr<testing::NiceMock<Mock<R(P1, P2, P3, P4), N> > > niceMock = bsl::make_shared<testing::NiceMock<Mock<R(P1, P2, P3, P4), N> > >(funcName);
            return bsl::static_pointer_cast<Mock<R(P1, P2, P3, P4), N> >(niceMock);
        }

        // Create a nice mock for a private static function with 5 parameters
        template <int N, typename R, typename P1, typename P2, typename P3, typename P4, typename P5>
        static bsl::shared_ptr<Mock<R(P1, P2, P3, P4, P5), N> > createPrivateStaticMockNice(R targetFunc(P1, P2, P3, P4, P5), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            bsl::shared_ptr<testing::NiceMock<Mock<R(P1, P2, P3, P4, P5), N> > > niceMock = bsl::make_shared<testing::NiceMock<Mock<R(P1, P2, P3, P4, P5), N> > >(funcName);
            return bsl::static_pointer_cast<Mock<R(P1, P2, P3, P4, P5), N> >(niceMock);
        }

        // Create a nice mock for a private static function with 6 parameters
        template <int N, typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6>
        static bsl::shared_ptr<Mock<R(P1, P2, P3, P4, P5, P6), N> > createPrivateStaticMockNice(R targetFunc(P1, P2, P3, P4, P5, P6), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            bsl::shared_ptr<testing::NiceMock<Mock<R(P1, P2, P3, P4, P5, P6), N> > > niceMock = bsl::make_shared<testing::NiceMock<Mock<R(P1, P2, P3, P4, P5, P6), N> > >(funcName);
            return bsl::static_pointer_cast<Mock<R(P1, P2, P3, P4, P5, P6), N> >(niceMock);
        }

        // Create a nice mock for a private static function with 7 parameters
        template <int N, typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7>
        static bsl::shared_ptr<Mock<R(P1, P2, P3, P4, P5, P6, P7), N> > createPrivateStaticMockNice(
            R targetFunc(P1, P2, P3, P4, P5, P6, P7), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            bsl::shared_ptr<testing::NiceMock<Mock<R(P1, P2, P3, P4, P5, P6, P7), N> > > niceMock = bsl::make_shared<testing::NiceMock<Mock<R(P1, P2, P3, P4, P5, P6, P7), N> > >(funcName);
            return bsl::static_pointer_cast<Mock<R(P1, P2, P3, P4, P5, P6, P7), N> >(niceMock);
        }

        // Create a nice mock for a private static function with 8 parameters
        template <int N, typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
            typename P7, typename P8>
        static bsl::shared_ptr<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8), N> > createPrivateStaticMockNice(
            R targetFunc(P1, P2, P3, P4, P5, P6, P7, P8), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            bsl::shared_ptr<testing::NiceMock<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8), N> > > niceMock = bsl::make_shared<testing::NiceMock<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8), N> > >(funcName);
            return bsl::static_pointer_cast<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8), N> >(niceMock);
        }

        // Create a nice mock for a private static function with 9 parameters
        template <int N, typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
            typename P7, typename P8, typename P9>
        static bsl::shared_ptr<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9), N> > createPrivateStaticMockNice(
            R targetFunc(P1, P2, P3, P4, P5, P6, P7, P8, P9), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            bsl::shared_ptr<testing::NiceMock<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9), N> > > niceMock = bsl::make_shared<testing::NiceMock<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9), N> > >(funcName);
            return bsl::static_pointer_cast<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9), N> >(niceMock);
        }

        // Create a nice mock for a private static function with 10 parameters
        template <int N, typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
            typename P7, typename P8, typename P9, typename P10>
        static bsl::shared_ptr<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10), N> > createPrivateStaticMockNice(
            R targetFunc(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            bsl::shared_ptr<testing::NiceMock<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10), N> > > niceMock = bsl::make_shared<testing::NiceMock<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10), N> > >(funcName);
            return bsl::static_pointer_cast<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10), N> >(niceMock);
        }

        // Create a nice mock for a private static function with 11 parameters
        template <int N, typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
            typename P7, typename P8, typename P9, typename P10, typename P11>
        static bsl::shared_ptr<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11), N> > createPrivateStaticMockNice(
            R targetFunc(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            bsl::shared_ptr<testing::NiceMock<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11), N> > > niceMock = bsl::make_shared<testing::NiceMock<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11), N> > >(funcName);
            return bsl::static_pointer_cast<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11), N> >(niceMock);
        }

        // Create a nice mock for a private static function with 12 parameters
        template <int N, typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
            typename P7, typename P8, typename P9, typename P10, typename P11, typename P12>
        static bsl::shared_ptr<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12), N> > createPrivateStaticMockNice(
            R targetFunc(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            bsl::shared_ptr<testing::NiceMock<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12), N> > > niceMock = bsl::make_shared<testing::NiceMock<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12), N> > >(funcName);
            return bsl::static_pointer_cast<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12), N> >(niceMock);
        }

        // Create a nice mock for a private static function with 13 parameters
        template <int N, typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
            typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13>
        static bsl::shared_ptr<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13), N> > createPrivateStaticMockNice(
            R targetFunc(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            bsl::shared_ptr<testing::NiceMock<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13), N> > > niceMock = bsl::make_shared<testing::NiceMock<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13), N> > >(funcName);
            return bsl::static_pointer_cast<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13), N> >(niceMock);
        }

        // Create a nice mock for a private static function with 14 parameters
        template <int N, typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
            typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13, typename P14>
        static bsl::shared_ptr<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14), N> > createPrivateStaticMockNice(
            R targetFunc(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            bsl::shared_ptr<testing::NiceMock<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14), N> > > niceMock = bsl::make_shared<testing::NiceMock<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14), N> > >(funcName);
            return bsl::static_pointer_cast<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14), N> >(niceMock);
        }

        // Create a nice mock for a private static function with 15 parameters
        template <int N, typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
            typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13, typename P14, typename P15>
        static bsl::shared_ptr<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15), N> > createPrivateStaticMockNice(
            R targetFunc(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            bsl::shared_ptr<testing::NiceMock<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15), N> > > niceMock = bsl::make_shared<testing::NiceMock<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15), N> > >(funcName);
            return bsl::static_pointer_cast<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15), N> >(niceMock);
        }

        // =========================================================================
        // createPrivateMockNice - Non-const private member functions
        // =========================================================================

        // Create a nice mock for a non-const private member function with 0 parameters
        template <int N, typename C, typename R>
        static bsl::shared_ptr<MockPrivate<R (C::*)(), N> > createPrivateMockNice(R targetFunc(), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            bsl::shared_ptr<testing::NiceMock<MockPrivate<R (C::*)(), N> > > l_mockObj = bsl::make_shared<testing::NiceMock<MockPrivate<R (C::*)(), N> > >(funcName);
            return bsl::static_pointer_cast<MockPrivate<R (C::*)(), N> >(l_mockObj);
        }

        // Create a nice mock for a non-const private member function with 1 parameter
        template <int N, typename C, typename R, typename P1>
        static bsl::shared_ptr<MockPrivate<R (C::*)(P1), N> > createPrivateMockNice(R targetFunc(P1), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            bsl::shared_ptr<testing::NiceMock<MockPrivate<R (C::*)(P1), N> > > l_mockObj = bsl::make_shared<testing::NiceMock<MockPrivate<R (C::*)(P1), N> > >(funcName);
            return bsl::static_pointer_cast<MockPrivate<R (C::*)(P1), N> >(l_mockObj);
        }

        // Create a nice mock for a non-const private member function with 2 parameters
        template <int N, typename C, typename R, typename P1, typename P2>
        static bsl::shared_ptr<MockPrivate<R (C::*)(P1, P2), N> > createPrivateMockNice(R targetFunc(P1, P2), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            bsl::shared_ptr<testing::NiceMock<MockPrivate<R (C::*)(P1, P2), N> > > l_mockObj = bsl::make_shared<testing::NiceMock<MockPrivate<R (C::*)(P1, P2), N> > >(funcName);
            return bsl::static_pointer_cast<MockPrivate<R (C::*)(P1, P2), N> >(l_mockObj);
        }

        // Create a nice mock for a non-const private member function with 3 parameters
        template <int N, typename C, typename R, typename P1, typename P2, typename P3>
        static bsl::shared_ptr<MockPrivate<R (C::*)(P1, P2, P3), N> > createPrivateMockNice(R targetFunc(P1, P2, P3), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            bsl::shared_ptr<testing::NiceMock<MockPrivate<R (C::*)(P1, P2, P3), N> > > l_mockObj = bsl::make_shared<testing::NiceMock<MockPrivate<R (C::*)(P1, P2, P3), N> > >(funcName);
            return bsl::static_pointer_cast<MockPrivate<R (C::*)(P1, P2, P3), N> >(l_mockObj);
        }

        // Create a nice mock for a non-const private member function with 4 parameters
        template <int N, typename C, typename R, typename P1, typename P2, typename P3, typename P4>
        static bsl::shared_ptr<MockPrivate<R (C::*)(P1, P2, P3, P4), N> > createPrivateMockNice(R targetFunc(P1, P2, P3, P4), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            bsl::shared_ptr<testing::NiceMock<MockPrivate<R (C::*)(P1, P2, P3, P4), N> > > l_mockObj = bsl::make_shared<testing::NiceMock<MockPrivate<R (C::*)(P1, P2, P3, P4), N> > >(funcName);
            return bsl::static_pointer_cast<MockPrivate<R (C::*)(P1, P2, P3, P4), N> >(l_mockObj);
        }

        // Create a nice mock for a non-const private member function with 5 parameters
        template <int N, typename C, typename R, typename P1, typename P2, typename P3, typename P4, typename P5>
        static bsl::shared_ptr<MockPrivate<R (C::*)(P1, P2, P3, P4, P5), N> > createPrivateMockNice(R targetFunc(P1, P2, P3, P4, P5), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            bsl::shared_ptr<testing::NiceMock<MockPrivate<R (C::*)(P1, P2, P3, P4, P5), N> > > l_mockObj = bsl::make_shared<testing::NiceMock<MockPrivate<R (C::*)(P1, P2, P3, P4, P5), N> > >(funcName);
            return bsl::static_pointer_cast<MockPrivate<R (C::*)(P1, P2, P3, P4, P5), N> >(l_mockObj);
        }

        // Create a nice mock for a non-const private member function with 6 parameters
        template <int N, typename C, typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6>
        static bsl::shared_ptr<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6), N> > createPrivateMockNice(R targetFunc(P1, P2, P3, P4, P5, P6), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            bsl::shared_ptr<testing::NiceMock<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6), N> > > l_mockObj = bsl::make_shared<testing::NiceMock<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6), N> > >(funcName);
            return bsl::static_pointer_cast<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6), N> >(l_mockObj);
        }

        // Create a nice mock for a non-const private member function with 7 parameters
        template <int N, typename C, typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7>
        static bsl::shared_ptr<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7), N> > createPrivateMockNice(
            R targetFunc(P1, P2, P3, P4, P5, P6, P7), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            bsl::shared_ptr<testing::NiceMock<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7), N> > > l_mockObj = bsl::make_shared<testing::NiceMock<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7), N> > >(funcName);
            return bsl::static_pointer_cast<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7), N> >(l_mockObj);
        }

        // Create a nice mock for a non-const private member function with 8 parameters
        template <int N, typename C, typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
            typename P7, typename P8>
        static bsl::shared_ptr<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8), N> > createPrivateMockNice(
            R targetFunc(P1, P2, P3, P4, P5, P6, P7, P8), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            bsl::shared_ptr<testing::NiceMock<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8), N> > > l_mockObj = bsl::make_shared<testing::NiceMock<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8), N> > >(funcName);
            return bsl::static_pointer_cast<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8), N> >(l_mockObj);
        }

        // Create a nice mock for a non-const private member function with 9 parameters
        template <int N, typename C, typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
            typename P7, typename P8, typename P9>
        static bsl::shared_ptr<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9), N> > createPrivateMockNice(
            R targetFunc(P1, P2, P3, P4, P5, P6, P7, P8, P9), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            bsl::shared_ptr<testing::NiceMock<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9), N> > > l_mockObj = bsl::make_shared<testing::NiceMock<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9), N> > >(funcName);
            return bsl::static_pointer_cast<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9), N> >(l_mockObj);
        }

        // Create a nice mock for a non-const private member function with 10 parameters
        template <int N, typename C, typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
            typename P7, typename P8, typename P9, typename P10>
        static bsl::shared_ptr<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10), N> > createPrivateMockNice(
            R targetFunc(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            bsl::shared_ptr<testing::NiceMock<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10), N> > > l_mockObj = bsl::make_shared<testing::NiceMock<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10), N> > >(funcName);
            return bsl::static_pointer_cast<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10), N> >(l_mockObj);
        }

        // Create a nice mock for a non-const private member function with 11 parameters
        template <int N, typename C, typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
            typename P7, typename P8, typename P9, typename P10, typename P11>
        static bsl::shared_ptr<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11), N> > createPrivateMockNice(
            R targetFunc(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            bsl::shared_ptr<testing::NiceMock<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11), N> > > l_mockObj = bsl::make_shared<testing::NiceMock<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11), N> > >(funcName);
            return bsl::static_pointer_cast<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11), N> >(l_mockObj);
        }

        // Create a nice mock for a non-const private member function with 12 parameters
        template <int N, typename C, typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
            typename P7, typename P8, typename P9, typename P10, typename P11, typename P12>
        static bsl::shared_ptr<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12), N> > createPrivateMockNice(
            R targetFunc(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            bsl::shared_ptr<testing::NiceMock<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12), N> > > l_mockObj = bsl::make_shared<testing::NiceMock<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12), N> > >(funcName);
            return bsl::static_pointer_cast<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12), N> >(l_mockObj);
        }

        // Create a nice mock for a non-const private member function with 13 parameters
        template <int N, typename C, typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
            typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13>
        static bsl::shared_ptr<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13), N> > createPrivateMockNice(
            R targetFunc(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            bsl::shared_ptr<testing::NiceMock<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13), N> > > l_mockObj = bsl::make_shared<testing::NiceMock<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13), N> > >(funcName);
            return bsl::static_pointer_cast<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13), N> >(l_mockObj);
        }

        // Create a nice mock for a non-const private member function with 14 parameters
        template <int N, typename C, typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
            typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13, typename P14>
        static bsl::shared_ptr<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14), N> > createPrivateMockNice(
            R targetFunc(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            bsl::shared_ptr<testing::NiceMock<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14), N> > > l_mockObj = bsl::make_shared<testing::NiceMock<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14), N> > >(funcName);
            return bsl::static_pointer_cast<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14), N> >(l_mockObj);
        }

        // Create a nice mock for a non-const private member function with 15 parameters
        template <int N, typename C, typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
            typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13, typename P14, typename P15>
        static bsl::shared_ptr<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15), N> > createPrivateMockNice(
            R targetFunc(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            bsl::shared_ptr<testing::NiceMock<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15), N> > > l_mockObj = bsl::make_shared<testing::NiceMock<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15), N> > >(funcName);
            return bsl::static_pointer_cast<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15), N> >(l_mockObj);
        }

        // =========================================================================
        // createPrivateMockNiceConst - Const private member functions
        // =========================================================================

        // Create a nice mock for a const private member function with 0 parameters
        template <int N, typename C, typename R>
        static bsl::shared_ptr<MockPrivate<R (C::*)() const, N> > createPrivateMockNiceConst(R targetFunc(), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            bsl::shared_ptr<testing::NiceMock<MockPrivate<R (C::*)() const, N> > > l_mockObj = bsl::make_shared<testing::NiceMock<MockPrivate<R (C::*)() const, N> > >(funcName);
            return bsl::static_pointer_cast<MockPrivate<R (C::*)() const, N> >(l_mockObj);
        }

        // Create a nice mock for a const private member function with 1 parameter
        template <int N, typename C, typename R, typename P1>
        static bsl::shared_ptr<MockPrivate<R (C::*)(P1) const, N> > createPrivateMockNiceConst(R targetFunc(P1), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            bsl::shared_ptr<testing::NiceMock<MockPrivate<R (C::*)(P1) const, N> > > l_mockObj = bsl::make_shared<testing::NiceMock<MockPrivate<R (C::*)(P1) const, N> > >(funcName);
            return bsl::static_pointer_cast<MockPrivate<R (C::*)(P1) const, N> >(l_mockObj);
        }

        // Create a nice mock for a const private member function with 2 parameters
        template <int N, typename C, typename R, typename P1, typename P2>
        static bsl::shared_ptr<MockPrivate<R (C::*)(P1, P2) const, N> > createPrivateMockNiceConst(R targetFunc(P1, P2), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            bsl::shared_ptr<testing::NiceMock<MockPrivate<R (C::*)(P1, P2) const, N> > > l_mockObj = bsl::make_shared<testing::NiceMock<MockPrivate<R (C::*)(P1, P2) const, N> > >(funcName);
            return bsl::static_pointer_cast<MockPrivate<R (C::*)(P1, P2) const, N> >(l_mockObj);
        }

        // Create a nice mock for a const private member function with 3 parameters
        template <int N, typename C, typename R, typename P1, typename P2, typename P3>
        static bsl::shared_ptr<MockPrivate<R (C::*)(P1, P2, P3) const, N> > createPrivateMockNiceConst(R targetFunc(P1, P2, P3), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            bsl::shared_ptr<testing::NiceMock<MockPrivate<R (C::*)(P1, P2, P3) const, N> > > l_mockObj = bsl::make_shared<testing::NiceMock<MockPrivate<R (C::*)(P1, P2, P3) const, N> > >(funcName);
            return bsl::static_pointer_cast<MockPrivate<R (C::*)(P1, P2, P3) const, N> >(l_mockObj);
        }

        // Create a nice mock for a const private member function with 4 parameters
        template <int N, typename C, typename R, typename P1, typename P2, typename P3, typename P4>
        static bsl::shared_ptr<MockPrivate<R (C::*)(P1, P2, P3, P4) const, N> > createPrivateMockNiceConst(R targetFunc(P1, P2, P3, P4), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            bsl::shared_ptr<testing::NiceMock<MockPrivate<R (C::*)(P1, P2, P3, P4) const, N> > > l_mockObj = bsl::make_shared<testing::NiceMock<MockPrivate<R (C::*)(P1, P2, P3, P4) const, N> > >(funcName);
            return bsl::static_pointer_cast<MockPrivate<R (C::*)(P1, P2, P3, P4) const, N> >(l_mockObj);
        }

        // Create a nice mock for a const private member function with 5 parameters
        template <int N, typename C, typename R, typename P1, typename P2, typename P3, typename P4, typename P5>
        static bsl::shared_ptr<MockPrivate<R (C::*)(P1, P2, P3, P4, P5) const, N> > createPrivateMockNiceConst(R targetFunc(P1, P2, P3, P4, P5), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            bsl::shared_ptr<testing::NiceMock<MockPrivate<R (C::*)(P1, P2, P3, P4, P5) const, N> > > l_mockObj = bsl::make_shared<testing::NiceMock<MockPrivate<R (C::*)(P1, P2, P3, P4, P5) const, N> > >(funcName);
            return bsl::static_pointer_cast<MockPrivate<R (C::*)(P1, P2, P3, P4, P5) const, N> >(l_mockObj);
        }

        // Create a nice mock for a const private member function with 6 parameters
        template <int N, typename C, typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6>
        static bsl::shared_ptr<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6) const, N> > createPrivateMockNiceConst(R targetFunc(P1, P2, P3, P4, P5, P6), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            bsl::shared_ptr<testing::NiceMock<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6) const, N> > > l_mockObj = bsl::make_shared<testing::NiceMock<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6) const, N> > >(funcName);
            return bsl::static_pointer_cast<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6) const, N> >(l_mockObj);
        }

        // Create a nice mock for a const private member function with 7 parameters
        template <int N, typename C, typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7>
        static bsl::shared_ptr<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7) const, N> > createPrivateMockNiceConst(
            R targetFunc(P1, P2, P3, P4, P5, P6, P7), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            bsl::shared_ptr<testing::NiceMock<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7) const, N> > > l_mockObj = bsl::make_shared<testing::NiceMock<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7) const, N> > >(funcName);
            return bsl::static_pointer_cast<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7) const, N> >(l_mockObj);
        }

        // Create a nice mock for a const private member function with 8 parameters
        template <int N, typename C, typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
            typename P7, typename P8>
        static bsl::shared_ptr<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8) const, N> > createPrivateMockNiceConst(
            R targetFunc(P1, P2, P3, P4, P5, P6, P7, P8), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            bsl::shared_ptr<testing::NiceMock<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8) const, N> > > l_mockObj = bsl::make_shared<testing::NiceMock<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8) const, N> > >(funcName);
            return bsl::static_pointer_cast<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8) const, N> >(l_mockObj);
        }

        // Create a nice mock for a const private member function with 9 parameters
        template <int N, typename C, typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
            typename P7, typename P8, typename P9>
        static bsl::shared_ptr<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9) const, N> > createPrivateMockNiceConst(
            R targetFunc(P1, P2, P3, P4, P5, P6, P7, P8, P9), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            bsl::shared_ptr<testing::NiceMock<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9) const, N> > > l_mockObj = bsl::make_shared<testing::NiceMock<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9) const, N> > >(funcName);
            return bsl::static_pointer_cast<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9) const, N> >(l_mockObj);
        }

        // Create a nice mock for a const private member function with 10 parameters
        template <int N, typename C, typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
            typename P7, typename P8, typename P9, typename P10>
        static bsl::shared_ptr<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10) const, N> > createPrivateMockNiceConst(
            R targetFunc(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            bsl::shared_ptr<testing::NiceMock<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10) const, N> > > l_mockObj = bsl::make_shared<testing::NiceMock<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10) const, N> > >(funcName);
            return bsl::static_pointer_cast<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10) const, N> >(l_mockObj);
        }

        // Create a nice mock for a const private member function with 11 parameters
        template <int N, typename C, typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
            typename P7, typename P8, typename P9, typename P10, typename P11>
        static bsl::shared_ptr<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11) const, N> > createPrivateMockNiceConst(
            R targetFunc(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            bsl::shared_ptr<testing::NiceMock<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11) const, N> > > l_mockObj = bsl::make_shared<testing::NiceMock<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11) const, N> > >(funcName);
            return bsl::static_pointer_cast<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11) const, N> >(l_mockObj);
        }

        // Create a nice mock for a const private member function with 12 parameters
        template <int N, typename C, typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
            typename P7, typename P8, typename P9, typename P10, typename P11, typename P12>
        static bsl::shared_ptr<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12) const, N> > createPrivateMockNiceConst(
            R targetFunc(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            bsl::shared_ptr<testing::NiceMock<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12) const, N> > > l_mockObj = bsl::make_shared<testing::NiceMock<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12) const, N> > >(funcName);
            return bsl::static_pointer_cast<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12) const, N> >(l_mockObj);
        }

        // Create a nice mock for a const private member function with 13 parameters
        template <int N, typename C, typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
            typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13>
        static bsl::shared_ptr<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13) const, N> > createPrivateMockNiceConst(
            R targetFunc(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            bsl::shared_ptr<testing::NiceMock<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13) const, N> > > l_mockObj = bsl::make_shared<testing::NiceMock<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13) const, N> > >(funcName);
            return bsl::static_pointer_cast<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13) const, N> >(l_mockObj);
        }

        // Create a nice mock for a const private member function with 14 parameters
        template <int N, typename C, typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
            typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13, typename P14>
        static bsl::shared_ptr<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14) const, N> > createPrivateMockNiceConst(
            R targetFunc(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            bsl::shared_ptr<testing::NiceMock<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14) const, N> > > l_mockObj = bsl::make_shared<testing::NiceMock<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14) const, N> > >(funcName);
            return bsl::static_pointer_cast<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14) const, N> >(l_mockObj);
        }

        // Create a nice mock for a const private member function with 15 parameters
        template <int N, typename C, typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
            typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13, typename P14, typename P15>
        static bsl::shared_ptr<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15) const, N> > createPrivateMockNiceConst(
            R targetFunc(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            bsl::shared_ptr<testing::NiceMock<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15) const, N> > > l_mockObj = bsl::make_shared<testing::NiceMock<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15) const, N> > >(funcName);
            return bsl::static_pointer_cast<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15) const, N> >(l_mockObj);
        }
    };

} // bonobomock
} // BloombergLP

#endif
