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

#ifndef INCLUDED_BONOBOMOCK_INTERNAL_CREATOR_CPP03
#define INCLUDED_BONOBOMOCK_INTERNAL_CREATOR_CPP03

#if !defined(INCLUDED_BONOBOMOCK_API) && !defined(BONOBO_MOCK_BUILDING_LIBRARY)
    #error "This is a private header. Directly including it is a contract violation and undefined behavior."
#endif

#include <bonobomock_internal_mocker_cpp03.h>
#include <bonobomock_internal_private_address_resolver.h>

#include <bsl_memory.h>
#include <bsl_string.h>

namespace BloombergLP {
namespace bonobomock {

    class MockCreator {
    public:
        // =========================================================================
        // createMock - Global/free/static/fortran functions
        // =========================================================================

        // Create a mock for a global/free or fortran, or static function with 0 parameters
        template <int N, typename R>
        static bsl::shared_ptr<Mock<R(), N> > createMock(R targetFunc(), const bsl::string& funcName)
        {
            // Create the Mock object
            bsl::shared_ptr<Mock<R(), N> > l_mockObj = bsl::make_shared<Mock<R(), N> >(targetFunc, funcName);

            return l_mockObj;
        }

        // Create a mock for a global/free or fortran, or static function with 1 parameter
        template <int N, typename R, typename P1>
        static bsl::shared_ptr<Mock<R(P1), N> > createMock(R targetFunc(P1), const bsl::string& funcName)
        {
            // Create the Mock object
            bsl::shared_ptr<Mock<R(P1), N> > l_mockObj = bsl::make_shared<Mock<R(P1), N> >(targetFunc, funcName);

            return l_mockObj;
        }

        // Create a mock for a global/free or fortran, or static function with 2 parameters
        template <int N, typename R, typename P1, typename P2>
        static bsl::shared_ptr<Mock<R(P1, P2), N> > createMock(R targetFunc(P1, P2), const bsl::string& funcName)
        {
            // Create the Mock object
            bsl::shared_ptr<Mock<R(P1, P2), N> > l_mockObj = bsl::make_shared<Mock<R(P1, P2), N> >(targetFunc, funcName);

            return l_mockObj;
        }

        // Create a mock for a global/free or fortran, or static function with 3 parameters
        template <int N, typename R, typename P1, typename P2, typename P3>
        static bsl::shared_ptr<Mock<R(P1, P2, P3), N> > createMock(R targetFunc(P1, P2, P3), const bsl::string& funcName)
        {
            // Create the Mock object
            bsl::shared_ptr<Mock<R(P1, P2, P3), N> > l_mockObj = bsl::make_shared<Mock<R(P1, P2, P3), N> >(targetFunc, funcName);

            return l_mockObj;
        }

        // Create a mock for a global/free or fortran, or static function with 4 parameters
        template <int N, typename R, typename P1, typename P2, typename P3, typename P4>
        static bsl::shared_ptr<Mock<R(P1, P2, P3, P4), N> > createMock(R targetFunc(P1, P2, P3, P4), const bsl::string& funcName)
        {
            // Create the Mock object
            bsl::shared_ptr<Mock<R(P1, P2, P3, P4), N> > l_mockObj = bsl::make_shared<Mock<R(P1, P2, P3, P4), N> >(targetFunc, funcName);

            return l_mockObj;
        }

        // Create a mock for a global/free or fortran, or static function with 5 parameters
        template <int N, typename R, typename P1, typename P2, typename P3, typename P4, typename P5>
        static bsl::shared_ptr<Mock<R(P1, P2, P3, P4, P5), N> > createMock(R targetFunc(P1, P2, P3, P4, P5), const bsl::string& funcName)
        {
            // Create the Mock object
            bsl::shared_ptr<Mock<R(P1, P2, P3, P4, P5), N> > l_mockObj = bsl::make_shared<Mock<R(P1, P2, P3, P4, P5), N> >(targetFunc, funcName);

            return l_mockObj;
        }

        // Create a mock for a global/free or fortran, or static function with 6 parameters
        template <int N, typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6>
        static bsl::shared_ptr<Mock<R(P1, P2, P3, P4, P5, P6), N> > createMock(R targetFunc(P1, P2, P3, P4, P5, P6), const bsl::string& funcName)
        {
            // Create the Mock object
            bsl::shared_ptr<Mock<R(P1, P2, P3, P4, P5, P6), N> > l_mockObj = bsl::make_shared<Mock<R(P1, P2, P3, P4, P5, P6), N> >(targetFunc, funcName);

            return l_mockObj;
        }

        // Create a mock for a global/free or fortran, or static function with 7 parameters
        template <int N, typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7>
        static bsl::shared_ptr<Mock<R(P1, P2, P3, P4, P5, P6, P7), N> > createMock(R targetFunc(P1, P2, P3, P4, P5, P6, P7), const bsl::string& funcName)
        {
            // Create the Mock object
            bsl::shared_ptr<Mock<R(P1, P2, P3, P4, P5, P6, P7), N> > l_mockObj = bsl::make_shared<Mock<R(P1, P2, P3, P4, P5, P6, P7), N> >(targetFunc, funcName);

            return l_mockObj;
        }

        // Create a mock for a global/free or fortran, or static function with 8 parameters
        template <int N, typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
            typename P7, typename P8>
        static bsl::shared_ptr<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8), N> > createMock(
            R targetFunc(P1, P2, P3, P4, P5, P6, P7, P8), const bsl::string& funcName)
        {
            // Create the Mock object
            bsl::shared_ptr<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8), N> > l_mockObj = bsl::make_shared<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8), N> >(targetFunc, funcName);

