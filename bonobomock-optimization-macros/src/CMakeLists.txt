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

add_library(bonobomock-optimization-macros STATIC bonobomock_optimization_macros_api.cpp)

# Warnings-as-error + per-compiler warning set (defined in cmake/BonoboMockLibrary.cmake).
bonobomock_set_warnings(bonobomock-optimization-macros)

target_link_libraries(bonobomock-optimization-macros PUBLIC bsl)

set_target_properties(bonobomock-optimization-macros PROPERTIES POSITION_INDEPENDENT_CODE ON)

# Install the archive + CMake export, headers (incl. their include dirs),
# pkg-config, and CPS metadata.
bonobomock_install_dev_package(
    bonobomock-optimization-macros
    TYPE archive
    DESCRIPTION "Macros to disable function optimization for BONOBOMOCK library"
    COMPONENT libbonobomock-optimization-macros-dev
    CPS_REQUIRES_NON_NAMESPACED bsl)
