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

#ifndef INCLUDED_BONOBOMOCK_INTERNAL_MOCKER_CPP03
#define INCLUDED_BONOBOMOCK_INTERNAL_MOCKER_CPP03

#if !defined(INCLUDED_BONOBOMOCK_API) && !defined(BONOBO_MOCK_BUILDING_LIBRARY)
    #error "This is a private header. Directly including it is a contract violation and undefined behavior."
#endif

#include <bonobomock_internal_code_address.h>
#include <bonobomock_internal_gmock_cpp03.h>
#include <bonobomock_internal_patch.h>
#include <bonobomock_internal_private_address_resolver.h>
#include <bonobomock_internal_virtual_resolve.h>

#include <cstring>

#include <bslmt_once.h>

#include <cstring>

namespace BloombergLP {
namespace bonobomock {

    template <typename T, int N>
    class Mock;

    template <typename T, int N>
    class MockVirtual;

    template <typename T, int N>
    class MockPrivate;

    template <typename T, int N>
    class MockManager;

    template <typename T, int N>
    class MockVirtualManager;

    template <typename T, int N>
    class MockPrivateManager;

    template <typename R, int N>
    class MockManager<R(), N> {
    public:
        static MockManager& getInstance()
        {
            static MockManager* p = NULL;
            BSLMT_ONCE_DO
            {
                static MockManager self;
                p = &self;
            }
            return *p;
        }

        Mock<R(), N>*& get()
        {
            return d_obj;
        }

        void clear()
        {
            d_obj = NULL;
        }

    private:
        MockManager() { }
        MockManager(const MockManager& rhs);
        MockManager& operator=(const MockManager& rhs);

        Mock<R(), N>* d_obj;
    };

    template <typename R, typename P1, int N>
    class MockManager<R(P1), N> {
    public:
        static MockManager& getInstance()
        {
            static MockManager* p = NULL;
            BSLMT_ONCE_DO
            {
                static MockManager self;
                p = &self;
            }
            return *p;
        }

        Mock<R(P1), N>*& get()
        {
            return d_obj;
        }

        void clear()
        {
            d_obj = NULL;
        }

    private:
        MockManager() { }
        MockManager(const MockManager& rhs);
        MockManager& operator=(const MockManager& rhs);

        Mock<R(P1), N>* d_obj;
    };

    template <typename R, typename P1, typename P2, int N>
    class MockManager<R(P1, P2), N> {
    public:
        static MockManager& getInstance()
        {
            static MockManager* p = NULL;
            BSLMT_ONCE_DO
            {
                static MockManager self;
                p = &self;
            }
            return *p;
        }

        Mock<R(P1, P2), N>*& get()
        {
            return d_obj;
        }

        void clear()
        {
            d_obj = NULL;
        }

    private:
        MockManager() { }
        MockManager(const MockManager& rhs);
        MockManager& operator=(const MockManager& rhs);

        Mock<R(P1, P2), N>* d_obj;
    };

    template <typename R, typename P1, typename P2, typename P3, int N>
    class MockManager<R(P1, P2, P3), N> {
    public:
        static MockManager& getInstance()
        {
            static MockManager* p = NULL;
            BSLMT_ONCE_DO
            {
                static MockManager self;
                p = &self;
            }
            return *p;
        }

        Mock<R(P1, P2, P3), N>*& get()
        {
            return d_obj;
        }

        void clear()
        {
            d_obj = NULL;
        }

    private:
        MockManager() { }
        MockManager(const MockManager& rhs);
        MockManager& operator=(const MockManager& rhs);

        Mock<R(P1, P2, P3), N>* d_obj;
    };

    template <typename R, typename P1, typename P2, typename P3, typename P4, int N>
    class MockManager<R(P1, P2, P3, P4), N> {
    public:
        static MockManager& getInstance()
        {
            static MockManager* p = NULL;
            BSLMT_ONCE_DO
            {
                static MockManager self;
                p = &self;
            }
            return *p;
        }

        Mock<R(P1, P2, P3, P4), N>*& get()
        {
            return d_obj;
        }

        void clear()
        {
            d_obj = NULL;
        }

    private:
        MockManager() { }
        MockManager(const MockManager& rhs);
        MockManager& operator=(const MockManager& rhs);

        Mock<R(P1, P2, P3, P4), N>* d_obj;
    };

    template <typename R, typename P1, typename P2, typename P3, typename P4, typename P5, int N>
    class MockManager<R(P1, P2, P3, P4, P5), N> {
    public:
        static MockManager& getInstance()
        {
            static MockManager* p = NULL;
            BSLMT_ONCE_DO
            {
                static MockManager self;
                p = &self;
            }
            return *p;
        }

        Mock<R(P1, P2, P3, P4, P5), N>*& get()
        {
            return d_obj;
        }

        void clear()
        {
            d_obj = NULL;
        }

    private:
        MockManager() { }
        MockManager(const MockManager& rhs);
        MockManager& operator=(const MockManager& rhs);

        Mock<R(P1, P2, P3, P4, P5), N>* d_obj;
    };

    template <typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, int N>
    class MockManager<R(P1, P2, P3, P4, P5, P6), N> {
    public:
        static MockManager& getInstance()
        {
            static MockManager* p = NULL;
            BSLMT_ONCE_DO
            {
                static MockManager self;
                p = &self;
            }
            return *p;
        }

        Mock<R(P1, P2, P3, P4, P5, P6), N>*& get()
        {
            return d_obj;
        }

        void clear()
        {
            d_obj = NULL;
        }

    private:
        MockManager() { }
        MockManager(const MockManager& rhs);
        MockManager& operator=(const MockManager& rhs);

        Mock<R(P1, P2, P3, P4, P5, P6), N>* d_obj;
    };

    template <typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, int N>
    class MockManager<R(P1, P2, P3, P4, P5, P6, P7), N> {
    public:
        static MockManager& getInstance()
        {
            static MockManager* p = NULL;
            BSLMT_ONCE_DO
            {
                static MockManager self;
                p = &self;
            }
            return *p;
        }

        Mock<R(P1, P2, P3, P4, P5, P6, P7), N>*& get()
        {
            return d_obj;
        }

        void clear()
        {
            d_obj = NULL;
        }

    private:
        MockManager() { }
        MockManager(const MockManager& rhs);
        MockManager& operator=(const MockManager& rhs);

        Mock<R(P1, P2, P3, P4, P5, P6, P7), N>* d_obj;
    };

    template <typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
        typename P7, typename P8, int N>
    class MockManager<R(P1, P2, P3, P4, P5, P6, P7, P8), N> {
    public:
        static MockManager& getInstance()
        {
            static MockManager* p = NULL;
            BSLMT_ONCE_DO
            {
                static MockManager self;
                p = &self;
            }
            return *p;
        }

        Mock<R(P1, P2, P3, P4, P5, P6, P7, P8), N>*& get()
        {
            return d_obj;
        }

        void clear()
        {
            d_obj = NULL;
        }

    private:
        MockManager() { }
        MockManager(const MockManager& rhs);
        MockManager& operator=(const MockManager& rhs);

        Mock<R(P1, P2, P3, P4, P5, P6, P7, P8), N>* d_obj;
    };

    template <typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
        typename P7, typename P8, typename P9, int N>
    class MockManager<R(P1, P2, P3, P4, P5, P6, P7, P8, P9), N> {
    public:
        static MockManager& getInstance()
        {
            static MockManager* p = NULL;
            BSLMT_ONCE_DO
            {
                static MockManager self;
                p = &self;
            }
            return *p;
        }

        Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9), N>*& get()
        {
            return d_obj;
        }

        void clear()
        {
            d_obj = NULL;
        }

