# Mock Static Function

In this example we are going to show you how to mock and test a static function using [BonoboMock](../index.md).

> **Note:** In optimized builds (e.g., CMake build types `RelWithDebInfo` or `Release`), the compiler may inline functions, preventing BonoboMock from intercepting calls. See [Function inlining](../reference/limitations.md#function-inlining) for this limitation and the available mitigations using the [optimization macros](../reference/optimization-macros.md) and [CMake helper](../reference/cmake-helper.md).

> **Note:** If your project uses C++03, `auto` is unavailable. Explicitly declare the mock type instead — see [Explicit Mock Object Types](mock-object-types.md).

## Define static function

Let's define a static function `sample_function` in class `SampleClass`, it takes a boolean argument and returns the boolean value:

```c++
class SampleClass {
public:
    static bool sample_function(bool in) {
        return in;
    }
};
```

## Write unittest using BonoboMock

```c++
TEST(Static, Mock) {
    // Mock static function sample_function in class SampleClass
#ifdef BSLS_COMPILERFEATURES_FULL_CPP11
    auto mock = BONOBO_MOCK(&SampleClass::sample_function);
#else
    bsl::shared_ptr<GMock<bool(bool)> > mock = BONOBO_MOCK(&SampleClass::sample_function);
#endif

    EXPECT_CALL(*mock, BONOBO_MOCK_FUNCTION(false))
        .Times(1)
        .WillOnce(Return(true));

    EXPECT_TRUE(SampleClass::sample_function(false));

    EXPECT_CALL(*mock, BONOBO_MOCK_FUNCTION(_))
        .WillRepeatedly(Return(true));

    EXPECT_TRUE(SampleClass::sample_function(false));
    EXPECT_TRUE(SampleClass::sample_function(true));

    mock->restore();

    EXPECT_FALSE(SampleClass::sample_function(false));
    EXPECT_TRUE(SampleClass::sample_function(true));
}
```

For `sample_function`, we first pass the address of it to `BONOBO_MOCK`, which will return a `mock` object that manages the mocking.
After creating the mock object, we can define how we expect it to behave using `BONOBO_MOCK_FUNCTION`. Because `sample_function` takes 1 boolean argument, we can match the matcher parameter to a specific argument or match anything using `_`. In this example, the first `EXPECT_CALL` is mocking the specific case in which `sample_function` is called with `false` as input. The second `EXPECT_CALL` is to mock all other cases.

If you need to stop mocking in the middle of the unit test, you can use `mock->restore()` to revert to the default behavior.

The `mock` object will automatically restore the mocking when it goes out of scope.

## Example source code

You can find additional examples among the unit test files for the library under `tests/unit/`.

---

[← Back to Cookbook](index.md)

[← Documentation Home](../index.md)
