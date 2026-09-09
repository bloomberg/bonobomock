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

cmake_minimum_required(VERSION 4.0)
project(bonobomock LANGUAGES C CXX)

include(GNUInstallDirs)

# Helper functions for building/packaging the bonobomock libraries
# (bonobomock_enable_private_mocking, bonobomock_install_dev_package, ...).
include(cmake/BonoboMockLibrary.cmake)

find_package(bsl REQUIRED)
find_package(bdl REQUIRED)
find_package(GTest REQUIRED)

enable_testing()

# The BonoboMock libraries.
add_subdirectory(bonobomock)
add_subdirectory(bonobomock-optimization-macros)
add_subdirectory(cmake-bonobomock-helper)

# Help CMake find the BonoboMockHelper module, will later be used in tests
# https://cmake.org/cmake/help/latest/variable/CMAKE_PREFIX_PATH.html
list(APPEND CMAKE_PREFIX_PATH "${PROJECT_SOURCE_DIR}/cmake-bonobomock-helper/BonoboMockHelper")

add_subdirectory(tests)

# Install the CMake package config (bonobomockConfig.cmake + bonobomockTargets.cmake)
# that find_package(bonobomock) loads.  Must come after the add_subdirectory() calls
# above, once every bonobomock library has registered into the bonobomockTargets export set.
bonobomock_install_cmake_package_config()
