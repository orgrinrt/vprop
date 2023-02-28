# vprop

Simple property macros for cpp (clang &amp; msvc)

## What and why

Macros that simplify declaring virtual properties, mainly to make declaring interfaces neater:

### Property

````cpp
prop(p_type, p_prop_name, p_getter, p_setter)
````

### Pure virtual property

````cpp
vprop(p_type, p_prop_name)
````

## Usage

### Property

```cpp
struct IFoo {
    prop(float, bar, m_get_bar, m_set_bar)
private:
    float m_bar;
    float m_get_bar() const { return m_bar; }
    void m_set_bar(float value) { m_bar = value; }
};

```

### Pure virtual property

```cpp
struct IFoo {
    vprop(float, bar)
    vprop(int, baz)
    vprop(bool, bat)
    // ...
};
```

## Note

For now, requires either

* `msvc` or
* `clang` with either `-fdeclspec` or `-fms-extensions` enabled

due to use of `__declspec(property(get=, put=))`
