#include <iostream>
#include <type_traits>
#include <string>

template <class T, T v>
struct integral_constant {
  static constexpr T value = v;
};

template <bool v>
struct bool_constant : public integral_constant<bool, v> {};

using true_type = bool_constant<true>;
using false_type = bool_constant<false>;

template <class T>
struct is_const : false_type {
};

template <class T>
struct is_const<const T> : true_type {
};

template <class T>
struct IsConst {
    static constexpr bool type = false;
};

template <class T>
struct IsConst<const T> {
    static constexpr bool type = true;
};

template <class T>
struct RemoveConst {
  using type = T;
};

template <class T>
struct RemoveConst<const T> {
  using type = T;
};

// template <class T>
// struct is_pointer: bool_constant<
//     std::disjunction_v<is_pointer<std::remove_cv<T>>> {
// };

template <class T>
struct is_pointer : false_type {}; // NOLINT

template <class T>
struct is_pointer<T*> : true_type {};  // NOLINT

template <class T>
struct is_pointer<const T*> :  true_type {};  // NOLINT

template <class T>
struct is_pointer<const volatile T*> : true_type {};  // NOLINT

// template <class T>
// struct my_is_pointer : false_type {};

// template <class T>
// struct my_is_pointer<std::remove_cv_t<T>*> : true_type {};  :(

// template <class T, class U = std::remove_cv_t<T>>
// struct my_is_pointer : false_type {};

// template <class T>
// struct my_is_pointer<T> : true_type {};

template <class T>
struct is_pointer_helper : false_type {};

template <class T>
struct is_pointer_helper<T*> : true_type {};

template <class T>
struct is_pointer : is_pointer_helper<std::remove_cv_t<T>> {};

struct Base {};

struct Derived : public Base {};

// template <class T>
// std::is_base_of<T, Derived>;  // Base == true

// std::conjunction<true_type, false_type>
template <class T>
void PrintIfString(const T& value) {
    if constexpr (std::is_same_v<T, std::string>) {
        std::cout << value << std::endl;
    }
}

// SFINAE
// substitution failure is not an error

template <class T, bool Predicate>
struct EnableIf {};

template <class T>
struct EnableIf<T, true> {
    using value = T;
};

template <class T, class U = typename EnableIf<T, std::is_same_v<T, int>>::value>
void f() {
    U x;
}

int main() {   
    PrintIfString<int>(1);
    PrintIfString<std::string>("7aa7oo7aa7");

    f<int>();
    f<double>();

    // std::remove_reference;
    // std::is_pointer;
    // std::is_reference;
    // std::is_rvalue_reference;
    // std::is_const;
    // std::integral_constant;
    // std::bool_constant;
    // std::true_type;
    // std::false_type;

    return 0;
}

