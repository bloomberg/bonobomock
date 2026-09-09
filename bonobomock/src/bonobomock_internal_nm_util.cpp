// SPDX-License-Identifier: Apache-2.0
//
// Copyright 2025 Bloomberg Finance LP
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <bonobomock_internal_error.h>
#include <bonobomock_internal_nm_util.h>

#include <bdlb_stringviewutil.h>

#include <bsl_iostream.h>
#include <bsl_optional.h>
#include <bsl_sstream.h>
#include <bsl_string_view.h>
#include <bsl_utility.h>
#include <bsl_vector.h>

#include <bslma_managedptr.h>

#include <bsls_platform.h>

#include <cctype>
#include <cerrno>
#include <cstdio>
#include <cstdlib>
#include <sys/wait.h>

// Symbols are demangled in-process (rather than via `nm -C`) because the
// demangler bundled with `nm` on older toolchains can lag behind and choke on
// modern C++ mangling.  The in-process demangling API is selected by *compiler*,
// not OS -- the demangler must match the compiler's mangling scheme: SunPro emits
// Sun mangling (cplus_demangle from the system libdemangle), while GCC/Clang emit
// Itanium mangling (abi::__cxa_demangle from libstdc++/libsupc++ or libc++abi).
// GCC on Solaris is therefore an Itanium target and must NOT use libdemangle.
#if defined(__GNUC__) || defined(__clang__)
    #include <cxxabi.h>
#elif defined(__SUNPRO_CC)
    #include <demangle.h>
#else
    #error "No in-process demangler known for this compiler"
#endif

namespace BloombergLP {
namespace bonobomock {

    namespace {

        // ------------------------------ State -------------------------------

        // PIE (Position Independent Executable) slide between the addresses nm
        // reports and the actual runtime addresses.  Computed once (see
        // findFunctionAddress) and reused thereafter.
        bool s_pieCalibrated = false;
        size_t s_pieOffset = 0;

        // Symbol table cache.  nm is run once per binary and its full output is
        // cached here as (demangled name, address) pairs, so that mocking many
        // private functions does not re-spawn nm for each one.  Insertion order
        // matches nm's output order, which findRawNmAddress relies on to return
        // the first matching symbol.
        // s_symbolCacheBuilt tracks whether nm has already been run for
        // s_cachedTaskPath.  We cannot rely on s_symbolCache being non-empty:
        // a binary may legitimately yield no parseable symbols, and in that
        // case an emptiness check would re-spawn nm on every lookup.
        bool s_symbolCacheBuilt = false;
        bsl::string s_cachedTaskPath;
        bsl::vector<bsl::pair<bsl::string, size_t> > s_symbolCache;

        // ------------------------------ RAII --------------------------------

        // Deleter for bslma::ManagedPtr, used to free the malloc'd buffers
        // below (the getline() line buffer and the abi::__cxa_demangle result)
        // even if an intervening allocation throws.  ManagedPtr requires a
        // 'void (*)(void *object, void *cookie)' deleter.
        void freeManagedBuffer(void* buffer, void*)
        {
            free(buffer);
        }

        // RAII owner of a popen()ed command stream.  popen() both allocates a
        // stream and forks a child process; the child is only reaped -- and the
        // stream and file descriptor freed -- when pclose() is called.  This
        // wrapper guarantees pclose() runs on every path (including
        // exceptions), so a failure while reading cannot leak the descriptor or
        // leave a zombie process.  Call close() on the success path to reap the
        // child and obtain its exit status; otherwise the destructor closes the
        // stream and discards the status.
        class Popen {
            FILE* d_stream;

            Popen(const Popen&);
            Popen& operator=(const Popen&);

        public:
            explicit Popen(const bsl::string& command)
                : d_stream(popen(command.c_str(), "r"))
            {
            }
            ~Popen()
            {
                if (d_stream) {
                    pclose(d_stream);
                }
            }

            bool isOpen() const { return d_stream != NULL; }
            FILE* stream() const { return d_stream; }

            // Reap the child process and return its exit status (see
            // pclose()).  After this call the wrapper no longer owns a stream.
            int close()
            {
                int status = pclose(d_stream);
                d_stream = NULL;
                return status;
            }
        };

