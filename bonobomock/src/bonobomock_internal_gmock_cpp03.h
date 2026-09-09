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

#ifndef INCLUDED_BONOBOMOCK_INTERNAL_GMOCK_CPP03
#define INCLUDED_BONOBOMOCK_INTERNAL_GMOCK_CPP03

#if !defined(INCLUDED_BONOBOMOCK_API) && !defined(BONOBO_MOCK_BUILDING_LIBRARY)
    #error "This is a private header. Directly including it is a contract violation and undefined behavior."
#endif

#include <bonobomock_internal_base.h>

#include <bsl_string.h>

#include <gmock/gmock.h>

namespace BloombergLP {
namespace bonobomock {

    template <typename T>
    class GMock;

    template <typename R>
    class GMock<R()> : public MockBase {
    public:
        GMock(const bsl::string& funcName)
            : d_funcName(funcName)
        {
        }

        virtual ~GMock() { }

        R bonobomockInternalForwardFunc()
        {
            d_gmock.SetOwnerAndName(this, d_funcName.c_str());
            return d_gmock.Invoke();
        }

        ::testing::MockSpec<R()> gmock_bonobomockInternalForwardFunc()
        {
            d_gmock.RegisterOwner(this);
            return d_gmock.With();
        }

        void restore() { }

        ::testing::FunctionMocker<R()> d_gmock;

    private:
        bsl::string d_funcName;
    };

    template <typename R, typename P1>
    class GMock<R(P1)> : public MockBase {
    public:
        GMock(const bsl::string& funcName)
            : d_funcName(funcName)
        {
        }

        virtual ~GMock() { }

        R bonobomockInternalForwardFunc(P1 p1)
        {
            d_gmock.SetOwnerAndName(this, d_funcName.c_str());
            return d_gmock.Invoke(p1);
        }

        ::testing::MockSpec<R(P1)> gmock_bonobomockInternalForwardFunc(const ::testing::Matcher<P1>& p1)
        {
            d_gmock.RegisterOwner(this);
            return d_gmock.With(p1);
        }

        void restore() { }

        ::testing::FunctionMocker<R(P1)> d_gmock;

    private:
        bsl::string d_funcName;
    };

    template <typename R, typename P1, typename P2>
    class GMock<R(P1, P2)> : public MockBase {
    public:
        GMock(const bsl::string& funcName)
            : d_funcName(funcName)
        {
        }

        virtual ~GMock() { }

        R bonobomockInternalForwardFunc(P1 p1, P2 p2)
        {
            d_gmock.SetOwnerAndName(this, d_funcName.c_str());
            return d_gmock.Invoke(p1, p2);
        }

        ::testing::MockSpec<R(P1, P2)> gmock_bonobomockInternalForwardFunc(const ::testing::Matcher<P1>& p1, const ::testing::Matcher<P2>& p2)
        {
            d_gmock.RegisterOwner(this);
            return d_gmock.With(p1, p2);
        }

        void restore() { }

        ::testing::FunctionMocker<R(P1, P2)> d_gmock;

    private:
        bsl::string d_funcName;
    };

    template <typename R, typename P1, typename P2, typename P3>
    class GMock<R(P1, P2, P3)> : public MockBase {
    public:
        GMock(const bsl::string& funcName)
            : d_funcName(funcName)
        {
        }

        virtual ~GMock() { }

        R bonobomockInternalForwardFunc(P1 p1, P2 p2, P3 p3)
        {
            d_gmock.SetOwnerAndName(this, d_funcName.c_str());
            return d_gmock.Invoke(p1, p2, p3);
        }

        ::testing::MockSpec<R(P1, P2, P3)> gmock_bonobomockInternalForwardFunc(const ::testing::Matcher<P1>& p1, const ::testing::Matcher<P2>& p2,
            const ::testing::Matcher<P3>& p3)
        {
            d_gmock.RegisterOwner(this);
            return d_gmock.With(p1, p2, p3);
        }

        void restore() { }

        ::testing::FunctionMocker<R(P1, P2, P3)> d_gmock;

    private:
        bsl::string d_funcName;
    };

    template <typename R, typename P1, typename P2, typename P3, typename P4>
    class GMock<R(P1, P2, P3, P4)> : public MockBase {
    public:
        GMock(const bsl::string& funcName)
            : d_funcName(funcName)
        {
        }

        virtual ~GMock() { }

        R bonobomockInternalForwardFunc(P1 p1, P2 p2, P3 p3, P4 p4)
        {
            d_gmock.SetOwnerAndName(this, d_funcName.c_str());
            return d_gmock.Invoke(p1, p2, p3, p4);
        }

