# Explicit Mock Object Types

If your project uses C++11, you can use `auto` to declare mock objects:

```c++
auto mock = BONOBO_MOCK(&sample_function);
```

However, you must declare the type explicitly when:
- Your project uses C++03 (which doesn't support `auto`)
- Adding mock objects as members in GoogleTest fixture classes — C++ doesn't allow `auto` for member variables

In both cases, declare the mock type as `bsl::shared_ptr<GMock<SIGNATURE>>`, where the signature depends on the function type.

## Type rules

### Free / static functions

The GMock template parameter matches the function signature directly:

```c++
// int sample_function(int a, int b):
bsl::shared_ptr<GMock<int(int, int)> > mock = BONOBO_MOCK(&sample_function);
```

### Non-const member functions

Prepend `void*` as the first parameter (for the object pointer):

```c++
// int MyClass::method(bool flag):
bsl::shared_ptr<GMock<int(void*, bool)> > mock = BONOBO_MOCK(&MyClass::method);
```

### Const member functions

Prepend `const void*` as the first parameter:

```c++
// int MyClass::const_method(bool flag) const:
bsl::shared_ptr<GMock<int(const void*, bool)> > mock = BONOBO_MOCK(&MyClass::const_method);
```

## GoogleTest fixture example

When you need a mock as a member of a GoogleTest fixture class, you must use the explicit type since `auto` cannot be used for member variables:

```c++
#include <bonobomock_api.h>
#include <gmock/gmock.h>
#include <gtest/gtest.h>

int add(int a, int b) {
    return a + b;
}

class AddTest : public ::testing::Test {
  protected:
    // Must use explicit type — auto is not allowed for member variables
    bsl::shared_ptr<GMock<int(int, int)> > d_mock;

    void SetUp() {
        d_mock = BONOBO_MOCK(&add);
    }
};

TEST_F(AddTest, ReturnsMockedValue) {
    EXPECT_CALL(*d_mock, BONOBO_MOCK_FUNCTION(1, 2))
        .WillOnce(Return(42));

    EXPECT_EQ(42, add(1, 2));
}

TEST_F(AddTest, ReturnsZeroForAnyArgs) {
    EXPECT_CALL(*d_mock, BONOBO_MOCK_FUNCTION(_, _))
        .WillRepeatedly(Return(0));

    EXPECT_EQ(0, add(3, 4));
    EXPECT_EQ(0, add(5, 6));
}
```

Each `TEST_F` gets a fresh mock object because `SetUp()` runs before every test. The mock is automatically restored after each test when the fixture (and its members) is destroyed.

---

[← Back to Cookbook](index.md)

[← Documentation Home](../index.md)
