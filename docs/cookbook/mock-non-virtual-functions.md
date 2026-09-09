# Mock Non-virtual Member Functions

In this example we are going to show you how to mock and test a public non-virtual member function using [BonoboMock](../index.md).

> **Note:** In optimized builds (e.g., CMake build types `RelWithDebInfo` or `Release`), the compiler may inline functions, preventing BonoboMock from intercepting calls. See [Function inlining](../reference/limitations.md#function-inlining) for this limitation and the available mitigations using the [optimization macros](../reference/optimization-macros.md) and [CMake helper](../reference/cmake-helper.md).

> **Note:** In C++, a function can be virtual even without the `virtual` keyword -- if any base class declares a function with the same signature as `virtual`, it is implicitly virtual in all derived classes. If that is the case, you must use [virtual function mocking](./mock-virtual-functions.md) instead. See [Implicitly Virtual Functions](./implicitly-virtual-functions.md) for details.

> **Note:** If your project uses C++03, `auto` is unavailable. Explicitly declare the mock type instead — see [Explicit Mock Object Types](mock-object-types.md).

## Define non-virtual member function

### Define the class and its functions

Let's define a class `SampleClassNonVirtual` with 2 non-virtual public member functions. `member_function` is a non-const function and `const_member_function` is const, both of them take a boolean argument and return an integer:

```c++
class SampleClassNonVirtual {
public:
    int member_function(bool in) {
        if (in) {
            return 1;
        }
        return 0;
    }

    int const_member_function(bool in) const {
        if (in) {
            return 10;
        }
        return -10;
    }
};
```

### Define free functions to demonstrate all-instance matching

To demonstrate that BonoboMock can intercept member function calls on objects the test does not control, we define two free functions that create their own instance of `SampleClassNonVirtual` and call the non-virtual member functions:

```c++
int non_virtual_member_wrapper() {
    SampleClassNonVirtual obj;
    return obj.member_function(false);
}

int non_virtual_const_member_wrapper() {
    SampleClassNonVirtual obj;
    return obj.const_member_function(false);
}
```

## Write unittest using BonoboMock

### Mock non-const function

```c++
TEST(Nonvirtual, Mock_nonvirtual) {
#ifdef BSLS_COMPILERFEATURES_FULL_CPP11
    auto mock = BONOBO_MOCK(&SampleClassNonVirtual::member_function);
#else
    bsl::shared_ptr<GMock<int(void*, bool)> > mock = BONOBO_MOCK(&SampleClassNonVirtual::member_function);
#endif

    EXPECT_CALL(*mock, BONOBO_MOCK_FUNCTION(_, _))
        .Times(1)
        .WillOnce(Return(100));

    SampleClassNonVirtual obj;
    EXPECT_CALL(*mock, BONOBO_MOCK_FUNCTION(&obj, _))
        .Times(2)
        .WillOnce(Return(200))
        .WillOnce(Return(250));

    EXPECT_EQ(200, obj.member_function(true));
    EXPECT_EQ(100, non_virtual_member_wrapper());
    EXPECT_EQ(250, obj.member_function(true));

    mock->restore();

    EXPECT_EQ(1, obj.member_function(true));
    EXPECT_EQ(0, non_virtual_member_wrapper());
}
```

For `member_function`, we first pass the address of it to `BONOBO_MOCK`, which will return a `mock` object that manages the mocking of the function. The function signature inside the `mock` object takes one more argument at the beginning, `void*` should be used when you are mocking a non-const member function and `const void*` should be used when you are mocking a const member function.

After creating the mock object, we can define the mocking behavior using `BONOBO_MOCK_FUNCTION`. Because `member_function` takes 1 boolean argument, we can match the matcher parameter to a specific argument or match anything using `_`.

You may wonder why `BONOBO_MOCK_FUNCTION` takes two matcher parameters while `member_function` only expects one. This is because for class member function mocking, the first argument of `BONOBO_MOCK_FUNCTION` is always the pointer to the class object. You can pass a specific object's pointer or `_` to match any object.

In this example, the first `EXPECT_CALL` is telling BonoboMock to return *100* for any object of `SampleClassNonVirtual` with any arguments, except for the test cases defined in the second `EXPECT_CALL`, which return *200* then *250* when the specific object `obj` is called.

Because the first `EXPECT_CALL` uses `_` as the first argument (the instance pointer), it matches calls on all instances — including the object created inside `non_virtual_member_wrapper`, which the test does not have direct access to. The second `EXPECT_CALL` uses `&obj` as the first argument, so it matches calls only on that specific instance.

If you need to stop mocking in the middle of the unit test, you can use `mock->restore()` to revert to the default behavior.

The `mock` object will automatically restore the mocking when it goes out of scope.

### Mock const function

```c++
TEST(Nonvirtual, Mock_nonvirtual_const_member) {
    // Mock the const non-virtual function `member_function`
#ifdef BSLS_COMPILERFEATURES_FULL_CPP11
    auto mock = BONOBO_MOCK(&SampleClassNonVirtual::const_member_function);
#else
    bsl::shared_ptr<GMock<int(const void*, bool)> > mock = BONOBO_MOCK(&SampleClassNonVirtual::const_member_function);
#endif

    EXPECT_CALL(*mock, BONOBO_MOCK_FUNCTION(_, _))
        .Times(1)
        .WillOnce(Return(100));

    const SampleClassNonVirtual obj;
    EXPECT_CALL(*mock, BONOBO_MOCK_FUNCTION(&obj, _))
        .Times(2)
        .WillOnce(Return(200))
        .WillOnce(Return(250));

    EXPECT_EQ(200, obj.const_member_function(true));
    EXPECT_EQ(250, obj.const_member_function(true));
    EXPECT_EQ(100, non_virtual_const_member_wrapper());
}
```

For `const_member_function`, everything remains the same except the type of `mock` is slightly different.

## Example source code

You can find additional examples among the unit test files for the library under `tests/unit/`.

---

[← Back to Cookbook](index.md)

[← Documentation Home](../index.md)
