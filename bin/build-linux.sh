#!/usr/bin/env bash

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

# This script builds BonoboMock and its dependencies from public sources.It is
# developed and tested on Ubuntu and RHEL 9, but is distro-agnostic: it
# shells out to nothing distro-specific. Install the prerequisites with whatever
# package manager your distribution uses; the script only checks that the tools
# are present on PATH.
#
# BonoboMock depends on two external libraries, both built here from public
# source into the install prefix:
#   * BDE (bsl, bdl) -- Bloomberg's open-source foundation libraries, built via
#     the bde-tools build system (bbs_build).
#   * GoogleTest (gmock/gtest) -- the mocking/assertion framework BonoboMock
#     plugs into.
#
# Neither is taken from the distribution's packages: a distro-shipped GoogleTest
# is whatever vintage that release froze on, which can be far older than the
# compiler and the rest of the toolchain it has to agree with.
#
# See docs/project-setup/cmake.md for details.

set -euo pipefail

# :: Parse and validate arguments :::::::::::::::::::::::::::::::::::::::::::::
print_usage_and_exit_with_error() {
    echo "Usage:   $0 [-s|--cxx-standard STD] [--deps-only]"
    echo "  -s|--cxx-standard STD   C++ standard to build against (default: 17)."
    echo "                          One of: 14, 17, 20, 23."
    echo "  --deps-only             Build and install BDE, then stop."
    exit 1
}
command -v getopt >/dev/null 2>&1 || {
    echo "Error: 'getopt' not found on PATH (Linux util-linux package)." >&2
    exit 1
}
VALID_ARGS=$(getopt -o s: --long cxx-standard:,deps-only -- "$@") || print_usage_and_exit_with_error
eval "set -- ${VALID_ARGS}"

CXX_STANDARD=17
DEPS_ONLY=false
while [[ "$#" -gt 0 ]]; do
    case "$1" in
    -s | --cxx-standard)
        CXX_STANDARD="$2"
        shift 2
        ;;
    --deps-only)
        DEPS_ONLY=true
        shift
        ;;
    --)
        shift
        break
        ;;
    *)
        print_usage_and_exit_with_error
        ;;
    esac
done

if [[ "$#" -ne 0 ]]; then
    echo "Unexpected argument(s): $*"
    print_usage_and_exit_with_error
fi

# C++03 and C++11 are deliberately excluded: GoogleTest 1.13 and newer require
# C++14, and older GoogleTest is not what this script builds.
case "${CXX_STANDARD}" in
14 | 17 | 20 | 23) ;;
*)
    echo "Invalid C++ standard '${CXX_STANDARD}' provided."
    print_usage_and_exit_with_error
    ;;
esac

# :: Ensure we are run from the repository root ::::::::::::::::::::::::::::::
script_path="bin/$(basename "$0")"

if [[ ! -f "${script_path}" ]] || [[ "$(realpath "$0")" != "$(realpath "${script_path}")" ]]; then
    echo 'This script must be run from the root of the BonoboMock repository.'
    exit 1
fi

# :: Compiler selection :::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# Pin the BonoboMock build to GCC. bde-tools' gcc-default toolchain is
# "compiler-less" and "bbs_build_env unset" clears CC/CXX after the BDE build,
# so without this the BonoboMock configure would fall back to whatever CMake's
# default c++ detection happens to find. Override by setting CC/CXX in the env.
CC_BIN="${CC:-gcc}"
CXX_BIN="${CXX:-g++}"

# :: Verify prerequisites :::::::::::::::::::::::::::::::::::::::::::::::::::::::
# Fail early with a clear, actionable message if a required build tool is
# missing, rather than deep into the (multi-minute) dependency build.
missing_tools=()
for tool in git cmake pkg-config python3 "${CC_BIN}" "${CXX_BIN}"; do
    command -v "${tool}" >/dev/null 2>&1 || missing_tools+=("${tool}")
done
# Some distributions install the Ninja executable as `ninja-build`; CMake's
# -G Ninja generator accepts either, so neither name should fail this check.
command -v ninja >/dev/null 2>&1 || command -v ninja-build >/dev/null 2>&1 \
    || missing_tools+=("ninja/ninja-build")
if [[ "${#missing_tools[@]}" -ne 0 ]]; then
    cat >&2 <<EOF
Error: missing required build tool(s): ${missing_tools[*]}

