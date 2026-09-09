# Internals

This page explains how BonoboMock works under the hood. It is intended for contributors and curious users who want to better understand the mechanisms behind this library. You do not need this information to use BonoboMock effectively -- see the [Core Concepts](../core-concepts.md) and [Cookbook](../cookbook/index.md) for everyday usage.

**[Watch the animation: How BonoboMock patches functions at runtime](../assets/animations/bonobomock/patching/index.html)**

## Runtime binary patching

BonoboMock intercepts function calls by **patching machine instructions** at the target function's entry point. When you create a mock, BonoboMock overwrites the first few bytes of the original function with a jump instruction that redirects execution to a mock handler. When the mock is destroyed, the original bytes are restored.

The patching process works as follows:

1. **Extract the target address** -- You tell BonoboMock which function to mock, and BonoboMock resolves the address where that function's machine code begins. How it resolves that address depends on the function type:
   - **Global functions, public static functions, and non-virtual member functions** -- The user passes a function pointer (e.g., `&myFunction`, `&MyClass::staticMethod`). On supported platforms, taking a pointer to these functions yields the code address directly.
   - **Virtual functions** -- A pointer-to-member-function for a virtual function does not encode the code address directly; what it represents is ABI-dependent (e.g., a vtable offset in the Itanium ABI). BonoboMock uses compiler-specific techniques to resolve the actual implementation address. See [Virtual function address extraction](#virtual-function-address-extraction) below.
   - **Private functions** -- The symbol is not visible outside the class, so you cannot form a pointer to it at compile time. BonoboMock resolves the address at runtime via symbol table lookup. See [Private function address extraction](#private-function-address-extraction) below.
2. **Save original instructions** -- The first N bytes at the target address are copied into a buffer so they can be restored later.
3. **Make memory writable** -- Function code lives in read-only/execute-only memory pages. BonoboMock calls `mprotect()` to temporarily make the page (and the next page, in case the patch spans a page boundary) writable.
4. **Write jump instructions** -- Architecture-specific jump instructions are written to the target address, redirecting to the mock function.
5. **Restore page permissions** -- The memory pages are made non-writable again.

### Platform-specific jump instructions

**x86-64:**

BonoboMock uses one of two jump encodings depending on the distance between the original function and the mock function:

- **Short jump** (target within 2 GB): A 5-byte relative `JMP` instruction (`0xE9` + 4-byte signed offset).
- **Far jump** (target beyond 2 GB): A 5-byte relative `JMP` to an out-of-line trampoline allocated within 2 GB via `mmap`. The trampoline contains a 14-byte indirect `JMP` (`0xFF 0x25` + 4-byte RIP-relative offset + 8-byte absolute address). If the trampoline allocation fails, the 14-byte jump is written inline as a fallback.

**SPARC:**

- **32-bit SPARC**: BonoboMock first tries a single `ba,a` (branch always, annulled delay slot) instruction (4 bytes), which has a range of ±8 MB. If the mock function is beyond that range, it falls back to a 3-instruction sequence (12 bytes): `sethi` to load the upper 22 bits of the destination into `%g1`, `jmp %g1 + offset`, and a `nop` in the delay slot.
- **64-bit SPARC**: Constructing a full 64-bit jump address requires 7 instructions (28 bytes), which is too large for many small functions. BonoboMock places this 28-byte jump in an out-of-line trampoline allocated via `mmap`, and writes a short branch to it at the function entry point. Two layers are tried:
    1. **4-byte patch** (`ba,a`): If a trampoline can be allocated within ±8 MB, a single `ba,a` instruction is written. This is only 4 bytes, making even the smallest leaf functions (8 bytes) safe to mock. The `ba,a` instruction does not clobber `%o7`, so the caller's return address is preserved.
    2. **12-byte patch** (`mov`/`call`/`mov`): If no trampoline is available within 8 MB, the search widens to ±2 GB and a 3-instruction sequence is used: `mov %o7, %g1` to save the return address, `call <trampoline>` (30-bit displacement), and `mov %g1, %o7` in the delay slot to restore the return address.

### Trampoline allocation

On architectures where the inline patch uses a trampoline (SPARC 64-bit, x86-64 far jumps), BonoboMock allocates executable memory pages via `mmap` near the target function. Each page holds multiple trampoline entries, and individual entries are tracked for reuse. When a mock is destroyed, its trampoline entry is freed; when all entries on a page are freed, the page is `munmap`'d.

The allocation strategy differs by operating system:

- **Solaris**: `mmap` ignores hint addresses, so `MAP_FIXED` is used. Before each `MAP_FIXED` call, `mincore()` checks that the target page is unmapped (indicated by `ENOMEM`) to avoid overwriting existing mappings.
- **Linux**: `mmap` respects hint addresses without `MAP_FIXED`. BonoboMock passes a hint near the target function and verifies the returned address is within the required range.

On SPARC, the CPU instruction cache is not coherent with stores. BonoboMock issues `flush` instructions after writing trampoline code and inline patches to ensure the CPU fetches the new instructions.

## GoogleTest/gMock integration

BonoboMock builds on top of gMock's expectation and dispatching infrastructure. Understanding how gMock works internally makes BonoboMock's design much clearer, because BonoboMock manually provides the same contract that gMock's `MOCK_METHOD` macro generates automatically.

### How gMock works under the hood

#### What you write

A typical gMock workflow starts with an interface and a mock class:

```c++
// An interface with one virtual method
class Calculator {
public:
    virtual ~Calculator() = default;
    virtual int Add(int x, int y) = 0;
};

// The gMock mock class
class MockCalculator : public Calculator {
public:
    MOCK_METHOD(int, Add, (int x, int y), (override));
};
```

Then in a test, you set expectations and call the mock:

```c++
TEST(CalculatorTest, AddReturnsMockedValue) {
    MockCalculator calc;
    EXPECT_CALL(calc, Add(3, 4)).WillOnce(Return(42));

    ASSERT_EQ(calc.Add(3, 4), 42);  // calls the mock, not real code
}
```

#### What gMock generates

Inside `MockCalculator`, the line `MOCK_METHOD(int, Add, (int x, int y), (override))` generates approximately:

```c++
// 1. Virtual override -- replaces Calculator::Add
int Add(int x, int y) override {
    d_gmock_Add.SetOwnerAndName(this, "Add");
    return d_gmock_Add.Invoke(x, y);
}

// 2. Companion method -- EXPECT_CALL calls this to register expectations
MockSpec<int(int, int)> gmock_Add(Matcher<int> x, Matcher<int> y) {
    d_gmock_Add.RegisterOwner(this);
    return d_gmock_Add.With(x, y);
}

// 3. FunctionMocker member -- stores expectations, dispatches calls
FunctionMocker<int(int, int)> d_gmock_Add;
```

The **override** is what actually executes when the mocked method is called. The **companion** is what `EXPECT_CALL` calls to set up expectations. The **`FunctionMocker`** is the engine that connects the two: it stores the list of expectations (matchers + actions) and, at call time, finds the matching one and executes its action.

#### How the pieces connect

There are two paths through the generated code:

- **Setup path** (`EXPECT_CALL`): `EXPECT_CALL(calc, Add(3, 4))` preprocessor-pastes `gmock_` onto the method name → calls `calc.gmock_Add(3, 4)` → returns a `MockSpec` → `InternalExpectedAt()` creates a `TypedExpectation` → `.WillOnce(Return(42))` attaches the action.

- **Call path** (`calc.Add(3, 4)`): virtual dispatch hits the override → `d_gmock_Add.Invoke(3, 4)` → `FunctionMocker` scans its expectation list → finds the `(3, 4)` match → executes `Return(42)` → returns `42` to the caller.

```
calc.Add(3, 4)                    virtual override called
  → d_gmock_Add.Invoke(3, 4)      FunctionMocker searches expectations
  → match: Add(3, 4)              args match the registered matchers
  → execute: Return(42)           action attached via .WillOnce()
  → return 42 to caller
```

### How BonoboMock adapts gMock

Standard `MOCK_METHOD` only works for virtual methods on a class you define. BonoboMock needs to mock *existing* functions -- free functions, static methods, non-virtual member functions, and private functions -- that aren't virtual methods on a user-defined mock class. So BonoboMock can't use `MOCK_METHOD`, but it can manually provide the same two-method contract that gMock expects.

The `GMock<R(P...)>` template in `bonobomock_internal_gmock.h` does exactly this:

```c++
template<typename R, typename... P>
class GMock<R(P...)> : public MockBase {
public:
    // Same role as the virtual override generated by MOCK_METHOD
    R bonobomockInternalForwardFunc(P... p) {
        d_gmock.SetOwnerAndName(this, d_funcName.c_str());
        return d_gmock.Invoke(std::forward<P>(p)...);
    }

    // Same role as the gmock_Foo() companion generated by MOCK_METHOD
    MockSpec<R(P...)> gmock_bonobomockInternalForwardFunc(const Matcher<P>&... p) {
        d_gmock.RegisterOwner(this);
        return d_gmock.With(p...);
    }

    // Same FunctionMocker engine
    FunctionMocker<R(P...)> d_gmock;
};
```

The parallel is exact:

| gMock standard (`MOCK_METHOD`) | BonoboMock (`GMock<R(P...)>`) | Role |
|---|---|---|
| `Foo(args...)` | `bonobomockInternalForwardFunc(args...)` | Runtime dispatch -- calls `d_gmock.Invoke()` |
| `gmock_Foo(matchers...)` | `gmock_bonobomockInternalForwardFunc(matchers...)` | Expectation setup -- returns `MockSpec` |
| `d_gmock_Foo` | `d_gmock` | `FunctionMocker` engine |

`BONOBO_MOCK_FUNCTION` is a macro that expands to `bonobomockInternalForwardFunc`. When you write:

```c++
EXPECT_CALL(*mock, BONOBO_MOCK_FUNCTION(_, _)).WillOnce(Return(42));
```

gMock's `EXPECT_CALL` macro pastes `gmock_` onto the method name, producing `gmock_bonobomockInternalForwardFunc(_, _)` -- the same mechanism as standard gMock. The rest of the chain (`.WillOnce()`, `.Times()`, etc.) works identically.

#### Key types

| BonoboMock type | Role |
|---|---|
| `GMock<R(P...)>` | Wraps `FunctionMocker<R(P...)>`. Provides the two-method contract gMock expects. |
| `Mock<Signature, N>` | Combines `GMock` with patching logic. Constructor patches the target; destructor restores it. |
| `MockManager<Signature, N>` | Thread-safe singleton that stores the active `Mock` instance for a given signature and unique ID `N`. |
| `MockCreator` | Static factory that constructs `Mock` objects wrapped in `shared_ptr`. |
| `MockBase` | Abstract base providing the `restore()` interface. |

### Call interception flow

When a mocked function is called at runtime, execution follows this path:

```
caller invokes originalFunction(args...)
  │
  │  patched JMP redirects  (see "Runtime binary patching" above)
  ▼
Mock<Sig, N>::mockFunction(args...)          static method, same signature
  │
  │  retrieve active mock
  ▼
MockManager<Sig, N>::getInstance().get()     thread-safe singleton
  │
  │  forward to GMock adapter
  ▼
mock->bonobomockInternalForwardFunc(args...)     same role as a MOCK_METHOD override
  │
  │  gMock's standard dispatch path
  ▼
d_gmock.Invoke(args...)                      FunctionMocker finds matching
  │                                          expectation, executes action
  ▼
return value flows back to caller
```

For free functions and static methods, `mockFunction` is a **static method** with the same signature as the target. The patched jump redirects directly to it.

For **member functions**, the mock must also capture the object's `this` pointer. `Mock<R(C::*)(P...), N>` inherits from `GMock<R(void*, P...)>` -- the object pointer becomes an explicit first argument. The `mockFunction` for a non-const member function looks like this:

```c++
// From bonobomock_internal_mocker.h (simplified)
template<typename R, typename C, typename... P, int N>
class Mock<R(C::*)(P...), N> : public GMock<R(void*, P...)> {
    // mockFunction is NOT static -- it's a member, so `this` is the calling object
    R mockFunction(P... p) {
        Mock* obj = MockManager<R(C::*)(P...), N>::getInstance().get();
        return obj->bonobomockInternalForwardFunc(this, std::forward<P>(p)...);
    }
};
```

Because `this` is forwarded as the first argument, `EXPECT_CALL` for member functions takes an extra leading matcher for the object pointer:

```c++
EXPECT_CALL(*mock, BONOBO_MOCK_FUNCTION(_, arg1_matcher));
//                                  ^
//                                  matches the object's `this` pointer (void*)
```

For const member functions, the pattern is the same but inherits from `GMock<R(const void*, P...)>` instead.

The patching mechanism gets execution into the mock; everything after that is standard gMock dispatching.

### Virtual function address extraction

A pointer-to-member-function for a virtual function does not point directly at the function's machine code -- it encodes ABI-specific information (a vtable offset on GCC/Clang, a thunk address on SunPro) that BonoboMock must decode to find the real address. The decoding mechanism differs by compiler ABI but the user-facing macro is the same: `BONOBO_MOCK_VIRTUAL`.

For the full details on how each ABI represents virtual member function pointers and how BonoboMock resolves them, see [Virtual Mocking Internals](virtual-mocking-internals.md).

### Private function address extraction

Private member functions cannot be referenced outside the class, so there is no way to form a compile-time function pointer to them. BonoboMock resolves the address at runtime through symbol table lookup:

1. The user creates the mock with `BONOBO_MOCK_PRIVATE_STATIC` / `BONOBO_MOCK_PRIVATE_NON_CONST` / `BONOBO_MOCK_PRIVATE_CONST`, which stringifies the fully qualified function name (via `#function`). Resolution happens on first use.
2. BonoboMock auto-detects the path to the running executable using `ProcessUtil::getCurrentExecutablePath()`.
3. It enumerates the executable's symbol table and demangles the symbols, using a platform-specific mechanism (see below). The full listing is enumerated and demangled **once** and cached in memory; subsequent private-function lookups search the cache instead of re-reading the symbol table.
4. It searches the demangled listing for the stringified function name and extracts the corresponding symbol address. Const-ness is determined by the mock's type (the const vs non-const `MockPrivate` specialization; static `Mock` is always non-const) and matched exactly against the demangled symbol, since const and non-const overloads mangle to different symbols.
5. On Unix, BonoboMock calibrates address offsets for PIE (Position Independent Executable) binaries by comparing a known function's runtime address with its symbol table entry.
6. A separate free function pointer (the `signature` parameter) is used purely for template deduction of the return and parameter types -- it is never called.

The symbol enumeration and demangling in step 3 is dispatched by OS (`SymbolResolver::findFunctionAddress`):

- **Unix (Linux, Solaris)** -- runs `nm` on the executable to obtain the *mangled* symbol listing, then demangles each symbol in-process via a library API rather than `nm -C`'s bundled demangler: `abi::__cxa_demangle` from the C++ runtime (libstdc++/libc++abi) on Linux, and `cplus_demangle` from the system libdemangle on Solaris. This avoids the stale demangler shipped with `nm` on older toolchains, which cannot handle modern C++ mangling -- on Linux the runtime demangler tracks the compiler that built the binary, and on Solaris libdemangle handles both the SunPro and GNU mangling schemes.
- **Windows (MSVC)** -- enumerates and demangles symbols in-process via the DbgHelp API (`SymEnumSymbols` + `UnDecorateSymbolName`), reading the executable's PDB. No external process is spawned, and because DbgHelp is Microsoft's own demangler, it always matches MSVC's mangling scheme.

Like the SunPro virtual mocking path, the string-based search matches on a name prefix, so it **cannot disambiguate overloaded functions** that share the same name.

Relevant code: `bonobomock_internal_private_address_resolver.cpp` (`PrivateAddressResolver::findNonConstPrivateAddress()` / `findConstPrivateAddress()`) dispatches through `bonobomock_internal_symbol_resolver.cpp` to `bonobomock_internal_nm_util.cpp` (Unix) or `bonobomock_internal_dbghelp_resolver.cpp` (Windows).

## Mock object lifecycle (RAII)

Mock objects follow RAII semantics. The constructor patches the target function; the destructor restores it.

```
BONOBO_MOCK(&targetFunc)
  |
  v
MockCreator::createMock<N>(targetFunc, "targetFunc")
  |
  v
bsl::make_shared<Mock<Sig, N>>(targetFunc, funcName)
  |
  v
Mock constructor:
  1. Registers self in MockManager<Sig, N>
  2. Extracts target function address
  3. Extracts mock function (Mock::mockFunction) address
  4. Calls Patch::setup() to overwrite target with JMP
  |
  v
... test runs, calls are intercepted ...
  |
  v
shared_ptr destructor triggers Mock destructor:
  1. Calls Patch::restore() to write back original instructions
  2. Clears MockManager<Sig, N>
```

Because mocks are returned as `bsl::shared_ptr`, they are safe to use with exceptions and early returns. You can also call `mock->restore()` manually to restore the original function before the mock goes out of scope.

## Template uniqueness

Each `BONOBO_MOCK` call must produce a unique template specialization, even when mocking multiple functions with the same signature in the same test. BonoboMock achieves this with a unique integer template parameter `N`:

```c++
// Simplified expansion of BONOBO_MOCK:
MockCreator::createMock<N>(targetFunc, "targetFunc")
//                     ^
//                     unique per call site
```

The macro `BONOBO_MOCK_INTERNAL_UNIQUE_NUMBER` generates `N`:

- **GCC/Clang**: uses `__COUNTER__`, a compiler extension that increments with each macro expansion.
- **Other compilers**: falls back to `__LINE__`, which is unique as long as each `BONOBO_MOCK` call is on a separate line.

This `N` propagates through the entire type hierarchy -- `Mock<Sig, N>`, `MockManager<Sig, N>`, etc. -- so two mocks of functions with identical signatures (e.g., two `int(int, int)` functions) get separate manager singletons and do not interfere with each other.

---

**See also:** [Reference](macros.md)

[← Back to Documentation Home](../index.md)
