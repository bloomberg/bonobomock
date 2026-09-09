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

# Classes with side-effecting constructors, built as a static library so their
# real definitions live in a linked archive that the BONOBO_DUMMY_* macros override.
# The constructor/destructor definitions and the code that constructs the widgets
# live in separate translation units so the constructor calls are not inlined
# away (see sample_side_effect_consumer.cpp).
add_library(
    sample_side_effect_lib STATIC ${CMAKE_CURRENT_SOURCE_DIR}/sample_side_effect_lib.cpp
                                  ${CMAKE_CURRENT_SOURCE_DIR}/sample_side_effect_consumer.cpp)

target_include_directories(sample_side_effect_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
