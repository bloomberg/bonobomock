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

#ifndef INCLUDED_BONOBOMOCK_INTERNAL_MOCKER
#define INCLUDED_BONOBOMOCK_INTERNAL_MOCKER

#if !defined(INCLUDED_BONOBOMOCK_API) && !defined(BONOBO_MOCK_BUILDING_LIBRARY)
    #error "This is a private header. Directly including it is a contract violation and undefined behavior."
#endif

#include <bonobomock_internal_abi_detection.h>
#include <bonobomock_internal_code_address.h>
#include <bonobomock_internal_error.h>
#include <bonobomock_internal_gmock.h>
#include <bonobomock_internal_patch.h>
#include <bonobomock_internal_private_address_resolver.h>
#include <bonobomock_internal_virtual_resolve.h>
#include <bonobomock_internal_windows_thunk_resolve.h>

#include <bslmt_once.h>
#include <bsls_compilerfeatures.h>

#include <bsl_iostream.h>
#include <cstring>
#include <type_traits>

namespace BloombergLP {
namespace bonobomock {

// Resolves a member function pointer to the memory address where the function
// code lives, for both virtual and non-virtual functions.
// Under the Itanium ABI (GCC/Clang), a pointer-to-virtual-member-function
// encodes a vtable offset rather than a real address. If targetAddr is smaller
// than a page size, we treat it as a vtable offset and resolve the real
// address by instantiating the class and indexing into its vtable. Otherwise,
// it is already the real address of a non-virtual function and is returned
// as-is.
// Requires C++17 for if constexpr, std::is_polymorphic_v, and
// std::is_default_constructible_v.
#if BONOBO_MOCK_INTERNAL_IS_ITANIUM_ABI && defined(BSLS_COMPILERFEATURES_FULL_CPP17)
    template <typename C, typename PMF>
    typename std::enable_if<!std::is_polymorphic<C>::value, void*>::type
    resolveFunctionAddress(const PMF& targetFunc)
    {
        return toCodeAddress(targetFunc);
    }

    template <typename C, typename PMF>
    typename std::enable_if<std::is_polymorphic<C>::value
            && !std::is_default_constructible<C>::value,
        void*>::type
    resolveFunctionAddress(const PMF& targetFunc)
    {
        size_t targetAddr;
        std::memcpy(&targetAddr, &targetFunc, sizeof(size_t));
        if (targetAddr < Patch::pageSize()) {
            throwError("bonobomock ERROR: BONOBO_MOCK() detected a virtual "
                       "function but class is not "
                       "default-constructible.\n"
                       "Use BONOBO_MOCK_VIRTUAL_ON(instance, "
                       "&Class::func) instead.");
        }
        return reinterpret_cast<void*>(targetAddr);
    }

    template <typename C, typename PMF>
    typename std::enable_if<std::is_polymorphic<C>::value
            && std::is_default_constructible<C>::value,
        void*>::type
    resolveFunctionAddress(const PMF& targetFunc)
    {
        size_t targetAddr;
        std::memcpy(&targetAddr, &targetFunc, sizeof(size_t));
        if (targetAddr < Patch::pageSize()) {
            C l_obj;
            return resolveFromVtable(
                targetAddr, reinterpret_cast<void*>(&l_obj));
        }
        return reinterpret_cast<void*>(targetAddr);
    }
#endif

    template <typename T, int N>
    class Mock;

    template <typename T, int N>
    class MockVirtual;

    template <typename T, int N>
    class MockPrivate;

    template <typename T, int N>
    class MockManager;

    template <typename T, int N>
    class MockVirtualManager;

    template <typename T, int N>
    class MockPrivateManager;

    template <typename R, typename... P, int N>
    class MockManager<R(P...), N> {
    public:
        static MockManager& getInstance()
        {
            static MockManager* p = NULL;
            BSLMT_ONCE_DO
            {
                static MockManager self;
                p = &self;
            }
            return *p;
        }

        Mock<R(P...), N>*& get()
        {
            return d_obj;
        }

        void clear()
        {
            d_obj = NULL;
        }

    private:
        MockManager() { }
        MockManager(const MockManager& rhs) = delete;
        MockManager& operator=(const MockManager& rhs) = delete;
        MockManager& operator=(MockManager&& rhs) = delete;

        Mock<R(P...), N>* d_obj;
    };

    template <typename R, typename C, typename... P, int N>
    class MockManager<R (C::*)(P...), N> {
    public:
        static MockManager& getInstance()
        {
            static MockManager* p = NULL;
            BSLMT_ONCE_DO
            {
                static MockManager self;
                p = &self;
            }
            return *p;
        }

