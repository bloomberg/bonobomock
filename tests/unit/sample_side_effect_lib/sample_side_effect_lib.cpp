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

#include <sample_side_effect_lib.h>

namespace sample_side_effect_lib {

int& sideEffectCounter()
{
    static int counter = 0;
    return counter;
}

NonPolyWidget::NonPolyWidget(int id)
    : d_id(id)
{
    ++sideEffectCounter();
}

NonPolyWidget::~NonPolyWidget()
{
    ++sideEffectCounter();
}

int NonPolyWidget::id() const
{
    return d_id;
}

PolyWidget::PolyWidget(int id)
    : d_id(id)
{
    ++sideEffectCounter();
}

PolyWidget::~PolyWidget()
{
    ++sideEffectCounter();
}

int PolyWidget::value() const
{
    return 42;
}

Dependency::Dependency(int value)
    : d_value(value)
{
}

int Dependency::value() const
{
    return d_value;
}

WidgetWithDependency::WidgetWithDependency(int id)
    : d_dep(id)
{
    ++sideEffectCounter();
}

WidgetWithDependency::~WidgetWithDependency()
{
    ++sideEffectCounter();
}

int WidgetWithDependency::dependencyValue() const
{
    return d_dep.value();
}

MultiArgDependency::MultiArgDependency(int first, int second)
    : d_value(first + second)
{
}

int MultiArgDependency::value() const
{
    return d_value;
}

// Real member inits differ from the dummies used in the tests, so a matching
// result confirms the dummy's member-initializer list ran, not the real one.
WidgetWithMultiArgMember::WidgetWithMultiArgMember(int id)
    : d_dep(id, 100)
{
    ++sideEffectCounter();
}

WidgetWithMultiArgMember::~WidgetWithMultiArgMember()
{
    ++sideEffectCounter();
}

int WidgetWithMultiArgMember::dependencyValue() const
{
    return d_dep.value();
}

WidgetWithTwoMembers::WidgetWithTwoMembers(int id)
    : d_dep1(id + 1000)
    , d_dep2(id + 2000)
{
    ++sideEffectCounter();
}

WidgetWithTwoMembers::~WidgetWithTwoMembers()
{
    ++sideEffectCounter();
}

int WidgetWithTwoMembers::firstValue() const
{
    return d_dep1.value();
}

int WidgetWithTwoMembers::secondValue() const
{
    return d_dep2.value();
}

WidgetWithMixedMembers::WidgetWithMixedMembers(int first, int second)
    : d_dep1(first + 1000, second)
    , d_dep2(second + 2000)
{
    ++sideEffectCounter();
}

WidgetWithMixedMembers::~WidgetWithMixedMembers()
{
    ++sideEffectCounter();
}

int WidgetWithMixedMembers::firstValue() const
{
    return d_dep1.value();
}

int WidgetWithMixedMembers::secondValue() const
{
    return d_dep2.value();
}

} // namespace sample_side_effect_lib
