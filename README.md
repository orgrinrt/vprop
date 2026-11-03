# `vprop`

> Property macros for C++ on clang and msvc, for declaring virtual properties.

A single header, `vprop.hpp`, with two macros that make declaring properties on an interface neater. `prop(type, name, getter, setter)` declares a property that goes through the given getter and setter, and `vprop(type, name)` declares a pure virtual one.

```cpp
struct IFoo {
    prop(float, bar, m_get_bar, m_set_bar)
private:
    float m_bar;
    float m_get_bar() const { return m_bar; }
    void m_set_bar(float value) { m_bar = value; }
};

struct IBaz {
    vprop(float, bar)
    vprop(int, baz)
    vprop(bool, bat)
};
```

They are built on `__declspec(property(get=, put=))`, so they need msvc, or clang with `-fdeclspec` or `-fms-extensions`.

## License

The project is licensed under the MIT License, see [LICENSE](LICENSE).
