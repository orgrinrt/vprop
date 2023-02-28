# vprop

Simple virtual property macros for cpp (clang &amp; msvc)

## What and why

A macro to simplify declaring virtual properties, mainly to make declaring interfaces neater.

## Usage

```cpp
struct Foo {
        vprop(bar, float)
        vprop(baz, int)
        vprop(buz, bool)
        // ...
    };
```

## Note

For now, requires either

* `msvc` or
* `clang` with either `-fdeclspec` or `-fms-extensions` enabled

due to use of `__declspec(property(get=, put=))`
