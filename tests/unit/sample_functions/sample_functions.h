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

#ifndef INCLUDED_BONOBOMOCK_SAMPLE_FUNCTIONS
#define INCLUDED_BONOBOMOCK_SAMPLE_FUNCTIONS

#include <bsl_string.h>
#include <bsls_compilerfeatures.h>

#include <bonobomock_optimization_macros_api.h>

// Sample free functions used by global_function tests.  Defined in a separate
// translation unit so the compiler cannot apply intra-TU constant propagation
// when the test calls them.
namespace sample_functions {

bool sample_function();
int sample_function_2(int, int);
int sample_function_3(bsl::string&);

#ifdef BSLS_COMPILERFEATURES_FULL_CPP11
int sample_function_4(bsl::string&&);

// Template must be defined in the header; the TU boundary protects the
// non-template overloads, and the template body is non-trivial enough that
// constant-propagation across the call is not a concern.
template <typename T>
BONOBO_MOCK_DISABLE_FUNCTION_OPTIMIZATION_START(sample_function_5)
int sample_function_5(T&&)
{
    volatile int result = 0;
    return result;
}
BONOBO_MOCK_DISABLE_FUNCTION_OPTIMIZATION_END(sample_function_5)
#endif

int foo(int& a, int* b, int c);

#ifdef BSLS_COMPILERFEATURES_FULL_CPP11
bsl::string makeFooStr();
bsl::string makeBarStr();
#endif

} // namespace sample_functions

#endif
