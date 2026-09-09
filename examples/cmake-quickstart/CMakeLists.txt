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

# Matches the floor BonoboMock itself builds with. A consumer may well work with
# an older CMake, but nothing verifies that, so this declares only what is tested.
cmake_minimum_required(VERSION 4.0)
project(bonobomock-quickstart LANGUAGES CXX)

# Provides bonobomock::bonobomock, and pulls in bsl and bdl transitively.
find_package(bonobomock REQUIRED)

# Found explicitly rather than relied on transitively, because tests/CMakeLists.txt
# names GTest::gtest_main.
find_package(GTest REQUIRED)

# BonoboMockHelper provides add_bonobomock_executable(), which creates a test
# target and sets the per-compiler flags BonoboMock needs to reliably intercept
# calls (e.g. -fno-inline on GCC/Clang). Always use it for targets that use
# BonoboMock.
find_package(BonoboMockHelper REQUIRED)

enable_testing()

add_subdirectory(src)
add_subdirectory(tests)
