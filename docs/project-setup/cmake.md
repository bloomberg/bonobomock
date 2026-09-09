# Project Setup (CMake)

This guide takes you from a machine with nothing installed to a CMake project
whose test replaces a real dependency with a mock — without changing the code
under test.

Using BonoboMock assumes a working knowledge of GoogleTest and gMock; if
you need it, start with the
[GoogleTest Docs](https://google.github.io/googletest/).

Unlike GoogleTest, BonoboMock is **not** self-contained, so there is one extra
step up front: you build and install the library before consuming it.

| Step | What you do |
|------|-------------|
| [1. Prerequisites](#1-prerequisites) | Install a compiler, CMake, Ninja, and git |
| [2. Build and install BonoboMock](#2-build-and-install-bonobomock) | Run `bin/build-linux.sh`, then `cmake --install` |
| [3. Read the example](#3-read-the-example) | Walk through `examples/cmake-quickstart/` to see a basis usecase for BonoboMock in action
| [4. Build and run it](#4-build-and-run-it) | Configure the example against your install prefix and run `ctest` |


Steps 3 and 4 use [`examples/cmake-quickstart/`](../../examples/cmake-quickstart),
which is already in the clone you made in step 2 — there is nothing to type in.
Open it alongside this page; the snippets below are excerpts from those files.

## 1. Prerequisites

BonoboMock depends on two external libraries. Both are open source, and the
build script fetches and builds both for you at pinned versions.

| Dependency | What it provides | Where it comes from |
|------------|------------------|---------------------|
| [BDE](https://github.com/bloomberg/bde) (`bsl`, `bdl`) | The foundation libraries BonoboMock is written against | Built from source for you, via [`bde-tools`](https://github.com/bloomberg/bde-tools) |
| [GoogleTest](https://github.com/google/googletest) (`gmock`, `gtest`) | The mocking/assertion framework BonoboMock plugs into | Built from source for you |

Neither is taken from your distribution's packages. A distro-shipped GoogleTest
is whatever vintage that release froze on, which can be far older than the
compiler it has to agree with — so the script builds its own and installs it
into the same prefix as everything else.

That leaves only build tools to install: a C/C++ compiler, CMake, Ninja,
pkg-config, git and Python 3.

On Ubuntu (22.04 or newer):

```bash
sudo apt update && sudo apt -y install ca-certificates
sudo apt install -y --no-install-recommends \
    build-essential cmake ninja-build pkg-config git python3
```

`python3` is required because BDE's build system (`bbs_build`) is written in
Python.

On RHEL/Fedora the equivalents are `gcc-c++`, `cmake`, `ninja-build`,
`pkgconf-pkg-config`, `git` and `python3`.

The scripted build uses BDE's `gcc-default` toolchain, so it requires **GCC**
(BonoboMock itself also compiles with Clang, but `bin/build-linux.sh` does not
wire that up). You also need **CMake ≥ 4.0**.

## 2. Build and install BonoboMock

From the root of a fresh clone:

```bash
git clone https://github.com/bloomberg/BonoboMock.git
cd BonoboMock
./bin/build-linux.sh
```
That single command clones BDE and GoogleTest, builds and installs them, then
builds BonoboMock and runs its test suite. When it finishes you should see:

```
BonoboMock built successfully.
  library:      /path/to/BonoboMock/build/bonobomock/bonobomock/src/libbonobomock.a
  install with: cmake --install /path/to/BonoboMock/build/bonobomock
```

By default everything is created under the repository root:

| Directory | Contents |
|-----------|----------|
| `thirdparty/` | Cloned `bde-tools`, `bde` and `googletest` sources |
| `build/` | Build trees for BDE, GoogleTest and BonoboMock |
| `install/` | Installed BDE and GoogleTest (and, next, BonoboMock) |

You can relocate any of them by setting `DIR_THIRDPARTY`, `DIR_BUILD`, or
`DIR_INSTALL` in the environment. To build against a different C++ standard,
pass `--cxx-standard` (one of `14`, `17`, `20`, `23`; default `17`):

```bash
./bin/build-linux.sh --cxx-standard 20
```

The script picks the GoogleTest release to match: `v1.18.0` normally, and
`v1.16.0` for `--cxx-standard 14`, since GoogleTest 1.17 and later require
C++17 to compile.

C++03 and C++11 are not offered here: GoogleTest 1.13 and later require C++14.
Building BonoboMock itself for those standards is supported — see
[Supported Platforms](../supported-platforms.md) — but needs an older
GoogleTest than this script builds.

The script is developed and tested on Ubuntu and RHEL 9, but nothing in it is
distro-specific — it invokes no distribution-specific tooling.

Finally, install BonoboMock into the prefix:

```bash
cmake --install build/bonobomock   # installs into ./install by default
```

**Note the install prefix** — you will pass it as `CMAKE_PREFIX_PATH` in step 4.
The install provides two CMake packages your project will use:

| Package | `find_package` name | What it gives you |
|---------|---------------------|-------------------|
| BonoboMock library | `bonobomock` | The `bonobomock::bonobomock` target (and `bsl`, `bdl`, GoogleTest transitively) |
| CMake helper | `BonoboMockHelper` | `add_bonobomock_executable()`, which sets the compiler flags BonoboMock needs |

<details>
<summary><strong>Prefer to run the build steps by hand?</strong> Here is what the script automates.</summary>

### Build and install BDE

`bde-tools` provides the `bbs_build` build driver and the CMake toolchain files;
`bde` provides `bsl`/`bdl`. Both are pinned to the same release tag.

```bash
git clone --depth 1 --branch 4.39.0.0 https://github.com/bloomberg/bde-tools thirdparty/bde-tools
git clone --depth 1 --branch 4.39.0.0 https://github.com/bloomberg/bde.git    thirdparty/bde

export PATH="$PWD/thirdparty/bde-tools/bin:$PATH"
cd thirdparty/bde
eval "$(bbs_build_env -u opt_64_cpp17 -b "$PWD/../../build/bde" -i "$PWD/../../install")"
bbs_build configure --prefix="$PWD/../../install"
bbs_build build     --prefix="$PWD/../../install"
bbs_build install --install_dir="/" --prefix="$PWD/../../install"
eval "$(bbs_build_env unset)"
cd ../..

# bbs_build installs the CMake config packages under install/lib64/cmake/.
# Debian/Ubuntu's CMake does not search <prefix>/lib64/cmake by default, so
# expose it via a lib/ symlink for find_package() in the next step.
if [ -d install/lib64 ] && [ ! -e install/lib ]; then ln -s lib64 install/lib; fi
```

This installs `bslConfig.cmake` / `bdlConfig.cmake` (plus headers and libraries)
into `install/`, which is what makes `find_package(bsl)` / `find_package(bdl)`
succeed next.

### Build and install GoogleTest

Into the same prefix, after the symlink above, so that both libraries land in
the same directory whichever of `lib`/`lib64` the distribution prefers.

```bash
git clone --depth 1 --branch v1.18.0 https://github.com/google/googletest.git thirdparty/googletest

cmake -S thirdparty/googletest -B build/googletest -G Ninja \
    -DCMAKE_CXX_STANDARD=17 \
    -DCMAKE_BUILD_TYPE=RelWithDebInfo \
    -DCMAKE_POSITION_INDEPENDENT_CODE=ON \
    -DCMAKE_INSTALL_PREFIX="$PWD/install"

cmake --build build/googletest --parallel
cmake --install build/googletest
```

### Build and test BonoboMock

BonoboMock is compiled with the same `bde-tools` toolchain BDE was built with, so
the two agree on compiler flags and ABI. `CMAKE_PREFIX_PATH` points CMake at the
prefix, which is where `find_package` resolves BDE and GoogleTest from.

```bash
cmake -B build/bonobomock -S . -G Ninja \
    -DCMAKE_TOOLCHAIN_FILE=thirdparty/bde-tools/BdeBuildSystem/toolchains/linux/gcc-default.cmake \
    -DCMAKE_CXX_STANDARD=17 \
    -DCMAKE_BUILD_TYPE=RelWithDebInfo \
    -DCMAKE_PREFIX_PATH="$PWD/install" \
    -DCMAKE_INSTALL_PREFIX="$PWD/install"

cmake --build build/bonobomock --parallel
ctest --test-dir build/bonobomock --output-on-failure
```

</details>


## 3. Read the example

The example tests a library whose dependencies cannot be injected: a **free
function** and a **static member function**, both called directly by the code
under test. There is no interface to substitute and no constructor to pass a
fake through — the case interface-based mocking can't handle, and BonoboMock's
sweet spot. Read [Core Concepts](../core-concepts.md) first if you haven't;
this guide assumes you know what `BONOBO_MOCK` and `BONOBO_MOCK_FUNCTION` do.

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

See the  example's
[README](../../examples/cmake-quickstart/README.md) for more information.

## 4. Build and run it

From the root of your clone, configure the example against the prefix where you
installed BonoboMock in step 2:

```bash
cmake -B /tmp/quickstart -S examples/cmake-quickstart \
    -DCMAKE_BUILD_TYPE=Debug -DCMAKE_CXX_STANDARD=17 \
    -DCMAKE_PREFIX_PATH=/path/to/install
cmake --build /tmp/quickstart
ctest --test-dir /tmp/quickstart --output-on-failure
```

`CMAKE_CXX_STANDARD` must match the `--cxx-standard` you built with in step 2 —
otherwise you link a consumer built for one standard against a BDE and a
BonoboMock built for another.

Expected output:

```
100% tests passed, 0 tests failed out of 3
```

`Debug` builds at `-O0`, which sidesteps inlining entirely — the simplest choice
while you are getting started. These tests also pass unchanged with
`-DCMAKE_BUILD_TYPE=RelWithDebInfo`; the example's
[README](../../examples/cmake-quickstart/README.md#the-cmake) explains why, and
when you would need more than this:

```bash
cmake -B /tmp/quickstart-opt -S examples/cmake-quickstart \
    -DCMAKE_BUILD_TYPE=RelWithDebInfo -DCMAKE_CXX_STANDARD=17 \
    -DCMAKE_PREFIX_PATH=/path/to/install
cmake --build /tmp/quickstart-opt
ctest --test-dir /tmp/quickstart-opt --output-on-failure
```

## What just happened

- `find_package(bonobomock)` made the `bonobomock::bonobomock` target and the BonoboMock
  headers (`bonobomock_api.h`) available, and brought in GoogleTest transitively.
- `add_bonobomock_executable` built the test with the per-compiler flags BonoboMock
  relies on, so the calls to `fetchLatestPrice()` and `Clock::nowUtcSeconds()`
  survived to runtime.
- At runtime, `BONOBO_MOCK` patched each function's entry point so the calls were
  redirected to your gMock expectations — with no change to anything in `src/`.
  See [Internals](../reference/internals.md) for how the patching works.

## Next steps

- Browse the [Cookbook](../cookbook/index.md) for recipes covering member
  functions, static, virtual, overloaded, private, and variadic functions.
- Read the [CMake Helper Reference](../reference/cmake-helper.md) for the full
  `add_bonobomock_executable` parameter set (`NON_PROD_ONLY_TEST_FILES`,
  `FILES_TO_RECOMPILE`, `ALLOW_CONSTRUCTOR_DUMMIES`).
- Hit a snag? See [Troubleshooting](../reference/troubleshooting.md).

---

[← Back to Project Setup](index.md)

[← Documentation Home](../index.md)