        Mock<R (C::*)(P...), N>*& get()
        {
            return d_obj;
        }

        void clear()
        {
            d_obj = NULL;
        }

    private:
        MockManager() { }
        MockManager(const MockManager& rhs) = delete;
        MockManager& operator=(const MockManager& rhs) = delete;
        MockManager& operator=(MockManager&& rhs) = delete;

        Mock<R (C::*)(P...), N>* d_obj;
    };

    template <typename R, typename C, typename... P, int N>
    class MockManager<R (C::*)(P...) const, N> {
    public:
        static MockManager& getInstance()
        {
            static MockManager* p = NULL;
            BSLMT_ONCE_DO
            {
                static MockManager self;
                p = &self;
            }
            return *p;
        }

        Mock<R (C::*)(P...) const, N>*& get()
        {
            return d_obj;
        }

        void clear()
        {
            d_obj = NULL;
        }

    private:
        MockManager() { }
        MockManager(const MockManager& rhs) = delete;
        MockManager& operator=(const MockManager& rhs) = delete;
        MockManager& operator=(MockManager&& rhs) = delete;

        Mock<R (C::*)(P...) const, N>* d_obj;
    };

    template <typename R, typename C, typename... P, int N>
    class MockVirtualManager<R (C::*)(P...), N> {
    public:
        static MockVirtualManager& getInstance()
        {
            static MockVirtualManager* p = NULL;
            BSLMT_ONCE_DO
            {
                static MockVirtualManager self;
                p = &self;
            }
            return *p;
        }

        MockVirtual<R (C::*)(P...), N>*& get()
        {
            return d_obj;
        }

        void clear()
        {
            d_obj = NULL;
        }

    private:
        MockVirtualManager() { }
        MockVirtualManager(const MockVirtualManager& rhs) = delete;
        MockVirtualManager& operator=(const MockVirtualManager& rhs) = delete;
        MockVirtualManager& operator=(MockVirtualManager&& rhs) = delete;

        MockVirtual<R (C::*)(P...), N>* d_obj;
    };

    template <typename R, typename C, typename... P, int N>
    class MockVirtualManager<R (C::*)(P...) const, N> {
    public:
        static MockVirtualManager& getInstance()
        {
            static MockVirtualManager* p = NULL;
            BSLMT_ONCE_DO
            {
                static MockVirtualManager self;
                p = &self;
            }
            return *p;
        }

        MockVirtual<R (C::*)(P...) const, N>*& get()
        {
            return d_obj;
        }

        void clear()
        {
            d_obj = NULL;
        }

    private:
        MockVirtualManager() { }
        MockVirtualManager(const MockVirtualManager& rhs) = delete;
        MockVirtualManager& operator=(const MockVirtualManager& rhs) = delete;
        MockVirtualManager& operator=(MockVirtualManager&& rhs) = delete;

        MockVirtual<R (C::*)(P...) const, N>* d_obj;
    };

    template <typename R, typename C, typename... P, int N>
    class MockPrivateManager<R (C::*)(P...), N> {
    public:
        static MockPrivateManager& getInstance()
        {
            static MockPrivateManager* p = NULL;
            BSLMT_ONCE_DO
            {
                static MockPrivateManager self;
                p = &self;
            }
            return *p;
        }

        MockPrivate<R (C::*)(P...), N>*& get()
        {
            return d_obj;
        }

        void clear()
        {
            d_obj = NULL;
        }

    private:
        MockPrivateManager() { }
        MockPrivateManager(const MockPrivateManager& rhs) = delete;
        MockPrivateManager& operator=(const MockPrivateManager& rhs) = delete;
        MockPrivateManager& operator=(MockPrivateManager&& rhs) = delete;

        MockPrivate<R (C::*)(P...), N>* d_obj;
    };

    template <typename R, typename C, typename... P, int N>
    class MockPrivateManager<R (C::*)(P...) const, N> {
    public:
        static MockPrivateManager& getInstance()
        {
            static MockPrivateManager* p = NULL;
            BSLMT_ONCE_DO
            {
                static MockPrivateManager self;
                p = &self;
            }
            return *p;
        }

        MockPrivate<R (C::*)(P...) const, N>*& get()
        {
            return d_obj;
        }

        void clear()
        {
            d_obj = NULL;
        }

    private:
        MockPrivateManager() { }
        MockPrivateManager(const MockPrivateManager& rhs) = delete;
        MockPrivateManager& operator=(const MockPrivateManager& rhs) = delete;
        MockPrivateManager& operator=(MockPrivateManager&& rhs) = delete;

