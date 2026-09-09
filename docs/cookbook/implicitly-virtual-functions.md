# Implicitly Virtual Functions

In C++, a function can be virtual even if it is not declared with the `virtual` keyword. This happens when a base class declares the function as `virtual` -- all overrides of that function in derived classes are automatically virtual, regardless of whether the `virtual` keyword is used.

## Example

```c++
class Animal {
public:
    virtual int speak(bool loud) {
        return 0;
    }
};

class Dog : public Animal {
public:
    // This function is virtual even though it's not declared with `virtual`.
    // It overrides Animal::speak, so it is implicitly virtual.
    int speak(bool loud) {
        return loud ? 100 : 50;
    }
};
```

In this example, `Dog::speak` is implicitly virtual because it overrides `Animal::speak`, which is declared `virtual`. Even though `Dog::speak` has no `virtual` keyword, it behaves as a virtual function.

On Itanium ABI compilers (GCC, Clang) with C++11 or later, `BONOBO_MOCK` auto-detects this and handles it correctly — no special action is needed.

On SunPro or C++03, you **must** use `BONOBO_MOCK_VIRTUAL` or `BONOBO_MOCK_VIRTUAL_ON` for implicitly virtual functions. Using `BONOBO_MOCK` on these compilers will not work correctly.

## How to check if your function is implicitly virtual

Look at the class hierarchy. If **any** base class declares a function with the same name and signature as `virtual`, then your function is virtual too, even without the keyword. This applies through the entire inheritance chain -- if a grandparent class declares the function as virtual, it remains virtual in all descendants.

## What to do

If the function you want to mock is implicitly virtual, follow the instructions in [Mock Virtual Function](./mock-virtual-functions.md) instead.

---

[← Back to Cookbook](index.md)

[← Documentation Home](../index.md)
