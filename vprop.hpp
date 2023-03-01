//
// Created by orgrinrt on 28.2.2023.
//

#ifndef VPROP_HPP
#define VPROP_HPP

#if defined(_MSC_VER) || defined(__clang__)
#define prop(p_type, p_prop_name, p_getter, p_setter)                                                \
    /* clang-format off */                                                                         \
public:                                                                                            \
    __declspec(property(get = p_getter, put = p_setter)) p_type p_prop_name; \
    /* clang-format on */

#define vprop(p_type, p_prop_name)                                                                   \
    /* clang-format off */                                                                         \
protected:                                                                                         \
    virtual p_type get_##p_prop_name() const       = 0;                                            \
    virtual void set_##p_prop_name(p_type p_value) = 0;                                            \
                                                                                                   \
public:                                                                                            \
    __declspec(property(get = get_##p_prop_name, put = set_##p_prop_name)) p_type p_prop_name; \
    /* clang-format on */

#else
// TODO: find a way to do this in GCC etc
#define prop(p_type, p_prop_name, p_getter, p_setter) ...
#define vprop(p_type, p_prop_name) ...
#endif//defined(_MSC_VER) || defined(__clang__)

#endif//VPROP_HPP
