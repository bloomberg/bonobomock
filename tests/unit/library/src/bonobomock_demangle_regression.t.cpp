// SPDX-License-Identifier: Apache-2.0
//
// Copyright 2025 Bloomberg Finance LP
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

// Regression test for the in-process demangler used by private-function mocking.
//
// To mock a private function, bonobomock finds its address by running `nm` and
// demangling every symbol in the binary in-process with abi::__cxa_demangle
// (see bonobomock_internal_nm_util.cpp).  abi::__cxa_demangle is provided by the C++
// runtime library -- and on older systems (e.g. RHEL 7) the *shared* libstdc++
// that supplies it at runtime is ancient: its demangler recurses without bound on
// some modern-C++ symbols (std::variant / std::optional internals) and overflows
// the stack, killing the whole test process.  To avoid that, bonobomock links a
// modern __cxa_demangle straight into libbonobomock.a (see bonobomock/src/CMakeLists.txt),
// so the in-process demangler always matches the compiler and is crash-safe.
//
// This test feeds that demangler the exact std::variant symbol that used to crash
// a real downstream consumer on RHEL 7, and checks it demangles successfully
// rather than crashing.  It exercises the same abi::__cxa_demangle the library
// resolves at link time, so without the fix the test process would abort here.

#include <bonobomock_api.h>

#include <gtest/gtest.h>

// This scenario applies only where the compiler uses the Itanium C++ ABI
// (GCC/Clang), which is what provides <cxxabi.h>/abi::__cxa_demangle -- the
// demangler bonobomock's non-Windows path uses. MSVC and SunPro use a different
// demangler, so guard on bonobomock's Itanium-ABI macro.
#if BONOBO_MOCK_IS_ITANIUM_ABI

    #include <cxxabi.h>

    #include <cstdlib>
    #include <string>

namespace {

// A deeply-nested C++17 std::variant internal symbol: a std::forward of a lambda
// declared inside
// std::__detail::__variant::_Variant_storage<..., bsl::string, double, int,
// BloombergLP::bdlt::Date, bool, std::nullopt_t>::_M_reset().  The Itanium
// demangler shipped in RHEL 7's system libstdc++ recursed on this until it
// exhausted the stack (SIGSEGV).
const char* const k_deeplyNestedVariantSymbol = "_ZSt7forwardIOZNSt8__detail9__variant16_Variant_storageILb0EJN3bsl12basic_"
                                                "stringIcSt11char_traitsIcENS3_9allocatorIcEEEEdiN11BloombergLP4bdlt4DateEb"
                                                "St9nullopt_tEE8_M_resetEvEUlOT_E_ESG_RNSt16remove_referenceISF_E4typeE";

} // namespace

// Demangling the symbol must succeed (status 0, non-null result) instead of
// overflowing the stack.  The old shared-libstdc++ demangler this replaces would
// crash the process before returning.
TEST(DemanglerRegression, DemanglesDeeplyNestedVariantSymbolWithoutCrashing)
{
    int status = -1;
    char* demangled = abi::__cxa_demangle(k_deeplyNestedVariantSymbol, NULL, NULL, &status);

    ASSERT_EQ(0, status);
    ASSERT_TRUE(demangled != NULL);

    const std::string result(demangled);
    free(demangled);

    // Sanity-check the demangled text really is the intended type.
    EXPECT_NE(std::string::npos,
        result.find("std::__detail::__variant::_Variant_storage"));
}

#endif // BONOBO_MOCK_IS_ITANIUM_ABI
