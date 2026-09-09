# Cookbook

Step-by-step recipes for mocking different types of functions with BonoboMock. Each recipe includes a complete working example.

## Mocking individual functions

Recipes for mocking specific function types using `BONOBO_MOCK` and its variants.

| Recipe | Description | Platform |
|--------|-------------|----------|
| [Free Functions](mock-free-functions.md) | Mock free (global) functions, including `extern "C"` functions | All platforms |
| [Static Functions](mock-static-functions.md) | Mock static member functions | All platforms |
| [Non-virtual Functions](mock-non-virtual-functions.md) | Mock non-virtual member functions (per-instance or all-instance matching) | All platforms |
| [Virtual Functions](mock-virtual-functions.md) | Mock virtual member functions (incl. protected and private) | All platforms |
| [Protected Functions](mock-protected-functions.md) | Mock non-virtual protected member functions | All platforms |
| [Private Functions](mock-private-functions.md) | Mock private member functions (static and non-static) | All platforms |
| [Overloaded Functions](mock-overloaded-functions.md) | Mock overloaded functions (static, member, and template) | All platforms |
| [Variadic Functions](mock-variadic-functions.md) | Mock variadic template and C-style variadic functions | All platforms, C++11+ |
| [Lambda Functions](mock-lambda-functions.md) | Mock lambda functions | All platforms, C++11+ |

## Mock class approach

An alternative higher-level pattern for mocking an entire class at once using `BONOBO_MOCK_METHOD`.

| Recipe | Description | Platform |
|--------|-------------|----------|
| [Mock Classes](mock-class.md) | gMock-style `EXPECT_CALL` syntax with `BONOBO_MOCK_METHOD` | C++11+, Itanium ABI only |

## Constructors

Recipes for dealing with constructors, which cannot be mocked directly.

| Recipe | Description | Platform |
|--------|-------------|----------|
| [Suppress Constructor Side Effects](suppress-constructor-side-effects.md) | Use `BONOBO_DUMMY_*` link dummying to stop a constructor's side effects | All platforms |

## Mock object recipes

Recipes for configuring and typing mock objects regardless of the function type being mocked.

| Recipe | Description | Platform |
|--------|-------------|----------|
| [Naggy, Nice, and Strict Mocks](mock-strictness.md) | Control behavior for unexpected calls | All platforms |
| [Explicit Mock Object Types](mock-object-types.md) | Declare mock types for C++03 projects or GoogleTest fixtures | All platforms |

## Which macro should I use?

| Function type | Macro |
|---------------|-------|
| Free / static / non-virtual | `BONOBO_MOCK` |
| Virtual (Itanium ABI + C++11, default constructor) | `BONOBO_MOCK` (auto-detects virtual functions) |
| Virtual (Itanium ABI + C++11, no default constructor) | `BONOBO_MOCK_VIRTUAL_ON` |
| Virtual (SunPro / C++03, default constructor) | `BONOBO_MOCK_VIRTUAL` |
| Virtual (SunPro / C++03, no default constructor) | `BONOBO_MOCK_VIRTUAL_ON` |
| Virtual protected | Expose pointer via derived helper class, then use `BONOBO_MOCK_VIRTUAL` — see [Virtual Functions: Protected](mock-virtual-functions.md#mock-protected-virtual-functions) |
| Private static | `BONOBO_MOCK_PRIVATE_STATIC` |
| Private non-static (virtual or non-virtual) | `BONOBO_MOCK_PRIVATE_NON_CONST` for non-const functions or `BONOBO_MOCK_PRIVATE_CONST` for const functions |

See [Macro API Reference](../reference/macros.md) for the full documentation of each macro.

---
[← Back to Documentation Home](../index.md)
