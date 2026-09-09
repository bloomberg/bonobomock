# Optimization Macros Reference

Reference documentation for `bonobomock-optimization-macros`.

## What it is

`bonobomock-optimization-macros` is a utility library that provides a pair of macros (`BONOBO_MOCK_DISABLE_FUNCTION_OPTIMIZATION_START` and `BONOBO_MOCK_DISABLE_FUNCTION_OPTIMIZATION_END`) for suppressing compiler optimization on individual functions. These macros wrap a function definition and instruct the compiler not to [inline](limitations.md#function-inlining) or optimize it when building the unit test executable.

The macros are designed to take effect only for test binaries and not for the libraries/applications that are released/deployed. The macros expand to nothing unless `BONOBO_MOCK_APPLY_OPTIMIZATION_RESTRICTIONS` is defined. `BONOBO_MOCK_APPLY_OPTIMIZATION_RESTRICTIONS` is only defined in [cmake-bonobomock-helper](cmake-helper.md) which is expected to be used to set up the test target (test binary). As a result, when you use BONOBO_MOCK_DISABLE_FUNCTION_OPTIMIZATION_START/END in a source file of the original library, the source file (and the shipped library/application) are not affected by the optimization restrictions unless the source file is recompiled for the test binary, which is controlled by `FILES_TO_RECOMPILE` in the CMake helper.


## Why and when you'd need this

BonoboMock intercepts function calls by [patching machine instructions at the function's entry point](internals.md#runtime-binary-patching). This requires the function to exist as a standalone symbol in the binary — if the compiler has inlined the function, there is no entry point to patch and the mock has no effect.

In non-optimized builds (e.g., CMake build type `Debug`), the compiler does not inline functions, so BonoboMock can always find and patch them. Inlining becomes a concern in optimized builds (e.g., CMake build types `RelWithDebInfo` or `Release`), where the compiler may eliminate small or simple functions entirely.

`add_bonobomock_executable()`  applies `-fno-inline` (or equivalent) to the test target's own translation units to suppress inlining there. But when the function being mocked lives in a **separate source file** — for example, in the library under test — that flag does not reach it. The compiler compiles the library source with its normal optimization settings, which may inline the function before BonoboMock ever gets a chance to patch it.

Use the optimization macros when:

1. You write a test that mocks a function.
2. The test passes in non-optimized builds (e.g., CMake build type `Debug`) but fails in optimized builds (e.g., CMake build types `RelWithDebInfo` or `Release`).
3. The failure is because the function was inlined by the compiler and BonoboMock cannot find its entry point.

Apply the macros to the specific function in the source under test to prevent the compiler from inlining it in the test build.

## How to use it

### When you own the function's source

If you can modify the source file where the function is defined, apply the macros directly to the function definition. This is the preferred approach.

#### 1. Add the dependency

See [Project Setup](../project-setup/index.md) for how to add `bonobomock-optimization-macros` to your project.

#### 2. Include the header

```c++
#include <bonobomock_optimization_macros_api.h>
```

#### 3. Wrap the function definition

Place `BONOBO_MOCK_DISABLE_FUNCTION_OPTIMIZATION_START` immediately before the function definition and `BONOBO_MOCK_DISABLE_FUNCTION_OPTIMIZATION_END` immediately after the closing brace:

```c++
BONOBO_MOCK_DISABLE_FUNCTION_OPTIMIZATION_START(sample_function)
bool sample_function() {
    return false;
}
BONOBO_MOCK_DISABLE_FUNCTION_OPTIMIZATION_END(sample_function)
```

Note: there is **no semicolon** after either macro.

#### 4. Register the source file for recompilation

Add the source file containing the wrapped function to `FILES_TO_RECOMPILE` in your `CMakeLists.txt`:

```cmake
add_bonobomock_executable(
    TARGET_NAME
        my_test.u.t
    TEST_FILES
        test1.t.cpp
    FILES_TO_RECOMPILE
        ${PROJECT_SOURCE_DIR}/src/source_file.cpp
)
```

This tells the CMake helper to compile the source file a second time — with `BONOBO_MOCK_APPLY_OPTIMIZATION_RESTRICTIONS` defined — and include it in the test executable. The newly compiled object takes precedence over the same file in the linked library. The original library build is unaffected.

#### 5. Link the library

```cmake
target_link_libraries(my_test.u.t PRIVATE
  bonobomock
  bonobomock-optimization-macros
)
```

#### 6. Verify

Build and run the test in an optimized build (e.g., CMake build type `RelWithDebInfo` or `Release`). If mocking still fails after applying the macros, the function may be getting inlined at the call site rather than as a definition. In that case, use `NON_PROD_ONLY_TEST_FILES` in the CMake helper to restrict the test to non-production builds, where `-O0` prevents all inlining.

### When you cannot modify the function's source

If the function you want to mock is defined in a library you do not own — or in code you otherwise cannot change — you cannot apply the optimization macros to it. Instead, you could introduce a wrapper function in your own code that delegates to the library function, and mock the wrapper:

```c++
// my_wrappers.cpp
#include <bonobomock_optimization_macros_api.h>
#include <third_party_lib.h>

BONOBO_MOCK_DISABLE_FUNCTION_OPTIMIZATION_START(my_wrapper)
int my_wrapper(int x) {
    return third_party_function(x);
}
BONOBO_MOCK_DISABLE_FUNCTION_OPTIMIZATION_END(my_wrapper)
```

Then refactor the code under test to call `my_wrapper()` instead of `third_party_function()` directly. In your test, mock `my_wrapper` — since you own its source, you can apply the optimization macros and register it with `FILES_TO_RECOMPILE` as described above.

## How it's implemented

### Compile-time gate

The entire mechanism is controlled by a single preprocessor symbol: `BONOBO_MOCK_APPLY_OPTIMIZATION_RESTRICTIONS`.

When that symbol is **not** defined, both macros expand to nothing. When the symbol **is** defined (set by the CMake helper during optimized test builds, e.g., CMake build types `RelWithDebInfo` or `Release`), the macros expand into compiler-specific attributes and pragmas:

| Compiler | `START` expands to | `END` expands to |
|----------|--------------------|------------------|
| Clang | `__attribute__((optnone)) __attribute__((noinline))` | _(empty)_ |
| GCC | `__attribute__((optimize("O0"))) __attribute__((noinline))` | _(empty)_ |
| MSVC | `__declspec(noinline)` | _(empty)_ |
| Oracle Studio (SunPro) | `__attribute__((returns_twice)) __attribute__((noinline))` | `#pragma unknown_control_flow(func_name)` |

The `START` macro is placed before the function definition so the attributes apply to it. The `END` macro is placed after the closing brace to accommodate SunPro's `#pragma unknown_control_flow`, which must follow the function body.

### Why the source file must be recompiled

Compiler attributes and pragmas only take effect when the compiler processes the source file that contains them. When the function lives in a library that is already compiled, the attributes are never seen. Listing the file in `FILES_TO_RECOMPILE` causes the CMake helper to add it as a source of the test executable and define `BONOBO_MOCK_APPLY_OPTIMIZATION_RESTRICTIONS` for that compilation. The resulting object file overrides the version from the library, giving BonoboMock an unoptimized, non-inlined entry point to patch.

## Limitations

### MSVC: weaker per-function guarantee

On GCC and Clang, the `START` macro expands to a per-function optimization disable
attribute (`optimize("O0")` / `optnone`). This makes the annotated function
completely opaque to the optimizer: the compiler cannot inline it, constant-fold its
return value at call sites, or treat it as a candidate for identical-code merging.

On MSVC, the macro expands only to `__declspec(noinline)`. This prevents the
function from being inlined but leaves two optimizations active that can still
prevent BonoboMock from intercepting calls when the function is defined in the **same
translation unit as the test**:

- **Intra-TU constant propagation.** MSVC's interprocedural analysis can inspect a
  visible function body and substitute a constant return value at the call site —
  even without inlining the function. If the compiler can prove `f()` always returns
  `false`, it may compile `if (f()) { ... }` as if the branch is dead, regardless of
  any mock that patches `f`'s entry point.

- **COMDAT identical-code folding (ICF).** The linker can merge functions whose
  compiled machine code is byte-identical. If two functions produce the same
  instruction sequence (common with trivial single-expression functions), they
  share an address. Mocking one mock also affects the other, and expected call
  counts on each can fail to match.

Both risks are narrow in practice: they only affect functions whose return value is
trivially derivable from a constant argument (constant propagation) or whose
machine code happens to be identical to another function in the same binary (ICF).
Real production functions with branching logic, state, or side effects are generally
not affected.

**Functions in a separate library TU** — the most common BonoboMock use case — are not
subject to constant propagation (the test compiler cannot see the body). ICF can
still apply across TUs, but it only merges byte-identical code, which is rare for
non-trivial library functions.

**Workaround for affected functions.** If you have an in-project function that hits
either issue on MSVC, move the mock test for that function into
`NON_PROD_ONLY_TEST_FILES` in the CMake helper. Those test files are excluded from
optimized (RelWithDebInfo) builds and run only in debug builds, where MSVC defaults
to `/Od` and neither optimization applies.

### Oracle Studio (SunPro): overloaded functions

On Oracle Studio (SunPro), the macros may not work for overloaded functions (functions with the same name) because the `#pragma unknown_control_flow` directive uses the function name and the compiler cannot disambiguate between overloads.

## References

- [CMake Helper](cmake-helper.md)
- [Limitations: Function inlining](limitations.md#function-inlining)

---
[← Back to Documentation Home](../index.md)