    private:
        MockManager() { }
        MockManager(const MockManager& rhs);
        MockManager& operator=(const MockManager& rhs);

        Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9), N>* d_obj;
    };

    template <typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
        typename P7, typename P8, typename P9, typename P10, int N>
    class MockManager<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10), N> {
    public:
        static MockManager& getInstance()
        {
            static MockManager* p = NULL;
            BSLMT_ONCE_DO
            {
                static MockManager self;
                p = &self;
            }
            return *p;
        }

        Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10), N>*& get()
        {
            return d_obj;
        }

        void clear()
        {
            d_obj = NULL;
        }

    private:
        MockManager() { }
        MockManager(const MockManager& rhs);
        MockManager& operator=(const MockManager& rhs);

        Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10), N>* d_obj;
    };

    template <typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
        typename P7, typename P8, typename P9, typename P10, typename P11, int N>
    class MockManager<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11), N> {
    public:
        static MockManager& getInstance()
        {
            static MockManager* p = NULL;
            BSLMT_ONCE_DO
            {
                static MockManager self;
                p = &self;
            }
            return *p;
        }

        Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11), N>*& get()
        {
            return d_obj;
        }

        void clear()
        {
            d_obj = NULL;
        }

    private:
        MockManager() { }
        MockManager(const MockManager& rhs);
        MockManager& operator=(const MockManager& rhs);

        Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11), N>* d_obj;
    };

    template <typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
        typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, int N>
    class MockManager<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12), N> {
    public:
        static MockManager& getInstance()
        {
            static MockManager* p = NULL;
            BSLMT_ONCE_DO
            {
                static MockManager self;
                p = &self;
            }
            return *p;
        }

        Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12), N>*& get()
        {
            return d_obj;
        }

        void clear()
        {
            d_obj = NULL;
        }

    private:
        MockManager() { }
        MockManager(const MockManager& rhs);
        MockManager& operator=(const MockManager& rhs);

        Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12), N>* d_obj;
    };

    template <typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
        typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13, int N>
    class MockManager<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13), N> {
    public:
        static MockManager& getInstance()
        {
            static MockManager* p = NULL;
            BSLMT_ONCE_DO
            {
                static MockManager self;
                p = &self;
            }
            return *p;
        }

        Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13), N>*& get()
        {
            return d_obj;
        }

        void clear()
        {
            d_obj = NULL;
        }

    private:
        MockManager() { }
        MockManager(const MockManager& rhs);
        MockManager& operator=(const MockManager& rhs);

        Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13), N>* d_obj;
    };

    template <typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
        typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13, typename P14, int N>
    class MockManager<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14), N> {
    public:
        static MockManager& getInstance()
        {
            static MockManager* p = NULL;
            BSLMT_ONCE_DO
            {
                static MockManager self;
                p = &self;
            }
            return *p;
        }

        Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14), N>*& get()
        {
            return d_obj;
        }

        void clear()
        {
            d_obj = NULL;
        }

    private:
        MockManager() { }
        MockManager(const MockManager& rhs);
        MockManager& operator=(const MockManager& rhs);

        Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14), N>* d_obj;
    };

    template <typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
        typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13, typename P14, typename P15, int N>
    class MockManager<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15), N> {
    public:
        static MockManager& getInstance()
        {
            static MockManager* p = NULL;
            BSLMT_ONCE_DO
            {
                static MockManager self;
                p = &self;
            }
            return *p;
        }

        Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15), N>*& get()
        {
            return d_obj;
        }

        void clear()
        {
            d_obj = NULL;
        }

    private:
        MockManager() { }
        MockManager(const MockManager& rhs);
        MockManager& operator=(const MockManager& rhs);

        Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15), N>* d_obj;
    };

    template <typename R, typename C, int N>
    class MockManager<R (C::*)(), N> {
    public:
        static MockManager& getInstance()
        {
            static MockManager* p = NULL;
            BSLMT_ONCE_DO
            {
                static MockManager self;
                p = &self;
            }
            return *p;
        }

        Mock<R (C::*)(), N>*& get()
        {
            return d_obj;
        }

        void clear()
        {
            d_obj = NULL;
        }

    private:
        MockManager() { }
        MockManager(const MockManager& rhs);
        MockManager& operator=(const MockManager& rhs);

        Mock<R (C::*)(), N>* d_obj;
    };

    template <typename R, typename C, typename P1, int N>
    class MockManager<R (C::*)(P1), N> {
    public:
        static MockManager& getInstance()
        {
            static MockManager* p = NULL;
            BSLMT_ONCE_DO
            {
                static MockManager self;
                p = &self;
            }
            return *p;
        }

        Mock<R (C::*)(P1), N>*& get()
        {
            return d_obj;
        }

        void clear()
        {
            d_obj = NULL;
        }

    private:
        MockManager() { }
        MockManager(const MockManager& rhs);
        MockManager& operator=(const MockManager& rhs);

        Mock<R (C::*)(P1), N>* d_obj;
    };

    template <typename R, typename C, typename P1, typename P2, int N>
    class MockManager<R (C::*)(P1, P2), N> {
    public:
        static MockManager& getInstance()
        {
            static MockManager* p = NULL;
            BSLMT_ONCE_DO
            {
                static MockManager self;
                p = &self;
            }
            return *p;
        }

        Mock<R (C::*)(P1, P2), N>*& get()
        {
            return d_obj;
        }

        void clear()
        {
            d_obj = NULL;
        }

    private:
        MockManager() { }
        MockManager(const MockManager& rhs);
        MockManager& operator=(const MockManager& rhs);

        Mock<R (C::*)(P1, P2), N>* d_obj;
    };

    template <typename R, typename C, typename P1, typename P2, typename P3, int N>
    class MockManager<R (C::*)(P1, P2, P3), N> {
    public:
        static MockManager& getInstance()
        {
            static MockManager* p = NULL;
            BSLMT_ONCE_DO
            {
                static MockManager self;
                p = &self;
            }
            return *p;
        }

        Mock<R (C::*)(P1, P2, P3), N>*& get()
        {
            return d_obj;
        }

        void clear()
        {
            d_obj = NULL;
        }

    private:
        MockManager() { }
        MockManager(const MockManager& rhs);
        MockManager& operator=(const MockManager& rhs);

        Mock<R (C::*)(P1, P2, P3), N>* d_obj;
    };

    template <typename R, typename C, typename P1, typename P2, typename P3, typename P4, int N>
    class MockManager<R (C::*)(P1, P2, P3, P4), N> {
    public:
        static MockManager& getInstance()
        {
            static MockManager* p = NULL;
            BSLMT_ONCE_DO
            {
                static MockManager self;
                p = &self;
            }
            return *p;
        }

        Mock<R (C::*)(P1, P2, P3, P4), N>*& get()
        {
            return d_obj;
        }

        void clear()
        {
            d_obj = NULL;
        }

    private:
        MockManager() { }
        MockManager(const MockManager& rhs);
        MockManager& operator=(const MockManager& rhs);

        Mock<R (C::*)(P1, P2, P3, P4), N>* d_obj;
    };

    template <typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, int N>
    class MockManager<R (C::*)(P1, P2, P3, P4, P5), N> {
    public:
        static MockManager& getInstance()
        {
            static MockManager* p = NULL;
            BSLMT_ONCE_DO
            {
                static MockManager self;
                p = &self;
            }
            return *p;
        }

        Mock<R (C::*)(P1, P2, P3, P4, P5), N>*& get()
        {
            return d_obj;
        }

        void clear()
        {
            d_obj = NULL;
        }

    private:
        MockManager() { }
        MockManager(const MockManager& rhs);
        MockManager& operator=(const MockManager& rhs);

        Mock<R (C::*)(P1, P2, P3, P4, P5), N>* d_obj;
    };

    template <typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, int N>
    class MockManager<R (C::*)(P1, P2, P3, P4, P5, P6), N> {
    public:
        static MockManager& getInstance()
        {
            static MockManager* p = NULL;
            BSLMT_ONCE_DO
            {
                static MockManager self;
                p = &self;
            }
            return *p;
        }

        Mock<R (C::*)(P1, P2, P3, P4, P5, P6), N>*& get()
        {
            return d_obj;
        }

        void clear()
        {
            d_obj = NULL;
        }

    private:
        MockManager() { }
        MockManager(const MockManager& rhs);
        MockManager& operator=(const MockManager& rhs);

        Mock<R (C::*)(P1, P2, P3, P4, P5, P6), N>* d_obj;
    };

    template <typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, int N>
    class MockManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7), N> {
    public:
        static MockManager& getInstance()
        {
            static MockManager* p = NULL;
            BSLMT_ONCE_DO
            {
                static MockManager self;
                p = &self;
            }
            return *p;
        }

        Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7), N>*& get()
        {
            return d_obj;
        }

        void clear()
        {
            d_obj = NULL;
        }

    private:
        MockManager() { }
        MockManager(const MockManager& rhs);
        MockManager& operator=(const MockManager& rhs);

        Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7), N>* d_obj;
    };

    template <typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
        typename P7, typename P8, int N>
    class MockManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8), N> {
    public:
        static MockManager& getInstance()
        {
            static MockManager* p = NULL;
            BSLMT_ONCE_DO
            {
                static MockManager self;
                p = &self;
            }
            return *p;
        }

        Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8), N>*& get()
        {
            return d_obj;
        }

        void clear()
        {
            d_obj = NULL;
        }

    private:
        MockManager() { }
        MockManager(const MockManager& rhs);
        MockManager& operator=(const MockManager& rhs);

        Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8), N>* d_obj;
    };

    template <typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
        typename P7, typename P8, typename P9, int N>
    class MockManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9), N> {
    public:
        static MockManager& getInstance()
        {
            static MockManager* p = NULL;
            BSLMT_ONCE_DO
            {
                static MockManager self;
                p = &self;
            }
            return *p;
        }

        Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9), N>*& get()
        {
            return d_obj;
        }

        void clear()
        {
            d_obj = NULL;
        }

    private:
        MockManager() { }
        MockManager(const MockManager& rhs);
        MockManager& operator=(const MockManager& rhs);

        Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9), N>* d_obj;
    };

    template <typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
        typename P7, typename P8, typename P9, typename P10, int N>
    class MockManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10), N> {
    public:
        static MockManager& getInstance()
        {
            static MockManager* p = NULL;
            BSLMT_ONCE_DO
            {
                static MockManager self;
                p = &self;
            }
            return *p;
        }

        Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10), N>*& get()
        {
            return d_obj;
        }

        void clear()
        {
            d_obj = NULL;
        }

    private:
        MockManager() { }
        MockManager(const MockManager& rhs);
        MockManager& operator=(const MockManager& rhs);

        Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10), N>* d_obj;
    };

    template <typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
        typename P7, typename P8, typename P9, typename P10, typename P11, int N>
    class MockManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11), N> {
    public:
        static MockManager& getInstance()
        {
            static MockManager* p = NULL;
            BSLMT_ONCE_DO
            {
                static MockManager self;
                p = &self;
            }
            return *p;
        }

        Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11), N>*& get()
        {
            return d_obj;
        }

        void clear()
        {
            d_obj = NULL;
        }

    private:
        MockManager() { }
        MockManager(const MockManager& rhs);
        MockManager& operator=(const MockManager& rhs);

        Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11), N>* d_obj;
    };

    template <typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
        typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, int N>
    class MockManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12), N> {
    public:
        static MockManager& getInstance()
        {
            static MockManager* p = NULL;
            BSLMT_ONCE_DO
            {
                static MockManager self;
                p = &self;
            }
            return *p;
        }

        Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12), N>*& get()
        {
            return d_obj;
        }

        void clear()
        {
            d_obj = NULL;
        }

    private:
        MockManager() { }
        MockManager(const MockManager& rhs);
        MockManager& operator=(const MockManager& rhs);

        Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12), N>* d_obj;
    };

    template <typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
        typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13, int N>
    class MockManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13), N> {
    public:
        static MockManager& getInstance()
        {
            static MockManager* p = NULL;
            BSLMT_ONCE_DO
            {
                static MockManager self;
                p = &self;
            }
            return *p;
        }

        Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13), N>*& get()
        {
            return d_obj;
        }

        void clear()
        {
            d_obj = NULL;
        }

    private:
        MockManager() { }
        MockManager(const MockManager& rhs);
        MockManager& operator=(const MockManager& rhs);

        Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13), N>* d_obj;
    };

    template <typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
        typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13, typename P14, int N>
    class MockManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14), N> {
    public:
        static MockManager& getInstance()
        {
            static MockManager* p = NULL;
            BSLMT_ONCE_DO
            {
                static MockManager self;
                p = &self;
            }
            return *p;
        }

        Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14), N>*& get()
        {
            return d_obj;
        }

        void clear()
        {
            d_obj = NULL;
        }

    private:
        MockManager() { }
        MockManager(const MockManager& rhs);
        MockManager& operator=(const MockManager& rhs);

        Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14), N>* d_obj;
    };

    template <typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
        typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13, typename P14, typename P15, int N>
    class MockManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15), N> {
    public:
        static MockManager& getInstance()
        {
            static MockManager* p = NULL;
            BSLMT_ONCE_DO
            {
                static MockManager self;
                p = &self;
            }
            return *p;
        }

        Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15), N>*& get()
        {
            return d_obj;
        }

        void clear()
        {
            d_obj = NULL;
        }

    private:
        MockManager() { }
        MockManager(const MockManager& rhs);
        MockManager& operator=(const MockManager& rhs);

        Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15), N>* d_obj;
    };

    template <typename R, typename C, int N>
    class MockManager<R (C::*)() const, N> {
    public:
        static MockManager& getInstance()
        {
            static MockManager* p = NULL;
            BSLMT_ONCE_DO
            {
                static MockManager self;
                p = &self;
            }
            return *p;
        }

        Mock<R (C::*)() const, N>*& get()
        {
            return d_obj;
        }

        void clear()
        {
            d_obj = NULL;
        }

    private:
        MockManager() { }
        MockManager(const MockManager& rhs);
        MockManager& operator=(const MockManager& rhs);

        Mock<R (C::*)() const, N>* d_obj;
    };

    template <typename R, typename C, typename P1, int N>
    class MockManager<R (C::*)(P1) const, N> {
    public:
        static MockManager& getInstance()
        {
            static MockManager* p = NULL;
            BSLMT_ONCE_DO
            {
                static MockManager self;
                p = &self;
            }
            return *p;
        }

        Mock<R (C::*)(P1) const, N>*& get()
        {
            return d_obj;
        }

        void clear()
        {
            d_obj = NULL;
        }

    private:
        MockManager() { }
        MockManager(const MockManager& rhs);
        MockManager& operator=(const MockManager& rhs);

        Mock<R (C::*)(P1) const, N>* d_obj;
    };

    template <typename R, typename C, typename P1, typename P2, int N>
    class MockManager<R (C::*)(P1, P2) const, N> {
    public:
        static MockManager& getInstance()
        {
            static MockManager* p = NULL;
            BSLMT_ONCE_DO
            {
                static MockManager self;
                p = &self;
            }
            return *p;
        }

        Mock<R (C::*)(P1, P2) const, N>*& get()
        {
            return d_obj;
        }

        void clear()
        {
            d_obj = NULL;
        }

    private:
        MockManager() { }
        MockManager(const MockManager& rhs);
        MockManager& operator=(const MockManager& rhs);

        Mock<R (C::*)(P1, P2) const, N>* d_obj;
    };

    template <typename R, typename C, typename P1, typename P2, typename P3, int N>
    class MockManager<R (C::*)(P1, P2, P3) const, N> {
    public:
        static MockManager& getInstance()
        {
            static MockManager* p = NULL;
            BSLMT_ONCE_DO
            {
                static MockManager self;
                p = &self;
            }
            return *p;
        }

        Mock<R (C::*)(P1, P2, P3) const, N>*& get()
        {
            return d_obj;
        }

        void clear()
        {
            d_obj = NULL;
        }

    private:
        MockManager() { }
        MockManager(const MockManager& rhs);
        MockManager& operator=(const MockManager& rhs);

        Mock<R (C::*)(P1, P2, P3) const, N>* d_obj;
    };

    template <typename R, typename C, typename P1, typename P2, typename P3, typename P4, int N>
    class MockManager<R (C::*)(P1, P2, P3, P4) const, N> {
    public:
        static MockManager& getInstance()
        {
            static MockManager* p = NULL;
            BSLMT_ONCE_DO
            {
                static MockManager self;
                p = &self;
            }
            return *p;
        }

        Mock<R (C::*)(P1, P2, P3, P4) const, N>*& get()
        {
            return d_obj;
        }

        void clear()
        {
            d_obj = NULL;
        }

    private:
        MockManager() { }
        MockManager(const MockManager& rhs);
        MockManager& operator=(const MockManager& rhs);

        Mock<R (C::*)(P1, P2, P3, P4) const, N>* d_obj;
    };

    template <typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, int N>
    class MockManager<R (C::*)(P1, P2, P3, P4, P5) const, N> {
    public:
        static MockManager& getInstance()
        {
            static MockManager* p = NULL;
            BSLMT_ONCE_DO
            {
                static MockManager self;
                p = &self;
            }
            return *p;
        }

        Mock<R (C::*)(P1, P2, P3, P4, P5) const, N>*& get()
        {
            return d_obj;
        }

        void clear()
        {
            d_obj = NULL;
        }

    private:
        MockManager() { }
        MockManager(const MockManager& rhs);
        MockManager& operator=(const MockManager& rhs);

        Mock<R (C::*)(P1, P2, P3, P4, P5) const, N>* d_obj;
    };

    template <typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, int N>
    class MockManager<R (C::*)(P1, P2, P3, P4, P5, P6) const, N> {
    public:
        static MockManager& getInstance()
        {
            static MockManager* p = NULL;
            BSLMT_ONCE_DO
            {
                static MockManager self;
                p = &self;
            }
            return *p;
        }

        Mock<R (C::*)(P1, P2, P3, P4, P5, P6) const, N>*& get()
        {
            return d_obj;
        }

        void clear()
        {
            d_obj = NULL;
        }

    private:
        MockManager() { }
        MockManager(const MockManager& rhs);
        MockManager& operator=(const MockManager& rhs);

        Mock<R (C::*)(P1, P2, P3, P4, P5, P6) const, N>* d_obj;
    };

    template <typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
        typename P7, int N>
    class MockManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7) const, N> {
    public:
        static MockManager& getInstance()
        {
            static MockManager* p = NULL;
            BSLMT_ONCE_DO
            {
                static MockManager self;
                p = &self;
            }
            return *p;
        }

        Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7) const, N>*& get()
        {
            return d_obj;
        }

        void clear()
        {
            d_obj = NULL;
        }

    private:
        MockManager() { }
        MockManager(const MockManager& rhs);
        MockManager& operator=(const MockManager& rhs);

        Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7) const, N>* d_obj;
    };

    template <typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
        typename P7, typename P8, int N>
    class MockManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8) const, N> {
    public:
        static MockManager& getInstance()
        {
            static MockManager* p = NULL;
            BSLMT_ONCE_DO
            {
                static MockManager self;
                p = &self;
            }
            return *p;
        }

        Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8) const, N>*& get()
        {
            return d_obj;
        }

        void clear()
        {
            d_obj = NULL;
        }

    private:
        MockManager() { }
        MockManager(const MockManager& rhs);
        MockManager& operator=(const MockManager& rhs);

        Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8) const, N>* d_obj;
    };

    template <typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
        typename P7, typename P8, typename P9, int N>
    class MockManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9) const, N> {
    public:
        static MockManager& getInstance()
        {
            static MockManager* p = NULL;
            BSLMT_ONCE_DO
            {
                static MockManager self;
                p = &self;
            }
            return *p;
        }

        Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9) const, N>*& get()
        {
            return d_obj;
        }

        void clear()
        {
            d_obj = NULL;
        }

    private:
        MockManager() { }
        MockManager(const MockManager& rhs);
        MockManager& operator=(const MockManager& rhs);

        Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9) const, N>* d_obj;
    };

    template <typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
        typename P7, typename P8, typename P9, typename P10, int N>
    class MockManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10) const, N> {
    public:
        static MockManager& getInstance()
        {
            static MockManager* p = NULL;
            BSLMT_ONCE_DO
            {
                static MockManager self;
                p = &self;
            }
            return *p;
        }

        Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10) const, N>*& get()
        {
            return d_obj;
        }

        void clear()
        {
            d_obj = NULL;
        }

    private:
        MockManager() { }
        MockManager(const MockManager& rhs);
        MockManager& operator=(const MockManager& rhs);

        Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10) const, N>* d_obj;
    };

    template <typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
        typename P7, typename P8, typename P9, typename P10, typename P11, int N>
    class MockManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11) const, N> {
    public:
        static MockManager& getInstance()
        {
            static MockManager* p = NULL;
            BSLMT_ONCE_DO
            {
                static MockManager self;
                p = &self;
            }
            return *p;
        }

        Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11) const, N>*& get()
        {
            return d_obj;
        }

        void clear()
        {
            d_obj = NULL;
        }

    private:
        MockManager() { }
        MockManager(const MockManager& rhs);
        MockManager& operator=(const MockManager& rhs);

        Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11) const, N>* d_obj;
    };

    template <typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
        typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, int N>
    class MockManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12) const, N> {
    public:
        static MockManager& getInstance()
        {
            static MockManager* p = NULL;
            BSLMT_ONCE_DO
            {
                static MockManager self;
                p = &self;
            }
            return *p;
        }

        Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12) const, N>*& get()
        {
            return d_obj;
        }

        void clear()
        {
            d_obj = NULL;
        }

    private:
        MockManager() { }
        MockManager(const MockManager& rhs);
        MockManager& operator=(const MockManager& rhs);

        Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12) const, N>* d_obj;
    };

    template <typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
        typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13, int N>
    class MockManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13) const, N> {
    public:
        static MockManager& getInstance()
        {
            static MockManager* p = NULL;
            BSLMT_ONCE_DO
            {
                static MockManager self;
                p = &self;
            }
            return *p;
        }

        Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13) const, N>*& get()
        {
            return d_obj;
        }

        void clear()
        {
            d_obj = NULL;
        }

    private:
        MockManager() { }
        MockManager(const MockManager& rhs);
        MockManager& operator=(const MockManager& rhs);

        Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13) const, N>* d_obj;
    };

    template <typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
        typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13, typename P14, int N>
    class MockManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14) const, N> {
    public:
        static MockManager& getInstance()
        {
            static MockManager* p = NULL;
            BSLMT_ONCE_DO
            {
                static MockManager self;
                p = &self;
            }
            return *p;
        }

        Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14) const, N>*& get()
        {
            return d_obj;
        }

        void clear()
        {
            d_obj = NULL;
        }

    private:
        MockManager() { }
        MockManager(const MockManager& rhs);
        MockManager& operator=(const MockManager& rhs);

        Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14) const, N>* d_obj;
    };

    template <typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
        typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13, typename P14, typename P15, int N>
    class MockManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15) const, N> {
    public:
        static MockManager& getInstance()
        {
            static MockManager* p = NULL;
            BSLMT_ONCE_DO
            {
                static MockManager self;
                p = &self;
            }
            return *p;
        }

        Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15) const, N>*& get()
        {
            return d_obj;
        }

        void clear()
        {
            d_obj = NULL;
        }

    private:
        MockManager() { }
        MockManager(const MockManager& rhs);
        MockManager& operator=(const MockManager& rhs);

        Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15) const, N>* d_obj;
    };

    template <typename R, typename C, int N>
    class MockVirtualManager<R (C::*)(), N> {
    public:
        static MockVirtualManager& getInstance()
        {
            static MockVirtualManager* p = NULL;
            BSLMT_ONCE_DO
            {
                static MockVirtualManager self;
                p = &self;
            }
            return *p;
        }

        MockVirtual<R (C::*)(), N>*& get()
        {
            return d_obj;
        }

        void clear()
        {
            d_obj = NULL;
        }

    private:
        MockVirtualManager() { }
        MockVirtualManager(const MockVirtualManager& rhs);
        MockVirtualManager& operator=(const MockVirtualManager& rhs);

        MockVirtual<R (C::*)(), N>* d_obj;
    };

    template <typename R, typename C, typename P1, int N>
    class MockVirtualManager<R (C::*)(P1), N> {
    public:
        static MockVirtualManager& getInstance()
        {
            static MockVirtualManager* p = NULL;
            BSLMT_ONCE_DO
            {
                static MockVirtualManager self;
                p = &self;
            }
            return *p;
        }

        MockVirtual<R (C::*)(P1), N>*& get()
        {
            return d_obj;
        }

        void clear()
        {
            d_obj = NULL;
        }

    private:
        MockVirtualManager() { }
        MockVirtualManager(const MockVirtualManager& rhs);
        MockVirtualManager& operator=(const MockVirtualManager& rhs);

        MockVirtual<R (C::*)(P1), N>* d_obj;
    };

    template <typename R, typename C, typename P1, typename P2, int N>
    class MockVirtualManager<R (C::*)(P1, P2), N> {
    public:
        static MockVirtualManager& getInstance()
        {
            static MockVirtualManager* p = NULL;
            BSLMT_ONCE_DO
            {
                static MockVirtualManager self;
                p = &self;
            }
            return *p;
        }

        MockVirtual<R (C::*)(P1, P2), N>*& get()
        {
            return d_obj;
        }

        void clear()
        {
            d_obj = NULL;
        }

    private:
        MockVirtualManager() { }
        MockVirtualManager(const MockVirtualManager& rhs);
        MockVirtualManager& operator=(const MockVirtualManager& rhs);

        MockVirtual<R (C::*)(P1, P2), N>* d_obj;
    };

    template <typename R, typename C, typename P1, typename P2, typename P3, int N>
    class MockVirtualManager<R (C::*)(P1, P2, P3), N> {
    public:
        static MockVirtualManager& getInstance()
        {
            static MockVirtualManager* p = NULL;
            BSLMT_ONCE_DO
            {
                static MockVirtualManager self;
                p = &self;
            }
            return *p;
        }

        MockVirtual<R (C::*)(P1, P2, P3), N>*& get()
        {
            return d_obj;
        }

        void clear()
        {
            d_obj = NULL;
        }

    private:
        MockVirtualManager() { }
        MockVirtualManager(const MockVirtualManager& rhs);
        MockVirtualManager& operator=(const MockVirtualManager& rhs);

        MockVirtual<R (C::*)(P1, P2, P3), N>* d_obj;
    };

    template <typename R, typename C, typename P1, typename P2, typename P3, typename P4, int N>
    class MockVirtualManager<R (C::*)(P1, P2, P3, P4), N> {
    public:
        static MockVirtualManager& getInstance()
        {
            static MockVirtualManager* p = NULL;
            BSLMT_ONCE_DO
            {
                static MockVirtualManager self;
                p = &self;
            }
            return *p;
        }

        MockVirtual<R (C::*)(P1, P2, P3, P4), N>*& get()
        {
            return d_obj;
        }

        void clear()
        {
            d_obj = NULL;
        }

    private:
        MockVirtualManager() { }
        MockVirtualManager(const MockVirtualManager& rhs);
        MockVirtualManager& operator=(const MockVirtualManager& rhs);

        MockVirtual<R (C::*)(P1, P2, P3, P4), N>* d_obj;
    };

    template <typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, int N>
    class MockVirtualManager<R (C::*)(P1, P2, P3, P4, P5), N> {
    public:
        static MockVirtualManager& getInstance()
        {
            static MockVirtualManager* p = NULL;
            BSLMT_ONCE_DO
            {
                static MockVirtualManager self;
                p = &self;
            }
            return *p;
        }

        MockVirtual<R (C::*)(P1, P2, P3, P4, P5), N>*& get()
        {
            return d_obj;
        }

        void clear()
        {
            d_obj = NULL;
        }

    private:
        MockVirtualManager() { }
        MockVirtualManager(const MockVirtualManager& rhs);
        MockVirtualManager& operator=(const MockVirtualManager& rhs);

        MockVirtual<R (C::*)(P1, P2, P3, P4, P5), N>* d_obj;
    };

    template <typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, int N>
    class MockVirtualManager<R (C::*)(P1, P2, P3, P4, P5, P6), N> {
    public:
        static MockVirtualManager& getInstance()
        {
            static MockVirtualManager* p = NULL;
            BSLMT_ONCE_DO
            {
                static MockVirtualManager self;
                p = &self;
            }
            return *p;
        }

        MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6), N>*& get()
        {
            return d_obj;
        }

        void clear()
        {
            d_obj = NULL;
        }

    private:
        MockVirtualManager() { }
        MockVirtualManager(const MockVirtualManager& rhs);
        MockVirtualManager& operator=(const MockVirtualManager& rhs);

        MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6), N>* d_obj;
    };

    template <typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
        typename P7, int N>
    class MockVirtualManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7), N> {
    public:
        static MockVirtualManager& getInstance()
        {
            static MockVirtualManager* p = NULL;
            BSLMT_ONCE_DO
            {
                static MockVirtualManager self;
                p = &self;
            }
            return *p;
        }

        MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7), N>*& get()
        {
            return d_obj;
        }

        void clear()
        {
            d_obj = NULL;
        }

    private:
        MockVirtualManager() { }
        MockVirtualManager(const MockVirtualManager& rhs);
        MockVirtualManager& operator=(const MockVirtualManager& rhs);

        MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7), N>* d_obj;
    };

    template <typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
        typename P7, typename P8, int N>
    class MockVirtualManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8), N> {
    public:
        static MockVirtualManager& getInstance()
        {
            static MockVirtualManager* p = NULL;
            BSLMT_ONCE_DO
            {
                static MockVirtualManager self;
                p = &self;
            }
            return *p;
        }

        MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8), N>*& get()
        {
            return d_obj;
        }

        void clear()
        {
            d_obj = NULL;
        }

    private:
        MockVirtualManager() { }
        MockVirtualManager(const MockVirtualManager& rhs);
        MockVirtualManager& operator=(const MockVirtualManager& rhs);

        MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8), N>* d_obj;
    };

    template <typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
        typename P7, typename P8, typename P9, int N>
    class MockVirtualManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9), N> {
    public:
        static MockVirtualManager& getInstance()
        {
            static MockVirtualManager* p = NULL;
            BSLMT_ONCE_DO
            {
                static MockVirtualManager self;
                p = &self;
            }
            return *p;
        }

        MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9), N>*& get()
        {
            return d_obj;
        }

        void clear()
        {
            d_obj = NULL;
        }

    private:
        MockVirtualManager() { }
        MockVirtualManager(const MockVirtualManager& rhs);
        MockVirtualManager& operator=(const MockVirtualManager& rhs);

        MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9), N>* d_obj;
    };

    template <typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
        typename P7, typename P8, typename P9, typename P10, int N>
    class MockVirtualManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10), N> {
    public:
        static MockVirtualManager& getInstance()
        {
            static MockVirtualManager* p = NULL;
            BSLMT_ONCE_DO
            {
                static MockVirtualManager self;
                p = &self;
            }
            return *p;
        }

        MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10), N>*& get()
        {
            return d_obj;
        }

        void clear()
        {
            d_obj = NULL;
        }

    private:
        MockVirtualManager() { }
        MockVirtualManager(const MockVirtualManager& rhs);
        MockVirtualManager& operator=(const MockVirtualManager& rhs);

        MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10), N>* d_obj;
    };

    template <typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
        typename P7, typename P8, typename P9, typename P10, typename P11, int N>
    class MockVirtualManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11), N> {
    public:
        static MockVirtualManager& getInstance()
        {
            static MockVirtualManager* p = NULL;
            BSLMT_ONCE_DO
            {
                static MockVirtualManager self;
                p = &self;
            }
            return *p;
        }

        MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11), N>*& get()
        {
            return d_obj;
        }

        void clear()
        {
            d_obj = NULL;
        }

    private:
        MockVirtualManager() { }
        MockVirtualManager(const MockVirtualManager& rhs);
        MockVirtualManager& operator=(const MockVirtualManager& rhs);

        MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11), N>* d_obj;
    };

    template <typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
        typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, int N>
    class MockVirtualManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12), N> {
    public:
        static MockVirtualManager& getInstance()
        {
            static MockVirtualManager* p = NULL;
            BSLMT_ONCE_DO
            {
                static MockVirtualManager self;
                p = &self;
            }
            return *p;
        }

        MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12), N>*& get()
        {
            return d_obj;
        }

        void clear()
        {
            d_obj = NULL;
        }

    private:
        MockVirtualManager() { }
        MockVirtualManager(const MockVirtualManager& rhs);
        MockVirtualManager& operator=(const MockVirtualManager& rhs);

        MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12), N>* d_obj;
    };

    template <typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
        typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13, int N>
    class MockVirtualManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13), N> {
    public:
        static MockVirtualManager& getInstance()
        {
            static MockVirtualManager* p = NULL;
            BSLMT_ONCE_DO
            {
                static MockVirtualManager self;
                p = &self;
            }
            return *p;
        }

        MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13), N>*& get()
        {
            return d_obj;
        }

        void clear()
        {
            d_obj = NULL;
        }

    private:
        MockVirtualManager() { }
        MockVirtualManager(const MockVirtualManager& rhs);
        MockVirtualManager& operator=(const MockVirtualManager& rhs);

        MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13), N>* d_obj;
    };

    template <typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
        typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13, typename P14, int N>
    class MockVirtualManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14), N> {
    public:
        static MockVirtualManager& getInstance()
        {
            static MockVirtualManager* p = NULL;
            BSLMT_ONCE_DO
            {
                static MockVirtualManager self;
                p = &self;
            }
            return *p;
        }

        MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14), N>*& get()
        {
            return d_obj;
        }

        void clear()
        {
            d_obj = NULL;
        }

    private:
        MockVirtualManager() { }
        MockVirtualManager(const MockVirtualManager& rhs);
        MockVirtualManager& operator=(const MockVirtualManager& rhs);

        MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14), N>* d_obj;
    };

    template <typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
        typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13, typename P14, typename P15, int N>
    class MockVirtualManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15), N> {
    public:
        static MockVirtualManager& getInstance()
        {
            static MockVirtualManager* p = NULL;
            BSLMT_ONCE_DO
            {
                static MockVirtualManager self;
                p = &self;
            }
            return *p;
        }

        MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15), N>*& get()
        {
            return d_obj;
        }

        void clear()
        {
            d_obj = NULL;
        }

    private:
        MockVirtualManager() { }
        MockVirtualManager(const MockVirtualManager& rhs);
        MockVirtualManager& operator=(const MockVirtualManager& rhs);

        MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15), N>* d_obj;
    };

    template <typename R, typename C, int N>
    class MockVirtualManager<R (C::*)() const, N> {
    public:
        static MockVirtualManager& getInstance()
        {
            static MockVirtualManager* p = NULL;
            BSLMT_ONCE_DO
            {
                static MockVirtualManager self;
                p = &self;
            }
            return *p;
        }

        MockVirtual<R (C::*)() const, N>*& get()
        {
            return d_obj;
        }

        void clear()
        {
            d_obj = NULL;
        }

    private:
        MockVirtualManager() { }
        MockVirtualManager(const MockVirtualManager& rhs);
        MockVirtualManager& operator=(const MockVirtualManager& rhs);

        MockVirtual<R (C::*)() const, N>* d_obj;
    };

    template <typename R, typename C, typename P1, int N>
    class MockVirtualManager<R (C::*)(P1) const, N> {
    public:
        static MockVirtualManager& getInstance()
        {
            static MockVirtualManager* p = NULL;
            BSLMT_ONCE_DO
            {
                static MockVirtualManager self;
                p = &self;
            }
            return *p;
        }

        MockVirtual<R (C::*)(P1) const, N>*& get()
        {
            return d_obj;
        }

        void clear()
        {
            d_obj = NULL;
        }

    private:
        MockVirtualManager() { }
        MockVirtualManager(const MockVirtualManager& rhs);
        MockVirtualManager& operator=(const MockVirtualManager& rhs);

        MockVirtual<R (C::*)(P1) const, N>* d_obj;
    };

    template <typename R, typename C, typename P1, typename P2, int N>
    class MockVirtualManager<R (C::*)(P1, P2) const, N> {
    public:
        static MockVirtualManager& getInstance()
        {
            static MockVirtualManager* p = NULL;
            BSLMT_ONCE_DO
            {
                static MockVirtualManager self;
                p = &self;
            }
            return *p;
        }

        MockVirtual<R (C::*)(P1, P2) const, N>*& get()
        {
            return d_obj;
        }

        void clear()
        {
            d_obj = NULL;
        }

    private:
        MockVirtualManager() { }
        MockVirtualManager(const MockVirtualManager& rhs);
        MockVirtualManager& operator=(const MockVirtualManager& rhs);

        MockVirtual<R (C::*)(P1, P2) const, N>* d_obj;
    };

    template <typename R, typename C, typename P1, typename P2, typename P3, int N>
    class MockVirtualManager<R (C::*)(P1, P2, P3) const, N> {
    public:
        static MockVirtualManager& getInstance()
        {
            static MockVirtualManager* p = NULL;
            BSLMT_ONCE_DO
            {
                static MockVirtualManager self;
                p = &self;
            }
            return *p;
        }

        MockVirtual<R (C::*)(P1, P2, P3) const, N>*& get()
        {
            return d_obj;
        }

        void clear()
        {
            d_obj = NULL;
        }

    private:
        MockVirtualManager() { }
        MockVirtualManager(const MockVirtualManager& rhs);
        MockVirtualManager& operator=(const MockVirtualManager& rhs);

        MockVirtual<R (C::*)(P1, P2, P3) const, N>* d_obj;
    };

    template <typename R, typename C, typename P1, typename P2, typename P3, typename P4, int N>
    class MockVirtualManager<R (C::*)(P1, P2, P3, P4) const, N> {
    public:
        static MockVirtualManager& getInstance()
        {
            static MockVirtualManager* p = NULL;
            BSLMT_ONCE_DO
            {
                static MockVirtualManager self;
                p = &self;
            }
            return *p;
        }

        MockVirtual<R (C::*)(P1, P2, P3, P4) const, N>*& get()
        {
            return d_obj;
        }

        void clear()
        {
            d_obj = NULL;
        }

    private:
        MockVirtualManager() { }
        MockVirtualManager(const MockVirtualManager& rhs);
        MockVirtualManager& operator=(const MockVirtualManager& rhs);

        MockVirtual<R (C::*)(P1, P2, P3, P4) const, N>* d_obj;
    };

    template <typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, int N>
    class MockVirtualManager<R (C::*)(P1, P2, P3, P4, P5) const, N> {
    public:
        static MockVirtualManager& getInstance()
        {
            static MockVirtualManager* p = NULL;
            BSLMT_ONCE_DO
            {
                static MockVirtualManager self;
                p = &self;
            }
            return *p;
        }

        MockVirtual<R (C::*)(P1, P2, P3, P4, P5) const, N>*& get()
        {
            return d_obj;
        }

        void clear()
        {
            d_obj = NULL;
        }

    private:
        MockVirtualManager() { }
        MockVirtualManager(const MockVirtualManager& rhs);
        MockVirtualManager& operator=(const MockVirtualManager& rhs);

        MockVirtual<R (C::*)(P1, P2, P3, P4, P5) const, N>* d_obj;
    };

    template <typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, int N>
    class MockVirtualManager<R (C::*)(P1, P2, P3, P4, P5, P6) const, N> {
    public:
        static MockVirtualManager& getInstance()
        {
            static MockVirtualManager* p = NULL;
            BSLMT_ONCE_DO
            {
                static MockVirtualManager self;
                p = &self;
            }
            return *p;
        }

        MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6) const, N>*& get()
        {
            return d_obj;
        }

        void clear()
        {
            d_obj = NULL;
        }

    private:
        MockVirtualManager() { }
        MockVirtualManager(const MockVirtualManager& rhs);
        MockVirtualManager& operator=(const MockVirtualManager& rhs);

        MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6) const, N>* d_obj;
    };

    template <typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
        typename P7, int N>
    class MockVirtualManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7) const, N> {
    public:
        static MockVirtualManager& getInstance()
        {
            static MockVirtualManager* p = NULL;
            BSLMT_ONCE_DO
            {
                static MockVirtualManager self;
                p = &self;
            }
            return *p;
        }

        MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7) const, N>*& get()
        {
            return d_obj;
        }

        void clear()
        {
            d_obj = NULL;
        }

    private:
        MockVirtualManager() { }
        MockVirtualManager(const MockVirtualManager& rhs);
        MockVirtualManager& operator=(const MockVirtualManager& rhs);

        MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7) const, N>* d_obj;
    };

    template <typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
        typename P7, typename P8, int N>
    class MockVirtualManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8) const, N> {
    public:
        static MockVirtualManager& getInstance()
        {
            static MockVirtualManager* p = NULL;
            BSLMT_ONCE_DO
            {
                static MockVirtualManager self;
                p = &self;
            }
            return *p;
        }

        MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8) const, N>*& get()
        {
            return d_obj;
        }

        void clear()
        {
            d_obj = NULL;
        }

    private:
        MockVirtualManager() { }
        MockVirtualManager(const MockVirtualManager& rhs);
        MockVirtualManager& operator=(const MockVirtualManager& rhs);

        MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8) const, N>* d_obj;
    };

    template <typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
        typename P7, typename P8, typename P9, int N>
    class MockVirtualManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9) const, N> {
    public:
        static MockVirtualManager& getInstance()
        {
            static MockVirtualManager* p = NULL;
            BSLMT_ONCE_DO
            {
                static MockVirtualManager self;
                p = &self;
            }
            return *p;
        }

        MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9) const, N>*& get()
        {
            return d_obj;
        }

        void clear()
        {
            d_obj = NULL;
        }

    private:
        MockVirtualManager() { }
        MockVirtualManager(const MockVirtualManager& rhs);
        MockVirtualManager& operator=(const MockVirtualManager& rhs);

        MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9) const, N>* d_obj;
    };

    template <typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
        typename P7, typename P8, typename P9, typename P10, int N>
    class MockVirtualManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10) const, N> {
    public:
        static MockVirtualManager& getInstance()
        {
            static MockVirtualManager* p = NULL;
            BSLMT_ONCE_DO
            {
                static MockVirtualManager self;
                p = &self;
            }
            return *p;
        }

        MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10) const, N>*& get()
        {
            return d_obj;
        }

        void clear()
        {
            d_obj = NULL;
        }

    private:
        MockVirtualManager() { }
        MockVirtualManager(const MockVirtualManager& rhs);
        MockVirtualManager& operator=(const MockVirtualManager& rhs);

        MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10) const, N>* d_obj;
    };

    template <typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
        typename P7, typename P8, typename P9, typename P10, typename P11, int N>
    class MockVirtualManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11) const, N> {
    public:
        static MockVirtualManager& getInstance()
        {
            static MockVirtualManager* p = NULL;
            BSLMT_ONCE_DO
            {
                static MockVirtualManager self;
                p = &self;
            }
            return *p;
        }

        MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11) const, N>*& get()
        {
            return d_obj;
        }

        void clear()
        {
            d_obj = NULL;
        }

    private:
        MockVirtualManager() { }
        MockVirtualManager(const MockVirtualManager& rhs);
        MockVirtualManager& operator=(const MockVirtualManager& rhs);

        MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11) const, N>* d_obj;
    };

    template <typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
        typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, int N>
    class MockVirtualManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12) const, N> {
    public:
        static MockVirtualManager& getInstance()
        {
            static MockVirtualManager* p = NULL;
            BSLMT_ONCE_DO
            {
                static MockVirtualManager self;
                p = &self;
            }
            return *p;
        }

        MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12) const, N>*& get()
        {
            return d_obj;
        }

        void clear()
        {
            d_obj = NULL;
        }

    private:
        MockVirtualManager() { }
        MockVirtualManager(const MockVirtualManager& rhs);
        MockVirtualManager& operator=(const MockVirtualManager& rhs);

        MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12) const, N>* d_obj;
    };

    template <typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
        typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13, int N>
    class MockVirtualManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13) const, N> {
    public:
        static MockVirtualManager& getInstance()
        {
            static MockVirtualManager* p = NULL;
            BSLMT_ONCE_DO
            {
                static MockVirtualManager self;
                p = &self;
            }
            return *p;
        }

        MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13) const, N>*& get()
        {
            return d_obj;
        }

        void clear()
        {
            d_obj = NULL;
        }

    private:
        MockVirtualManager() { }
        MockVirtualManager(const MockVirtualManager& rhs);
        MockVirtualManager& operator=(const MockVirtualManager& rhs);

        MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13) const, N>* d_obj;
    };

    template <typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
        typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13, typename P14, int N>
    class MockVirtualManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14) const, N> {
    public:
        static MockVirtualManager& getInstance()
        {
            static MockVirtualManager* p = NULL;
            BSLMT_ONCE_DO
            {
                static MockVirtualManager self;
                p = &self;
            }
            return *p;
        }

        MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14) const, N>*& get()
        {
            return d_obj;
        }

        void clear()
        {
            d_obj = NULL;
        }

    private:
        MockVirtualManager() { }
        MockVirtualManager(const MockVirtualManager& rhs);
        MockVirtualManager& operator=(const MockVirtualManager& rhs);

        MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14) const, N>* d_obj;
    };

    template <typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
        typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13, typename P14, typename P15, int N>
    class MockVirtualManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15) const, N> {
    public:
        static MockVirtualManager& getInstance()
        {
            static MockVirtualManager* p = NULL;
            BSLMT_ONCE_DO
            {
                static MockVirtualManager self;
                p = &self;
            }
            return *p;
        }

        MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15) const, N>*& get()
        {
            return d_obj;
        }

        void clear()
        {
            d_obj = NULL;
        }

    private:
        MockVirtualManager() { }
        MockVirtualManager(const MockVirtualManager& rhs);
        MockVirtualManager& operator=(const MockVirtualManager& rhs);

        MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15) const, N>* d_obj;
    };

    template <typename R, typename C, int N>
    class MockPrivateManager<R (C::*)(), N> {
    public:
        static MockPrivateManager& getInstance()
        {
            static MockPrivateManager* p = NULL;
            BSLMT_ONCE_DO
            {
                static MockPrivateManager self;
                p = &self;
            }
            return *p;
        }

        MockPrivate<R (C::*)(), N>*& get()
        {
            return d_obj;
        }

        void clear()
        {
            d_obj = NULL;
        }

    private:
        MockPrivateManager() { }
        MockPrivateManager(const MockPrivateManager& rhs);
        MockPrivateManager& operator=(const MockPrivateManager& rhs);

        MockPrivate<R (C::*)(), N>* d_obj;
    };

    template <typename R, typename C, typename P1, int N>
    class MockPrivateManager<R (C::*)(P1), N> {
    public:
        static MockPrivateManager& getInstance()
        {
            static MockPrivateManager* p = NULL;
            BSLMT_ONCE_DO
            {
                static MockPrivateManager self;
                p = &self;
            }
            return *p;
        }

        MockPrivate<R (C::*)(P1), N>*& get()
        {
            return d_obj;
        }

        void clear()
        {
            d_obj = NULL;
        }

    private:
        MockPrivateManager() { }
        MockPrivateManager(const MockPrivateManager& rhs);
        MockPrivateManager& operator=(const MockPrivateManager& rhs);

        MockPrivate<R (C::*)(P1), N>* d_obj;
    };

    template <typename R, typename C, typename P1, typename P2, int N>
    class MockPrivateManager<R (C::*)(P1, P2), N> {
    public:
        static MockPrivateManager& getInstance()
        {
            static MockPrivateManager* p = NULL;
            BSLMT_ONCE_DO
            {
                static MockPrivateManager self;
                p = &self;
            }
            return *p;
        }

        MockPrivate<R (C::*)(P1, P2), N>*& get()
        {
            return d_obj;
        }

        void clear()
        {
            d_obj = NULL;
        }

    private:
        MockPrivateManager() { }
        MockPrivateManager(const MockPrivateManager& rhs);
        MockPrivateManager& operator=(const MockPrivateManager& rhs);

        MockPrivate<R (C::*)(P1, P2), N>* d_obj;
    };

    template <typename R, typename C, typename P1, typename P2, typename P3, int N>
    class MockPrivateManager<R (C::*)(P1, P2, P3), N> {
    public:
        static MockPrivateManager& getInstance()
        {
            static MockPrivateManager* p = NULL;
            BSLMT_ONCE_DO
            {
                static MockPrivateManager self;
                p = &self;
            }
            return *p;
        }

        MockPrivate<R (C::*)(P1, P2, P3), N>*& get()
        {
            return d_obj;
        }

        void clear()
        {
            d_obj = NULL;
        }

    private:
        MockPrivateManager() { }
        MockPrivateManager(const MockPrivateManager& rhs);
        MockPrivateManager& operator=(const MockPrivateManager& rhs);

        MockPrivate<R (C::*)(P1, P2, P3), N>* d_obj;
    };

    template <typename R, typename C, typename P1, typename P2, typename P3, typename P4, int N>
    class MockPrivateManager<R (C::*)(P1, P2, P3, P4), N> {
    public:
        static MockPrivateManager& getInstance()
        {
            static MockPrivateManager* p = NULL;
            BSLMT_ONCE_DO
            {
                static MockPrivateManager self;
                p = &self;
            }
            return *p;
        }

        MockPrivate<R (C::*)(P1, P2, P3, P4), N>*& get()
        {
            return d_obj;
        }

        void clear()
        {
            d_obj = NULL;
        }

    private:
        MockPrivateManager() { }
        MockPrivateManager(const MockPrivateManager& rhs);
        MockPrivateManager& operator=(const MockPrivateManager& rhs);

        MockPrivate<R (C::*)(P1, P2, P3, P4), N>* d_obj;
    };

    template <typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, int N>
    class MockPrivateManager<R (C::*)(P1, P2, P3, P4, P5), N> {
    public:
        static MockPrivateManager& getInstance()
        {
            static MockPrivateManager* p = NULL;
            BSLMT_ONCE_DO
            {
                static MockPrivateManager self;
                p = &self;
            }
            return *p;
        }

        MockPrivate<R (C::*)(P1, P2, P3, P4, P5), N>*& get()
        {
            return d_obj;
        }

        void clear()
        {
            d_obj = NULL;
        }

    private:
        MockPrivateManager() { }
        MockPrivateManager(const MockPrivateManager& rhs);
        MockPrivateManager& operator=(const MockPrivateManager& rhs);

        MockPrivate<R (C::*)(P1, P2, P3, P4, P5), N>* d_obj;
    };

    template <typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, int N>
    class MockPrivateManager<R (C::*)(P1, P2, P3, P4, P5, P6), N> {
    public:
        static MockPrivateManager& getInstance()
        {
            static MockPrivateManager* p = NULL;
            BSLMT_ONCE_DO
            {
                static MockPrivateManager self;
                p = &self;
            }
            return *p;
        }

        MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6), N>*& get()
        {
            return d_obj;
        }

        void clear()
        {
            d_obj = NULL;
        }

    private:
        MockPrivateManager() { }
        MockPrivateManager(const MockPrivateManager& rhs);
        MockPrivateManager& operator=(const MockPrivateManager& rhs);

        MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6), N>* d_obj;
    };

    template <typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
        typename P7, int N>
    class MockPrivateManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7), N> {
    public:
        static MockPrivateManager& getInstance()
        {
            static MockPrivateManager* p = NULL;
            BSLMT_ONCE_DO
            {
                static MockPrivateManager self;
                p = &self;
            }
            return *p;
        }

        MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7), N>*& get()
        {
            return d_obj;
        }

        void clear()
        {
            d_obj = NULL;
        }

    private:
        MockPrivateManager() { }
        MockPrivateManager(const MockPrivateManager& rhs);
        MockPrivateManager& operator=(const MockPrivateManager& rhs);

        MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7), N>* d_obj;
    };

    template <typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
        typename P7, typename P8, int N>
    class MockPrivateManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8), N> {
    public:
        static MockPrivateManager& getInstance()
        {
            static MockPrivateManager* p = NULL;
            BSLMT_ONCE_DO
            {
                static MockPrivateManager self;
                p = &self;
            }
            return *p;
        }

        MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8), N>*& get()
        {
            return d_obj;
        }

        void clear()
        {
            d_obj = NULL;
        }

    private:
        MockPrivateManager() { }
        MockPrivateManager(const MockPrivateManager& rhs);
        MockPrivateManager& operator=(const MockPrivateManager& rhs);

        MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8), N>* d_obj;
    };

    template <typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
        typename P7, typename P8, typename P9, int N>
    class MockPrivateManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9), N> {
    public:
        static MockPrivateManager& getInstance()
        {
            static MockPrivateManager* p = NULL;
            BSLMT_ONCE_DO
            {
                static MockPrivateManager self;
                p = &self;
            }
            return *p;
        }

        MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9), N>*& get()
        {
            return d_obj;
        }

        void clear()
        {
            d_obj = NULL;
        }

    private:
        MockPrivateManager() { }
        MockPrivateManager(const MockPrivateManager& rhs);
        MockPrivateManager& operator=(const MockPrivateManager& rhs);

        MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9), N>* d_obj;
    };

    template <typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
        typename P7, typename P8, typename P9, typename P10, int N>
    class MockPrivateManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10), N> {
    public:
        static MockPrivateManager& getInstance()
        {
            static MockPrivateManager* p = NULL;
            BSLMT_ONCE_DO
            {
                static MockPrivateManager self;
                p = &self;
            }
            return *p;
        }

        MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10), N>*& get()
        {
            return d_obj;
        }

        void clear()
        {
            d_obj = NULL;
        }

    private:
        MockPrivateManager() { }
        MockPrivateManager(const MockPrivateManager& rhs);
        MockPrivateManager& operator=(const MockPrivateManager& rhs);

        MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10), N>* d_obj;
    };

    template <typename R, typename C, int N>
    class MockPrivateManager<R (C::*)() const, N> {
    public:
        static MockPrivateManager& getInstance()
        {
            static MockPrivateManager* p = NULL;
            BSLMT_ONCE_DO
            {
                static MockPrivateManager self;
                p = &self;
            }
            return *p;
        }

        MockPrivate<R (C::*)() const, N>*& get()
        {
            return d_obj;
        }

        void clear()
        {
            d_obj = NULL;
        }

    private:
        MockPrivateManager() { }
        MockPrivateManager(const MockPrivateManager& rhs);
        MockPrivateManager& operator=(const MockPrivateManager& rhs);

        MockPrivate<R (C::*)() const, N>* d_obj;
    };

    template <typename R, typename C, typename P1, int N>
    class MockPrivateManager<R (C::*)(P1) const, N> {
    public:
        static MockPrivateManager& getInstance()
        {
            static MockPrivateManager* p = NULL;
            BSLMT_ONCE_DO
            {
                static MockPrivateManager self;
                p = &self;
            }
            return *p;
        }

        MockPrivate<R (C::*)(P1) const, N>*& get()
        {
            return d_obj;
        }

        void clear()
        {
            d_obj = NULL;
        }

    private:
        MockPrivateManager() { }
        MockPrivateManager(const MockPrivateManager& rhs);
        MockPrivateManager& operator=(const MockPrivateManager& rhs);

        MockPrivate<R (C::*)(P1) const, N>* d_obj;
    };

    template <typename R, typename C, typename P1, typename P2, int N>
    class MockPrivateManager<R (C::*)(P1, P2) const, N> {
    public:
        static MockPrivateManager& getInstance()
        {
            static MockPrivateManager* p = NULL;
            BSLMT_ONCE_DO
            {
                static MockPrivateManager self;
                p = &self;
            }
            return *p;
        }

        MockPrivate<R (C::*)(P1, P2) const, N>*& get()
        {
            return d_obj;
        }

        void clear()
        {
            d_obj = NULL;
        }

    private:
        MockPrivateManager() { }
        MockPrivateManager(const MockPrivateManager& rhs);
        MockPrivateManager& operator=(const MockPrivateManager& rhs);

        MockPrivate<R (C::*)(P1, P2) const, N>* d_obj;
    };

    template <typename R, typename C, typename P1, typename P2, typename P3, int N>
    class MockPrivateManager<R (C::*)(P1, P2, P3) const, N> {
    public:
        static MockPrivateManager& getInstance()
        {
            static MockPrivateManager* p = NULL;
            BSLMT_ONCE_DO
            {
                static MockPrivateManager self;
                p = &self;
            }
            return *p;
        }

        MockPrivate<R (C::*)(P1, P2, P3) const, N>*& get()
        {
            return d_obj;
        }

        void clear()
        {
            d_obj = NULL;
        }

    private:
        MockPrivateManager() { }
        MockPrivateManager(const MockPrivateManager& rhs);
        MockPrivateManager& operator=(const MockPrivateManager& rhs);

        MockPrivate<R (C::*)(P1, P2, P3) const, N>* d_obj;
    };

    template <typename R, typename C, typename P1, typename P2, typename P3, typename P4, int N>
    class MockPrivateManager<R (C::*)(P1, P2, P3, P4) const, N> {
    public:
        static MockPrivateManager& getInstance()
        {
            static MockPrivateManager* p = NULL;
            BSLMT_ONCE_DO
            {
                static MockPrivateManager self;
                p = &self;
            }
            return *p;
        }

        MockPrivate<R (C::*)(P1, P2, P3, P4) const, N>*& get()
        {
            return d_obj;
        }

        void clear()
        {
            d_obj = NULL;
        }

    private:
        MockPrivateManager() { }
        MockPrivateManager(const MockPrivateManager& rhs);
        MockPrivateManager& operator=(const MockPrivateManager& rhs);

        MockPrivate<R (C::*)(P1, P2, P3, P4) const, N>* d_obj;
    };

    template <typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, int N>
    class MockPrivateManager<R (C::*)(P1, P2, P3, P4, P5) const, N> {
    public:
        static MockPrivateManager& getInstance()
        {
            static MockPrivateManager* p = NULL;
            BSLMT_ONCE_DO
            {
                static MockPrivateManager self;
                p = &self;
            }
            return *p;
        }

        MockPrivate<R (C::*)(P1, P2, P3, P4, P5) const, N>*& get()
        {
            return d_obj;
        }

        void clear()
        {
            d_obj = NULL;
        }

    private:
        MockPrivateManager() { }
        MockPrivateManager(const MockPrivateManager& rhs);
        MockPrivateManager& operator=(const MockPrivateManager& rhs);

        MockPrivate<R (C::*)(P1, P2, P3, P4, P5) const, N>* d_obj;
    };

    template <typename R, int N>
    class Mock<R(), N> : public GMock<R()> {
        typedef R FuncType();

    public:
        Mock(const bsl::string& funcName)
            : GMock<R()>(funcName)
            , d_targetFunc(NULL)
            , d_funcName(funcName)
        {
            size_t addr = PrivateAddressResolver::findNonConstPrivateAddress(funcName);
            MockManager<R(), N>::getInstance().get() = this;
            void* l_targetAddr = reinterpret_cast<void*>(addr);
            FuncType* l_mockFunction = &Mock::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        Mock(R targetFunc(), const bsl::string& funcName)
            : GMock<R()>(funcName)
            , d_targetFunc(targetFunc)
            , d_funcName(funcName)
        {
            MockManager<R(), N>::getInstance().get() = this;
            // Get function address
            void* l_targetAddr = toCodeAddress(d_targetFunc);
            FuncType* l_mockFunction = &Mock::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        virtual ~Mock()
        {
            // Restore runtime patch
            d_patch.restore();
            MockManager<R(), N>::getInstance().clear();
        }

        static R mockFunction()
        {
            Mock<R(), N>* obj = MockManager<R(), N>::getInstance().get();
            return obj->bonobomockInternalForwardFunc();
        }

        void restore()
        {
            // Restore runtime patch
            d_patch.restore();
        }

    private:
        FuncType* d_targetFunc;
        bsl::string d_funcName;
        Patch d_patch;
    };

    template <typename R, typename P1, int N>
    class Mock<R(P1), N> : public GMock<R(P1)> {
        typedef R FuncType(P1);

    public:
        Mock(const bsl::string& funcName)
            : GMock<R(P1)>(funcName)
            , d_targetFunc(NULL)
            , d_funcName(funcName)
        {
            size_t addr = PrivateAddressResolver::findNonConstPrivateAddress(funcName);
            MockManager<R(P1), N>::getInstance().get() = this;
            void* l_targetAddr = reinterpret_cast<void*>(addr);
            FuncType* l_mockFunction = &Mock::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        Mock(R targetFunc(P1), const bsl::string& funcName)
            : GMock<R(P1)>(funcName)
            , d_targetFunc(targetFunc)
            , d_funcName(funcName)
        {
            MockManager<R(P1), N>::getInstance().get() = this;
            // Get function address
            void* l_targetAddr = toCodeAddress(d_targetFunc);
            FuncType* l_mockFunction = &Mock::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        virtual ~Mock()
        {
            // Restore runtime patch
            d_patch.restore();
            MockManager<R(P1), N>::getInstance().clear();
        }

        static R mockFunction(P1 p1)
        {
            Mock<R(P1), N>* obj = MockManager<R(P1), N>::getInstance().get();
            return obj->bonobomockInternalForwardFunc(p1);
        }

        void restore()
        {
            // Restore runtime patch
            d_patch.restore();
        }

    private:
        FuncType* d_targetFunc;
        bsl::string d_funcName;
        Patch d_patch;
    };

    template <typename R, typename P1, typename P2, int N>
    class Mock<R(P1, P2), N> : public GMock<R(P1, P2)> {
        typedef R FuncType(P1, P2);

    public:
        Mock(const bsl::string& funcName)
            : GMock<R(P1, P2)>(funcName)
            , d_targetFunc(NULL)
            , d_funcName(funcName)
        {
            size_t addr = PrivateAddressResolver::findNonConstPrivateAddress(funcName);
            MockManager<R(P1, P2), N>::getInstance().get() = this;
            void* l_targetAddr = reinterpret_cast<void*>(addr);
            FuncType* l_mockFunction = &Mock::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        Mock(R targetFunc(P1, P2), const bsl::string& funcName)
            : GMock<R(P1, P2)>(funcName)
            , d_targetFunc(targetFunc)
            , d_funcName(funcName)
        {
            MockManager<R(P1, P2), N>::getInstance().get() = this;
            // Get function address
            void* l_targetAddr = toCodeAddress(d_targetFunc);
            FuncType* l_mockFunction = &Mock::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        virtual ~Mock()
        {
            // Restore runtime patch
            d_patch.restore();
            MockManager<R(P1, P2), N>::getInstance().clear();
        }

        static R mockFunction(P1 p1, P2 p2)
        {
            Mock<R(P1, P2), N>* obj = MockManager<R(P1, P2), N>::getInstance().get();
            return obj->bonobomockInternalForwardFunc(p1, p2);
        }

        void restore()
        {
            // Restore runtime patch
            d_patch.restore();
        }

    private:
        FuncType* d_targetFunc;
        bsl::string d_funcName;
        Patch d_patch;
    };

    template <typename R, typename P1, typename P2, typename P3, int N>
    class Mock<R(P1, P2, P3), N> : public GMock<R(P1, P2, P3)> {
        typedef R FuncType(P1, P2, P3);

    public:
        Mock(const bsl::string& funcName)
            : GMock<R(P1, P2, P3)>(funcName)
            , d_targetFunc(NULL)
            , d_funcName(funcName)
        {
            size_t addr = PrivateAddressResolver::findNonConstPrivateAddress(funcName);
            MockManager<R(P1, P2, P3), N>::getInstance().get() = this;
            void* l_targetAddr = reinterpret_cast<void*>(addr);
            FuncType* l_mockFunction = &Mock::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        Mock(R targetFunc(P1, P2, P3), const bsl::string& funcName)
            : GMock<R(P1, P2, P3)>(funcName)
            , d_targetFunc(targetFunc)
            , d_funcName(funcName)
        {
            MockManager<R(P1, P2, P3), N>::getInstance().get() = this;
            // Get function address
            void* l_targetAddr = toCodeAddress(d_targetFunc);
            FuncType* l_mockFunction = &Mock::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        virtual ~Mock()
        {
            // Restore runtime patch
            d_patch.restore();
            MockManager<R(P1, P2, P3), N>::getInstance().clear();
        }

        static R mockFunction(P1 p1, P2 p2, P3 p3)
        {
            Mock<R(P1, P2, P3), N>* obj = MockManager<R(P1, P2, P3), N>::getInstance().get();
            return obj->bonobomockInternalForwardFunc(p1, p2, p3);
        }

        void restore()
        {
            // Restore runtime patch
            d_patch.restore();
        }

    private:
        FuncType* d_targetFunc;
        bsl::string d_funcName;
        Patch d_patch;
    };

    template <typename R, typename P1, typename P2, typename P3, typename P4, int N>
    class Mock<R(P1, P2, P3, P4), N> : public GMock<R(P1, P2, P3, P4)> {
        typedef R FuncType(P1, P2, P3, P4);

    public:
        Mock(const bsl::string& funcName)
            : GMock<R(P1, P2, P3, P4)>(funcName)
            , d_targetFunc(NULL)
            , d_funcName(funcName)
        {
            size_t addr = PrivateAddressResolver::findNonConstPrivateAddress(funcName);
            MockManager<R(P1, P2, P3, P4), N>::getInstance().get() = this;
            void* l_targetAddr = reinterpret_cast<void*>(addr);
            FuncType* l_mockFunction = &Mock::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        Mock(R targetFunc(P1, P2, P3, P4), const bsl::string& funcName)
            : GMock<R(P1, P2, P3, P4)>(funcName)
            , d_targetFunc(targetFunc)
            , d_funcName(funcName)
        {
            MockManager<R(P1, P2, P3, P4), N>::getInstance().get() = this;
            // Get function address
            void* l_targetAddr = toCodeAddress(d_targetFunc);
            FuncType* l_mockFunction = &Mock::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        virtual ~Mock()
        {
            // Restore runtime patch
            d_patch.restore();
            MockManager<R(P1, P2, P3, P4), N>::getInstance().clear();
        }

        static R mockFunction(P1 p1, P2 p2, P3 p3, P4 p4)
        {
            Mock<R(P1, P2, P3, P4), N>* obj = MockManager<R(P1, P2, P3, P4), N>::getInstance().get();
            return obj->bonobomockInternalForwardFunc(p1, p2, p3, p4);
        }

        void restore()
        {
            // Restore runtime patch
            d_patch.restore();
        }

    private:
        FuncType* d_targetFunc;
        bsl::string d_funcName;
        Patch d_patch;
    };

    template <typename R, typename P1, typename P2, typename P3, typename P4, typename P5, int N>
    class Mock<R(P1, P2, P3, P4, P5), N> : public GMock<R(P1, P2, P3, P4, P5)> {
        typedef R FuncType(P1, P2, P3, P4, P5);

    public:
        Mock(const bsl::string& funcName)
            : GMock<R(P1, P2, P3, P4, P5)>(funcName)
            , d_targetFunc(NULL)
            , d_funcName(funcName)
        {
            size_t addr = PrivateAddressResolver::findNonConstPrivateAddress(funcName);
            MockManager<R(P1, P2, P3, P4, P5), N>::getInstance().get() = this;
            void* l_targetAddr = reinterpret_cast<void*>(addr);
            FuncType* l_mockFunction = &Mock::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        Mock(R targetFunc(P1, P2, P3, P4, P5), const bsl::string& funcName)
            : GMock<R(P1, P2, P3, P4, P5)>(funcName)
            , d_targetFunc(targetFunc)
            , d_funcName(funcName)
        {
            MockManager<R(P1, P2, P3, P4, P5), N>::getInstance().get() = this;
            // Get function address
            void* l_targetAddr = toCodeAddress(d_targetFunc);
            FuncType* l_mockFunction = &Mock::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        virtual ~Mock()
        {
            // Restore runtime patch
            d_patch.restore();
            MockManager<R(P1, P2, P3, P4, P5), N>::getInstance().clear();
        }

        static R mockFunction(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5)
        {
            Mock<R(P1, P2, P3, P4, P5), N>* obj = MockManager<R(P1, P2, P3, P4, P5), N>::getInstance().get();
            return obj->bonobomockInternalForwardFunc(p1, p2, p3, p4, p5);
        }

        void restore()
        {
            // Restore runtime patch
            d_patch.restore();
        }

    private:
        FuncType* d_targetFunc;
        bsl::string d_funcName;
        Patch d_patch;
    };

    template <typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, int N>
    class Mock<R(P1, P2, P3, P4, P5, P6), N> : public GMock<R(P1, P2, P3, P4, P5, P6)> {
        typedef R FuncType(P1, P2, P3, P4, P5, P6);

    public:
        Mock(const bsl::string& funcName)
            : GMock<R(P1, P2, P3, P4, P5, P6)>(funcName)
            , d_targetFunc(NULL)
            , d_funcName(funcName)
        {
            size_t addr = PrivateAddressResolver::findNonConstPrivateAddress(funcName);
            MockManager<R(P1, P2, P3, P4, P5, P6), N>::getInstance().get() = this;
            void* l_targetAddr = reinterpret_cast<void*>(addr);
            FuncType* l_mockFunction = &Mock::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        Mock(R targetFunc(P1, P2, P3, P4, P5, P6), const bsl::string& funcName)
            : GMock<R(P1, P2, P3, P4, P5, P6)>(funcName)
            , d_targetFunc(targetFunc)
            , d_funcName(funcName)
        {
            MockManager<R(P1, P2, P3, P4, P5, P6), N>::getInstance().get() = this;
            // Get function address
            void* l_targetAddr = toCodeAddress(d_targetFunc);
            FuncType* l_mockFunction = &Mock::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        virtual ~Mock()
        {
            // Restore runtime patch
            d_patch.restore();
            MockManager<R(P1, P2, P3, P4, P5, P6), N>::getInstance().clear();
        }

        static R mockFunction(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6)
        {
            Mock<R(P1, P2, P3, P4, P5, P6), N>* obj = MockManager<R(P1, P2, P3, P4, P5, P6), N>::getInstance().get();
            return obj->bonobomockInternalForwardFunc(p1, p2, p3, p4, p5, p6);
        }

        void restore()
        {
            // Restore runtime patch
            d_patch.restore();
        }

    private:
        FuncType* d_targetFunc;
        bsl::string d_funcName;
        Patch d_patch;
    };

    template <typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
        typename P7, int N>
    class Mock<R(P1, P2, P3, P4, P5, P6, P7), N> : public GMock<R(P1, P2, P3, P4, P5, P6, P7)> {
        typedef R FuncType(P1, P2, P3, P4, P5, P6, P7);

    public:
        Mock(const bsl::string& funcName)
            : GMock<R(P1, P2, P3, P4, P5, P6, P7)>(funcName)
            , d_targetFunc(NULL)
            , d_funcName(funcName)
        {
            size_t addr = PrivateAddressResolver::findNonConstPrivateAddress(funcName);
            MockManager<R(P1, P2, P3, P4, P5, P6, P7), N>::getInstance().get() = this;
            void* l_targetAddr = reinterpret_cast<void*>(addr);
            FuncType* l_mockFunction = &Mock::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        Mock(R targetFunc(P1, P2, P3, P4, P5, P6, P7), const bsl::string& funcName)
            : GMock<R(P1, P2, P3, P4, P5, P6, P7)>(funcName)
            , d_targetFunc(targetFunc)
            , d_funcName(funcName)
        {
            MockManager<R(P1, P2, P3, P4, P5, P6, P7), N>::getInstance().get() = this;
            // Get function address
            void* l_targetAddr = toCodeAddress(d_targetFunc);
            FuncType* l_mockFunction = &Mock::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        virtual ~Mock()
        {
            // Restore runtime patch
            d_patch.restore();
            MockManager<R(P1, P2, P3, P4, P5, P6, P7), N>::getInstance().clear();
        }

        static R mockFunction(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6, P7 p7)
        {
            Mock<R(P1, P2, P3, P4, P5, P6, P7), N>* obj = MockManager<R(P1, P2, P3, P4, P5, P6, P7), N>::getInstance().get();
            return obj->bonobomockInternalForwardFunc(p1, p2, p3, p4, p5, p6, p7);
        }

        void restore()
        {
            // Restore runtime patch
            d_patch.restore();
        }

    private:
        FuncType* d_targetFunc;
        bsl::string d_funcName;
        Patch d_patch;
    };

    template <typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
        typename P7, typename P8, int N>
    class Mock<R(P1, P2, P3, P4, P5, P6, P7, P8), N> : public GMock<R(P1, P2, P3, P4, P5, P6, P7, P8)> {
        typedef R FuncType(P1, P2, P3, P4, P5, P6, P7, P8);

    public:
        Mock(const bsl::string& funcName)
            : GMock<R(P1, P2, P3, P4, P5, P6, P7, P8)>(funcName)
            , d_targetFunc(NULL)
            , d_funcName(funcName)
        {
            size_t addr = PrivateAddressResolver::findNonConstPrivateAddress(funcName);
            MockManager<R(P1, P2, P3, P4, P5, P6, P7, P8), N>::getInstance().get() = this;
            void* l_targetAddr = reinterpret_cast<void*>(addr);
            FuncType* l_mockFunction = &Mock::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        Mock(R targetFunc(P1, P2, P3, P4, P5, P6, P7, P8), const bsl::string& funcName)
            : GMock<R(P1, P2, P3, P4, P5, P6, P7, P8)>(funcName)
            , d_targetFunc(targetFunc)
            , d_funcName(funcName)
        {
            MockManager<R(P1, P2, P3, P4, P5, P6, P7, P8), N>::getInstance().get() = this;
            // Get function address
            void* l_targetAddr = toCodeAddress(d_targetFunc);
            FuncType* l_mockFunction = &Mock::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        virtual ~Mock()
        {
            // Restore runtime patch
            d_patch.restore();
            MockManager<R(P1, P2, P3, P4, P5, P6, P7, P8), N>::getInstance().clear();
        }

        static R mockFunction(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6, P7 p7, P8 p8)
        {
            Mock<R(P1, P2, P3, P4, P5, P6, P7, P8), N>* obj = MockManager<R(P1, P2, P3, P4, P5, P6, P7, P8), N>::getInstance().get();
            return obj->bonobomockInternalForwardFunc(p1, p2, p3, p4, p5, p6, p7, p8);
        }

        void restore()
        {
            // Restore runtime patch
            d_patch.restore();
        }

    private:
        FuncType* d_targetFunc;
        bsl::string d_funcName;
        Patch d_patch;
    };

    template <typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
        typename P7, typename P8, typename P9, int N>
    class Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9), N> : public GMock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9)> {
        typedef R FuncType(P1, P2, P3, P4, P5, P6, P7, P8, P9);

    public:
        Mock(const bsl::string& funcName)
            : GMock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9)>(funcName)
            , d_targetFunc(NULL)
            , d_funcName(funcName)
        {
            size_t addr = PrivateAddressResolver::findNonConstPrivateAddress(funcName);
            MockManager<R(P1, P2, P3, P4, P5, P6, P7, P8, P9), N>::getInstance().get() = this;
            void* l_targetAddr = reinterpret_cast<void*>(addr);
            FuncType* l_mockFunction = &Mock::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        Mock(R targetFunc(P1, P2, P3, P4, P5, P6, P7, P8, P9), const bsl::string& funcName)
            : GMock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9)>(funcName)
            , d_targetFunc(targetFunc)
            , d_funcName(funcName)
        {
            MockManager<R(P1, P2, P3, P4, P5, P6, P7, P8, P9), N>::getInstance().get() = this;
            // Get function address
            void* l_targetAddr = toCodeAddress(d_targetFunc);
            FuncType* l_mockFunction = &Mock::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        virtual ~Mock()
        {
            // Restore runtime patch
            d_patch.restore();
            MockManager<R(P1, P2, P3, P4, P5, P6, P7, P8, P9), N>::getInstance().clear();
        }

        static R mockFunction(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6, P7 p7, P8 p8, P9 p9)
        {
            Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9), N>* obj = MockManager<R(P1, P2, P3, P4, P5, P6, P7, P8, P9), N>::getInstance().get();
            return obj->bonobomockInternalForwardFunc(p1, p2, p3, p4, p5, p6, p7, p8, p9);
        }

        void restore()
        {
            // Restore runtime patch
            d_patch.restore();
        }

    private:
        FuncType* d_targetFunc;
        bsl::string d_funcName;
        Patch d_patch;
    };

    template <typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
        typename P7, typename P8, typename P9, typename P10, int N>
    class Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10), N> : public GMock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10)> {
        typedef R FuncType(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10);

    public:
        Mock(const bsl::string& funcName)
            : GMock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10)>(funcName)
            , d_targetFunc(NULL)
            , d_funcName(funcName)
        {
            size_t addr = PrivateAddressResolver::findNonConstPrivateAddress(funcName);
            MockManager<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10), N>::getInstance().get() = this;
            void* l_targetAddr = reinterpret_cast<void*>(addr);
            FuncType* l_mockFunction = &Mock::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        Mock(R targetFunc(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10), const bsl::string& funcName)
            : GMock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10)>(funcName)
            , d_targetFunc(targetFunc)
            , d_funcName(funcName)
        {
            MockManager<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10), N>::getInstance().get() = this;
            // Get function address
            void* l_targetAddr = toCodeAddress(d_targetFunc);
            FuncType* l_mockFunction = &Mock::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        virtual ~Mock()
        {
            // Restore runtime patch
            d_patch.restore();
            MockManager<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10), N>::getInstance().clear();
        }

        static R mockFunction(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6, P7 p7, P8 p8, P9 p9, P10 p10)
        {
            Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10), N>* obj = MockManager<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10), N>::getInstance().get();
            return obj->bonobomockInternalForwardFunc(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10);
        }

        void restore()
        {
            // Restore runtime patch
            d_patch.restore();
        }

    private:
        FuncType* d_targetFunc;
        bsl::string d_funcName;
        Patch d_patch;
    };

    template <typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
        typename P7, typename P8, typename P9, typename P10, typename P11, int N>
    class Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11), N> : public GMock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11)> {
        typedef R FuncType(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11);

    public:
        Mock(const bsl::string& funcName)
            : GMock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11)>(funcName)
            , d_targetFunc(NULL)
            , d_funcName(funcName)
        {
            size_t addr = PrivateAddressResolver::findNonConstPrivateAddress(funcName);
            MockManager<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11), N>::getInstance().get() = this;
            void* l_targetAddr = reinterpret_cast<void*>(addr);
            FuncType* l_mockFunction = &Mock::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        Mock(R targetFunc(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11), const bsl::string& funcName)
            : GMock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11)>(funcName)
            , d_targetFunc(targetFunc)
            , d_funcName(funcName)
        {
            MockManager<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11), N>::getInstance().get() = this;
            // Get function address
            void* l_targetAddr = toCodeAddress(d_targetFunc);
            FuncType* l_mockFunction = &Mock::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        virtual ~Mock()
        {
            // Restore runtime patch
            d_patch.restore();
            MockManager<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11), N>::getInstance().clear();
        }

        static R mockFunction(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6, P7 p7, P8 p8, P9 p9, P10 p10, P11 p11)
        {
            Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11), N>* obj = MockManager<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11), N>::getInstance().get();
            return obj->bonobomockInternalForwardFunc(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11);
        }

        void restore()
        {
            // Restore runtime patch
            d_patch.restore();
        }

    private:
        FuncType* d_targetFunc;
        bsl::string d_funcName;
        Patch d_patch;
    };

    template <typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
        typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, int N>
    class Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12), N> : public GMock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12)> {
        typedef R FuncType(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12);

    public:
        Mock(const bsl::string& funcName)
            : GMock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12)>(funcName)
            , d_targetFunc(NULL)
            , d_funcName(funcName)
        {
            size_t addr = PrivateAddressResolver::findNonConstPrivateAddress(funcName);
            MockManager<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12), N>::getInstance().get() = this;
            void* l_targetAddr = reinterpret_cast<void*>(addr);
            FuncType* l_mockFunction = &Mock::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        Mock(R targetFunc(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12), const bsl::string& funcName)
            : GMock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12)>(funcName)
            , d_targetFunc(targetFunc)
            , d_funcName(funcName)
        {
            MockManager<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12), N>::getInstance().get() = this;
            // Get function address
            void* l_targetAddr = toCodeAddress(d_targetFunc);
            FuncType* l_mockFunction = &Mock::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        virtual ~Mock()
        {
            // Restore runtime patch
            d_patch.restore();
            MockManager<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12), N>::getInstance().clear();
        }

        static R mockFunction(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6, P7 p7, P8 p8, P9 p9, P10 p10, P11 p11, P12 p12)
        {
            Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12), N>* obj = MockManager<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12), N>::getInstance().get();
            return obj->bonobomockInternalForwardFunc(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12);
        }

        void restore()
        {
            // Restore runtime patch
            d_patch.restore();
        }

    private:
        FuncType* d_targetFunc;
        bsl::string d_funcName;
        Patch d_patch;
    };

    template <typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
        typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13, int N>
    class Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13), N> : public GMock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13)> {
        typedef R FuncType(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13);

    public:
        Mock(const bsl::string& funcName)
            : GMock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13)>(funcName)
            , d_targetFunc(NULL)
            , d_funcName(funcName)
        {
            size_t addr = PrivateAddressResolver::findNonConstPrivateAddress(funcName);
            MockManager<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13), N>::getInstance().get() = this;
            void* l_targetAddr = reinterpret_cast<void*>(addr);
            FuncType* l_mockFunction = &Mock::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        Mock(R targetFunc(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13), const bsl::string& funcName)
            : GMock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13)>(funcName)
            , d_targetFunc(targetFunc)
            , d_funcName(funcName)
        {
            MockManager<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13), N>::getInstance().get() = this;
            // Get function address
            void* l_targetAddr = toCodeAddress(d_targetFunc);
            FuncType* l_mockFunction = &Mock::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        virtual ~Mock()
        {
            // Restore runtime patch
            d_patch.restore();
            MockManager<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13), N>::getInstance().clear();
        }

        static R mockFunction(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6, P7 p7, P8 p8, P9 p9, P10 p10, P11 p11, P12 p12, P13 p13)
        {
            Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13), N>* obj = MockManager<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13), N>::getInstance().get();
            return obj->bonobomockInternalForwardFunc(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13);
        }

        void restore()
        {
            // Restore runtime patch
            d_patch.restore();
        }

    private:
        FuncType* d_targetFunc;
        bsl::string d_funcName;
        Patch d_patch;
    };

    template <typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
        typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13, typename P14, int N>
    class Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14), N> : public GMock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14)> {
        typedef R FuncType(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14);

    public:
        Mock(const bsl::string& funcName)
            : GMock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14)>(funcName)
            , d_targetFunc(NULL)
            , d_funcName(funcName)
        {
            size_t addr = PrivateAddressResolver::findNonConstPrivateAddress(funcName);
            MockManager<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14), N>::getInstance().get() = this;
            void* l_targetAddr = reinterpret_cast<void*>(addr);
            FuncType* l_mockFunction = &Mock::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        Mock(R targetFunc(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14), const bsl::string& funcName)
            : GMock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14)>(funcName)
            , d_targetFunc(targetFunc)
            , d_funcName(funcName)
        {
            MockManager<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14), N>::getInstance().get() = this;
            // Get function address
            void* l_targetAddr = toCodeAddress(d_targetFunc);
            FuncType* l_mockFunction = &Mock::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        virtual ~Mock()
        {
            // Restore runtime patch
            d_patch.restore();
            MockManager<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14), N>::getInstance().clear();
        }

        static R mockFunction(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6, P7 p7, P8 p8, P9 p9, P10 p10, P11 p11, P12 p12, P13 p13, P14 p14)
        {
            Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14), N>* obj = MockManager<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14), N>::getInstance().get();
            return obj->bonobomockInternalForwardFunc(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14);
        }

        void restore()
        {
            // Restore runtime patch
            d_patch.restore();
        }

    private:
        FuncType* d_targetFunc;
        bsl::string d_funcName;
        Patch d_patch;
    };

    template <typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
        typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13, typename P14, typename P15, int N>
    class Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15), N> : public GMock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15)> {
        typedef R FuncType(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15);

    public:
        Mock(const bsl::string& funcName)
            : GMock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15)>(funcName)
            , d_targetFunc(NULL)
            , d_funcName(funcName)
        {
            size_t addr = PrivateAddressResolver::findNonConstPrivateAddress(funcName);
            MockManager<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15), N>::getInstance().get() = this;
            void* l_targetAddr = reinterpret_cast<void*>(addr);
            FuncType* l_mockFunction = &Mock::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        Mock(R targetFunc(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15), const bsl::string& funcName)
            : GMock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15)>(funcName)
            , d_targetFunc(targetFunc)
            , d_funcName(funcName)
        {
            MockManager<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15), N>::getInstance().get() = this;
            // Get function address
            void* l_targetAddr = toCodeAddress(d_targetFunc);
            FuncType* l_mockFunction = &Mock::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        virtual ~Mock()
        {
            // Restore runtime patch
            d_patch.restore();
            MockManager<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15), N>::getInstance().clear();
        }

        static R mockFunction(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6, P7 p7, P8 p8, P9 p9, P10 p10, P11 p11, P12 p12, P13 p13, P14 p14, P15 p15)
        {
            Mock<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15), N>* obj = MockManager<R(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15), N>::getInstance().get();
            return obj->bonobomockInternalForwardFunc(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15);
        }

        void restore()
        {
            // Restore runtime patch
            d_patch.restore();
        }

    private:
        FuncType* d_targetFunc;
        bsl::string d_funcName;
        Patch d_patch;
    };

    template <typename R, typename C, int N>
    class Mock<R (C::*)(), N> : public GMock<R(void*)> {
        typedef R (Mock::*FuncType)();

    public:
        Mock(R (C::*targetFunc)(), const bsl::string& funcName)
            : GMock<R(void*)>(funcName)
        {
            MockManager<R (C::*)(), N>::getInstance().get() = this;
            // Get function address
            void* l_targetAddr = toCodeAddress(targetFunc);
            FuncType l_mockFunction = &Mock::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        virtual ~Mock()
        {
            // Restore runtime patch
            d_patch.restore();
            MockManager<R (C::*)(), N>::getInstance().clear();
        }

        R mockFunction()
        {
            Mock<R (C::*)(), N>* obj = MockManager<R (C::*)(), N>::getInstance().get();
            return obj->bonobomockInternalForwardFunc(this);
        }

        virtual void restore()
        {
            // Restore runtime patch
            d_patch.restore();
        }

    private:
        Patch d_patch;
    };

    template <typename R, typename C, typename P1, int N>
    class Mock<R (C::*)(P1), N> : public GMock<R(void*, P1)> {
        typedef R (Mock::*FuncType)(P1);

    public:
        Mock(R (C::*targetFunc)(P1), const bsl::string& funcName)
            : GMock<R(void*, P1)>(funcName)
        {
            MockManager<R (C::*)(P1), N>::getInstance().get() = this;
            // Get function address
            void* l_targetAddr = toCodeAddress(targetFunc);
            FuncType l_mockFunction = &Mock::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        virtual ~Mock()
        {
            // Restore runtime patch
            d_patch.restore();
            MockManager<R (C::*)(P1), N>::getInstance().clear();
        }

        R mockFunction(P1 p1)
        {
            Mock<R (C::*)(P1), N>* obj = MockManager<R (C::*)(P1), N>::getInstance().get();
            return obj->bonobomockInternalForwardFunc(this, p1);
        }

        virtual void restore()
        {
            // Restore runtime patch
            d_patch.restore();
        }

    private:
        Patch d_patch;
    };

    template <typename R, typename C, typename P1, typename P2, int N>
    class Mock<R (C::*)(P1, P2), N> : public GMock<R(void*, P1, P2)> {
        typedef R (Mock::*FuncType)(P1, P2);

    public:
        Mock(R (C::*targetFunc)(P1, P2), const bsl::string& funcName)
            : GMock<R(void*, P1, P2)>(funcName)
        {
            MockManager<R (C::*)(P1, P2), N>::getInstance().get() = this;
            // Get function address
            void* l_targetAddr = toCodeAddress(targetFunc);
            FuncType l_mockFunction = &Mock::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        virtual ~Mock()
        {
            // Restore runtime patch
            d_patch.restore();
            MockManager<R (C::*)(P1, P2), N>::getInstance().clear();
        }

        R mockFunction(P1 p1, P2 p2)
        {
            Mock<R (C::*)(P1, P2), N>* obj = MockManager<R (C::*)(P1, P2), N>::getInstance().get();
            return obj->bonobomockInternalForwardFunc(this, p1, p2);
        }

        virtual void restore()
        {
            // Restore runtime patch
            d_patch.restore();
        }

    private:
        Patch d_patch;
    };

    template <typename R, typename C, typename P1, typename P2, typename P3, int N>
    class Mock<R (C::*)(P1, P2, P3), N> : public GMock<R(void*, P1, P2, P3)> {
        typedef R (Mock::*FuncType)(P1, P2, P3);

    public:
        Mock(R (C::*targetFunc)(P1, P2, P3), const bsl::string& funcName)
            : GMock<R(void*, P1, P2, P3)>(funcName)
        {
            MockManager<R (C::*)(P1, P2, P3), N>::getInstance().get() = this;
            // Get function address
            void* l_targetAddr = toCodeAddress(targetFunc);
            FuncType l_mockFunction = &Mock::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        virtual ~Mock()
        {
            // Restore runtime patch
            d_patch.restore();
            MockManager<R (C::*)(P1, P2, P3), N>::getInstance().clear();
        }

        R mockFunction(P1 p1, P2 p2, P3 p3)
        {
            Mock<R (C::*)(P1, P2, P3), N>* obj = MockManager<R (C::*)(P1, P2, P3), N>::getInstance().get();
            return obj->bonobomockInternalForwardFunc(this, p1, p2, p3);
        }

        virtual void restore()
        {
            // Restore runtime patch
            d_patch.restore();
        }

    private:
        Patch d_patch;
    };

    template <typename R, typename C, typename P1, typename P2, typename P3, typename P4, int N>
    class Mock<R (C::*)(P1, P2, P3, P4), N> : public GMock<R(void*, P1, P2, P3, P4)> {
        typedef R (Mock::*FuncType)(P1, P2, P3, P4);

    public:
        Mock(R (C::*targetFunc)(P1, P2, P3, P4), const bsl::string& funcName)
            : GMock<R(void*, P1, P2, P3, P4)>(funcName)
        {
            MockManager<R (C::*)(P1, P2, P3, P4), N>::getInstance().get() = this;
            // Get function address
            void* l_targetAddr = toCodeAddress(targetFunc);
            FuncType l_mockFunction = &Mock::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        virtual ~Mock()
        {
            // Restore runtime patch
            d_patch.restore();
            MockManager<R (C::*)(P1, P2, P3, P4), N>::getInstance().clear();
        }

        R mockFunction(P1 p1, P2 p2, P3 p3, P4 p4)
        {
            Mock<R (C::*)(P1, P2, P3, P4), N>* obj = MockManager<R (C::*)(P1, P2, P3, P4), N>::getInstance().get();
            return obj->bonobomockInternalForwardFunc(this, p1, p2, p3, p4);
        }

        virtual void restore()
        {
            // Restore runtime patch
            d_patch.restore();
        }

    private:
        Patch d_patch;
    };

    template <typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, int N>
    class Mock<R (C::*)(P1, P2, P3, P4, P5), N> : public GMock<R(void*, P1, P2, P3, P4, P5)> {
        typedef R (Mock::*FuncType)(P1, P2, P3, P4, P5);

    public:
        Mock(R (C::*targetFunc)(P1, P2, P3, P4, P5), const bsl::string& funcName)
            : GMock<R(void*, P1, P2, P3, P4, P5)>(funcName)
        {
            MockManager<R (C::*)(P1, P2, P3, P4, P5), N>::getInstance().get() = this;
            // Get function address
            void* l_targetAddr = toCodeAddress(targetFunc);
            FuncType l_mockFunction = &Mock::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        virtual ~Mock()
        {
            // Restore runtime patch
            d_patch.restore();
            MockManager<R (C::*)(P1, P2, P3, P4, P5), N>::getInstance().clear();
        }

        R mockFunction(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5)
        {
            Mock<R (C::*)(P1, P2, P3, P4, P5), N>* obj = MockManager<R (C::*)(P1, P2, P3, P4, P5), N>::getInstance().get();
            return obj->bonobomockInternalForwardFunc(this, p1, p2, p3, p4, p5);
        }

        virtual void restore()
        {
            // Restore runtime patch
            d_patch.restore();
        }

    private:
        Patch d_patch;
    };

    template <typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, int N>
    class Mock<R (C::*)(P1, P2, P3, P4, P5, P6), N> : public GMock<R(void*, P1, P2, P3, P4, P5, P6)> {
        typedef R (Mock::*FuncType)(P1, P2, P3, P4, P5, P6);

    public:
        Mock(R (C::*targetFunc)(P1, P2, P3, P4, P5, P6), const bsl::string& funcName)
            : GMock<R(void*, P1, P2, P3, P4, P5, P6)>(funcName)
        {
            MockManager<R (C::*)(P1, P2, P3, P4, P5, P6), N>::getInstance().get() = this;
            // Get function address
            void* l_targetAddr = toCodeAddress(targetFunc);
            FuncType l_mockFunction = &Mock::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        virtual ~Mock()
        {
            // Restore runtime patch
            d_patch.restore();
            MockManager<R (C::*)(P1, P2, P3, P4, P5, P6), N>::getInstance().clear();
        }

        R mockFunction(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6)
        {
            Mock<R (C::*)(P1, P2, P3, P4, P5, P6), N>* obj = MockManager<R (C::*)(P1, P2, P3, P4, P5, P6), N>::getInstance().get();
            return obj->bonobomockInternalForwardFunc(this, p1, p2, p3, p4, p5, p6);
        }

        virtual void restore()
        {
            // Restore runtime patch
            d_patch.restore();
        }

    private:
        Patch d_patch;
    };

    template <typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
        typename P7, int N>
    class Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7), N> : public GMock<R(void*, P1, P2, P3, P4, P5, P6, P7)> {
        typedef R (Mock::*FuncType)(P1, P2, P3, P4, P5, P6, P7);

    public:
        Mock(R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7), const bsl::string& funcName)
            : GMock<R(void*, P1, P2, P3, P4, P5, P6, P7)>(funcName)
        {
            MockManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7), N>::getInstance().get() = this;
            // Get function address
            void* l_targetAddr = toCodeAddress(targetFunc);
            FuncType l_mockFunction = &Mock::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        virtual ~Mock()
        {
            // Restore runtime patch
            d_patch.restore();
            MockManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7), N>::getInstance().clear();
        }

        R mockFunction(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6, P7 p7)
        {
            Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7), N>* obj = MockManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7), N>::getInstance().get();
            return obj->bonobomockInternalForwardFunc(this, p1, p2, p3, p4, p5, p6, p7);
        }

        virtual void restore()
        {
            // Restore runtime patch
            d_patch.restore();
        }

    private:
        Patch d_patch;
    };

    template <typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
        typename P7, typename P8, int N>
    class Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8), N> : public GMock<R(void*, P1, P2, P3, P4, P5, P6, P7, P8)> {
        typedef R (Mock::*FuncType)(P1, P2, P3, P4, P5, P6, P7, P8);

    public:
        Mock(R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8), const bsl::string& funcName)
            : GMock<R(void*, P1, P2, P3, P4, P5, P6, P7, P8)>(funcName)
        {
            MockManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8), N>::getInstance().get() = this;
            // Get function address
            void* l_targetAddr = toCodeAddress(targetFunc);
            FuncType l_mockFunction = &Mock::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        virtual ~Mock()
        {
            // Restore runtime patch
            d_patch.restore();
            MockManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8), N>::getInstance().clear();
        }

        R mockFunction(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6, P7 p7, P8 p8)
        {
            Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8), N>* obj = MockManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8), N>::getInstance().get();
            return obj->bonobomockInternalForwardFunc(this, p1, p2, p3, p4, p5, p6, p7, p8);
        }

        virtual void restore()
        {
            // Restore runtime patch
            d_patch.restore();
        }

    private:
        Patch d_patch;
    };

    template <typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
        typename P7, typename P8, typename P9, int N>
    class Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9), N> : public GMock<R(void*, P1, P2, P3, P4, P5, P6, P7, P8, P9)> {
        typedef R (Mock::*FuncType)(P1, P2, P3, P4, P5, P6, P7, P8, P9);

    public:
        Mock(R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9), const bsl::string& funcName)
            : GMock<R(void*, P1, P2, P3, P4, P5, P6, P7, P8, P9)>(funcName)
        {
            MockManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9), N>::getInstance().get() = this;
            // Get function address
            void* l_targetAddr = toCodeAddress(targetFunc);
            FuncType l_mockFunction = &Mock::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        virtual ~Mock()
        {
            // Restore runtime patch
            d_patch.restore();
            MockManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9), N>::getInstance().clear();
        }

        R mockFunction(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6, P7 p7, P8 p8, P9 p9)
        {
            Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9), N>* obj = MockManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9), N>::getInstance().get();
            return obj->bonobomockInternalForwardFunc(this, p1, p2, p3, p4, p5, p6, p7, p8, p9);
        }

        virtual void restore()
        {
            // Restore runtime patch
            d_patch.restore();
        }

    private:
        Patch d_patch;
    };

    template <typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
        typename P7, typename P8, typename P9, typename P10, int N>
    class Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10), N> : public GMock<R(void*, P1, P2, P3, P4, P5, P6, P7, P8, P9, P10)> {
        typedef R (Mock::*FuncType)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10);

    public:
        Mock(R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10), const bsl::string& funcName)
            : GMock<R(void*, P1, P2, P3, P4, P5, P6, P7, P8, P9, P10)>(funcName)
        {
            MockManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10), N>::getInstance().get() = this;
            // Get function address
            void* l_targetAddr = toCodeAddress(targetFunc);
            FuncType l_mockFunction = &Mock::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        virtual ~Mock()
        {
            // Restore runtime patch
            d_patch.restore();
            MockManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10), N>::getInstance().clear();
        }

        R mockFunction(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6, P7 p7, P8 p8, P9 p9, P10 p10)
        {
            Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10), N>* obj = MockManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10), N>::getInstance().get();
            return obj->bonobomockInternalForwardFunc(this, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10);
        }

        virtual void restore()
        {
            // Restore runtime patch
            d_patch.restore();
        }

    private:
        Patch d_patch;
    };

    template <typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
        typename P7, typename P8, typename P9, typename P10, typename P11, int N>
    class Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11), N> : public GMock<R(void*, P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11)> {
        typedef R (Mock::*FuncType)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11);

    public:
        Mock(R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11), const bsl::string& funcName)
            : GMock<R(void*, P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11)>(funcName)
        {
            MockManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11), N>::getInstance().get() = this;
            // Get function address
            void* l_targetAddr = toCodeAddress(targetFunc);
            FuncType l_mockFunction = &Mock::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        virtual ~Mock()
        {
            // Restore runtime patch
            d_patch.restore();
            MockManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11), N>::getInstance().clear();
        }

        R mockFunction(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6, P7 p7, P8 p8, P9 p9, P10 p10, P11 p11)
        {
            Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11), N>* obj = MockManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11), N>::getInstance().get();
            return obj->bonobomockInternalForwardFunc(this, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11);
        }

        virtual void restore()
        {
            // Restore runtime patch
            d_patch.restore();
        }

    private:
        Patch d_patch;
    };

    template <typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
        typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, int N>
    class Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12), N> : public GMock<R(void*, P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12)> {
        typedef R (Mock::*FuncType)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12);

    public:
        Mock(R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12), const bsl::string& funcName)
            : GMock<R(void*, P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12)>(funcName)
        {
            MockManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12), N>::getInstance().get() = this;
            // Get function address
            void* l_targetAddr = toCodeAddress(targetFunc);
            FuncType l_mockFunction = &Mock::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        virtual ~Mock()
        {
            // Restore runtime patch
            d_patch.restore();
            MockManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12), N>::getInstance().clear();
        }

        R mockFunction(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6, P7 p7, P8 p8, P9 p9, P10 p10, P11 p11, P12 p12)
        {
            Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12), N>* obj = MockManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12), N>::getInstance().get();
            return obj->bonobomockInternalForwardFunc(this, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12);
        }

        virtual void restore()
        {
            // Restore runtime patch
            d_patch.restore();
        }

    private:
        Patch d_patch;
    };

    template <typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
        typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13, int N>
    class Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13), N> : public GMock<R(void*, P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13)> {
        typedef R (Mock::*FuncType)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13);

    public:
        Mock(R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13), const bsl::string& funcName)
            : GMock<R(void*, P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13)>(funcName)
        {
            MockManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13), N>::getInstance().get() = this;
            // Get function address
            void* l_targetAddr = toCodeAddress(targetFunc);
            FuncType l_mockFunction = &Mock::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        virtual ~Mock()
        {
            // Restore runtime patch
            d_patch.restore();
            MockManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13), N>::getInstance().clear();
        }

        R mockFunction(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6, P7 p7, P8 p8, P9 p9, P10 p10, P11 p11, P12 p12, P13 p13)
        {
            Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13), N>* obj = MockManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13), N>::getInstance().get();
            return obj->bonobomockInternalForwardFunc(this, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13);
        }

        virtual void restore()
        {
            // Restore runtime patch
            d_patch.restore();
        }

    private:
        Patch d_patch;
    };

    template <typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
        typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13, typename P14, int N>
    class Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14), N> : public GMock<R(void*, P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14)> {
        typedef R (Mock::*FuncType)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14);

    public:
        Mock(R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14), const bsl::string& funcName)
            : GMock<R(void*, P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14)>(funcName)
        {
            MockManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14), N>::getInstance().get() = this;
            // Get function address
            void* l_targetAddr = toCodeAddress(targetFunc);
            FuncType l_mockFunction = &Mock::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        virtual ~Mock()
        {
            // Restore runtime patch
            d_patch.restore();
            MockManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14), N>::getInstance().clear();
        }

        R mockFunction(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6, P7 p7, P8 p8, P9 p9, P10 p10, P11 p11, P12 p12, P13 p13, P14 p14)
        {
            Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14), N>* obj = MockManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14), N>::getInstance().get();
            return obj->bonobomockInternalForwardFunc(this, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14);
        }

        virtual void restore()
        {
            // Restore runtime patch
            d_patch.restore();
        }

    private:
        Patch d_patch;
    };

    template <typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
        typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13, typename P14, typename P15, int N>
    class Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15), N> : public GMock<R(void*, P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15)> {
        typedef R (Mock::*FuncType)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15);

    public:
        Mock(R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15), const bsl::string& funcName)
            : GMock<R(void*, P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15)>(funcName)
        {
            MockManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15), N>::getInstance().get() = this;
            // Get function address
            void* l_targetAddr = toCodeAddress(targetFunc);
            FuncType l_mockFunction = &Mock::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        virtual ~Mock()
        {
            // Restore runtime patch
            d_patch.restore();
            MockManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15), N>::getInstance().clear();
        }

        R mockFunction(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6, P7 p7, P8 p8, P9 p9, P10 p10, P11 p11, P12 p12, P13 p13, P14 p14, P15 p15)
        {
            Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15), N>* obj = MockManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15), N>::getInstance().get();
            return obj->bonobomockInternalForwardFunc(this, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15);
        }

        virtual void restore()
        {
            // Restore runtime patch
            d_patch.restore();
        }

    private:
        Patch d_patch;
    };

    template <typename R, typename C, int N>
    class Mock<R (C::*)() const, N> : public GMock<R(const void*)> {
        typedef R (Mock::*FuncType)();

    public:
        Mock(R (C::*targetFunc)() const, const bsl::string& funcName)
            : GMock<R(const void*)>(funcName)
        {
            MockManager<R (C::*)() const, N>::getInstance().get() = this;
            // Get function address
            void* l_targetAddr = toCodeAddress(targetFunc);
            FuncType l_mockFunction = &Mock::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        virtual ~Mock()
        {
            // Restore runtime patch
            d_patch.restore();
            MockManager<R (C::*)(), N>::getInstance().clear();
        }

        R mockFunction()
        {
            Mock<R (C::*)() const, N>* obj = MockManager<R (C::*)() const, N>::getInstance().get();
            return obj->bonobomockInternalForwardFunc(this);
        }

        virtual void restore()
        {
            // Restore runtime patch
            d_patch.restore();
        }

    private:
        Patch d_patch;
    };

    template <typename R, typename C, typename P1, int N>
    class Mock<R (C::*)(P1) const, N> : public GMock<R(const void*, P1)> {
        typedef R (Mock::*FuncType)(P1);

    public:
        Mock(R (C::*targetFunc)(P1) const, const bsl::string& funcName)
            : GMock<R(const void*, P1)>(funcName)
        {
            MockManager<R (C::*)(P1) const, N>::getInstance().get() = this;
            // Get function address
            void* l_targetAddr = toCodeAddress(targetFunc);
            FuncType l_mockFunction = &Mock::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        virtual ~Mock()
        {
            // Restore runtime patch
            d_patch.restore();
            MockManager<R (C::*)(P1), N>::getInstance().clear();
        }

        R mockFunction(P1 p1)
        {
            Mock<R (C::*)(P1) const, N>* obj = MockManager<R (C::*)(P1) const, N>::getInstance().get();
            return obj->bonobomockInternalForwardFunc(this, p1);
        }

        virtual void restore()
        {
            // Restore runtime patch
            d_patch.restore();
        }

    private:
        Patch d_patch;
    };

    template <typename R, typename C, typename P1, typename P2, int N>
    class Mock<R (C::*)(P1, P2) const, N> : public GMock<R(const void*, P1, P2)> {
        typedef R (Mock::*FuncType)(P1, P2);

    public:
        Mock(R (C::*targetFunc)(P1, P2) const, const bsl::string& funcName)
            : GMock<R(const void*, P1, P2)>(funcName)
        {
            MockManager<R (C::*)(P1, P2) const, N>::getInstance().get() = this;
            // Get function address
            void* l_targetAddr = toCodeAddress(targetFunc);
            FuncType l_mockFunction = &Mock::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        virtual ~Mock()
        {
            // Restore runtime patch
            d_patch.restore();
            MockManager<R (C::*)(P1, P2), N>::getInstance().clear();
        }

        R mockFunction(P1 p1, P2 p2)
        {
            Mock<R (C::*)(P1, P2) const, N>* obj = MockManager<R (C::*)(P1, P2) const, N>::getInstance().get();
            return obj->bonobomockInternalForwardFunc(this, p1, p2);
        }

        virtual void restore()
        {
            // Restore runtime patch
            d_patch.restore();
        }

    private:
        Patch d_patch;
    };

    template <typename R, typename C, typename P1, typename P2, typename P3, int N>
    class Mock<R (C::*)(P1, P2, P3) const, N> : public GMock<R(const void*, P1, P2, P3)> {
        typedef R (Mock::*FuncType)(P1, P2, P3);

    public:
        Mock(R (C::*targetFunc)(P1, P2, P3) const, const bsl::string& funcName)
            : GMock<R(const void*, P1, P2, P3)>(funcName)
        {
            MockManager<R (C::*)(P1, P2, P3) const, N>::getInstance().get() = this;
            // Get function address
            void* l_targetAddr = toCodeAddress(targetFunc);
            FuncType l_mockFunction = &Mock::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        virtual ~Mock()
        {
            // Restore runtime patch
            d_patch.restore();
            MockManager<R (C::*)(P1, P2, P3), N>::getInstance().clear();
        }

        R mockFunction(P1 p1, P2 p2, P3 p3)
        {
            Mock<R (C::*)(P1, P2, P3) const, N>* obj = MockManager<R (C::*)(P1, P2, P3) const, N>::getInstance().get();
            return obj->bonobomockInternalForwardFunc(this, p1, p2, p3);
        }

        virtual void restore()
        {
            // Restore runtime patch
            d_patch.restore();
        }

    private:
        Patch d_patch;
    };

    template <typename R, typename C, typename P1, typename P2, typename P3, typename P4, int N>
    class Mock<R (C::*)(P1, P2, P3, P4) const, N> : public GMock<R(const void*, P1, P2, P3, P4)> {
        typedef R (Mock::*FuncType)(P1, P2, P3, P4);

    public:
        Mock(R (C::*targetFunc)(P1, P2, P3, P4) const, const bsl::string& funcName)
            : GMock<R(const void*, P1, P2, P3, P4)>(funcName)
        {
            MockManager<R (C::*)(P1, P2, P3, P4) const, N>::getInstance().get() = this;
            // Get function address
            void* l_targetAddr = toCodeAddress(targetFunc);
            FuncType l_mockFunction = &Mock::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        virtual ~Mock()
        {
            // Restore runtime patch
            d_patch.restore();
            MockManager<R (C::*)(P1, P2, P3, P4), N>::getInstance().clear();
        }

        R mockFunction(P1 p1, P2 p2, P3 p3, P4 p4)
        {
            Mock<R (C::*)(P1, P2, P3, P4) const, N>* obj = MockManager<R (C::*)(P1, P2, P3, P4) const, N>::getInstance().get();
            return obj->bonobomockInternalForwardFunc(this, p1, p2, p3, p4);
        }

        virtual void restore()
        {
            // Restore runtime patch
            d_patch.restore();
        }

    private:
        Patch d_patch;
    };

    template <typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, int N>
    class Mock<R (C::*)(P1, P2, P3, P4, P5) const, N> : public GMock<R(const void*, P1, P2, P3, P4, P5)> {
        typedef R (Mock::*FuncType)(P1, P2, P3, P4, P5);

    public:
        Mock(R (C::*targetFunc)(P1, P2, P3, P4, P5) const, const bsl::string& funcName)
            : GMock<R(const void*, P1, P2, P3, P4, P5)>(funcName)
        {
            MockManager<R (C::*)(P1, P2, P3, P4, P5) const, N>::getInstance().get() = this;
            // Get function address
            void* l_targetAddr = toCodeAddress(targetFunc);
            FuncType l_mockFunction = &Mock::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        virtual ~Mock()
        {
            // Restore runtime patch
            d_patch.restore();
            MockManager<R (C::*)(P1, P2, P3, P4, P5), N>::getInstance().clear();
        }

        R mockFunction(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5)
        {
            Mock<R (C::*)(P1, P2, P3, P4, P5) const, N>* obj = MockManager<R (C::*)(P1, P2, P3, P4, P5) const, N>::getInstance().get();
            return obj->bonobomockInternalForwardFunc(this, p1, p2, p3, p4, p5);
        }

        virtual void restore()
        {
            // Restore runtime patch
            d_patch.restore();
        }

    private:
        Patch d_patch;
    };

    template <typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, int N>
    class Mock<R (C::*)(P1, P2, P3, P4, P5, P6) const, N> : public GMock<R(const void*, P1, P2, P3, P4, P5, P6)> {
        typedef R (Mock::*FuncType)(P1, P2, P3, P4, P5, P6);

    public:
        Mock(R (C::*targetFunc)(P1, P2, P3, P4, P5, P6) const, const bsl::string& funcName)
            : GMock<R(const void*, P1, P2, P3, P4, P5, P6)>(funcName)
        {
            MockManager<R (C::*)(P1, P2, P3, P4, P5, P6) const, N>::getInstance().get() = this;
            // Get function address
            void* l_targetAddr = toCodeAddress(targetFunc);
            FuncType l_mockFunction = &Mock::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        virtual ~Mock()
        {
            // Restore runtime patch
            d_patch.restore();
            MockManager<R (C::*)(P1, P2, P3, P4, P5, P6), N>::getInstance().clear();
        }

        R mockFunction(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6)
        {
            Mock<R (C::*)(P1, P2, P3, P4, P5, P6) const, N>* obj = MockManager<R (C::*)(P1, P2, P3, P4, P5, P6) const, N>::getInstance().get();
            return obj->bonobomockInternalForwardFunc(this, p1, p2, p3, p4, p5, p6);
        }

        virtual void restore()
        {
            // Restore runtime patch
            d_patch.restore();
        }

    private:
        Patch d_patch;
    };

    template <typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
        typename P7, int N>
    class Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7) const, N> : public GMock<R(const void*, P1, P2, P3, P4, P5, P6, P7)> {
        typedef R (Mock::*FuncType)(P1, P2, P3, P4, P5, P6, P7);

    public:
        Mock(R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7) const, const bsl::string& funcName)
            : GMock<R(const void*, P1, P2, P3, P4, P5, P6, P7)>(funcName)
        {
            MockManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7) const, N>::getInstance().get() = this;
            // Get function address
            void* l_targetAddr = toCodeAddress(targetFunc);
            FuncType l_mockFunction = &Mock::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        virtual ~Mock()
        {
            // Restore runtime patch
            d_patch.restore();
            MockManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7), N>::getInstance().clear();
        }

        R mockFunction(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6, P7 p7)
        {
            Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7) const, N>* obj = MockManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7) const, N>::getInstance().get();
            return obj->bonobomockInternalForwardFunc(this, p1, p2, p3, p4, p5, p6, p7);
        }

        virtual void restore()
        {
            // Restore runtime patch
            d_patch.restore();
        }

    private:
        Patch d_patch;
    };

    template <typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
        typename P7, typename P8, int N>
    class Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8) const, N> : public GMock<R(const void*, P1, P2, P3, P4, P5, P6, P7, P8)> {
        typedef R (Mock::*FuncType)(P1, P2, P3, P4, P5, P6, P7, P8);

    public:
        Mock(R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8) const, const bsl::string& funcName)
            : GMock<R(const void*, P1, P2, P3, P4, P5, P6, P7, P8)>(funcName)
        {
            MockManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8) const, N>::getInstance().get() = this;
            // Get function address
            void* l_targetAddr = toCodeAddress(targetFunc);
            FuncType l_mockFunction = &Mock::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        virtual ~Mock()
        {
            // Restore runtime patch
            d_patch.restore();
            MockManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8), N>::getInstance().clear();
        }

        R mockFunction(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6, P7 p7, P8 p8)
        {
            Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8) const, N>* obj = MockManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8) const, N>::getInstance().get();
            return obj->bonobomockInternalForwardFunc(this, p1, p2, p3, p4, p5, p6, p7, p8);
        }

        virtual void restore()
        {
            // Restore runtime patch
            d_patch.restore();
        }

    private:
        Patch d_patch;
    };

    template <typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
        typename P7, typename P8, typename P9, int N>
    class Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9) const, N> : public GMock<R(const void*, P1, P2, P3, P4, P5, P6, P7, P8, P9)> {
        typedef R (Mock::*FuncType)(P1, P2, P3, P4, P5, P6, P7, P8, P9);

    public:
        Mock(R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9) const, const bsl::string& funcName)
            : GMock<R(const void*, P1, P2, P3, P4, P5, P6, P7, P8, P9)>(funcName)
        {
            MockManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9) const, N>::getInstance().get() = this;
            // Get function address
            void* l_targetAddr = toCodeAddress(targetFunc);
            FuncType l_mockFunction = &Mock::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        virtual ~Mock()
        {
            // Restore runtime patch
            d_patch.restore();
            MockManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9), N>::getInstance().clear();
        }

        R mockFunction(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6, P7 p7, P8 p8, P9 p9)
        {
            Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9) const, N>* obj = MockManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9) const, N>::getInstance().get();
            return obj->bonobomockInternalForwardFunc(this, p1, p2, p3, p4, p5, p6, p7, p8, p9);
        }

        virtual void restore()
        {
            // Restore runtime patch
            d_patch.restore();
        }

    private:
        Patch d_patch;
    };

    template <typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
        typename P7, typename P8, typename P9, typename P10, int N>
    class Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10) const, N> : public GMock<R(const void*, P1, P2, P3, P4, P5, P6, P7, P8, P9, P10)> {
        typedef R (Mock::*FuncType)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10);

    public:
        Mock(R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10) const, const bsl::string& funcName)
            : GMock<R(const void*, P1, P2, P3, P4, P5, P6, P7, P8, P9, P10)>(funcName)
        {
            MockManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10) const, N>::getInstance().get() = this;
            // Get function address
            void* l_targetAddr = toCodeAddress(targetFunc);
            FuncType l_mockFunction = &Mock::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        virtual ~Mock()
        {
            // Restore runtime patch
            d_patch.restore();
            MockManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10), N>::getInstance().clear();
        }

        R mockFunction(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6, P7 p7, P8 p8, P9 p9, P10 p10)
        {
            Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10) const, N>* obj = MockManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10) const, N>::getInstance().get();
            return obj->bonobomockInternalForwardFunc(this, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10);
        }

        virtual void restore()
        {
            // Restore runtime patch
            d_patch.restore();
        }

    private:
        Patch d_patch;
    };

    template <typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
        typename P7, typename P8, typename P9, typename P10, typename P11, int N>
    class Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11) const, N> : public GMock<R(const void*, P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11)> {
        typedef R (Mock::*FuncType)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11);

    public:
        Mock(R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11) const, const bsl::string& funcName)
            : GMock<R(const void*, P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11)>(funcName)
        {
            MockManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11) const, N>::getInstance().get() = this;
            // Get function address
            void* l_targetAddr = toCodeAddress(targetFunc);
            FuncType l_mockFunction = &Mock::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        virtual ~Mock()
        {
            // Restore runtime patch
            d_patch.restore();
            MockManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11), N>::getInstance().clear();
        }

        R mockFunction(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6, P7 p7, P8 p8, P9 p9, P10 p10, P11 p11)
        {
            Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11) const, N>* obj = MockManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11) const, N>::getInstance().get();
            return obj->bonobomockInternalForwardFunc(this, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11);
        }

        virtual void restore()
        {
            // Restore runtime patch
            d_patch.restore();
        }

    private:
        Patch d_patch;
    };

    template <typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
        typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, int N>
    class Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12) const, N> : public GMock<R(const void*, P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12)> {
        typedef R (Mock::*FuncType)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12);

    public:
        Mock(R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12) const, const bsl::string& funcName)
            : GMock<R(const void*, P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12)>(funcName)
        {
            MockManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12) const, N>::getInstance().get() = this;
            // Get function address
            void* l_targetAddr = toCodeAddress(targetFunc);
            FuncType l_mockFunction = &Mock::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        virtual ~Mock()
        {
            // Restore runtime patch
            d_patch.restore();
            MockManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12), N>::getInstance().clear();
        }

        R mockFunction(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6, P7 p7, P8 p8, P9 p9, P10 p10, P11 p11, P12 p12)
        {
            Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12) const, N>* obj = MockManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12) const, N>::getInstance().get();
            return obj->bonobomockInternalForwardFunc(this, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12);
        }

        virtual void restore()
        {
            // Restore runtime patch
            d_patch.restore();
        }

    private:
        Patch d_patch;
    };

    template <typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
        typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13, int N>
    class Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13) const, N> : public GMock<R(const void*, P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13)> {
        typedef R (Mock::*FuncType)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13);

    public:
        Mock(R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13) const, const bsl::string& funcName)
            : GMock<R(const void*, P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13)>(funcName)
        {
            MockManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13) const, N>::getInstance().get() = this;
            // Get function address
            void* l_targetAddr = toCodeAddress(targetFunc);
            FuncType l_mockFunction = &Mock::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        virtual ~Mock()
        {
            // Restore runtime patch
            d_patch.restore();
            MockManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13), N>::getInstance().clear();
        }

        R mockFunction(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6, P7 p7, P8 p8, P9 p9, P10 p10, P11 p11, P12 p12, P13 p13)
        {
            Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13) const, N>* obj = MockManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13) const, N>::getInstance().get();
            return obj->bonobomockInternalForwardFunc(this, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13);
        }

        virtual void restore()
        {
            // Restore runtime patch
            d_patch.restore();
        }

    private:
        Patch d_patch;
    };

    template <typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
        typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13, typename P14, int N>
    class Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14) const, N> : public GMock<R(const void*, P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14)> {
        typedef R (Mock::*FuncType)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14);

    public:
        Mock(R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14) const, const bsl::string& funcName)
            : GMock<R(const void*, P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14)>(funcName)
        {
            MockManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14) const, N>::getInstance().get() = this;
            // Get function address
            void* l_targetAddr = toCodeAddress(targetFunc);
            FuncType l_mockFunction = &Mock::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        virtual ~Mock()
        {
            // Restore runtime patch
            d_patch.restore();
            MockManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14), N>::getInstance().clear();
        }

        R mockFunction(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6, P7 p7, P8 p8, P9 p9, P10 p10, P11 p11, P12 p12, P13 p13, P14 p14)
        {
            Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14) const, N>* obj = MockManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14) const, N>::getInstance().get();
            return obj->bonobomockInternalForwardFunc(this, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14);
        }

        virtual void restore()
        {
            // Restore runtime patch
            d_patch.restore();
        }

    private:
        Patch d_patch;
    };

    template <typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
        typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13, typename P14, typename P15, int N>
    class Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15) const, N> : public GMock<R(const void*, P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15)> {
        typedef R (Mock::*FuncType)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15);

    public:
        Mock(R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15) const, const bsl::string& funcName)
            : GMock<R(const void*, P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15)>(funcName)
        {
            MockManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15) const, N>::getInstance().get() = this;
            // Get function address
            void* l_targetAddr = toCodeAddress(targetFunc);
            FuncType l_mockFunction = &Mock::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        virtual ~Mock()
        {
            // Restore runtime patch
            d_patch.restore();
            MockManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15), N>::getInstance().clear();
        }

        R mockFunction(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6, P7 p7, P8 p8, P9 p9, P10 p10, P11 p11, P12 p12, P13 p13, P14 p14, P15 p15)
        {
            Mock<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15) const, N>* obj = MockManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15) const, N>::getInstance().get();
            return obj->bonobomockInternalForwardFunc(this, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15);
        }

        virtual void restore()
        {
            // Restore runtime patch
            d_patch.restore();
        }

    private:
        Patch d_patch;
    };

    template <typename R, typename C, int N>
    class MockVirtual<R (C::*)(), N> : public GMock<R(void*)> {
        typedef R (MockVirtual::*FuncType)();

    public:
        MockVirtual(R (C::*targetFunc)(), const bsl::string& funcName)
            : GMock<R(void*)>(funcName)
        {
            MockVirtualManager<R (C::*)(), N>::getInstance().get() = this;
            C l_obj;
            void* l_targetAddr = resolveVirtualAddress(
                reinterpret_cast<const void*>(&targetFunc),
                reinterpret_cast<void*>(&l_obj));
            FuncType l_mockFunction = &MockVirtual::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        MockVirtual(const C& inst, R (C::*targetFunc)(), const bsl::string& funcName)
            : GMock<R(void*)>(funcName)
        {
            MockVirtualManager<R (C::*)(), N>::getInstance().get() = this;
            void* l_targetAddr = resolveVirtualAddress(
                reinterpret_cast<const void*>(&targetFunc),
                const_cast<void*>(reinterpret_cast<const void*>(&inst)));
            FuncType l_mockFunction = &MockVirtual::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        virtual ~MockVirtual()
        {
            // Restore runtime patch
            d_patch.restore();
            MockVirtualManager<R (C::*)(), N>::getInstance().clear();
        }

        R mockFunction()
        {
            MockVirtual<R (C::*)(), N>* obj = MockVirtualManager<R (C::*)(), N>::getInstance().get();
            return obj->bonobomockInternalForwardFunc(this);
        }

        virtual void restore()
        {
            // Restore runtime patch
            d_patch.restore();
        }

    private:
        Patch d_patch;
    };

    template <typename R, typename C, typename P1, int N>
    class MockVirtual<R (C::*)(P1), N> : public GMock<R(void*, P1)> {
        typedef R (MockVirtual::*FuncType)(P1);

    public:
        MockVirtual(R (C::*targetFunc)(P1), const bsl::string& funcName)
            : GMock<R(void*, P1)>(funcName)
        {
            MockVirtualManager<R (C::*)(P1), N>::getInstance().get() = this;
            C l_obj;
            void* l_targetAddr = resolveVirtualAddress(
                reinterpret_cast<const void*>(&targetFunc),
                reinterpret_cast<void*>(&l_obj));
            FuncType l_mockFunction = &MockVirtual::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        MockVirtual(const C& inst, R (C::*targetFunc)(P1), const bsl::string& funcName)
            : GMock<R(void*, P1)>(funcName)
        {
            MockVirtualManager<R (C::*)(P1), N>::getInstance().get() = this;
            void* l_targetAddr = resolveVirtualAddress(
                reinterpret_cast<const void*>(&targetFunc),
                const_cast<void*>(reinterpret_cast<const void*>(&inst)));
            FuncType l_mockFunction = &MockVirtual::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        virtual ~MockVirtual()
        {
            // Restore runtime patch
            d_patch.restore();
            MockVirtualManager<R (C::*)(P1), N>::getInstance().clear();
        }

        R mockFunction(P1 p1)
        {
            MockVirtual<R (C::*)(P1), N>* obj = MockVirtualManager<R (C::*)(P1), N>::getInstance().get();
            return obj->bonobomockInternalForwardFunc(this, p1);
        }

        virtual void restore()
        {
            // Restore runtime patch
            d_patch.restore();
        }

    private:
        Patch d_patch;
    };

    template <typename R, typename C, typename P1, typename P2, int N>
    class MockVirtual<R (C::*)(P1, P2), N> : public GMock<R(void*, P1, P2)> {
        typedef R (MockVirtual::*FuncType)(P1, P2);

    public:
        MockVirtual(R (C::*targetFunc)(P1, P2), const bsl::string& funcName)
            : GMock<R(void*, P1, P2)>(funcName)
        {
            MockVirtualManager<R (C::*)(P1, P2), N>::getInstance().get() = this;
            C l_obj;
            void* l_targetAddr = resolveVirtualAddress(
                reinterpret_cast<const void*>(&targetFunc),
                reinterpret_cast<void*>(&l_obj));
            FuncType l_mockFunction = &MockVirtual::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        MockVirtual(const C& inst, R (C::*targetFunc)(P1, P2), const bsl::string& funcName)
            : GMock<R(void*, P1, P2)>(funcName)
        {
            MockVirtualManager<R (C::*)(P1, P2), N>::getInstance().get() = this;
            void* l_targetAddr = resolveVirtualAddress(
                reinterpret_cast<const void*>(&targetFunc),
                const_cast<void*>(reinterpret_cast<const void*>(&inst)));
            FuncType l_mockFunction = &MockVirtual::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        virtual ~MockVirtual()
        {
            // Restore runtime patch
            d_patch.restore();
            MockVirtualManager<R (C::*)(P1, P2), N>::getInstance().clear();
        }

        R mockFunction(P1 p1, P2 p2)
        {
            MockVirtual<R (C::*)(P1, P2), N>* obj = MockVirtualManager<R (C::*)(P1, P2), N>::getInstance().get();
            return obj->bonobomockInternalForwardFunc(this, p1, p2);
        }

        virtual void restore()
        {
            // Restore runtime patch
            d_patch.restore();
        }

    private:
        Patch d_patch;
    };

    template <typename R, typename C, typename P1, typename P2, typename P3, int N>
    class MockVirtual<R (C::*)(P1, P2, P3), N> : public GMock<R(void*, P1, P2, P3)> {
        typedef R (MockVirtual::*FuncType)(P1, P2, P3);

    public:
        MockVirtual(R (C::*targetFunc)(P1, P2, P3), const bsl::string& funcName)
            : GMock<R(void*, P1, P2, P3)>(funcName)
        {
            MockVirtualManager<R (C::*)(P1, P2, P3), N>::getInstance().get() = this;
            C l_obj;
            void* l_targetAddr = resolveVirtualAddress(
                reinterpret_cast<const void*>(&targetFunc),
                reinterpret_cast<void*>(&l_obj));
            FuncType l_mockFunction = &MockVirtual::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        MockVirtual(const C& inst, R (C::*targetFunc)(P1, P2, P3), const bsl::string& funcName)
            : GMock<R(void*, P1, P2, P3)>(funcName)
        {
            MockVirtualManager<R (C::*)(P1, P2, P3), N>::getInstance().get() = this;
            void* l_targetAddr = resolveVirtualAddress(
                reinterpret_cast<const void*>(&targetFunc),
                const_cast<void*>(reinterpret_cast<const void*>(&inst)));
            FuncType l_mockFunction = &MockVirtual::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        virtual ~MockVirtual()
        {
            // Restore runtime patch
            d_patch.restore();
            MockVirtualManager<R (C::*)(P1, P2, P3), N>::getInstance().clear();
        }

        R mockFunction(P1 p1, P2 p2, P3 p3)
        {
            MockVirtual<R (C::*)(P1, P2, P3), N>* obj = MockVirtualManager<R (C::*)(P1, P2, P3), N>::getInstance().get();
            return obj->bonobomockInternalForwardFunc(this, p1, p2, p3);
        }

        virtual void restore()
        {
            // Restore runtime patch
            d_patch.restore();
        }

    private:
        Patch d_patch;
    };

    template <typename R, typename C, typename P1, typename P2, typename P3, typename P4, int N>
    class MockVirtual<R (C::*)(P1, P2, P3, P4), N> : public GMock<R(void*, P1, P2, P3, P4)> {
        typedef R (MockVirtual::*FuncType)(P1, P2, P3, P4);

    public:
        MockVirtual(R (C::*targetFunc)(P1, P2, P3, P4), const bsl::string& funcName)
            : GMock<R(void*, P1, P2, P3, P4)>(funcName)
        {
            MockVirtualManager<R (C::*)(P1, P2, P3, P4), N>::getInstance().get() = this;
            C l_obj;
            void* l_targetAddr = resolveVirtualAddress(
                reinterpret_cast<const void*>(&targetFunc),
                reinterpret_cast<void*>(&l_obj));
            FuncType l_mockFunction = &MockVirtual::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        MockVirtual(const C& inst, R (C::*targetFunc)(P1, P2, P3, P4), const bsl::string& funcName)
            : GMock<R(void*, P1, P2, P3, P4)>(funcName)
        {
            MockVirtualManager<R (C::*)(P1, P2, P3, P4), N>::getInstance().get() = this;
            void* l_targetAddr = resolveVirtualAddress(
                reinterpret_cast<const void*>(&targetFunc),
                const_cast<void*>(reinterpret_cast<const void*>(&inst)));
            FuncType l_mockFunction = &MockVirtual::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        virtual ~MockVirtual()
        {
            // Restore runtime patch
            d_patch.restore();
            MockVirtualManager<R (C::*)(P1, P2, P3, P4), N>::getInstance().clear();
        }

        R mockFunction(P1 p1, P2 p2, P3 p3, P4 p4)
        {
            MockVirtual<R (C::*)(P1, P2, P3, P4), N>* obj = MockVirtualManager<R (C::*)(P1, P2, P3, P4), N>::getInstance().get();
            return obj->bonobomockInternalForwardFunc(this, p1, p2, p3, p4);
        }

        virtual void restore()
        {
            // Restore runtime patch
            d_patch.restore();
        }

    private:
        Patch d_patch;
    };

    template <typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, int N>
    class MockVirtual<R (C::*)(P1, P2, P3, P4, P5), N> : public GMock<R(void*, P1, P2, P3, P4, P5)> {
        typedef R (MockVirtual::*FuncType)(P1, P2, P3, P4, P5);

    public:
        MockVirtual(R (C::*targetFunc)(P1, P2, P3, P4, P5), const bsl::string& funcName)
            : GMock<R(void*, P1, P2, P3, P4, P5)>(funcName)
        {
            MockVirtualManager<R (C::*)(P1, P2, P3, P4, P5), N>::getInstance().get() = this;
            C l_obj;
            void* l_targetAddr = resolveVirtualAddress(
                reinterpret_cast<const void*>(&targetFunc),
                reinterpret_cast<void*>(&l_obj));
            FuncType l_mockFunction = &MockVirtual::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        MockVirtual(const C& inst, R (C::*targetFunc)(P1, P2, P3, P4, P5), const bsl::string& funcName)
            : GMock<R(void*, P1, P2, P3, P4, P5)>(funcName)
        {
            MockVirtualManager<R (C::*)(P1, P2, P3, P4, P5), N>::getInstance().get() = this;
            void* l_targetAddr = resolveVirtualAddress(
                reinterpret_cast<const void*>(&targetFunc),
                const_cast<void*>(reinterpret_cast<const void*>(&inst)));
            FuncType l_mockFunction = &MockVirtual::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        virtual ~MockVirtual()
        {
            // Restore runtime patch
            d_patch.restore();
            MockVirtualManager<R (C::*)(P1, P2, P3, P4, P5), N>::getInstance().clear();
        }

        R mockFunction(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5)
        {
            MockVirtual<R (C::*)(P1, P2, P3, P4, P5), N>* obj = MockVirtualManager<R (C::*)(P1, P2, P3, P4, P5), N>::getInstance().get();
            return obj->bonobomockInternalForwardFunc(this, p1, p2, p3, p4, p5);
        }

        virtual void restore()
        {
            // Restore runtime patch
            d_patch.restore();
        }

    private:
        Patch d_patch;
    };

    template <typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, int N>
    class MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6), N> : public GMock<R(void*, P1, P2, P3, P4, P5, P6)> {
        typedef R (MockVirtual::*FuncType)(P1, P2, P3, P4, P5, P6);

    public:
        MockVirtual(R (C::*targetFunc)(P1, P2, P3, P4, P5, P6), const bsl::string& funcName)
            : GMock<R(void*, P1, P2, P3, P4, P5, P6)>(funcName)
        {
            MockVirtualManager<R (C::*)(P1, P2, P3, P4, P5, P6), N>::getInstance().get() = this;
            C l_obj;
            void* l_targetAddr = resolveVirtualAddress(
                reinterpret_cast<const void*>(&targetFunc),
                reinterpret_cast<void*>(&l_obj));
            FuncType l_mockFunction = &MockVirtual::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        MockVirtual(const C& inst, R (C::*targetFunc)(P1, P2, P3, P4, P5, P6), const bsl::string& funcName)
            : GMock<R(void*, P1, P2, P3, P4, P5, P6)>(funcName)
        {
            MockVirtualManager<R (C::*)(P1, P2, P3, P4, P5, P6), N>::getInstance().get() = this;
            void* l_targetAddr = resolveVirtualAddress(
                reinterpret_cast<const void*>(&targetFunc),
                const_cast<void*>(reinterpret_cast<const void*>(&inst)));
            FuncType l_mockFunction = &MockVirtual::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        virtual ~MockVirtual()
        {
            // Restore runtime patch
            d_patch.restore();
            MockVirtualManager<R (C::*)(P1, P2, P3, P4, P5, P6), N>::getInstance().clear();
        }

        R mockFunction(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6)
        {
            MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6), N>* obj = MockVirtualManager<R (C::*)(P1, P2, P3, P4, P5, P6), N>::getInstance().get();
            return obj->bonobomockInternalForwardFunc(this, p1, p2, p3, p4, p5, p6);
        }

        virtual void restore()
        {
            // Restore runtime patch
            d_patch.restore();
        }

    private:
        Patch d_patch;
    };

    template <typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
        typename P7, int N>
    class MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7), N> : public GMock<R(void*, P1, P2, P3, P4, P5, P6, P7)> {
        typedef R (MockVirtual::*FuncType)(P1, P2, P3, P4, P5, P6, P7);

    public:
        MockVirtual(R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7), const bsl::string& funcName)
            : GMock<R(void*, P1, P2, P3, P4, P5, P6, P7)>(funcName)
        {
            MockVirtualManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7), N>::getInstance().get() = this;
            C l_obj;
            void* l_targetAddr = resolveVirtualAddress(
                reinterpret_cast<const void*>(&targetFunc),
                reinterpret_cast<void*>(&l_obj));
            FuncType l_mockFunction = &MockVirtual::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        MockVirtual(const C& inst, R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7), const bsl::string& funcName)
            : GMock<R(void*, P1, P2, P3, P4, P5, P6, P7)>(funcName)
        {
            MockVirtualManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7), N>::getInstance().get() = this;
            void* l_targetAddr = resolveVirtualAddress(
                reinterpret_cast<const void*>(&targetFunc),
                const_cast<void*>(reinterpret_cast<const void*>(&inst)));
            FuncType l_mockFunction = &MockVirtual::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        virtual ~MockVirtual()
        {
            // Restore runtime patch
            d_patch.restore();
            MockVirtualManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7), N>::getInstance().clear();
        }

        R mockFunction(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6, P7 p7)
        {
            MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7), N>* obj = MockVirtualManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7), N>::getInstance().get();
            return obj->bonobomockInternalForwardFunc(this, p1, p2, p3, p4, p5, p6, p7);
        }

        virtual void restore()
        {
            // Restore runtime patch
            d_patch.restore();
        }

    private:
        Patch d_patch;
    };

    template <typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
        typename P7, typename P8, int N>
    class MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8), N> : public GMock<R(void*, P1, P2, P3, P4, P5, P6, P7, P8)> {
        typedef R (MockVirtual::*FuncType)(P1, P2, P3, P4, P5, P6, P7, P8);

    public:
        MockVirtual(R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8), const bsl::string& funcName)
            : GMock<R(void*, P1, P2, P3, P4, P5, P6, P7, P8)>(funcName)
        {
            MockVirtualManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8), N>::getInstance().get() = this;
            C l_obj;
            void* l_targetAddr = resolveVirtualAddress(
                reinterpret_cast<const void*>(&targetFunc),
                reinterpret_cast<void*>(&l_obj));
            FuncType l_mockFunction = &MockVirtual::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        MockVirtual(const C& inst, R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8), const bsl::string& funcName)
            : GMock<R(void*, P1, P2, P3, P4, P5, P6, P7, P8)>(funcName)
        {
            MockVirtualManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8), N>::getInstance().get() = this;
            void* l_targetAddr = resolveVirtualAddress(
                reinterpret_cast<const void*>(&targetFunc),
                const_cast<void*>(reinterpret_cast<const void*>(&inst)));
            FuncType l_mockFunction = &MockVirtual::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        virtual ~MockVirtual()
        {
            // Restore runtime patch
            d_patch.restore();
            MockVirtualManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8), N>::getInstance().clear();
        }

        R mockFunction(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6, P7 p7, P8 p8)
        {
            MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8), N>* obj = MockVirtualManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8), N>::getInstance().get();
            return obj->bonobomockInternalForwardFunc(this, p1, p2, p3, p4, p5, p6, p7, p8);
        }

        virtual void restore()
        {
            // Restore runtime patch
            d_patch.restore();
        }

    private:
        Patch d_patch;
    };

    template <typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
        typename P7, typename P8, typename P9, int N>
    class MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9), N> : public GMock<R(void*, P1, P2, P3, P4, P5, P6, P7, P8, P9)> {
        typedef R (MockVirtual::*FuncType)(P1, P2, P3, P4, P5, P6, P7, P8, P9);

    public:
        MockVirtual(R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9), const bsl::string& funcName)
            : GMock<R(void*, P1, P2, P3, P4, P5, P6, P7, P8, P9)>(funcName)
        {
            MockVirtualManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9), N>::getInstance().get() = this;
            C l_obj;
            void* l_targetAddr = resolveVirtualAddress(
                reinterpret_cast<const void*>(&targetFunc),
                reinterpret_cast<void*>(&l_obj));
            FuncType l_mockFunction = &MockVirtual::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        MockVirtual(const C& inst, R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9), const bsl::string& funcName)
            : GMock<R(void*, P1, P2, P3, P4, P5, P6, P7, P8, P9)>(funcName)
        {
            MockVirtualManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9), N>::getInstance().get() = this;
            void* l_targetAddr = resolveVirtualAddress(
                reinterpret_cast<const void*>(&targetFunc),
                const_cast<void*>(reinterpret_cast<const void*>(&inst)));
            FuncType l_mockFunction = &MockVirtual::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        virtual ~MockVirtual()
        {
            // Restore runtime patch
            d_patch.restore();
            MockVirtualManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9), N>::getInstance().clear();
        }

        R mockFunction(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6, P7 p7, P8 p8, P9 p9)
        {
            MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9), N>* obj = MockVirtualManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9), N>::getInstance().get();
            return obj->bonobomockInternalForwardFunc(this, p1, p2, p3, p4, p5, p6, p7, p8, p9);
        }

        virtual void restore()
        {
            // Restore runtime patch
            d_patch.restore();
        }

    private:
        Patch d_patch;
    };

    template <typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
        typename P7, typename P8, typename P9, typename P10, int N>
    class MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10), N> : public GMock<R(void*, P1, P2, P3, P4, P5, P6, P7, P8, P9, P10)> {
        typedef R (MockVirtual::*FuncType)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10);

    public:
        MockVirtual(R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10), const bsl::string& funcName)
            : GMock<R(void*, P1, P2, P3, P4, P5, P6, P7, P8, P9, P10)>(funcName)
        {
            MockVirtualManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10), N>::getInstance().get() = this;
            C l_obj;
            void* l_targetAddr = resolveVirtualAddress(
                reinterpret_cast<const void*>(&targetFunc),
                reinterpret_cast<void*>(&l_obj));
            FuncType l_mockFunction = &MockVirtual::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        MockVirtual(const C& inst, R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10), const bsl::string& funcName)
            : GMock<R(void*, P1, P2, P3, P4, P5, P6, P7, P8, P9, P10)>(funcName)
        {
            MockVirtualManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10), N>::getInstance().get() = this;
            void* l_targetAddr = resolveVirtualAddress(
                reinterpret_cast<const void*>(&targetFunc),
                const_cast<void*>(reinterpret_cast<const void*>(&inst)));
            FuncType l_mockFunction = &MockVirtual::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        virtual ~MockVirtual()
        {
            // Restore runtime patch
            d_patch.restore();
            MockVirtualManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10), N>::getInstance().clear();
        }

        R mockFunction(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6, P7 p7, P8 p8, P9 p9, P10 p10)
        {
            MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10), N>* obj = MockVirtualManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10), N>::getInstance().get();
            return obj->bonobomockInternalForwardFunc(this, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10);
        }

        virtual void restore()
        {
            // Restore runtime patch
            d_patch.restore();
        }

    private:
        Patch d_patch;
    };

    template <typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
        typename P7, typename P8, typename P9, typename P10, typename P11, int N>
    class MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11), N> : public GMock<R(void*, P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11)> {
        typedef R (MockVirtual::*FuncType)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11);

    public:
        MockVirtual(R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11), const bsl::string& funcName)
            : GMock<R(void*, P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11)>(funcName)
        {
            MockVirtualManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11), N>::getInstance().get() = this;
            C l_obj;
            void* l_targetAddr = resolveVirtualAddress(
                reinterpret_cast<const void*>(&targetFunc),
                reinterpret_cast<void*>(&l_obj));
            FuncType l_mockFunction = &MockVirtual::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        MockVirtual(const C& inst, R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11), const bsl::string& funcName)
            : GMock<R(void*, P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11)>(funcName)
        {
            MockVirtualManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11), N>::getInstance().get() = this;
            void* l_targetAddr = resolveVirtualAddress(
                reinterpret_cast<const void*>(&targetFunc),
                const_cast<void*>(reinterpret_cast<const void*>(&inst)));
            FuncType l_mockFunction = &MockVirtual::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        virtual ~MockVirtual()
        {
            // Restore runtime patch
            d_patch.restore();
            MockVirtualManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11), N>::getInstance().clear();
        }

        R mockFunction(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6, P7 p7, P8 p8, P9 p9, P10 p10, P11 p11)
        {
            MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11), N>* obj = MockVirtualManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11), N>::getInstance().get();
            return obj->bonobomockInternalForwardFunc(this, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11);
        }

        virtual void restore()
        {
            // Restore runtime patch
            d_patch.restore();
        }

    private:
        Patch d_patch;
    };

    template <typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
        typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, int N>
    class MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12), N> : public GMock<R(void*, P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12)> {
        typedef R (MockVirtual::*FuncType)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12);

    public:
        MockVirtual(R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12), const bsl::string& funcName)
            : GMock<R(void*, P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12)>(funcName)
        {
            MockVirtualManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12), N>::getInstance().get() = this;
            C l_obj;
            void* l_targetAddr = resolveVirtualAddress(
                reinterpret_cast<const void*>(&targetFunc),
                reinterpret_cast<void*>(&l_obj));
            FuncType l_mockFunction = &MockVirtual::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        MockVirtual(const C& inst, R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12), const bsl::string& funcName)
            : GMock<R(void*, P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12)>(funcName)
        {
            MockVirtualManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12), N>::getInstance().get() = this;
            void* l_targetAddr = resolveVirtualAddress(
                reinterpret_cast<const void*>(&targetFunc),
                const_cast<void*>(reinterpret_cast<const void*>(&inst)));
            FuncType l_mockFunction = &MockVirtual::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        virtual ~MockVirtual()
        {
            // Restore runtime patch
            d_patch.restore();
            MockVirtualManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12), N>::getInstance().clear();
        }

        R mockFunction(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6, P7 p7, P8 p8, P9 p9, P10 p10, P11 p11, P12 p12)
        {
            MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12), N>* obj = MockVirtualManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12), N>::getInstance().get();
            return obj->bonobomockInternalForwardFunc(this, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12);
        }

        virtual void restore()
        {
            // Restore runtime patch
            d_patch.restore();
        }

    private:
        Patch d_patch;
    };

    template <typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
        typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13, int N>
    class MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13), N> : public GMock<R(void*, P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13)> {
        typedef R (MockVirtual::*FuncType)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13);

    public:
        MockVirtual(R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13), const bsl::string& funcName)
            : GMock<R(void*, P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13)>(funcName)
        {
            MockVirtualManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13), N>::getInstance().get() = this;
            C l_obj;
            void* l_targetAddr = resolveVirtualAddress(
                reinterpret_cast<const void*>(&targetFunc),
                reinterpret_cast<void*>(&l_obj));
            FuncType l_mockFunction = &MockVirtual::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        MockVirtual(const C& inst, R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13), const bsl::string& funcName)
            : GMock<R(void*, P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13)>(funcName)
        {
            MockVirtualManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13), N>::getInstance().get() = this;
            void* l_targetAddr = resolveVirtualAddress(
                reinterpret_cast<const void*>(&targetFunc),
                const_cast<void*>(reinterpret_cast<const void*>(&inst)));
            FuncType l_mockFunction = &MockVirtual::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        virtual ~MockVirtual()
        {
            // Restore runtime patch
            d_patch.restore();
            MockVirtualManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13), N>::getInstance().clear();
        }

        R mockFunction(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6, P7 p7, P8 p8, P9 p9, P10 p10, P11 p11, P12 p12, P13 p13)
        {
            MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13), N>* obj = MockVirtualManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13), N>::getInstance().get();
            return obj->bonobomockInternalForwardFunc(this, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13);
        }

        virtual void restore()
        {
            // Restore runtime patch
            d_patch.restore();
        }

    private:
        Patch d_patch;
    };

    template <typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
        typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13, typename P14, int N>
    class MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14), N> : public GMock<R(void*, P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14)> {
        typedef R (MockVirtual::*FuncType)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14);

    public:
        MockVirtual(R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14), const bsl::string& funcName)
            : GMock<R(void*, P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14)>(funcName)
        {
            MockVirtualManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14), N>::getInstance().get() = this;
            C l_obj;
            void* l_targetAddr = resolveVirtualAddress(
                reinterpret_cast<const void*>(&targetFunc),
                reinterpret_cast<void*>(&l_obj));
            FuncType l_mockFunction = &MockVirtual::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        MockVirtual(const C& inst, R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14), const bsl::string& funcName)
            : GMock<R(void*, P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14)>(funcName)
        {
            MockVirtualManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14), N>::getInstance().get() = this;
            void* l_targetAddr = resolveVirtualAddress(
                reinterpret_cast<const void*>(&targetFunc),
                const_cast<void*>(reinterpret_cast<const void*>(&inst)));
            FuncType l_mockFunction = &MockVirtual::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        virtual ~MockVirtual()
        {
            // Restore runtime patch
            d_patch.restore();
            MockVirtualManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14), N>::getInstance().clear();
        }

        R mockFunction(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6, P7 p7, P8 p8, P9 p9, P10 p10, P11 p11, P12 p12, P13 p13, P14 p14)
        {
            MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14), N>* obj = MockVirtualManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14), N>::getInstance().get();
            return obj->bonobomockInternalForwardFunc(this, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14);
        }

        virtual void restore()
        {
            // Restore runtime patch
            d_patch.restore();
        }

    private:
        Patch d_patch;
    };

    template <typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
        typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13, typename P14, typename P15, int N>
    class MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15), N> : public GMock<R(void*, P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15)> {
        typedef R (MockVirtual::*FuncType)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15);

    public:
        MockVirtual(R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15), const bsl::string& funcName)
            : GMock<R(void*, P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15)>(funcName)
        {
            MockVirtualManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15), N>::getInstance().get() = this;
            C l_obj;
            void* l_targetAddr = resolveVirtualAddress(
                reinterpret_cast<const void*>(&targetFunc),
                reinterpret_cast<void*>(&l_obj));
            FuncType l_mockFunction = &MockVirtual::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        MockVirtual(const C& inst, R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15), const bsl::string& funcName)
            : GMock<R(void*, P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15)>(funcName)
        {
            MockVirtualManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15), N>::getInstance().get() = this;
            void* l_targetAddr = resolveVirtualAddress(
                reinterpret_cast<const void*>(&targetFunc),
                const_cast<void*>(reinterpret_cast<const void*>(&inst)));
            FuncType l_mockFunction = &MockVirtual::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        virtual ~MockVirtual()
        {
            // Restore runtime patch
            d_patch.restore();
            MockVirtualManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15), N>::getInstance().clear();
        }

        R mockFunction(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6, P7 p7, P8 p8, P9 p9, P10 p10, P11 p11, P12 p12, P13 p13, P14 p14, P15 p15)
        {
            MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15), N>* obj = MockVirtualManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15), N>::getInstance().get();
            return obj->bonobomockInternalForwardFunc(this, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15);
        }

        virtual void restore()
        {
            // Restore runtime patch
            d_patch.restore();
        }

    private:
        Patch d_patch;
    };

    template <typename R, typename C, int N>
    class MockVirtual<R (C::*)() const, N> : public GMock<R(const void*)> {
        typedef R (MockVirtual::*FuncType)();

    public:
        MockVirtual(R (C::*targetFunc)() const, const bsl::string& funcName)
            : GMock<R(const void*)>(funcName)
        {
            MockVirtualManager<R (C::*)() const, N>::getInstance().get() = this;
            C l_obj;
            void* l_targetAddr = resolveVirtualAddress(
                reinterpret_cast<const void*>(&targetFunc),
                reinterpret_cast<void*>(&l_obj));
            FuncType l_mockFunction = &MockVirtual::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        MockVirtual(const C& inst, R (C::*targetFunc)() const, const bsl::string& funcName)
            : GMock<R(const void*)>(funcName)
        {
            MockVirtualManager<R (C::*)() const, N>::getInstance().get() = this;
            void* l_targetAddr = resolveVirtualAddress(
                reinterpret_cast<const void*>(&targetFunc),
                const_cast<void*>(reinterpret_cast<const void*>(&inst)));
            FuncType l_mockFunction = &MockVirtual::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        virtual ~MockVirtual()
        {
            // Restore runtime patch
            d_patch.restore();
            MockVirtualManager<R (C::*)(), N>::getInstance().clear();
        }

        R mockFunction()
        {
            MockVirtual<R (C::*)() const, N>* obj = MockVirtualManager<R (C::*)() const, N>::getInstance().get();
            return obj->bonobomockInternalForwardFunc(this);
        }

        virtual void restore()
        {
            // Restore runtime patch
            d_patch.restore();
        }

    private:
        Patch d_patch;
    };

    template <typename R, typename C, typename P1, int N>
    class MockVirtual<R (C::*)(P1) const, N> : public GMock<R(const void*, P1)> {
        typedef R (MockVirtual::*FuncType)(P1);

    public:
        MockVirtual(R (C::*targetFunc)(P1) const, const bsl::string& funcName)
            : GMock<R(const void*, P1)>(funcName)
        {
            MockVirtualManager<R (C::*)(P1) const, N>::getInstance().get() = this;
            C l_obj;
            void* l_targetAddr = resolveVirtualAddress(
                reinterpret_cast<const void*>(&targetFunc),
                reinterpret_cast<void*>(&l_obj));
            FuncType l_mockFunction = &MockVirtual::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        MockVirtual(const C& inst, R (C::*targetFunc)(P1) const, const bsl::string& funcName)
            : GMock<R(const void*, P1)>(funcName)
        {
            MockVirtualManager<R (C::*)(P1) const, N>::getInstance().get() = this;
            void* l_targetAddr = resolveVirtualAddress(
                reinterpret_cast<const void*>(&targetFunc),
                const_cast<void*>(reinterpret_cast<const void*>(&inst)));
            FuncType l_mockFunction = &MockVirtual::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        virtual ~MockVirtual()
        {
            // Restore runtime patch
            d_patch.restore();
            MockVirtualManager<R (C::*)(P1), N>::getInstance().clear();
        }

        R mockFunction(P1 p1)
        {
            MockVirtual<R (C::*)(P1) const, N>* obj = MockVirtualManager<R (C::*)(P1) const, N>::getInstance().get();
            return obj->bonobomockInternalForwardFunc(this, p1);
        }

        virtual void restore()
        {
            // Restore runtime patch
            d_patch.restore();
        }

    private:
        Patch d_patch;
    };

    template <typename R, typename C, typename P1, typename P2, int N>
    class MockVirtual<R (C::*)(P1, P2) const, N> : public GMock<R(const void*, P1, P2)> {
        typedef R (MockVirtual::*FuncType)(P1, P2);

    public:
        MockVirtual(R (C::*targetFunc)(P1, P2) const, const bsl::string& funcName)
            : GMock<R(const void*, P1, P2)>(funcName)
        {
            MockVirtualManager<R (C::*)(P1, P2) const, N>::getInstance().get() = this;
            C l_obj;
            void* l_targetAddr = resolveVirtualAddress(
                reinterpret_cast<const void*>(&targetFunc),
                reinterpret_cast<void*>(&l_obj));
            FuncType l_mockFunction = &MockVirtual::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        MockVirtual(const C& inst, R (C::*targetFunc)(P1, P2) const, const bsl::string& funcName)
            : GMock<R(const void*, P1, P2)>(funcName)
        {
            MockVirtualManager<R (C::*)(P1, P2) const, N>::getInstance().get() = this;
            void* l_targetAddr = resolveVirtualAddress(
                reinterpret_cast<const void*>(&targetFunc),
                const_cast<void*>(reinterpret_cast<const void*>(&inst)));
            FuncType l_mockFunction = &MockVirtual::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        virtual ~MockVirtual()
        {
            // Restore runtime patch
            d_patch.restore();
            MockVirtualManager<R (C::*)(P1, P2), N>::getInstance().clear();
        }

        R mockFunction(P1 p1, P2 p2)
        {
            MockVirtual<R (C::*)(P1, P2) const, N>* obj = MockVirtualManager<R (C::*)(P1, P2) const, N>::getInstance().get();
            return obj->bonobomockInternalForwardFunc(this, p1, p2);
        }

        virtual void restore()
        {
            // Restore runtime patch
            d_patch.restore();
        }

    private:
        Patch d_patch;
    };

    template <typename R, typename C, typename P1, typename P2, typename P3, int N>
    class MockVirtual<R (C::*)(P1, P2, P3) const, N> : public GMock<R(const void*, P1, P2, P3)> {
        typedef R (MockVirtual::*FuncType)(P1, P2, P3);

    public:
        MockVirtual(R (C::*targetFunc)(P1, P2, P3) const, const bsl::string& funcName)
            : GMock<R(const void*, P1, P2, P3)>(funcName)
        {
            MockVirtualManager<R (C::*)(P1, P2, P3) const, N>::getInstance().get() = this;
            C l_obj;
            void* l_targetAddr = resolveVirtualAddress(
                reinterpret_cast<const void*>(&targetFunc),
                reinterpret_cast<void*>(&l_obj));
            FuncType l_mockFunction = &MockVirtual::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        MockVirtual(const C& inst, R (C::*targetFunc)(P1, P2, P3) const, const bsl::string& funcName)
            : GMock<R(const void*, P1, P2, P3)>(funcName)
        {
            MockVirtualManager<R (C::*)(P1, P2, P3) const, N>::getInstance().get() = this;
            void* l_targetAddr = resolveVirtualAddress(
                reinterpret_cast<const void*>(&targetFunc),
                const_cast<void*>(reinterpret_cast<const void*>(&inst)));
            FuncType l_mockFunction = &MockVirtual::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        virtual ~MockVirtual()
        {
            // Restore runtime patch
            d_patch.restore();
            MockVirtualManager<R (C::*)(P1, P2, P3), N>::getInstance().clear();
        }

        R mockFunction(P1 p1, P2 p2, P3 p3)
        {
            MockVirtual<R (C::*)(P1, P2, P3) const, N>* obj = MockVirtualManager<R (C::*)(P1, P2, P3) const, N>::getInstance().get();
            return obj->bonobomockInternalForwardFunc(this, p1, p2, p3);
        }

        virtual void restore()
        {
            // Restore runtime patch
            d_patch.restore();
        }

    private:
        Patch d_patch;
    };

    template <typename R, typename C, typename P1, typename P2, typename P3, typename P4, int N>
    class MockVirtual<R (C::*)(P1, P2, P3, P4) const, N> : public GMock<R(const void*, P1, P2, P3, P4)> {
        typedef R (MockVirtual::*FuncType)(P1, P2, P3, P4);

    public:
        MockVirtual(R (C::*targetFunc)(P1, P2, P3, P4) const, const bsl::string& funcName)
            : GMock<R(const void*, P1, P2, P3, P4)>(funcName)
        {
            MockVirtualManager<R (C::*)(P1, P2, P3, P4) const, N>::getInstance().get() = this;
            C l_obj;
            void* l_targetAddr = resolveVirtualAddress(
                reinterpret_cast<const void*>(&targetFunc),
                reinterpret_cast<void*>(&l_obj));
            FuncType l_mockFunction = &MockVirtual::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        MockVirtual(const C& inst, R (C::*targetFunc)(P1, P2, P3, P4) const, const bsl::string& funcName)
            : GMock<R(const void*, P1, P2, P3, P4)>(funcName)
        {
            MockVirtualManager<R (C::*)(P1, P2, P3, P4) const, N>::getInstance().get() = this;
            void* l_targetAddr = resolveVirtualAddress(
                reinterpret_cast<const void*>(&targetFunc),
                const_cast<void*>(reinterpret_cast<const void*>(&inst)));
            FuncType l_mockFunction = &MockVirtual::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        virtual ~MockVirtual()
        {
            // Restore runtime patch
            d_patch.restore();
            MockVirtualManager<R (C::*)(P1, P2, P3, P4), N>::getInstance().clear();
        }

        R mockFunction(P1 p1, P2 p2, P3 p3, P4 p4)
        {
            MockVirtual<R (C::*)(P1, P2, P3, P4) const, N>* obj = MockVirtualManager<R (C::*)(P1, P2, P3, P4) const, N>::getInstance().get();
            return obj->bonobomockInternalForwardFunc(this, p1, p2, p3, p4);
        }

        virtual void restore()
        {
            // Restore runtime patch
            d_patch.restore();
        }

    private:
        Patch d_patch;
    };

    template <typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, int N>
    class MockVirtual<R (C::*)(P1, P2, P3, P4, P5) const, N> : public GMock<R(const void*, P1, P2, P3, P4, P5)> {
        typedef R (MockVirtual::*FuncType)(P1, P2, P3, P4, P5);

    public:
        MockVirtual(R (C::*targetFunc)(P1, P2, P3, P4, P5) const, const bsl::string& funcName)
            : GMock<R(const void*, P1, P2, P3, P4, P5)>(funcName)
        {
            MockVirtualManager<R (C::*)(P1, P2, P3, P4, P5) const, N>::getInstance().get() = this;
            C l_obj;
            void* l_targetAddr = resolveVirtualAddress(
                reinterpret_cast<const void*>(&targetFunc),
                reinterpret_cast<void*>(&l_obj));
            FuncType l_mockFunction = &MockVirtual::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        MockVirtual(const C& inst, R (C::*targetFunc)(P1, P2, P3, P4, P5) const, const bsl::string& funcName)
            : GMock<R(const void*, P1, P2, P3, P4, P5)>(funcName)
        {
            MockVirtualManager<R (C::*)(P1, P2, P3, P4, P5) const, N>::getInstance().get() = this;
            void* l_targetAddr = resolveVirtualAddress(
                reinterpret_cast<const void*>(&targetFunc),
                const_cast<void*>(reinterpret_cast<const void*>(&inst)));
            FuncType l_mockFunction = &MockVirtual::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        virtual ~MockVirtual()
        {
            // Restore runtime patch
            d_patch.restore();
            MockVirtualManager<R (C::*)(P1, P2, P3, P4, P5), N>::getInstance().clear();
        }

        R mockFunction(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5)
        {
            MockVirtual<R (C::*)(P1, P2, P3, P4, P5) const, N>* obj = MockVirtualManager<R (C::*)(P1, P2, P3, P4, P5) const, N>::getInstance().get();
            return obj->bonobomockInternalForwardFunc(this, p1, p2, p3, p4, p5);
        }

        virtual void restore()
        {
            // Restore runtime patch
            d_patch.restore();
        }

    private:
        Patch d_patch;
    };

    template <typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, int N>
    class MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6) const, N> : public GMock<R(const void*, P1, P2, P3, P4, P5, P6)> {
        typedef R (MockVirtual::*FuncType)(P1, P2, P3, P4, P5, P6);

    public:
        MockVirtual(R (C::*targetFunc)(P1, P2, P3, P4, P5, P6) const, const bsl::string& funcName)
            : GMock<R(const void*, P1, P2, P3, P4, P5, P6)>(funcName)
        {
            MockVirtualManager<R (C::*)(P1, P2, P3, P4, P5, P6) const, N>::getInstance().get() = this;
            C l_obj;
            void* l_targetAddr = resolveVirtualAddress(
                reinterpret_cast<const void*>(&targetFunc),
                reinterpret_cast<void*>(&l_obj));
            FuncType l_mockFunction = &MockVirtual::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        MockVirtual(const C& inst, R (C::*targetFunc)(P1, P2, P3, P4, P5, P6) const, const bsl::string& funcName)
            : GMock<R(const void*, P1, P2, P3, P4, P5, P6)>(funcName)
        {
            MockVirtualManager<R (C::*)(P1, P2, P3, P4, P5, P6) const, N>::getInstance().get() = this;
            void* l_targetAddr = resolveVirtualAddress(
                reinterpret_cast<const void*>(&targetFunc),
                const_cast<void*>(reinterpret_cast<const void*>(&inst)));
            FuncType l_mockFunction = &MockVirtual::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        virtual ~MockVirtual()
        {
            // Restore runtime patch
            d_patch.restore();
            MockVirtualManager<R (C::*)(P1, P2, P3, P4, P5, P6), N>::getInstance().clear();
        }

        R mockFunction(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6)
        {
            MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6) const, N>* obj = MockVirtualManager<R (C::*)(P1, P2, P3, P4, P5, P6) const, N>::getInstance().get();
            return obj->bonobomockInternalForwardFunc(this, p1, p2, p3, p4, p5, p6);
        }

        virtual void restore()
        {
            // Restore runtime patch
            d_patch.restore();
        }

    private:
        Patch d_patch;
    };

    template <typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
        typename P7, int N>
    class MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7) const, N> : public GMock<R(const void*, P1, P2, P3, P4, P5, P6, P7)> {
        typedef R (MockVirtual::*FuncType)(P1, P2, P3, P4, P5, P6, P7);

    public:
        MockVirtual(R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7) const, const bsl::string& funcName)
            : GMock<R(const void*, P1, P2, P3, P4, P5, P6, P7)>(funcName)
        {
            MockVirtualManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7) const, N>::getInstance().get() = this;
            C l_obj;
            void* l_targetAddr = resolveVirtualAddress(
                reinterpret_cast<const void*>(&targetFunc),
                reinterpret_cast<void*>(&l_obj));
            FuncType l_mockFunction = &MockVirtual::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        MockVirtual(const C& inst, R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7) const, const bsl::string& funcName)
            : GMock<R(const void*, P1, P2, P3, P4, P5, P6, P7)>(funcName)
        {
            MockVirtualManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7) const, N>::getInstance().get() = this;
            void* l_targetAddr = resolveVirtualAddress(
                reinterpret_cast<const void*>(&targetFunc),
                const_cast<void*>(reinterpret_cast<const void*>(&inst)));
            FuncType l_mockFunction = &MockVirtual::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        virtual ~MockVirtual()
        {
            // Restore runtime patch
            d_patch.restore();
            MockVirtualManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7), N>::getInstance().clear();
        }

        R mockFunction(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6, P7 p7)
        {
            MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7) const, N>* obj = MockVirtualManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7) const, N>::getInstance().get();
            return obj->bonobomockInternalForwardFunc(this, p1, p2, p3, p4, p5, p6, p7);
        }

        virtual void restore()
        {
            // Restore runtime patch
            d_patch.restore();
        }

    private:
        Patch d_patch;
    };

    template <typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
        typename P7, typename P8, int N>
    class MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8) const, N> : public GMock<R(const void*, P1, P2, P3, P4, P5, P6, P7, P8)> {
        typedef R (MockVirtual::*FuncType)(P1, P2, P3, P4, P5, P6, P7, P8);

    public:
        MockVirtual(R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8) const, const bsl::string& funcName)
            : GMock<R(const void*, P1, P2, P3, P4, P5, P6, P7, P8)>(funcName)
        {
            MockVirtualManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8) const, N>::getInstance().get() = this;
            C l_obj;
            void* l_targetAddr = resolveVirtualAddress(
                reinterpret_cast<const void*>(&targetFunc),
                reinterpret_cast<void*>(&l_obj));
            FuncType l_mockFunction = &MockVirtual::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        MockVirtual(const C& inst, R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8) const, const bsl::string& funcName)
            : GMock<R(const void*, P1, P2, P3, P4, P5, P6, P7, P8)>(funcName)
        {
            MockVirtualManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8) const, N>::getInstance().get() = this;
            void* l_targetAddr = resolveVirtualAddress(
                reinterpret_cast<const void*>(&targetFunc),
                const_cast<void*>(reinterpret_cast<const void*>(&inst)));
            FuncType l_mockFunction = &MockVirtual::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        virtual ~MockVirtual()
        {
            // Restore runtime patch
            d_patch.restore();
            MockVirtualManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8), N>::getInstance().clear();
        }

        R mockFunction(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6, P7 p7, P8 p8)
        {
            MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8) const, N>* obj = MockVirtualManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8) const, N>::getInstance().get();
            return obj->bonobomockInternalForwardFunc(this, p1, p2, p3, p4, p5, p6, p7, p8);
        }

        virtual void restore()
        {
            // Restore runtime patch
            d_patch.restore();
        }

    private:
        Patch d_patch;
    };

    template <typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
        typename P7, typename P8, typename P9, int N>
    class MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9) const, N> : public GMock<R(const void*, P1, P2, P3, P4, P5, P6, P7, P8, P9)> {
        typedef R (MockVirtual::*FuncType)(P1, P2, P3, P4, P5, P6, P7, P8, P9);

    public:
        MockVirtual(R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9) const, const bsl::string& funcName)
            : GMock<R(const void*, P1, P2, P3, P4, P5, P6, P7, P8, P9)>(funcName)
        {
            MockVirtualManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9) const, N>::getInstance().get() = this;
            C l_obj;
            void* l_targetAddr = resolveVirtualAddress(
                reinterpret_cast<const void*>(&targetFunc),
                reinterpret_cast<void*>(&l_obj));
            FuncType l_mockFunction = &MockVirtual::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        MockVirtual(const C& inst, R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9) const, const bsl::string& funcName)
            : GMock<R(const void*, P1, P2, P3, P4, P5, P6, P7, P8, P9)>(funcName)
        {
            MockVirtualManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9) const, N>::getInstance().get() = this;
            void* l_targetAddr = resolveVirtualAddress(
                reinterpret_cast<const void*>(&targetFunc),
                const_cast<void*>(reinterpret_cast<const void*>(&inst)));
            FuncType l_mockFunction = &MockVirtual::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        virtual ~MockVirtual()
        {
            // Restore runtime patch
            d_patch.restore();
            MockVirtualManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9), N>::getInstance().clear();
        }

        R mockFunction(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6, P7 p7, P8 p8, P9 p9)
        {
            MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9) const, N>* obj = MockVirtualManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9) const, N>::getInstance().get();
            return obj->bonobomockInternalForwardFunc(this, p1, p2, p3, p4, p5, p6, p7, p8, p9);
        }

        virtual void restore()
        {
            // Restore runtime patch
            d_patch.restore();
        }

    private:
        Patch d_patch;
    };

    template <typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
        typename P7, typename P8, typename P9, typename P10, int N>
    class MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10) const, N> : public GMock<R(const void*, P1, P2, P3, P4, P5, P6, P7, P8, P9, P10)> {
        typedef R (MockVirtual::*FuncType)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10);

    public:
        MockVirtual(R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10) const, const bsl::string& funcName)
            : GMock<R(const void*, P1, P2, P3, P4, P5, P6, P7, P8, P9, P10)>(funcName)
        {
            MockVirtualManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10) const, N>::getInstance().get() = this;
            C l_obj;
            void* l_targetAddr = resolveVirtualAddress(
                reinterpret_cast<const void*>(&targetFunc),
                reinterpret_cast<void*>(&l_obj));
            FuncType l_mockFunction = &MockVirtual::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        MockVirtual(const C& inst, R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10) const, const bsl::string& funcName)
            : GMock<R(const void*, P1, P2, P3, P4, P5, P6, P7, P8, P9, P10)>(funcName)
        {
            MockVirtualManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10) const, N>::getInstance().get() = this;
            void* l_targetAddr = resolveVirtualAddress(
                reinterpret_cast<const void*>(&targetFunc),
                const_cast<void*>(reinterpret_cast<const void*>(&inst)));
            FuncType l_mockFunction = &MockVirtual::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        virtual ~MockVirtual()
        {
            // Restore runtime patch
            d_patch.restore();
            MockVirtualManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10), N>::getInstance().clear();
        }

        R mockFunction(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6, P7 p7, P8 p8, P9 p9, P10 p10)
        {
            MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10) const, N>* obj = MockVirtualManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10) const, N>::getInstance().get();
            return obj->bonobomockInternalForwardFunc(this, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10);
        }

        virtual void restore()
        {
            // Restore runtime patch
            d_patch.restore();
        }

    private:
        Patch d_patch;
    };

    template <typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
        typename P7, typename P8, typename P9, typename P10, typename P11, int N>
    class MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11) const, N> : public GMock<R(const void*, P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11)> {
        typedef R (MockVirtual::*FuncType)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11);

    public:
        MockVirtual(R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11) const, const bsl::string& funcName)
            : GMock<R(const void*, P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11)>(funcName)
        {
            MockVirtualManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11) const, N>::getInstance().get() = this;
            C l_obj;
            void* l_targetAddr = resolveVirtualAddress(
                reinterpret_cast<const void*>(&targetFunc),
                reinterpret_cast<void*>(&l_obj));
            FuncType l_mockFunction = &MockVirtual::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        MockVirtual(const C& inst, R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11) const, const bsl::string& funcName)
            : GMock<R(const void*, P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11)>(funcName)
        {
            MockVirtualManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11) const, N>::getInstance().get() = this;
            void* l_targetAddr = resolveVirtualAddress(
                reinterpret_cast<const void*>(&targetFunc),
                const_cast<void*>(reinterpret_cast<const void*>(&inst)));
            FuncType l_mockFunction = &MockVirtual::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        virtual ~MockVirtual()
        {
            // Restore runtime patch
            d_patch.restore();
            MockVirtualManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11), N>::getInstance().clear();
        }

        R mockFunction(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6, P7 p7, P8 p8, P9 p9, P10 p10, P11 p11)
        {
            MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11) const, N>* obj = MockVirtualManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11) const, N>::getInstance().get();
            return obj->bonobomockInternalForwardFunc(this, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11);
        }

        virtual void restore()
        {
            // Restore runtime patch
            d_patch.restore();
        }

    private:
        Patch d_patch;
    };

    template <typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
        typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, int N>
    class MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12) const, N> : public GMock<R(const void*, P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12)> {
        typedef R (MockVirtual::*FuncType)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12);

    public:
        MockVirtual(R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12) const, const bsl::string& funcName)
            : GMock<R(const void*, P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12)>(funcName)
        {
            MockVirtualManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12) const, N>::getInstance().get() = this;
            C l_obj;
            void* l_targetAddr = resolveVirtualAddress(
                reinterpret_cast<const void*>(&targetFunc),
                reinterpret_cast<void*>(&l_obj));
            FuncType l_mockFunction = &MockVirtual::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        MockVirtual(const C& inst, R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12) const, const bsl::string& funcName)
            : GMock<R(const void*, P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12)>(funcName)
        {
            MockVirtualManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12) const, N>::getInstance().get() = this;
            void* l_targetAddr = resolveVirtualAddress(
                reinterpret_cast<const void*>(&targetFunc),
                const_cast<void*>(reinterpret_cast<const void*>(&inst)));
            FuncType l_mockFunction = &MockVirtual::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        virtual ~MockVirtual()
        {
            // Restore runtime patch
            d_patch.restore();
            MockVirtualManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12), N>::getInstance().clear();
        }

        R mockFunction(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6, P7 p7, P8 p8, P9 p9, P10 p10, P11 p11, P12 p12)
        {
            MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12) const, N>* obj = MockVirtualManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12) const, N>::getInstance().get();
            return obj->bonobomockInternalForwardFunc(this, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12);
        }

        virtual void restore()
        {
            // Restore runtime patch
            d_patch.restore();
        }

    private:
        Patch d_patch;
    };

    template <typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
        typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13, int N>
    class MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13) const, N> : public GMock<R(const void*, P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13)> {
        typedef R (MockVirtual::*FuncType)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13);

    public:
        MockVirtual(R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13) const, const bsl::string& funcName)
            : GMock<R(const void*, P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13)>(funcName)
        {
            MockVirtualManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13) const, N>::getInstance().get() = this;
            C l_obj;
            void* l_targetAddr = resolveVirtualAddress(
                reinterpret_cast<const void*>(&targetFunc),
                reinterpret_cast<void*>(&l_obj));
            FuncType l_mockFunction = &MockVirtual::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        MockVirtual(const C& inst, R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13) const, const bsl::string& funcName)
            : GMock<R(const void*, P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13)>(funcName)
        {
            MockVirtualManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13) const, N>::getInstance().get() = this;
            void* l_targetAddr = resolveVirtualAddress(
                reinterpret_cast<const void*>(&targetFunc),
                const_cast<void*>(reinterpret_cast<const void*>(&inst)));
            FuncType l_mockFunction = &MockVirtual::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        virtual ~MockVirtual()
        {
            // Restore runtime patch
            d_patch.restore();
            MockVirtualManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13), N>::getInstance().clear();
        }

        R mockFunction(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6, P7 p7, P8 p8, P9 p9, P10 p10, P11 p11, P12 p12, P13 p13)
        {
            MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13) const, N>* obj = MockVirtualManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13) const, N>::getInstance().get();
            return obj->bonobomockInternalForwardFunc(this, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13);
        }

        virtual void restore()
        {
            // Restore runtime patch
            d_patch.restore();
        }

    private:
        Patch d_patch;
    };

    template <typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
        typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13, typename P14, int N>
    class MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14) const, N> : public GMock<R(const void*, P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14)> {
        typedef R (MockVirtual::*FuncType)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14);

    public:
        MockVirtual(R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14) const, const bsl::string& funcName)
            : GMock<R(const void*, P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14)>(funcName)
        {
            MockVirtualManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14) const, N>::getInstance().get() = this;
            C l_obj;
            void* l_targetAddr = resolveVirtualAddress(
                reinterpret_cast<const void*>(&targetFunc),
                reinterpret_cast<void*>(&l_obj));
            FuncType l_mockFunction = &MockVirtual::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        MockVirtual(const C& inst, R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14) const, const bsl::string& funcName)
            : GMock<R(const void*, P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14)>(funcName)
        {
            MockVirtualManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14) const, N>::getInstance().get() = this;
            void* l_targetAddr = resolveVirtualAddress(
                reinterpret_cast<const void*>(&targetFunc),
                const_cast<void*>(reinterpret_cast<const void*>(&inst)));
            FuncType l_mockFunction = &MockVirtual::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        virtual ~MockVirtual()
        {
            // Restore runtime patch
            d_patch.restore();
            MockVirtualManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14), N>::getInstance().clear();
        }

        R mockFunction(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6, P7 p7, P8 p8, P9 p9, P10 p10, P11 p11, P12 p12, P13 p13, P14 p14)
        {
            MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14) const, N>* obj = MockVirtualManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14) const, N>::getInstance().get();
            return obj->bonobomockInternalForwardFunc(this, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14);
        }

        virtual void restore()
        {
            // Restore runtime patch
            d_patch.restore();
        }

    private:
        Patch d_patch;
    };

    template <typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6,
        typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13, typename P14, typename P15, int N>
    class MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15) const, N> : public GMock<R(const void*, P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15)> {
        typedef R (MockVirtual::*FuncType)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15);

    public:
        MockVirtual(R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15) const, const bsl::string& funcName)
            : GMock<R(const void*, P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15)>(funcName)
        {
            MockVirtualManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15) const, N>::getInstance().get() = this;
            C l_obj;
            void* l_targetAddr = resolveVirtualAddress(
                reinterpret_cast<const void*>(&targetFunc),
                reinterpret_cast<void*>(&l_obj));
            FuncType l_mockFunction = &MockVirtual::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        MockVirtual(const C& inst, R (C::*targetFunc)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15) const, const bsl::string& funcName)
            : GMock<R(const void*, P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15)>(funcName)
        {
            MockVirtualManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15) const, N>::getInstance().get() = this;
            void* l_targetAddr = resolveVirtualAddress(
                reinterpret_cast<const void*>(&targetFunc),
                const_cast<void*>(reinterpret_cast<const void*>(&inst)));
            FuncType l_mockFunction = &MockVirtual::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        virtual ~MockVirtual()
        {
            // Restore runtime patch
            d_patch.restore();
            MockVirtualManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15), N>::getInstance().clear();
        }

        R mockFunction(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6, P7 p7, P8 p8, P9 p9, P10 p10, P11 p11, P12 p12, P13 p13, P14 p14, P15 p15)
        {
            MockVirtual<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15) const, N>* obj = MockVirtualManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15) const, N>::getInstance().get();
            return obj->bonobomockInternalForwardFunc(this, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15);
        }

        virtual void restore()
        {
            // Restore runtime patch
            d_patch.restore();
        }

    private:
        Patch d_patch;
    };

    template <typename R, typename C, int N>
    class MockPrivate<R (C::*)(), N> : public GMock<R(void*)> {
        typedef R (MockPrivate::*FuncType)();

    public:
        MockPrivate(const bsl::string& funcName)
            : GMock<R(void*)>(funcName)
        {
            // Get function address
            size_t addr = PrivateAddressResolver::findNonConstPrivateAddress(funcName);
            MockPrivateManager<R (C::*)(), N>::getInstance().get() = this;
            void* l_targetAddr = reinterpret_cast<void*>(addr);
            FuncType l_mockFunction = &MockPrivate::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        virtual ~MockPrivate()
        {
            // Restore runtime patch
            d_patch.restore();
            MockPrivateManager<R (C::*)(), N>::getInstance().clear();
        }

        R mockFunction()
        {
            MockPrivate<R (C::*)(), N>* obj = MockPrivateManager<R (C::*)(), N>::getInstance().get();
            return obj->bonobomockInternalForwardFunc(this);
        }

        virtual void restore()
        {
            // Restore runtime patch
            d_patch.restore();
        }

    private:
        Patch d_patch;
    };

    template <typename R, typename C, typename P1, int N>
    class MockPrivate<R (C::*)(P1), N> : public GMock<R(void*, P1)> {
        typedef R (MockPrivate::*FuncType)(P1);

    public:
        MockPrivate(const bsl::string& funcName)
            : GMock<R(void*, P1)>(funcName)
        {
            // Get function address
            size_t addr = PrivateAddressResolver::findNonConstPrivateAddress(funcName);
            MockPrivateManager<R (C::*)(P1), N>::getInstance().get() = this;
            void* l_targetAddr = reinterpret_cast<void*>(addr);
            FuncType l_mockFunction = &MockPrivate::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        virtual ~MockPrivate()
        {
            // Restore runtime patch
            d_patch.restore();
            MockPrivateManager<R (C::*)(P1), N>::getInstance().clear();
        }

        R mockFunction(P1 p1)
        {
            MockPrivate<R (C::*)(P1), N>* obj = MockPrivateManager<R (C::*)(P1), N>::getInstance().get();
            return obj->bonobomockInternalForwardFunc(this, p1);
        }

        virtual void restore()
        {
            // Restore runtime patch
            d_patch.restore();
        }

    private:
        Patch d_patch;
    };

    template <typename R, typename C, typename P1, typename P2, int N>
    class MockPrivate<R (C::*)(P1, P2), N> : public GMock<R(void*, P1, P2)> {
        typedef R (MockPrivate::*FuncType)(P1, P2);

    public:
        MockPrivate(const bsl::string& funcName)
            : GMock<R(void*, P1, P2)>(funcName)
        {
            // Get function address
            size_t addr = PrivateAddressResolver::findNonConstPrivateAddress(funcName);
            MockPrivateManager<R (C::*)(P1, P2), N>::getInstance().get() = this;
            void* l_targetAddr = reinterpret_cast<void*>(addr);
            FuncType l_mockFunction = &MockPrivate::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        virtual ~MockPrivate()
        {
            // Restore runtime patch
            d_patch.restore();
            MockPrivateManager<R (C::*)(P1, P2), N>::getInstance().clear();
        }

        R mockFunction(P1 p1, P2 p2)
        {
            MockPrivate<R (C::*)(P1, P2), N>* obj = MockPrivateManager<R (C::*)(P1, P2), N>::getInstance().get();
            return obj->bonobomockInternalForwardFunc(this, p1, p2);
        }

        virtual void restore()
        {
            // Restore runtime patch
            d_patch.restore();
        }

    private:
        Patch d_patch;
    };

    template <typename R, typename C, typename P1, typename P2, typename P3, int N>
    class MockPrivate<R (C::*)(P1, P2, P3), N> : public GMock<R(void*, P1, P2, P3)> {
        typedef R (MockPrivate::*FuncType)(P1, P2, P3);

    public:
        MockPrivate(const bsl::string& funcName)
            : GMock<R(void*, P1, P2, P3)>(funcName)
        {
            // Get function address
            size_t addr = PrivateAddressResolver::findNonConstPrivateAddress(funcName);
            MockPrivateManager<R (C::*)(P1, P2, P3), N>::getInstance().get() = this;
            void* l_targetAddr = reinterpret_cast<void*>(addr);
            FuncType l_mockFunction = &MockPrivate::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        virtual ~MockPrivate()
        {
            // Restore runtime patch
            d_patch.restore();
            MockPrivateManager<R (C::*)(P1, P2, P3), N>::getInstance().clear();
        }

        R mockFunction(P1 p1, P2 p2, P3 p3)
        {
            MockPrivate<R (C::*)(P1, P2, P3), N>* obj = MockPrivateManager<R (C::*)(P1, P2, P3), N>::getInstance().get();
            return obj->bonobomockInternalForwardFunc(this, p1, p2, p3);
        }

        virtual void restore()
        {
            // Restore runtime patch
            d_patch.restore();
        }

    private:
        Patch d_patch;
    };

    template <typename R, typename C, typename P1, typename P2, typename P3, typename P4, int N>
    class MockPrivate<R (C::*)(P1, P2, P3, P4), N> : public GMock<R(void*, P1, P2, P3, P4)> {
        typedef R (MockPrivate::*FuncType)(P1, P2, P3, P4);

    public:
        MockPrivate(const bsl::string& funcName)
            : GMock<R(void*, P1, P2, P3, P4)>(funcName)
        {
            // Get function address
            size_t addr = PrivateAddressResolver::findNonConstPrivateAddress(funcName);
            MockPrivateManager<R (C::*)(P1, P2, P3, P4), N>::getInstance().get() = this;
            void* l_targetAddr = reinterpret_cast<void*>(addr);
            FuncType l_mockFunction = &MockPrivate::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        virtual ~MockPrivate()
        {
            // Restore runtime patch
            d_patch.restore();
            MockPrivateManager<R (C::*)(P1, P2, P3, P4), N>::getInstance().clear();
        }

        R mockFunction(P1 p1, P2 p2, P3 p3, P4 p4)
        {
            MockPrivate<R (C::*)(P1, P2, P3, P4), N>* obj = MockPrivateManager<R (C::*)(P1, P2, P3, P4), N>::getInstance().get();
            return obj->bonobomockInternalForwardFunc(this, p1, p2, p3, p4);
        }

        virtual void restore()
        {
            // Restore runtime patch
            d_patch.restore();
        }

    private:
        Patch d_patch;
    };

    template <typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, int N>
    class MockPrivate<R (C::*)(P1, P2, P3, P4, P5), N> : public GMock<R(void*, P1, P2, P3, P4, P5)> {
        typedef R (MockPrivate::*FuncType)(P1, P2, P3, P4, P5);

    public:
        MockPrivate(const bsl::string& funcName)
            : GMock<R(void*, P1, P2, P3, P4, P5)>(funcName)
        {
            // Get function address
            size_t addr = PrivateAddressResolver::findNonConstPrivateAddress(funcName);
            MockPrivateManager<R (C::*)(P1, P2, P3, P4, P5), N>::getInstance().get() = this;
            void* l_targetAddr = reinterpret_cast<void*>(addr);
            FuncType l_mockFunction = &MockPrivate::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        virtual ~MockPrivate()
        {
            // Restore runtime patch
            d_patch.restore();
            MockPrivateManager<R (C::*)(P1, P2, P3, P4, P5), N>::getInstance().clear();
        }

        R mockFunction(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5)
        {
            MockPrivate<R (C::*)(P1, P2, P3, P4, P5), N>* obj = MockPrivateManager<R (C::*)(P1, P2, P3, P4, P5), N>::getInstance().get();
            return obj->bonobomockInternalForwardFunc(this, p1, p2, p3, p4, p5);
        }

        virtual void restore()
        {
            // Restore runtime patch
            d_patch.restore();
        }

    private:
        Patch d_patch;
    };

    template <typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, int N>
    class MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6), N> : public GMock<R(void*, P1, P2, P3, P4, P5, P6)> {
        typedef R (MockPrivate::*FuncType)(P1, P2, P3, P4, P5, P6);

    public:
        MockPrivate(const bsl::string& funcName)
            : GMock<R(void*, P1, P2, P3, P4, P5, P6)>(funcName)
        {
            // Get function address
            size_t addr = PrivateAddressResolver::findNonConstPrivateAddress(funcName);
            MockPrivateManager<R (C::*)(P1, P2, P3, P4, P5, P6), N>::getInstance().get() = this;
            void* l_targetAddr = reinterpret_cast<void*>(addr);
            FuncType l_mockFunction = &MockPrivate::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        virtual ~MockPrivate()
        {
            // Restore runtime patch
            d_patch.restore();
            MockPrivateManager<R (C::*)(P1, P2, P3, P4, P5, P6), N>::getInstance().clear();
        }

        R mockFunction(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6)
        {
            MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6), N>* obj = MockPrivateManager<R (C::*)(P1, P2, P3, P4, P5, P6), N>::getInstance().get();
            return obj->bonobomockInternalForwardFunc(this, p1, p2, p3, p4, p5, p6);
        }

        virtual void restore()
        {
            // Restore runtime patch
            d_patch.restore();
        }

    private:
        Patch d_patch;
    };

    template <typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, int N>
    class MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7), N> : public GMock<R(void*, P1, P2, P3, P4, P5, P6, P7)> {
        typedef R (MockPrivate::*FuncType)(P1, P2, P3, P4, P5, P6, P7);

    public:
        MockPrivate(const bsl::string& funcName)
            : GMock<R(void*, P1, P2, P3, P4, P5, P6, P7)>(funcName)
        {
            // Get function address
            size_t addr = PrivateAddressResolver::findNonConstPrivateAddress(funcName);
            MockPrivateManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7), N>::getInstance().get() = this;
            void* l_targetAddr = reinterpret_cast<void*>(addr);
            FuncType l_mockFunction = &MockPrivate::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        virtual ~MockPrivate()
        {
            // Restore runtime patch
            d_patch.restore();
            MockPrivateManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7), N>::getInstance().clear();
        }

        R mockFunction(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6, P7 p7)
        {
            MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7), N>* obj = MockPrivateManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7), N>::getInstance().get();
            return obj->bonobomockInternalForwardFunc(this, p1, p2, p3, p4, p5, p6, p7);
        }

        virtual void restore()
        {
            // Restore runtime patch
            d_patch.restore();
        }

    private:
        Patch d_patch;
    };

    template <typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, int N>
    class MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8), N> : public GMock<R(void*, P1, P2, P3, P4, P5, P6, P7, P8)> {
        typedef R (MockPrivate::*FuncType)(P1, P2, P3, P4, P5, P6, P7, P8);

    public:
        MockPrivate(const bsl::string& funcName)
            : GMock<R(void*, P1, P2, P3, P4, P5, P6, P7, P8)>(funcName)
        {
            // Get function address
            size_t addr = PrivateAddressResolver::findNonConstPrivateAddress(funcName);
            MockPrivateManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8), N>::getInstance().get() = this;
            void* l_targetAddr = reinterpret_cast<void*>(addr);
            FuncType l_mockFunction = &MockPrivate::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        virtual ~MockPrivate()
        {
            // Restore runtime patch
            d_patch.restore();
            MockPrivateManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8), N>::getInstance().clear();
        }

        R mockFunction(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6, P7 p7, P8 p8)
        {
            MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8), N>* obj = MockPrivateManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8), N>::getInstance().get();
            return obj->bonobomockInternalForwardFunc(this, p1, p2, p3, p4, p5, p6, p7, p8);
        }

        virtual void restore()
        {
            // Restore runtime patch
            d_patch.restore();
        }

    private:
        Patch d_patch;
    };

    template <typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8,
        typename P9, int N>
    class MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9), N> : public GMock<R(void*, P1, P2, P3, P4, P5, P6, P7, P8, P9)> {
        typedef R (MockPrivate::*FuncType)(P1, P2, P3, P4, P5, P6, P7, P8, P9);

    public:
        MockPrivate(const bsl::string& funcName)
            : GMock<R(void*, P1, P2, P3, P4, P5, P6, P7, P8, P9)>(funcName)
        {
            // Get function address
            size_t addr = PrivateAddressResolver::findNonConstPrivateAddress(funcName);
            MockPrivateManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9), N>::getInstance().get() = this;
            void* l_targetAddr = reinterpret_cast<void*>(addr);
            FuncType l_mockFunction = &MockPrivate::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        virtual ~MockPrivate()
        {
            // Restore runtime patch
            d_patch.restore();
            MockPrivateManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9), N>::getInstance().clear();
        }

        R mockFunction(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6, P7 p7, P8 p8, P9 p9)
        {
            MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9), N>* obj = MockPrivateManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9), N>::getInstance().get();
            return obj->bonobomockInternalForwardFunc(this, p1, p2, p3, p4, p5, p6, p7, p8, p9);
        }

        virtual void restore()
        {
            // Restore runtime patch
            d_patch.restore();
        }

    private:
        Patch d_patch;
    };

    template <typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8,
        typename P9, typename P10, int N>
    class MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10), N> : public GMock<R(void*, P1, P2, P3, P4, P5, P6, P7, P8, P9, P10)> {
        typedef R (MockPrivate::*FuncType)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10);

    public:
        MockPrivate(const bsl::string& funcName)
            : GMock<R(void*, P1, P2, P3, P4, P5, P6, P7, P8, P9, P10)>(funcName)
        {
            // Get function address
            size_t addr = PrivateAddressResolver::findNonConstPrivateAddress(funcName);
            MockPrivateManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10), N>::getInstance().get() = this;
            void* l_targetAddr = reinterpret_cast<void*>(addr);
            FuncType l_mockFunction = &MockPrivate::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        virtual ~MockPrivate()
        {
            // Restore runtime patch
            d_patch.restore();
            MockPrivateManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10), N>::getInstance().clear();
        }

        R mockFunction(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6, P7 p7, P8 p8, P9 p9, P10 p10)
        {
            MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10), N>* obj = MockPrivateManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10), N>::getInstance().get();
            return obj->bonobomockInternalForwardFunc(this, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10);
        }

        virtual void restore()
        {
            // Restore runtime patch
            d_patch.restore();
        }

    private:
        Patch d_patch;
    };

    template <typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8,
        typename P9, typename P10, typename P11, int N>
    class MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11), N> : public GMock<R(void*, P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11)> {
        typedef R (MockPrivate::*FuncType)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11);

    public:
        MockPrivate(const bsl::string& funcName)
            : GMock<R(void*, P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11)>(funcName)
        {
            // Get function address
            size_t addr = PrivateAddressResolver::findNonConstPrivateAddress(funcName);
            MockPrivateManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11), N>::getInstance().get() = this;
            void* l_targetAddr = reinterpret_cast<void*>(addr);
            FuncType l_mockFunction = &MockPrivate::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        virtual ~MockPrivate()
        {
            // Restore runtime patch
            d_patch.restore();
            MockPrivateManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11), N>::getInstance().clear();
        }

        R mockFunction(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6, P7 p7, P8 p8, P9 p9, P10 p10, P11 p11)
        {
            MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11), N>* obj = MockPrivateManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11), N>::getInstance().get();
            return obj->bonobomockInternalForwardFunc(this, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11);
        }

        virtual void restore()
        {
            // Restore runtime patch
            d_patch.restore();
        }

    private:
        Patch d_patch;
    };

    template <typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8,
        typename P9, typename P10, typename P11, typename P12, int N>
    class MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12), N> : public GMock<R(void*, P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12)> {
        typedef R (MockPrivate::*FuncType)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12);

    public:
        MockPrivate(const bsl::string& funcName)
            : GMock<R(void*, P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12)>(funcName)
        {
            // Get function address
            size_t addr = PrivateAddressResolver::findNonConstPrivateAddress(funcName);
            MockPrivateManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12), N>::getInstance().get() = this;
            void* l_targetAddr = reinterpret_cast<void*>(addr);
            FuncType l_mockFunction = &MockPrivate::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        virtual ~MockPrivate()
        {
            // Restore runtime patch
            d_patch.restore();
            MockPrivateManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12), N>::getInstance().clear();
        }

        R mockFunction(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6, P7 p7, P8 p8, P9 p9, P10 p10, P11 p11, P12 p12)
        {
            MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12), N>* obj = MockPrivateManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12), N>::getInstance().get();
            return obj->bonobomockInternalForwardFunc(this, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12);
        }

        virtual void restore()
        {
            // Restore runtime patch
            d_patch.restore();
        }

    private:
        Patch d_patch;
    };

    template <typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8,
        typename P9, typename P10, typename P11, typename P12, typename P13, int N>
    class MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13), N> : public GMock<R(void*, P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13)> {
        typedef R (MockPrivate::*FuncType)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13);

    public:
        MockPrivate(const bsl::string& funcName)
            : GMock<R(void*, P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13)>(funcName)
        {
            // Get function address
            size_t addr = PrivateAddressResolver::findNonConstPrivateAddress(funcName);
            MockPrivateManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13), N>::getInstance().get() = this;
            void* l_targetAddr = reinterpret_cast<void*>(addr);
            FuncType l_mockFunction = &MockPrivate::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        virtual ~MockPrivate()
        {
            // Restore runtime patch
            d_patch.restore();
            MockPrivateManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13), N>::getInstance().clear();
        }

        R mockFunction(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6, P7 p7, P8 p8, P9 p9, P10 p10, P11 p11, P12 p12, P13 p13)
        {
            MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13), N>* obj = MockPrivateManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13), N>::getInstance().get();
            return obj->bonobomockInternalForwardFunc(this, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13);
        }

        virtual void restore()
        {
            // Restore runtime patch
            d_patch.restore();
        }

    private:
        Patch d_patch;
    };

    template <typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8,
        typename P9, typename P10, typename P11, typename P12, typename P13, typename P14, int N>
    class MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14), N> : public GMock<R(void*, P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14)> {
        typedef R (MockPrivate::*FuncType)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14);

    public:
        MockPrivate(const bsl::string& funcName)
            : GMock<R(void*, P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14)>(funcName)
        {
            // Get function address
            size_t addr = PrivateAddressResolver::findNonConstPrivateAddress(funcName);
            MockPrivateManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14), N>::getInstance().get() = this;
            void* l_targetAddr = reinterpret_cast<void*>(addr);
            FuncType l_mockFunction = &MockPrivate::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        virtual ~MockPrivate()
        {
            // Restore runtime patch
            d_patch.restore();
            MockPrivateManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14), N>::getInstance().clear();
        }

        R mockFunction(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6, P7 p7, P8 p8, P9 p9, P10 p10, P11 p11, P12 p12, P13 p13, P14 p14)
        {
            MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14), N>* obj = MockPrivateManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14), N>::getInstance().get();
            return obj->bonobomockInternalForwardFunc(this, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14);
        }

        virtual void restore()
        {
            // Restore runtime patch
            d_patch.restore();
        }

    private:
        Patch d_patch;
    };

    template <typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8,
        typename P9, typename P10, typename P11, typename P12, typename P13, typename P14, typename P15, int N>
    class MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15), N> : public GMock<R(void*, P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15)> {
        typedef R (MockPrivate::*FuncType)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15);

    public:
        MockPrivate(const bsl::string& funcName)
            : GMock<R(void*, P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15)>(funcName)
        {
            // Get function address
            size_t addr = PrivateAddressResolver::findNonConstPrivateAddress(funcName);
            MockPrivateManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15), N>::getInstance().get() = this;
            void* l_targetAddr = reinterpret_cast<void*>(addr);
            FuncType l_mockFunction = &MockPrivate::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        virtual ~MockPrivate()
        {
            // Restore runtime patch
            d_patch.restore();
            MockPrivateManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15), N>::getInstance().clear();
        }

        R mockFunction(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6, P7 p7, P8 p8, P9 p9, P10 p10, P11 p11, P12 p12, P13 p13, P14 p14, P15 p15)
        {
            MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15), N>* obj = MockPrivateManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15), N>::getInstance().get();
            return obj->bonobomockInternalForwardFunc(this, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15);
        }

        virtual void restore()
        {
            // Restore runtime patch
            d_patch.restore();
        }

    private:
        Patch d_patch;
    };

    template <typename R, typename C, int N>
    class MockPrivate<R (C::*)() const, N> : public GMock<R(const void*)> {
        typedef R (MockPrivate::*FuncType)();

    public:
        MockPrivate(const bsl::string& funcName)
            : GMock<R(const void*)>(funcName)
        {
            // Get function address
            size_t addr = PrivateAddressResolver::findConstPrivateAddress(funcName);
            MockPrivateManager<R (C::*)() const, N>::getInstance().get() = this;
            void* l_targetAddr = reinterpret_cast<void*>(addr);
            FuncType l_mockFunction = &MockPrivate::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        virtual ~MockPrivate()
        {
            // Restore runtime patch
            d_patch.restore();
            MockPrivateManager<R (C::*)() const, N>::getInstance().clear();
        }

        R mockFunction()
        {
            MockPrivate<R (C::*)() const, N>* obj = MockPrivateManager<R (C::*)() const, N>::getInstance().get();
            return obj->bonobomockInternalForwardFunc(this);
        }

        virtual void restore()
        {
            // Restore runtime patch
            d_patch.restore();
        }

    private:
        Patch d_patch;
    };

    template <typename R, typename C, typename P1, int N>
    class MockPrivate<R (C::*)(P1) const, N> : public GMock<R(const void*, P1)> {
        typedef R (MockPrivate::*FuncType)(P1);

    public:
        MockPrivate(const bsl::string& funcName)
            : GMock<R(const void*, P1)>(funcName)
        {
            // Get function address
            size_t addr = PrivateAddressResolver::findConstPrivateAddress(funcName);
            MockPrivateManager<R (C::*)(P1) const, N>::getInstance().get() = this;
            void* l_targetAddr = reinterpret_cast<void*>(addr);
            FuncType l_mockFunction = &MockPrivate::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        virtual ~MockPrivate()
        {
            // Restore runtime patch
            d_patch.restore();
            MockPrivateManager<R (C::*)(P1) const, N>::getInstance().clear();
        }

        R mockFunction(P1 p1)
        {
            MockPrivate<R (C::*)(P1) const, N>* obj = MockPrivateManager<R (C::*)(P1) const, N>::getInstance().get();
            return obj->bonobomockInternalForwardFunc(this, p1);
        }

        virtual void restore()
        {
            // Restore runtime patch
            d_patch.restore();
        }

    private:
        Patch d_patch;
    };

    template <typename R, typename C, typename P1, typename P2, int N>
    class MockPrivate<R (C::*)(P1, P2) const, N> : public GMock<R(const void*, P1, P2)> {
        typedef R (MockPrivate::*FuncType)(P1, P2);

    public:
        MockPrivate(const bsl::string& funcName)
            : GMock<R(const void*, P1, P2)>(funcName)
        {
            // Get function address
            size_t addr = PrivateAddressResolver::findConstPrivateAddress(funcName);
            MockPrivateManager<R (C::*)(P1, P2) const, N>::getInstance().get() = this;
            void* l_targetAddr = reinterpret_cast<void*>(addr);
            FuncType l_mockFunction = &MockPrivate::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        virtual ~MockPrivate()
        {
            // Restore runtime patch
            d_patch.restore();
            MockPrivateManager<R (C::*)(P1, P2) const, N>::getInstance().clear();
        }

        R mockFunction(P1 p1, P2 p2)
        {
            MockPrivate<R (C::*)(P1, P2) const, N>* obj = MockPrivateManager<R (C::*)(P1, P2) const, N>::getInstance().get();
            return obj->bonobomockInternalForwardFunc(this, p1, p2);
        }

        virtual void restore()
        {
            // Restore runtime patch
            d_patch.restore();
        }

    private:
        Patch d_patch;
    };

    template <typename R, typename C, typename P1, typename P2, typename P3, int N>
    class MockPrivate<R (C::*)(P1, P2, P3) const, N> : public GMock<R(const void*, P1, P2, P3)> {
        typedef R (MockPrivate::*FuncType)(P1, P2, P3);

    public:
        MockPrivate(const bsl::string& funcName)
            : GMock<R(const void*, P1, P2, P3)>(funcName)
        {
            // Get function address
            size_t addr = PrivateAddressResolver::findConstPrivateAddress(funcName);
            MockPrivateManager<R (C::*)(P1, P2, P3) const, N>::getInstance().get() = this;
            void* l_targetAddr = reinterpret_cast<void*>(addr);
            FuncType l_mockFunction = &MockPrivate::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        virtual ~MockPrivate()
        {
            // Restore runtime patch
            d_patch.restore();
            MockPrivateManager<R (C::*)(P1, P2, P3) const, N>::getInstance().clear();
        }

        R mockFunction(P1 p1, P2 p2, P3 p3)
        {
            MockPrivate<R (C::*)(P1, P2, P3) const, N>* obj = MockPrivateManager<R (C::*)(P1, P2, P3) const, N>::getInstance().get();
            return obj->bonobomockInternalForwardFunc(this, p1, p2, p3);
        }

        virtual void restore()
        {
            // Restore runtime patch
            d_patch.restore();
        }

    private:
        Patch d_patch;
    };

    template <typename R, typename C, typename P1, typename P2, typename P3, typename P4, int N>
    class MockPrivate<R (C::*)(P1, P2, P3, P4) const, N> : public GMock<R(const void*, P1, P2, P3, P4)> {
        typedef R (MockPrivate::*FuncType)(P1, P2, P3, P4);

    public:
        MockPrivate(const bsl::string& funcName)
            : GMock<R(const void*, P1, P2, P3, P4)>(funcName)
        {
            // Get function address
            size_t addr = PrivateAddressResolver::findConstPrivateAddress(funcName);
            MockPrivateManager<R (C::*)(P1, P2, P3, P4) const, N>::getInstance().get() = this;
            void* l_targetAddr = reinterpret_cast<void*>(addr);
            FuncType l_mockFunction = &MockPrivate::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        virtual ~MockPrivate()
        {
            // Restore runtime patch
            d_patch.restore();
            MockPrivateManager<R (C::*)(P1, P2, P3, P4) const, N>::getInstance().clear();
        }

        R mockFunction(P1 p1, P2 p2, P3 p3, P4 p4)
        {
            MockPrivate<R (C::*)(P1, P2, P3, P4) const, N>* obj = MockPrivateManager<R (C::*)(P1, P2, P3, P4) const, N>::getInstance().get();
            return obj->bonobomockInternalForwardFunc(this, p1, p2, p3, p4);
        }

        virtual void restore()
        {
            // Restore runtime patch
            d_patch.restore();
        }

    private:
        Patch d_patch;
    };

    template <typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, int N>
    class MockPrivate<R (C::*)(P1, P2, P3, P4, P5) const, N> : public GMock<R(const void*, P1, P2, P3, P4, P5)> {
        typedef R (MockPrivate::*FuncType)(P1, P2, P3, P4, P5);

    public:
        MockPrivate(const bsl::string& funcName)
            : GMock<R(const void*, P1, P2, P3, P4, P5)>(funcName)
        {
            // Get function address
            size_t addr = PrivateAddressResolver::findConstPrivateAddress(funcName);
            MockPrivateManager<R (C::*)(P1, P2, P3, P4, P5) const, N>::getInstance().get() = this;
            void* l_targetAddr = reinterpret_cast<void*>(addr);
            FuncType l_mockFunction = &MockPrivate::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        virtual ~MockPrivate()
        {
            // Restore runtime patch
            d_patch.restore();
            MockPrivateManager<R (C::*)(P1, P2, P3, P4, P5) const, N>::getInstance().clear();
        }

        R mockFunction(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5)
        {
            MockPrivate<R (C::*)(P1, P2, P3, P4, P5) const, N>* obj = MockPrivateManager<R (C::*)(P1, P2, P3, P4, P5) const, N>::getInstance().get();
            return obj->bonobomockInternalForwardFunc(this, p1, p2, p3, p4, p5);
        }

        virtual void restore()
        {
            // Restore runtime patch
            d_patch.restore();
        }

    private:
        Patch d_patch;
    };

    template <typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, int N>
    class MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6) const, N> : public GMock<R(const void*, P1, P2, P3, P4, P5, P6)> {
        typedef R (MockPrivate::*FuncType)(P1, P2, P3, P4, P5, P6);

    public:
        MockPrivate(const bsl::string& funcName)
            : GMock<R(const void*, P1, P2, P3, P4, P5, P6)>(funcName)
        {
            // Get function address
            size_t addr = PrivateAddressResolver::findConstPrivateAddress(funcName);
            MockPrivateManager<R (C::*)(P1, P2, P3, P4, P5, P6) const, N>::getInstance().get() = this;
            void* l_targetAddr = reinterpret_cast<void*>(addr);
            FuncType l_mockFunction = &MockPrivate::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        virtual ~MockPrivate()
        {
            // Restore runtime patch
            d_patch.restore();
            MockPrivateManager<R (C::*)(P1, P2, P3, P4, P5, P6) const, N>::getInstance().clear();
        }

        R mockFunction(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6)
        {
            MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6) const, N>* obj = MockPrivateManager<R (C::*)(P1, P2, P3, P4, P5, P6) const, N>::getInstance().get();
            return obj->bonobomockInternalForwardFunc(this, p1, p2, p3, p4, p5, p6);
        }

        virtual void restore()
        {
            // Restore runtime patch
            d_patch.restore();
        }

    private:
        Patch d_patch;
    };

    template <typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, int N>
    class MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7) const, N> : public GMock<R(const void*, P1, P2, P3, P4, P5, P6, P7)> {
        typedef R (MockPrivate::*FuncType)(P1, P2, P3, P4, P5, P6, P7);

    public:
        MockPrivate(const bsl::string& funcName)
            : GMock<R(const void*, P1, P2, P3, P4, P5, P6, P7)>(funcName)
        {
            // Get function address
            size_t addr = PrivateAddressResolver::findConstPrivateAddress(funcName);
            MockPrivateManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7) const, N>::getInstance().get() = this;
            void* l_targetAddr = reinterpret_cast<void*>(addr);
            FuncType l_mockFunction = &MockPrivate::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        virtual ~MockPrivate()
        {
            // Restore runtime patch
            d_patch.restore();
            MockPrivateManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7) const, N>::getInstance().clear();
        }

        R mockFunction(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6, P7 p7)
        {
            MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7) const, N>* obj = MockPrivateManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7) const, N>::getInstance().get();
            return obj->bonobomockInternalForwardFunc(this, p1, p2, p3, p4, p5, p6, p7);
        }

        virtual void restore()
        {
            // Restore runtime patch
            d_patch.restore();
        }

    private:
        Patch d_patch;
    };

    template <typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, int N>
    class MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8) const, N> : public GMock<R(const void*, P1, P2, P3, P4, P5, P6, P7, P8)> {
        typedef R (MockPrivate::*FuncType)(P1, P2, P3, P4, P5, P6, P7, P8);

    public:
        MockPrivate(const bsl::string& funcName)
            : GMock<R(const void*, P1, P2, P3, P4, P5, P6, P7, P8)>(funcName)
        {
            // Get function address
            size_t addr = PrivateAddressResolver::findConstPrivateAddress(funcName);
            MockPrivateManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8) const, N>::getInstance().get() = this;
            void* l_targetAddr = reinterpret_cast<void*>(addr);
            FuncType l_mockFunction = &MockPrivate::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        virtual ~MockPrivate()
        {
            // Restore runtime patch
            d_patch.restore();
            MockPrivateManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8) const, N>::getInstance().clear();
        }

        R mockFunction(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6, P7 p7, P8 p8)
        {
            MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8) const, N>* obj = MockPrivateManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8) const, N>::getInstance().get();
            return obj->bonobomockInternalForwardFunc(this, p1, p2, p3, p4, p5, p6, p7, p8);
        }

        virtual void restore()
        {
            // Restore runtime patch
            d_patch.restore();
        }

    private:
        Patch d_patch;
    };

    template <typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8,
        typename P9, int N>
    class MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9) const, N> : public GMock<R(const void*, P1, P2, P3, P4, P5, P6, P7, P8, P9)> {
        typedef R (MockPrivate::*FuncType)(P1, P2, P3, P4, P5, P6, P7, P8, P9);

    public:
        MockPrivate(const bsl::string& funcName)
            : GMock<R(const void*, P1, P2, P3, P4, P5, P6, P7, P8, P9)>(funcName)
        {
            // Get function address
            size_t addr = PrivateAddressResolver::findConstPrivateAddress(funcName);
            MockPrivateManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9) const, N>::getInstance().get() = this;
            void* l_targetAddr = reinterpret_cast<void*>(addr);
            FuncType l_mockFunction = &MockPrivate::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        virtual ~MockPrivate()
        {
            // Restore runtime patch
            d_patch.restore();
            MockPrivateManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9) const, N>::getInstance().clear();
        }

        R mockFunction(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6, P7 p7, P8 p8, P9 p9)
        {
            MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9) const, N>* obj = MockPrivateManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9) const, N>::getInstance().get();
            return obj->bonobomockInternalForwardFunc(this, p1, p2, p3, p4, p5, p6, p7, p8, p9);
        }

        virtual void restore()
        {
            // Restore runtime patch
            d_patch.restore();
        }

    private:
        Patch d_patch;
    };

    template <typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8,
        typename P9, typename P10, int N>
    class MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10) const, N> : public GMock<R(const void*, P1, P2, P3, P4, P5, P6, P7, P8, P9, P10)> {
        typedef R (MockPrivate::*FuncType)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10);

    public:
        MockPrivate(const bsl::string& funcName)
            : GMock<R(const void*, P1, P2, P3, P4, P5, P6, P7, P8, P9, P10)>(funcName)
        {
            // Get function address
            size_t addr = PrivateAddressResolver::findConstPrivateAddress(funcName);
            MockPrivateManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10) const, N>::getInstance().get() = this;
            void* l_targetAddr = reinterpret_cast<void*>(addr);
            FuncType l_mockFunction = &MockPrivate::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        virtual ~MockPrivate()
        {
            // Restore runtime patch
            d_patch.restore();
            MockPrivateManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10) const, N>::getInstance().clear();
        }

        R mockFunction(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6, P7 p7, P8 p8, P9 p9, P10 p10)
        {
            MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10) const, N>* obj = MockPrivateManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10) const, N>::getInstance().get();
            return obj->bonobomockInternalForwardFunc(this, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10);
        }

        virtual void restore()
        {
            // Restore runtime patch
            d_patch.restore();
        }

    private:
        Patch d_patch;
    };

    template <typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8,
        typename P9, typename P10, typename P11, int N>
    class MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11) const, N> : public GMock<R(const void*, P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11)> {
        typedef R (MockPrivate::*FuncType)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11);

    public:
        MockPrivate(const bsl::string& funcName)
            : GMock<R(const void*, P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11)>(funcName)
        {
            // Get function address
            size_t addr = PrivateAddressResolver::findConstPrivateAddress(funcName);
            MockPrivateManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11) const, N>::getInstance().get() = this;
            void* l_targetAddr = reinterpret_cast<void*>(addr);
            FuncType l_mockFunction = &MockPrivate::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        virtual ~MockPrivate()
        {
            // Restore runtime patch
            d_patch.restore();
            MockPrivateManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11) const, N>::getInstance().clear();
        }

        R mockFunction(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6, P7 p7, P8 p8, P9 p9, P10 p10, P11 p11)
        {
            MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11) const, N>* obj = MockPrivateManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11) const, N>::getInstance().get();
            return obj->bonobomockInternalForwardFunc(this, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11);
        }

        virtual void restore()
        {
            // Restore runtime patch
            d_patch.restore();
        }

    private:
        Patch d_patch;
    };

    template <typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8,
        typename P9, typename P10, typename P11, typename P12, int N>
    class MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12) const, N> : public GMock<R(const void*, P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12)> {
        typedef R (MockPrivate::*FuncType)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12);

    public:
        MockPrivate(const bsl::string& funcName)
            : GMock<R(const void*, P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12)>(funcName)
        {
            // Get function address
            size_t addr = PrivateAddressResolver::findConstPrivateAddress(funcName);
            MockPrivateManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12) const, N>::getInstance().get() = this;
            void* l_targetAddr = reinterpret_cast<void*>(addr);
            FuncType l_mockFunction = &MockPrivate::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        virtual ~MockPrivate()
        {
            // Restore runtime patch
            d_patch.restore();
            MockPrivateManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12) const, N>::getInstance().clear();
        }

        R mockFunction(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6, P7 p7, P8 p8, P9 p9, P10 p10, P11 p11, P12 p12)
        {
            MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12) const, N>* obj = MockPrivateManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12) const, N>::getInstance().get();
            return obj->bonobomockInternalForwardFunc(this, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12);
        }

        virtual void restore()
        {
            // Restore runtime patch
            d_patch.restore();
        }

    private:
        Patch d_patch;
    };

    template <typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8,
        typename P9, typename P10, typename P11, typename P12, typename P13, int N>
    class MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13) const, N> : public GMock<R(const void*, P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13)> {
        typedef R (MockPrivate::*FuncType)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13);

    public:
        MockPrivate(const bsl::string& funcName)
            : GMock<R(const void*, P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13)>(funcName)
        {
            // Get function address
            size_t addr = PrivateAddressResolver::findConstPrivateAddress(funcName);
            MockPrivateManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13) const, N>::getInstance().get() = this;
            void* l_targetAddr = reinterpret_cast<void*>(addr);
            FuncType l_mockFunction = &MockPrivate::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        virtual ~MockPrivate()
        {
            // Restore runtime patch
            d_patch.restore();
            MockPrivateManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13) const, N>::getInstance().clear();
        }

        R mockFunction(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6, P7 p7, P8 p8, P9 p9, P10 p10, P11 p11, P12 p12, P13 p13)
        {
            MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13) const, N>* obj = MockPrivateManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13) const, N>::getInstance().get();
            return obj->bonobomockInternalForwardFunc(this, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13);
        }

        virtual void restore()
        {
            // Restore runtime patch
            d_patch.restore();
        }

    private:
        Patch d_patch;
    };

    template <typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8,
        typename P9, typename P10, typename P11, typename P12, typename P13, typename P14, int N>
    class MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14) const, N> : public GMock<R(const void*, P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14)> {
        typedef R (MockPrivate::*FuncType)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14);

    public:
        MockPrivate(const bsl::string& funcName)
            : GMock<R(const void*, P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14)>(funcName)
        {
            // Get function address
            size_t addr = PrivateAddressResolver::findConstPrivateAddress(funcName);
            MockPrivateManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14) const, N>::getInstance().get() = this;
            void* l_targetAddr = reinterpret_cast<void*>(addr);
            FuncType l_mockFunction = &MockPrivate::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        virtual ~MockPrivate()
        {
            // Restore runtime patch
            d_patch.restore();
            MockPrivateManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14) const, N>::getInstance().clear();
        }

        R mockFunction(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6, P7 p7, P8 p8, P9 p9, P10 p10, P11 p11, P12 p12, P13 p13, P14 p14)
        {
            MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14) const, N>* obj = MockPrivateManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14) const, N>::getInstance().get();
            return obj->bonobomockInternalForwardFunc(this, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14);
        }

        virtual void restore()
        {
            // Restore runtime patch
            d_patch.restore();
        }

    private:
        Patch d_patch;
    };

    template <typename R, typename C, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8,
        typename P9, typename P10, typename P11, typename P12, typename P13, typename P14, typename P15, int N>
    class MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15) const, N> : public GMock<R(const void*, P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15)> {
        typedef R (MockPrivate::*FuncType)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15);

    public:
        MockPrivate(const bsl::string& funcName)
            : GMock<R(const void*, P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15)>(funcName)
        {
            // Get function address
            size_t addr = PrivateAddressResolver::findConstPrivateAddress(funcName);
            MockPrivateManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15) const, N>::getInstance().get() = this;
            void* l_targetAddr = reinterpret_cast<void*>(addr);
            FuncType l_mockFunction = &MockPrivate::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        virtual ~MockPrivate()
        {
            // Restore runtime patch
            d_patch.restore();
            MockPrivateManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15) const, N>::getInstance().clear();
        }

        R mockFunction(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6, P7 p7, P8 p8, P9 p9, P10 p10, P11 p11, P12 p12, P13 p13, P14 p14, P15 p15)
        {
            MockPrivate<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15) const, N>* obj = MockPrivateManager<R (C::*)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15) const, N>::getInstance().get();
            return obj->bonobomockInternalForwardFunc(this, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15);
        }

        virtual void restore()
        {
            // Restore runtime patch
            d_patch.restore();
        }

    private:
        Patch d_patch;
    };

}
}

#endif
