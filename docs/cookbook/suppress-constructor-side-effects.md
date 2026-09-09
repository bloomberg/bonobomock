# Suppress Constructor Side Effects

Constructors and destructors cannot be mocked (see
[Limitations: Constructors and destructors](../reference/limitations.md#constructors-and-destructors)).
But the usual reason to want to mock a constructor is to stop it from running
**side effects** — opening connections, doing I/O, registering globally. [BonoboMock](../index.md)
can suppress those with the `BONOBO_DUMMY_*` macros, which provide empty definitions
that the linker uses in place of the real constructor and destructor.

The real object still links, so the class's other methods stay intact and can be
mocked with `BONOBO_MOCK`. This is what makes the pattern useful: dummy the
side-effecting constructor, then mock the methods you care about.

> **Note:** This works against **statically linked** dependencies and requires
> the [`ALLOW_CONSTRUCTOR_DUMMIES`](../reference/cmake-helper.md) option (using a
> `BONOBO_DUMMY_*` macro without it is a compile error). See
> [Limitations](../reference/limitations.md#suppressing-constructor-side-effects-link-dummying)
> for the full constraints. Classes with reference or non-default-constructible
> members need the `*_WITH_INIT` macro variants, which take a member-initializer
> list.

## The class under test

Suppose a dependency provides a class whose constructor talks to a backend:

```c++
namespace tsadmapi {
class FirmHdr {
public:
    explicit FirmHdr(int pricingNumber);  // side effects: fetches firm data
    bool isValid() const;
    int traddt() const;
};
}
```

and the code under test constructs it directly:

```c++
bsl::optional<int> getTradeDate(int pricingNumber) {
    tsadmapi::FirmHdr firmHeader(pricingNumber);
    if (firmHeader.isValid()) {
        return firmHeader.traddt();
    }
    return bsl::nullopt;
}
```

## Write the unit test

Dummy the constructor and destructor at **namespace scope** (out-of-line member
definitions cannot appear inside an anonymous namespace), then mock the methods:

```c++
// Namespace scope. Pass the leaf class name explicitly and the parameter list
// in parentheses.
BONOBO_DUMMY_CONSTRUCTOR_AND_DESTRUCTOR(tsadmapi::FirmHdr, FirmHdr, (int))

TEST(GetTradeDate, ReturnsTradeDateWhenValid) {
    auto validMock = BONOBO_MOCK(&tsadmapi::FirmHdr::isValid);
    EXPECT_CALL(*validMock, BONOBO_MOCK_FUNCTION(_)).WillRepeatedly(Return(true));

    auto traddtMock = BONOBO_MOCK(&tsadmapi::FirmHdr::traddt);
    EXPECT_CALL(*traddtMock, BONOBO_MOCK_FUNCTION(_)).WillRepeatedly(Return(20260101));

    EXPECT_EQ(getTradeDate(123), bsl::optional<int>(20260101));
}

TEST(GetTradeDate, ReturnsNulloptWhenInvalid) {
    auto validMock = BONOBO_MOCK(&tsadmapi::FirmHdr::isValid);
    EXPECT_CALL(*validMock, BONOBO_MOCK_FUNCTION(_)).WillRepeatedly(Return(false));

    EXPECT_EQ(getTradeDate(123), bsl::nullopt);
}
```

`getTradeDate` constructs `FirmHdr` via the dummied constructor, so no backend
call happens; `isValid()` and `traddt()` are real methods redirected by `BONOBO_MOCK`
to exercise both branches.

## Enable the macros in CMake

The dummy definitions coexist with the real ones from the linked library, so the
target must be built with `ALLOW_CONSTRUCTOR_DUMMIES`:

```cmake
find_package(BonoboMockHelper REQUIRED)
add_bonobomock_executable(
    TARGET_NAME my_test.u.t
    TEST_FILES my_test.t.cpp
    ALLOW_CONSTRUCTOR_DUMMIES
)

target_link_libraries(my_test.u.t PRIVATE bonobomock the_dependency_library)
```

## Example source code

You can find a working example in the unit test files under `tests/unit/`
(`bonobomock_dummy_constructor.t.cpp` and `sample_side_effect_lib/`).

---

[← Back to Cookbook](index.md)

[← Documentation Home](../index.md)