        // ---------------------------- Helpers -------------------------------

        // Single-quote 'path' for safe interpolation into a /bin/sh command
        // line, escaping any embedded single quotes.
        bsl::string shellEscapePath(const bsl::string& path)
        {
            bsl::string escaped = "'";
            for (bsl::string::size_type i = 0; i < path.size(); ++i) {
                if (path[i] == '\'') {
                    escaped += "'\\''";
                } else {
                    escaped += path[i];
                }
            }
            escaped += "'";
            return escaped;
        }

        // Demangle a mangled C++ symbol name using the compiler's in-process
        // demangling API (see the include block above).  Returns the demangled
        // name on success, or the original mangled name if demangling fails
        // (e.g. for plain C symbols).
        bsl::string demangleSymbol(const bsl::string& mangled)
        {
#if defined(__GNUC__) || defined(__clang__)
            int status = 0;
            // Owns the malloc'd result and frees it on return -- including if
            // the bsl::string construction below throws.  (bslma::ManagedPtr
            // stands in for bsl::unique_ptr, which is unavailable in C++03; its
            // deleter takes an extra cookie argument, hence freeManagedBuffer.)
            bslma::ManagedPtr<char> demangled(
                abi::__cxa_demangle(mangled.c_str(), NULL, NULL, &status),
                NULL,
                &freeManagedBuffer);
            if (status == 0 && demangled) {
                return bsl::string(demangled.get());
            }
            return mangled;
#elif defined(__SUNPRO_CC)
            // cplus_demangle writes into a caller-supplied buffer and returns
            // DEMANGLE_ESPACE when it is too small.  Grow and retry so that
            // arbitrarily long demangled names are handled without truncation,
            // matching the Itanium path (whose demangler allocates for us).  Any
            // other non-zero return (e.g. DEMANGLE_ENAME for a plain C symbol)
            // means the name is not demangled -- return it unchanged.
            bsl::vector<char> buf(8192);
            for (;;) {
                int rc = cplus_demangle(
                    mangled.c_str(), buf.data(), buf.size());
                if (rc == 0) {
                    return bsl::string(buf.data());
                }
                if (rc != DEMANGLE_ESPACE) {
                    return mangled;
                }
                buf.resize(buf.size() * 2);
            }
#else
    #error "bonobomock: no in-process demangler known for this compiler"
#endif
        }

        // A symbol parsed from one line of nm output: its mangled name and
        // its (uncalibrated) address.
        struct NmSymbol {
            bsl::string mangled;
            size_t address;
        };

        // Parse one line of nm output into an NmSymbol.  Returns an empty
        // optional for lines that are not usable symbol definitions (wrong
        // format, no address, or a cold-section clone).  nm's column layout is
        // platform-specific, so the parsing is too.
        bsl::optional<NmSymbol> parseNmLine(const char* line)
        {
            bsl::string_view content(line);

            // Cold-section clones ("<name> [clone .cold]") are partial copies
            // of a function moved out of the hot path, not its entry point --
            // skip them so we don't patch the wrong address.
            if (content.find("[clone .cold]") != bsl::string_view::npos) {
                return bsl::nullopt;
            }

#ifdef BSLS_PLATFORM_OS_LINUX
            // GNU/Linux: whitespace-separated "<hexAddr> <type> <name>".
            // Undefined symbols have no address and are skipped.
            bsl::istringstream iss(line);
            bsl::string addrField, typeField, nameField;
            if (!(iss >> addrField >> typeField >> nameField)) {
                return bsl::nullopt;
            }

            char* end = NULL;
            errno = 0;
            size_t address = strtoull(addrField.c_str(), &end, 16);
            if (end == addrField.c_str() // no hex digits parsed
                || errno != 0) { // conversion error (e.g. overflow)
                return bsl::nullopt;
            }

            NmSymbol symbol;
            symbol.mangled = nameField;
            symbol.address = address;
            return symbol;

#elif defined(BSLS_PLATFORM_OS_SOLARIS)
            // Solaris: '|'-separated fields.  The symbol name is the last field
            // and the (decimal) address is the second field.
            size_t lastPipe = content.rfind('|');
            if (lastPipe == bsl::string_view::npos) {
                return bsl::nullopt;
            }
            bsl::string_view nameField = bdlb::StringViewUtil::trim(
                content.substr(lastPipe + 1));
            if (nameField.empty()) {
                return bsl::nullopt;
            }

            size_t firstPipe = content.find('|');
            size_t secondPipe = content.find('|', firstPipe + 1);
            if (secondPipe == bsl::string_view::npos) {
                return bsl::nullopt;
            }

            // Extract the leading run of digits from the address field
            // (it may be surrounded by padding/other characters).
            bsl::string digits;
            for (size_t i = firstPipe + 1; i < secondPipe; ++i) {
                if (std::isdigit(static_cast<unsigned char>(content[i]))) {
                    digits += content[i];
                } else if (!digits.empty()) {
                    break;
                }
            }
            if (digits.empty()) {
                return bsl::nullopt;
            }

            errno = 0;
            size_t address = strtoull(digits.c_str(), NULL, 10);
            if (errno != 0) { // conversion error (e.g. overflow)
                return bsl::nullopt;
            }

            NmSymbol symbol;
            symbol.mangled.assign(nameField.data(), nameField.size());
            symbol.address = address;
            return symbol;
#else
    #error "No nm output parser implemented for this OS"
#endif
        }

