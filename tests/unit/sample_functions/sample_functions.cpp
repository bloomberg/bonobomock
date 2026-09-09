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

#include "sample_functions.h"

#include <bsls_compilerfeatures.h>

namespace sample_functions {

bool sample_function()
{
    volatile bool result = false;
    return result;
}

int sample_function_2(int, int)
{
    volatile int result = 0;
    return result;
}

int sample_function_3(bsl::string&)
{
    volatile int result = 0;
    return result;
}

#ifdef BSLS_COMPILERFEATURES_FULL_CPP11
int sample_function_4(bsl::string&&)
{
    volatile int result = 0;
    return result;
}
#endif

int foo(int& a, int* b, int c)
{
    int result = a + *b + c;
    a = *b;
    *b = c;
    return result;
}

#ifdef BSLS_COMPILERFEATURES_FULL_CPP11
bsl::string makeFooStr()
{
    return "foo";
}

bsl::string makeBarStr()
{
    return "bar";
}
#endif

} // namespace sample_functions
