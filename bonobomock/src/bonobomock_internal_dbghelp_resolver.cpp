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

#include <bonobomock_internal_dbghelp_resolver.h>

#include <windows.h>

#include <dbghelp.h>

#include <bsl_array.h>
#include <bsl_optional.h>
#include <bsl_string.h>
#include <bsl_unordered_map.h>
#include <bsl_vector.h>

namespace BloombergLP {
namespace bonobomock {

    namespace {

        struct CachedSymbol {
            bool isConst;
            bool constVerified;
            size_t address;
        };

        typedef bsl::unordered_map<bsl::string, bsl::vector<CachedSymbol> >
            SymbolCache;

        // SymEnumSymbols callback used once at initialization to populate
        // s_symbolCache.
        //
        // On some MSVC/DbgHelp configurations (observed on x86-32
        // RelWithDebInfo), pSymInfo->Name arrives already-undecorated despite
        // SYMOPT_UNDNAME being cleared.  When names are mangled ('?' prefix)
        // we can detect const-ness via UNDNAME_NAME_ONLY's " const" suffix.
        // When names are already undecorated the const qualifier is lost; we
        // store constVerified=false so lookups accept either const/non-const.
        //
        // Limitation: if a class has both `void foo()` and `void foo() const`,
        // and symbols arrive undecorated, this function cannot distinguish them
        // and will return the first match.  BONOBO_MOCK_PRIVATE users who need to
        // mock both overloads must give them distinct names.
        static BOOL CALLBACK populateCacheCallback(PSYMBOL_INFO pSymInfo,
            ULONG /*symbolSize*/,
            PVOID userContext)
        {
            SymbolCache* cache = static_cast<SymbolCache*>(userContext);

            const char* rawName = pSymInfo->Name;
            bsl::string nameOnly;
            bool constVerified = false;
            bool hasConst = false;

            if (rawName[0] == '?') {
                bsl::array<char, 2048> undecBuf;
                DWORD len = UnDecorateSymbolName(rawName, undecBuf.data(),
                    static_cast<DWORD>(undecBuf.size()), UNDNAME_NAME_ONLY);
                if (len == 0) {
                    return TRUE;
                }
                bsl::string undecName(undecBuf.data(), len);

                const bsl::string constSuffix(" const");
                if (undecName.size() > constSuffix.size() && undecName.compare(undecName.size() - constSuffix.size(), constSuffix.size(), constSuffix) == 0) {
                    hasConst = true;
                    undecName.resize(undecName.size() - constSuffix.size());
                }
                nameOnly = undecName;
                constVerified = true;
            } else {
                nameOnly = rawName;
            }

            CachedSymbol sym;
            sym.isConst = hasConst;
            sym.constVerified = constVerified;
            sym.address = static_cast<size_t>(pSymInfo->Address);
            (*cache)[nameOnly].push_back(sym);
            return TRUE;
        }

        static bool findWindowsFunctionAddress(const bsl::string& funcName,
            bool isFuncConst,
            size_t& outAddr)
        {
            static DWORD64 s_moduleBase = 0;
            static SymbolCache s_symbolCache;

            if (!s_moduleBase) {
                // Get the full path to this executable.
                bsl::string fullExePath(MAX_PATH, '\0');
                DWORD pathLen = GetModuleFileNameA(NULL, &fullExePath[0], MAX_PATH);
                if (pathLen == 0 || pathLen >= MAX_PATH) {
                    return false;
                }
                fullExePath.resize(pathLen);

                // Derive the directory for the PDB search path.
                bsl::string exeDir = fullExePath;
                bsl::string::size_type sep = exeDir.rfind('\\');
                if (sep != bsl::string::npos) {
                    exeDir.resize(sep);
                }

                // Do NOT set SYMOPT_UNDNAME: with that flag pSymInfo->Name is
                // already-undecorated, so our UnDecorateSymbolName() call
                // (which expects a raw mangled '?' name) returns failure and
                // the callback skips every symbol.
                SymSetOptions(SymGetOptions() & ~SYMOPT_UNDNAME);

                // Initialize without auto-invading: we will load the module
                // explicitly below so we control exactly which PDB is used.
                SymInitialize(GetCurrentProcess(), exeDir.c_str(), FALSE);

                // Explicitly load THIS executable's debug symbols by full path.
                // SymInitialize with fInvadeProcess=TRUE may fail to find the PDB
                // if the embedded debug path in the PE header does not match the
                // actual filename.  SymLoadModuleEx with the actual exe path
                // triggers the correct PDB lookup.
                //
                // Pass the ACTUAL runtime base address (from GetModuleHandle) as
                // DllBase.  If we pass 0, DbgHelp reads the preferred base from
                // the PE header; with ASLR enabled the process may be loaded at a
                // different address, making all pSymInfo->Address values wrong and
                // causing access violations when we try to patch the returned addr.
                DWORD64 actualBase = static_cast<DWORD64>(
                    reinterpret_cast<uintptr_t>(GetModuleHandle(NULL)));
                s_moduleBase = SymLoadModuleEx(GetCurrentProcess(),
                    NULL,
                    fullExePath.c_str(),
                    NULL,
                    actualBase,
                    0,
                    NULL,
                    0);

                if (s_moduleBase == 0) {
                    // Already loaded — use the actual base as the search key.
                    s_moduleBase = actualBase;
                }

                // Enumerate all symbols once and cache them.  Subsequent
                // lookups iterate s_symbolCache rather than re-invoking
                // SymEnumSymbols, reducing O(n) DbgHelp calls to O(1).
                DWORD savedOpts = SymGetOptions();
                SymSetOptions(savedOpts & ~SYMOPT_UNDNAME);
                SymEnumSymbols(GetCurrentProcess(), s_moduleBase, "*",
                    populateCacheCallback, &s_symbolCache);
                SymSetOptions(savedOpts);
            }

            SymbolCache::const_iterator it = s_symbolCache.find(funcName);
            if (it == s_symbolCache.end()) {
                return false;
            }
            for (const CachedSymbol& sym : it->second) {
                if (sym.constVerified && sym.isConst != isFuncConst) {
                    continue;
                }
                outAddr = sym.address;
                return true;
            }
            return false;
        }

    } // unnamed namespace

    bsl::optional<size_t> DbgHelpResolver::findFunctionAddress(
        const bsl::string& funcName,
        const bsl::string& taskPath,
        bool isFuncConst)
    {
        (void)taskPath;
        size_t addr = 0;
        if (!findWindowsFunctionAddress(funcName, isFuncConst, addr)) {
            return bsl::nullopt;
        }
        return addr;
    }

} // namespace bonobomock
} // namespace BloombergLP
