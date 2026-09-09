# Mock Protected Function

In this example we are going to show you how to mock and test a protected function using [BonoboMock](../index.md).

> **Note:** In optimized builds (e.g., CMake build types `RelWithDebInfo` or `Release`), the compiler may inline functions, preventing BonoboMock from intercepting calls. See [Function inlining](../reference/limitations.md#function-inlining) for this limitation and the available mitigations using the [optimization macros](../reference/optimization-macros.md) and [CMake helper](../reference/cmake-helper.md).

> **Note:** In C++, a function can be virtual even without the `virtual` keyword -- if any base class declares a function with the same signature as `virtual`, it is implicitly virtual in all derived classes. Make sure you are using the correct mocking approach (virtual vs. non-virtual) for your protected function. See [Implicitly Virtual Functions](./implicitly-virtual-functions.md) for details.

> **Note:** If your project uses C++03, `auto` is unavailable. Explicitly declare the mock type instead — see [Explicit Mock Object Types](mock-object-types.md).

## Extract protected function address

We need to find a way to extract the address of the protected functions so that BonoboMock can mock them.

For example there is a class `SampleClassProtected` that has one non-virtual protected function and one virtual protected one:

```c++
class BaseClassProctected {
protected:
    virtual bool protected_virtual_function(bool) = 0;
};

// The SampleClassProtected class contains a protected for us to mock.
class SampleClassProtected : public BaseClassProctected {
public:
    static bool sample_function(bool in) {
        return in;
    }

    int call_protected(int* in) {
        return protected_member_function(in);
    }

    bool call_protected_virtual(bool in) {
        return protected_virtual_function(in);
    }

protected:
    BONOBO_MOCK_DISABLE_FUNCTION_OPTIMIZATION_START(protected_member_function)
    int protected_member_function(int* in) {
        return *in;
    }
    BONOBO_MOCK_DISABLE_FUNCTION_OPTIMIZATION_END(protected_member_function)

    virtual bool protected_virtual_function(bool in) {
        return !in;
    }
};
```

We can define a child class of `SampleClassProtected` that exposes a public interface to return the address of these protected functions:

```c++
class childClass: public SampleClassProtected
{
public:
    typedef int(childClass::*func_type)(int*);

    typedef bool(childClass::*func_type_virtual)(bool);

    static func_type get_func() {
        return &childClass::protected_member_function;
    }

    static func_type_virtual get_virtual_func() {
        return &childClass::protected_virtual_function;
    }

    static bool get_virtual_func_type(bool in) {
        childClass obj;
        return obj.protected_virtual_function(in);
    }
};
```

With that you can mock the protected functions like:

```c++
    auto mock = BONOBO_MOCK(childClass::get_func());
```

and

```c++
    auto mock = BONOBO_MOCK_VIRTUAL(childClass::get_virtual_func());
```

For more information on mocking, please read [Mock Non-virtual Member Function](./mock-non-virtual-functions.md) and [Mock Virtual Member Function](./mock-virtual-functions.md).

## Example source code

You can find additional examples among the unit test files for the library under `tests/unit/`.

---

[← Back to Cookbook](index.md)

[← Documentation Home](../index.md)
