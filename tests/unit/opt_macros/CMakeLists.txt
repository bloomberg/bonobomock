# SPDX-License-Identifier: Apache-2.0
#
# Copyright 2025 Bloomberg Finance LP
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

# BONOBOMOCK optimization macros define compiler-specific pre-processor commands
# or function attributes to disable function optimization. The macros are expected
# to expand to nothing when BONOBO_MOCK_APPLY_OPTIMIZATION_RESTRICTIONS is not defined
# and to the appropriate compiler-specific commands/attributes when
# BONOBO_MOCK_APPLY_OPTIMIZATION_RESTRICTIONS is defined.
# The goal of the unit tests in this folder is to test 2 scenarios:
# 1.  Source code contains optimization macros but the optimization macros ARE NOT enabled.
#     We expect the function for which the optimization macros are applied to NOT produce any warnings for any of the compilers.
# 2.  Source code contains optimization macros and the optimization macros ARE enabled.
#     We expect the macros to be defined now but still NOT produce any warnings or errors (e.g. about an unsupported compiler flag/attribute).
# The two targets below implement these two scenarios.

# Function to treat warnings as errors on target @param target_name
function(target_treat_warnings_as_errors target_name)
    set_target_properties(${target_name} PROPERTIES COMPILE_WARNING_AS_ERROR ON)

    # Enable additional warnings specific to GCC and Clang
    if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
        target_compile_options(${target_name} PRIVATE -Wall -Wextra)
    endif()
endfunction()

# Set up a test for the first scenario: optimization macros not enabled, expect no warnings/errors
add_executable(optmacros_disabled.u.t bonobomock_optimization_macros_api.t.cpp)
target_treat_warnings_as_errors(optmacros_disabled.u.t)

target_include_directories(optmacros_disabled.u.t PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(optmacros_disabled.u.t PRIVATE GTest::gtest_main
                                                     bonobomock-optimization-macros)
add_test(NAME optmacros_disabled.u.t COMMAND optmacros_disabled.u.t)

# Set up a test for the second scenario: optimization macros ARE enabled, expect no warnings/errors
add_executable(
    optmacros_enabled.u.t
    bonobomock_optimization_macros_api.t.cpp
    # need to provide as a path so that the file is recompiled with the BONOBO_MOCK_APPLY_OPTIMIZATION_RESTRICTIONS flag/definition
    ${PROJECT_SOURCE_DIR}/bonobomock-optimization-macros/src/bonobomock_optimization_macros_api.cpp)

# Supply the definition to enable the optimization macros
target_compile_definitions(optmacros_enabled.u.t PUBLIC BONOBO_MOCK_APPLY_OPTIMIZATION_RESTRICTIONS)

target_treat_warnings_as_errors(optmacros_enabled.u.t)

target_include_directories(optmacros_enabled.u.t PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(optmacros_enabled.u.t PRIVATE GTest::gtest_main
                                                    bonobomock-optimization-macros)
add_test(NAME optmacros_enabled.u.t COMMAND optmacros_enabled.u.t)
