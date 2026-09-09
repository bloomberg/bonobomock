# Mock Lambda Function

In this example we are going to show you how to mock and test lambda functions using [BonoboMock](../index.md).

> **Note:** In optimized builds (e.g., CMake build types `RelWithDebInfo` or `Release`), the compiler may inline functions, preventing BonoboMock from intercepting calls. See [Function inlining](../reference/limitations.md#function-inlining) for this limitation and the available mitigations using the [optimization macros](../reference/optimization-macros.md) and [CMake helper](../reference/cmake-helper.md).

## Define Lambda Function

**Lambda functions are a C++11 language feature. BonoboMock supports lambda mocking on GCC and Clang for projects using C++11 or later.** Lambda mocking is [not supported on MSVC](../reference/limitations.md#lambda-mocking-on-msvc).

In order to mock the lambda function, we need to get the object of it first (we have to use `auto` here because we don't know the exact type of a lambda function):

```c++
auto lambdaFunc = [](int a) { return a > 10; };
```

## Write unittest using BonoboMock

### Mock lambda function

The lambda function is basically implemented as a functor in C++ behind the scenes, so BonoboMock can mock it with existing functionalities. As we have the object of the lambda function, we can use `decltype` to extract the type of it. And because it is a functor, we just need to fetch the address of the corresponding `operator()` of the specific type. One thing worth noting is that the following code will only work when there is no compiler optimization.

```c++
TEST(Lambda, example_without_optimization) {
    // demonstrate existing behavior of our lambda
    EXPECT_FALSE(lambdaFunc(10));

    auto functor = &decltype(lambdaFunc)::operator();
    auto mock = BONOBO_MOCK(functor);

    EXPECT_CALL(*mock, BONOBO_MOCK_FUNCTION(_,_))
        .Times(1)
        .WillOnce(Return(true));

    // the behavior of the lambda is now overridden for our testing
    EXPECT_TRUE(lambdaFunc(10));

    mock->restore();

    // pre-existing behavior of the lambda is restored
    EXPECT_FALSE(lambdaFunc(10));
}
```

If we want to mock a lambda function with higher optimization, the only thing we can do is define a wrapper function that calls the lambda function inside, and add the bonobomock-optimization-macro around the wrapper function. This is because there is no place for us to add attributes to a lambda function.

> **MSVC limitation:** Lambda mocking is not supported on MSVC. MSVC routes stateless lambda calls through an internal static invoke function rather than through `operator()`, bypassing the binary patch that BonoboMock installs. This affects both the optimized wrapper pattern and direct lambda mocking.

```c++
namespace {
auto lambdaFunc = [](int a) { return a > 10; };

BONOBO_MOCK_DISABLE_FUNCTION_OPTIMIZATION_START(lambda_wrapper)
bool lambda_wrapper(int a) {
    return lambdaFunc(a);
}
BONOBO_MOCK_DISABLE_FUNCTION_OPTIMIZATION_END(lambda_wrapper)
}

TEST(Lambda, example_with_optimization) {
    // calling lambda function directly won't trigger the mocking behavior due to compiler optimization
    EXPECT_FALSE(lambdaFunc(10));
    // demonstrate existing behavior of our lambda in the wrapper function
    EXPECT_FALSE(lambda_wrapper(10));
    
    auto functor = &decltype(lambdaFunc)::operator();
    auto mock = BONOBO_MOCK(functor);

    EXPECT_CALL(*mock, BONOBO_MOCK_FUNCTION(_,_))
        .Times(2)
        .WillOnce(Return(true))
        .WillOnce(Return(true));
    // the behavior of the lambda is now overridden for our testing by calling the wrapper function
    EXPECT_TRUE(lambda_wrapper(10));
    EXPECT_TRUE(lambda_wrapper(10));
    // calling lambda function directly won't trigger the mocking behavior due to compiler optimization
    EXPECT_FALSE(lambdaFunc(10));

    mock->restore();

    // calling lambda function directly won't trigger the mocking behavior due to compiler optimization
    EXPECT_FALSE(lambdaFunc(10));
    // pre-existing behavior of the lambda is restored when wrapper function is called
    EXPECT_FALSE(lambda_wrapper(10));
}
```

## Example source code

You can find additional examples among the unit test files for the library under `tests/unit/`.

---

[← Back to Cookbook](index.md)

[← Documentation Home](../index.md)
