# BonoboMock CMake quickstart

The library under test contains no testing scaffolding at all: no virtual
interfaces, no dependency injection, no `#ifdef`s. The test replaces a **free
function** (`fetchLatestPrice`) and a **static member function**
(`Clock::nowUtcSeconds`) at their entry points -- two dependencies you cannot
substitute without editing the code that calls them.

This is the worked example behind
[Project Setup (CMake)](../../docs/project-setup/cmake.md), which covers
installing BonoboMock first. That guide assumes you know what `BONOBO_MOCK` and
`BONOBO_MOCK_FUNCTION` do; if you don't, start with
[Core Concepts](../../docs/core-concepts.md).

## Layout

```
cmake-quickstart/
├── CMakeLists.txt          # find_package()s, enable_testing(), add_subdirectory()
├── src/
│   ├── CMakeLists.txt      # the `portfolio` library target
│   ├── pricefeed.h/.cpp    # fetchLatestPrice() -- stand-in for a live price feed
│   ├── clock.h/.cpp        # Clock::nowUtcSeconds() -- the system clock
│   └── portfolio.h/.cpp    # code under test: Portfolio::value() calls both
└── tests/
    ├── CMakeLists.txt      # the `portfolio.t` test target, links `portfolio`
    └── portfolio.t.cpp     # three BonoboMock tests
```

Library sources in `src/`, tests in `tests/`, and a test target that links the
library rather than recompiling it.

## The dependencies

[`src/pricefeed.h`](src/pricefeed.h) and [`src/clock.h`](src/clock.h) declare
two things a unit test must not reach: a network price feed and the wall clock.
Neither is behind an interface.

```c++
// src/pricefeed.h
double fetchLatestPrice(const char* ticker);   // a live quote, over the network
```

```c++
// src/clock.h
class Clock {
public:
    static long long nowUtcSeconds();
};
```

```c++
// src/pricefeed.cpp
#include <pricefeed.h>

double fetchLatestPrice(const char* /* ticker */)
{
    return 0.0;  // a real feed would return a live quote over the network
}
```

## Code under test

In [`src/portfolio.h`](src/portfolio.h), `Portfolio::value()` prices every
holding and stamps the result. It calls both dependencies directly, and it
prices each distinct ticker only once:

```c++
// src/portfolio.h
struct Valuation {
    double    totalUsd;
    long long asOfUtcSeconds;
};

class Portfolio {
public:
    void addHolding(std::string ticker, int shares);
    Valuation value() const;
    // ...
};
```

```c++
// src/portfolio.cpp
Valuation Portfolio::value() const
{
    std::map<std::string, double> prices;

    double totalUsd = 0.0;
    for (const Holding& holding : d_holdings) {
        std::map<std::string, double>::const_iterator price = prices.find(holding.ticker);
        if (price == prices.end()) {
            price = prices.insert(std::make_pair(holding.ticker,
                                      fetchLatestPrice(holding.ticker.c_str())))
                        .first;
        }
        totalUsd += price->second * holding.shares;
    }

    Valuation valuation;
    valuation.totalUsd = totalUsd;
    valuation.asOfUtcSeconds = Clock::nowUtcSeconds();
    return valuation;
}
```

## The test

[`tests/portfolio.t.cpp`](tests/portfolio.t.cpp) replaces both dependencies, so
the test is fast, deterministic, and offline:

