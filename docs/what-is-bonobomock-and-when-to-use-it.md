# What is BonoboMock and when should I use it?

BonoboMock is a GoogleTest-compatible C++ mocking library that uses [runtime binary patching](reference/internals.md#runtime-binary-patching) (aka monkey patching) to intercept function calls at runtime. Unlike traditional mocking frameworks, it can mock free functions, static methods, non-virtual and virtual member functions, and even private/protected methods -- without requiring the C++ code under test to be designed for testability.

<div style="width:100%;aspect-ratio:1200/735;overflow:hidden;">
  <iframe src="assets/animations/bonobomock/patching/index.html" style="width:100%;height:100%;border:none;" title="BonoboMock patching animation"></iframe>
</div>

> If the animation above does not display, [view it here](assets/animations/bonobomock/patching/index.html).

## The challenge: Testing C++ code with dependencies

Most C++ components depend on other components -- classes in the same project, linked libraries, databases, or remote services, for example. To unit-test in isolation, you must replace those dependencies with test doubles.

Consider a class like this:

```c++
class CompanyUtil {
  public:
    // Business logic we want to test
    static bsl::string produceDividendMessage(int companyID) {
        bsl::string name = getCompanyNameFromDb(companyID);
        bsl::string region = getRegionFromService(companyID);

        // Business logic combining results
        return "Company " + name + " (" + region + ") issued a dividend.";
    }

    static bsl::string getCompanyNameFromDb(int companyID) {
        // Hits a real database
    }

    static bsl::string getRegionFromService(int companyID) {
        // Calls a remote service
    }
};
```

Business logic is intertwined with hard-coded dependencies, and it is fully implemented as static functions. There is no way to replace the database or service calls with test doubles without making changes to the code or the build pipeline. As a result, the business logic cannot be tested in isolation. You may often encounter this pattern in legacy and/or third-party code.

## Traditional approaches

There are three common strategies to test code with hard dependencies like these:

### Dependency injection with virtual interfaces

Define an abstract interface for the dependency, provide a production implementation and a test mock using gMock, and inject the dependency via constructor or setter.

Trade-offs:

- Requires virtual functions, which introduce runtime overhead.
- The code must be designed upfront for testability.
- Retrofitting existing code requires extensive, risky refactoring.

### Link-time substitution

Provide an alternative translation unit with a different implementation of the dependency, and then link the test binary against it instead of the production version.

Trade-offs:

- Complicates the build pipeline.
- Obscures differences between test and production code.
- Reduces test clarity and maintainability.

### Manual mock classes

Write and maintain a hand-written mock class for each dependency. Use the mock in tests and the real class in production.

Trade-offs:

- Tedious and error-prone to write.
- Creates ongoing maintenance overhead.
- Can have its own limitations (e.g., inability to simulate certain behavior).

All three approaches require the code to be structured upfront for testability, or to undergo significant refactoring -- which is not always feasible for the software you may be seeking to test.

## How BonoboMock is different

BonoboMock patches the target function's entry point in memory at runtime, redirecting calls to a gMock-based handler. The original instructions are restored when the mock goes out of scope (RAII). This means:

- **No changes to the code under test.** No interfaces, no virtual functions, no dependency injection required.
- **Works with any function type.** Free functions, static methods, non-virtual member functions, virtual member functions, and private/protected methods are all supported.
- **Standard gMock expectations.** Uses the same `EXPECT_CALL` / `WillOnce` / `Return` API you already know from gMock.
- **Flexible test runner.** BonoboMock depends on gMock to provide an expectation engine, but the test runner is your choice -- it will work with GoogleTest or Catch2. See [Dependencies](supported-platforms.md#dependencies) for more details.


For example, testing `CompanyUtil` with BonoboMock requires zero refactoring:

```c++
TEST(CompanyUtilTest, ProduceDividendMessage) {
    auto mockDb = BONOBO_MOCK(&CompanyUtil::getCompanyNameFromDb);
    auto mockSvc = BONOBO_MOCK(&CompanyUtil::getRegionFromService);

    EXPECT_CALL(*mockDb, BONOBO_MOCK_FUNCTION(42))
        .WillOnce(Return("Acme Corp"));
    EXPECT_CALL(*mockSvc, BONOBO_MOCK_FUNCTION(42))
        .WillOnce(Return("AMER"));

    EXPECT_EQ("Company Acme Corp (AMER) issued a dividend.",
              CompanyUtil::produceDividendMessage(42));
}
```

For a detailed explanation of the patching mechanism, gMock integration, and call interception flow, see [Internals](reference/internals.md).

## When to use BonoboMock

Follow this priority order when deciding how to test code with dependencies:

1. **Refactor for testability (preferred).** If you can modify the code, introduce abstractions and dependency injection so dependencies can be replaced with standard gMock test doubles. For `CompanyUtil`, this would mean extracting the database and service calls behind injectable interfaces so that tests can supply mock implementations directly.

2. **Wrap in an interface.** When you depend on someone else’s component (or are dealing with legacy code you can’t change), write a small wrapper class that exposes the functionality behind an interface. Your code depends on the interface, not the original component, allowing you to inject a mock implementation during testing. If `CompanyUtil` belongs to a library you cannot modify, you could wrap it in your own thin adapter class that forwards calls to `CompanyUtil` but can be swapped for a mock in tests.

3. **Use BonoboMock.** When refactoring or wrapping is too costly, too risky, or impractical -- e.g., deeply embedded legacy code, third-party libraries, or code too fragile to change safely -- BonoboMock lets you mock the dependency directly without any code changes.

## Suggested use cases

- **Legacy code with hard-coded dependencies.** Static methods, free functions, or non-virtual member functions that call databases, services, or other components directly. BonoboMock lets you test the business logic without restructuring the code.
- **Third-party libraries you cannot modify.** When your code depends on a library that lacks virtual interfaces and you cannot add dependency injection at the source.
- **Retrofitting test coverage.** Adding unit-tests to an existing codebase that was not designed for testability, without touching production code.
- **Deeply coupled call chains.** Code where a dependency is buried several layers deep, making wrapper-based injection impractical without refactoring the entire chain.
- **Fortran interop.** Mocking Fortran functions called from C++ test code.
- **Exploratory testing.** Quickly writing tests to understand the behavior of unfamiliar code before deciding whether and how to refactor it.

## When NOT to use BonoboMock

**Do not use BonoboMock as a design strategy for new components.** New code should be designed with testability in mind using dependency injection and interfaces.

BonoboMock's ability to mock any function should never justify writing tightly coupled or non-modular code. If you are writing new code, it is recommended that you design it for testability from the start.

## Next steps

- [Supported Platforms](supported-platforms.md)
- [Core Concepts](core-concepts.md)
- [Project Setup](project-setup/index.md)

---

[← Back to Documentation Home](index.md)
