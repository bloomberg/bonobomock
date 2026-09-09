# Mock Private Function

In this example we are going to show you how to mock and test a private function using [BonoboMock](../index.md).

> **Note:** In optimized builds (e.g., CMake build types `RelWithDebInfo` or `Release`), the compiler may inline functions, preventing BonoboMock from intercepting calls. See [Function inlining](../reference/limitations.md#function-inlining) for this limitation and the available mitigations using the [optimization macros](../reference/optimization-macros.md) and [CMake helper](../reference/cmake-helper.md).

> **Note:** If your project uses C++03, `auto` is unavailable. Explicitly declare the mock type instead — see [Explicit Mock Object Types](mock-object-types.md).

> **Note:** Private function mocking does not support function overloading (functions with the same name) because BonoboMock uses string-based symbol table lookup to resolve private function addresses. See [Limitations](../reference/limitations.md#overloaded-private-functions) for details.

> **Note:** In order to mock private methods, the `BONOBO_MOCK_PRIVATE_*` macros scan the symbol table of the test binary on first use. This can have significant runtime cost for a large test binary. We recommend using `add_test` rather than `gtest_discover_tests` or `catch_discover_tests` for optimal performance.

## Mock private static function

BonoboMock can mock private **static** member functions using the `BONOBO_MOCK_PRIVATE_STATIC` family of macros. Because static functions have free-function signatures (no implicit `this` pointer), they use a simpler workflow than private non-static members — no class parameter or const/non-const distinction is needed.

### Define the class with a private static function

```c++
class SampleClassPrivate {
public:
    static int call_private_static(int* in) {
        return private_static_function(in);
    }
private:
    static int private_static_function(int* in) {
        return *in;
    }
};
```

### Define a signature-conveying free function

BonoboMock needs to know the function signature of the private static function, but it cannot access private members directly. Define a free function with the same signature — its body does not matter, as it is never called:

```c++
int function_with_same_signature_as_private_static_function(int* in) {
    return *in; // never called — only used for type deduction
}
```

### Write unittest using BonoboMock

```c++
TEST(PrivateStatic, Mock_private_static) {
#ifdef BSLS_COMPILERFEATURES_FULL_CPP11
    auto mock = BONOBO_MOCK_PRIVATE_STATIC(
        Namespace::SampleClassPrivate::private_static_function,
        &function_with_same_signature_as_private_static_function);
#else
    bsl::shared_ptr<GMock<int(int*)> > mock = BONOBO_MOCK_PRIVATE_STATIC(
        Namespace::SampleClassPrivate::private_static_function,
        &function_with_same_signature_as_private_static_function);
#endif

    EXPECT_CALL(*mock, BONOBO_MOCK_FUNCTION(_))
        .Times(1)
        .WillOnce(Return(100));

    int input = 10;
    EXPECT_EQ(100, SampleClassPrivate::call_private_static(&input));

    mock->restore();

    EXPECT_EQ(10, SampleClassPrivate::call_private_static(&input));
}
```

Use `BONOBO_MOCK_PRIVATE_STATIC` to create the mock — the first argument is the fully qualified function name, the second is the address of the signature-conveying free function. The address is resolved via symbol table lookup on first use.

Unlike private non-static member functions, there is no class parameter and no `this` pointer in the matchers — `BONOBO_MOCK_FUNCTION` receives only the actual function arguments.

Strict and nice variants are also available: `BONOBO_MOCK_PRIVATE_STATIC_STRICT` and `BONOBO_MOCK_PRIVATE_STATIC_NICE`. See [Naggy, Nice, and Strict Mocks](mock-strictness.md) for details.

## Mock private non-static member function

BonoboMock can mock private non-static member functions regardless of whether they are const or non-const, virtual or non-virtual. The following sample code only shows the mocking of a non-const, non-virtual, private function. More examples can be found among the unit test files for the library under `tests/unit/`.

### Define the classes with private functions

Let's define a class `SampleClassPrivate` that has a private function -- `private_member_function`. It also contains a public function which serves as a wrapper of the private one:

```c++
class SampleClassPrivate {
public:
    int call_private(int* in) {
        return private_member_function(in);
    }
private:
    int private_member_function(int* in) {
        return *in;
    }
};
```

### Define a signature-conveying free function

BonoboMock needs to know the function signature of the private function, but it cannot access private members directly. We define a free function with the same signature — its body does not matter, as it is never called. It exists only to convey the type to BonoboMock:

```c++
int function_with_same_signature_as_private_member_function(int* in) {
    return *in; // never called — only used for type deduction
}
```

### Define a wrapper to demonstrate all-instance matching

To demonstrate that BonoboMock can intercept calls to the private function on objects the test does not control, we define a free function that creates its own `SampleClassPrivate` and calls the private function through its public wrapper:

```c++
int call_private_via_local_object(int* in) {
    SampleClassPrivate obj;
    return obj.call_private(in);
}
```

## Write unittest using BonoboMock

### Mock non-const private function

```c++
TEST(Private, Mock_non_const_private) {
#ifdef BSLS_COMPILERFEATURES_FULL_CPP11
    auto mock = BONOBO_MOCK_PRIVATE_NON_CONST(
        BloombergLP::bonobomock::test::SampleClassPrivate::private_member_function,
        BloombergLP::bonobomock::test::SampleClassPrivate,
        &function_with_same_signature_as_private_member_function);
#else
    bsl::shared_ptr<GMock<int(void*, int*)> > mock =
        BONOBO_MOCK_PRIVATE_NON_CONST(
            BloombergLP::bonobomock::test::SampleClassPrivate::private_member_function,
            BloombergLP::bonobomock::test::SampleClassPrivate,
            &function_with_same_signature_as_private_member_function);
#endif

    SampleClassPrivate obj;
    EXPECT_CALL(*mock, BONOBO_MOCK_FUNCTION(_, _))
        .Times(1)
        .WillOnce(Return(100));

    EXPECT_CALL(*mock, BONOBO_MOCK_FUNCTION(&obj, _))
        .Times(1)
        .WillOnce(Return(200));

    int input = 10;
    EXPECT_EQ(200, obj.call_private(&input));
    EXPECT_EQ(100, call_private_via_local_object(&input));

    mock->restore();

    EXPECT_EQ(10, obj.call_private(&input));
    EXPECT_EQ(10, call_private_via_local_object(&input));
}
```

To mock a private function, use `BONOBO_MOCK_PRIVATE_NON_CONST` to create the mock object. The first argument is the full name of the function, the second is the full name of the class, and the third is the address of the signature-conveying free function. The function address is resolved via symbol table lookup on first use.
The rest of the code is quite similar to [Non-virtual Member Function Mocking](./mock-non-virtual-functions.md).

## Example source code

You can find additional examples among the unit test files for the library under `tests/unit/`.

---

[← Back to Cookbook](index.md)

[← Documentation Home](../index.md)
