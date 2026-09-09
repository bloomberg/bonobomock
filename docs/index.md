# Documentation

<p align="center">
  <img src="assets/animations/bonobomock/patching/bonobomock_mascot_transparent.png" alt="BonoboMock mascot" width="220">
</p>

**BonoboMock** is a GoogleTest-compatible C++ mocking library developed at Bloomberg.

**New to BonoboMock?** Follow the suggested reading order below. **Already using it?** Jump to [Cookbook](cookbook/index.md) or [Reference](#reference).


## Suggested Reading Order

| Step | Page | Description |
|------|------|-------------|
| 1 | [What is BonoboMock and when should I use it?](what-is-bonobomock-and-when-to-use-it.md) | Overview of the library and when it's the right choice |
| 2 | [Supported Platforms](supported-platforms.md) | Check platform compatibility and requirements |
| 3 | [Core Concepts](core-concepts.md) | Core concepts and a basic example |
| 4 | [Project Setup](project-setup/index.md) | Add BonoboMock to your project |
| 5 | [Cookbook](cookbook/index.md) | Step-by-step recipes for different function types |


## Reference

- [Macro API](reference/macros.md) -- complete list of all BonoboMock macros
- [CMake Helper](reference/cmake-helper.md) -- `cmake-bonobomock-helper` reference
- [Optimization Macros](reference/optimization-macros.md) -- `bonobomock-optimization-macros` reference
- [Internals](reference/internals.md) -- how BonoboMock works under the hood
  - [Virtual Mocking Internals](reference/virtual-mocking-internals.md) -- vtable resolution on GCC/Clang and SunPro
- [Limitations](reference/limitations.md) -- known limitations by platform and C++ standard
- [Troubleshooting](reference/troubleshooting.md) -- common issues and solutions

## Contact

Please see `MAINTAINERS.md` for the list of active maintainers and reach out with any questions.
