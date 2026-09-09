# SPDX-License-Identifier: Apache-2.0
#
# Copyright 2025 Bloomberg Finance LP
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

# Helper functions for building and packaging the bonobomock library.
#
# Functions prefixed with a leading underscore (e.g. _bonobomock_embed_static_demangler)
# are internal helpers of other functions in this file, not entry points meant to
# be called from a CMakeLists.txt.

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

# Apply the warning configuration bonobomock builds with:
#   - warnings-as-error (COMPILE_WARNING_AS_ERROR).
#   - some extra warnings, per compiler.
function(bonobomock_set_warnings target)
    set_target_properties(${target} PROPERTIES COMPILE_WARNING_AS_ERROR ON)

    if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
        target_compile_options(${target} PRIVATE -Wall -Wextra)
    endif()
    if(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
        target_compile_options(${target} PRIVATE -Wunreachable-code-aggressive
                                                 -Wno-unknown-warning-option)
    endif()
    if(MSVC)
        target_compile_options(${target} PRIVATE /W4)
    endif()
endfunction()

# (GCC/Clang) Embed the compiler's own __cxa_demangle into the target's static
# archive, so consumers get a demangler that matches the compiler.  Used for every
# Itanium-ABI toolchain -- GCC/Clang on Linux and GCC on Solaris alike.
#
# With GCC/Clang BonoboMock demangles with abi::__cxa_demangle from the C++ runtime,
# which is served at run time by the shared libstdc++. When that shared libstdc++
# is much older than the compiler (a modern compiler paired with an old system
# runtime -- e.g. RHEL 7's 2015-era libstdc++), its demangler can recurse without
# bound on some modern-C++ symbols (std::variant / std::optional / ...) and overflow
# the stack. Embedding the object into lib<target>.a puts a working demangler inside
# the archive, so every consumer links it however it links bonobomock, with nothing extra
# to propagate.
#
# Done in three steps:
#   1. Locate a static C++ runtime archive that contains __cxa_demangle -- libsupc++.a
#      if the toolchain ships it, else libstdc++.a (which also contains cp-demangle.o).
#      CMAKE_CXX_COMPILER is the compiler executable; running it with
#      -print-file-name=<archive> prints the full path to that library as this compiler
#      resolves it. The library is per-architecture, so pass the target bitness
#      explicitly (-m32 or -m64): querying the wrong architecture would return an object
#      that cannot be linked into this build (e.g. a 64-bit object in a 32-bit build).
#   2. Extract the single object that defines __cxa_demangle, cp-demangle.o, from
#      that archive with `ar x`. It depends only on libc, so taking just this
#      object does not pull in the rest of libstdc++.
#   3. Add that prebuilt object to the target's sources as an EXTERNAL_OBJECT, so
#      it is archived into lib<target>.a next to the target's own objects.
#
# Internal helper of bonobomock_enable_private_mocking.
function(_bonobomock_embed_static_demangler target)
    if(CMAKE_SIZEOF_VOID_P EQUAL 4)
        set(arch_flag -m32)
    else()
        set(arch_flag -m64)
    endif()

    # cp-demangle.o (the __cxa_demangle definition) lives in the compiler's static C++
    # runtime archive.  Toolchains differ in which one they ship: most expose libsupc++.a,
    # but some ship only the larger libstdc++.a, which contains the same object.  Try each
    # in turn and use the first that both resolves to a real file and holds a cp-demangle.o
    # member -- `ar t <archive> <member>` echoes the name when present and nothing when
    # absent, so a toolchain that ships neither (only a shared libstdc++) falls back to the
    # runtime demangler below instead of turning `ar x` into a hard error.
    set(archive "")
    set(looked_at "")
    foreach(candidate libsupc++.a libstdc++.a)
        execute_process(
            COMMAND "${CMAKE_CXX_COMPILER}" ${arch_flag} -print-file-name=${candidate}
            OUTPUT_VARIABLE resolved
            OUTPUT_STRIP_TRAILING_WHITESPACE)
        string(APPEND looked_at " '${resolved}'")
        if(NOT EXISTS "${resolved}")
            continue()
        endif()
        execute_process(COMMAND "${CMAKE_AR}" t "${resolved}" cp-demangle.o
                        OUTPUT_VARIABLE member OUTPUT_STRIP_TRAILING_WHITESPACE ERROR_QUIET)
        if(member STREQUAL "cp-demangle.o")
            set(archive "${resolved}")
            break()
        endif()
    endforeach()

    if(archive STREQUAL "")
        # No static archive to embed (e.g. the Solaris GCC toolchain ships none): fall back
        # to the runtime abi::__cxa_demangle. Logged, not warned -- it is the expected, safe
        # path where the runtime libstdc++ matches the compiler.
        message(
            STATUS "bonobomock: no static C++ runtime archive (libsupc++.a or libstdc++.a) with a "
                   "cp-demangle.o member found (looked at${looked_at}); using the runtime "
                   "abi::__cxa_demangle instead.")
        return()
    endif()

    # cp-demangle.o is embedded verbatim -- CMake cannot recompile a prebuilt
    # object, so it is not covered by the target's POSITION_INDEPENDENT_CODE property
    # and must already be position-independent, or it would break consumers that link
    # the target into a PIE or shared object. The toolchain's static C++ archive is built
    # -fPIC (verified: no absolute text relocations), so this is safe.
    set(cp_demangle_o "${CMAKE_CURRENT_BINARY_DIR}/cp-demangle.o")
    add_custom_command(
        OUTPUT "${cp_demangle_o}"
        COMMAND "${CMAKE_AR}" x "${archive}" cp-demangle.o
        WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}"
        DEPENDS "${archive}"
        COMMENT "Extracting cp-demangle.o (__cxa_demangle) from ${archive}"
        VERBATIM)
    set_source_files_properties("${cp_demangle_o}" PROPERTIES EXTERNAL_OBJECT TRUE GENERATED TRUE)
    target_sources(${target} PRIVATE "${cp_demangle_o}")
