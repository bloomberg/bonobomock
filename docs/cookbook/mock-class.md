# Mock Classes

Mock classes let you create a mock counterpart for a class, similar to how gMock's `MOCK_METHOD` creates mock implementations of virtual functions. Instead of managing individual mock pointers, you define a mock class for the target class and use gMock-style `EXPECT_CALL` syntax.

This works with static methods, non-virtual member functions, and virtual member functions.

## Motivation

Without mock classes, mocking multiple methods requires managing separate mock pointers:

```c++
auto mock1 = BONOBO_MOCK(&CallbackUtil::callbackForRequest);
auto mock2 = BONOBO_MOCK(&CallbackUtil::callbackForResponse);

EXPECT_CALL(*mock1, BONOBO_MOCK_FUNCTION(arg1, arg2));
EXPECT_CALL(*mock2, BONOBO_MOCK_FUNCTION(arg1));
```

With mock classes, you define a mock for the entire class and use method names directly:

```c++
struct CallbackUtilMock {
    BONOBO_MOCK_METHOD(CallbackUtil, callbackForRequest);
    BONOBO_MOCK_METHOD(CallbackUtil, callbackForResponse);
};

CallbackUtilMock cbUtil;

EXPECT_CALL(cbUtil, callbackForRequest(arg1, arg2));
EXPECT_CALL(cbUtil, callbackForResponse(arg1));
```

## Defining a mock class

Use `BONOBO_MOCK_METHOD(ClassName, methodName)` as a member declaration inside a struct. A mock class should correspond to a single target class, listing the methods you want to mock:

```c++
struct UtilityMock {
    BONOBO_MOCK_METHOD(Utility, compute);
    BONOBO_MOCK_METHOD(Utility, validate);
};
```

This is analogous to how a gMock mock class mirrors a single interface:

```c++
// gMock virtual function mock (for comparison)
struct MockUtility : Utility {
    MOCK_METHOD(int, compute, (int a, int b), (override));
    MOCK_METHOD(bool, validate, (int value), (override));
};
```

Each `BONOBO_MOCK_METHOD(Class, method)` declaration creates a mock for `Class::method` that is activated when the struct is constructed and automatically restored when it is destroyed (RAII).

## Static methods

For static methods, the `EXPECT_CALL` arguments match the method signature directly:

```c++
struct UtilityMock {
    BONOBO_MOCK_METHOD(Utility, compute);
};

UtilityMock mock;

EXPECT_CALL(mock, compute(1, 2))
    .WillOnce(::testing::Return(42));

EXPECT_EQ(42, Utility::compute(1, 2));
```

## Non-virtual and virtual member functions

For member functions (non-virtual and virtual), BonoboMock includes the object pointer as the first parameter. Use `_` or a specific matcher for it:

```c++
struct WidgetMock {
    BONOBO_MOCK_METHOD(Widget, process);
};

WidgetMock mock;

// Use _ to match any object instance
EXPECT_CALL(mock, process(_, 42))
    .WillOnce(::testing::Return(true));
```

This is consistent with how the one-argument `BONOBO_MOCK` handles member functions.

## Using in a test fixture

```c++
struct UtilityMock {
    BONOBO_MOCK_METHOD(Utility, compute);
    BONOBO_MOCK_METHOD(Utility, validate);
};

struct MyTest : ::testing::Test {
    UtilityMock d_util;
};

TEST_F(MyTest, exampleTest) {
    EXPECT_CALL(d_util, compute(1, 2))
        .WillOnce(::testing::Return(42));

    EXPECT_CALL(d_util, validate(42))
        .WillOnce(::testing::Return(true));

    // Call the code under test that uses Utility::compute and Utility::validate
}
```

The mocks are active for the lifetime of the test fixture and automatically cleaned up after each test.

## Strict and nice variants

Use `BONOBO_MOCK_METHOD_STRICT` or `BONOBO_MOCK_METHOD_NICE` for strict or nice mock semantics:

```c++
struct StrictUtilityMock {
    BONOBO_MOCK_METHOD_STRICT(Utility, compute);  // fails on unexpected calls
};

struct NiceUtilityMock {
    BONOBO_MOCK_METHOD_NICE(Utility, compute);    // silently ignores unexpected calls
};
```

These behave identically to gMock's `StrictMock` and `NiceMock` wrappers.

## Overloaded functions

When a class has overloaded methods, `BONOBO_MOCK_METHOD` cannot disambiguate them. Use `BONOBO_MOCK_METHOD_AS` to specify an alias and the function pointer type:

```c++
struct OverloadedMock {
    BONOBO_MOCK_METHOD_AS(Utility, compute, computeOne, int(*)(int));

    // For signatures with commas, use a type alias:
    using ComputeTwoPtr = int(*)(int, int);
    BONOBO_MOCK_METHOD_AS(Utility, compute, computeTwo, ComputeTwoPtr);
};

OverloadedMock mock;

EXPECT_CALL(mock, computeOne(5));
EXPECT_CALL(mock, computeTwo(1, 2));
```

`BONOBO_MOCK_METHOD_STRICT_AS` and `BONOBO_MOCK_METHOD_NICE_AS` variants are also available.

## Requirements

- C++11 or later
- Itanium ABI (`BONOBO_MOCK_IS_ITANIUM_ABI`), which covers GCC and Clang on all platforms. On non-Itanium ABIs (e.g., SunPro on Solaris), use the explicit `BONOBO_MOCK()`, `BONOBO_MOCK_VIRTUAL_*`, and related macros instead.
- Mock class structs must be defined at namespace or class scope (not inside function bodies), because the macro generates template member functions.

## Example source code

You can find additional examples among the unit test files for the library under `tests/unit/`.
