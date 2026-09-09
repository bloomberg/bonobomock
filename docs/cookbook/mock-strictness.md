# Naggy, Nice, and Strict Mocks

> **Note:** If your project uses C++03, `auto` is unavailable. Explicitly declare the mock type instead — see [Explicit Mock Object Types](mock-object-types.md).

By default, `BONOBO_MOCK` creates a *naggy* mock (gMock's default). When a mocked function is called, and it does not have an `EXPECT_CALL` expectation set up, the test prints an "Uninteresting mock function call" warning but still passes. This is fine for most cases, but sometimes you want stricter or more lenient behavior:

- **`BONOBO_MOCK_STRICT`** -- fails the test on any unexpected call.
- **`BONOBO_MOCK_NICE`** -- silently ignores unexpected calls (no warning, no failure).

These variants map directly to gMock's `StrictMock<>` and `NiceMock<>` wrappers. For more background, see the [GoogleTest documentation](https://google.github.io/googletest/gmock_cook_book.html#NiceStrictNaggy).

## When to use each

- **Naggy (default)**: Good starting point. Warnings surface forgotten expectations without breaking the build.
- **Strict**: Use when every call matters and an unexpected call indicates a bug (e.g. verifying that a function is called exactly N times and no more).
- **Nice**: Use when the function under test makes many calls you don't care about and the warnings are noise (e.g. logging, metrics).

## Example: static function

Given a static function:

```c++
class SampleClass {
public:
    static bool sample_function(bool in) {
        return in;
    }
};
```

### Naggy mock (default)

```c++
TEST(NaggyMock, StaticMethod) {
    auto mock = BONOBO_MOCK(&SampleClass::sample_function);

    // No EXPECT_CALL set -- calling the function prints
    // an "Uninteresting mock function call" warning,
    // but the test still passes.
    SampleClass::sample_function(true);
}
```

### Strict mock

```c++
TEST(StrictMock, StaticMethod) {
    auto mock = BONOBO_MOCK_STRICT(&SampleClass::sample_function);

    // No EXPECT_CALL set -- the test FAILS with
    // "Uninteresting mock function call".
    SampleClass::sample_function(true);
}
```

### Nice mock

```c++
TEST(NiceMock, StaticMethod) {
    auto mock = BONOBO_MOCK_NICE(&SampleClass::sample_function);

    // No EXPECT_CALL set -- the call is silently ignored.
    // No warning, no failure.
    SampleClass::sample_function(true);
}
```

## Available macros

The `_STRICT` and `_NICE` variants are available for every mock type:

| Function type | Naggy (default) | Strict | Nice |
|---|---|---|---|
| Free / static / non-virtual | `BONOBO_MOCK` | `BONOBO_MOCK_STRICT` | `BONOBO_MOCK_NICE` |
| Virtual (Itanium ABI + C++11) | `BONOBO_MOCK` | `BONOBO_MOCK_STRICT` | `BONOBO_MOCK_NICE` |
| Virtual (SunPro / C++03) | `BONOBO_MOCK_VIRTUAL` | `BONOBO_MOCK_VIRTUAL_STRICT` | `BONOBO_MOCK_VIRTUAL_NICE` |
| Virtual on instance | `BONOBO_MOCK_VIRTUAL_ON` | `BONOBO_MOCK_VIRTUAL_STRICT_ON` | `BONOBO_MOCK_VIRTUAL_NICE_ON` |
| Private (non-const) | `BONOBO_MOCK_PRIVATE_NON_CONST` | `BONOBO_MOCK_PRIVATE_STRICT_NON_CONST` | `BONOBO_MOCK_PRIVATE_NICE_NON_CONST` |
| Private (const) | `BONOBO_MOCK_PRIVATE_CONST` | `BONOBO_MOCK_PRIVATE_STRICT_CONST` | `BONOBO_MOCK_PRIVATE_NICE_CONST` |

---

[← Back to Cookbook](index.md)

[← Documentation Home](../index.md)


