# Macro API Reference

Complete reference for all BonoboMock macros.

## Core macros

### `BONOBO_MOCK(function_pointer)`

Declare a mock for a free function, static member function, or non-virtual member function. Returns a mock object (`bsl::shared_ptr<GMock<...>>`).

On Itanium ABI compilers (GCC, Clang) with C++11 or later, `BONOBO_MOCK` also handles virtual member functions — it auto-detects whether the function is virtual and resolves its address accordingly. On SunPro or C++03, use `BONOBO_MOCK_VIRTUAL` for virtual functions instead.

**Do not** use this macro for private member functions — use the `BONOBO_MOCK_PRIVATE_*` macros below.

```c++
auto mock = BONOBO_MOCK(&free_function);
auto mock = BONOBO_MOCK(&MyClass::static_method);
auto mock = BONOBO_MOCK(&MyClass::non_virtual_method);
auto mock = BONOBO_MOCK(&MyClass::virtual_method);  // Itanium ABI + C++11 only
```

### `BONOBO_MOCK_FUNCTION(matchers...)`

Used inside `EXPECT_CALL` to specify argument matchers for the mocked function. Works with all mock types.

- For **free/static functions**: matchers correspond directly to function arguments.
- For **member functions**: the first matcher is the object pointer (`_` for any object, or `&obj` for a specific object), followed by the function arguments.

```c++
EXPECT_CALL(*mock, BONOBO_MOCK_FUNCTION(_, arg1_matcher, arg2_matcher));
```

## Virtual function macros

### `BONOBO_MOCK_VIRTUAL(function_pointer)` -- All compilers

Declare a mock for a virtual member function. Required on SunPro and C++03; on Itanium ABI + C++11, `BONOBO_MOCK` handles virtual functions automatically. Requires the class to have a default constructor.

```c++
auto mock = BONOBO_MOCK_VIRTUAL(&MyClass::virtual_method);
```

### `BONOBO_MOCK_VIRTUAL_ON(instance, function_pointer)` -- All compilers

Declare a mock for a virtual member function on a class without a default constructor. The `instance` is used to extract the virtual function address.

```c++
MyClass instance(args...);
auto mock = BONOBO_MOCK_VIRTUAL_ON(instance, &MyClass::virtual_method);
```

## Private static function macros

### `BONOBO_MOCK_PRIVATE_STATIC(fully_qualified_function, free_function_ptr)`

