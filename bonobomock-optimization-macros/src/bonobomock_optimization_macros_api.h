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

#ifndef INCLUDED_BONOBOMOCK_OPTIMIZATION_MACROS_API
#define INCLUDED_BONOBOMOCK_OPTIMIZATION_MACROS_API

#define BONOBO_MOCK_DO_PRAGMA(x) _Pragma(#x)

// When BONOBO_MOCK_APPLY_OPTIMIZATION_RESTRICTIONS macro is not defined, these
// optimization macros expand to nothing
// The BONOBO_MOCK_APPLY_OPTIMIZATION_RESTRICTIONS macro is defined by a function
// in BONOBOMOCK CMake Helper
#ifndef BONOBO_MOCK_APPLY_OPTIMIZATION_RESTRICTIONS
    #define BONOBO_MOCK_DISABLE_FUNCTION_OPTIMIZATION_START(func_name)
    #define BONOBO_MOCK_DISABLE_FUNCTION_OPTIMIZATION_END(func_name)
#endif

// Clang must be checked before GCC because Clang also defines __GNUC__.
// Macros specific to Clang Compiler
#if defined(BONOBO_MOCK_APPLY_OPTIMIZATION_RESTRICTIONS) && defined(__clang__)
    #define BONOBO_MOCK_DISABLE_FUNCTION_OPTIMIZATION_START(func_name) __attribute__((optnone)) __attribute__((noinline))
    #define BONOBO_MOCK_DISABLE_FUNCTION_OPTIMIZATION_END(func_name)
#endif

// Macros specific to GCC Compiler
#if defined(BONOBO_MOCK_APPLY_OPTIMIZATION_RESTRICTIONS) && defined(__GNUC__) && !defined(__clang__)
    #define BONOBO_MOCK_DISABLE_FUNCTION_OPTIMIZATION_START(func_name) __attribute__((optimize("O0"))) __attribute__((noinline))
    #define BONOBO_MOCK_DISABLE_FUNCTION_OPTIMIZATION_END(func_name)
#endif

// Macros specific to MSVC (Windows)
//
// __pragma(optimize("", off)) is a compile-unit-level directive that MSVC
// rejects inside class bodies and template contexts, so it cannot be used
// as a function attribute in a macro.  Use __declspec(noinline) instead,
// which prevents inline expansion at call sites and is valid in all
// function-declaration contexts.  Mocked functions are defined in a
// separate translation unit so MSVC cannot apply intra-TU constant
// propagation to eliminate their CALL instructions.
#if defined(BONOBO_MOCK_APPLY_OPTIMIZATION_RESTRICTIONS) && defined(_MSC_VER) && !defined(__clang__)
    #define BONOBO_MOCK_DISABLE_FUNCTION_OPTIMIZATION_START(func_name) __declspec(noinline)
    #define BONOBO_MOCK_DISABLE_FUNCTION_OPTIMIZATION_END(func_name)
#endif

// Macros specific to SunPro Compiler (Solaris)
#if defined(BONOBO_MOCK_APPLY_OPTIMIZATION_RESTRICTIONS) && defined(__SUNPRO_CC)
    #define BONOBO_MOCK_INTERNAL_GET_PRAGMA_FOR_SUNPRO(func_name) BONOBO_MOCK_DO_PRAGMA(unknown_control_flow(##func_name))
    #define BONOBO_MOCK_DISABLE_FUNCTION_OPTIMIZATION_START(func_name) __attribute__((returns_twice)) __attribute__((noinline))
    #define BONOBO_MOCK_DISABLE_FUNCTION_OPTIMIZATION_END(func_name) \
        BONOBO_MOCK_INTERNAL_GET_PRAGMA_FOR_SUNPRO(func_name)
#endif

#endif
