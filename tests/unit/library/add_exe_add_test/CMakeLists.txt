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

find_package(BonoboMockHelper REQUIRED)
file(GLOB BONOBOMOCK_UNIT_TEST_FILES "${CMAKE_CURRENT_SOURCE_DIR}/../src/*t.cpp")
add_bonobomock_executable(
    TARGET_NAME add_test.u.t TEST_FILES ${BONOBOMOCK_UNIT_TEST_FILES}
    ${CMAKE_CURRENT_SOURCE_DIR}/../../sample_functions/sample_functions.cpp
    ALLOW_CONSTRUCTOR_DUMMIES)

set_target_properties(add_test.u.t PROPERTIES COMPILE_WARNING_AS_ERROR ON)
if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    target_compile_options(add_test.u.t PRIVATE -Wall -Wextra)
endif()

target_include_directories(add_test.u.t PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}
                                                ${CMAKE_CURRENT_SOURCE_DIR}/../../sample_functions)

target_link_libraries(add_test.u.t PRIVATE GTest::gtest_main bonobomock
                                           bonobomock-optimization-macros sample_side_effect_lib)

add_test(NAME add_test.u.t COMMAND add_test.u.t)
