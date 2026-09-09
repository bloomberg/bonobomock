# Mock Overloaded Functions

This recipe shows how to mock overloaded functions — static, member, or template — using [BonoboMock](../index.md).

> **Note:** In optimized builds (e.g., CMake build types `RelWithDebInfo` or `Release`), the compiler may inline functions, preventing BonoboMock from intercepting calls. See [Function inlining](../reference/limitations.md#function-inlining) for this limitation and the available mitigations using the [optimization macros](../reference/optimization-macros.md) and [CMake helper](../reference/cmake-helper.md).

> **Note:** In C++, a function can be virtual even without the `virtual` keyword -- if any base class declares a function with the same signature as `virtual`, it is implicitly virtual in all derived classes. If that is the case, you must use [virtual function mocking](./mock-virtual-functions.md) instead. See [Implicitly Virtual Functions](./implicitly-virtual-functions.md) for details.

## Core technique: typed function pointers

Overloaded functions in C++ share the same function name. `BONOBO_MOCK` can't disambiguate by name alone, so you use **typed function pointers** to select the correct overload. Define a `typedef` with the exact signature of the overload you want to mock, assign the function address to a variable of that type, and pass the variable to `BONOBO_MOCK`.

## Overloaded static functions

Each overload gets its own function-pointer typedef to disambiguate it.

### Define the overloaded static functions

```c++
class SampleClass {
public:
    static int sample_function(int a) {
        return a * 2;
    }

    static int sample_function(int a, int b) {
        return a + b;
    }
};
```

### Mock each overload

```c++
TEST(OverloadedStatic, Mock) {
    typedef int(*FUNC_TYPE_1)(int);
    FUNC_TYPE_1 functor1 = &SampleClass::sample_function;

    typedef int(*FUNC_TYPE_2)(int, int);
    FUNC_TYPE_2 functor2 = &SampleClass::sample_function;

    auto mock1 = BONOBO_MOCK(functor1);
    auto mock2 = BONOBO_MOCK(functor2);

    EXPECT_CALL(*mock1, BONOBO_MOCK_FUNCTION(_))
        .WillOnce(Return(100));

    EXPECT_CALL(*mock2, BONOBO_MOCK_FUNCTION(_, _))
        .WillOnce(Return(200));

    EXPECT_EQ(100, SampleClass::sample_function(5));
    EXPECT_EQ(200, SampleClass::sample_function(5, 10));

    mock1->restore();
    mock2->restore();

    EXPECT_EQ(10, SampleClass::sample_function(5));
    EXPECT_EQ(15, SampleClass::sample_function(5, 10));
}
```

Because these are static (non-member) functions, the `BONOBO_MOCK_FUNCTION` arguments correspond directly to the function parameters — there is no leading `_` for an object pointer.

## Overloaded template member functions

This is a more advanced case that combines overloaded functions with templates and member-function pointer syntax. For member functions the typedef uses `ReturnType(ClassName::*)(Args...)` instead of a plain function pointer.

### Define the overloaded template member functions

```c++
template<typename A>
class SampleTemplateClass {
public:
    template<typename B>
    long sample_function(B b, B c) {
        long res = b + c;
        if (b % 2 == 0) {
            if (c % 2 != 0) {
                res += c * 2;
            } else {
                res += b * 2;
            }
        } else if (b > c) {
            res -= c;
        } else {
            res += b;
        }
        return res;
    }

    template<typename B>
    long sample_function(B b, B c, A d) {
        long res = b + c + d;
        if (b % 2 == 0) {
            if (c % 2 != 0) {
                res += c * 2;
            } else if (d % 2 != 0) {
                res += d * 2;
            } else {
                res += b * 2;
            }
        } else if (b > c) {
            res -= c;
        } else if (d > b) {
            res += d;
        } else {
            res += b;
        }
        return res;
    }

    template<typename B>
    long sample_function(B b, B c) const {
        long res = b + c;
        if (b % 2 != 0) {
            if (c % 2 == 0) {
                res += c * 2;
            } else {
                res += b * 2;
            }
        } else if (b < c) {
            res -= c;
        } else {
            res += b;
        }
        return res;
    }
};

long sample_function_wrapper_for_template(long a, long b) {
    SampleTemplateClass<int> obj;
    return obj.sample_function(a, b, 0);
}
```

There are 3 template member functions in template class `SampleTemplateClass` sharing the same name: `sample_function`. Function `sample_function_wrapper_for_template` demonstrates that BonoboMock can intercept calls on objects the test does not control (all-instance matching).

Each overload gets its own member-function-pointer typedef. Note the `ClassName::*` syntax and the trailing `const` for the const overload:

- `functor1` → `long(SampleTemplateClass<int>::*)(long, long)` — non-const, two args
- `functor2` → `long(SampleTemplateClass<int>::*)(long, long, int)` — non-const, three args
- `functor3` → `long(SampleTemplateClass<int>::*)(long, long) const` — const, two args

### Mock each overload

```c++
TEST(Template, Mock) {
    typedef long(SampleTemplateClass<int>::*FUNC_TYPE_1)(long, long);
    FUNC_TYPE_1 functor1 = &SampleTemplateClass<int>::sample_function;

    typedef long(SampleTemplateClass<int>::*FUNC_TYPE_2)(long, long, int);
    FUNC_TYPE_2 functor2 = &SampleTemplateClass<int>::sample_function;

    typedef long(SampleTemplateClass<int>::*FUNC_TYPE_3)(long, long) const;
    FUNC_TYPE_3 functor3 = &SampleTemplateClass<int>::sample_function;

#ifdef BSLS_COMPILERFEATURES_FULL_CPP11
    auto mock1 = BONOBO_MOCK(functor1);
    auto mock2 = BONOBO_MOCK(functor2);
    auto mock3 = BONOBO_MOCK(functor3);
#else
    bsl::shared_ptr<GMock<long(void*, long, long)> > mock1 = 
        BONOBO_MOCK(functor1);
    bsl::shared_ptr<GMock<long(void*, long, long, int)> > mock2 = 
        BONOBO_MOCK(functor2);
    bsl::shared_ptr<GMock<long(const void*, long, long)> > mock3 = 
        BONOBO_MOCK(functor3);
#endif

    EXPECT_CALL(*mock1, BONOBO_MOCK_FUNCTION(_, _, _))
        .Times(1)
        .WillOnce(Return(100));

    EXPECT_CALL(*mock2, BONOBO_MOCK_FUNCTION(_, _, _, _))
        .Times(2)
        .WillOnce(Return(101))
        .WillOnce(Return(102));

    EXPECT_CALL(*mock3, BONOBO_MOCK_FUNCTION(_, _, _))
        .Times(1)
        .WillOnce(Return(103));

    SampleTemplateClass<int> obj;

    EXPECT_EQ(100, obj.sample_function<long>(0, 0));
    EXPECT_EQ(101, obj.sample_function<long>(0, 0, 0));
    EXPECT_EQ(102, sample_function_wrapper_for_template(0, 0));

    const SampleTemplateClass<int> obj_const;
    EXPECT_EQ(103, obj_const.sample_function<long>(0, 0));

    // Tell BonoboMock to stop mocking, use the original sample_function.
    mock1->restore();
    mock2->restore();
    mock3->restore();

    EXPECT_EQ(0, obj.sample_function<long>(0, 0));
    EXPECT_EQ(0, obj.sample_function<long>(0, 0, 0));
    EXPECT_EQ(0, sample_function_wrapper_for_template(0, 0));
    EXPECT_EQ(0, obj_const.sample_function<long>(0, 0));
}
```

## Example source code

You can find additional examples among the unit test files for the library under `tests/unit/`.

---

[← Back to Cookbook](index.md)

[← Documentation Home](../index.md)