        ::testing::MockSpec<R(P1, P2, P3, P4)> gmock_bonobomockInternalForwardFunc(const ::testing::Matcher<P1>& p1, const ::testing::Matcher<P2>& p2,
            const ::testing::Matcher<P3>& p3, const ::testing::Matcher<P4>& p4)
        {
            d_gmock.RegisterOwner(this);
            return d_gmock.With(p1, p2, p3, p4);
        }

        void restore() { }

        ::testing::FunctionMocker<R(P1, P2, P3, P4)> d_gmock;

    private:
        bsl::string d_funcName;
    };

    template <typename R, typename P1, typename P2, typename P3, typename P4, typename P5>
    class GMock<R(P1, P2, P3, P4, P5)> : public MockBase {
    public:
        GMock(const bsl::string& funcName)
            : d_funcName(funcName)
        {
        }

        virtual ~GMock() { }

        R bonobomockInternalForwardFunc(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5)
        {
            d_gmock.SetOwnerAndName(this, d_funcName.c_str());
            return d_gmock.Invoke(p1, p2, p3, p4, p5);
        }

        ::testing::MockSpec<R(P1, P2, P3, P4, P5)> gmock_bonobomockInternalForwardFunc(
            const ::testing::Matcher<P1>& p1,
            const ::testing::Matcher<P2>& p2,
            const ::testing::Matcher<P3>& p3,
            const ::testing::Matcher<P4>& p4,
            const ::testing::Matcher<P5>& p5)
        {
            d_gmock.RegisterOwner(this);
            return d_gmock.With(p1, p2, p3, p4, p5);
        }

        void restore() { }

        ::testing::FunctionMocker<R(P1, P2, P3, P4, P5)> d_gmock;

    private:
        bsl::string d_funcName;
    };

    template <typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6>
    class GMock<R(P1, P2, P3, P4, P5, P6)> : public MockBase {
    public:
        GMock(const bsl::string& funcName)
            : d_funcName(funcName)
        {
        }

        virtual ~GMock() { }

        R bonobomockInternalForwardFunc(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6)
        {
            d_gmock.SetOwnerAndName(this, d_funcName.c_str());
            return d_gmock.Invoke(p1, p2, p3, p4, p5, p6);
        }

        ::testing::MockSpec<R(P1, P2, P3, P4, P5, P6)> gmock_bonobomockInternalForwardFunc(
            const ::testing::Matcher<P1>& p1,
            const ::testing::Matcher<P2>& p2,
            const ::testing::Matcher<P3>& p3,
            const ::testing::Matcher<P4>& p4,
            const ::testing::Matcher<P5>& p5,
            const ::testing::Matcher<P6>& p6)
        {
            d_gmock.RegisterOwner(this);
            return d_gmock.With(p1, p2, p3, p4, p5, p6);
        }

        void restore() { }

        ::testing::FunctionMocker<R(P1, P2, P3, P4, P5, P6)> d_gmock;

    private:
        bsl::string d_funcName;
    };

    template <typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7>
    class GMock<R(P1, P2, P3, P4, P5, P6, P7)> : public MockBase {
    public:
        GMock(const bsl::string& funcName)
            : d_funcName(funcName)
        {
        }

        virtual ~GMock() { }

        R bonobomockInternalForwardFunc(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6, P7 p7)
        {
            d_gmock.SetOwnerAndName(this, d_funcName.c_str());
            return d_gmock.Invoke(p1, p2, p3, p4, p5, p6, p7);
        }

        ::testing::MockSpec<R(P1, P2, P3, P4, P5, P6, P7)> gmock_bonobomockInternalForwardFunc(
            const ::testing::Matcher<P1>& p1,
            const ::testing::Matcher<P2>& p2,
            const ::testing::Matcher<P3>& p3,
            const ::testing::Matcher<P4>& p4,
            const ::testing::Matcher<P5>& p5,
            const ::testing::Matcher<P6>& p6,
            const ::testing::Matcher<P7>& p7)
        {
            d_gmock.RegisterOwner(this);
            return d_gmock.With(p1, p2, p3, p4, p5, p6, p7);
        }

        void restore() { }

        ::testing::FunctionMocker<R(P1, P2, P3, P4, P5, P6, P7)> d_gmock;

    private:
        bsl::string d_funcName;
    };