Declare a mock for a private static member function. On first use it resolves the function address via symbol table lookup (auto-detecting the current executable path with BDE's `bdls::ProcessUtil`); see [Internals: Private function address extraction](internals.md#private-function-address-extraction). The second argument is a free function with the same signature — used only for type deduction, never called.

```c++
auto mock = BONOBO_MOCK_PRIVATE_STATIC(
    Namespace::Class::private_static_method,
    &function_with_same_signature);
```

### `BONOBO_MOCK_PRIVATE_STATIC_STRICT(fully_qualified_function, free_function_ptr)`

Equivalent to `BONOBO_MOCK_PRIVATE_STATIC`, but creates a strict mock (fails on unexpected calls).

### `BONOBO_MOCK_PRIVATE_STATIC_NICE(fully_qualified_function, free_function_ptr)`

Equivalent to `BONOBO_MOCK_PRIVATE_STATIC`, but creates a nice mock (silently ignores unexpected calls).

## Private member function macros (non-static)

### `BONOBO_MOCK_PRIVATE_NON_CONST(fully_qualified_function, class, free_function_ptr)`

Declare a mock for a non-const private member method. On first use it resolves the function address via symbol table lookup (auto-detecting the current executable path with BDE's `bdls::ProcessUtil`); see [Internals: Private function address extraction](internals.md#private-function-address-extraction). The third argument is a free function with the same signature.

```c++
auto mock = BONOBO_MOCK_PRIVATE_NON_CONST(
    Namespace::Class::private_method,
    Namespace::Class,
    &define_private_method);
```

### `BONOBO_MOCK_PRIVATE_CONST(fully_qualified_function, class, free_function_ptr)`

Declare a mock for a const private member method.

```c++
auto mock = BONOBO_MOCK_PRIVATE_CONST(
    Namespace::Class::private_const_method,
    Namespace::Class,
    &define_private_const_method);
```

## Mock class macros (C++11+)

### `BONOBO_MOCK_METHOD(Class, method)`

Use as a member declaration in a mock struct. Creates a mock for `Class::method` with gMock-style `EXPECT_CALL` syntax. Works with static methods, non-virtual member functions, and virtual member functions.

```c++
struct UtilityMock {
    BONOBO_MOCK_METHOD(Utility, compute);
};
```

### `BONOBO_MOCK_METHOD_AS(Class, method, alias, Signature)`

Like `BONOBO_MOCK_METHOD`, but for overloaded functions. Disambiguates by specifying the function pointer type and provides an alias for use in `EXPECT_CALL`.

```c++
struct OverloadedMock {
    BONOBO_MOCK_METHOD_AS(Utility, compute, computeOne, int(*)(int));
};
```

### `BONOBO_MOCK_METHOD_STRICT` / `BONOBO_MOCK_METHOD_NICE`

Strict and nice variants of `BONOBO_MOCK_METHOD`. Strict mocks fail on unexpected calls; nice mocks silently ignore them. Corresponding `_AS` variants are also available (`BONOBO_MOCK_METHOD_STRICT_AS`, `BONOBO_MOCK_METHOD_NICE_AS`).

See [Mock Classes](../cookbook/mock-class.md) for full usage examples.

## Constructor side-effect suppression (link dummying)

Constructors and destructors cannot be *mocked* (see
[Limitations: Constructors and destructors](limitations.md#constructors-and-destructors)).
When the goal is only to stop a constructor's **side effects** (I/O, network,
registration) from running, these macros provide empty definitions that the
linker uses in place of the real constructor and destructor. The real object
still links, so the class's vtable and other methods remain intact and can be
mocked with `BONOBO_MOCK`.

Use at **namespace scope**. The leaf class name must be passed explicitly (the
preprocessor cannot extract it from the qualified name), and the signature is a
parenthesized parameter-type list. The test target must be built with the
[`ALLOW_CONSTRUCTOR_DUMMIES`](cmake-helper.md) option of
`add_bonobomock_executable()`; using a dummy macro without it is a compile error.

See the [Suppress Constructor Side Effects](../cookbook/suppress-constructor-side-effects.md)
cookbook recipe for a full example, and
[Limitations](limitations.md#constructors-and-destructors) for the constraints
(non-default-constructible members, statically linked dependencies, etc.).

### `BONOBO_DUMMY_CONSTRUCTOR(qualified_class, leaf_name, signature)`

Provide an empty definition for one constructor of the class.

```c++
BONOBO_DUMMY_CONSTRUCTOR(ns::Widget, Widget, (int))
```

### `BONOBO_DUMMY_CONSTRUCTOR_WITH_INIT(qualified_class, leaf_name, signature, ...)`

Like `BONOBO_DUMMY_CONSTRUCTOR`, but appends the trailing arguments as a
member-initializer list. Use it when the class has a reference, `const`, or
non-default-constructible member that an empty body cannot initialize. Name the
signature's parameters to forward them to members.

```c++
BONOBO_DUMMY_CONSTRUCTOR_WITH_INIT(ns::Widget, Widget, (int id), d_dep(id))
```

### `BONOBO_DUMMY_DESTRUCTOR(qualified_class, leaf_name)`

Provide an empty definition for the class's destructor.

```c++
BONOBO_DUMMY_DESTRUCTOR(ns::Widget, Widget)
```

### `BONOBO_DUMMY_CONSTRUCTOR_AND_DESTRUCTOR(qualified_class, leaf_name, signature)`

Convenience for the common case: dummies both the constructor and the
destructor. Dummy both together — the empty constructor skips initialization, so
running the real destructor on the resulting object risks undefined behavior.

```c++
BONOBO_DUMMY_CONSTRUCTOR_AND_DESTRUCTOR(ns::Widget, Widget, (int))
```

### `BONOBO_DUMMY_CONSTRUCTOR_AND_DESTRUCTOR_WITH_INIT(qualified_class, leaf_name, signature, ...)`

Combines `BONOBO_DUMMY_CONSTRUCTOR_WITH_INIT` and `BONOBO_DUMMY_DESTRUCTOR`: the common
case for a class that has a member-initializer requirement.

```c++
BONOBO_DUMMY_CONSTRUCTOR_AND_DESTRUCTOR_WITH_INIT(ns::Widget, Widget, (int id), d_dep(id))
```

## Quick reference table

| Macro | Use for | Compiler support |
|-------|---------|----------|
| `BONOBO_MOCK` | Free, static, non-virtual functions (+ virtual on Itanium ABI + C++11) | All compilers |
| `BONOBO_MOCK_FUNCTION` | Argument matchers in `EXPECT_CALL` | All compilers |
| `BONOBO_MOCK_VIRTUAL` | Virtual functions (default constructor) | All compilers |
| `BONOBO_MOCK_VIRTUAL_ON` | Virtual functions (no default constructor) | All compilers |
| `BONOBO_MOCK_PRIVATE_STATIC` | Declare private static mock | All compilers |
| `BONOBO_MOCK_PRIVATE_STATIC_STRICT` / `_NICE` | Strict/nice private static mock | All compilers |
| `BONOBO_MOCK_PRIVATE_NON_CONST` | Declare non-const private mock | All compilers |
| `BONOBO_MOCK_PRIVATE_CONST` | Declare const private mock | All compilers |
| `BONOBO_MOCK_METHOD` | Mock class member declaration | C++11+, Itanium ABI |
| `BONOBO_MOCK_METHOD_AS` | Mock class member for overloads | C++11+, Itanium ABI |
| `BONOBO_MOCK_METHOD_STRICT` / `_NICE` | Strict/nice mock class members | C++11+, Itanium ABI |
| `BONOBO_DUMMY_CONSTRUCTOR` | Suppress a constructor's side effects | All compilers |
| `BONOBO_DUMMY_CONSTRUCTOR_WITH_INIT` | As above, with a member-initializer list | All compilers |
| `BONOBO_DUMMY_DESTRUCTOR` | Suppress a destructor's side effects | All compilers |
| `BONOBO_DUMMY_CONSTRUCTOR_AND_DESTRUCTOR` | Suppress both (common case) | All compilers |
| `BONOBO_DUMMY_CONSTRUCTOR_AND_DESTRUCTOR_WITH_INIT` | Suppress both, with a member-initializer list | All compilers |

---
[← Back to Documentation Home](../index.md)
