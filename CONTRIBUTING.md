# Contributing

## Before You Begin

Please read:
- [GOVERNANCE.md](GOVERNANCE.md) — how decisions are made and approvals work.
- [MAINTAINERS.md](MAINTAINERS.md) — who reviews and merges pull requests.
- [CODE_OF_CONDUCT.md](CODE_OF_CONDUCT.md) — expectations for respectful collaboration.

## Development Setup

*Coming soon.*

## Running Tests

*Coming soon.*

## Pull Requests

Each pull request requires **two maintainer approvals** (see [GOVERNANCE.md](GOVERNANCE.md)). Before submitting, ensure:

- The change compiles and tests pass on all supported platforms, bitness configurations, and optimization levels (e.g. CMake Build types Debug, RelWithDebInfo, Release). See [Supported Platforms](docs/supported-platforms.md) for the tested combinations.
- Every user-facing change should include corresponding documentation updates. The documentation lives in the `docs/` directory.
- Code style follows the existing conventions and the `.clang-format` configuration. Run `make format` to apply it automatically.


## Adding a New Platform

BonoboMock patches machine code at runtime, so platform support touches several areas of the codebase. The subsections below describe the concerns you should think about when adding support for a new CPU architecture, operating system, or compiler. In practice these axes are often intertwined — a new platform may require changes across several of them.

For a detailed explanation of how each mechanism works, see [Internals](docs/reference/internals.md) and [Virtual Mocking Internals](docs/reference/virtual-mocking-internals.md).

### Binary patching

BonoboMock intercepts function calls by overwriting the first bytes of a target function with a jump instruction. Each CPU architecture has its own encoding — instruction format, patch size, and whether near/far jump variants are needed depending on address distance. A new architecture needs its own jump encoding and must define the patch size (the number of bytes saved and restored at the function entry point).

### Memory protection

Function code lives in read-only memory pages. BonoboMock must make these pages writable before patching and restore permissions afterward. The current implementation uses POSIX `mprotect()` and `sysconf(_SC_PAGE_SIZE)`. A new operating system may require a different memory protection API (e.g., `VirtualProtect` on Windows) or explicit opt-in to make code pages writable (e.g., AIX requires `MPROTECT_TXT=ON`).

### Virtual function address resolution

A pointer-to-member-function for a virtual function does not point directly at the function's machine code — what it encodes is ABI-specific. On the Itanium ABI (GCC, Clang), it contains a vtable offset that BonoboMock decodes by inspecting the pointer value. On the SunPro ABI, it contains a thunk address that BonoboMock disassembles to extract the vtable offset. A new compiler ABI will need its own resolution logic. See [Virtual Mocking Internals](docs/reference/virtual-mocking-internals.md) for details on the existing implementations.

### Private function address resolution

Private functions cannot be referenced by pointer at compile time, so BonoboMock resolves their addresses at runtime by looking them up in the executable's symbol table. This is dispatched by OS through `SymbolResolver`, and the mechanism differs by platform:

- **Unix (Linux, Solaris)** — runs `nm` on the executable to obtain mangled symbols, then demangles them in-process rather than via `nm -C`: `abi::__cxa_demangle` from the C++ runtime (libstdc++/libc++abi) on Linux, and `cplus_demangle` from the system libdemangle on Solaris. This avoids the stale demangler bundled with older `nm` versions — on Linux the runtime demangler matches the compiler that built the binary, and on Solaris libdemangle handles both the SunPro and GNU mangling schemes. The `nm` output format differs across operating systems — field delimiters, address encoding (hex vs. decimal), and const-qualification suffixes all vary — so a new Unix OS or toolchain may need its own parser and demangling API.
- **Windows (MSVC)** — reads the executable's PDB in-process via the DbgHelp API (`SymEnumSymbols` + `UnDecorateSymbolName`); no external `nm` process is involved.

A new OS must plug into the `SymbolResolver` dispatch with whichever mechanism its toolchain provides. Additionally, position-independent executables (PIE) require a calibration step to translate symbol table addresses to runtime addresses.

### Compiler integration

Each compiler needs a detection guard so BonoboMock can select the correct code paths. Beyond ABI detection, this includes: choosing a unique ID macro (`__COUNTER__` if available, `__LINE__` as fallback), providing compiler-specific attributes or pragmas for suppressing inlining in the optimization macros (e.g., `__attribute__((optnone))` on Clang, `__attribute__((optimize("O0")))` on GCC, `#pragma unknown_control_flow` on SunPro), and adding the appropriate compiler flags to the [CMake helper](docs/reference/cmake-helper.md) (e.g., `-fno-inline` on GCC). The C++ standard also determines the API surface — C++11 and later get the full variadic template API, while C++03 compilers use manually-expanded variants with fixed parameter limits.

### Testing

New platform support must be validated across all optimization levels and bitness configurations.