        MockPrivate<R (C::*)(P...) const, N>* d_obj;
    };

    template <typename R, typename... P, int N>
    class Mock<R(P...), N> : public GMock<R(P...)> {
        typedef R FuncType(P...);
        typedef R FuncTypeVariadic(P..., ...);

        static_assert(sizeof(FuncType*) == sizeof(size_t),
            "Function pointer size must equal size_t size");

    public:
        // Constructor for private static functions: the address is resolved by
        // name from the symbol table (static functions are never const).
        Mock(const bsl::string& funcName)
            : GMock<R(P...)>(funcName)
            , d_targetFunc(NULL)
            , d_targetFuncVariadic(NULL)
            , d_funcName(funcName)
        {
            size_t addr = PrivateAddressResolver::findNonConstPrivateAddress(funcName);
            MockManager<R(P...), N>::getInstance().get() = this;
            void* l_targetAddr = reinterpret_cast<void*>(addr);
            FuncType* l_mockFunction = &Mock::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        Mock(R (*targetFunc)(P...), const bsl::string& funcName)
            : GMock<R(P...)>(funcName)
            , d_targetFunc(targetFunc)
            , d_funcName(funcName)
        {
            MockManager<R(P...), N>::getInstance().get() = this;
            void* l_targetAddr = toCodeAddress(d_targetFunc);
#ifdef BSLS_PLATFORM_OS_WINDOWS
            l_targetAddr = resolveJmpThunk(l_targetAddr);
#endif
            FuncType* l_mockFunction = &Mock::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        Mock(R (*targetFunc)(P..., ...), const bsl::string& funcName)
            : GMock<R(P...)>(funcName)
            , d_targetFuncVariadic(targetFunc)
            , d_funcName(funcName)
        {
            MockManager<R(P...), N>::getInstance().get() = this;
            void* l_targetAddr = toCodeAddress(d_targetFuncVariadic);
#ifdef BSLS_PLATFORM_OS_WINDOWS
            l_targetAddr = resolveJmpThunk(l_targetAddr);
#endif
            FuncType* l_mockFunction = &Mock::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        virtual ~Mock()
        {
            // Restore runtime patch
            d_patch.restore();
            MockManager<R(P...), N>::getInstance().clear();
        }

        static R mockFunction(P... p)
        {
            Mock<R(P...), N>* obj = MockManager<R(P...), N>::getInstance().get();
            return obj->bonobomockInternalForwardFunc(std::forward<P>(p)...);
        }

        void restore()
        {
            // Restore runtime patch
            d_patch.restore();
        }

    private:
        FuncType* d_targetFunc;
        FuncTypeVariadic* d_targetFuncVariadic;
        bsl::string d_funcName;
        Patch d_patch;
    };

    template <typename R, typename C, typename... P, int N>
    class Mock<R (C::*)(P...), N> : public GMock<R(void*, P...)> {
        typedef R (Mock::*FuncType)(P...);
        static_assert(sizeof(FuncType*) == sizeof(size_t),
            "Function pointer size must equal size_t size");

    public:
        Mock(R (C::*targetFunc)(P...), const bsl::string& funcName)
            : GMock<R(void*, P...)>(funcName)
        {
            MockManager<R (C::*)(P...), N>::getInstance().get() = this;
            // When the compiler is using Itanium ABI (GCC/Clang), and C++17 features are available,
            // we can auto-detect virtual vs non-virtual from the member function pointer representation.
            // In all other cases, this function can be used only with non-virtual methods as we assume
            // that the passed in pointer to be the actual address of the function. In such cases, virtual
            // functions require the BONOBO_MOCK_VIRTUAL macros.
            void* l_targetAddr;
#if BONOBO_MOCK_INTERNAL_IS_ITANIUM_ABI && defined(BSLS_COMPILERFEATURES_FULL_CPP17)
            l_targetAddr = resolveFunctionAddress<C>(targetFunc);
#elif defined(BSLS_PLATFORM_OS_WINDOWS)
            l_targetAddr = resolveJmpThunk(toCodeAddress(targetFunc));
#else
            l_targetAddr = toCodeAddress(targetFunc);
#endif
            FuncType l_mockFunction = &Mock::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        virtual ~Mock()
        {
            d_patch.restore();
            MockManager<R (C::*)(P...), N>::getInstance().clear();
        }

        R mockFunction(P... p)
        {
            Mock<R (C::*)(P...), N>* obj = MockManager<R (C::*)(P...), N>::getInstance().get();
            return obj->bonobomockInternalForwardFunc(this, std::forward<P>(p)...);
        }

        virtual void restore()
        {
            // Restore runtime patch
            d_patch.restore();
        }

    private:
        Patch d_patch;
    };

    template <typename R, typename C, typename... P, int N>
    class Mock<R (C::*)(P...) const, N> : public GMock<R(const void*, P...)> {
        typedef R (Mock::*FuncType)(P...);
        static_assert(sizeof(FuncType*) == sizeof(size_t),
            "Function pointer size must equal size_t size");

    public:
        Mock(R (C::*targetFunc)(P...) const, const bsl::string& funcName)
            : GMock<R(const void*, P...)>(funcName)
        {
            MockManager<R (C::*)(P...) const, N>::getInstance().get() = this;
            // When the compiler is using Itanium ABI (GCC/Clang), and C++17 features are available,
            // we can auto-detect virtual vs non-virtual from the member function pointer representation.
            // In all other cases, this function can be used only with non-virtual methods as we assume
            // that the passed in pointer to be the actual address of the function. In such cases, virtual
            // functions require the BONOBO_MOCK_VIRTUAL macros.
            void* l_targetAddr;
#if BONOBO_MOCK_INTERNAL_IS_ITANIUM_ABI && defined(BSLS_COMPILERFEATURES_FULL_CPP17)
            l_targetAddr = resolveFunctionAddress<C>(targetFunc);
#elif defined(BSLS_PLATFORM_OS_WINDOWS)
            l_targetAddr = resolveJmpThunk(toCodeAddress(targetFunc));
#else
            l_targetAddr = toCodeAddress(targetFunc);
#endif
            FuncType l_mockFunction = &Mock::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        virtual ~Mock()
        {
            d_patch.restore();
            MockManager<R (C::*)(P...), N>::getInstance().clear();
        }

        R mockFunction(P... p)
        {
            Mock<R (C::*)(P...) const, N>* obj = MockManager<R (C::*)(P...) const, N>::getInstance().get();
            return obj->bonobomockInternalForwardFunc(this, std::forward<P>(p)...);
        }

        virtual void restore()
        {
            // Restore runtime patch
            d_patch.restore();
        }

    private:
        Patch d_patch;
    };

    template <typename R, typename C, typename... P, int N>
    class MockVirtual<R (C::*)(P...), N> : public GMock<R(void*, P...)> {
        typedef R (MockVirtual::*FuncType)(P...);
        static_assert(sizeof(FuncType*) == sizeof(size_t),
            "Function pointer size must equal size_t size");

    public:
        MockVirtual(R (C::*targetFunc)(P...), const bsl::string& funcName)
            : GMock<R(void*, P...)>(funcName)
        {
            MockVirtualManager<R (C::*)(P...), N>::getInstance().get() = this;
            // Resolve virtual function address from vtable
            C l_obj;
            void* l_targetAddr = resolveVirtualAddress(
                reinterpret_cast<const void*>(&targetFunc),
                reinterpret_cast<void*>(&l_obj));

            FuncType l_mockFunction = &MockVirtual::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);

            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        MockVirtual(C& inst, R (C::*targetFunc)(P...), const bsl::string& funcName)
            : GMock<R(void*, P...)>(funcName)
        {
            MockVirtualManager<R (C::*)(P...), N>::getInstance().get() = this;
            // Resolve virtual function address from vtable
            void* l_targetAddr = resolveVirtualAddress(
                reinterpret_cast<const void*>(&targetFunc),
                reinterpret_cast<void*>(&inst));

            FuncType l_mockFunction = &MockVirtual::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);

            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }
        virtual ~MockVirtual()
        {
            // Restore runtime patch
            d_patch.restore();
            MockVirtualManager<R (C::*)(P...), N>::getInstance().clear();
        }

        R mockFunction(P... p)
        {
            MockVirtual<R (C::*)(P...), N>* obj = MockVirtualManager<R (C::*)(P...), N>::getInstance().get();
            return obj->bonobomockInternalForwardFunc(this, std::forward<P>(p)...);
        }

        virtual void restore()
        {
            // Restore runtime patch
            d_patch.restore();
        }

    private:
        Patch d_patch;
    };

    template <typename R, typename C, typename... P, int N>
    class MockVirtual<R (C::*)(P...) const, N> : public GMock<R(const void*, P...)> {
        typedef R (MockVirtual::*FuncType)(P...);
        static_assert(sizeof(FuncType*) == sizeof(size_t),
            "Function pointer size must equal size_t size");

    public:
        MockVirtual(R (C::*targetFunc)(P...) const, const bsl::string& funcName)
            : GMock<R(const void*, P...)>(funcName)
        {
            MockVirtualManager<R (C::*)(P...) const, N>::getInstance().get() = this;
            // Resolve virtual function address from vtable
            C l_obj;
            void* l_targetAddr = resolveVirtualAddress(
                reinterpret_cast<const void*>(&targetFunc),
                reinterpret_cast<void*>(&l_obj));

            FuncType l_mockFunction = &MockVirtual::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);

            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        MockVirtual(const C& inst, R (C::*targetFunc)(P...) const, const bsl::string& funcName)
            : GMock<R(const void*, P...)>(funcName)
        {
            MockVirtualManager<R (C::*)(P...) const, N>::getInstance().get() = this;
            // Resolve virtual function address from vtable
            void* l_targetAddr = resolveVirtualAddress(
                reinterpret_cast<const void*>(&targetFunc),
                const_cast<void*>(reinterpret_cast<const void*>(&inst)));

            FuncType l_mockFunction = &MockVirtual::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);

            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }
        virtual ~MockVirtual()
        {
            // Restore runtime patch
            d_patch.restore();
            MockVirtualManager<R (C::*)(P...), N>::getInstance().clear();
        }

        R mockFunction(P... p)
        {
            MockVirtual<R (C::*)(P...) const, N>* obj = MockVirtualManager<R (C::*)(P...) const, N>::getInstance().get();
            return obj->bonobomockInternalForwardFunc(this, std::forward<P>(p)...);
        }

        virtual void restore()
        {
            // Restore runtime patch
            d_patch.restore();
        }

    private:
        Patch d_patch;
    };

    template <typename R, typename C, typename... P, int N>
    class MockPrivate<R (C::*)(P...), N> : public GMock<R(void*, P...)> {
        typedef R (MockPrivate::*FuncType)(P...);
        static_assert(sizeof(FuncType*) == sizeof(size_t),
            "Function pointer size must equal size_t size");

    public:
        // The address is resolved by name from the symbol table. This is the
        // non-const specialization, so a non-const symbol is requested.
        MockPrivate(const bsl::string& funcName)
            : GMock<R(void*, P...)>(funcName)
        {
            // Get function address
            size_t addr = PrivateAddressResolver::findNonConstPrivateAddress(funcName);
            MockPrivateManager<R (C::*)(P...), N>::getInstance().get() = this;
            void* l_targetAddr = reinterpret_cast<void*>(addr);
            FuncType l_mockFunction = &MockPrivate::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        virtual ~MockPrivate()
        {
            // Restore runtime patch
            d_patch.restore();
            MockPrivateManager<R (C::*)(P...), N>::getInstance().clear();
        }

        R mockFunction(P... p)
        {
            MockPrivate<R (C::*)(P...), N>* obj = MockPrivateManager<R (C::*)(P...), N>::getInstance().get();
            return obj->bonobomockInternalForwardFunc(this, std::forward<P>(p)...);
        }

        virtual void restore()
        {
            // Restore runtime patch
            d_patch.restore();
        }

    private:
        Patch d_patch;
    };

    template <typename R, typename C, typename... P, int N>
    class MockPrivate<R (C::*)(P...) const, N> : public GMock<R(const void*, P...)> {
        typedef R (MockPrivate::*FuncType)(P...);
        static_assert(sizeof(FuncType*) == sizeof(size_t),
            "Function pointer size must equal size_t size");

    public:
        // The address is resolved by name from the symbol table. This is the
        // const specialization, so a const symbol is requested.
        MockPrivate(const bsl::string& funcName)
            : GMock<R(const void*, P...)>(funcName)
        {
            // Get function address
            size_t addr = PrivateAddressResolver::findConstPrivateAddress(funcName);
            MockPrivateManager<R (C::*)(P...) const, N>::getInstance().get() = this;
            void* l_targetAddr = reinterpret_cast<void*>(addr);
            FuncType l_mockFunction = &MockPrivate::mockFunction;
            void* l_mockAddr = toCodeAddress(l_mockFunction);
            // Setup runtime patch
            d_patch.setup(l_targetAddr, l_mockAddr);
        }

        virtual ~MockPrivate()
        {
            // Restore runtime patch
            d_patch.restore();
            MockPrivateManager<R (C::*)(P...) const, N>::getInstance().clear();
        }

        R mockFunction(P... p)
        {
            MockPrivate<R (C::*)(P...) const, N>* obj = MockPrivateManager<R (C::*)(P...) const, N>::getInstance().get();
            return obj->bonobomockInternalForwardFunc(this, std::forward<P>(p)...);
        }

        virtual void restore()
        {
            // Restore runtime patch
            d_patch.restore();
        }

    private:
        Patch d_patch;
    };

}
}

#endif