Install them with your distribution's package manager. You need a C/C++
compiler, CMake (>= 4.0), Ninja, pkg-config, git and Python 3 (used by BDE's
bbs_build).

On Ubuntu (22.04 or newer):

  sudo apt update && sudo apt -y install ca-certificates
  sudo apt install -y --no-install-recommends \\
      build-essential cmake ninja-build pkg-config git python3

On RHEL/Fedora the equivalents are gcc-c++, cmake, ninja-build,
pkgconf-pkg-config, git and python3.
EOF
    exit 1
fi

# :: Set some initial constants :::::::::::::::::::::::::::::::::::::::::::::::
DIR_ROOT="$(pwd)"

# Directories can be overridden via the environment (useful for CI / testing an
# out-of-tree build). By default everything lands under the repository root.
DIR_THIRDPARTY="${DIR_THIRDPARTY:-${DIR_ROOT}/thirdparty}"
mkdir -p "${DIR_THIRDPARTY}"

DIR_BUILD="${DIR_BUILD:-${DIR_ROOT}/build}"
mkdir -p "${DIR_BUILD}"

DIR_INSTALL="${DIR_INSTALL:-${DIR_ROOT}/install}"
mkdir -p "${DIR_INSTALL}"

# Parallelism for the (large) dependency and library builds. Override via JOBS
# in the environment, e.g. to cap memory use on a small machine.
JOBS="${JOBS:-$(nproc)}"

# BDE build configuration. The "unified flag id" (UFID) selects an optimized
# 64-bit build for the requested C++ standard.
BDE_TAG="4.39.0.0"
UFID="opt_64_cpp${CXX_STANDARD}"

# GoogleTest 1.17 and later require C++17 to compile, so a C++14 build has to
# stay on the last release that still builds under C++14.
if [[ "${CXX_STANDARD}" -eq 14 ]]; then
    GTEST_TAG="v1.16.0"
else
    GTEST_TAG="v1.18.0"
fi

# :: Clone dependencies :::::::::::::::::::::::::::::::::::::::::::::::::::::::
# bde-tools provides the BDE build system (bbs_build) and CMake toolchain files.
# bde provides the bsl/bdl libraries that BonoboMock links against.
#
# Clone into a temporary ".tmp" path and rename into place only on success, so
# that an interrupted clone (Ctrl-C, dropped network) is not mistaken for a
# complete checkout on the next run.
clone_dependency() {
    local dest="$1"
    local url="$2"
    local tag="$3"
    if [[ -d "${dest}" ]]; then
        # An existing checkout is reused as-is, so warn loudly when it does not
        # match the pinned tag -- otherwise a bump silently builds old sources.
        local want have
        want="$(git -C "${dest}" rev-parse --verify --quiet "${tag}^{commit}" 2>/dev/null || true)"
        have="$(git -C "${dest}" rev-parse --verify --quiet HEAD 2>/dev/null || true)"
        if [[ -z "${have}" ]] || [[ "${have}" != "${want}" ]]; then
            echo "warning: ${dest} is not at ${tag}; delete it to refetch." >&2
        fi
        return
    fi
    rm -rf "${dest}.tmp"
    git clone --depth 1 --branch "${tag}" "${url}" "${dest}.tmp"
    mv "${dest}.tmp" "${dest}"
}
clone_dependency "${DIR_THIRDPARTY}/bde-tools"   https://github.com/bloomberg/bde-tools    "${BDE_TAG}"
clone_dependency "${DIR_THIRDPARTY}/bde"         https://github.com/bloomberg/bde.git      "${BDE_TAG}"
clone_dependency "${DIR_THIRDPARTY}/googletest"  https://github.com/google/googletest.git  "${GTEST_TAG}"

# :: Build and install BDE ::::::::::::::::::::::::::::::::::::::::::::::::::::
# Refer to https://bloomberg.github.io/bde/library_information/build.html
PATH="${DIR_THIRDPARTY}/bde-tools/bin:${PATH}"

# The completion sentinel is keyed to the tag and the UFID so that bumping
# BDE_TAG or switching --cxx-standard forces a fresh BDE build/install rather
# than silently reusing an install built from different sources or for a
# different C++ standard (which would be an ABI/standard mismatch).
BDE_SENTINEL="${DIR_BUILD}/bde/.complete-${BDE_TAG}-${UFID}"
if [[ ! -e "${BDE_SENTINEL}" ]]; then
    (
        cd "${DIR_THIRDPARTY}/bde"
        eval "$(bbs_build_env -u "${UFID}" -b "${DIR_BUILD}/bde" -i "${DIR_INSTALL}")"
        bbs_build configure --prefix="${DIR_INSTALL}"
        bbs_build build --prefix="${DIR_INSTALL}" -j "${JOBS}"
        bbs_build install --install_dir="/" --prefix="${DIR_INSTALL}"
        eval "$(bbs_build_env unset)"
    )
    touch "${BDE_SENTINEL}"
