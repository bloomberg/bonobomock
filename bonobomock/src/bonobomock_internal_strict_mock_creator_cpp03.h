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

#ifndef INCLUDED_BONOBOMOCK_INTERNAL_STRICT_MOCK_CREATOR_CPP03
#define INCLUDED_BONOBOMOCK_INTERNAL_STRICT_MOCK_CREATOR_CPP03

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

    class StrictMockCreator {
    public:
        // =========================================================================
        // createMockStrict - Global/free/static/fortran functions
        // =========================================================================

        // Create a strict mock for a global/free or fortran, or static function with 0 parameters
        template <int N, typename R>
        static bsl::shared_ptr<Mock<R(), N> > createMockStrict(R targetFunc(), const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::StrictMock<Mock<R(), N> > > strictMock = bsl::make_shared<testing::StrictMock<Mock<R(), N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<Mock<R(), N> >(strictMock);
        }

        // Create a strict mock for a global/free or fortran, or static function with 1 parameter
        template <int N, typename R, typename P1>
        static bsl::shared_ptr<Mock<R(P1), N> > createMockStrict(R targetFunc(P1), const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::StrictMock<Mock<R(P1), N> > > strictMock = bsl::make_shared<testing::StrictMock<Mock<R(P1), N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<Mock<R(P1), N> >(strictMock);
        }

        // Create a strict mock for a global/free or fortran, or static function with 2 parameters
        template <int N, typename R, typename P1, typename P2>
        static bsl::shared_ptr<Mock<R(P1, P2), N> > createMockStrict(R targetFunc(P1, P2), const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::StrictMock<Mock<R(P1, P2), N> > > strictMock = bsl::make_shared<testing::StrictMock<Mock<R(P1, P2), N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<Mock<R(P1, P2), N> >(strictMock);
        }

        // Create a strict mock for a global/free or fortran, or static function with 3 parameters
        template <int N, typename R, typename P1, typename P2, typename P3>
        static bsl::shared_ptr<Mock<R(P1, P2, P3), N> > createMockStrict(R targetFunc(P1, P2, P3), const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::StrictMock<Mock<R(P1, P2, P3), N> > > strictMock = bsl::make_shared<testing::StrictMock<Mock<R(P1, P2, P3), N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<Mock<R(P1, P2, P3), N> >(strictMock);
        }

        // Create a strict mock for a global/free or fortran, or static function with 4 parameters
        template <int N, typename R, typename P1, typename P2, typename P3, typename P4>
        static bsl::shared_ptr<Mock<R(P1, P2, P3, P4), N> > createMockStrict(R targetFunc(P1, P2, P3, P4), const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::StrictMock<Mock<R(P1, P2, P3, P4), N> > > strictMock = bsl::make_shared<testing::StrictMock<Mock<R(P1, P2, P3, P4), N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<Mock<R(P1, P2, P3, P4), N> >(strictMock);
        }

        // Create a strict mock for a global/free or fortran, or static function with 5 parameters
        template <int N, typename R, typename P1, typename P2, typename P3, typename P4, typename P5>
        static bsl::shared_ptr<Mock<R(P1, P2, P3, P4, P5), N> > createMockStrict(R targetFunc(P1, P2, P3, P4, P5), const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::StrictMock<Mock<R(P1, P2, P3, P4, P5), N> > > strictMock = bsl::make_shared<testing::StrictMock<Mock<R(P1, P2, P3, P4, P5), N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<Mock<R(P1, P2, P3, P4, P5), N> >(strictMock);
        }

        // Create a strict mock for a global/free or fortran, or static function with 6 parameters
        template <int N, typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6>
        static bsl::shared_ptr<Mock<R(P1, P2, P3, P4, P5, P6), N> > createMockStrict(R targetFunc(P1, P2, P3, P4, P5, P6), const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::StrictMock<Mock<R(P1, P2, P3, P4, P5, P6), N> > > strictMock = bsl::make_shared<testing::StrictMock<Mock<R(P1, P2, P3, P4, P5, P6), N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<Mock<R(P1, P2, P3, P4, P5, P6), N> >(strictMock);
        }

        // Create a strict mock for a global/free or fortran, or static function with 7 parameters
        template <int N, typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7>
        static bsl::shared_ptr<Mock<R(P1, P2, P3, P4, P5, P6, P7), N> > createMockStrict(
            R targetFunc(P1, P2, P3, P4, P5, P6, P7), const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::StrictMock<Mock<R(P1, P2, P3, P4, P5, P6, P7), N> > > strictMock = bsl::make_shared<testing::StrictMock<Mock<R(P1, P2, P3, P4, P5, P6, P7), N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<Mock<R(P1, P2, P3, P4, P5, P6, P7), N> >(strictMock);
        }

        // Create a strict mock for a global/free or fortran, or static function with 8 parameters
        template <int N, typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
            typename P7, typename P8>
        static bsl::shared_ptr<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8), N> > createMockStrict(
            R targetFunc(P1, P2, P3, P4, P5, P6, P7, P8), const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::StrictMock<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8), N> > > strictMock = bsl::make_shared<testing::StrictMock<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8), N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8), N> >(strictMock);
        }

        // Create a strict mock for a global/free or fortran, or static function with 9 parameters
        template <int N, typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
            typename P7, typename P8, typename P9>
        static bsl::shared_ptr<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9), N> > createMockStrict(
            R targetFunc(P1, P2, P3, P4, P5, P6, P7, P8, P9), const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::StrictMock<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9), N> > > strictMock = bsl::make_shared<testing::StrictMock<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9), N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9), N> >(strictMock);
        }

        // Create a strict mock for a global/free or fortran, or static function with 10 parameters
        template <int N, typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
            typename P7, typename P8, typename P9, typename P10>
        static bsl::shared_ptr<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10), N> > createMockStrict(
            R targetFunc(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10), const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::StrictMock<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10), N> > > strictMock = bsl::make_shared<testing::StrictMock<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10), N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10), N> >(strictMock);
        }

        // Create a strict mock for a global/free or fortran, or static function with 11 parameters
        template <int N, typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
            typename P7, typename P8, typename P9, typename P10, typename P11>
        static bsl::shared_ptr<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11), N> > createMockStrict(
            R targetFunc(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11), const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::StrictMock<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11), N> > > strictMock = bsl::make_shared<testing::StrictMock<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11), N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11), N> >(strictMock);
        }

        // Create a strict mock for a global/free or fortran, or static function with 12 parameters
        template <int N, typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
            typename P7, typename P8, typename P9, typename P10, typename P11, typename P12>
        static bsl::shared_ptr<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12), N> > createMockStrict(
            R targetFunc(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12), const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::StrictMock<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12), N> > > strictMock = bsl::make_shared<testing::StrictMock<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12), N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12), N> >(strictMock);
        }

        // Create a strict mock for a global/free or fortran, or static function with 13 parameters
        template <int N, typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
            typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13>
        static bsl::shared_ptr<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13), N> > createMockStrict(
            R targetFunc(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13), const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::StrictMock<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13), N> > > strictMock = bsl::make_shared<testing::StrictMock<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13), N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13), N> >(strictMock);
        }

        // Create a strict mock for a global/free or fortran, or static function with 14 parameters
        template <int N, typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
            typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13, typename P14>
        static bsl::shared_ptr<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14), N> > createMockStrict(
            R targetFunc(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14), const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::StrictMock<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14), N> > > strictMock = bsl::make_shared<testing::StrictMock<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14), N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14), N> >(strictMock);
        }

        // Create a strict mock for a global/free or fortran, or static function with 15 parameters
        template <int N, typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
            typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13, typename P14, typename P15>
        static bsl::shared_ptr<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15), N> > createMockStrict(
            R targetFunc(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15), const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::StrictMock<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15), N> > > strictMock = bsl::make_shared<testing::StrictMock<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15), N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15), N> >(strictMock);
        }

        // =========================================================================
        // createMockStrict - Non-const non-virtual member functions
        // =========================================================================

        // Create a strict mock for a NON-CONST member function with 0 parameters
        template <int N, typename R, typename C>
        static bsl::shared_ptr<Mock<R (C::*)(), N> > createMockStrict(R (C::*targetFunc)(), const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::StrictMock<Mock<R (C::*)(), N> > > strictMock = bsl::make_shared<testing::StrictMock<Mock<R (C::*)(), N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<Mock<R (C::*)(), N> >(strictMock);
        }

        // Create a strict mock for a NON-CONST member function with 1 parameter
        template <int N, typename R, typename C, typename P1>
        static bsl::shared_ptr<Mock<R (C::*)(P1), N> > createMockStrict(R (C::*targetFunc)(P1), const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::StrictMock<Mock<R (C::*)(P1), N> > > strictMock = bsl::make_shared<testing::StrictMock<Mock<R (C::*)(P1), N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<Mock<R (C::*)(P1), N> >(strictMock);
        }

        // Create a strict mock for a NON-CONST member function with 2 parameters
        template <int N, typename R, typename C, typename P1, typename P2>
        static bsl::shared_ptr<Mock<R (C::*)(P1, P2), N> > createMockStrict(R (C::*targetFunc)(P1, P2), const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::StrictMock<Mock<R (C::*)(P1, P2), N> > > strictMock = bsl::make_shared<testing::StrictMock<Mock<R (C::*)(P1, P2), N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<Mock<R (C::*)(P1, P2), N> >(strictMock);
        }

        // Create a strict mock for a NON-CONST member function with 3 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3>
        static bsl::shared_ptr<Mock<R (C::*)(P1, P2, P3), N> > createMockStrict(
            R (C::*targetFunc)(P1, P2, P3), const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::StrictMock<Mock<R (C::*)(P1, P2, P3), N> > > strictMock = bsl::make_shared<testing::StrictMock<Mock<R (C::*)(P1, P2, P3), N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<Mock<R (C::*)(P1, P2, P3), N> >(strictMock);
        }

        // Create a strict mock for a NON-CONST member function with 4 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4>
        static bsl::shared_ptr<Mock<R (C::*)(P1, P2, P3, P4), N> > createMockStrict(
            R (C::*targetFunc)(P1, P2, P3, P4), const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::StrictMock<Mock<R (C::*)(P1, P2, P3, P4), N> > > strictMock = bsl::make_shared<testing::StrictMock<Mock<R (C::*)(P1, P2, P3, P4), N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<Mock<R (C::*)(P1, P2, P3, P4), N> >(strictMock);
        }

        // Create a strict mock for a NON-CONST member function with 5 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5>
        static bsl::shared_ptr<Mock<R (C::*)(P1, P2, P3, P4, P5), N> > createMockStrict(
            R (C::*targetFunc)(P1, P2, P3, P4, P5), const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::StrictMock<Mock<R (C::*)(P1, P2, P3, P4, P5), N> > > strictMock = bsl::make_shared<testing::StrictMock<Mock<R (C::*)(P1, P2, P3, P4, P5), N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<Mock<R (C::*)(P1, P2, P3, P4, P5), N> >(strictMock);
        }

        // Create a strict mock for a NON-CONST member function with 6 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6>
        static bsl::shared_ptr<Mock<R (C::*)(P1, P2, P3, P4, P5, P6), N> > createMockStrict(
            R (C::*targetFunc)(P1, P2, P3, P4, P5, P6), const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::StrictMock<Mock<R (C::*)(P1, P2, P3, P4, P5, P6), N> > > strictMock = bsl::make_shared<testing::StrictMock<Mock<R (C::*)(P1, P2, P3, P4, P5, P6), N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<Mock<R (C::*)(P1, P2, P3, P4, P5, P6), N> >(strictMock);
        }

        // Create a strict mock for a NON-CONST member function with 7 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7>
        static bsl::shared_ptr<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7), N> > createMockStrict(
            R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7), const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::StrictMock<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7), N> > > strictMock = bsl::make_shared<testing::StrictMock<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7), N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7), N> >(strictMock);
        }

        // Create a strict mock for a NON-CONST member function with 8 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
            typename P7, typename P8>
        static bsl::shared_ptr<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8), N> > createMockStrict(
            R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8), const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::StrictMock<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8), N> > > strictMock = bsl::make_shared<testing::StrictMock<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8), N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8), N> >(strictMock);
        }

        // Create a strict mock for a NON-CONST member function with 9 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
            typename P7, typename P8, typename P9>
        static bsl::shared_ptr<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9), N> > createMockStrict(
            R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9), const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::StrictMock<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9), N> > > strictMock = bsl::make_shared<testing::StrictMock<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9), N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9), N> >(strictMock);
        }

        // Create a strict mock for a NON-CONST member function with 10 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
            typename P7, typename P8, typename P9, typename P10>
        static bsl::shared_ptr<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10), N> > createMockStrict(
            R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10), const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::StrictMock<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10), N> > > strictMock = bsl::make_shared<testing::StrictMock<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10), N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10), N> >(strictMock);
        }

        // Create a strict mock for a NON-CONST member function with 11 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
            typename P7, typename P8, typename P9, typename P10, typename P11>
        static bsl::shared_ptr<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11), N> > createMockStrict(
            R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11), const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::StrictMock<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11), N> > > strictMock = bsl::make_shared<testing::StrictMock<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11), N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11), N> >(strictMock);
        }

        // Create a strict mock for a NON-CONST member function with 12 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
            typename P7, typename P8, typename P9, typename P10, typename P11, typename P12>
        static bsl::shared_ptr<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12), N> > createMockStrict(
            R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12), const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::StrictMock<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12), N> > > strictMock = bsl::make_shared<testing::StrictMock<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12), N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12), N> >(strictMock);
        }

        // Create a strict mock for a NON-CONST member function with 13 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
            typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13>
        static bsl::shared_ptr<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13), N> > createMockStrict(
            R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13), const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::StrictMock<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13), N> > > strictMock = bsl::make_shared<testing::StrictMock<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13), N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13), N> >(strictMock);
        }

        // Create a strict mock for a NON-CONST member function with 14 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
            typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13, typename P14>
        static bsl::shared_ptr<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14), N> > createMockStrict(
            R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14), const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::StrictMock<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14), N> > > strictMock = bsl::make_shared<testing::StrictMock<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14), N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14), N> >(strictMock);
        }

        // Create a strict mock for a NON-CONST member function with 15 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
            typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13, typename P14, typename P15>
        static bsl::shared_ptr<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15), N> > createMockStrict(
            R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15), const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::StrictMock<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15), N> > > strictMock = bsl::make_shared<testing::StrictMock<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15), N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15), N> >(strictMock);
        }

        // =========================================================================
        // createMockStrict - Const non-virtual member functions
        // =========================================================================

        // Create a strict mock for a CONST member function with 0 parameters
        template <int N, typename R, typename C>
        static bsl::shared_ptr<Mock<R (C::*)() const, N> > createMockStrict(R (C::*targetFunc)() const, const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::StrictMock<Mock<R (C::*)() const, N> > > strictMock = bsl::make_shared<testing::StrictMock<Mock<R (C::*)() const, N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<Mock<R (C::*)() const, N> >(strictMock);
        }

        // Create a strict mock for a CONST member function with 1 parameter
        template <int N, typename R, typename C, typename P1>
        static bsl::shared_ptr<Mock<R (C::*)(P1) const, N> > createMockStrict(R (C::*targetFunc)(P1) const, const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::StrictMock<Mock<R (C::*)(P1) const, N> > > strictMock = bsl::make_shared<testing::StrictMock<Mock<R (C::*)(P1) const, N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<Mock<R (C::*)(P1) const, N> >(strictMock);
        }

        // Create a strict mock for a CONST member function with 2 parameters
        template <int N, typename R, typename C, typename P1, typename P2>
        static bsl::shared_ptr<Mock<R (C::*)(P1, P2) const, N> > createMockStrict(R (C::*targetFunc)(P1, P2) const, const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::StrictMock<Mock<R (C::*)(P1, P2) const, N> > > strictMock = bsl::make_shared<testing::StrictMock<Mock<R (C::*)(P1, P2) const, N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<Mock<R (C::*)(P1, P2) const, N> >(strictMock);
        }

        // Create a strict mock for a CONST member function with 3 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3>
        static bsl::shared_ptr<Mock<R (C::*)(P1, P2, P3) const, N> > createMockStrict(R (C::*targetFunc)(P1, P2, P3) const, const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::StrictMock<Mock<R (C::*)(P1, P2, P3) const, N> > > strictMock = bsl::make_shared<testing::StrictMock<Mock<R (C::*)(P1, P2, P3) const, N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<Mock<R (C::*)(P1, P2, P3) const, N> >(strictMock);
        }

        // Create a strict mock for a CONST member function with 4 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4>
        static bsl::shared_ptr<Mock<R (C::*)(P1, P2, P3, P4) const, N> > createMockStrict(R (C::*targetFunc)(P1, P2, P3, P4) const, const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::StrictMock<Mock<R (C::*)(P1, P2, P3, P4) const, N> > > strictMock = bsl::make_shared<testing::StrictMock<Mock<R (C::*)(P1, P2, P3, P4) const, N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<Mock<R (C::*)(P1, P2, P3, P4) const, N> >(strictMock);
        }

        // Create a strict mock for a CONST member function with 5 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5>
        static bsl::shared_ptr<Mock<R (C::*)(P1, P2, P3, P4, P5) const, N> > createMockStrict(R (C::*targetFunc)(P1, P2, P3, P4, P5) const, const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::StrictMock<Mock<R (C::*)(P1, P2, P3, P4, P5) const, N> > > strictMock = bsl::make_shared<testing::StrictMock<Mock<R (C::*)(P1, P2, P3, P4, P5) const, N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<Mock<R (C::*)(P1, P2, P3, P4, P5) const, N> >(strictMock);
        }

        // Create a strict mock for a CONST member function with 6 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6>
        static bsl::shared_ptr<Mock<R (C::*)(P1, P2, P3, P4, P5, P6) const, N> > createMockStrict(R (C::*targetFunc)(P1, P2, P3, P4, P5, P6) const, const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::StrictMock<Mock<R (C::*)(P1, P2, P3, P4, P5, P6) const, N> > > strictMock = bsl::make_shared<testing::StrictMock<Mock<R (C::*)(P1, P2, P3, P4, P5, P6) const, N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<Mock<R (C::*)(P1, P2, P3, P4, P5, P6) const, N> >(strictMock);
        }

        // Create a strict mock for a CONST member function with 7 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7>
        static bsl::shared_ptr<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7) const, N> > createMockStrict(R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7) const, const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::StrictMock<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7) const, N> > > strictMock = bsl::make_shared<testing::StrictMock<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7) const, N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7) const, N> >(strictMock);
        }

        // Create a strict mock for a CONST member function with 8 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8>
        static bsl::shared_ptr<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8) const, N> > createMockStrict(R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8) const, const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::StrictMock<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8) const, N> > > strictMock = bsl::make_shared<testing::StrictMock<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8) const, N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8) const, N> >(strictMock);
        }

        // Create a strict mock for a CONST member function with 9 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8,
            typename P9>
        static bsl::shared_ptr<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9) const, N> > createMockStrict(R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9) const, const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::StrictMock<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9) const, N> > > strictMock = bsl::make_shared<testing::StrictMock<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9) const, N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9) const, N> >(strictMock);
        }

        // Create a strict mock for a CONST member function with 10 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8,
            typename P9, typename P10>
        static bsl::shared_ptr<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10) const, N> > createMockStrict(R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10) const, const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::StrictMock<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10) const, N> > > strictMock = bsl::make_shared<testing::StrictMock<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10) const, N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10) const, N> >(strictMock);
        }

        // Create a strict mock for a CONST member function with 11 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8,
            typename P9, typename P10, typename P11>
        static bsl::shared_ptr<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11) const, N> > createMockStrict(R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11) const, const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::StrictMock<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11) const, N> > > strictMock = bsl::make_shared<testing::StrictMock<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11) const, N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11) const, N> >(strictMock);
        }

        // Create a strict mock for a CONST member function with 12 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8,
            typename P9, typename P10, typename P11, typename P12>
        static bsl::shared_ptr<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12) const, N> > createMockStrict(R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12) const, const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::StrictMock<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12) const, N> > > strictMock = bsl::make_shared<testing::StrictMock<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12) const, N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12) const, N> >(strictMock);
        }

        // Create a strict mock for a CONST member function with 13 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8,
            typename P9, typename P10, typename P11, typename P12, typename P13>
        static bsl::shared_ptr<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13) const, N> > createMockStrict(R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13) const, const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::StrictMock<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13) const, N> > > strictMock = bsl::make_shared<testing::StrictMock<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13) const, N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13) const, N> >(strictMock);
        }

        // Create a strict mock for a CONST member function with 14 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8,
            typename P9, typename P10, typename P11, typename P12, typename P13, typename P14>
        static bsl::shared_ptr<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14) const, N> > createMockStrict(R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14) const, const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::StrictMock<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14) const, N> > > strictMock = bsl::make_shared<testing::StrictMock<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14) const, N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14) const, N> >(strictMock);
        }

        // Create a strict mock for a CONST member function with 15 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8,
            typename P9, typename P10, typename P11, typename P12, typename P13, typename P14, typename P15>
        static bsl::shared_ptr<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15) const, N> > createMockStrict(R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15) const, const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::StrictMock<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15) const, N> > > strictMock = bsl::make_shared<testing::StrictMock<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15) const, N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15) const, N> >(strictMock);
        }

        // =========================================================================
        // createVirtualMockStrict - Non-const virtual member functions
        // =========================================================================

        // Create a strict mock for a NON-CONST virtual member function with 0 parameters
        template <int N, typename R, typename C>
        static bsl::shared_ptr<MockVirtual<R (C::*)(), N> > createVirtualMockStrict(
            R (C::*targetFunc)(), const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::StrictMock<MockVirtual<R (C::*)(), N> > > l_mockObj = bsl::make_shared<testing::StrictMock<MockVirtual<R (C::*)(), N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<MockVirtual<R (C::*)(), N> >(l_mockObj);
        }

        // Create a strict mock for a NON-CONST virtual member function with 1 parameter
        template <int N, typename R, typename C, typename P1>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1), N> > createVirtualMockStrict(
            R (C::*targetFunc)(P1), const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::StrictMock<MockVirtual<R (C::*)(P1), N> > > l_mockObj = bsl::make_shared<testing::StrictMock<MockVirtual<R (C::*)(P1), N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<MockVirtual<R (C::*)(P1), N> >(l_mockObj);
        }

        // Create a strict mock for a NON-CONST virtual member function with 2 parameters
        template <int N, typename R, typename C, typename P1, typename P2>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2), N> > createVirtualMockStrict(
            R (C::*targetFunc)(P1, P2), const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::StrictMock<MockVirtual<R (C::*)(P1, P2), N> > > l_mockObj = bsl::make_shared<testing::StrictMock<MockVirtual<R (C::*)(P1, P2), N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<MockVirtual<R (C::*)(P1, P2), N> >(l_mockObj);
        }

        // Create a strict mock for a NON-CONST virtual member function with 3 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3), N> > createVirtualMockStrict(
            R (C::*targetFunc)(P1, P2, P3), const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::StrictMock<MockVirtual<R (C::*)(P1, P2, P3), N> > > l_mockObj = bsl::make_shared<testing::StrictMock<MockVirtual<R (C::*)(P1, P2, P3), N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<MockVirtual<R (C::*)(P1, P2, P3), N> >(l_mockObj);
        }

        // Create a strict mock for a NON-CONST virtual member function with 4 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4), N> > createVirtualMockStrict(
            R (C::*targetFunc)(P1, P2, P3, P4), const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::StrictMock<MockVirtual<R (C::*)(P1, P2, P3, P4), N> > > l_mockObj = bsl::make_shared<testing::StrictMock<MockVirtual<R (C::*)(P1, P2, P3, P4), N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<MockVirtual<R (C::*)(P1, P2, P3, P4), N> >(l_mockObj);
        }

        // Create a strict mock for a NON-CONST virtual member function with 5 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5), N> > createVirtualMockStrict(
            R (C::*targetFunc)(P1, P2, P3, P4, P5), const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::StrictMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5), N> > > l_mockObj = bsl::make_shared<testing::StrictMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5), N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<MockVirtual<R (C::*)(P1, P2, P3, P4, P5), N> >(l_mockObj);
        }

        // Create a strict mock for a NON-CONST virtual member function with 6 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6), N> > createVirtualMockStrict(
            R (C::*targetFunc)(P1, P2, P3, P4, P5, P6), const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::StrictMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6), N> > > l_mockObj = bsl::make_shared<testing::StrictMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6), N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6), N> >(l_mockObj);
        }

        // Create a strict mock for a NON-CONST virtual member function with 7 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7), N> > createVirtualMockStrict(
            R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7), const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::StrictMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7), N> > > l_mockObj = bsl::make_shared<testing::StrictMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7), N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7), N> >(l_mockObj);
        }

        // Create a strict mock for a NON-CONST virtual member function with 8 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8), N> > createVirtualMockStrict(
            R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8), const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::StrictMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8), N> > > l_mockObj = bsl::make_shared<testing::StrictMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8), N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8), N> >(l_mockObj);
        }

        // Create a strict mock for a NON-CONST virtual member function with 9 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9), N> > createVirtualMockStrict(
            R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9), const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::StrictMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9), N> > > l_mockObj = bsl::make_shared<testing::StrictMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9), N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9), N> >(l_mockObj);
        }

        // Create a strict mock for a NON-CONST virtual member function with 10 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9, typename P10>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10), N> > createVirtualMockStrict(
            R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10), const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::StrictMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10), N> > > l_mockObj = bsl::make_shared<testing::StrictMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10), N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10), N> >(l_mockObj);
        }

        // Create a strict mock for a NON-CONST virtual member function with 11 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9, typename P10, typename P11>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11), N> > createVirtualMockStrict(
            R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11), const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::StrictMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11), N> > > l_mockObj = bsl::make_shared<testing::StrictMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11), N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11), N> >(l_mockObj);
        }

        // Create a strict mock for a NON-CONST virtual member function with 12 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9, typename P10, typename P11, typename P12>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12), N> > createVirtualMockStrict(
            R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12), const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::StrictMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12), N> > > l_mockObj = bsl::make_shared<testing::StrictMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12), N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12), N> >(l_mockObj);
        }

        // Create a strict mock for a NON-CONST virtual member function with 13 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13), N> > createVirtualMockStrict(
            R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13), const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::StrictMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13), N> > > l_mockObj = bsl::make_shared<testing::StrictMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13), N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13), N> >(l_mockObj);
        }

        // Create a strict mock for a NON-CONST virtual member function with 14 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13, typename P14>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14), N> > createVirtualMockStrict(
            R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14), const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::StrictMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14), N> > > l_mockObj = bsl::make_shared<testing::StrictMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14), N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14), N> >(l_mockObj);
        }

        // Create a strict mock for a NON-CONST virtual member function with 15 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13, typename P14, typename P15>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15), N> > createVirtualMockStrict(
            R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15), const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::StrictMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15), N> > > l_mockObj = bsl::make_shared<testing::StrictMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15), N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15), N> >(l_mockObj);
        }

        // =========================================================================
        // createVirtualMockStrict - Const virtual member functions
        // =========================================================================

        // Create a strict mock for a CONST virtual member function with 0 parameters
        template <int N, typename R, typename C>
        static bsl::shared_ptr<MockVirtual<R (C::*)() const, N> > createVirtualMockStrict(
            R (C::*targetFunc)() const, const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::StrictMock<MockVirtual<R (C::*)() const, N> > > l_mockObj = bsl::make_shared<testing::StrictMock<MockVirtual<R (C::*)() const, N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<MockVirtual<R (C::*)() const, N> >(l_mockObj);
        }

        // Create a strict mock for a CONST virtual member function with 1 parameter
        template <int N, typename R, typename C, typename P1>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1) const, N> > createVirtualMockStrict(
            R (C::*targetFunc)(P1) const, const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::StrictMock<MockVirtual<R (C::*)(P1) const, N> > > l_mockObj = bsl::make_shared<testing::StrictMock<MockVirtual<R (C::*)(P1) const, N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<MockVirtual<R (C::*)(P1) const, N> >(l_mockObj);
        }

        // Create a strict mock for a CONST virtual member function with 2 parameters
        template <int N, typename R, typename C, typename P1, typename P2>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2) const, N> > createVirtualMockStrict(
            R (C::*targetFunc)(P1, P2) const, const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::StrictMock<MockVirtual<R (C::*)(P1, P2) const, N> > > l_mockObj = bsl::make_shared<testing::StrictMock<MockVirtual<R (C::*)(P1, P2) const, N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<MockVirtual<R (C::*)(P1, P2) const, N> >(l_mockObj);
        }

        // Create a strict mock for a CONST virtual member function with 3 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3) const, N> > createVirtualMockStrict(
            R (C::*targetFunc)(P1, P2, P3) const, const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::StrictMock<MockVirtual<R (C::*)(P1, P2, P3) const, N> > > l_mockObj = bsl::make_shared<testing::StrictMock<MockVirtual<R (C::*)(P1, P2, P3) const, N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<MockVirtual<R (C::*)(P1, P2, P3) const, N> >(l_mockObj);
        }

        // Create a strict mock for a CONST virtual member function with 4 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4) const, N> > createVirtualMockStrict(
            R (C::*targetFunc)(P1, P2, P3, P4) const, const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::StrictMock<MockVirtual<R (C::*)(P1, P2, P3, P4) const, N> > > l_mockObj = bsl::make_shared<testing::StrictMock<MockVirtual<R (C::*)(P1, P2, P3, P4) const, N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<MockVirtual<R (C::*)(P1, P2, P3, P4) const, N> >(l_mockObj);
        }

        // Create a strict mock for a CONST virtual member function with 5 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5) const, N> > createVirtualMockStrict(
            R (C::*targetFunc)(P1, P2, P3, P4, P5) const, const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::StrictMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5) const, N> > > l_mockObj = bsl::make_shared<testing::StrictMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5) const, N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<MockVirtual<R (C::*)(P1, P2, P3, P4, P5) const, N> >(l_mockObj);
        }

        // Create a strict mock for a CONST virtual member function with 6 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6) const, N> > createVirtualMockStrict(
            R (C::*targetFunc)(P1, P2, P3, P4, P5, P6) const, const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::StrictMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6) const, N> > > l_mockObj = bsl::make_shared<testing::StrictMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6) const, N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6) const, N> >(l_mockObj);
        }

        // Create a strict mock for a CONST virtual member function with 7 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7) const, N> > createVirtualMockStrict(
            R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7) const, const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::StrictMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7) const, N> > > l_mockObj = bsl::make_shared<testing::StrictMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7) const, N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7) const, N> >(l_mockObj);
        }

        // Create a strict mock for a CONST virtual member function with 8 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8) const, N> > createVirtualMockStrict(
            R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8) const, const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::StrictMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8) const, N> > > l_mockObj = bsl::make_shared<testing::StrictMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8) const, N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8) const, N> >(l_mockObj);
        }

        // Create a strict mock for a CONST virtual member function with 9 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9) const, N> > createVirtualMockStrict(
            R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9) const, const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::StrictMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9) const, N> > > l_mockObj = bsl::make_shared<testing::StrictMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9) const, N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9) const, N> >(l_mockObj);
        }

        // Create a strict mock for a CONST virtual member function with 10 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9, typename P10>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10) const, N> > createVirtualMockStrict(
            R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10) const, const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::StrictMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10) const, N> > > l_mockObj = bsl::make_shared<testing::StrictMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10) const, N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10) const, N> >(l_mockObj);
        }

        // Create a strict mock for a CONST virtual member function with 11 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9, typename P10, typename P11>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11) const, N> > createVirtualMockStrict(
            R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11) const, const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::StrictMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11) const, N> > > l_mockObj = bsl::make_shared<testing::StrictMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11) const, N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11) const, N> >(l_mockObj);
        }

        // Create a strict mock for a CONST virtual member function with 12 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9, typename P10, typename P11, typename P12>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12) const, N> > createVirtualMockStrict(
            R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12) const, const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::StrictMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12) const, N> > > l_mockObj = bsl::make_shared<testing::StrictMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12) const, N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12) const, N> >(l_mockObj);
        }

        // Create a strict mock for a CONST virtual member function with 13 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13) const, N> > createVirtualMockStrict(
            R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13) const, const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::StrictMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13) const, N> > > l_mockObj = bsl::make_shared<testing::StrictMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13) const, N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13) const, N> >(l_mockObj);
        }

        // Create a strict mock for a CONST virtual member function with 14 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13, typename P14>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14) const, N> > createVirtualMockStrict(
            R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14) const, const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::StrictMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14) const, N> > > l_mockObj = bsl::make_shared<testing::StrictMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14) const, N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14) const, N> >(l_mockObj);
        }

        // Create a strict mock for a CONST virtual member function with 15 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13, typename P14, typename P15>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15) const, N> > createVirtualMockStrict(
            R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15) const, const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::StrictMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15) const, N> > > l_mockObj = bsl::make_shared<testing::StrictMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15) const, N> > >(targetFunc, funcName);
            return bsl::static_pointer_cast<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15) const, N> >(l_mockObj);
        }

        // =========================================================================
        // PMF-accepting with instance overloads (BONOBO_MOCK_VIRTUAL_ON)
        // =========================================================================

        // Create a strict mock with instance for a NON-CONST virtual member function with 0 parameters
        template <int N, typename R, typename C>
        static bsl::shared_ptr<MockVirtual<R (C::*)(), N> > createVirtualMockStrict(
            const C& inst, R (C::*targetFunc)(), const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::StrictMock<MockVirtual<R (C::*)(), N> > > l_mockObj = bsl::make_shared<testing::StrictMock<MockVirtual<R (C::*)(), N> > >(inst, targetFunc, funcName);
            return bsl::static_pointer_cast<MockVirtual<R (C::*)(), N> >(l_mockObj);
        }

        // Create a strict mock with instance for a NON-CONST virtual member function with 1 parameter
        template <int N, typename R, typename C, typename P1>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1), N> > createVirtualMockStrict(
            const C& inst, R (C::*targetFunc)(P1), const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::StrictMock<MockVirtual<R (C::*)(P1), N> > > l_mockObj = bsl::make_shared<testing::StrictMock<MockVirtual<R (C::*)(P1), N> > >(inst, targetFunc, funcName);
            return bsl::static_pointer_cast<MockVirtual<R (C::*)(P1), N> >(l_mockObj);
        }

        // Create a strict mock with instance for a NON-CONST virtual member function with 2 parameters
        template <int N, typename R, typename C, typename P1, typename P2>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2), N> > createVirtualMockStrict(
            const C& inst, R (C::*targetFunc)(P1, P2), const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::StrictMock<MockVirtual<R (C::*)(P1, P2), N> > > l_mockObj = bsl::make_shared<testing::StrictMock<MockVirtual<R (C::*)(P1, P2), N> > >(inst, targetFunc, funcName);
            return bsl::static_pointer_cast<MockVirtual<R (C::*)(P1, P2), N> >(l_mockObj);
        }

        // Create a strict mock with instance for a NON-CONST virtual member function with 3 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3), N> > createVirtualMockStrict(
            const C& inst, R (C::*targetFunc)(P1, P2, P3), const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::StrictMock<MockVirtual<R (C::*)(P1, P2, P3), N> > > l_mockObj = bsl::make_shared<testing::StrictMock<MockVirtual<R (C::*)(P1, P2, P3), N> > >(inst, targetFunc, funcName);
            return bsl::static_pointer_cast<MockVirtual<R (C::*)(P1, P2, P3), N> >(l_mockObj);
        }

        // Create a strict mock with instance for a NON-CONST virtual member function with 4 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4), N> > createVirtualMockStrict(
            const C& inst, R (C::*targetFunc)(P1, P2, P3, P4), const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::StrictMock<MockVirtual<R (C::*)(P1, P2, P3, P4), N> > > l_mockObj = bsl::make_shared<testing::StrictMock<MockVirtual<R (C::*)(P1, P2, P3, P4), N> > >(inst, targetFunc, funcName);
            return bsl::static_pointer_cast<MockVirtual<R (C::*)(P1, P2, P3, P4), N> >(l_mockObj);
        }

        // Create a strict mock with instance for a NON-CONST virtual member function with 5 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5), N> > createVirtualMockStrict(
            const C& inst, R (C::*targetFunc)(P1, P2, P3, P4, P5), const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::StrictMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5), N> > > l_mockObj = bsl::make_shared<testing::StrictMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5), N> > >(inst, targetFunc, funcName);
            return bsl::static_pointer_cast<MockVirtual<R (C::*)(P1, P2, P3, P4, P5), N> >(l_mockObj);
        }

        // Create a strict mock with instance for a NON-CONST virtual member function with 6 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6), N> > createVirtualMockStrict(
            const C& inst, R (C::*targetFunc)(P1, P2, P3, P4, P5, P6), const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::StrictMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6), N> > > l_mockObj = bsl::make_shared<testing::StrictMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6), N> > >(inst, targetFunc, funcName);
            return bsl::static_pointer_cast<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6), N> >(l_mockObj);
        }

        // Create a strict mock with instance for a NON-CONST virtual member function with 7 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7), N> > createVirtualMockStrict(
            const C& inst, R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7), const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::StrictMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7), N> > > l_mockObj = bsl::make_shared<testing::StrictMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7), N> > >(inst, targetFunc, funcName);
            return bsl::static_pointer_cast<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7), N> >(l_mockObj);
        }

        // Create a strict mock with instance for a NON-CONST virtual member function with 8 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8), N> > createVirtualMockStrict(
            const C& inst, R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8), const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::StrictMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8), N> > > l_mockObj = bsl::make_shared<testing::StrictMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8), N> > >(inst, targetFunc, funcName);
            return bsl::static_pointer_cast<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8), N> >(l_mockObj);
        }

        // Create a strict mock with instance for a NON-CONST virtual member function with 9 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9), N> > createVirtualMockStrict(
            const C& inst, R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9), const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::StrictMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9), N> > > l_mockObj = bsl::make_shared<testing::StrictMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9), N> > >(inst, targetFunc, funcName);
            return bsl::static_pointer_cast<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9), N> >(l_mockObj);
        }

        // Create a strict mock with instance for a NON-CONST virtual member function with 10 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9, typename P10>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10), N> > createVirtualMockStrict(
            const C& inst, R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10), const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::StrictMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10), N> > > l_mockObj = bsl::make_shared<testing::StrictMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10), N> > >(inst, targetFunc, funcName);
            return bsl::static_pointer_cast<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10), N> >(l_mockObj);
        }

        // Create a strict mock with instance for a NON-CONST virtual member function with 11 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9, typename P10, typename P11>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11), N> > createVirtualMockStrict(
            const C& inst, R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11), const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::StrictMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11), N> > > l_mockObj = bsl::make_shared<testing::StrictMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11), N> > >(inst, targetFunc, funcName);
            return bsl::static_pointer_cast<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11), N> >(l_mockObj);
        }

        // Create a strict mock with instance for a NON-CONST virtual member function with 12 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9, typename P10, typename P11, typename P12>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12), N> > createVirtualMockStrict(
            const C& inst, R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12), const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::StrictMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12), N> > > l_mockObj = bsl::make_shared<testing::StrictMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12), N> > >(inst, targetFunc, funcName);
            return bsl::static_pointer_cast<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12), N> >(l_mockObj);
        }

        // Create a strict mock with instance for a NON-CONST virtual member function with 13 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13), N> > createVirtualMockStrict(
            const C& inst, R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13), const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::StrictMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13), N> > > l_mockObj = bsl::make_shared<testing::StrictMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13), N> > >(inst, targetFunc, funcName);
            return bsl::static_pointer_cast<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13), N> >(l_mockObj);
        }

        // Create a strict mock with instance for a NON-CONST virtual member function with 14 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13, typename P14>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14), N> > createVirtualMockStrict(
            const C& inst, R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14), const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::StrictMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14), N> > > l_mockObj = bsl::make_shared<testing::StrictMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14), N> > >(inst, targetFunc, funcName);
            return bsl::static_pointer_cast<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14), N> >(l_mockObj);
        }

        // Create a strict mock with instance for a NON-CONST virtual member function with 15 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13, typename P14, typename P15>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15), N> > createVirtualMockStrict(
            const C& inst, R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15), const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::StrictMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15), N> > > l_mockObj = bsl::make_shared<testing::StrictMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15), N> > >(inst, targetFunc, funcName);
            return bsl::static_pointer_cast<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15), N> >(l_mockObj);
        }

        // Create a strict mock with instance for a CONST virtual member function with 0 parameters
        template <int N, typename R, typename C>
        static bsl::shared_ptr<MockVirtual<R (C::*)() const, N> > createVirtualMockStrict(
            const C& inst, R (C::*targetFunc)() const, const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::StrictMock<MockVirtual<R (C::*)() const, N> > > l_mockObj = bsl::make_shared<testing::StrictMock<MockVirtual<R (C::*)() const, N> > >(inst, targetFunc, funcName);
            return bsl::static_pointer_cast<MockVirtual<R (C::*)() const, N> >(l_mockObj);
        }

        // Create a strict mock with instance for a CONST virtual member function with 1 parameter
        template <int N, typename R, typename C, typename P1>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1) const, N> > createVirtualMockStrict(
            const C& inst, R (C::*targetFunc)(P1) const, const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::StrictMock<MockVirtual<R (C::*)(P1) const, N> > > l_mockObj = bsl::make_shared<testing::StrictMock<MockVirtual<R (C::*)(P1) const, N> > >(inst, targetFunc, funcName);
            return bsl::static_pointer_cast<MockVirtual<R (C::*)(P1) const, N> >(l_mockObj);
        }

        // Create a strict mock with instance for a CONST virtual member function with 2 parameters
        template <int N, typename R, typename C, typename P1, typename P2>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2) const, N> > createVirtualMockStrict(
            const C& inst, R (C::*targetFunc)(P1, P2) const, const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::StrictMock<MockVirtual<R (C::*)(P1, P2) const, N> > > l_mockObj = bsl::make_shared<testing::StrictMock<MockVirtual<R (C::*)(P1, P2) const, N> > >(inst, targetFunc, funcName);
            return bsl::static_pointer_cast<MockVirtual<R (C::*)(P1, P2) const, N> >(l_mockObj);
        }

        // Create a strict mock with instance for a CONST virtual member function with 3 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3) const, N> > createVirtualMockStrict(
            const C& inst, R (C::*targetFunc)(P1, P2, P3) const, const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::StrictMock<MockVirtual<R (C::*)(P1, P2, P3) const, N> > > l_mockObj = bsl::make_shared<testing::StrictMock<MockVirtual<R (C::*)(P1, P2, P3) const, N> > >(inst, targetFunc, funcName);
            return bsl::static_pointer_cast<MockVirtual<R (C::*)(P1, P2, P3) const, N> >(l_mockObj);
        }

        // Create a strict mock with instance for a CONST virtual member function with 4 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4) const, N> > createVirtualMockStrict(
            const C& inst, R (C::*targetFunc)(P1, P2, P3, P4) const, const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::StrictMock<MockVirtual<R (C::*)(P1, P2, P3, P4) const, N> > > l_mockObj = bsl::make_shared<testing::StrictMock<MockVirtual<R (C::*)(P1, P2, P3, P4) const, N> > >(inst, targetFunc, funcName);
            return bsl::static_pointer_cast<MockVirtual<R (C::*)(P1, P2, P3, P4) const, N> >(l_mockObj);
        }

        // Create a strict mock with instance for a CONST virtual member function with 5 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5) const, N> > createVirtualMockStrict(
            const C& inst, R (C::*targetFunc)(P1, P2, P3, P4, P5) const, const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::StrictMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5) const, N> > > l_mockObj = bsl::make_shared<testing::StrictMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5) const, N> > >(inst, targetFunc, funcName);
            return bsl::static_pointer_cast<MockVirtual<R (C::*)(P1, P2, P3, P4, P5) const, N> >(l_mockObj);
        }

        // Create a strict mock with instance for a CONST virtual member function with 6 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6) const, N> > createVirtualMockStrict(
            const C& inst, R (C::*targetFunc)(P1, P2, P3, P4, P5, P6) const, const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::StrictMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6) const, N> > > l_mockObj = bsl::make_shared<testing::StrictMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6) const, N> > >(inst, targetFunc, funcName);
            return bsl::static_pointer_cast<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6) const, N> >(l_mockObj);
        }

        // Create a strict mock with instance for a CONST virtual member function with 7 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7) const, N> > createVirtualMockStrict(
            const C& inst, R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7) const, const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::StrictMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7) const, N> > > l_mockObj = bsl::make_shared<testing::StrictMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7) const, N> > >(inst, targetFunc, funcName);
            return bsl::static_pointer_cast<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7) const, N> >(l_mockObj);
        }

        // Create a strict mock with instance for a CONST virtual member function with 8 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8) const, N> > createVirtualMockStrict(
            const C& inst, R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8) const, const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::StrictMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8) const, N> > > l_mockObj = bsl::make_shared<testing::StrictMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8) const, N> > >(inst, targetFunc, funcName);
            return bsl::static_pointer_cast<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8) const, N> >(l_mockObj);
        }

        // Create a strict mock with instance for a CONST virtual member function with 9 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9) const, N> > createVirtualMockStrict(
            const C& inst, R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9) const, const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::StrictMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9) const, N> > > l_mockObj = bsl::make_shared<testing::StrictMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9) const, N> > >(inst, targetFunc, funcName);
            return bsl::static_pointer_cast<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9) const, N> >(l_mockObj);
        }

        // Create a strict mock with instance for a CONST virtual member function with 10 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9, typename P10>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10) const, N> > createVirtualMockStrict(
            const C& inst, R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10) const, const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::StrictMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10) const, N> > > l_mockObj = bsl::make_shared<testing::StrictMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10) const, N> > >(inst, targetFunc, funcName);
            return bsl::static_pointer_cast<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10) const, N> >(l_mockObj);
        }

        // Create a strict mock with instance for a CONST virtual member function with 11 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9, typename P10, typename P11>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11) const, N> > createVirtualMockStrict(
            const C& inst, R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11) const, const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::StrictMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11) const, N> > > l_mockObj = bsl::make_shared<testing::StrictMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11) const, N> > >(inst, targetFunc, funcName);
            return bsl::static_pointer_cast<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11) const, N> >(l_mockObj);
        }

        // Create a strict mock with instance for a CONST virtual member function with 12 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9, typename P10, typename P11, typename P12>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12) const, N> > createVirtualMockStrict(
            const C& inst, R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12) const, const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::StrictMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12) const, N> > > l_mockObj = bsl::make_shared<testing::StrictMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12) const, N> > >(inst, targetFunc, funcName);
            return bsl::static_pointer_cast<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12) const, N> >(l_mockObj);
        }

        // Create a strict mock with instance for a CONST virtual member function with 13 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13) const, N> > createVirtualMockStrict(
            const C& inst, R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13) const, const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::StrictMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13) const, N> > > l_mockObj = bsl::make_shared<testing::StrictMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13) const, N> > >(inst, targetFunc, funcName);
            return bsl::static_pointer_cast<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13) const, N> >(l_mockObj);
        }

        // Create a strict mock with instance for a CONST virtual member function with 14 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13, typename P14>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14) const, N> > createVirtualMockStrict(
            const C& inst, R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14) const, const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::StrictMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14) const, N> > > l_mockObj = bsl::make_shared<testing::StrictMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14) const, N> > >(inst, targetFunc, funcName);
            return bsl::static_pointer_cast<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14) const, N> >(l_mockObj);
        }

        // Create a strict mock with instance for a CONST virtual member function with 15 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13, typename P14, typename P15>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15) const, N> > createVirtualMockStrict(
            const C& inst, R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15) const, const bsl::string& funcName)
        {
            bsl::shared_ptr<testing::StrictMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15) const, N> > > l_mockObj = bsl::make_shared<testing::StrictMock<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15) const, N> > >(inst, targetFunc, funcName);
            return bsl::static_pointer_cast<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15) const, N> >(l_mockObj);
        }

        // =========================================================================
        // createPrivateStaticMockStrict - Private static functions
        // =========================================================================

        // Create a strict mock for a private static function with 0 parameters
        template <int N, typename R>
        static bsl::shared_ptr<Mock<R(), N> > createPrivateStaticMockStrict(R targetFunc(), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            bsl::shared_ptr<testing::StrictMock<Mock<R(), N> > > strictMock = bsl::make_shared<testing::StrictMock<Mock<R(), N> > >(funcName);
            return bsl::static_pointer_cast<Mock<R(), N> >(strictMock);
        }

        // Create a strict mock for a private static function with 1 parameter
        template <int N, typename R, typename P1>
        static bsl::shared_ptr<Mock<R(P1), N> > createPrivateStaticMockStrict(R targetFunc(P1), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            bsl::shared_ptr<testing::StrictMock<Mock<R(P1), N> > > strictMock = bsl::make_shared<testing::StrictMock<Mock<R(P1), N> > >(funcName);
            return bsl::static_pointer_cast<Mock<R(P1), N> >(strictMock);
        }

        // Create a strict mock for a private static function with 2 parameters
        template <int N, typename R, typename P1, typename P2>
        static bsl::shared_ptr<Mock<R(P1, P2), N> > createPrivateStaticMockStrict(R targetFunc(P1, P2), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            bsl::shared_ptr<testing::StrictMock<Mock<R(P1, P2), N> > > strictMock = bsl::make_shared<testing::StrictMock<Mock<R(P1, P2), N> > >(funcName);
            return bsl::static_pointer_cast<Mock<R(P1, P2), N> >(strictMock);
        }

        // Create a strict mock for a private static function with 3 parameters
        template <int N, typename R, typename P1, typename P2, typename P3>
        static bsl::shared_ptr<Mock<R(P1, P2, P3), N> > createPrivateStaticMockStrict(R targetFunc(P1, P2, P3), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            bsl::shared_ptr<testing::StrictMock<Mock<R(P1, P2, P3), N> > > strictMock = bsl::make_shared<testing::StrictMock<Mock<R(P1, P2, P3), N> > >(funcName);
            return bsl::static_pointer_cast<Mock<R(P1, P2, P3), N> >(strictMock);
        }

        // Create a strict mock for a private static function with 4 parameters
        template <int N, typename R, typename P1, typename P2, typename P3, typename P4>
        static bsl::shared_ptr<Mock<R(P1, P2, P3, P4), N> > createPrivateStaticMockStrict(R targetFunc(P1, P2, P3, P4), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            bsl::shared_ptr<testing::StrictMock<Mock<R(P1, P2, P3, P4), N> > > strictMock = bsl::make_shared<testing::StrictMock<Mock<R(P1, P2, P3, P4), N> > >(funcName);
            return bsl::static_pointer_cast<Mock<R(P1, P2, P3, P4), N> >(strictMock);
        }

        // Create a strict mock for a private static function with 5 parameters
        template <int N, typename R, typename P1, typename P2, typename P3, typename P4, typename P5>
        static bsl::shared_ptr<Mock<R(P1, P2, P3, P4, P5), N> > createPrivateStaticMockStrict(R targetFunc(P1, P2, P3, P4, P5), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            bsl::shared_ptr<testing::StrictMock<Mock<R(P1, P2, P3, P4, P5), N> > > strictMock = bsl::make_shared<testing::StrictMock<Mock<R(P1, P2, P3, P4, P5), N> > >(funcName);
            return bsl::static_pointer_cast<Mock<R(P1, P2, P3, P4, P5), N> >(strictMock);
        }

        // Create a strict mock for a private static function with 6 parameters
        template <int N, typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6>
        static bsl::shared_ptr<Mock<R(P1, P2, P3, P4, P5, P6), N> > createPrivateStaticMockStrict(R targetFunc(P1, P2, P3, P4, P5, P6), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            bsl::shared_ptr<testing::StrictMock<Mock<R(P1, P2, P3, P4, P5, P6), N> > > strictMock = bsl::make_shared<testing::StrictMock<Mock<R(P1, P2, P3, P4, P5, P6), N> > >(funcName);
            return bsl::static_pointer_cast<Mock<R(P1, P2, P3, P4, P5, P6), N> >(strictMock);
        }

        // Create a strict mock for a private static function with 7 parameters
        template <int N, typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7>
        static bsl::shared_ptr<Mock<R(P1, P2, P3, P4, P5, P6, P7), N> > createPrivateStaticMockStrict(
            R targetFunc(P1, P2, P3, P4, P5, P6, P7), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            bsl::shared_ptr<testing::StrictMock<Mock<R(P1, P2, P3, P4, P5, P6, P7), N> > > strictMock = bsl::make_shared<testing::StrictMock<Mock<R(P1, P2, P3, P4, P5, P6, P7), N> > >(funcName);
            return bsl::static_pointer_cast<Mock<R(P1, P2, P3, P4, P5, P6, P7), N> >(strictMock);
        }

        // Create a strict mock for a private static function with 8 parameters
        template <int N, typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
            typename P7, typename P8>
        static bsl::shared_ptr<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8), N> > createPrivateStaticMockStrict(
            R targetFunc(P1, P2, P3, P4, P5, P6, P7, P8), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            bsl::shared_ptr<testing::StrictMock<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8), N> > > strictMock = bsl::make_shared<testing::StrictMock<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8), N> > >(funcName);
            return bsl::static_pointer_cast<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8), N> >(strictMock);
        }

        // Create a strict mock for a private static function with 9 parameters
        template <int N, typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
            typename P7, typename P8, typename P9>
        static bsl::shared_ptr<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9), N> > createPrivateStaticMockStrict(
            R targetFunc(P1, P2, P3, P4, P5, P6, P7, P8, P9), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            bsl::shared_ptr<testing::StrictMock<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9), N> > > strictMock = bsl::make_shared<testing::StrictMock<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9), N> > >(funcName);
            return bsl::static_pointer_cast<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9), N> >(strictMock);
        }

        // Create a strict mock for a private static function with 10 parameters
        template <int N, typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
            typename P7, typename P8, typename P9, typename P10>
        static bsl::shared_ptr<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10), N> > createPrivateStaticMockStrict(
            R targetFunc(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            bsl::shared_ptr<testing::StrictMock<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10), N> > > strictMock = bsl::make_shared<testing::StrictMock<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10), N> > >(funcName);
            return bsl::static_pointer_cast<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10), N> >(strictMock);
        }

        // Create a strict mock for a private static function with 11 parameters
        template <int N, typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
            typename P7, typename P8, typename P9, typename P10, typename P11>
        static bsl::shared_ptr<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11), N> > createPrivateStaticMockStrict(
            R targetFunc(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            bsl::shared_ptr<testing::StrictMock<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11), N> > > strictMock = bsl::make_shared<testing::StrictMock<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11), N> > >(funcName);
            return bsl::static_pointer_cast<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11), N> >(strictMock);
        }

        // Create a strict mock for a private static function with 12 parameters
        template <int N, typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
            typename P7, typename P8, typename P9, typename P10, typename P11, typename P12>
        static bsl::shared_ptr<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12), N> > createPrivateStaticMockStrict(
            R targetFunc(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            bsl::shared_ptr<testing::StrictMock<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12), N> > > strictMock = bsl::make_shared<testing::StrictMock<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12), N> > >(funcName);
            return bsl::static_pointer_cast<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12), N> >(strictMock);
        }

        // Create a strict mock for a private static function with 13 parameters
        template <int N, typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
            typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13>
        static bsl::shared_ptr<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13), N> > createPrivateStaticMockStrict(
            R targetFunc(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            bsl::shared_ptr<testing::StrictMock<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13), N> > > strictMock = bsl::make_shared<testing::StrictMock<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13), N> > >(funcName);
            return bsl::static_pointer_cast<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13), N> >(strictMock);
        }

        // Create a strict mock for a private static function with 14 parameters
        template <int N, typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
            typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13, typename P14>
        static bsl::shared_ptr<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14), N> > createPrivateStaticMockStrict(
            R targetFunc(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            bsl::shared_ptr<testing::StrictMock<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14), N> > > strictMock = bsl::make_shared<testing::StrictMock<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14), N> > >(funcName);
            return bsl::static_pointer_cast<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14), N> >(strictMock);
        }

        // Create a strict mock for a private static function with 15 parameters
        template <int N, typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
            typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13, typename P14, typename P15>
        static bsl::shared_ptr<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15), N> > createPrivateStaticMockStrict(
            R targetFunc(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            bsl::shared_ptr<testing::StrictMock<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15), N> > > strictMock = bsl::make_shared<testing::StrictMock<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15), N> > >(funcName);
            return bsl::static_pointer_cast<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15), N> >(strictMock);
        }

        // =========================================================================
        // createPrivateMockStrict - Non-const private member functions
        // =========================================================================

        // Create a strict mock for a non-const private member function with 0 parameters
        template <int N, typename C, typename R>
        static bsl::shared_ptr<MockPrivate<R (C::*)(), N> > createPrivateMockStrict(R targetFunc(), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            bsl::shared_ptr<testing::StrictMock<MockPrivate<R (C::*)(), N> > > l_mockObj = bsl::make_shared<testing::StrictMock<MockPrivate<R (C::*)(), N> > >(funcName);
            return bsl::static_pointer_cast<MockPrivate<R (C::*)(), N> >(l_mockObj);
        }

        // Create a strict mock for a non-const private member function with 1 parameter
        template <int N, typename C, typename R, typename P1>
        static bsl::shared_ptr<MockPrivate<R (C::*)(P1), N> > createPrivateMockStrict(R targetFunc(P1), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            bsl::shared_ptr<testing::StrictMock<MockPrivate<R (C::*)(P1), N> > > l_mockObj = bsl::make_shared<testing::StrictMock<MockPrivate<R (C::*)(P1), N> > >(funcName);
            return bsl::static_pointer_cast<MockPrivate<R (C::*)(P1), N> >(l_mockObj);
        }

        // Create a strict mock for a non-const private member function with 2 parameters
        template <int N, typename C, typename R, typename P1, typename P2>
        static bsl::shared_ptr<MockPrivate<R (C::*)(P1, P2), N> > createPrivateMockStrict(R targetFunc(P1, P2), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            bsl::shared_ptr<testing::StrictMock<MockPrivate<R (C::*)(P1, P2), N> > > l_mockObj = bsl::make_shared<testing::StrictMock<MockPrivate<R (C::*)(P1, P2), N> > >(funcName);
            return bsl::static_pointer_cast<MockPrivate<R (C::*)(P1, P2), N> >(l_mockObj);
        }

        // Create a strict mock for a non-const private member function with 3 parameters
        template <int N, typename C, typename R, typename P1, typename P2, typename P3>
        static bsl::shared_ptr<MockPrivate<R (C::*)(P1, P2, P3), N> > createPrivateMockStrict(R targetFunc(P1, P2, P3), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            bsl::shared_ptr<testing::StrictMock<MockPrivate<R (C::*)(P1, P2, P3), N> > > l_mockObj = bsl::make_shared<testing::StrictMock<MockPrivate<R (C::*)(P1, P2, P3), N> > >(funcName);
            return bsl::static_pointer_cast<MockPrivate<R (C::*)(P1, P2, P3), N> >(l_mockObj);
        }

        // Create a strict mock for a non-const private member function with 4 parameters
        template <int N, typename C, typename R, typename P1, typename P2, typename P3, typename P4>
        static bsl::shared_ptr<MockPrivate<R (C::*)(P1, P2, P3, P4), N> > createPrivateMockStrict(R targetFunc(P1, P2, P3, P4), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            bsl::shared_ptr<testing::StrictMock<MockPrivate<R (C::*)(P1, P2, P3, P4), N> > > l_mockObj = bsl::make_shared<testing::StrictMock<MockPrivate<R (C::*)(P1, P2, P3, P4), N> > >(funcName);
            return bsl::static_pointer_cast<MockPrivate<R (C::*)(P1, P2, P3, P4), N> >(l_mockObj);
        }

        // Create a strict mock for a non-const private member function with 5 parameters
        template <int N, typename C, typename R, typename P1, typename P2, typename P3, typename P4, typename P5>
        static bsl::shared_ptr<MockPrivate<R (C::*)(P1, P2, P3, P4, P5), N> > createPrivateMockStrict(R targetFunc(P1, P2, P3, P4, P5), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            bsl::shared_ptr<testing::StrictMock<MockPrivate<R (C::*)(P1, P2, P3, P4, P5), N> > > l_mockObj = bsl::make_shared<testing::StrictMock<MockPrivate<R (C::*)(P1, P2, P3, P4, P5), N> > >(funcName);
            return bsl::static_pointer_cast<MockPrivate<R (C::*)(P1, P2, P3, P4, P5), N> >(l_mockObj);
        }

        // Create a strict mock for a non-const private member function with 6 parameters
        template <int N, typename C, typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6>
        static bsl::shared_ptr<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6), N> > createPrivateMockStrict(R targetFunc(P1, P2, P3, P4, P5, P6), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            bsl::shared_ptr<testing::StrictMock<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6), N> > > l_mockObj = bsl::make_shared<testing::StrictMock<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6), N> > >(funcName);
            return bsl::static_pointer_cast<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6), N> >(l_mockObj);
        }

        // Create a strict mock for a non-const private member function with 7 parameters
        template <int N, typename C, typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7>
        static bsl::shared_ptr<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7), N> > createPrivateMockStrict(
            R targetFunc(P1, P2, P3, P4, P5, P6, P7), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            bsl::shared_ptr<testing::StrictMock<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7), N> > > l_mockObj = bsl::make_shared<testing::StrictMock<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7), N> > >(funcName);
            return bsl::static_pointer_cast<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7), N> >(l_mockObj);
        }

        // Create a strict mock for a non-const private member function with 8 parameters
        template <int N, typename C, typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
            typename P7, typename P8>
        static bsl::shared_ptr<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8), N> > createPrivateMockStrict(
            R targetFunc(P1, P2, P3, P4, P5, P6, P7, P8), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            bsl::shared_ptr<testing::StrictMock<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8), N> > > l_mockObj = bsl::make_shared<testing::StrictMock<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8), N> > >(funcName);
            return bsl::static_pointer_cast<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8), N> >(l_mockObj);
        }

        // Create a strict mock for a non-const private member function with 9 parameters
        template <int N, typename C, typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
            typename P7, typename P8, typename P9>
        static bsl::shared_ptr<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9), N> > createPrivateMockStrict(
            R targetFunc(P1, P2, P3, P4, P5, P6, P7, P8, P9), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            bsl::shared_ptr<testing::StrictMock<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9), N> > > l_mockObj = bsl::make_shared<testing::StrictMock<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9), N> > >(funcName);
            return bsl::static_pointer_cast<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9), N> >(l_mockObj);
        }

        // Create a strict mock for a non-const private member function with 10 parameters
        template <int N, typename C, typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
            typename P7, typename P8, typename P9, typename P10>
        static bsl::shared_ptr<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10), N> > createPrivateMockStrict(
            R targetFunc(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            bsl::shared_ptr<testing::StrictMock<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10), N> > > l_mockObj = bsl::make_shared<testing::StrictMock<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10), N> > >(funcName);
            return bsl::static_pointer_cast<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10), N> >(l_mockObj);
        }

        // Create a strict mock for a non-const private member function with 11 parameters
        template <int N, typename C, typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
            typename P7, typename P8, typename P9, typename P10, typename P11>
        static bsl::shared_ptr<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11), N> > createPrivateMockStrict(
            R targetFunc(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            bsl::shared_ptr<testing::StrictMock<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11), N> > > l_mockObj = bsl::make_shared<testing::StrictMock<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11), N> > >(funcName);
            return bsl::static_pointer_cast<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11), N> >(l_mockObj);
        }

        // Create a strict mock for a non-const private member function with 12 parameters
        template <int N, typename C, typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
            typename P7, typename P8, typename P9, typename P10, typename P11, typename P12>
        static bsl::shared_ptr<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12), N> > createPrivateMockStrict(
            R targetFunc(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            bsl::shared_ptr<testing::StrictMock<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12), N> > > l_mockObj = bsl::make_shared<testing::StrictMock<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12), N> > >(funcName);
            return bsl::static_pointer_cast<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12), N> >(l_mockObj);
        }

        // Create a strict mock for a non-const private member function with 13 parameters
        template <int N, typename C, typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
            typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13>
        static bsl::shared_ptr<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13), N> > createPrivateMockStrict(
            R targetFunc(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            bsl::shared_ptr<testing::StrictMock<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13), N> > > l_mockObj = bsl::make_shared<testing::StrictMock<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13), N> > >(funcName);
            return bsl::static_pointer_cast<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13), N> >(l_mockObj);
        }

        // Create a strict mock for a non-const private member function with 14 parameters
        template <int N, typename C, typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
            typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13, typename P14>
        static bsl::shared_ptr<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14), N> > createPrivateMockStrict(
            R targetFunc(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            bsl::shared_ptr<testing::StrictMock<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14), N> > > l_mockObj = bsl::make_shared<testing::StrictMock<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14), N> > >(funcName);
            return bsl::static_pointer_cast<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14), N> >(l_mockObj);
        }

        // Create a strict mock for a non-const private member function with 15 parameters
        template <int N, typename C, typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
            typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13, typename P14, typename P15>
        static bsl::shared_ptr<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15), N> > createPrivateMockStrict(
            R targetFunc(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            bsl::shared_ptr<testing::StrictMock<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15), N> > > l_mockObj = bsl::make_shared<testing::StrictMock<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15), N> > >(funcName);
            return bsl::static_pointer_cast<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15), N> >(l_mockObj);
        }

        // =========================================================================
        // createPrivateMockStrictConst - Const private member functions
        // =========================================================================

        // Create a strict mock for a const private member function with 0 parameters
        template <int N, typename C, typename R>
        static bsl::shared_ptr<MockPrivate<R (C::*)() const, N> > createPrivateMockStrictConst(R targetFunc(), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            bsl::shared_ptr<testing::StrictMock<MockPrivate<R (C::*)() const, N> > > l_mockObj = bsl::make_shared<testing::StrictMock<MockPrivate<R (C::*)() const, N> > >(funcName);
            return bsl::static_pointer_cast<MockPrivate<R (C::*)() const, N> >(l_mockObj);
        }

        // Create a strict mock for a const private member function with 1 parameter
        template <int N, typename C, typename R, typename P1>
        static bsl::shared_ptr<MockPrivate<R (C::*)(P1) const, N> > createPrivateMockStrictConst(R targetFunc(P1), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            bsl::shared_ptr<testing::StrictMock<MockPrivate<R (C::*)(P1) const, N> > > l_mockObj = bsl::make_shared<testing::StrictMock<MockPrivate<R (C::*)(P1) const, N> > >(funcName);
            return bsl::static_pointer_cast<MockPrivate<R (C::*)(P1) const, N> >(l_mockObj);
        }

        // Create a strict mock for a const private member function with 2 parameters
        template <int N, typename C, typename R, typename P1, typename P2>
        static bsl::shared_ptr<MockPrivate<R (C::*)(P1, P2) const, N> > createPrivateMockStrictConst(R targetFunc(P1, P2), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            bsl::shared_ptr<testing::StrictMock<MockPrivate<R (C::*)(P1, P2) const, N> > > l_mockObj = bsl::make_shared<testing::StrictMock<MockPrivate<R (C::*)(P1, P2) const, N> > >(funcName);
            return bsl::static_pointer_cast<MockPrivate<R (C::*)(P1, P2) const, N> >(l_mockObj);
        }

        // Create a strict mock for a const private member function with 3 parameters
        template <int N, typename C, typename R, typename P1, typename P2, typename P3>
        static bsl::shared_ptr<MockPrivate<R (C::*)(P1, P2, P3) const, N> > createPrivateMockStrictConst(R targetFunc(P1, P2, P3), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            bsl::shared_ptr<testing::StrictMock<MockPrivate<R (C::*)(P1, P2, P3) const, N> > > l_mockObj = bsl::make_shared<testing::StrictMock<MockPrivate<R (C::*)(P1, P2, P3) const, N> > >(funcName);
            return bsl::static_pointer_cast<MockPrivate<R (C::*)(P1, P2, P3) const, N> >(l_mockObj);
        }

        // Create a strict mock for a const private member function with 4 parameters
        template <int N, typename C, typename R, typename P1, typename P2, typename P3, typename P4>
        static bsl::shared_ptr<MockPrivate<R (C::*)(P1, P2, P3, P4) const, N> > createPrivateMockStrictConst(R targetFunc(P1, P2, P3, P4), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            bsl::shared_ptr<testing::StrictMock<MockPrivate<R (C::*)(P1, P2, P3, P4) const, N> > > l_mockObj = bsl::make_shared<testing::StrictMock<MockPrivate<R (C::*)(P1, P2, P3, P4) const, N> > >(funcName);
            return bsl::static_pointer_cast<MockPrivate<R (C::*)(P1, P2, P3, P4) const, N> >(l_mockObj);
        }

        // Create a strict mock for a const private member function with 5 parameters
        template <int N, typename C, typename R, typename P1, typename P2, typename P3, typename P4, typename P5>
        static bsl::shared_ptr<MockPrivate<R (C::*)(P1, P2, P3, P4, P5) const, N> > createPrivateMockStrictConst(R targetFunc(P1, P2, P3, P4, P5), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            bsl::shared_ptr<testing::StrictMock<MockPrivate<R (C::*)(P1, P2, P3, P4, P5) const, N> > > l_mockObj = bsl::make_shared<testing::StrictMock<MockPrivate<R (C::*)(P1, P2, P3, P4, P5) const, N> > >(funcName);
            return bsl::static_pointer_cast<MockPrivate<R (C::*)(P1, P2, P3, P4, P5) const, N> >(l_mockObj);
        }

        // Create a strict mock for a const private member function with 6 parameters
        template <int N, typename C, typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6>
        static bsl::shared_ptr<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6) const, N> > createPrivateMockStrictConst(R targetFunc(P1, P2, P3, P4, P5, P6), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            bsl::shared_ptr<testing::StrictMock<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6) const, N> > > l_mockObj = bsl::make_shared<testing::StrictMock<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6) const, N> > >(funcName);
            return bsl::static_pointer_cast<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6) const, N> >(l_mockObj);
        }

        // Create a strict mock for a const private member function with 7 parameters
        template <int N, typename C, typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7>
        static bsl::shared_ptr<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7) const, N> > createPrivateMockStrictConst(
            R targetFunc(P1, P2, P3, P4, P5, P6, P7), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            bsl::shared_ptr<testing::StrictMock<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7) const, N> > > l_mockObj = bsl::make_shared<testing::StrictMock<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7) const, N> > >(funcName);
            return bsl::static_pointer_cast<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7) const, N> >(l_mockObj);
        }

        // Create a strict mock for a const private member function with 8 parameters
        template <int N, typename C, typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
            typename P7, typename P8>
        static bsl::shared_ptr<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8) const, N> > createPrivateMockStrictConst(
            R targetFunc(P1, P2, P3, P4, P5, P6, P7, P8), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            bsl::shared_ptr<testing::StrictMock<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8) const, N> > > l_mockObj = bsl::make_shared<testing::StrictMock<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8) const, N> > >(funcName);
            return bsl::static_pointer_cast<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8) const, N> >(l_mockObj);
        }

        // Create a strict mock for a const private member function with 9 parameters
        template <int N, typename C, typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
            typename P7, typename P8, typename P9>
        static bsl::shared_ptr<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9) const, N> > createPrivateMockStrictConst(
            R targetFunc(P1, P2, P3, P4, P5, P6, P7, P8, P9), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            bsl::shared_ptr<testing::StrictMock<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9) const, N> > > l_mockObj = bsl::make_shared<testing::StrictMock<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9) const, N> > >(funcName);
            return bsl::static_pointer_cast<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9) const, N> >(l_mockObj);
        }

        // Create a strict mock for a const private member function with 10 parameters
        template <int N, typename C, typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
            typename P7, typename P8, typename P9, typename P10>
        static bsl::shared_ptr<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10) const, N> > createPrivateMockStrictConst(
            R targetFunc(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            bsl::shared_ptr<testing::StrictMock<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10) const, N> > > l_mockObj = bsl::make_shared<testing::StrictMock<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10) const, N> > >(funcName);
            return bsl::static_pointer_cast<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10) const, N> >(l_mockObj);
        }

        // Create a strict mock for a const private member function with 11 parameters
        template <int N, typename C, typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
            typename P7, typename P8, typename P9, typename P10, typename P11>
        static bsl::shared_ptr<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11) const, N> > createPrivateMockStrictConst(
            R targetFunc(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            bsl::shared_ptr<testing::StrictMock<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11) const, N> > > l_mockObj = bsl::make_shared<testing::StrictMock<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11) const, N> > >(funcName);
            return bsl::static_pointer_cast<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11) const, N> >(l_mockObj);
        }

        // Create a strict mock for a const private member function with 12 parameters
        template <int N, typename C, typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
            typename P7, typename P8, typename P9, typename P10, typename P11, typename P12>
        static bsl::shared_ptr<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12) const, N> > createPrivateMockStrictConst(
            R targetFunc(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            bsl::shared_ptr<testing::StrictMock<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12) const, N> > > l_mockObj = bsl::make_shared<testing::StrictMock<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12) const, N> > >(funcName);
            return bsl::static_pointer_cast<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12) const, N> >(l_mockObj);
        }

        // Create a strict mock for a const private member function with 13 parameters
        template <int N, typename C, typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
            typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13>
        static bsl::shared_ptr<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13) const, N> > createPrivateMockStrictConst(
            R targetFunc(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            bsl::shared_ptr<testing::StrictMock<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13) const, N> > > l_mockObj = bsl::make_shared<testing::StrictMock<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13) const, N> > >(funcName);
            return bsl::static_pointer_cast<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13) const, N> >(l_mockObj);
        }

        // Create a strict mock for a const private member function with 14 parameters
        template <int N, typename C, typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
            typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13, typename P14>
        static bsl::shared_ptr<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14) const, N> > createPrivateMockStrictConst(
            R targetFunc(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            bsl::shared_ptr<testing::StrictMock<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14) const, N> > > l_mockObj = bsl::make_shared<testing::StrictMock<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14) const, N> > >(funcName);
            return bsl::static_pointer_cast<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14) const, N> >(l_mockObj);
        }

        // Create a strict mock for a const private member function with 15 parameters
        template <int N, typename C, typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
            typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13, typename P14, typename P15>
        static bsl::shared_ptr<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15) const, N> > createPrivateMockStrictConst(
            R targetFunc(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            bsl::shared_ptr<testing::StrictMock<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15) const, N> > > l_mockObj = bsl::make_shared<testing::StrictMock<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15) const, N> > >(funcName);
            return bsl::static_pointer_cast<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15) const, N> >(l_mockObj);
        }
    };

} // bonobomock
} // BloombergLP

#endif
