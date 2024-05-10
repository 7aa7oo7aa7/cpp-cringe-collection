#include <iostream>
// #include <concepts>
#include <type_traits>
#include <algorithm>
#include <vector>

template <class... Args>
struct TypeVector {
    template <class T>
    using PushBack = TypeVector<Args..., T>;
    static constexpr size_t kSize = sizeof...(Args);
};

template <class TV, class T>
struct PushBack {
    using type = typename TV::PushBack<T>;
};

template <class TV>
struct Size {
    static constexpr size_t value = TV::kSize;
};


template <class TV1, class TV2>
struct Concatenate;

template <size_t Left, size_t Right, class Head, class... Tail>
struct Slice {
    // TypeVector<Head, Tail...>
    using type = Slice<Left - 1, Right - 1, Tail...>::type;
};

template <size_t Right, class Head, class... Tail>
struct Slice<0, Right, Head, Tail...> {
    using type = PushFront<Slice<0, Right - 1, Tail...>, Head>::type;
};

template <class Head, class... Tail>
struct Slice<0, 0, Head, Tail...> {
    using type = TypeVector<>;
};

template <class TV, size_t Idx, class T>
struct Insert {
    // Insert<TV, Idx - 1, T>
    using type = Concatenate<Concatenate<
                    Slice<TV, 0, Idx>, 
                    TypeVector<T>>, 
                    Slice<TV, Idx, Size<TV>::value>
                >;
};

int main() {
    TypeVector<int> v1;
    typename PushBack<TypeVector<int>, int>::type v2;
    static_assert(std::is_same_v<decltype(v2), TypeVector<int, int>>);
    static_assert(Size<TypeVector<int, double, double>>::value == 3);
    return 0;
}
