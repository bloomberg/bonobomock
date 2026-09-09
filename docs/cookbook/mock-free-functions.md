# Mock Free Function

In this example we are going to show you how to mock and test a free function using [BonoboMock](../index.md). The same approach works for `extern "C"` functions.

> **Note:** In optimized builds (e.g., CMake build types `RelWithDebInfo` or `Release`), the compiler may inline functions, preventing BonoboMock from intercepting calls. See [Function inlining](../reference/limitations.md#function-inlining) for this limitation and the available mitigations using the [optimization macros](../reference/optimization-macros.md) and [CMake helper](../reference/cmake-helper.md).

> **Note:** If your project uses C++03, `auto` is unavailable. Explicitly declare the mock type instead — see [Explicit Mock Object Types](mock-object-types.md).

## Define free function

### Define 1st free function

Let's define a super simple free function `sample_function`, which always returns `false`:

```c++
bool sample_function() {
    return false;
}
```

### Define 2nd free function

Then define another free function that requires 2 arguments so that we can show you the usage of matcher:

```c++
int sample_function_2(int a, int b) {
    return a + b;
}
```

## Write unittest using BonoboMock

### Mock function without arguments

```c++
TEST(Global, Mock1) {
#ifdef BSLS_COMPILERFEATURES_FULL_CPP11
    auto mock = BONOBO_MOCK(&sample_function);
#else
    bsl::shared_ptr<GMock<bool()> > mock = BONOBO_MOCK(&sample_function);
#endif

    EXPECT_CALL(*mock, BONOBO_MOCK_FUNCTION())
        .Times(1)
        .WillOnce(Return(true));

    EXPECT_TRUE(sample_function());

    mock->restore();

    EXPECT_FALSE(sample_function());
}
```

For `sample_function`, we first pass the address of it to `BONOBO_MOCK`, which will return a `mock` object that manages the mocking of the function.
After creating the mock object, we can define how we expect it to behave using `BONOBO_MOCK_FUNCTION`. Because `sample_function` doesn't take any arguments, we don't pass any matcher parameter to `BONOBO_MOCK_FUNCTION`. We are letting `sample_function` return `true` in this example.

If you need to stop mocking in the middle of the unit test, use `mock->restore()` to revert to the default behavior.

The `mock` object will automatically restore the mocking when it goes out of scope.

### Mock function with arguments

```c++
TEST(Global, Mock2) {
#ifdef BSLS_COMPILERFEATURES_FULL_CPP11
    auto mock = BONOBO_MOCK(&sample_function_2);
#else
    bsl::shared_ptr<GMock<int(int, int)> > mock = BONOBO_MOCK(&sample_function_2);
#endif

    EXPECT_CALL(*mock, BONOBO_MOCK_FUNCTION(_, _))
        .WillRepeatedly(Return(100));

    EXPECT_CALL(*mock, BONOBO_MOCK_FUNCTION(100, 150))
        .Times(2)
        .WillOnce(Return(150))
        .WillOnce(Return(250));

    EXPECT_EQ(150, sample_function_2(100,150));
    EXPECT_EQ(250, sample_function_2(100,150));
    EXPECT_EQ(100, sample_function_2(1,2));
    EXPECT_EQ(100, sample_function_2(3,4));
}
```

For `sample_function_2`, we also call `BONOBO_MOCK` to create the `mock` object first. However, when calling `BONOBO_MOCK_FUNCTION`, we need to pass matcher parameters this time since the function now requires 2 arguments.

As gMock supports, the matcher can match a specific function argument or anything. We use `_` to tell BonoboMock that we would like to match anything in the first `EXPECT_CALL` and match specifically `100` and `150` as function arguments in the second `EXPECT_CALL`. Putting them together, we are telling BonoboMock to return *150* when `sample_function_2` is called with `100` and `150` as function arguments for the first time and return *250* for the second call. For all other cases, BonoboMock will return *100*.

## Example source code

You can find additional examples among the unit test files for the library under `tests/unit/`.

---

[← Back to Cookbook](index.md)

[← Documentation Home](../index.md)
