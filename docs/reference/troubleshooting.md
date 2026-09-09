# Troubleshooting

## My test code doesn't compile

- **Incorrect explicit mock type** — if you are not using `auto`, ensure the `GMock<signature>` type matches the function signature. For member functions, the first parameter is `void*` (non-const) or `const void*` (const). See [Explicit Mock Object Types](../cookbook/mock-object-types.md).

## My test compiles but the mock doesn't work

There are several common causes:

### 1. The function is inlined or optimized away

The compiler inlined the target function, so there is no entry point for BonoboMock to patch. The mock is installed without error but the original code still runs. See [Limitations: Function inlining](limitations.md#function-inlining) for details on why this happens and the available mitigations.

- Ensure you are using [cmake-bonobomock-helper](cmake-helper.md) to build your test target — it sets compiler flags (e.g., `-fno-inline`) that reduce inlining.
- Apply [bonobomock-optimization-macros](optimization-macros.md) around the function definition and add the source file to `FILES_TO_RECOMPILE` in your CMakeLists.txt.
- If optimization macros don't help, move the test source to `NON_PROD_ONLY_TEST_FILES` in the call to the [cmake-bonobomock-helper](cmake-helper.md).

### 2. The wrong overload is being mocked

If the function you are mocking is overloaded, `&Class::method` may be selecting the wrong overload. You need to cast the function pointer to the specific signature you want to mock. See [Mock Overloaded Functions](../cookbook/mock-overloaded-functions.md) for how to disambiguate.

### 3. Using BONOBO_MOCK on a virtual function (SunPro / C++03 only)

On SunPro or C++03, if the function you are mocking is virtual, you must use `BONOBO_MOCK_VIRTUAL` instead of `BONOBO_MOCK`. The two macros resolve the function's address in memory differently — `BONOBO_MOCK` uses the function pointer directly, while `BONOBO_MOCK_VIRTUAL` resolves the actual implementation address through the vtable. Using the wrong macro may patch the wrong location, causing the mock to have no effect. See [Mock Virtual Functions](../cookbook/mock-virtual-functions.md) for details.

On Itanium ABI compilers (GCC, Clang) with C++11 or later, `BONOBO_MOCK` auto-detects virtual functions and resolves their addresses correctly, so this is not a concern.


## My test works in low-optimization builds but not in optimized builds

This is almost always caused by function inlining. When building without optimization (e.g., `-O0`, as in CMake's `Debug` build type), the compiler does not inline functions, so BonoboMock can patch every entry point. In optimized builds (e.g., `-O2`, as in CMake's `RelWithDebInfo` or `Release` build types), the compiler may inline the function you are trying to mock — the mock is installed without error, but calls that were inlined at compile time bypass the patch entirely.

See [section 1 above](#1-the-function-is-inlined-or-optimized-away) for how to resolve this.

## `bonobomock make current page writable error`

This is a fatal runtime error from `mprotect()` failing inside BonoboMock's patching logic. BonoboMock needs to make code pages writable to overwrite function entry points (see [Internals](internals.md#runtime-binary-patching)), and the OS refused.

On SunPro or C++03, the most common cause is using `BONOBO_MOCK` on a virtual function instead of `BONOBO_MOCK_VIRTUAL`. When `BONOBO_MOCK` is used on a virtual function on these compilers, it may resolve to an invalid address (e.g., a vtable offset rather than an actual code address), and attempting to make that memory writable fails. Use `BONOBO_MOCK_VIRTUAL` instead — see [Mock Virtual Functions](../cookbook/mock-virtual-functions.md). On Itanium ABI compilers (GCC, Clang) with C++11, `BONOBO_MOCK` handles virtual functions correctly and this error has a different cause — check that the function address is valid and that the binary has not been stripped.

---
[← Back to Documentation Home](../index.md)