endfunction()

# Enable private-function mocking for <target>.  Does three things:
#   - adds the platform symbol resolver source (the code that reads the symbol
#     table).
#   - gives consumers a correct in-process demangler for the symbols it reads.
#   - reports, via the two named output variables, the extra tokens consumers need
#     in the generated pkg-config / CPS metadata (both empty where nothing extra is
#     required).
#
# To mock a private function, BonoboMock finds its symbol -- and its address -- in
# the executable's symbol table, then demangles that symbol to match it against the
# function being mocked (see bonobomock_internal_nm_util.cpp). That takes two
# cooperating pieces, both set up here:
#
# 1. The symbol *resolver* -- the source that reads the symbol table:
#      - MSVC (Windows): a DbgHelp-based resolver that reads the PDB in-process;
#        it needs the system `dbghelp` library.
#      - everything else: an nm-based resolver (runs `nm`, then demangles + matches
#        in-process).  The non-MSVC branch must be an OS that
#        bonobomock_internal_nm_util.cpp supports (currently Linux and Solaris); any
#        other OS fails loudly at build time via the #error guards in that file and
#        in bonobomock_internal_symbol_resolver.cpp.
#    See docs/supported-platforms.md and CONTRIBUTING.md ("Adding a new platform").
#
# 2. The *demangler* the resolver relies on.  It must match the compiler's mangling
#    scheme, so it is chosen by compiler (not OS); because bonobomock is a static archive it
#    has to be made available to whatever links bonobomock:
#      - SunPro (Solaris): cplus_demangle() lives in libdemangle -- bundled with Solaris
#        but not linked by default -- so request it with -ldemangle. That reference must
#        reach every consumer through whichever channel it uses to discover bonobomock:
#        the CMake PUBLIC link interface (set here), the pkg-config Libs line
#        (out_pc_libs_var), and the CPS link_libraries field (out_cps_link_libs_var).
#        A CPS `requires` entry names a dependency *package*, which the consumer's build
#        tool has to go and find; `link_libraries` names libraries to put on the link
#        line as-is. libdemangle is a plain system library that no package describes, so
#        it goes in link_libraries -- listing it under `requires` would make consumers
#        look for a demangle package that does not exist.
#      - GCC/Clang (Itanium ABI, on Linux and on Solaris): embed a modern demangler into
#        the archive instead (see _bonobomock_embed_static_demangler); nothing to propagate.
#      - Windows/MSVC: the DbgHelp resolver demangles in-process; nothing to do.
function(bonobomock_enable_private_mocking target out_pc_libs_var out_cps_link_libs_var)
    # 1. Symbol resolver.
    if(MSVC)
        target_sources(${target} PRIVATE bonobomock_internal_dbghelp_resolver.cpp)
        target_link_libraries(${target} PRIVATE dbghelp)
    else()
        target_sources(${target} PRIVATE bonobomock_internal_nm_util.cpp)
    endif()

    # 2. Demangler, plus the metadata tokens consumers need to link it.  Selected by the
    #    *compiler*, not the OS: the demangler must match the compiler's mangling scheme.
    #    This matters on Solaris, where both toolchains share one OS -- SunPro emits Sun
    #    mangling, GCC emits Itanium mangling, so GCC on Solaris must NOT use libdemangle.
    set(pc_libs "")
    set(cps_link_libs "")
    if(CMAKE_CXX_COMPILER_ID STREQUAL "SunPro")
        target_link_libraries(${target} PUBLIC -ldemangle)
        set(pc_libs " -ldemangle")
        set(cps_link_libs demangle)
    elseif(CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
        _bonobomock_embed_static_demangler(${target})
    endif()

    set(${out_pc_libs_var}
        "${pc_libs}"
        PARENT_SCOPE)
    set(${out_cps_link_libs_var}
        "${cps_link_libs}"
        PARENT_SCOPE)
endfunction()

# Generate and install <target>'s CPS (Common Package Specification) file.
#
# CPS is a JSON package-description format (https://cps-org.github.io/cps/) that
# build tools read to discover a library's link and include requirements,
# alongside or instead of pkg-config. This emits a `<target>.cps` next to the
# pkg-config file so consumers can locate the library through either mechanism.
#
# CMake 4.3 and later search for `<name>.cps` *before* `<name>Config.cmake` (see
# the search-procedure table in the find_package documentation), so from that
# version on this file -- not bonobomockConfig.cmake -- is what a plain
# `find_package(bonobomock)` reads. It therefore has to describe the dependencies
# as completely as the CMake config does.
#
# _bonobomock_install_cps_file(TARGET <name> TYPE <archive|interface>
#                          DESCRIPTION <text> COMPONENT <name>
#                          [REQUIRES <pkg>[:<comp>]...]
#                          [REQUIRES_NON_NAMESPACED <pkg>...]
#                          [LINK_LIBRARIES <lib>...])
#
# The three lists differ in what the consumer's build tool is asked to do, and
# picking the wrong one silently degrades the consumer's link line:
#
#   REQUIRES <pkg>[:<comp>]
#       A dependency *package* to look up, e.g. `GTest:gmock`. It is written both
#       to the package-level `requires` map (which is what makes CMake actually
#       run find_package(<pkg>)) and to the component-level `requires` array,
#       which references it as `<pkg>:<comp>`. The component defaults to <pkg>.
#       CMake binds `<pkg>:<comp>` to the imported target `<pkg>::<comp>`, so this
#       form only works for a dependency that exports a *namespaced* target of
#       exactly that name -- our own packages (bonobomock::bonobomock, ...) and
#       GoogleTest (GTest::gmock) do; see REQUIRES_NON_NAMESPACED for those that
#       do not. The dependency does not need to ship a .cps of its own: an entry
#       in the package-level `requires` map is resolved by an ordinary
#       find_package(), which is happy to load the dependency's CMake config.
#       That lookup is config mode only, though -- a Find module cannot satisfy
#       it -- so only name dependencies that install a <pkg>Config.cmake (or a
#       .cps). BDE and GoogleTest both do.
#
#   REQUIRES_NON_NAMESPACED <pkg>
#       A dependency package whose CMake config exports a target named plainly
#       `<pkg>` rather than `<pkg>::<pkg>` -- BDE's `bsl` and `bdl`. Naming these
#       under REQUIRES would make CMake look for the targets `bsl::bsl`/`bdl::bdl`
#       and fail. They are instead written to the package-level `requires` map
#       (so find_package(bsl) still runs and defines the target) and to the
#       component's `link_libraries` as the bare name `bsl`, which CMake resolves
#       against that now-existing target -- picking up its archive path, include
#       directories and transitive dependencies. A build tool that is not CMake
#       reads the same entry as plain `-lbsl`, which is what such a tool would
#       have to do anyway.
#
#   LINK_LIBRARIES <lib>
#       A bare external library that no package describes at all (`demangle` for
#       Solaris' libdemangle). Emitted to the component's `link_libraries` as-is,
#       with no lookup of any kind.
#
# Generates <name>.cps and installs it to <libdir>/cps.
# Internal helper of bonobomock_install_dev_package.
#
# The document is assembled with string(JSON) rather than configured from a
# template, because two of its members are conditional: a header-only library has
# no `location`, and a project that declares no version has no `version`. With a
# template those have to be spliced in as pre-formatted text carrying their own
# newline, indentation and trailing comma; here they are simply never set. The
# emitted layout -- two-space indent, members in alphabetical order -- is the same
# one CMake's own install(PACKAGE_INFO) produces.
#
# string(JSON) takes each value as JSON, so strings are passed in quoted. Every
# value written below is a target name, a package name or a fixed description --
# plain text with no quotes or backslashes needing escaped.
function(_bonobomock_install_cps_file)
    set(oneValueArgs TARGET TYPE DESCRIPTION COMPONENT)
    set(multiValueArgs REQUIRES REQUIRES_NON_NAMESPACED LINK_LIBRARIES)
    cmake_parse_arguments(ARG "" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

    # `@prefix@` is a literal token in the emitted file, not something expanded
    # here: the *consumer* resolves it at find-time against the directory the
    # installed .cps was found in, which is what makes the package relocatable.
    set(cps_dir "@prefix@/${CMAKE_INSTALL_LIBDIR}/cps")
    set(includedir "@prefix@/${CMAKE_INSTALL_INCLUDEDIR}")
    set(archive "@prefix@/${CMAKE_INSTALL_LIBDIR}/lib${ARG_TARGET}.a")

    set(cps "{}")
    string(JSON cps SET "${cps}" cps_version "\"0.13.0\"")
    string(JSON cps SET "${cps}" name "\"${ARG_TARGET}\"")
    string(JSON cps SET "${cps}" description "\"${ARG_DESCRIPTION}\"")
    string(JSON cps SET "${cps}" license "\"Apache-2.0\"")
    string(JSON cps SET "${cps}" cps_path "\"${cps_dir}\"")
    string(JSON cps SET "${cps}" default_components "[\"${ARG_TARGET}\"]")

    # Optional, and mirrors how the .pc files handle @PROJECT_VERSION@.
    if(PROJECT_VERSION)
        string(JSON cps SET "${cps}" version "\"${PROJECT_VERSION}\"")
    endif()

    # Walk the dependencies once, filling the package-level `requires` map (every
    # dependency package, whichever list it came from), the component-level
    # `requires` array (the namespaced ones) and the component-level
    # `link_libraries` array (the rest). See the header comment for the split.
    set(requires "{}")
    set(component_requires "")
    set(link_libraries "")

    foreach(req IN LISTS ARG_REQUIRES)
        # <pkg>[:<comp>], the component defaulting to the package name.
        if("${req}" MATCHES "^([^:]+):([^:]+)$")
            set(pkg "${CMAKE_MATCH_1}")
            set(comp "${CMAKE_MATCH_2}")
            # Ask for that one component explicitly, so a consumer that cannot
            # provide it is told at find_package() time rather than at link time.
            string(JSON requires SET "${requires}" "${pkg}" "{\"components\":[\"${comp}\"]}")
        else()
            set(pkg "${req}")
            set(comp "${req}")
            string(JSON requires SET "${requires}" "${pkg}" "{}")
        endif()
        list(APPEND component_requires "\"${pkg}:${comp}\"")
    endforeach()

    # Found as packages, but linked by bare target name (see the header comment).
    # These come before ARG_LINK_LIBRARIES so that the link line keeps the
    # dependency order the CMake link interface has: bonobomock, then bsl/bdl,
    # then any bare system library.
    foreach(pkg IN LISTS ARG_REQUIRES_NON_NAMESPACED)
        string(JSON requires SET "${requires}" "${pkg}" "{}")
        list(APPEND link_libraries "${pkg}")
    endforeach()

    list(APPEND link_libraries ${ARG_LINK_LIBRARIES})

    # The map and the two arrays below are emitted even when empty: `{}` and `[]`
    # say "nothing here" as plainly as an absent member would, and keep the shape
    # of the file constant.
    string(JSON cps SET "${cps}" requires "${requires}")

    set(component "{}")
    string(JSON component SET "${component}" type "\"${ARG_TYPE}\"")
    string(JSON component SET "${component}" includes "[\"${includedir}\"]")

    # Only compiled libraries have an on-disk archive; header-only INTERFACE
    # libraries do not, so they get no `location` at all.
    if(NOT ARG_TYPE STREQUAL "interface")
        string(JSON component SET "${component}" location "\"${archive}\"")
    endif()

    list(JOIN component_requires "," joined_requires)
    string(JSON component SET "${component}" requires "[${joined_requires}]")

    set(quoted_links "")
    foreach(lib IN LISTS link_libraries)
        list(APPEND quoted_links "\"${lib}\"")
    endforeach()
    list(JOIN quoted_links "," joined_links)
    string(JSON component SET "${component}" link_libraries "[${joined_links}]")

    set(components "{}")
    string(JSON components SET "${components}" "${ARG_TARGET}" "${component}")
    string(JSON cps SET "${cps}" components "${components}")

    set(output_file "${CMAKE_CURRENT_BINARY_DIR}/${ARG_TARGET}.cps")
    file(WRITE "${output_file}" "${cps}\n")

    install(
        FILES "${output_file}"
        DESTINATION "${CMAKE_INSTALL_LIBDIR}/cps"
        COMPONENT "${ARG_COMPONENT}")
endfunction()

# Make <target> a consumable dev package.  In one call it:
#   - exposes the public-header include dirs (BUILD_INTERFACE from the source tree
#     + INSTALL_INTERFACE from the installed include dir), with the usage-
#     requirement scope derived from TYPE (PUBLIC for compiled, INTERFACE for
#     header-only).
#   - installs the static archive (compiled libs only) and registers the target in
#     the bonobomockTargets export set (for find_package(bonobomock) consumers).
#   - installs the public header files.
#   - generates and installs a pkg-config (.pc) file.
#   - generates and installs a CPS file.
#
# Serves every library in the tree -- both compiled archives and header-only
# INTERFACE libraries; an INTERFACE library has no on-disk archive to install, so
# TYPE selects between the two.
#
# bonobomock_install_dev_package(<target>
#     TYPE <archive|interface>               # compiled library vs header-only
#     DESCRIPTION <text> COMPONENT <name>
#     [PC_PUBLIC_LIBS <string>]              # extra tokens for the .pc Libs line
#     [CPS_REQUIRES <pkg>[:<comp>]...]       # deps exporting <pkg>::<comp>
#     [CPS_REQUIRES_NON_NAMESPACED <pkg>...] # deps exporting a plain <pkg> target
#     [CPS_LINK_LIBRARIES <lib>...])         # bare external libs for the .cps
#
# The three CPS_* dependency lists map onto _bonobomock_install_cps_file's
# REQUIRES / REQUIRES_NON_NAMESPACED / LINK_LIBRARIES; see its header comment for
# which one a given dependency belongs in.
#
# The pkg-config template is taken from <target>.pc.in in the calling directory.
function(bonobomock_install_dev_package target)
    set(oneValueArgs TYPE DESCRIPTION COMPONENT PC_PUBLIC_LIBS)
    set(multiValueArgs CPS_REQUIRES CPS_REQUIRES_NON_NAMESPACED CPS_LINK_LIBRARIES)
    cmake_parse_arguments(ARG "" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

    # Expose the public headers at build time (from the source tree) and at install
    # time (from the installed include dir), so both this build and consumers can
    # find them. The usage-requirement scope follows TYPE: a compiled library needs
    # PUBLIC, a header-only INTERFACE library needs INTERFACE. The INSTALL_INTERFACE
    # dir must match the header DESTINATION set below.
    if(ARG_TYPE STREQUAL "interface")
        set(header_scope INTERFACE)
    else()
        set(header_scope PUBLIC)
    endif()
    target_include_directories(
        ${target} ${header_scope} $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)

    # A compiled library installs its static archive; a header-only INTERFACE
    # library has no archive artifact and is only registered in the export set.
    if(ARG_TYPE STREQUAL "interface")
        install(
            TARGETS ${target}
            EXPORT bonobomockTargets
            COMPONENT ${ARG_COMPONENT})
    else()
        install(
            TARGETS ${target}
            EXPORT bonobomockTargets
            ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR} COMPONENT ${ARG_COMPONENT})
    endif()

    file(GLOB headers "${CMAKE_CURRENT_SOURCE_DIR}/*.h")
    install(
        FILES ${headers}
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
        COMPONENT ${ARG_COMPONENT})

    # pkg-config: <target>.pc.in may expand @BONOBOMOCK_PC_PUBLIC_LIBS@ (only bonobomock's
    # template does today), so name the local variable accordingly before
    # configuring the template.
    set(BONOBOMOCK_PC_PUBLIC_LIBS "${ARG_PC_PUBLIC_LIBS}")
    configure_file(${target}.pc.in "${CMAKE_CURRENT_BINARY_DIR}/${target}.pc" @ONLY)
    install(
        FILES "${CMAKE_CURRENT_BINARY_DIR}/${target}.pc"
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/pkgconfig
        COMPONENT ${ARG_COMPONENT})

    # CPS (see _bonobomock_install_cps_file above).
    _bonobomock_install_cps_file(
        TARGET ${target}
        TYPE ${ARG_TYPE}
        DESCRIPTION "${ARG_DESCRIPTION}"
        REQUIRES ${ARG_CPS_REQUIRES}
        REQUIRES_NON_NAMESPACED ${ARG_CPS_REQUIRES_NON_NAMESPACED}
        LINK_LIBRARIES ${ARG_CPS_LINK_LIBRARIES}
        COMPONENT ${ARG_COMPONENT})
endfunction()

# Install the CMake package config for the whole bonobomock package -- the files that
# find_package(bonobomock) loads.
#
# NOTE: "package config" here means the *CMake* package config (bonobomockConfig.cmake
# + bonobomockTargets.cmake).  It is NOT pkg-config (the per-library .pc files) nor CPS
# (the per-library .cps files); those are produced per library by
# bonobomock_install_dev_package.  This is the one project-wide artifact for
# find_package() consumers.
#
# Does two things, both once per project:
#   - installs the bonobomockTargets export set (bonobomockTargets.cmake), so downstream
#     projects can import every bonobomock target as bonobomock::<name>.  Each library adds
#     itself to that set via bonobomock_install_dev_package; this call writes it out.
#   - generates and installs bonobomockConfig.cmake (the find_package entry point),
#     which pulls in transitive dependencies and then includes bonobomockTargets.cmake.
#
# Call once, from the top-level CMakeLists.txt, AFTER every add_subdirectory() that
# defines a bonobomock library -- install(EXPORT) requires all targets to have
# registered into the export set first.
function(bonobomock_install_cmake_package_config)
    install(
        EXPORT bonobomockTargets
        FILE bonobomockTargets.cmake
        NAMESPACE bonobomock::
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/bonobomock)

    configure_package_config_file(
        "${bonobomock_SOURCE_DIR}/cmake/bonobomockConfig.cmake.in"
        "${bonobomock_BINARY_DIR}/bonobomockConfig.cmake"
        INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/bonobomock)

    install(FILES "${bonobomock_BINARY_DIR}/bonobomockConfig.cmake"
            DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/bonobomock)
endfunction()
