#include <iostream>
#include <type_traits>
#include <cassert>

template <bool T>
struct bool_constant {
    static constexpr bool value = T;
};

using true_type = bool_constant<true>;
using false_type = bool_constant<false>;

struct Class : true_type {
    // by inheritance
    // static constexpr bool value = true;
};

template <class T>
struct IsArray : std::false_type {};

template <class T>
inline constexpr bool kIsArrayV = IsArray<T>::value;

template <class T>
struct IsArray<T[]> : std::true_type {};

template <class T, size_t N>
struct IsArray<T[N]> : std::true_type {};

///////////////////////////////////////

template <class T>
struct RemoveArray {
    using type = T;
};

template <class T>
struct RemoveArray<T[]> {
    using type = T;
};

template <class T, size_t N>
struct RemoveArray<T[N]> {
    using type = T;
};

template <class T>
using RemoveArrayT = RemoveArray<T>::type;

///////////////////////////////////////

int main() {
    assert(1);
    int x;
    assert(x = 2);
    // assert(false);  // error, fail

    static_assert(!kIsArrayV<int>);
    static_assert(kIsArrayV<int[3]>);
    static_assert(kIsArrayV<const int[]>);
    static_assert(kIsArrayV<int[3][4]>);
    static_assert(kIsArrayV<int*[][4][5]>);
    static_assert(!kIsArrayV<int(&)[3]>);

    static_assert(std::is_same_v<RemoveArrayT<int>, int>);
    static_assert(std::is_same_v<RemoveArrayT<int[3]>, int>);
    static_assert(std::is_same_v<RemoveArrayT<const int[]>, const int>);
    static_assert(std::is_same_v<RemoveArrayT<int[3][4]>, int[4]>);
    static_assert(std::is_same_v<RemoveArrayT<int*[][4][5]>, int* [4][5]>);
    static_assert(std::is_same_v<RemoveArrayT<int(&)[3]>, int(&)[3]>);

    return 0;
}
