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

#ifndef INCLUDED_BONOBOMOCK_SAMPLE_SIDE_EFFECT_LIB
#define INCLUDED_BONOBOMOCK_SAMPLE_SIDE_EFFECT_LIB

// Classes with side-effecting constructors/destructors, built as a separate
// static library so their real definitions live in a linked archive that the
// BONOBO_DUMMY_* macros can override at link time (the realistic "the side effect
// lives in a dependency" scenario).

namespace sample_side_effect_lib {

// Observable side effect: bumped by every real constructor/destructor body.
int& sideEffectCounter();

// Non-polymorphic class whose constructor and destructor have side effects.
class NonPolyWidget {
public:
    explicit NonPolyWidget(int id);
    ~NonPolyWidget();
    int id() const;

private:
    int d_id;
};

// Polymorphic class whose constructor and destructor have side effects.
class PolyWidget {
public:
    explicit PolyWidget(int id);
    virtual ~PolyWidget();

    // Returns a fixed value independent of constructor state, so a test can
    // confirm the real method (and vtable) survived even when the constructor
    // was dummied.
    virtual int value() const;

private:
    int d_id;
};

// A member type with no default constructor.
class Dependency {
public:
    explicit Dependency(int value);
    int value() const;

private:
    int d_value;
};

// Class with a non-default-constructible member. An empty dummy body cannot
// initialize d_dep, so this class must be dummied with the _WITH_INIT variant
// that supplies a member-initializer list.
class WidgetWithDependency {
public:
    explicit WidgetWithDependency(int id);
    ~WidgetWithDependency();
    int dependencyValue() const;

private:
    Dependency d_dep;
};

// A member type whose constructor takes more than one parameter. Used to check
// that a member-initializer entry containing its own comma (e.g. d_dep(id, 50))
// survives the _WITH_INIT variant's __VA_ARGS__ passthrough.
class MultiArgDependency {
public:
    MultiArgDependency(int first, int second);
    int value() const;

private:
    int d_value;
};

// Class with a single multi-argument member. Dummied with a member-initializer
// list entry that itself contains a comma.
class WidgetWithMultiArgMember {
public:
    explicit WidgetWithMultiArgMember(int id);
    ~WidgetWithMultiArgMember();
    int dependencyValue() const;

private:
    MultiArgDependency d_dep;
};

// Class with two non-default-constructible members. Dummying it requires two
// member-initializer entries separated by a top-level comma, checking that the
// comma between entries survives __VA_ARGS__.
class WidgetWithTwoMembers {
public:
    explicit WidgetWithTwoMembers(int id);
    ~WidgetWithTwoMembers();
    int firstValue() const;
    int secondValue() const;

private:
    Dependency d_dep1;
    Dependency d_dep2;
};

// Class mixing a multi-argument member and a single-argument member, and a
// constructor that itself takes multiple parameters. Exercises both comma
// cases at once: a comma inside one entry and a comma between entries.
class WidgetWithMixedMembers {
public:
    WidgetWithMixedMembers(int first, int second);
    ~WidgetWithMixedMembers();
    int firstValue() const;
    int secondValue() const;

private:
    MultiArgDependency d_dep1;
    Dependency d_dep2;
};

} // namespace sample_side_effect_lib

#endif