        // Render the status returned by pclose() into a human-readable
        // description of how the nm child process failed.
        bsl::string formatNmFailure(int status, const bsl::string& taskPath)
        {
            bsl::ostringstream oss;
            oss << "bonobomock: nm failed";
            if (status == -1) {
                oss << " (pclose error)";
            } else if (WIFEXITED(status)) {
                oss << " with exit code " << WEXITSTATUS(status);
            } else if (WIFSIGNALED(status)) {
                oss << " (killed by signal " << WTERMSIG(status) << ")";
            }
            oss << " on " << taskPath;
            return oss.str();
        }

        // Run nm once on 'taskPath' and populate s_symbolCache with every
        // parseable symbol.  No-op if the cache already holds this binary.
        void buildSymbolCache(const bsl::string& taskPath)
        {
            if (s_symbolCacheBuilt && s_cachedTaskPath == taskPath) {
                return;
            }

            s_symbolCacheBuilt = false;
            s_symbolCache.clear();
            s_cachedTaskPath = taskPath;

            Popen nm("nm -- " + shellEscapePath(taskPath));
            if (!nm.isOpen()) {
                throwError("bonobomock failed to run 'nm " + taskPath
                    + "': popen() failed");
            }

            // Read nm's output one line at a time.  getline() malloc's the
            // line buffer, growing it as needed so arbitrarily long mangled
            // names (common in heavily-templated C++) are never truncated.
            // Streaming a line at a time keeps peak memory bounded by the
            // longest line rather than the whole (potentially huge) output.
            // Each iteration's buffer is owned by a scoped ManagedPtr, so it is
            // freed on every path -- EOF, a skipped line, or an exception from
            // the loop body.
            for (;;) {
                char* lineBuf = NULL;
                size_t lineBufCap = 0;
                const bool gotLine = getline(&lineBuf, &lineBufCap, nm.stream()) != -1;
                bslma::ManagedPtr<char> lineBufGuard(
                    lineBuf, NULL, &freeManagedBuffer);
                if (!gotLine) {
                    break; // EOF (getline may still have malloc'd lineBuf)
                }

                bsl::optional<NmSymbol> symbol = parseNmLine(lineBuf);
                if (symbol) {
                    s_symbolCache.push_back(bsl::make_pair(
                        demangleSymbol(symbol->mangled), symbol->address));
                }
            }

            // The loop above drained nm's output to EOF, so any non-zero exit
            // status now reflects a genuine failure (not an early-close/SIGPIPE).
            int status = nm.close();
            if (status != 0) {
                throwError(formatNmFailure(status, taskPath));
            }

            // Only now is the cache valid; on a genuine nm failure we threw
            // above and leave s_symbolCacheBuilt false so a later call retries.
            s_symbolCacheBuilt = true;
        }