            return l_mockObj;
        }

        // Create a mock for a global/free or fortran, or static function with 9 parameters
        template <int N, typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
            typename P7, typename P8, typename P9>
        static bsl::shared_ptr<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9), N> > createMock(
            R targetFunc(P1, P2, P3, P4, P5, P6, P7, P8, P9), const bsl::string& funcName)
        {
            // Create the Mock object
            bsl::shared_ptr<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9), N> > l_mockObj = bsl::make_shared<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9), N> >(targetFunc, funcName);

            return l_mockObj;
        }

        // Create a mock for a global/free or fortran, or static function with 10 parameters
        template <int N, typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
            typename P7, typename P8, typename P9, typename P10>
        static bsl::shared_ptr<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10), N> > createMock(
            R targetFunc(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10), const bsl::string& funcName)
        {
            // Create the Mock object
            bsl::shared_ptr<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10), N> > l_mockObj = bsl::make_shared<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10), N> >(targetFunc, funcName);

            return l_mockObj;
        }

        // Create a mock for a global/free or fortran, or static function with 11 parameters
        template <int N, typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
            typename P7, typename P8, typename P9, typename P10, typename P11>
        static bsl::shared_ptr<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11), N> > createMock(
            R targetFunc(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11), const bsl::string& funcName)
        {
            // Create the Mock object
            bsl::shared_ptr<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11), N> > l_mockObj = bsl::make_shared<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11), N> >(targetFunc, funcName);

            return l_mockObj;
        }

        // Create a mock for a global/free or fortran, or static function with 12 parameters
        template <int N, typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
            typename P7, typename P8, typename P9, typename P10, typename P11, typename P12>
        static bsl::shared_ptr<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12), N> > createMock(
            R targetFunc(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12), const bsl::string& funcName)
        {
            // Create the Mock object
            bsl::shared_ptr<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12), N> > l_mockObj = bsl::make_shared<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12), N> >(targetFunc, funcName);

            return l_mockObj;
        }

        // Create a mock for a global/free or fortran, or static function with 13 parameters
        template <int N, typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
            typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13>
        static bsl::shared_ptr<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13), N> > createMock(
            R targetFunc(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13), const bsl::string& funcName)
        {
            // Create the Mock object
            bsl::shared_ptr<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13), N> > l_mockObj = bsl::make_shared<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13), N> >(targetFunc, funcName);

            return l_mockObj;
        }

        // Create a mock for a global/free or fortran, or static function with 14 parameters
        template <int N, typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
            typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13, typename P14>
        static bsl::shared_ptr<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14), N> > createMock(
            R targetFunc(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14), const bsl::string& funcName)
        {
            // Create the Mock object
            bsl::shared_ptr<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14), N> > l_mockObj = bsl::make_shared<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14), N> >(targetFunc, funcName);

            return l_mockObj;
        }

        // Create a mock for a global/free or fortran, or static function with 15 parameters
        template <int N, typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
            typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13, typename P14, typename P15>
        static bsl::shared_ptr<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15), N> > createMock(
            R targetFunc(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15), const bsl::string& funcName)
        {
            // Create the Mock object
            bsl::shared_ptr<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15), N> > l_mockObj = bsl::make_shared<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15), N> >(targetFunc, funcName);

            return l_mockObj;
        }

        // =========================================================================
        // createMock - Non-const non-virtual member functions
        // =========================================================================

        // Create a mock for a NON-CONST member function with 0 parameters
        template <int N, typename R, typename C>
        static bsl::shared_ptr<Mock<R (C::*)(), N> > createMock(R (C::*targetFunc)(), const bsl::string& funcName)
        {
            // Create the Mock object
            bsl::shared_ptr<Mock<R (C::*)(), N> > l_mockObj = bsl::make_shared<Mock<R (C::*)(), N> >(targetFunc, funcName);

            return l_mockObj;
        }

        // Create a mock for a NON-CONST member function with 1 parameter
        template <int N, typename R, typename C, typename P1>
        static bsl::shared_ptr<Mock<R (C::*)(P1), N> > createMock(R (C::*targetFunc)(P1), const bsl::string& funcName)
        {
            // Create the Mock object
            bsl::shared_ptr<Mock<R (C::*)(P1), N> > l_mockObj = bsl::make_shared<Mock<R (C::*)(P1), N> >(targetFunc, funcName);

            return l_mockObj;
        }

        // Create a mock for a NON-CONST member function with 2 parameters
        template <int N, typename R, typename C, typename P1, typename P2>
        static bsl::shared_ptr<Mock<R (C::*)(P1, P2), N> > createMock(R (C::*targetFunc)(P1, P2), const bsl::string& funcName)
        {
            // Create the Mock object
            bsl::shared_ptr<Mock<R (C::*)(P1, P2), N> > l_mockObj = bsl::make_shared<Mock<R (C::*)(P1, P2), N> >(targetFunc, funcName);

            return l_mockObj;
        }

        // Create a mock for a NON-CONST member function with 3 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3>
        static bsl::shared_ptr<Mock<R (C::*)(P1, P2, P3), N> > createMock(
            R (C::*targetFunc)(P1, P2, P3), const bsl::string& funcName)
        {
            // Create the Mock object
            bsl::shared_ptr<Mock<R (C::*)(P1, P2, P3), N> > l_mockObj = bsl::make_shared<Mock<R (C::*)(P1, P2, P3), N> >(targetFunc, funcName);

            return l_mockObj;
        }

        // Create a mock for a NON-CONST member function with 4 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4>
        static bsl::shared_ptr<Mock<R (C::*)(P1, P2, P3, P4), N> > createMock(
            R (C::*targetFunc)(P1, P2, P3, P4), const bsl::string& funcName)
        {
            // Create the Mock object
            bsl::shared_ptr<Mock<R (C::*)(P1, P2, P3, P4), N> > l_mockObj = bsl::make_shared<Mock<R (C::*)(P1, P2, P3, P4), N> >(targetFunc, funcName);

            return l_mockObj;
        }

        // Create a mock for a NON-CONST member function with 5 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5>
        static bsl::shared_ptr<Mock<R (C::*)(P1, P2, P3, P4, P5), N> > createMock(
            R (C::*targetFunc)(P1, P2, P3, P4, P5), const bsl::string& funcName)
        {
            // Create the Mock object
            bsl::shared_ptr<Mock<R (C::*)(P1, P2, P3, P4, P5), N> > l_mockObj = bsl::make_shared<Mock<R (C::*)(P1, P2, P3, P4, P5), N> >(targetFunc, funcName);

            return l_mockObj;
        }

        // Create a mock for a NON-CONST member function with 6 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6>
        static bsl::shared_ptr<Mock<R (C::*)(P1, P2, P3, P4, P5, P6), N> > createMock(
            R (C::*targetFunc)(P1, P2, P3, P4, P5, P6), const bsl::string& funcName)
        {
            // Create the Mock object
            bsl::shared_ptr<Mock<R (C::*)(P1, P2, P3, P4, P5, P6), N> > l_mockObj = bsl::make_shared<Mock<R (C::*)(P1, P2, P3, P4, P5, P6), N> >(targetFunc, funcName);

            return l_mockObj;
        }

        // Create a mock for a NON-CONST member function with 7 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7>
        static bsl::shared_ptr<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7), N> > createMock(
            R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7), const bsl::string& funcName)
        {
            // Create the Mock object
            bsl::shared_ptr<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7), N> > l_mockObj = bsl::make_shared<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7), N> >(targetFunc, funcName);

            return l_mockObj;
        }

        // Create a mock for a NON-CONST member function with 8 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
            typename P7, typename P8>
        static bsl::shared_ptr<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8), N> > createMock(
            R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8), const bsl::string& funcName)
        {
            // Create the Mock object
            bsl::shared_ptr<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8), N> > l_mockObj = bsl::make_shared<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8), N> >(targetFunc, funcName);

            return l_mockObj;
        }

        // Create a mock for a NON-CONST member function with 9 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
            typename P7, typename P8, typename P9>
        static bsl::shared_ptr<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9), N> > createMock(
            R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9), const bsl::string& funcName)
        {
            // Create the Mock object
            bsl::shared_ptr<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9), N> > l_mockObj = bsl::make_shared<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9), N> >(targetFunc, funcName);

            return l_mockObj;
        }

        // Create a mock for a NON-CONST member function with 10 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
            typename P7, typename P8, typename P9, typename P10>
        static bsl::shared_ptr<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10), N> > createMock(
            R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10), const bsl::string& funcName)
        {
            // Create the Mock object
            bsl::shared_ptr<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10), N> > l_mockObj = bsl::make_shared<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10), N> >(targetFunc, funcName);

            return l_mockObj;
        }

        // Create a mock for a NON-CONST member function with 11 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
            typename P7, typename P8, typename P9, typename P10, typename P11>
        static bsl::shared_ptr<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11), N> > createMock(
            R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11), const bsl::string& funcName)
        {
            // Create the Mock object
            bsl::shared_ptr<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11), N> > l_mockObj = bsl::make_shared<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11), N> >(targetFunc, funcName);

            return l_mockObj;
        }

        // Create a mock for a NON-CONST member function with 12 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
            typename P7, typename P8, typename P9, typename P10, typename P11, typename P12>
        static bsl::shared_ptr<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12), N> > createMock(
            R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12), const bsl::string& funcName)
        {
            // Create the Mock object
            bsl::shared_ptr<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12), N> > l_mockObj = bsl::make_shared<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12), N> >(targetFunc, funcName);

            return l_mockObj;
        }

        // Create a mock for a NON-CONST member function with 13 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
            typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13>
        static bsl::shared_ptr<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13), N> > createMock(
            R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13), const bsl::string& funcName)
        {
            // Create the Mock object
            bsl::shared_ptr<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13), N> > l_mockObj = bsl::make_shared<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13), N> >(targetFunc, funcName);

            return l_mockObj;
        }

        // Create a mock for a NON-CONST member function with 14 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
            typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13, typename P14>
        static bsl::shared_ptr<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14), N> > createMock(
            R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14), const bsl::string& funcName)
        {
            // Create the Mock object
            bsl::shared_ptr<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14), N> > l_mockObj = bsl::make_shared<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14), N> >(targetFunc, funcName);

            return l_mockObj;
        }

        // Create a mock for a NON-CONST member function with 15 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
            typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13, typename P14, typename P15>
        static bsl::shared_ptr<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15), N> > createMock(
            R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15), const bsl::string& funcName)
        {
            // Create the Mock object
            bsl::shared_ptr<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15), N> > l_mockObj = bsl::make_shared<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15), N> >(targetFunc, funcName);

            return l_mockObj;
        }

        // =========================================================================
        // createMock - Const non-virtual member functions
        // =========================================================================

        // Create a mock for a CONST member function with 0 parameters
        template <int N, typename R, typename C>
        static bsl::shared_ptr<Mock<R (C::*)() const, N> > createMock(R (C::*targetFunc)() const, const bsl::string& funcName)
        {
            // Create the Mock object
            bsl::shared_ptr<Mock<R (C::*)() const, N> > l_mockObj = bsl::make_shared<Mock<R (C::*)() const, N> >(targetFunc, funcName);

            return l_mockObj;
        }

        // Create a mock for a CONST member function with 1 parameter
        template <int N, typename R, typename C, typename P1>
        static bsl::shared_ptr<Mock<R (C::*)(P1) const, N> > createMock(R (C::*targetFunc)(P1) const, const bsl::string& funcName)
        {
            // Create the Mock object
            bsl::shared_ptr<Mock<R (C::*)(P1) const, N> > l_mockObj = bsl::make_shared<Mock<R (C::*)(P1) const, N> >(targetFunc, funcName);

            return l_mockObj;
        }

        // Create a mock for a CONST member function with 2 parameters
        template <int N, typename R, typename C, typename P1, typename P2>
        static bsl::shared_ptr<Mock<R (C::*)(P1, P2) const, N> > createMock(R (C::*targetFunc)(P1, P2) const, const bsl::string& funcName)
        {
            // Create the Mock object
            bsl::shared_ptr<Mock<R (C::*)(P1, P2) const, N> > l_mockObj = bsl::make_shared<Mock<R (C::*)(P1, P2) const, N> >(targetFunc, funcName);

            return l_mockObj;
        }

        // Create a mock for a CONST member function with 3 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3>
        static bsl::shared_ptr<Mock<R (C::*)(P1, P2, P3) const, N> > createMock(R (C::*targetFunc)(P1, P2, P3) const, const bsl::string& funcName)
        {
            // Create the Mock object
            bsl::shared_ptr<Mock<R (C::*)(P1, P2, P3) const, N> > l_mockObj = bsl::make_shared<Mock<R (C::*)(P1, P2, P3) const, N> >(targetFunc, funcName);

            return l_mockObj;
        }

        // Create a mock for a CONST member function with 4 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4>
        static bsl::shared_ptr<Mock<R (C::*)(P1, P2, P3, P4) const, N> > createMock(R (C::*targetFunc)(P1, P2, P3, P4) const, const bsl::string& funcName)
        {
            // Create the Mock object
            bsl::shared_ptr<Mock<R (C::*)(P1, P2, P3, P4) const, N> > l_mockObj = bsl::make_shared<Mock<R (C::*)(P1, P2, P3, P4) const, N> >(targetFunc, funcName);

            return l_mockObj;
        }

        // Create a mock for a CONST member function with 5 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5>
        static bsl::shared_ptr<Mock<R (C::*)(P1, P2, P3, P4, P5) const, N> > createMock(R (C::*targetFunc)(P1, P2, P3, P4, P5) const, const bsl::string& funcName)
        {
            // Create the Mock object
            bsl::shared_ptr<Mock<R (C::*)(P1, P2, P3, P4, P5) const, N> > l_mockObj = bsl::make_shared<Mock<R (C::*)(P1, P2, P3, P4, P5) const, N> >(targetFunc, funcName);

            return l_mockObj;
        }

        // Create a mock for a CONST member function with 6 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6>
        static bsl::shared_ptr<Mock<R (C::*)(P1, P2, P3, P4, P5, P6) const, N> > createMock(R (C::*targetFunc)(P1, P2, P3, P4, P5, P6) const, const bsl::string& funcName)
        {
            // Create the Mock object
            bsl::shared_ptr<Mock<R (C::*)(P1, P2, P3, P4, P5, P6) const, N> > l_mockObj = bsl::make_shared<Mock<R (C::*)(P1, P2, P3, P4, P5, P6) const, N> >(targetFunc, funcName);

            return l_mockObj;
        }

        // Create a mock for a CONST member function with 7 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7>
        static bsl::shared_ptr<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7) const, N> > createMock(R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7) const, const bsl::string& funcName)
        {
            // Create the Mock object
            bsl::shared_ptr<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7) const, N> > l_mockObj = bsl::make_shared<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7) const, N> >(targetFunc, funcName);

            return l_mockObj;
        }

        // Create a mock for a CONST member function with 8 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8>
        static bsl::shared_ptr<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8) const, N> > createMock(R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8) const, const bsl::string& funcName)
        {
            // Create the Mock object
            bsl::shared_ptr<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8) const, N> > l_mockObj = bsl::make_shared<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8) const, N> >(targetFunc, funcName);

            return l_mockObj;
        }

        // Create a mock for a CONST member function with 9 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8,
            typename P9>
        static bsl::shared_ptr<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9) const, N> > createMock(R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9) const, const bsl::string& funcName)
        {
            // Create the Mock object
            bsl::shared_ptr<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9) const, N> > l_mockObj = bsl::make_shared<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9) const, N> >(targetFunc, funcName);

            return l_mockObj;
        }

        // Create a mock for a CONST member function with 10 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8,
            typename P9, typename P10>
        static bsl::shared_ptr<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10) const, N> > createMock(R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10) const, const bsl::string& funcName)
        {
            // Create the Mock object
            bsl::shared_ptr<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10) const, N> > l_mockObj = bsl::make_shared<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10) const, N> >(targetFunc, funcName);

            return l_mockObj;
        }

        // Create a mock for a CONST member function with 11 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8,
            typename P9, typename P10, typename P11>
        static bsl::shared_ptr<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11) const, N> > createMock(R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11) const, const bsl::string& funcName)
        {
            // Create the Mock object
            bsl::shared_ptr<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11) const, N> > l_mockObj = bsl::make_shared<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11) const, N> >(targetFunc, funcName);

            return l_mockObj;
        }

        // Create a mock for a CONST member function with 12 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8,
            typename P9, typename P10, typename P11, typename P12>
        static bsl::shared_ptr<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12) const, N> > createMock(R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12) const, const bsl::string& funcName)
        {
            // Create the Mock object
            bsl::shared_ptr<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12) const, N> > l_mockObj = bsl::make_shared<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12) const, N> >(targetFunc, funcName);

            return l_mockObj;
        }

        // Create a mock for a CONST member function with 13 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8,
            typename P9, typename P10, typename P11, typename P12, typename P13>
        static bsl::shared_ptr<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13) const, N> > createMock(R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13) const, const bsl::string& funcName)
        {
            // Create the Mock object
            bsl::shared_ptr<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13) const, N> > l_mockObj = bsl::make_shared<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13) const, N> >(targetFunc, funcName);

            return l_mockObj;
        }

        // Create a mock for a CONST member function with 14 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8,
            typename P9, typename P10, typename P11, typename P12, typename P13, typename P14>
        static bsl::shared_ptr<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14) const, N> > createMock(R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14) const, const bsl::string& funcName)
        {
            // Create the Mock object
            bsl::shared_ptr<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14) const, N> > l_mockObj = bsl::make_shared<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14) const, N> >(targetFunc, funcName);

            return l_mockObj;
        }

        // Create a mock for a CONST member function with 15 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8,
            typename P9, typename P10, typename P11, typename P12, typename P13, typename P14, typename P15>
        static bsl::shared_ptr<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15) const, N> > createMock(R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15) const, const bsl::string& funcName)
        {
            // Create the Mock object
            bsl::shared_ptr<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15) const, N> > l_mockObj = bsl::make_shared<Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15) const, N> >(targetFunc, funcName);

            return l_mockObj;
        }

        // =========================================================================
        // createVirtualMock - Non-const virtual member functions
        // =========================================================================

        // Create a mock for a NON-CONST virtual member function with 0 parameters
        template <int N, typename R, typename C>
        static bsl::shared_ptr<MockVirtual<R (C::*)(), N> > createVirtualMock(
            R (C::*targetFunc)(), const bsl::string& funcName)
        {
            bsl::shared_ptr<MockVirtual<R (C::*)(), N> > l_mockObj = bsl::make_shared<MockVirtual<R (C::*)(), N> >(targetFunc, funcName);
            return l_mockObj;
        }

        // Create a mock for a NON-CONST virtual member function with 1 parameter
        template <int N, typename R, typename C, typename P1>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1), N> > createVirtualMock(
            R (C::*targetFunc)(P1), const bsl::string& funcName)
        {
            bsl::shared_ptr<MockVirtual<R (C::*)(P1), N> > l_mockObj = bsl::make_shared<MockVirtual<R (C::*)(P1), N> >(targetFunc, funcName);
            return l_mockObj;
        }

        // Create a mock for a NON-CONST virtual member function with 2 parameters
        template <int N, typename R, typename C, typename P1, typename P2>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2), N> > createVirtualMock(
            R (C::*targetFunc)(P1, P2), const bsl::string& funcName)
        {
            bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2), N> > l_mockObj = bsl::make_shared<MockVirtual<R (C::*)(P1, P2), N> >(targetFunc, funcName);
            return l_mockObj;
        }

        // Create a mock for a NON-CONST virtual member function with 3 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3), N> > createVirtualMock(
            R (C::*targetFunc)(P1, P2, P3), const bsl::string& funcName)
        {
            bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3), N> > l_mockObj = bsl::make_shared<MockVirtual<R (C::*)(P1, P2, P3), N> >(targetFunc, funcName);
            return l_mockObj;
        }

        // Create a mock for a NON-CONST virtual member function with 4 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4), N> > createVirtualMock(
            R (C::*targetFunc)(P1, P2, P3, P4), const bsl::string& funcName)
        {
            bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4), N> > l_mockObj = bsl::make_shared<MockVirtual<R (C::*)(P1, P2, P3, P4), N> >(targetFunc, funcName);
            return l_mockObj;
        }

        // Create a mock for a NON-CONST virtual member function with 5 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5), N> > createVirtualMock(
            R (C::*targetFunc)(P1, P2, P3, P4, P5), const bsl::string& funcName)
        {
            bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5), N> > l_mockObj = bsl::make_shared<MockVirtual<R (C::*)(P1, P2, P3, P4, P5), N> >(targetFunc, funcName);
            return l_mockObj;
        }

        // Create a mock for a NON-CONST virtual member function with 6 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6), N> > createVirtualMock(
            R (C::*targetFunc)(P1, P2, P3, P4, P5, P6), const bsl::string& funcName)
        {
            bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6), N> > l_mockObj = bsl::make_shared<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6), N> >(targetFunc, funcName);
            return l_mockObj;
        }

        // Create a mock for a NON-CONST virtual member function with 7 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7), N> > createVirtualMock(
            R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7), const bsl::string& funcName)
        {
            bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7), N> > l_mockObj = bsl::make_shared<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7), N> >(targetFunc, funcName);
            return l_mockObj;
        }

        // Create a mock for a NON-CONST virtual member function with 8 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8), N> > createVirtualMock(
            R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8), const bsl::string& funcName)
        {
            bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8), N> > l_mockObj = bsl::make_shared<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8), N> >(targetFunc, funcName);
            return l_mockObj;
        }

        // Create a mock for a NON-CONST virtual member function with 9 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9), N> > createVirtualMock(
            R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9), const bsl::string& funcName)
        {
            bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9), N> > l_mockObj = bsl::make_shared<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9), N> >(targetFunc, funcName);
            return l_mockObj;
        }

        // Create a mock for a NON-CONST virtual member function with 10 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9, typename P10>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10), N> > createVirtualMock(
            R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10), const bsl::string& funcName)
        {
            bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10), N> > l_mockObj = bsl::make_shared<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10), N> >(targetFunc, funcName);
            return l_mockObj;
        }

        // Create a mock for a NON-CONST virtual member function with 11 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9, typename P10, typename P11>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11), N> > createVirtualMock(
            R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11), const bsl::string& funcName)
        {
            bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11), N> > l_mockObj = bsl::make_shared<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11), N> >(targetFunc, funcName);
            return l_mockObj;
        }

        // Create a mock for a NON-CONST virtual member function with 12 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9, typename P10, typename P11, typename P12>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12), N> > createVirtualMock(
            R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12), const bsl::string& funcName)
        {
            bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12), N> > l_mockObj = bsl::make_shared<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12), N> >(targetFunc, funcName);
            return l_mockObj;
        }

        // Create a mock for a NON-CONST virtual member function with 13 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13), N> > createVirtualMock(
            R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13), const bsl::string& funcName)
        {
            bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13), N> > l_mockObj = bsl::make_shared<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13), N> >(targetFunc, funcName);
            return l_mockObj;
        }

        // Create a mock for a NON-CONST virtual member function with 14 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13, typename P14>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14), N> > createVirtualMock(
            R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14), const bsl::string& funcName)
        {
            bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14), N> > l_mockObj = bsl::make_shared<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14), N> >(targetFunc, funcName);
            return l_mockObj;
        }

        // Create a mock for a NON-CONST virtual member function with 15 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13, typename P14, typename P15>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15), N> > createVirtualMock(
            R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15), const bsl::string& funcName)
        {
            bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15), N> > l_mockObj = bsl::make_shared<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15), N> >(targetFunc, funcName);
            return l_mockObj;
        }

        // =========================================================================
        // createVirtualMock - Const virtual member functions
        // =========================================================================

        // Create a mock for a CONST virtual member function with 0 parameters
        template <int N, typename R, typename C>
        static bsl::shared_ptr<MockVirtual<R (C::*)() const, N> > createVirtualMock(
            R (C::*targetFunc)() const, const bsl::string& funcName)
        {
            bsl::shared_ptr<MockVirtual<R (C::*)() const, N> > l_mockObj = bsl::make_shared<MockVirtual<R (C::*)() const, N> >(targetFunc, funcName);
            return l_mockObj;
        }

        // Create a mock for a CONST virtual member function with 1 parameter
        template <int N, typename R, typename C, typename P1>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1) const, N> > createVirtualMock(
            R (C::*targetFunc)(P1) const, const bsl::string& funcName)
        {
            bsl::shared_ptr<MockVirtual<R (C::*)(P1) const, N> > l_mockObj = bsl::make_shared<MockVirtual<R (C::*)(P1) const, N> >(targetFunc, funcName);
            return l_mockObj;
        }

        // Create a mock for a CONST virtual member function with 2 parameters
        template <int N, typename R, typename C, typename P1, typename P2>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2) const, N> > createVirtualMock(
            R (C::*targetFunc)(P1, P2) const, const bsl::string& funcName)
        {
            bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2) const, N> > l_mockObj = bsl::make_shared<MockVirtual<R (C::*)(P1, P2) const, N> >(targetFunc, funcName);
            return l_mockObj;
        }

        // Create a mock for a CONST virtual member function with 3 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3) const, N> > createVirtualMock(
            R (C::*targetFunc)(P1, P2, P3) const, const bsl::string& funcName)
        {
            bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3) const, N> > l_mockObj = bsl::make_shared<MockVirtual<R (C::*)(P1, P2, P3) const, N> >(targetFunc, funcName);
            return l_mockObj;
        }

        // Create a mock for a CONST virtual member function with 4 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4) const, N> > createVirtualMock(
            R (C::*targetFunc)(P1, P2, P3, P4) const, const bsl::string& funcName)
        {
            bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4) const, N> > l_mockObj = bsl::make_shared<MockVirtual<R (C::*)(P1, P2, P3, P4) const, N> >(targetFunc, funcName);
            return l_mockObj;
        }

        // Create a mock for a CONST virtual member function with 5 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5) const, N> > createVirtualMock(
            R (C::*targetFunc)(P1, P2, P3, P4, P5) const, const bsl::string& funcName)
        {
            bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5) const, N> > l_mockObj = bsl::make_shared<MockVirtual<R (C::*)(P1, P2, P3, P4, P5) const, N> >(targetFunc, funcName);
            return l_mockObj;
        }

        // Create a mock for a CONST virtual member function with 6 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6) const, N> > createVirtualMock(
            R (C::*targetFunc)(P1, P2, P3, P4, P5, P6) const, const bsl::string& funcName)
        {
            bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6) const, N> > l_mockObj = bsl::make_shared<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6) const, N> >(targetFunc, funcName);
            return l_mockObj;
        }

        // Create a mock for a CONST virtual member function with 7 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7) const, N> > createVirtualMock(
            R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7) const, const bsl::string& funcName)
        {
            bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7) const, N> > l_mockObj = bsl::make_shared<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7) const, N> >(targetFunc, funcName);
            return l_mockObj;
        }

        // Create a mock for a CONST virtual member function with 8 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8) const, N> > createVirtualMock(
            R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8) const, const bsl::string& funcName)
        {
            bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8) const, N> > l_mockObj = bsl::make_shared<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8) const, N> >(targetFunc, funcName);
            return l_mockObj;
        }

        // Create a mock for a CONST virtual member function with 9 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9) const, N> > createVirtualMock(
            R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9) const, const bsl::string& funcName)
        {
            bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9) const, N> > l_mockObj = bsl::make_shared<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9) const, N> >(targetFunc, funcName);
            return l_mockObj;
        }

        // Create a mock for a CONST virtual member function with 10 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9, typename P10>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10) const, N> > createVirtualMock(
            R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10) const, const bsl::string& funcName)
        {
            bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10) const, N> > l_mockObj = bsl::make_shared<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10) const, N> >(targetFunc, funcName);
            return l_mockObj;
        }

        // Create a mock for a CONST virtual member function with 11 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9, typename P10, typename P11>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11) const, N> > createVirtualMock(
            R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11) const, const bsl::string& funcName)
        {
            bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11) const, N> > l_mockObj = bsl::make_shared<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11) const, N> >(targetFunc, funcName);
            return l_mockObj;
        }

        // Create a mock for a CONST virtual member function with 12 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9, typename P10, typename P11, typename P12>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12) const, N> > createVirtualMock(
            R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12) const, const bsl::string& funcName)
        {
            bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12) const, N> > l_mockObj = bsl::make_shared<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12) const, N> >(targetFunc, funcName);
            return l_mockObj;
        }

        // Create a mock for a CONST virtual member function with 13 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13) const, N> > createVirtualMock(
            R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13) const, const bsl::string& funcName)
        {
            bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13) const, N> > l_mockObj = bsl::make_shared<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13) const, N> >(targetFunc, funcName);
            return l_mockObj;
        }

        // Create a mock for a CONST virtual member function with 14 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13, typename P14>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14) const, N> > createVirtualMock(
            R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14) const, const bsl::string& funcName)
        {
            bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14) const, N> > l_mockObj = bsl::make_shared<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14) const, N> >(targetFunc, funcName);
            return l_mockObj;
        }

        // Create a mock for a CONST virtual member function with 15 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13, typename P14, typename P15>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15) const, N> > createVirtualMock(
            R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15) const, const bsl::string& funcName)
        {
            bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15) const, N> > l_mockObj = bsl::make_shared<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15) const, N> >(targetFunc, funcName);
            return l_mockObj;
        }

        // =========================================================================
        // PMF-accepting with instance overloads (BONOBO_MOCK_VIRTUAL_ON)
        // =========================================================================

        // Create a mock with instance for a NON-CONST virtual member function with 0 parameters
        template <int N, typename R, typename C>
        static bsl::shared_ptr<MockVirtual<R (C::*)(), N> > createVirtualMock(
            const C& inst, R (C::*targetFunc)(), const bsl::string& funcName)
        {
            bsl::shared_ptr<MockVirtual<R (C::*)(), N> > l_mockObj = bsl::make_shared<MockVirtual<R (C::*)(), N> >(inst, targetFunc, funcName);
            return l_mockObj;
        }

        // Create a mock with instance for a NON-CONST virtual member function with 1 parameter
        template <int N, typename R, typename C, typename P1>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1), N> > createVirtualMock(
            const C& inst, R (C::*targetFunc)(P1), const bsl::string& funcName)
        {
            bsl::shared_ptr<MockVirtual<R (C::*)(P1), N> > l_mockObj = bsl::make_shared<MockVirtual<R (C::*)(P1), N> >(inst, targetFunc, funcName);
            return l_mockObj;
        }

        // Create a mock with instance for a NON-CONST virtual member function with 2 parameters
        template <int N, typename R, typename C, typename P1, typename P2>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2), N> > createVirtualMock(
            const C& inst, R (C::*targetFunc)(P1, P2), const bsl::string& funcName)
        {
            bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2), N> > l_mockObj = bsl::make_shared<MockVirtual<R (C::*)(P1, P2), N> >(inst, targetFunc, funcName);
            return l_mockObj;
        }

        // Create a mock with instance for a NON-CONST virtual member function with 3 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3), N> > createVirtualMock(
            const C& inst, R (C::*targetFunc)(P1, P2, P3), const bsl::string& funcName)
        {
            bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3), N> > l_mockObj = bsl::make_shared<MockVirtual<R (C::*)(P1, P2, P3), N> >(inst, targetFunc, funcName);
            return l_mockObj;
        }

        // Create a mock with instance for a NON-CONST virtual member function with 4 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4), N> > createVirtualMock(
            const C& inst, R (C::*targetFunc)(P1, P2, P3, P4), const bsl::string& funcName)
        {
            bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4), N> > l_mockObj = bsl::make_shared<MockVirtual<R (C::*)(P1, P2, P3, P4), N> >(inst, targetFunc, funcName);
            return l_mockObj;
        }

        // Create a mock with instance for a NON-CONST virtual member function with 5 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5), N> > createVirtualMock(
            const C& inst, R (C::*targetFunc)(P1, P2, P3, P4, P5), const bsl::string& funcName)
        {
            bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5), N> > l_mockObj = bsl::make_shared<MockVirtual<R (C::*)(P1, P2, P3, P4, P5), N> >(inst, targetFunc, funcName);
            return l_mockObj;
        }

        // Create a mock with instance for a NON-CONST virtual member function with 6 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6), N> > createVirtualMock(
            const C& inst, R (C::*targetFunc)(P1, P2, P3, P4, P5, P6), const bsl::string& funcName)
        {
            bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6), N> > l_mockObj = bsl::make_shared<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6), N> >(inst, targetFunc, funcName);
            return l_mockObj;
        }

        // Create a mock with instance for a NON-CONST virtual member function with 7 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7), N> > createVirtualMock(
            const C& inst, R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7), const bsl::string& funcName)
        {
            bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7), N> > l_mockObj = bsl::make_shared<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7), N> >(inst, targetFunc, funcName);
            return l_mockObj;
        }

        // Create a mock with instance for a NON-CONST virtual member function with 8 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8), N> > createVirtualMock(
            const C& inst, R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8), const bsl::string& funcName)
        {
            bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8), N> > l_mockObj = bsl::make_shared<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8), N> >(inst, targetFunc, funcName);
            return l_mockObj;
        }

        // Create a mock with instance for a NON-CONST virtual member function with 9 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9), N> > createVirtualMock(
            const C& inst, R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9), const bsl::string& funcName)
        {
            bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9), N> > l_mockObj = bsl::make_shared<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9), N> >(inst, targetFunc, funcName);
            return l_mockObj;
        }

        // Create a mock with instance for a NON-CONST virtual member function with 10 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9, typename P10>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10), N> > createVirtualMock(
            const C& inst, R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10), const bsl::string& funcName)
        {
            bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10), N> > l_mockObj = bsl::make_shared<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10), N> >(inst, targetFunc, funcName);
            return l_mockObj;
        }

        // Create a mock with instance for a NON-CONST virtual member function with 11 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9, typename P10, typename P11>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11), N> > createVirtualMock(
            const C& inst, R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11), const bsl::string& funcName)
        {
            bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11), N> > l_mockObj = bsl::make_shared<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11), N> >(inst, targetFunc, funcName);
            return l_mockObj;
        }

        // Create a mock with instance for a NON-CONST virtual member function with 12 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9, typename P10, typename P11, typename P12>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12), N> > createVirtualMock(
            const C& inst, R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12), const bsl::string& funcName)
        {
            bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12), N> > l_mockObj = bsl::make_shared<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12), N> >(inst, targetFunc, funcName);
            return l_mockObj;
        }

        // Create a mock with instance for a NON-CONST virtual member function with 13 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13), N> > createVirtualMock(
            const C& inst, R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13), const bsl::string& funcName)
        {
            bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13), N> > l_mockObj = bsl::make_shared<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13), N> >(inst, targetFunc, funcName);
            return l_mockObj;
        }

        // Create a mock with instance for a NON-CONST virtual member function with 14 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13, typename P14>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14), N> > createVirtualMock(
            const C& inst, R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14), const bsl::string& funcName)
        {
            bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14), N> > l_mockObj = bsl::make_shared<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14), N> >(inst, targetFunc, funcName);
            return l_mockObj;
        }

        // Create a mock with instance for a NON-CONST virtual member function with 15 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13, typename P14, typename P15>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15), N> > createVirtualMock(
            const C& inst, R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15), const bsl::string& funcName)
        {
            bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15), N> > l_mockObj = bsl::make_shared<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15), N> >(inst, targetFunc, funcName);
            return l_mockObj;
        }

        // Create a mock with instance for a CONST virtual member function with 0 parameters
        template <int N, typename R, typename C>
        static bsl::shared_ptr<MockVirtual<R (C::*)() const, N> > createVirtualMock(
            const C& inst, R (C::*targetFunc)() const, const bsl::string& funcName)
        {
            bsl::shared_ptr<MockVirtual<R (C::*)() const, N> > l_mockObj = bsl::make_shared<MockVirtual<R (C::*)() const, N> >(inst, targetFunc, funcName);
            return l_mockObj;
        }

        // Create a mock with instance for a CONST virtual member function with 1 parameter
        template <int N, typename R, typename C, typename P1>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1) const, N> > createVirtualMock(
            const C& inst, R (C::*targetFunc)(P1) const, const bsl::string& funcName)
        {
            bsl::shared_ptr<MockVirtual<R (C::*)(P1) const, N> > l_mockObj = bsl::make_shared<MockVirtual<R (C::*)(P1) const, N> >(inst, targetFunc, funcName);
            return l_mockObj;
        }

        // Create a mock with instance for a CONST virtual member function with 2 parameters
        template <int N, typename R, typename C, typename P1, typename P2>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2) const, N> > createVirtualMock(
            const C& inst, R (C::*targetFunc)(P1, P2) const, const bsl::string& funcName)
        {
            bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2) const, N> > l_mockObj = bsl::make_shared<MockVirtual<R (C::*)(P1, P2) const, N> >(inst, targetFunc, funcName);
            return l_mockObj;
        }

        // Create a mock with instance for a CONST virtual member function with 3 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3) const, N> > createVirtualMock(
            const C& inst, R (C::*targetFunc)(P1, P2, P3) const, const bsl::string& funcName)
        {
            bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3) const, N> > l_mockObj = bsl::make_shared<MockVirtual<R (C::*)(P1, P2, P3) const, N> >(inst, targetFunc, funcName);
            return l_mockObj;
        }

        // Create a mock with instance for a CONST virtual member function with 4 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4) const, N> > createVirtualMock(
            const C& inst, R (C::*targetFunc)(P1, P2, P3, P4) const, const bsl::string& funcName)
        {
            bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4) const, N> > l_mockObj = bsl::make_shared<MockVirtual<R (C::*)(P1, P2, P3, P4) const, N> >(inst, targetFunc, funcName);
            return l_mockObj;
        }

        // Create a mock with instance for a CONST virtual member function with 5 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5) const, N> > createVirtualMock(
            const C& inst, R (C::*targetFunc)(P1, P2, P3, P4, P5) const, const bsl::string& funcName)
        {
            bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5) const, N> > l_mockObj = bsl::make_shared<MockVirtual<R (C::*)(P1, P2, P3, P4, P5) const, N> >(inst, targetFunc, funcName);
            return l_mockObj;
        }

        // Create a mock with instance for a CONST virtual member function with 6 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6) const, N> > createVirtualMock(
            const C& inst, R (C::*targetFunc)(P1, P2, P3, P4, P5, P6) const, const bsl::string& funcName)
        {
            bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6) const, N> > l_mockObj = bsl::make_shared<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6) const, N> >(inst, targetFunc, funcName);
            return l_mockObj;
        }

        // Create a mock with instance for a CONST virtual member function with 7 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7) const, N> > createVirtualMock(
            const C& inst, R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7) const, const bsl::string& funcName)
        {
            bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7) const, N> > l_mockObj = bsl::make_shared<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7) const, N> >(inst, targetFunc, funcName);
            return l_mockObj;
        }

        // Create a mock with instance for a CONST virtual member function with 8 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8) const, N> > createVirtualMock(
            const C& inst, R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8) const, const bsl::string& funcName)
        {
            bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8) const, N> > l_mockObj = bsl::make_shared<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8) const, N> >(inst, targetFunc, funcName);
            return l_mockObj;
        }

        // Create a mock with instance for a CONST virtual member function with 9 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9) const, N> > createVirtualMock(
            const C& inst, R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9) const, const bsl::string& funcName)
        {
            bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9) const, N> > l_mockObj = bsl::make_shared<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9) const, N> >(inst, targetFunc, funcName);
            return l_mockObj;
        }

        // Create a mock with instance for a CONST virtual member function with 10 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9, typename P10>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10) const, N> > createVirtualMock(
            const C& inst, R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10) const, const bsl::string& funcName)
        {
            bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10) const, N> > l_mockObj = bsl::make_shared<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10) const, N> >(inst, targetFunc, funcName);
            return l_mockObj;
        }

        // Create a mock with instance for a CONST virtual member function with 11 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9, typename P10, typename P11>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11) const, N> > createVirtualMock(
            const C& inst, R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11) const, const bsl::string& funcName)
        {
            bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11) const, N> > l_mockObj = bsl::make_shared<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11) const, N> >(inst, targetFunc, funcName);
            return l_mockObj;
        }

        // Create a mock with instance for a CONST virtual member function with 12 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9, typename P10, typename P11, typename P12>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12) const, N> > createVirtualMock(
            const C& inst, R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12) const, const bsl::string& funcName)
        {
            bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12) const, N> > l_mockObj = bsl::make_shared<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12) const, N> >(inst, targetFunc, funcName);
            return l_mockObj;
        }

        // Create a mock with instance for a CONST virtual member function with 13 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13) const, N> > createVirtualMock(
            const C& inst, R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13) const, const bsl::string& funcName)
        {
            bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13) const, N> > l_mockObj = bsl::make_shared<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13) const, N> >(inst, targetFunc, funcName);
            return l_mockObj;
        }

        // Create a mock with instance for a CONST virtual member function with 14 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13, typename P14>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14) const, N> > createVirtualMock(
            const C& inst, R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14) const, const bsl::string& funcName)
        {
            bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14) const, N> > l_mockObj = bsl::make_shared<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14) const, N> >(inst, targetFunc, funcName);
            return l_mockObj;
        }

        // Create a mock with instance for a CONST virtual member function with 15 parameters
        template <int N, typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13, typename P14, typename P15>
        static bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15) const, N> > createVirtualMock(
            const C& inst, R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15) const, const bsl::string& funcName)
        {
            bsl::shared_ptr<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15) const, N> > l_mockObj = bsl::make_shared<MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15) const, N> >(inst, targetFunc, funcName);
            return l_mockObj;
        }

        // =========================================================================
        // createPrivateStaticMock - Private static functions
        // =========================================================================

        // Create a mock for a private static function with 0 parameters
        template <int N, typename R>
        static bsl::shared_ptr<Mock<R(), N> > createPrivateStaticMock(R targetFunc(), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            // Create the Mock object
            bsl::shared_ptr<Mock<R(), N> > l_mockObj = bsl::make_shared<Mock<R(), N> >(funcName);

            return l_mockObj;
        }

        // Create a mock for a private static function with 1 parameter
        template <int N, typename R, typename P1>
        static bsl::shared_ptr<Mock<R(P1), N> > createPrivateStaticMock(R targetFunc(P1), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            // Create the Mock object
            bsl::shared_ptr<Mock<R(P1), N> > l_mockObj = bsl::make_shared<Mock<R(P1), N> >(funcName);

            return l_mockObj;
        }

        // Create a mock for a private static function with 2 parameters
        template <int N, typename R, typename P1, typename P2>
        static bsl::shared_ptr<Mock<R(P1, P2), N> > createPrivateStaticMock(R targetFunc(P1, P2), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            // Create the Mock object
            bsl::shared_ptr<Mock<R(P1, P2), N> > l_mockObj = bsl::make_shared<Mock<R(P1, P2), N> >(funcName);

            return l_mockObj;
        }

        // Create a mock for a private static function with 3 parameters
        template <int N, typename R, typename P1, typename P2, typename P3>
        static bsl::shared_ptr<Mock<R(P1, P2, P3), N> > createPrivateStaticMock(R targetFunc(P1, P2, P3), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            // Create the Mock object
            bsl::shared_ptr<Mock<R(P1, P2, P3), N> > l_mockObj = bsl::make_shared<Mock<R(P1, P2, P3), N> >(funcName);

            return l_mockObj;
        }

        // Create a mock for a private static function with 4 parameters
        template <int N, typename R, typename P1, typename P2, typename P3, typename P4>
        static bsl::shared_ptr<Mock<R(P1, P2, P3, P4), N> > createPrivateStaticMock(R targetFunc(P1, P2, P3, P4), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            // Create the Mock object
            bsl::shared_ptr<Mock<R(P1, P2, P3, P4), N> > l_mockObj = bsl::make_shared<Mock<R(P1, P2, P3, P4), N> >(funcName);

            return l_mockObj;
        }

        // Create a mock for a private static function with 5 parameters
        template <int N, typename R, typename P1, typename P2, typename P3, typename P4, typename P5>
        static bsl::shared_ptr<Mock<R(P1, P2, P3, P4, P5), N> > createPrivateStaticMock(R targetFunc(P1, P2, P3, P4, P5), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            // Create the Mock object
            bsl::shared_ptr<Mock<R(P1, P2, P3, P4, P5), N> > l_mockObj = bsl::make_shared<Mock<R(P1, P2, P3, P4, P5), N> >(funcName);

            return l_mockObj;
        }

        // Create a mock for a private static function with 6 parameters
        template <int N, typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6>
        static bsl::shared_ptr<Mock<R(P1, P2, P3, P4, P5, P6), N> > createPrivateStaticMock(R targetFunc(P1, P2, P3, P4, P5, P6), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            // Create the Mock object
            bsl::shared_ptr<Mock<R(P1, P2, P3, P4, P5, P6), N> > l_mockObj = bsl::make_shared<Mock<R(P1, P2, P3, P4, P5, P6), N> >(funcName);

            return l_mockObj;
        }

        // Create a mock for a private static function with 7 parameters
        template <int N, typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7>
        static bsl::shared_ptr<Mock<R(P1, P2, P3, P4, P5, P6, P7), N> > createPrivateStaticMock(R targetFunc(P1, P2, P3, P4, P5, P6, P7), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            // Create the Mock object
            bsl::shared_ptr<Mock<R(P1, P2, P3, P4, P5, P6, P7), N> > l_mockObj = bsl::make_shared<Mock<R(P1, P2, P3, P4, P5, P6, P7), N> >(funcName);

            return l_mockObj;
        }

        // Create a mock for a private static function with 8 parameters
        template <int N, typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8>
        static bsl::shared_ptr<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8), N> > createPrivateStaticMock(R targetFunc(P1, P2, P3, P4, P5, P6, P7, P8), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            // Create the Mock object
            bsl::shared_ptr<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8), N> > l_mockObj = bsl::make_shared<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8), N> >(funcName);

            return l_mockObj;
        }

        // Create a mock for a private static function with 9 parameters
        template <int N, typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9>
        static bsl::shared_ptr<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9), N> > createPrivateStaticMock(R targetFunc(P1, P2, P3, P4, P5, P6, P7, P8, P9), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            // Create the Mock object
            bsl::shared_ptr<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9), N> > l_mockObj = bsl::make_shared<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9), N> >(funcName);

            return l_mockObj;
        }

        // Create a mock for a private static function with 10 parameters
        template <int N, typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9, typename P10>
        static bsl::shared_ptr<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10), N> > createPrivateStaticMock(R targetFunc(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            // Create the Mock object
            bsl::shared_ptr<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10), N> > l_mockObj = bsl::make_shared<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10), N> >(funcName);

            return l_mockObj;
        }

        // Create a mock for a private static function with 11 parameters
        template <int N, typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9, typename P10, typename P11>
        static bsl::shared_ptr<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11), N> > createPrivateStaticMock(R targetFunc(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            // Create the Mock object
            bsl::shared_ptr<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11), N> > l_mockObj = bsl::make_shared<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11), N> >(funcName);

            return l_mockObj;
        }

        // Create a mock for a private static function with 12 parameters
        template <int N, typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9, typename P10, typename P11, typename P12>
        static bsl::shared_ptr<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12), N> > createPrivateStaticMock(R targetFunc(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            // Create the Mock object
            bsl::shared_ptr<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12), N> > l_mockObj = bsl::make_shared<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12), N> >(funcName);

            return l_mockObj;
        }

        // Create a mock for a private static function with 13 parameters
        template <int N, typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13>
        static bsl::shared_ptr<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13), N> > createPrivateStaticMock(R targetFunc(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            // Create the Mock object
            bsl::shared_ptr<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13), N> > l_mockObj = bsl::make_shared<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13), N> >(funcName);

            return l_mockObj;
        }

        // Create a mock for a private static function with 14 parameters
        template <int N, typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13, typename P14>
        static bsl::shared_ptr<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14), N> > createPrivateStaticMock(R targetFunc(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            // Create the Mock object
            bsl::shared_ptr<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14), N> > l_mockObj = bsl::make_shared<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14), N> >(funcName);

            return l_mockObj;
        }

        // Create a mock for a private static function with 15 parameters
        template <int N, typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13, typename P14, typename P15>
        static bsl::shared_ptr<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15), N> > createPrivateStaticMock(R targetFunc(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            // Create the Mock object
            bsl::shared_ptr<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15), N> > l_mockObj = bsl::make_shared<Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15), N> >(funcName);

            return l_mockObj;
        }

        // =========================================================================
        // createPrivateMock - Non-const private member functions
        // =========================================================================

        // Create a mock for a non-const private member function with 0 parameters
        template <int N, typename C, typename R>
        static bsl::shared_ptr<MockPrivate<R (C::*)(), N> > createPrivateMock(R targetFunc(), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            // Create the Mock object
            bsl::shared_ptr<MockPrivate<R (C::*)(), N> > l_mockObj = bsl::make_shared<MockPrivate<R (C::*)(), N> >(funcName);

            return l_mockObj;
        }

        // Create a mock for a non-const private member function with 1 parameter
        template <int N, typename C, typename R, typename P1>
        static bsl::shared_ptr<MockPrivate<R (C::*)(P1), N> > createPrivateMock(R targetFunc(P1), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            // Create the Mock object
            bsl::shared_ptr<MockPrivate<R (C::*)(P1), N> > l_mockObj = bsl::make_shared<MockPrivate<R (C::*)(P1), N> >(funcName);

            return l_mockObj;
        }

        // Create a mock for a non-const private member function with 2 parameters
        template <int N, typename C, typename R, typename P1, typename P2>
        static bsl::shared_ptr<MockPrivate<R (C::*)(P1, P2), N> > createPrivateMock(R targetFunc(P1, P2), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            // Create the Mock object
            bsl::shared_ptr<MockPrivate<R (C::*)(P1, P2), N> > l_mockObj = bsl::make_shared<MockPrivate<R (C::*)(P1, P2), N> >(funcName);

            return l_mockObj;
        }

        // Create a mock for a non-const private member function with 3 parameters
        template <int N, typename C, typename R, typename P1, typename P2, typename P3>
        static bsl::shared_ptr<MockPrivate<R (C::*)(P1, P2, P3), N> > createPrivateMock(R targetFunc(P1, P2, P3), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            // Create the Mock object
            bsl::shared_ptr<MockPrivate<R (C::*)(P1, P2, P3), N> > l_mockObj = bsl::make_shared<MockPrivate<R (C::*)(P1, P2, P3), N> >(funcName);

            return l_mockObj;
        }

        // Create a mock for a non-const private member function with 4 parameters
        template <int N, typename C, typename R, typename P1, typename P2, typename P3, typename P4>
        static bsl::shared_ptr<MockPrivate<R (C::*)(P1, P2, P3, P4), N> > createPrivateMock(R targetFunc(P1, P2, P3, P4), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            // Create the Mock object
            bsl::shared_ptr<MockPrivate<R (C::*)(P1, P2, P3, P4), N> > l_mockObj = bsl::make_shared<MockPrivate<R (C::*)(P1, P2, P3, P4), N> >(funcName);

            return l_mockObj;
        }

        // Create a mock for a non-const private member function with 5 parameters
        template <int N, typename C, typename R, typename P1, typename P2, typename P3, typename P4, typename P5>
        static bsl::shared_ptr<MockPrivate<R (C::*)(P1, P2, P3, P4, P5), N> > createPrivateMock(R targetFunc(P1, P2, P3, P4, P5), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            // Create the Mock object
            bsl::shared_ptr<MockPrivate<R (C::*)(P1, P2, P3, P4, P5), N> > l_mockObj = bsl::make_shared<MockPrivate<R (C::*)(P1, P2, P3, P4, P5), N> >(funcName);

            return l_mockObj;
        }

        // Create a mock for a non-const private member function with 6 parameters
        template <int N, typename C, typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6>
        static bsl::shared_ptr<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6), N> > createPrivateMock(R targetFunc(P1, P2, P3, P4, P5, P6), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            // Create the Mock object
            bsl::shared_ptr<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6), N> > l_mockObj = bsl::make_shared<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6), N> >(funcName);

            return l_mockObj;
        }

        // Create a mock for a non-const private member function with 7 parameters
        template <int N, typename C, typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7>
        static bsl::shared_ptr<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7), N> > createPrivateMock(R targetFunc(P1, P2, P3, P4, P5, P6, P7), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            // Create the Mock object
            bsl::shared_ptr<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7), N> > l_mockObj = bsl::make_shared<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7), N> >(funcName);

            return l_mockObj;
        }

        // Create a mock for a non-const private member function with 8 parameters
        template <int N, typename C, typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8>
        static bsl::shared_ptr<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8), N> > createPrivateMock(R targetFunc(P1, P2, P3, P4, P5, P6, P7, P8), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            // Create the Mock object
            bsl::shared_ptr<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8), N> > l_mockObj = bsl::make_shared<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8), N> >(funcName);

            return l_mockObj;
        }

        // Create a mock for a non-const private member function with 9 parameters
        template <int N, typename C, typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9>
        static bsl::shared_ptr<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9), N> > createPrivateMock(R targetFunc(P1, P2, P3, P4, P5, P6, P7, P8, P9), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            // Create the Mock object
            bsl::shared_ptr<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9), N> > l_mockObj = bsl::make_shared<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9), N> >(funcName);

            return l_mockObj;
        }

        // Create a mock for a non-const private member function with 10 parameters
        template <int N, typename C, typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8,
            typename P9, typename P10>
        static bsl::shared_ptr<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10), N> > createPrivateMock(R targetFunc(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            // Create the Mock object
            bsl::shared_ptr<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10), N> > l_mockObj = bsl::make_shared<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10), N> >(funcName);

            return l_mockObj;
        }

        // Create a mock for a non-const private member function with 11 parameters
        template <int N, typename C, typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8,
            typename P9, typename P10, typename P11>
        static bsl::shared_ptr<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11), N> > createPrivateMock(R targetFunc(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            // Create the Mock object
            bsl::shared_ptr<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11), N> > l_mockObj = bsl::make_shared<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11), N> >(funcName);

            return l_mockObj;
        }

        // Create a mock for a non-const private member function with 12 parameters
        template <int N, typename C, typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8,
            typename P9, typename P10, typename P11, typename P12>
        static bsl::shared_ptr<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12), N> > createPrivateMock(R targetFunc(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            // Create the Mock object
            bsl::shared_ptr<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12), N> > l_mockObj = bsl::make_shared<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12), N> >(funcName);

            return l_mockObj;
        }

        // Create a mock for a non-const private member function with 13 parameters
        template <int N, typename C, typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8,
            typename P9, typename P10, typename P11, typename P12, typename P13>
        static bsl::shared_ptr<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13), N> > createPrivateMock(R targetFunc(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            // Create the Mock object
            bsl::shared_ptr<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13), N> > l_mockObj = bsl::make_shared<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13), N> >(funcName);

            return l_mockObj;
        }

        // Create a mock for a non-const private member function with 14 parameters
        template <int N, typename C, typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8,
            typename P9, typename P10, typename P11, typename P12, typename P13, typename P14>
        static bsl::shared_ptr<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14), N> > createPrivateMock(R targetFunc(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            // Create the Mock object
            bsl::shared_ptr<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14), N> > l_mockObj = bsl::make_shared<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14), N> >(funcName);

            return l_mockObj;
        }

        // Create a mock for a non-const private member function with 15 parameters
        template <int N, typename C, typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8,
            typename P9, typename P10, typename P11, typename P12, typename P13, typename P14, typename P15>
        static bsl::shared_ptr<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15), N> > createPrivateMock(R targetFunc(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            // Create the Mock object
            bsl::shared_ptr<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15), N> > l_mockObj = bsl::make_shared<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15), N> >(funcName);

            return l_mockObj;
        }

        // =========================================================================
        // createPrivateMockConst - Const private member functions
        // =========================================================================

        // Create a mock for a const private member function with 0 parameters
        template <int N, typename C, typename R>
        static bsl::shared_ptr<MockPrivate<R (C::*)() const, N> > createPrivateMockConst(R targetFunc(), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            // Create the Mock object
            bsl::shared_ptr<MockPrivate<R (C::*)() const, N> > l_mockObj = bsl::make_shared<MockPrivate<R (C::*)() const, N> >(funcName);

            return l_mockObj;
        }

        // Create a mock for a const private member function with 1 parameter
        template <int N, typename C, typename R, typename P1>
        static bsl::shared_ptr<MockPrivate<R (C::*)(P1) const, N> > createPrivateMockConst(R targetFunc(P1), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            // Create the Mock object
            bsl::shared_ptr<MockPrivate<R (C::*)(P1) const, N> > l_mockObj = bsl::make_shared<MockPrivate<R (C::*)(P1) const, N> >(funcName);

            return l_mockObj;
        }

        // Create a mock for a const private member function with 2 parameters
        template <int N, typename C, typename R, typename P1, typename P2>
        static bsl::shared_ptr<MockPrivate<R (C::*)(P1, P2) const, N> > createPrivateMockConst(R targetFunc(P1, P2), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            // Create the Mock object
            bsl::shared_ptr<MockPrivate<R (C::*)(P1, P2) const, N> > l_mockObj = bsl::make_shared<MockPrivate<R (C::*)(P1, P2) const, N> >(funcName);

            return l_mockObj;
        }

        // Create a mock for a const private member function with 3 parameters
        template <int N, typename C, typename R, typename P1, typename P2, typename P3>
        static bsl::shared_ptr<MockPrivate<R (C::*)(P1, P2, P3) const, N> > createPrivateMockConst(R targetFunc(P1, P2, P3), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            // Create the Mock object
            bsl::shared_ptr<MockPrivate<R (C::*)(P1, P2, P3) const, N> > l_mockObj = bsl::make_shared<MockPrivate<R (C::*)(P1, P2, P3) const, N> >(funcName);

            return l_mockObj;
        }

        // Create a mock for a const private member function with 4 parameters
        template <int N, typename C, typename R, typename P1, typename P2, typename P3, typename P4>
        static bsl::shared_ptr<MockPrivate<R (C::*)(P1, P2, P3, P4) const, N> > createPrivateMockConst(R targetFunc(P1, P2, P3, P4), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            // Create the Mock object
            bsl::shared_ptr<MockPrivate<R (C::*)(P1, P2, P3, P4) const, N> > l_mockObj = bsl::make_shared<MockPrivate<R (C::*)(P1, P2, P3, P4) const, N> >(funcName);

            return l_mockObj;
        }

        // Create a mock for a const private member function with 5 parameters
        template <int N, typename C, typename R, typename P1, typename P2, typename P3, typename P4, typename P5>
        static bsl::shared_ptr<MockPrivate<R (C::*)(P1, P2, P3, P4, P5) const, N> > createPrivateMockConst(R targetFunc(P1, P2, P3, P4, P5), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            // Create the Mock object
            bsl::shared_ptr<MockPrivate<R (C::*)(P1, P2, P3, P4, P5) const, N> > l_mockObj = bsl::make_shared<MockPrivate<R (C::*)(P1, P2, P3, P4, P5) const, N> >(funcName);

            return l_mockObj;
        }

        // Create a mock for a const private member function with 6 parameters
        template <int N, typename C, typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6>
        static bsl::shared_ptr<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6) const, N> > createPrivateMockConst(R targetFunc(P1, P2, P3, P4, P5, P6), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            // Create the Mock object
            bsl::shared_ptr<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6) const, N> > l_mockObj = bsl::make_shared<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6) const, N> >(funcName);

            return l_mockObj;
        }

        // Create a mock for a const private member function with 7 parameters
        template <int N, typename C, typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7>
        static bsl::shared_ptr<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7) const, N> > createPrivateMockConst(R targetFunc(P1, P2, P3, P4, P5, P6, P7), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            // Create the Mock object
            bsl::shared_ptr<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7) const, N> > l_mockObj = bsl::make_shared<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7) const, N> >(funcName);

            return l_mockObj;
        }

        // Create a mock for a const private member function with 8 parameters
        template <int N, typename C, typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8>
        static bsl::shared_ptr<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8) const, N> > createPrivateMockConst(R targetFunc(P1, P2, P3, P4, P5, P6, P7, P8), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            // Create the Mock object
            bsl::shared_ptr<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8) const, N> > l_mockObj = bsl::make_shared<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8) const, N> >(funcName);

            return l_mockObj;
        }

        // Create a mock for a const private member function with 9 parameters
        template <int N, typename C, typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8,
            typename P9>
        static bsl::shared_ptr<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9) const, N> > createPrivateMockConst(R targetFunc(P1, P2, P3, P4, P5, P6, P7, P8, P9), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            // Create the Mock object
            bsl::shared_ptr<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9) const, N> > l_mockObj = bsl::make_shared<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9) const, N> >(funcName);

            return l_mockObj;
        }

        // Create a mock for a const private member function with 10 parameters
        template <int N, typename C, typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8,
            typename P9, typename P10>
        static bsl::shared_ptr<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10) const, N> > createPrivateMockConst(R targetFunc(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            // Create the Mock object
            bsl::shared_ptr<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10) const, N> > l_mockObj = bsl::make_shared<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10) const, N> >(funcName);

            return l_mockObj;
        }

        // Create a mock for a const private member function with 11 parameters
        template <int N, typename C, typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8,
            typename P9, typename P10, typename P11>
        static bsl::shared_ptr<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11) const, N> > createPrivateMockConst(R targetFunc(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            // Create the Mock object
            bsl::shared_ptr<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11) const, N> > l_mockObj = bsl::make_shared<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11) const, N> >(funcName);

            return l_mockObj;
        }

        // Create a mock for a const private member function with 12 parameters
        template <int N, typename C, typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8,
            typename P9, typename P10, typename P11, typename P12>
        static bsl::shared_ptr<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12) const, N> > createPrivateMockConst(R targetFunc(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            // Create the Mock object
            bsl::shared_ptr<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12) const, N> > l_mockObj = bsl::make_shared<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12) const, N> >(funcName);

            return l_mockObj;
        }

        // Create a mock for a const private member function with 13 parameters
        template <int N, typename C, typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8,
            typename P9, typename P10, typename P11, typename P12, typename P13>
        static bsl::shared_ptr<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13) const, N> > createPrivateMockConst(R targetFunc(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            // Create the Mock object
            bsl::shared_ptr<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13) const, N> > l_mockObj = bsl::make_shared<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13) const, N> >(funcName);

            return l_mockObj;
        }

        // Create a mock for a const private member function with 14 parameters
        template <int N, typename C, typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8,
            typename P9, typename P10, typename P11, typename P12, typename P13, typename P14>
        static bsl::shared_ptr<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14) const, N> > createPrivateMockConst(R targetFunc(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            // Create the Mock object
            bsl::shared_ptr<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14) const, N> > l_mockObj = bsl::make_shared<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14) const, N> >(funcName);

            return l_mockObj;
        }

        // Create a mock for a const private member function with 15 parameters
        template <int N, typename C, typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8,
            typename P9, typename P10, typename P11, typename P12, typename P13, typename P14, typename P15>
        static bsl::shared_ptr<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15) const, N> > createPrivateMockConst(R targetFunc(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15), const bsl::string& funcName)
        {
            // targetFunc is used only for template type deduction of R and P...
            (void)targetFunc;
            // Create the Mock object
            bsl::shared_ptr<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15) const, N> > l_mockObj = bsl::make_shared<MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15) const, N> >(funcName);

            return l_mockObj;
        }
    };

}
}

#endif
