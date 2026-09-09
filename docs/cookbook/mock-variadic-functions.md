# Mock Variadic Function

In this example we are going to show you how to mock and test variadic functions using [BonoboMock](../index.md).

> **Note:** In optimized builds (e.g., CMake build types `RelWithDebInfo` or `Release`), the compiler may inline functions, preventing BonoboMock from intercepting calls. See [Function inlining](../reference/limitations.md#function-inlining) for this limitation and the available mitigations using the [optimization macros](../reference/optimization-macros.md) and [CMake helper](../reference/cmake-helper.md).

## Variadic template functions

**Variadic templates are a C++11 language feature. BonoboMock supports variadic template mocking on all platforms for projects using C++11 or later.**

Variadic template functions are compiled into separate specializations for each set of argument types. To mock them, explicitly declare the signature of each specialization you want to mock — the same typed-function-pointer technique used for [overloaded functions](./mock-overloaded-functions.md).

### Define the variadic template functions

```c++
template<typename T>
int internal_variadic_impl(T a) {
    return static_cast<int>(a);
}

template<typename T, typename... Types>
int internal_variadic_impl(T a, Types... args) {
    int val = static_cast<int>(a);
    return val + internal_variadic_impl(args...);
}

template<typename... Types>
int variadic_function_1(Types... args) {
    return internal_variadic_impl(args...);
}
```

### Mock each specialization

```c++
TEST(Variadic, variadic_template_function) {
    typedef int(*FUNC_TYPE_1)(int);
    typedef int(*FUNC_TYPE_2)(int, int);

    FUNC_TYPE_1 functor1 = &variadic_function_1<int>;
    FUNC_TYPE_2 functor2 = &variadic_function_1<int, int>;

    auto mock1 = BONOBO_MOCK(functor1);
    auto mock2 = BONOBO_MOCK(functor2);

    EXPECT_CALL(*mock1, BONOBO_MOCK_FUNCTION(_))
        .Times(1)
        .WillOnce(Return(100));

    EXPECT_CALL(*mock2, BONOBO_MOCK_FUNCTION(_, _))
        .Times(1)
        .WillOnce(Return(200));

    EXPECT_EQ(100, variadic_function_1(1));
    EXPECT_EQ(200, variadic_function_1(1, 2));

    mock1->restore();
    mock2->restore();

    EXPECT_EQ(1, variadic_function_1(1));
    EXPECT_EQ(3, variadic_function_1(1, 2));
}
```

## C-style variadic functions

C-style variadic functions (using `cstdarg`) keep the ellipsis (`...`) in their compiled signature. BonoboMock can mock these on GCC/Clang, but `BONOBO_MOCK_FUNCTION` can only match arguments before the ellipsis — the variadic arguments themselves cannot be matched.

> **Tip:** An alternative approach is to make the variadic function delegate to a non-variadic function internally, and mock that callee instead. See this [Stack Overflow workaround](https://stackoverflow.com/questions/27252757/how-to-mock-variadic-functions-using-googlemock) for details.

### Define the C-style variadic function

```c++
int variadic_function_2(const char* fmt, ...) {
    va_list args;
    va_start(args, fmt);

    int sum = 0;

    while (*fmt != '\0')
    {
        if (*fmt == 'd')
        {
            int i = va_arg(args, int);
            sum += i;
        }
        ++fmt;
    }

    va_end(args);
    return sum;
}
```

In this example, `variadic_function_2`'s first argument is of type `const char*`, so we define one matcher in `BONOBO_MOCK_FUNCTION` for that argument:

```c++
TEST(Variadic, va_arg) {
    auto mock1 = BONOBO_MOCK(&variadic_function_2);

    EXPECT_CALL(*mock1, BONOBO_MOCK_FUNCTION(_))
        .Times(2)
        .WillOnce(Return(100))
        .WillOnce(Return(200));

    EXPECT_CALL(*mock1, BONOBO_MOCK_FUNCTION("ddd"))
        .Times(1)
        .WillOnce(Return(300));

    EXPECT_EQ(100, variadic_function_2("d", 1));
    EXPECT_EQ(200, variadic_function_2("dd", 1, 2));
    EXPECT_EQ(300, variadic_function_2("ddd", 1, 2, 3));

    mock1->restore();

    EXPECT_EQ(1, variadic_function_2("d", 1));
    EXPECT_EQ(3, variadic_function_2("dd", 1, 2));
    EXPECT_EQ(6, variadic_function_2("ddd", 1, 2, 3));
}
```

## Example source code

You can find additional examples among the unit test files for the library under `tests/unit/`.

---

[← Back to Cookbook](index.md)

[← Documentation Home](../index.md)