    template <typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
        typename P7, typename P8>
    class GMock<R(P1, P2, P3, P4, P5, P6, P7, P8)> : public MockBase {
    public:
        GMock(const bsl::string& funcName)
            : d_funcName(funcName)
        {
        }

        virtual ~GMock() { }

        R bonobomockInternalForwardFunc(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6, P7 p7, P8 p8)
        {
            d_gmock.SetOwnerAndName(this, d_funcName.c_str());
            return d_gmock.Invoke(p1, p2, p3, p4, p5, p6, p7, p8);
        }

        ::testing::MockSpec<R(P1, P2, P3, P4, P5, P6, P7, P8)> gmock_bonobomockInternalForwardFunc(
            const ::testing::Matcher<P1>& p1,
            const ::testing::Matcher<P2>& p2,
            const ::testing::Matcher<P3>& p3,
            const ::testing::Matcher<P4>& p4,
            const ::testing::Matcher<P5>& p5,
            const ::testing::Matcher<P6>& p6,
            const ::testing::Matcher<P7>& p7,
            const ::testing::Matcher<P8>& p8)
        {
            d_gmock.RegisterOwner(this);
            return d_gmock.With(p1, p2, p3, p4, p5, p6, p7, p8);
        }

        void restore() { }

        ::testing::FunctionMocker<R(P1, P2, P3, P4, P5, P6, P7, P8)> d_gmock;

    private:
        bsl::string d_funcName;
    };

    template <typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
        typename P7, typename P8, typename P9>
    class GMock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9)> : public MockBase {
    public:
        GMock(const bsl::string& funcName)
            : d_funcName(funcName)
        {
        }

        virtual ~GMock() { }

        R bonobomockInternalForwardFunc(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6, P7 p7, P8 p8, P9 p9)
        {
            d_gmock.SetOwnerAndName(this, d_funcName.c_str());
            return d_gmock.Invoke(p1, p2, p3, p4, p5, p6, p7, p8, p9);
        }

        ::testing::MockSpec<R(P1, P2, P3, P4, P5, P6, P7, P8, P9)> gmock_bonobomockInternalForwardFunc(
            const ::testing::Matcher<P1>& p1,
            const ::testing::Matcher<P2>& p2,
            const ::testing::Matcher<P3>& p3,
            const ::testing::Matcher<P4>& p4,
            const ::testing::Matcher<P5>& p5,
            const ::testing::Matcher<P6>& p6,
            const ::testing::Matcher<P7>& p7,
            const ::testing::Matcher<P8>& p8,
            const ::testing::Matcher<P9>& p9)
        {
            d_gmock.RegisterOwner(this);
            return d_gmock.With(p1, p2, p3, p4, p5, p6, p7, p8, p9);
        }

        void restore() { }

        ::testing::FunctionMocker<R(P1, P2, P3, P4, P5, P6, P7, P8, P9)> d_gmock;

    private:
        bsl::string d_funcName;
    };

