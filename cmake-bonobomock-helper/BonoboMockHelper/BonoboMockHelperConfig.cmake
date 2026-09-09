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

# Ensure this file is not included multiple times
include_guard()

# A function that creates a target (or uses an existing one with the specified name) to run tests that use BONOBOMOCK.
# It sets up the compiler flags for GCC, Clang, and SunPro compilers required to use BONOBOMOCK.
# Users will need to add add_test() or gtest_discover_tests() themselves.
function(add_bonobomock_executable)
    # Parse arguments
    # https://cmake.org/cmake/help/latest/command/cmake_parse_arguments.html
    set(options ALLOW_CONSTRUCTOR_DUMMIES)
    set(oneValueArgs TARGET_NAME)
    set(multiValueArgs TEST_FILES NON_PROD_ONLY_TEST_FILES FILES_TO_RECOMPILE)
    cmake_parse_arguments(FUNC_ARGS "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

    # Check that both TARGET_NAME and TEST_FILES are provided
    # If either paramter is not specified, the function will fail and exit CMake processing
    if((NOT DEFINED FUNC_ARGS_TARGET_NAME)
       OR (NOT DEFINED FUNC_ARGS_TEST_FILES)
       OR (FUNC_ARGS_KEYWORDS_MISSING_VALUES MATCHES "TARGET_NAME")
       OR ((FUNC_ARGS_KEYWORDS_MISSING_VALUES MATCHES "TEST_FILES")
           AND (NOT (FUNC_ARGS_KEYWORDS_MISSING_VALUES MATCHES "NON_PROD_ONLY_TEST_FILES"))))
        message(FATAL_ERROR "TARGET_NAME and TEST_FILES are required parameters")
    endif()

    # If NON_PROD_ONLY_TEST_FILES is in the function call but no files are provided, ask the developer to remove it
    if((FUNC_ARGS_KEYWORDS_MISSING_VALUES MATCHES "NON_PROD_ONLY_TEST_FILES"))
        message(
            WARNING
                "Please remove NON_PROD_ONLY_TEST_FILES from the function parameters if you do not intend to have any tests that should run only in non-production builds"
        )
    endif()

    # If FILES_TO_RECOMPILE is in the function call but no files are provided, ask the developer to remove it
    if((FUNC_ARGS_KEYWORDS_MISSING_VALUES MATCHES "FILES_TO_RECOMPILE"))
        message(
            WARNING
                "Please remove FILES_TO_RECOMPILE from the function parameters if you do not intend to recompile any source files for BONOBOMOCK optimization macros to take effect"
        )
    endif()

    # Create target with the specified name if there is no target
    if(TARGET ${FUNC_ARGS_TARGET_NAME})
        message(
            STATUS "Configuring existing target ${FUNC_ARGS_TARGET_NAME} to run BONOBOMOCK tests.")
    else()
        add_executable(${FUNC_ARGS_TARGET_NAME})
        message(
            STATUS
                "Created and configuring an executable target ${FUNC_ARGS_TARGET_NAME} to run BONOBOMOCK tests."
        )
    endif()

    # Set the required compiler options and environment properties for the target
    # https://stackoverflow.com/questions/23995019/what-is-the-modern-method-for-setting-general-compile-flags-in-cmake
    # https://cmake.org/cmake/help/latest/command/target_compile_options.html
    if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
        # GCC: disable inlining; suppress warnings when extracting function pointer from bound pointer to member function
        # https://gcc.gnu.org/onlinedocs/gcc/Optimize-Options.html#index-fno-inline
        # https://gcc.gnu.org/onlinedocs/gcc/Bound-member-functions.html
        target_compile_options(${FUNC_ARGS_TARGET_NAME}
                               PRIVATE -fno-inline $<$<COMPILE_LANGUAGE:CXX>:-Wno-pmf-conversions>)
    elseif(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
        # Clang: disable inlining (-Wno-pmf-conversions is GCC-specific and not needed here)
        target_compile_options(${FUNC_ARGS_TARGET_NAME} PRIVATE -fno-inline)
    elseif(CMAKE_CXX_COMPILER_ID STREQUAL "SunPro")
        # Sparc no inline
        # https://docs.oracle.com/cd/E19957-01/806-3572/Rev.html
        target_compile_options(${FUNC_ARGS_TARGET_NAME} PRIVATE +d)
    elseif(MSVC)
        # MSVC: disable inline expansion for test targets.
        #
        # /Ob0 prevents the compiler from inlining functions at call sites,
        # mirroring GCC/Clang's -fno-inline.  Functions being mocked live in a
        # separate translation unit (sample_functions.cpp), so MSVC cannot see
        # their bodies and cannot apply intra-TU constant propagation to
        # eliminate the CALL instruction.  The TU boundary plus /Ob0 is
        # sufficient to ensure every mocked function generates a real CALL that
        # the binary patch can intercept.
        #
        # https://learn.microsoft.com/en-us/cpp/build/reference/ob-inline-function-expansion
        target_compile_options(${FUNC_ARGS_TARGET_NAME} PRIVATE /Ob0)
    endif()

    # Enable constructor/destructor link dummying (BONOBO_DUMMY_* macros).
    # The empty dummy definitions and the real definitions from the linked
    # library are both present, so the linker must be told to allow multiple
    # definitions; the first definition (the dummy, from the test object) wins.
    # https://sourceware.org/binutils/docs/ld/Options.html (--allow-multiple-definition)
    if(FUNC_ARGS_ALLOW_CONSTRUCTOR_DUMMIES)
        # Lets the BONOBO_DUMMY_* macros detect the opt-in and turn misuse (using a
        # dummy macro without this option) into a clear compile error rather than
        # a cryptic multiple-definition link failure.
        target_compile_definitions(${FUNC_ARGS_TARGET_NAME}
                                   PRIVATE BONOBO_MOCK_ALLOW_CONSTRUCTOR_DUMMIES)

        # MSVC is checked first because clang-cl reports CMAKE_CXX_COMPILER_ID
        # as "Clang" while also setting MSVC; it drives lld-link, which needs
        # /FORCE:MULTIPLE rather than the GNU-ld syntax.
        if(MSVC)
            target_link_options(${FUNC_ARGS_TARGET_NAME} PRIVATE /FORCE:MULTIPLE)
        elseif(CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
            target_link_options(${FUNC_ARGS_TARGET_NAME} PRIVATE -Wl,--allow-multiple-definition)
        elseif(CMAKE_CXX_COMPILER_ID STREQUAL "SunPro")
            # Solaris ld: -z muldefs allows multiple symbol definitions
            target_link_options(${FUNC_ARGS_TARGET_NAME} PRIVATE -z muldefs)
        endif()
    endif()

    # Include the test source files
    # These tests will be included/executed for all (prod and non-prod) builds
    target_sources(${FUNC_ARGS_TARGET_NAME} PRIVATE ${FUNC_ARGS_TEST_FILES})

    # Include source files into the target based on build type
    # Define BONOBO_MOCK_APPLY_OPTIMIZATION_RESTRICTIONS for RelWithDebInfo regardless of
    # generator type.  The generator expression evaluates to the definition only when
    # the active configuration is RelWithDebInfo.
    target_compile_definitions(
        ${FUNC_ARGS_TARGET_NAME}
        PUBLIC $<$<CONFIG:RelWithDebInfo>:BONOBO_MOCK_APPLY_OPTIMIZATION_RESTRICTIONS>)

    if(CMAKE_BUILD_TYPE STREQUAL "RelWithDebInfo")
        # Include the source files that need to be recompiled. These are files that use
        # bonobomock-optimization-macros to disable optimization for specific functions.
        # https://cmake.org/cmake/help/latest/command/target_sources.html
        if((FUNC_ARGS_FILES_TO_RECOMPILE) AND (NOT FUNC_ARGS_KEYWORDS_MISSING_VALUES MATCHES
                                               "FILES_TO_RECOMPILE"))
            target_sources(${FUNC_ARGS_TARGET_NAME} PRIVATE ${FUNC_ARGS_FILES_TO_RECOMPILE})
        endif()
    else()
        # For any non-prod build, include the files in FUNC_ARGS_NON_PROD_ONLY_TEST_FILES
        # These are the test files that only work in non-prod builds
        # https://cmake.org/cmake/help/latest/command/target_sources.html
        if((DEFINED FUNC_ARGS_NON_PROD_ONLY_TEST_FILES) AND (NOT FUNC_ARGS_KEYWORDS_MISSING_VALUES
                                                             MATCHES "NON_PROD_ONLY_TEST_FILES"))
            target_sources(${FUNC_ARGS_TARGET_NAME} PRIVATE ${FUNC_ARGS_NON_PROD_ONLY_TEST_FILES})
        endif()
    endif()
endfunction()
