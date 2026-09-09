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

#ifndef INCLUDED_BONOBOMOCK_INTERNAL_GMOCK
#define INCLUDED_BONOBOMOCK_INTERNAL_GMOCK

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

    template <typename R, typename... P>
    class GMock<R(P...)> : public MockBase {
    public:
        GMock(const bsl::string& funcName)
            : d_funcName(funcName)
        {
        }

        virtual ~GMock() { }

        R bonobomockInternalForwardFunc(P... p)
        {
            d_gmock.SetOwnerAndName(this, d_funcName.c_str());
            return d_gmock.Invoke(std::forward<P>(p)...);
        }

        ::testing::MockSpec<R(P...)> gmock_bonobomockInternalForwardFunc(const ::testing::Matcher<P>&... p)
        {
            d_gmock.RegisterOwner(this);
            return d_gmock.With(p...);
        }

        ::testing::FunctionMocker<R(P...)> d_gmock;

    private:
        bsl::string d_funcName;
    };

    template <typename T>
    struct MockClassTraits;

    template <typename R, typename... P>
    struct MockClassTraits<R (*)(P...)> {
        using GMockType = GMock<R(P...)>;
    };

    template <typename R, typename C, typename... P>
    struct MockClassTraits<R (C::*)(P...)> {
        using GMockType = GMock<R(void*, P...)>;
    };

    template <typename R, typename C, typename... P>
    struct MockClassTraits<R (C::*)(P...) const> {
        using GMockType = GMock<R(const void*, P...)>;
    };

}
}

#endif
