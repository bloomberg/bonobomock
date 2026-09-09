# Supported Platforms

BonoboMock patches machine code at function entry points, so platform support depends on three axes: **CPU architecture** (e.g., jump instruction encoding), **operating system** (e.g., memory protection, executable layout, symbol table layout), and **compiler** (e.g., ABI for virtual functions, optimization). This page documents tested combinations. For guidance on adding support for a new platform, see [CONTRIBUTING.md](../CONTRIBUTING.md#adding-a-new-platform).

## C++ Standard Compatibility

The BonoboMock library code is C++03 compatible, but it can use modern language features when available. If your project is using C++03, use GoogleTest/gMock 1.8.1 (the last version supporting C++03). For C++11 or more recent platforms, any modern GoogleTest/gMock version works.


## Tested Combinations

The combinations listed below have been tested thoroughly:

| Architecture | OS | Compiler | Status |
|---|---|---|---|
| x86-64 | RHEL 7+ (Linux) | GCC 12+ | Full support |
| x86-64 | RHEL 7+ (Linux) | Clang 18+ | Full support |
| SPARC (64-bit) | Oracle Solaris 11.4 (Unix) | Oracle Studio 12.6+ (SunPro) | Full support |
| SPARC (64-bit) | Oracle Solaris 11.4 (Unix) | GCC 12 | Full support |
| x86-64 | Windows 10+ | MSVC 2022 (v143)+ | Full support [\*](#windows-notes) |

Unlisted combinations have not been tested.

Unlisted Linux/Unix distributions and versions on x86-64 architecture with GCC or Clang compilers are expected to work but have not been tested.

### Windows notes

MSVC has full support for all mocking features except [lambda mocking](reference/limitations.md#lambda-mocking-on-msvc).

## Dependencies

- **[gMock](https://github.com/google/googletest)** -- expectation infrastructure (`EXPECT_CALL`, matchers, actions). BonoboMock depends on gMock but not on any specific test runner -- it will work with GoogleTest or Catch2. Pick the gMock version matching the C++ standard used by your project; for C++03, use gMock 1.8.1.
- **[BDE](https://github.com/bloomberg/bde)** -- Bloomberg Development Environment. BonoboMock uses `bsl` (Bloomberg Standard Library) and `bdl` (Bloomberg Development Library) components.

---

**Next:** [Core Concepts](core-concepts.md)

[← Back to Documentation Home](index.md)

