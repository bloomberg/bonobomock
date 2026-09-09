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

#include <sample_side_effect_consumer.h>
#include <sample_side_effect_lib.h>

#include <bonobomock_api.h>

#include <gtest/gtest.h>

// Dummy out the side-effecting constructors and destructors. These must be at
// namespace (global) scope, not inside an anonymous namespace: out-of-line
// member definitions must appear in a namespace enclosing the class. The test
// target links with ALLOW_CONSTRUCTOR_DUMMIES so these empty definitions win
// over the real ones in sample_side_effect_lib.
BONOBO_DUMMY_CONSTRUCTOR_AND_DESTRUCTOR(sample_side_effect_lib::NonPolyWidget, NonPolyWidget, (int))
BONOBO_DUMMY_CONSTRUCTOR_AND_DESTRUCTOR(sample_side_effect_lib::PolyWidget, PolyWidget, (int))

// WidgetWithDependency has a non-default-constructible member (Dependency), so
// an empty dummy body would not compile; the _WITH_INIT variant supplies a
// member-initializer list that forwards the named constructor parameter.
BONOBO_DUMMY_CONSTRUCTOR_AND_DESTRUCTOR_WITH_INIT(
    sample_side_effect_lib::WidgetWithDependency, WidgetWithDependency, (int id), d_dep(id))

// The _WITH_INIT variant forwards the member-initializer list through
// __VA_ARGS__. The dummies below check that both kinds of comma survive that
// passthrough: a comma inside a single entry (d_dep(id, 50)) and a comma
// between entries (d_dep1(id), d_dep2(id)), including a constructor that itself
// takes multiple parameters.
BONOBO_DUMMY_CONSTRUCTOR_AND_DESTRUCTOR_WITH_INIT(
    sample_side_effect_lib::WidgetWithMultiArgMember, WidgetWithMultiArgMember, (int id), d_dep(id, 50))
BONOBO_DUMMY_CONSTRUCTOR_AND_DESTRUCTOR_WITH_INIT(
    sample_side_effect_lib::WidgetWithTwoMembers, WidgetWithTwoMembers, (int id), d_dep1(id), d_dep2(id))
BONOBO_DUMMY_CONSTRUCTOR_AND_DESTRUCTOR_WITH_INIT(
    sample_side_effect_lib::WidgetWithMixedMembers, WidgetWithMixedMembers, (int first, int second),
    d_dep1(first, second), d_dep2(second))

namespace {

using sample_side_effect_lib::constructNonPolyWidget;
using sample_side_effect_lib::constructPolyWidgetAndGetValue;
using sample_side_effect_lib::constructWidgetWithDependencyAndGetValue;
using sample_side_effect_lib::constructWidgetWithMixedMembersAndGetSum;
using sample_side_effect_lib::constructWidgetWithMultiArgMemberAndGetValue;
using sample_side_effect_lib::constructWidgetWithTwoMembersAndGetSum;
using sample_side_effect_lib::sideEffectCounter;

TEST(BonoboMockDummyConstructor, SuppressesNonPolymorphicConstructorSideEffects)
{
    // given a non-polymorphic class whose real constructor and destructor have
    // side effects, with both dummied out
    sideEffectCounter() = 0;

    // when an instance is constructed (and destroyed)
    constructNonPolyWidget(7);

    // then neither the real constructor nor the real destructor ran
    EXPECT_EQ(sideEffectCounter(), 0);
}

TEST(BonoboMockDummyConstructor, SuppressesPolymorphicConstructorButKeepsRealMethods)
{
    // given a polymorphic class whose real constructor has side effects, with
    // the constructor and destructor dummied out
    sideEffectCounter() = 0;

    // when an instance is constructed and a virtual method is called
    int value = constructPolyWidgetAndGetValue(7);

    // then the constructor side effect was suppressed, but the real virtual
    // method still ran (vtable and methods are preserved)
    EXPECT_EQ(sideEffectCounter(), 0);
    EXPECT_EQ(value, 42);
}

TEST(BonoboMockDummyConstructor, SuppressesConstructorForClassWithNonDefaultConstructibleMember)
{
    // given a class with a non-default-constructible member, dummied with the
    // _WITH_INIT variant so the member is initialized from the ctor parameter
    sideEffectCounter() = 0;

    // when an instance is constructed
    int value = constructWidgetWithDependencyAndGetValue(7);

    // then the constructor side effect was suppressed and the member was
    // initialized by the dummy's member-initializer list
    EXPECT_EQ(sideEffectCounter(), 0);
    EXPECT_EQ(value, 7);
}

TEST(BonoboMockDummyConstructor, SuppressesConstructorForMemberWithMultipleParameters)
{
    // given a class whose member's constructor takes multiple parameters,
    // dummied with a member-initializer entry that contains its own comma
    // (d_dep(id, 50)); the real ctor uses (id, 100), so the value tells them apart
    sideEffectCounter() = 0;

    // when an instance is constructed
    int value = constructWidgetWithMultiArgMemberAndGetValue(7);

    // then the side effect was suppressed and the dummy's init list ran (7 + 50)
    EXPECT_EQ(sideEffectCounter(), 0);
    EXPECT_EQ(value, 57);
}

TEST(BonoboMockDummyConstructor, SuppressesConstructorForClassWithMultipleMembers)
{
    // given a class with two non-default-constructible members, dummied with two
    // member-initializer entries separated by a top-level comma
    sideEffectCounter() = 0;

    // when an instance is constructed
    int sum = constructWidgetWithTwoMembersAndGetSum(7);

    // then the side effect was suppressed and both members were initialized from
    // the dummy's init list (7 + 7), not the real ctor's (id+1000, id+2000)
    EXPECT_EQ(sideEffectCounter(), 0);
    EXPECT_EQ(sum, 14);
}

TEST(BonoboMockDummyConstructor, SuppressesConstructorForClassWithMixedMembers)
{
    // given a class with a multi-argument member and a single-argument member,
    // and a constructor taking multiple parameters, dummied with a mix of a
    // comma-containing entry (d_dep1(first, second)) and a plain one (d_dep2(second))
    sideEffectCounter() = 0;

    // when an instance is constructed
    int sum = constructWidgetWithMixedMembersAndGetSum(3, 5);

    // then the side effect was suppressed and the dummy's init list ran:
    // d_dep1 = 3 + 5, d_dep2 = 5, so the sum is 13
    EXPECT_EQ(sideEffectCounter(), 0);
    EXPECT_EQ(sum, 13);
}

} // namespace
