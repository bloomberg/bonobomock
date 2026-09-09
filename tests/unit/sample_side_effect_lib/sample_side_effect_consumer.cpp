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

// Code that constructs the widgets. This is a separate translation unit from
// their constructor/destructor definitions (sample_side_effect_lib.cpp): it
// sees only the class declarations, so the compiler cannot inline the
// constructor bodies here and must emit a real call to the constructor symbol.
// That call is what the BONOBO_DUMMY_* link-dummy definitions redirect. This mirrors
// the real use case, where the code under test constructs an object from a
// dependency library it only has headers for.

#include <sample_side_effect_consumer.h>

#include <sample_side_effect_lib.h>

namespace sample_side_effect_lib {

void constructNonPolyWidget(int id)
{
    NonPolyWidget widget(id);
    (void)widget;
}

int constructPolyWidgetAndGetValue(int id)
{
    PolyWidget widget(id);
    return widget.value();
}

int constructWidgetWithDependencyAndGetValue(int id)
{
    WidgetWithDependency widget(id);
    return widget.dependencyValue();
}

int constructWidgetWithMultiArgMemberAndGetValue(int id)
{
    WidgetWithMultiArgMember widget(id);
    return widget.dependencyValue();
}

int constructWidgetWithTwoMembersAndGetSum(int id)
{
    WidgetWithTwoMembers widget(id);
    return widget.firstValue() + widget.secondValue();
}

int constructWidgetWithMixedMembersAndGetSum(int first, int second)
{
    WidgetWithMixedMembers widget(first, second);
    return widget.firstValue() + widget.secondValue();
}

} // namespace sample_side_effect_lib