        // Decide whether a cached demangled symbol is the function we are
        // looking for.  A match requires all of:
        //   * the symbol contains "<funcName>(" -- the start of its signature;
        //   * its constness matches (const methods carry a trailing const
        //     qualifier in the demangled form);
        //   * the signature's closing ')' is the very end of the symbol -- this
        //     rejects unrelated symbols that merely contain the name, such as
        //     the guard variable of a static local declared inside the function.
        bool demangledMatchesFunction(const bsl::string& demangled,
            const bsl::string& funcName,
            bool isFuncConst)
        {
            bsl::string namePrefix = funcName + "(";
            if (demangled.find(namePrefix) == bsl::string::npos) {
                return false;
            }

            // The demangled const suffix differs by demangler: Sun's cplus_demangle
            // emits ")const", the Itanium abi::__cxa_demangle emits ") const".  Keyed on
            // compiler to match the demangler chosen above (so GCC on Solaris, which uses
            // __cxa_demangle, correctly expects the spaced form).
#if defined(__SUNPRO_CC)
            bsl::string constSuffix = ")const";
#elif defined(__GNUC__) || defined(__clang__)
            bsl::string constSuffix = ") const";
#else
    #error "bonobomock: no demangled const-suffix format known for this compiler"
#endif

            bool hasConst = demangled.find(constSuffix) != bsl::string::npos;
            if (hasConst != isFuncConst) {
                return false;
            }

            bsl::string_view trimmed = bdlb::StringViewUtil::trim(demangled);
            bsl::string expectedEnd = isFuncConst ? constSuffix : bsl::string(")");
            size_t endIdx = trimmed.rfind(expectedEnd);
            return endIdx != bsl::string_view::npos
                && endIdx == trimmed.length() - expectedEnd.length();
        }

        // Look up the (uncalibrated) nm address of 'funcName' with the requested
        // constness, building the symbol cache on first use.  Returns an empty
        // optional if no matching symbol is found.
        bsl::optional<size_t> findRawNmAddress(const bsl::string& funcName,
            const bsl::string& taskPath,
            bool isFuncConst)
        {
            buildSymbolCache(taskPath);

            for (size_t i = 0; i < s_symbolCache.size(); ++i) {
                if (demangledMatchesFunction(
                        s_symbolCache[i].first, funcName, isFuncConst)) {
                    return s_symbolCache[i].second;
                }
            }
            return bsl::nullopt;
        }

    } // unnamed namespace

    namespace NmUtil {

        void pieCalibrationAnchor() { }

        // Force the linker to keep pieCalibrationAnchor in the symbol table:
        // PIE calibration below looks it up by name via nm, so it must not be
        // stripped as an unused static.  A volatile pointer guarantees the
        // reference is emitted.
        static void (*volatile s_pieCalibrationAnchorRef)()
            = &pieCalibrationAnchor;

        bsl::optional<size_t> findFunctionAddress(const bsl::string& funcName,
            const bsl::string& taskPath,
            bool isFuncConst)
        {
            (void)s_pieCalibrationAnchorRef;

            // In a PIE binary the loader applies a random base offset, so nm's
            // reported addresses differ from runtime addresses by a fixed
            // slide.  Recover that slide once by comparing the real runtime
            // address of pieCalibrationAnchor (taken directly) with the address
            // nm reports for it.
            if (!s_pieCalibrated) {
                bsl::optional<size_t> nmAddr = findRawNmAddress(
                    "BloombergLP::bonobomock::NmUtil::pieCalibrationAnchor",
                    taskPath, false);
                if (!nmAddr) {
                    throwError(
                        "bonobomock could not find the address of function "
                        "BloombergLP::bonobomock::NmUtil::pieCalibrationAnchor"
                        " in taskPath="
                        + taskPath);
                }
                s_pieOffset = reinterpret_cast<size_t>(&pieCalibrationAnchor) - *nmAddr;
                s_pieCalibrated = true;
            }

            bsl::optional<size_t> rawAddr = findRawNmAddress(funcName, taskPath, isFuncConst);
            if (!rawAddr) {
                return bsl::nullopt;
            }

            return *rawAddr + s_pieOffset; // nm address -> runtime address
        }

    } // namespace NmUtil
} // namespace bonobomock
} // namespace BloombergLP
