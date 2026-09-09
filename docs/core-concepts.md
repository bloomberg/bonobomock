# Core Concepts

This page introduces the core concepts of BonoboMock and walks through a basic example.

> **Prerequisites:**
> - Read [What is BonoboMock and when should I use it?](what-is-bonobomock-and-when-to-use-it.md) for an overview of the library.
> - This guide assumes familiarity with [GoogleTest and gMock](https://google.github.io/googletest/). If you are new to GoogleTest/gMock, please read the linked documentation first.

## How BonoboMock works

BonoboMock uses **runtime binary patching** to intercept function calls at runtime. When you mock a function, BonoboMock replaces its entry point in memory so that calls are redirected to a gMock object. This approach allows BonoboMock to mock functions that traditional interface-based mocking cannot, such as free functions, static methods, and non-virtual member functions.

> For a detailed explanation of the patching mechanism, gMock integration, and call interception flow, see [Internals](reference/internals.md).

## Core workflow

Every test that uses BonoboMock follows three steps:

1. **Declare** the mock using `BONOBO_MOCK`
2. **Define expectations** using `EXPECT_CALL` with `BONOBO_MOCK_FUNCTION`
3. **Call** the function under test (directly or through your Code-Under-Test) -- BonoboMock intercepts the call and applies your expectations

## Basic example

```c++
#include <bonobomock_api.h>
#include <gmock/gmock.h>
#include <gtest/gtest.h>

// A simple free function to mock
int add(int a, int b) {
    return a + b;
}

TEST(Primer, MockFreeFunction) {
    // Step 1: Declare the mock
    auto mock = BONOBO_MOCK(&add);

    // Step 2: Define expectations
    EXPECT_CALL(*mock, BONOBO_MOCK_FUNCTION(_, _))
        .WillOnce(Return(42));

    // Step 3: Call the function -- it returns the mocked value
    EXPECT_EQ(42, add(1, 2));

    // The mock auto-restores when it goes out of scope
}
```

## Understanding `BONOBO_MOCK_FUNCTION`

`BONOBO_MOCK_FUNCTION` is used inside `EXPECT_CALL` to specify gMock's matchers for the function's arguments:

- For **free/static functions**, the matchers correspond directly to the function's arguments.
- For **member functions**, the first matcher is a pointer to the class object (`_` matches any object), and the remaining matchers correspond to the function's arguments.

```c++
// Free function int sample(int a, int b):
// matchers map directly to arguments
EXPECT_CALL(*mock, BONOBO_MOCK_FUNCTION(arg1_matcher, arg2_matcher));

// Member function int MyClass::method(bool flag):
// first matcher is the object pointer
EXPECT_CALL(*mock, BONOBO_MOCK_FUNCTION(obj_ptr_or_wildcard, arg1_matcher));
```

See more examples in the appropriate sections of the [Cookbook](cookbook/index.md).

## Restoring original behavior

The mock object automatically restores the original function when it goes out of scope. You can also call `mock->restore()` to restore it manually.


## Mock object types

The simplest way to declare a mock object is with `auto`:

```c++
auto mock = BONOBO_MOCK(&sample_function);
```

If your project must compile with C++03 (where `auto` is unavailable) or you need a mock as a GoogleTest fixture member (where `auto` cannot be used for member variables), you must declare the type explicitly. See [Explicit Mock Object Types](cookbook/mock-object-types.md) for more details.


## Next steps

- [Add BonoboMock to your project](project-setup/index.md) to configure your build system.
- Browse the [Cookbook](cookbook/index.md) for step-by-step recipes for each function type.
- See [Macro API Reference](reference/macros.md) for the complete list of macros.

---

[← Back to Documentation Home](index.md)