```c++
// tests/portfolio.t.cpp
#include <clock.h>
#include <portfolio.h>
#include <pricefeed.h>

#include <bonobomock_api.h>
#include <bsl_memory.h>   // bsl::shared_ptr
#include <gmock/gmock.h>
#include <gtest/gtest.h>

using ::testing::Return;
using ::testing::StrEq;

const long long k_FIXED_NOW = 1735689600LL;  // 2025-01-01T00:00:00Z

TEST(PortfolioTest, ValuesEveryHoldingAtTheLatestPrice)
{
    // The template parameter is the signature of the function being mocked.
    // A static member function has a plain free-function signature.
    bsl::shared_ptr<GMock<double(const char*)> > feed = BONOBO_MOCK(&fetchLatestPrice);
    bsl::shared_ptr<GMock<long long()> > clock = BONOBO_MOCK(&Clock::nowUtcSeconds);

    // Matching the ticker rather than `_` is what makes the test catch a wrong
    // symbol being forwarded to the feed.
    EXPECT_CALL(*feed, BONOBO_MOCK_FUNCTION(StrEq("IBM"))).WillOnce(Return(100.0));
    EXPECT_CALL(*feed, BONOBO_MOCK_FUNCTION(StrEq("MSFT"))).WillOnce(Return(50.0));
    EXPECT_CALL(*clock, BONOBO_MOCK_FUNCTION()).WillOnce(Return(k_FIXED_NOW));

    Portfolio portfolio;
    portfolio.addHolding("IBM", 10);
    portfolio.addHolding("MSFT", 4);

    const Valuation valuation = portfolio.value();

    EXPECT_DOUBLE_EQ(1200.0, valuation.totalUsd);
    EXPECT_EQ(k_FIXED_NOW, valuation.asOfUtcSeconds);

    // `feed` and `clock` restore the real functions when they go out of scope.
}
```

The file goes on to test two more things that only a mock can see: that a ticker
held twice is priced exactly once (`.Times(1)` on a cache with no other
observable effect), and that the real functions are back once the handles die.

## The CMake

The top level finds the packages and nothing else:

```cmake
# Matches the floor BonoboMock itself builds with.
cmake_minimum_required(VERSION 4.0)
project(bonobomock-quickstart LANGUAGES CXX)

# Provides bonobomock, and pulls in bsl and bdl transitively.
find_package(bonobomock REQUIRED)

# Found explicitly, because tests/CMakeLists.txt names GTest::gtest_main.
find_package(GTest REQUIRED)

# Provides add_bonobomock_executable(), which sets the flags (e.g. -fno-inline)
# BonoboMock needs to reliably intercept calls.
find_package(BonoboMockHelper REQUIRED)

enable_testing()

add_subdirectory(src)
add_subdirectory(tests)
```

[`src/CMakeLists.txt`](src/CMakeLists.txt) is an ordinary library target:

```cmake
add_library(portfolio STATIC clock.cpp portfolio.cpp pricefeed.cpp)

target_include_directories(portfolio PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
```

[`tests/CMakeLists.txt`](tests/CMakeLists.txt) builds the test target and links
the library:

```cmake
add_bonobomock_executable(TARGET_NAME portfolio.t TEST_FILES portfolio.t.cpp)

target_link_libraries(portfolio.t PRIVATE portfolio bonobomock GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(portfolio.t)
```

> **Doesn't the library get compiled without the no-inline flags?** Yes --
> `add_bonobomock_executable` applies them only to the sources it compiles, and
> `libportfolio.a` is built with the project's normal settings. That is fine
> here: the mocked functions are defined in different translation units from
> their caller, so without LTO the compiler never sees a body to inline and
> every call survives as a real `call` instruction. It stops being fine when the
> definition *is* visible at the call site -- a header-defined or same-TU
> function, or an LTO build -- and then you protect the definition with
> `bonobomock-optimization-macros` and recompile it into the test target with the
> helper's `FILES_TO_RECOMPILE`. See
> [Function inlining](../../docs/reference/limitations.md#function-inlining) and
> the [CMake Helper Reference](../../docs/reference/cmake-helper.md).

## Build and run

First build and install BonoboMock (and its dependencies) into a prefix by
following [Project Setup (CMake)](../../docs/project-setup/cmake.md).
Then point this project at that prefix:

```bash
cmake -B build -S . -DCMAKE_BUILD_TYPE=Debug -DCMAKE_CXX_STANDARD=17 \
    -DCMAKE_PREFIX_PATH=/path/to/install
cmake --build build
ctest --test-dir build --output-on-failure
```

`CMAKE_CXX_STANDARD` must match the standard BonoboMock and BDE were built with.

You should see all three tests pass:

```
100% tests passed, 0 tests failed out of 3
```

### Optimized builds

The same tests pass unchanged with `-DCMAKE_BUILD_TYPE=RelWithDebInfo`, for the
translation-unit reason described above.
