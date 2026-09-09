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

# Below we are running BONOBOMOCK unit tests using 2 different
# configurations (the 2 different ways to use bonobomock + its CMake helper):
# 1. Using add_bonobomock_executable and add_test
# 2. Using add_bonobomock_executable and gtest_discover_tests
#
# Both configurations compile the same set of unit test source files located in "src" folder

add_subdirectory(add_exe_add_test)
add_subdirectory(add_exe_gtest_discover)
