# Limitations

This page documents known limitations of BonoboMock.

**Contents:**

- [General Limitations](#general-limitations)
    - [Function inlining](#function-inlining)
    - [Minimum function size](#minimum-function-size)
    - [Thread safety](#thread-safety)
    - [Constructors and destructors](#constructors-and-destructors)
    - [Overloaded private functions](#overloaded-private-functions)
    - [No call-through or per-object mocking](#no-call-through-or-per-object-mocking)
    - [Dynamically linked libraries](#dynamically-linked-libraries)
    - [Stripped symbol tables](#stripped-symbol-tables)
    - [Multiple inheritance](#multiple-inheritance)
    - [Lambda mocking on MSVC](#lambda-mocking-on-msvc)
- [C++ Standard-Specific Limitations](#c-standard-specific-limitations)
    - [C++03](#c03)

## General Limitations

These limitations apply across all supported platforms, compilers, and C++ standards.

### Function inlining

When the compiler *inlines* a function, it replaces the function call with the
function's body directly at the call site. The standalone function is eliminated
from the compiled binary.

BonoboMock intercepts calls by patching a function's entry point in the binary (see
[Runtime Binary Patching](internals.md#runtime-binary-patching)). If the
compiler has inlined a function, there is no entry point to patch, and the mock
has no effect.

Inlining can happen in two ways:

1. **Explicit inlining** — functions declared `inline` or defined in headers are
   candidates for inlining by the language rules.
2. **Compiler-driven inlining** — even without the `inline` keyword, the
   compiler may choose to inline functions as an optimization. This is common in
   optimized builds (e.g., CMake build types `RelWithDebInfo` or `Release`).

In non-optimized builds (e.g., CMake build type `Debug`, which typically use `-O0`),
the compiler does not inline functions, so this limitation does not apply.
Inlining becomes a concern in optimized builds (e.g., CMake build types `RelWithDebInfo` or `Release`).

Ideally BonoboMock would warn you when a function has been inlined, but this is
difficult to detect reliably. The compiler may inline a function at some call
sites while still emitting the original function symbol in the binary. BonoboMock
can find and patch that symbol, but calls that were already inlined at compile
time bypass the patched entry point entirely — so the mock has no effect on
those call sites.

#### Mitigations

BonoboMock provides two mechanisms to reduce inlining in test builds:

- **CMake helper** — [`add_bonobomock_executable()`](cmake-helper.md)
  sets compiler flags (e.g., `-fno-inline` on GCC) on the test target to reduce
  inlining across the translation units included in the target.
- **Optimization macros** —
  [`BONOBO_MOCK_DISABLE_FUNCTION_OPTIMIZATION_START/END`](optimization-macros.md)
  can be applied to individual functions in the source under test to prevent
  their inlining.

These mitigations reduce the problem but may not eliminate it in all cases. Some
functions may still be inlined or optimized away in optimized builds. If mocking
continues to fail after applying the macros, consider using
`NON_PROD_ONLY_TEST_FILES` in the [CMake helper](cmake-helper.md) to restrict
the test to non-production builds (e.g., CMake build type `Debug`). Because these builds use
`-O0`, the compiler does not inline any functions, guaranteeing that BonoboMock can
patch every function entry point.

In particular, **`-O3` is not supported**: at this optimization level, the
compiler inlines functions aggressively enough to bypass BonoboMock's entry-point
patching even when `-fno-inline` and the optimization macros are applied. This
causes widespread mock interception failures across all function types (global,
member, virtual, template, lambda). Use `-O0`, `-O1`, or `-O2` for test builds.


#### MSVC: additional limitations beyond inlining

On MSVC, the optimization macro expands only to `__declspec(noinline)`, which is
weaker than the equivalent GCC/Clang attributes. Two additional optimizations can
prevent mocking of in-project functions (functions defined in the same translation
unit as the test) even when the macro is applied:

- **Constant propagation** — MSVC may substitute a known return value at the call
  site without inlining the function, bypassing the patched entry point.
- **COMDAT identical-code folding (ICF)** — the linker may merge two functions with
  identical machine code, causing unexpected cross-mock interference.

Functions in a separate library translation unit (the typical use case) are not
affected by constant propagation. See
[Optimization Macros: MSVC limitations](optimization-macros.md#msvc-weaker-per-function-guarantee)
for details and the `NON_PROD_ONLY_TEST_FILES` workaround.


### Minimum function size

BonoboMock patches a function's entry point by overwriting its first bytes with a jump instruction. The number of bytes overwritten depends on the architecture, application bitness, and the distance between the target function and the mock function:

| Architecture | Application bitness | Patch size | Notes |
|---|---|---|---|
| SPARC | 32-bit application, target within 8 MB | **4 bytes** (1 instruction) | `ba,a` branch always |
| SPARC | 32-bit application, target beyond 8 MB | **12 bytes** (3 instructions) | `sethi` + `jmp` + `nop` |
| SPARC | 64-bit application, trampoline within 8 MB | **4 bytes** (1 instruction) | `ba,a` to trampoline |
| SPARC | 64-bit application, trampoline within 2 GB | **12 bytes** (3 instructions) | `call` to trampoline |
| x86 | 32-bit application | **5 bytes** | `JMP rel32` |
| x86 | 64-bit application | **5 bytes** | `JMP rel32` (trampoline used if target beyond 2 GB) |

On SPARC 64-bit, the full 64-bit jump sequence is 28 bytes, which is too large for many small functions. BonoboMock uses an out-of-line trampoline: the 28-byte jump is written to a nearby memory page allocated via `mmap`, and the target function is patched with a short branch to the trampoline. BonoboMock first tries to allocate the trampoline within 8 MB (allowing a 4-byte `ba,a` patch), and falls back to 2 GB range (requiring a 12-byte `call` sequence).

On x86-64, when the mock function is beyond 2 GB from the target, BonoboMock similarly uses a trampoline to keep the inline patch at 5 bytes. If trampoline allocation fails, it falls back to a 14-byte inline far jump.

If the target function's compiled code is smaller than the patch size, BonoboMock will overwrite adjacent code, which can cause crashes or unpredictable behavior. This is most likely to occur with very small functions (e.g., trivial getters or stubs) in optimized builds where the compiler emits minimal code.

### Thread safety

BonoboMock is not thread-safe for mock setup and teardown. Creating, destroying, or restoring mocks concurrently from multiple threads is undefined behavior — for example, two threads mocking the same function simultaneously could corrupt the saved original bytes or the patched jump instruction.

However, once a mock is established, the patched entry point is visible to all threads. If you set up your mocks sequentially on a single thread before spawning worker threads, all threads will see the mocked function and have their calls intercepted as expected.

### Constructors and destructors

Constructors and destructors cannot be mocked for two reasons:

1. **No way to obtain the address.** The C++ standard does not allow taking the address of a constructor or destructor — expressions like `&MyClass::MyClass` and `&MyClass::~MyClass` are ill-formed. Since BonoboMock works by patching a function at its address, there is no portable way to identify the target.

2. **Unreliable even with the address.** Even if the address could be found (e.g., via symbol table lookup), replacing a constructor with a mock is possible but may be unreliable — it could skip critical initialization such as vtable pointer setup, base class construction, member variable construction, and compiler-generated bookkeeping. The resulting object could be left in an invalid state, making subsequent use undefined behavior. Destructors have the inverse problem — skipping them could leak resources and skip base/member cleanup. Additionally, compilers often emit multiple variants of each constructor and destructor (e.g., complete-object vs. base-object vs. allocating constructors under the Itanium ABI), further complicating any patching approach.

#### Suppressing constructor side effects (link dummying)

While constructors cannot be *mocked*, their **side effects** (I/O, network,
registration) can be suppressed via link dummying: the
[`BONOBO_DUMMY_*` macros](macros.md#constructor-side-effect-suppression-link-dummying)
provide empty constructor/destructor definitions that the linker uses in place
of the real ones. Because a normal C++ definition emits all the mangled ABI
variants and the linker binds by symbol name, this avoids both problems above
(no address needed; all variants covered). The real object still links, so the
class's vtable and other methods remain intact and can be mocked with `BONOBO_MOCK`.

This has its own constraints:

- **The construction site must emit a real constructor call.** Link dummying
  redirects the constructor *symbol*, so it only affects call sites that actually
  call it. If the compiler inlines the constructor at the call site — because the
  constructor is defined `inline`/in a header, the call site is in the same
  translation unit as the constructor's definition, or link-time optimization
  (LTO) is enabled — no call remains to redirect and the real body (and its side
  effects) runs. This mirrors the [Function inlining](#function-inlining)
  limitation. The common case (constructing a type from a dependency you only
  have headers for) emits a real call and works.
- **Constructor and destructor must be dummied together.** The empty constructor
  skips initialization, so running the *real* destructor on the resulting object
  risks undefined behavior. Use `BONOBO_DUMMY_CONSTRUCTOR_AND_DESTRUCTOR`.
- **Members are default-initialized.** The empty constructor body leaves scalar
  members uninitialized and default-constructs class-type members. A class with a
  reference member, or a `const`/non-default-constructible member that must be
  initialized in the constructor init list, **will not compile** as a plain
  dummy; use the `*_WITH_INIT` variants to supply an explicit member-initializer
  list.
- **Statically linked dependencies only.** The real definition must come from a
  linked static archive (consistent with the [Dynamically linked
  libraries](#dynamically-linked-libraries) limitation).
- **Requires the linker's multiple-definition mode**, enabled per-target via the
  `ALLOW_CONSTRUCTOR_DUMMIES` option of
  [`add_bonobomock_executable()`](cmake-helper.md); this weakens duplicate-symbol
  detection for that target.
- **Overloaded constructors** must each be dummied explicitly.

### Overloaded private functions

Private function mocking relies on runtime symbol table lookup (`nm` with in-process demangling) with string-based name matching. The lookup matches on the function name prefix (e.g., `"MyClass::foo("`), which cannot disambiguate between overloaded functions that share the same name — both `MyClass::foo(int)` and `MyClass::foo(double)` match the same prefix. As a result, overloaded private functions cannot be reliably mocked on any platform.

### No call-through or per-object mocking

BonoboMock patches the function at its entry point in memory, which means **all** calls to that function are intercepted — there is no way to mock calls for a specific object while letting other objects call the original implementation. Similarly, BonoboMock does not support call-through mode (recording the call via an expectation and then continuing to execute the original function body). Once a function is mocked, every call to it goes through the mock handler until the mock is restored.

### Dynamically linked libraries

BonoboMock has only been tested with mocking symbols from statically linked libraries. Mocking functions from dynamically linked (shared) libraries has not been validated and may not work reliably.

### Stripped symbol tables

Private function mocking relies on `nm` to look up function addresses by name in the executable's symbol table. If the symbol table has been stripped (e.g., via `strip` or linker flags), `nm` cannot find the function and private function mocking will fail. This does not affect mocking of public, protected, or virtual functions, which resolve addresses through function pointers or vtable lookup rather than the symbol table.

### Multiple inheritance

BonoboMock does not support mocking virtual functions on classes that use multiple inheritance. When a class inherits from multiple base classes, the compiler may use multiple vtables and adjust object pointers with thunks when dispatching virtual calls. BonoboMock's vtable-based address resolution does not account for these adjustments, so mocking virtual functions on multiply-inherited classes may patch the wrong address or fail entirely.


### Lambda mocking on MSVC

Lambda mocking is not supported on MSVC.

BonoboMock patches the lambda's `operator()` address obtained via a pointer-to-member-function. On GCC and Clang, the compiler generates calls through `operator()`, so the patch intercepts them. On MSVC, the compiler routes stateless lambda invocations through an internal static invoke function rather than `operator()`, bypassing the patched entry point entirely. This affects both direct lambda calls and calls through optimization wrappers.

## C++ Standard-Specific Limitations

### C++03

BonoboMock depends on GoogleTest/gMock for argument matching. GoogleTest/gMock 1.8.1 (the last version supporting C++03) supports at most 10 parameters in mocked functions. As a result, BonoboMock, when used with C++03, is limited to:

- **10** parameters for free / static functions
- **9** parameters for member functions (one parameter slot is reserved for the object pointer)

This limitation does not apply to newer GoogleTest/gMock versions (C++11+).


---

[← Back to Documentation Home](../index.md)