    template <typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
        typename P7, typename P8, typename P9, typename P10>
    class GMock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10)> : public MockBase {
    public:
        GMock(const bsl::string& funcName)
            : d_funcName(funcName)
        {
        }

        virtual ~GMock() { }

        R bonobomockInternalForwardFunc(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6, P7 p7, P8 p8, P9 p9, P10 p10)
        {
            d_gmock.SetOwnerAndName(this, d_funcName.c_str());
            return d_gmock.Invoke(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10);
        }

        ::testing::MockSpec<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10)> gmock_bonobomockInternalForwardFunc(
            const ::testing::Matcher<P1>& p1,
            const ::testing::Matcher<P2>& p2,
            const ::testing::Matcher<P3>& p3,
            const ::testing::Matcher<P4>& p4,
            const ::testing::Matcher<P5>& p5,
            const ::testing::Matcher<P6>& p6,
            const ::testing::Matcher<P7>& p7,
            const ::testing::Matcher<P8>& p8,
            const ::testing::Matcher<P9>& p9,
            const ::testing::Matcher<P10>& p10)
        {
            d_gmock.RegisterOwner(this);
            return d_gmock.With(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10);
        }

        void restore() { }

        ::testing::FunctionMocker<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10)> d_gmock;

    private:
        bsl::string d_funcName;
    };

    template <typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
        typename P7, typename P8, typename P9, typename P10, typename P11>
    class GMock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11)> : public MockBase {
    public:
        GMock(const bsl::string& funcName)
            : d_funcName(funcName)
        {
        }

        virtual ~GMock() { }

        R bonobomockInternalForwardFunc(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6, P7 p7, P8 p8, P9 p9, P10 p10, P11 p11)
        {
            d_gmock.SetOwnerAndName(this, d_funcName.c_str());
            return d_gmock.Invoke(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11);
        }

        ::testing::MockSpec<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11)> gmock_bonobomockInternalForwardFunc(
            const ::testing::Matcher<P1>& p1,
            const ::testing::Matcher<P2>& p2,
            const ::testing::Matcher<P3>& p3,
            const ::testing::Matcher<P4>& p4,
            const ::testing::Matcher<P5>& p5,
            const ::testing::Matcher<P6>& p6,
            const ::testing::Matcher<P7>& p7,
            const ::testing::Matcher<P8>& p8,
            const ::testing::Matcher<P9>& p9,
            const ::testing::Matcher<P10>& p10,
            const ::testing::Matcher<P11>& p11)
        {
            d_gmock.RegisterOwner(this);
            return d_gmock.With(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11);
        }

        void restore() { }

        ::testing::FunctionMocker<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11)> d_gmock;

    private:
        bsl::string d_funcName;
    };

    template <typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
        typename P7, typename P8, typename P9, typename P10, typename P11, typename P12>
    class GMock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12)> : public MockBase {
    public:
        GMock(const bsl::string& funcName)
            : d_funcName(funcName)
        {
        }

        virtual ~GMock() { }

        R bonobomockInternalForwardFunc(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6, P7 p7, P8 p8, P9 p9, P10 p10, P11 p11, P12 p12)
        {
            d_gmock.SetOwnerAndName(this, d_funcName.c_str());
            return d_gmock.Invoke(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12);
        }

        ::testing::MockSpec<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12)> gmock_bonobomockInternalForwardFunc(
            const ::testing::Matcher<P1>& p1,
            const ::testing::Matcher<P2>& p2,
            const ::testing::Matcher<P3>& p3,
            const ::testing::Matcher<P4>& p4,
            const ::testing::Matcher<P5>& p5,
            const ::testing::Matcher<P6>& p6,
            const ::testing::Matcher<P7>& p7,
            const ::testing::Matcher<P8>& p8,
            const ::testing::Matcher<P9>& p9,
            const ::testing::Matcher<P10>& p10,
            const ::testing::Matcher<P11>& p11,
            const ::testing::Matcher<P12>& p12)
        {
            d_gmock.RegisterOwner(this);
            return d_gmock.With(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12);
        }

        void restore() { }

        ::testing::FunctionMocker<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12)> d_gmock;

    private:
        bsl::string d_funcName;
    };

    template <typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
        typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13>
    class GMock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13)> : public MockBase {
    public:
        GMock(const bsl::string& funcName)
            : d_funcName(funcName)
        {
        }

        virtual ~GMock() { }

        R bonobomockInternalForwardFunc(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6, P7 p7, P8 p8, P9 p9, P10 p10, P11 p11, P12 p12, P13 p13)
        {
            d_gmock.SetOwnerAndName(this, d_funcName.c_str());
            return d_gmock.Invoke(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13);
        }

        ::testing::MockSpec<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13)> gmock_bonobomockInternalForwardFunc(
            const ::testing::Matcher<P1>& p1,
            const ::testing::Matcher<P2>& p2,
            const ::testing::Matcher<P3>& p3,
            const ::testing::Matcher<P4>& p4,
            const ::testing::Matcher<P5>& p5,
            const ::testing::Matcher<P6>& p6,
            const ::testing::Matcher<P7>& p7,
            const ::testing::Matcher<P8>& p8,
            const ::testing::Matcher<P9>& p9,
            const ::testing::Matcher<P10>& p10,
            const ::testing::Matcher<P11>& p11,
            const ::testing::Matcher<P12>& p12,
            const ::testing::Matcher<P13>& p13)
        {
            d_gmock.RegisterOwner(this);
            return d_gmock.With(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13);
        }

        void restore() { }

        ::testing::FunctionMocker<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13)> d_gmock;

    private:
        bsl::string d_funcName;
    };

    template <typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
        typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13, typename P14>
    class GMock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14)> : public MockBase {
    public:
        GMock(const bsl::string& funcName)
            : d_funcName(funcName)
        {
        }

        virtual ~GMock() { }

        R bonobomockInternalForwardFunc(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6, P7 p7, P8 p8, P9 p9, P10 p10, P11 p11, P12 p12, P13 p13, P14 p14)
        {
            d_gmock.SetOwnerAndName(this, d_funcName.c_str());
            return d_gmock.Invoke(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14);
        }

        ::testing::MockSpec<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14)> gmock_bonobomockInternalForwardFunc(
            const ::testing::Matcher<P1>& p1,
            const ::testing::Matcher<P2>& p2,
            const ::testing::Matcher<P3>& p3,
            const ::testing::Matcher<P4>& p4,
            const ::testing::Matcher<P5>& p5,
            const ::testing::Matcher<P6>& p6,
            const ::testing::Matcher<P7>& p7,
            const ::testing::Matcher<P8>& p8,
            const ::testing::Matcher<P9>& p9,
            const ::testing::Matcher<P10>& p10,
            const ::testing::Matcher<P11>& p11,
            const ::testing::Matcher<P12>& p12,
            const ::testing::Matcher<P13>& p13,
            const ::testing::Matcher<P14>& p14)
        {
            d_gmock.RegisterOwner(this);
            return d_gmock.With(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14);
        }

        void restore() { }

        ::testing::FunctionMocker<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14)> d_gmock;

    private:
        bsl::string d_funcName;
    };

    template <typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
        typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13, typename P14, typename P15>
    class GMock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15)> : public MockBase {
    public:
        GMock(const bsl::string& funcName)
            : d_funcName(funcName)
        {
        }

        virtual ~GMock() { }

        R bonobomockInternalForwardFunc(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6, P7 p7, P8 p8, P9 p9, P10 p10, P11 p11, P12 p12, P13 p13, P14 p14, P15 p15)
        {
            d_gmock.SetOwnerAndName(this, d_funcName.c_str());
            return d_gmock.Invoke(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15);
        }

        ::testing::MockSpec<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15)> gmock_bonobomockInternalForwardFunc(
            const ::testing::Matcher<P1>& p1,
            const ::testing::Matcher<P2>& p2,
            const ::testing::Matcher<P3>& p3,
            const ::testing::Matcher<P4>& p4,
            const ::testing::Matcher<P5>& p5,
            const ::testing::Matcher<P6>& p6,
            const ::testing::Matcher<P7>& p7,
            const ::testing::Matcher<P8>& p8,
            const ::testing::Matcher<P9>& p9,
            const ::testing::Matcher<P10>& p10,
            const ::testing::Matcher<P11>& p11,
            const ::testing::Matcher<P12>& p12,
            const ::testing::Matcher<P13>& p13,
            const ::testing::Matcher<P14>& p14,
            const ::testing::Matcher<P15>& p15)
        {
            d_gmock.RegisterOwner(this);
            return d_gmock.With(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15);
        }

        void restore() { }

        ::testing::FunctionMocker<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15)> d_gmock;

    private:
        bsl::string d_funcName;
    };

    template <typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
        typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13, typename P14, typename P15, typename P16>
    class GMock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15, P16)> : public MockBase {
    public:
        GMock(const bsl::string& funcName)
            : d_funcName(funcName)
        {
        }

        virtual ~GMock() { }

        R bonobomockInternalForwardFunc(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6, P7 p7, P8 p8, P9 p9, P10 p10, P11 p11, P12 p12, P13 p13, P14 p14, P15 p15, P16 p16)
        {
            d_gmock.SetOwnerAndName(this, d_funcName.c_str());
            return d_gmock.Invoke(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15, p16);
        }

        ::testing::MockSpec<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15, P16)> gmock_bonobomockInternalForwardFunc(
            const ::testing::Matcher<P1>& p1,
            const ::testing::Matcher<P2>& p2,
            const ::testing::Matcher<P3>& p3,
            const ::testing::Matcher<P4>& p4,
            const ::testing::Matcher<P5>& p5,
            const ::testing::Matcher<P6>& p6,
            const ::testing::Matcher<P7>& p7,
            const ::testing::Matcher<P8>& p8,
            const ::testing::Matcher<P9>& p9,
            const ::testing::Matcher<P10>& p10,
            const ::testing::Matcher<P11>& p11,
            const ::testing::Matcher<P12>& p12,
            const ::testing::Matcher<P13>& p13,
            const ::testing::Matcher<P14>& p14,
            const ::testing::Matcher<P15>& p15,
            const ::testing::Matcher<P16>& p16)
        {
            d_gmock.RegisterOwner(this);
            return d_gmock.With(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15, p16);
        }

        void restore() { }

        ::testing::FunctionMocker<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15, P16)> d_gmock;

    private:
        bsl::string d_funcName;
    };

}
}

#endif
