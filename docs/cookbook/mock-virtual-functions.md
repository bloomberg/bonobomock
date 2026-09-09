# Mock Virtual Function

This page shows how to mock virtual functions using [BonoboMock](../index.md).

> **Note:** In optimized builds (e.g., CMake build types `RelWithDebInfo` or `Release`), the compiler may inline functions, preventing BonoboMock from intercepting calls. See [Function inlining](../reference/limitations.md#function-inlining) for this limitation and the available mitigations using the [optimization macros](../reference/optimization-macros.md) and [CMake helper](../reference/cmake-helper.md).

> **Note:** If your project uses C++03, `auto` is unavailable. Use explicit `bsl::shared_ptr<GMock<...>>` types instead. See [Explicit Mock Object Types](mock-object-types.md).

> **Note:** On Itanium ABI compilers (GCC, Clang) with C++11 or later, `BONOBO_MOCK` auto-detects virtual functions — you can use `BONOBO_MOCK` instead of `BONOBO_MOCK_VIRTUAL` and it will resolve the function address correctly. The examples below use `BONOBO_MOCK_VIRTUAL` because it works on all compilers, including SunPro and C++03.

**Contents:**

- [Mock public virtual functions](#mock-public-virtual-functions)
    - [Define the classes with virtual functions](#define-the-classes-with-virtual-functions)
    - [Define free functions to demonstrate all-instance matching](#define-free-functions-to-demonstrate-all-instance-matching)
    - [Mock non-const virtual function](#mock-non-const-virtual-function)
    - [Mock const virtual function](#mock-const-virtual-function)
    - [Classes without default constructor (BONOBO_MOCK_VIRTUAL_ON)](#classes-without-default-constructor-bonobo_mock_virtual_on)
- [Mock protected virtual functions](#mock-protected-virtual-functions)
- [Mock private virtual functions](#mock-private-virtual-functions)
- [Example source code](#example-source-code)

## Mock public virtual functions

The examples in this section use `BONOBO_MOCK_VIRTUAL` to mock **public** virtual functions.

> **Note:** `BONOBO_MOCK_VIRTUAL` requires the class to have a default constructor (no arguments). For classes without a default constructor, use [`BONOBO_MOCK_VIRTUAL_ON`](#classes-without-default-constructor-bonobo_mock_virtual_on) instead, which accepts an existing object instance to extract the virtual function address.


### Define the classes with virtual functions

Let's define a class `BaseClass` that has 2 pure virtual functions. Another class `SampleClassVirtual`, derives from `BaseClass` and implements the 2 virtual public member functions. `virtual_function` is a non-const function and `const_virtual_function` is const:

```c++
class BaseClass {
public:
    virtual int virtual_function(int& out, int in) = 0;
    virtual int const_virtual_function(bool) const = 0;
};

class SampleClassVirtual : public BaseClass {
public:
    virtual int virtual_function(int& out, int in) {
        out = in;
        return 0;
    }

    virtual int const_virtual_function(bool in) const {
        if (in) {
            return 10;
        }
        return -10;
    }
};
```

### Define free functions to demonstrate all-instance matching

To demonstrate that BonoboMock can intercept virtual member function calls on objects the test does not control, we define two free functions that create their own instance of `SampleClassVirtual` and call the virtual member functions:

```c++
int virtual_member_wrapper(int in) {
    int out = 0;
    SampleClassVirtual obj;
    BaseClass *base_ptr = &obj;
    int rc = base_ptr->virtual_function(out, in);
    if (rc) {
        return -1;
    }

    if (out == 100) {
        return 1;
    }

    return 0;
}

int const_virtual_member_wrapper() {
    const SampleClassVirtual obj;
    const BaseClass *base_ptr = &obj;
    return base_ptr->const_virtual_function(false);
}
```

### Mock non-const virtual function

```c++
TEST(Virtual, Mock_virtual) {
#ifdef BSLS_COMPILERFEATURES_FULL_CPP11
    auto mock = BONOBO_MOCK_VIRTUAL(&SampleClassVirtual::virtual_function);
#else
    bsl::shared_ptr<GMock<int(void*, int&, int)> > mock =
        BONOBO_MOCK_VIRTUAL(&SampleClassVirtual::virtual_function);
#endif

    EXPECT_CALL(*mock, BONOBO_MOCK_FUNCTION(_, _, _))
        .Times(1)
        .WillOnce(Return(-1));

    SampleClassVirtual obj;
    EXPECT_CALL(*mock, BONOBO_MOCK_FUNCTION(&obj, _, _))
        .Times(1)
        .WillOnce(Return(-2));

    int out = 0;
    EXPECT_EQ(-2, obj.virtual_function(out, 1));
    EXPECT_EQ(-1, virtual_member_wrapper(1));

    mock->restore();

    EXPECT_EQ(0, obj.virtual_function(out, 1));
    EXPECT_EQ(0, virtual_member_wrapper(1));
}
```

For `virtual_function`, we pass its address to `BONOBO_MOCK_VIRTUAL` (a special macro for virtual functions), which returns a `mock` object that manages the mocking.

After creating the mock object, we define expected behavior using `BONOBO_MOCK_FUNCTION`. Because `virtual_function` takes 2 arguments, we can match the matcher parameter to specific arguments or match anything using `_`.

You may wonder why `BONOBO_MOCK_FUNCTION` takes 3 matcher parameters while `virtual_function` only expects two. This is because for class member function mocking, the first argument of `BONOBO_MOCK_FUNCTION` is always the pointer to the class object. You can pass a specific object's pointer or `_` to match any object.

In this example, the first `EXPECT_CALL` is telling BonoboMock to return *-1* for any object of `SampleClassVirtual` with any arguments, except for the test cases defined in the second `EXPECT_CALL`, which return *-2* when the specific object `obj` is called.

Because the first `EXPECT_CALL` uses `_` as the first argument (the instance pointer), it matches calls on all instances — including the object created inside `virtual_member_wrapper`, which the test does not have direct access to. The second `EXPECT_CALL` uses `&obj` as the first argument, so it matches calls only on that specific instance.

If you need to stop mocking in the middle of the unit test, you can use `mock->restore()` to revert to the default behavior.

The `mock` object will automatically restore the mocking when it goes out of scope.

### Mock const virtual function

```c++
TEST(Virtual, Mock_virtual_const) {
#ifdef BSLS_COMPILERFEATURES_FULL_CPP11
    auto mock = BONOBO_MOCK_VIRTUAL(&SampleClassVirtual::const_virtual_function);
#else
    bsl::shared_ptr<GMock<int(const void*, bool)> > mock =
        BONOBO_MOCK_VIRTUAL(&SampleClassVirtual::const_virtual_function);
#endif

    EXPECT_CALL(*mock, BONOBO_MOCK_FUNCTION(_, _))
        .Times(1)
        .WillOnce(Return(100));

    const SampleClassVirtual obj;
    const BaseClass* ptr = &obj;
    EXPECT_CALL(*mock, BONOBO_MOCK_FUNCTION(&obj, _))
        .Times(1)
        .WillOnce(Return(200));

    EXPECT_EQ(200, ptr->const_virtual_function(true));
    EXPECT_EQ(100, const_virtual_member_wrapper());

    mock->restore();

    EXPECT_EQ(10, ptr->const_virtual_function(true));
    EXPECT_EQ(-10, const_virtual_member_wrapper());
}
```

For `const_virtual_function`, everything remains the same except the explicit type uses `const void*` instead of `void*` for the object pointer.

### Classes without default constructor (BONOBO_MOCK_VIRTUAL_ON)

Because BonoboMock needs to fetch the address of a virtual function through a real object, `BONOBO_MOCK_VIRTUAL` requires the class to have a default constructor. For classes that don't meet this requirement, we have a new macro `BONOBO_MOCK_VIRTUAL_ON`. The code below is almost the same as the example above; the only difference is `BONOBO_MOCK_VIRTUAL_ON`. `BONOBO_MOCK_VIRTUAL_ON` will use an object that you provide in your test to identify the location of the function. The object can be, but does not have to be, the same object as one in your actual test - it's sufficient to create a dummy object for this purpose that's otherwise unused.

```c++
// Abstract base class without default constructor
class BaseClass {
public:
    BaseClass(int x) : m_x(x) {}

    virtual int virtual_function(int& out, int in) = 0;
    virtual int const_virtual_function(bool) const = 0;

protected:
    int m_x;
};

// The SampleClassVirtual class contains virtual member functions for us to mock.
// Also no default constructor
class SampleClassVirtual : public BaseClass {
public:
    SampleClassVirtual(int x) : BaseClass(x) {}

    virtual int virtual_function(int& out, int in) {
        out = in;
        return m_x;
    }

    virtual int const_virtual_function(bool in) const {
        if (in) {
            return 10;
        }
        return -10;
    }
}

// This function will be used to demonstrate that BonoboMock can intercept
// virtual member function calls on objects the test does not control.
int virtual_member_wrapper(int in) {
    int out = 0;
    SampleClassVirtual obj(0);
    BaseClass *base_ptr = &obj;
    int rc = base_ptr->virtual_function(out, in);
    if (rc) {
        return -1;
    }

    if (out == 100) {
        return 1;
    }

    return 0;
}
```

```c++
TEST(VirtualOnInstance, Mock_virtual) {
    // Mock the virtual function `virtual_function`.
    // To correctly mock virtual function, we need to use the specific derived class here.

    // this object is used to extract the address and is otherwise unused
    SampleClassVirtual instance(0);
#ifdef BSLS_COMPILERFEATURES_FULL_CPP11
    auto mock = BONOBO_MOCK_VIRTUAL_ON(instance, &SampleClassVirtual::virtual_function);
#else
    bsl::shared_ptr<GMock<int(void*, int&, int)> > mock =
        BONOBO_MOCK_VIRTUAL_ON(instance, &SampleClassVirtual::virtual_function);
#endif

    // Defined the 2nd mocked function for `virtual_function`.
    // BONOBO_MOCK_FUNCTION is taking any input and mocking any object.
    // Return -1.
    EXPECT_CALL(*mock, BONOBO_MOCK_FUNCTION(_, _, _))
        .Times(1)
        .WillOnce(Return(-1));

    SampleClassVirtual obj(0);
    // Defined the 1st mocked function for `member_function`.
    // BONOBO_MOCK_FUNCTION is taking any input and the specific object `obj`.
    // Return -2.
    EXPECT_CALL(*mock, BONOBO_MOCK_FUNCTION(&obj, _, _))
        .Times(1)
        .WillOnce(Return(-2));

    int out = 0;
    EXPECT_EQ(-2, obj.virtual_function(out, 1));
    EXPECT_EQ(-1, virtual_member_wrapper(1));

    // Optionally tell BonoboMock to stop mocking, use the original sample_function.
    // Otherwise when the mock goes out of scope the behavior will be automatically restored.
    mock->restore();

    EXPECT_EQ(0, obj.virtual_function(out, 1));
    EXPECT_EQ(0, virtual_member_wrapper(1));
}
```

## Mock protected virtual functions

You cannot pass a protected member function pointer directly to `BONOBO_MOCK_VIRTUAL` because it is inaccessible from test code. The workaround is to create a derived **helper class** that exposes the pointer through a public static method.

> **Note:** `BONOBO_MOCK_VIRTUAL` requires the class to have a default constructor (no arguments). For classes without a default constructor, use [`BONOBO_MOCK_VIRTUAL_ON`](#classes-without-default-constructor-bonobo_mock_virtual_on) instead, which accepts an existing object instance to extract the virtual function address.


### Define the class and helper

```c++
class BaseClassProtected {
protected:
    virtual bool protected_virtual_function(bool) = 0;
};

class SampleClassProtected : public BaseClassProtected {
public:
    bool call_protected_virtual(bool in) {
        return protected_virtual_function(in);
    }

protected:
    virtual bool protected_virtual_function(bool in) {
        return !in;
    }
};

// Derived helper that exposes the protected function pointer
class Helper : public SampleClassProtected {
public:
    typedef bool(Helper::*func_type_virtual)(bool);

    static func_type_virtual get_virtual_func() {
        return &Helper::protected_virtual_function;
    }
};
```

### Write the test

```c++
TEST(Protected, Mock_virtual_protected) {
#ifdef BSLS_COMPILERFEATURES_FULL_CPP11
    auto mock = BONOBO_MOCK_VIRTUAL(Helper::get_virtual_func());
#else
    bsl::shared_ptr<GMock<bool(void*, bool)> > mock =
        BONOBO_MOCK_VIRTUAL(Helper::get_virtual_func());
#endif

    SampleClassProtected obj;
    EXPECT_CALL(*mock, BONOBO_MOCK_FUNCTION(_, _))
        .Times(1)
        .WillOnce(Return(true));

    EXPECT_TRUE(obj.call_protected_virtual(true));

    mock->restore();

    EXPECT_FALSE(obj.call_protected_virtual(true));
}
```

For non-virtual protected function mocking details, see [Mock Protected Functions](./mock-protected-functions.md).

## Mock private virtual functions

Private virtual functions are mocked using the same `BONOBO_MOCK_PRIVATE_*` macros as non-virtual private functions. See [Mock Private Functions](./mock-private-functions.md) for the full recipe.

## Example source code

You can find additional examples among the unit test files for the library under `tests/unit/`.

---

[← Back to Cookbook](index.md)

[← Documentation Home](../index.md)
