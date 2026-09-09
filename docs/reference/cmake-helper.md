# CMake Helper Reference

Reference documentation for `cmake-bonobomock-helper`. This CMake module defines a function that creates (or configures) a test target for use with BonoboMock. It sets up the required compiler flags for GCC, Clang, and Oracle Studio (SunPro) compilers. It also allows specifying tests that should only run in non-production builds (see `NON_PROD_ONLY_TEST_FILES`) and source files that need to be recompiled for `bonobomock-optimization-macros` to take effect (see `FILES_TO_RECOMPILE`).

## Adding the dependency

See [Project Setup](../project-setup/index.md) for how to add `cmake-bonobomock-helper` to your project.

## `add_bonobomock_executable`

```cmake
find_package(BonoboMockHelper REQUIRED)
add_bonobomock_executable(
      TARGET_NAME target_name
      TEST_FILES test_file1 [test_file2...]
      [NON_PROD_ONLY_TEST_FILES non_prod_test_file1 [non_prod_test_file2...]]
      [FILES_TO_RECOMPILE file_to_recompile1 [file_to_recompile2...]]
      [ALLOW_CONSTRUCTOR_DUMMIES]
)
```

### Parameters

| Parameter | Required | Description |
|-----------|----------|-------------|
| `TARGET_NAME` | Yes | Name of the target. Creates a new executable target with this name, or configures an existing target if one already exists. |
| `TEST_FILES` | Yes | List of test source files to include in the target. Included in all build types. Cannot be empty. |
| `NON_PROD_ONLY_TEST_FILES` | No | Test source files to include only in non-production builds (e.g., CMake build type `Debug`). These files are excluded from optimized builds (e.g., CMake build type `RelWithDebInfo`). Use this when a test cannot work in an optimized build because the function under test gets inlined even after applying optimization macros, but the test works correctly in non-production builds where `-O0` prevents all inlining. |
| `FILES_TO_RECOMPILE` | No | Source files (from the library under test) that use `bonobomock-optimization-macros` and need to be recompiled with `BONOBO_MOCK_APPLY_OPTIMIZATION_RESTRICTIONS` defined. Only takes effect in optimized builds (e.g., CMake build type `RelWithDebInfo`). The recompiled object overrides the version from the linked library, allowing the optimization macros to suppress inlining for the affected functions. See [Optimization Macros Reference](optimization-macros.md) for details. |
| `ALLOW_CONSTRUCTOR_DUMMIES` | No | Option (no value). Enables the [`BONOBO_DUMMY_*`](macros.md#constructor-side-effect-suppression-link-dummying) constructor/destructor link-dummying macros by adding the linker's multiple-definition mode to the target (`-Wl,--allow-multiple-definition` on GCC/Clang, `-z muldefs` on SunPro, `/FORCE:MULTIPLE` on MSVC). This lets the empty dummy definitions in the test override the real ones from a linked library. It also defines `BONOBO_MOCK_ALLOW_CONSTRUCTOR_DUMMIES` so that using a `BONOBO_DUMMY_*` macro without this option is a clear compile error rather than a cryptic multiple-definition link failure. It weakens duplicate-symbol detection for this target, so enable it only on targets that use the `BONOBO_DUMMY_*` macros. |

> **Note:** If you have no non-production-only tests, omit the `NON_PROD_ONLY_TEST_FILES` parameter entirely. If you have no files to recompile, omit `FILES_TO_RECOMPILE` entirely. Passing either keyword with no files is an error.

## Usage with `add_test()`

`add_test()` can have better performance than `gtest_discover_tests()` but groups all tests together, which can make it harder to run or filter individual test cases.

```cmake
find_package(BonoboMockHelper REQUIRED)
add_bonobomock_executable(
    TARGET_NAME my_test.u.t
    TEST_FILES test1.t.cpp test2.t.cpp
)

target_link_libraries(my_test.u.t PRIVATE bonobomock)

add_test(NAME my_test.u.t COMMAND my_test.u.t)
```

## Usage with `gtest_discover_tests()`

`gtest_discover_tests()` registers each GoogleTest test case individually with CTest, which gives better per-test filtering and reporting.

```cmake
find_package(BonoboMockHelper REQUIRED)
add_bonobomock_executable(
    TARGET_NAME my_test.u.t
    TEST_FILES test1.t.cpp test2.t.cpp
)

target_link_libraries(my_test.u.t PRIVATE bonobomock)

include(GoogleTest)
gtest_discover_tests(my_test.u.t)
```

## Examples

### Basic usage

Three test files, no special parameters:

```cmake
find_package(BonoboMockHelper REQUIRED)
add_bonobomock_executable(
    TARGET_NAME my_test.u.t
    TEST_FILES test1.t.cpp test2.t.cpp test3.t.cpp
)

target_link_libraries(my_test.u.t PRIVATE bonobomock)
```

### With `NON_PROD_ONLY_TEST_FILES`

`non_prod_test.t.cpp` mocks a function that gets inlined in optimized builds (e.g., CMake build type `RelWithDebInfo`) even with optimization macros applied. The test is excluded from optimized builds and runs only in non-production builds (e.g., CMake build type `Debug`):

```cmake
find_package(BonoboMockHelper REQUIRED)
add_bonobomock_executable(
    TARGET_NAME my_test.u.t
    TEST_FILES
        test1.t.cpp
        test2.t.cpp
        test3.t.cpp
    NON_PROD_ONLY_TEST_FILES
        non_prod_test.t.cpp
)

target_link_libraries(my_test.u.t PRIVATE bonobomock)
```

### With `FILES_TO_RECOMPILE`

`src/source_file.cpp` uses `bonobomock-optimization-macros` to prevent inlining of a function. It must be recompiled as part of the test target for the macros to take effect in optimized builds (e.g., CMake build type `RelWithDebInfo`):

```cmake
find_package(BonoboMockHelper REQUIRED)
add_bonobomock_executable(
    TARGET_NAME my_test.u.t
    TEST_FILES
        test1.t.cpp
        test2.t.cpp
        test3.t.cpp
    FILES_TO_RECOMPILE
        ${PROJECT_SOURCE_DIR}/src/source_file.cpp
)

target_link_libraries(my_test.u.t PRIVATE bonobomock)
```

## References

- [Optimization Macros](optimization-macros.md)
- [Limitations: Function inlining](limitations.md#function-inlining)

---
[← Back to Documentation Home](../index.md)