fi

# bbs_build installs BDE's CMake config packages under "lib64/cmake/". CMake on
# Debian/Ubuntu does not search "<prefix>/lib64/cmake" by default (only "lib/"
# and the multiarch "lib/<arch>/"). The BonoboMock configure below names lib64
# explicitly in CMAKE_PREFIX_PATH; the symlink is for downstream consumers that
# point only at the prefix (see docs/project-setup/cmake.md).
if [[ -d "${DIR_INSTALL}/lib64" ]] && [[ ! -e "${DIR_INSTALL}/lib" ]]; then
    ln -s lib64 "${DIR_INSTALL}/lib"
fi

# :: Build and install GoogleTest :::::::::::::::::::::::::::::::::::::::::::::
# Built after BDE so that the lib -> lib64 symlink above already exists and both
# libraries land in the same directory regardless of the distro's libdir naming.
# The sentinel is keyed to the tag and the C++ standard for the same reason BDE's
# is: switching either has to force a rebuild rather than reuse a mismatched one.
GTEST_SENTINEL="${DIR_BUILD}/googletest/.complete-${GTEST_TAG}-cpp${CXX_STANDARD}"
if [[ ! -e "${GTEST_SENTINEL}" ]]; then
    cmake -S "${DIR_THIRDPARTY}/googletest" -B "${DIR_BUILD}/googletest" -G Ninja \
        -DCMAKE_C_COMPILER="${CC_BIN}" \
        -DCMAKE_CXX_COMPILER="${CXX_BIN}" \
        -DCMAKE_CXX_STANDARD="${CXX_STANDARD}" \
        -DCMAKE_BUILD_TYPE=RelWithDebInfo \
        -DCMAKE_POSITION_INDEPENDENT_CODE=ON \
        -DCMAKE_INSTALL_PREFIX="${DIR_INSTALL}"
    cmake --build "${DIR_BUILD}/googletest" --parallel "${JOBS}"
    cmake --install "${DIR_BUILD}/googletest"
    touch "${GTEST_SENTINEL}"
fi

if [[ "${DEPS_ONLY}" = true ]]; then
    echo "BDE and GoogleTest installed into ${DIR_INSTALL}; stopping (--deps-only)."
    exit 0
fi

# :: Build and test BonoboMock ::::::::::::::::::::::::::::::::::::::::::::::::
# We build with the bde-tools toolchain so that BonoboMock is compiled with the
# same flags/ABI as BDE, and point CMAKE_PREFIX_PATH at our install prefix so that
# find_package(bsl/bdl) and find_package(GTest) all resolve to the libraries we
# just built rather than to anything preinstalled on the system.
cmake -B "${DIR_BUILD}/bonobomock" -S "${DIR_ROOT}" -G Ninja \
    -DCMAKE_TOOLCHAIN_FILE="${DIR_THIRDPARTY}/bde-tools/BdeBuildSystem/toolchains/linux/gcc-default.cmake" \
    -DCMAKE_C_COMPILER="${CC_BIN}" \
    -DCMAKE_CXX_COMPILER="${CXX_BIN}" \
    -DCMAKE_CXX_STANDARD="${CXX_STANDARD}" \
    -DCMAKE_BUILD_TYPE=RelWithDebInfo \
    -DCMAKE_PREFIX_PATH="${DIR_INSTALL};${DIR_INSTALL}/lib64" \
    -DCMAKE_INSTALL_PREFIX="${DIR_INSTALL}"

cmake --build "${DIR_BUILD}/bonobomock" --parallel "${JOBS}"

# :: Run the test suite :::::::::::::::::::::::::::::::::::::::::::::::::::::::
ctest --test-dir "${DIR_BUILD}/bonobomock" --output-on-failure

echo
echo "BonoboMock built successfully."
echo "  library:      ${DIR_BUILD}/bonobomock/bonobomock/src/libbonobomock.a"
echo "  install with: cmake --install ${DIR_BUILD}/bonobomock"
