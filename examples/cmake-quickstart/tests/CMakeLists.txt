# SPDX-License-Identifier: Apache-2.0
#
# Copyright 2026 Bloomberg Finance LP
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

# add_bonobomock_executable() creates the target and applies the flags
# BonoboMock needs (e.g. -fno-inline on GCC/Clang) to the sources it compiles.
add_bonobomock_executable(TARGET_NAME portfolio.t TEST_FILES portfolio.t.cpp)

if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    target_compile_options(portfolio.t PRIVATE -Wall -Wextra)
endif()

target_link_libraries(portfolio.t PRIVATE portfolio bonobomock::bonobomock GTest::gtest_main)

# Register each TEST() with CTest so `ctest` can run and filter them.
include(GoogleTest)
gtest_discover_tests(portfolio.t)
