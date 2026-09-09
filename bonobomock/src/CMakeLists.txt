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

# The bonobomock_* helpers below are defined in cmake/BonoboMockLibrary.cmake (included by
# the top-level CMakeLists.txt); each one documents the platform-specific detail
# it encapsulates.

# cmake-format: off
add_library(
    bonobomock STATIC
    # add more source files to the bonobomock build here
    bonobomock_api.cpp
    bonobomock_internal_symbol_resolver.cpp
    bonobomock_internal_process_util.cpp
    bonobomock_internal_private_address_resolver.cpp
    bonobomock_internal_patch.cpp
    bonobomock_internal_patch_trampoline.cpp)
# cmake-format: on

# Warnings-as-error + per-compiler warning set.
bonobomock_set_warnings(bonobomock)

# Compile bonobomock's own sources with -DBONOBO_MOCK_BUILDING_LIBRARY (PRIVATE, so it is
# not forwarded to consumers).  It helps discourage directly including headers
# other than bonobomock_api.h.
target_compile_definitions(bonobomock PRIVATE BONOBO_MOCK_BUILDING_LIBRARY)

target_link_libraries(bonobomock PUBLIC bsl bdl GTest::gmock)

# Enable private-function mocking: add the platform symbol resolver and give
# consumers a correct in-process demangler, collecting the extra pkg-config / CPS
# tokens they need to link it (empty except on Solaris).
bonobomock_enable_private_mocking(bonobomock BONOBOMOCK_PC_PUBLIC_LIBS
                                  BONOBOMOCK_CPS_LINK_LIBRARIES)

set_target_properties(bonobomock PROPERTIES POSITION_INDEPENDENT_CODE ON)

# Install the archive + CMake export, headers (incl. their include dirs),
# pkg-config, and CPS metadata.
bonobomock_install_dev_package(
    bonobomock
    TYPE archive
    DESCRIPTION "Bloomberg Mock Library"
    COMPONENT libbonobomock-dev
    PC_PUBLIC_LIBS "${BONOBOMOCK_PC_PUBLIC_LIBS}"
    CPS_REQUIRES GTest:gmock
    CPS_REQUIRES_NON_NAMESPACED bsl bdl
    CPS_LINK_LIBRARIES ${BONOBOMOCK_CPS_LINK_LIBRARIES})
