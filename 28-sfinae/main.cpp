#include <iostream>
#include <type_traits>

// SFINAE
// substitution failure is not an error

template <class T>
T&& Declval();

// decltype(Declval<int>());

struct A {
    using type = int;
    type a = 1;
};

void f(...) {
    std::cout << 1 << std::endl;
}

template <class T>
typename T::type f(T value) {
    std::cout << 2 << std::endl;
    return value.a;
}

// enable_if

template <class T, bool Predicate>
struct EnableIf {};

template <class T>
struct EnableIf<T, true> {
    using type = T;
};

template <class T, class = typename EnableIf<T, std::is_same_v<T, int>>::type>
void g() {
}

// int
// template <class T, class = T>
// void g() {
// }

// double - function doesn't exist
// template <class T, class = typename EnableIf<T, false>::type>  // type doesn't exist
// void g() {
// }

template <class T, class... Args>
class IsConstructible {
private:
    template <class T1, class... Args1>
    static constexpr bool f(...) {
        return false;
    }

    template <class T1, class... Args1>
    static constexpr decltype(T1(std::declval<Args1>()...), bool()) f(int) {
        return true;
    }

public:
    // true = constructor T(Args...) exists
    static constexpr bool value = f<T, Args...>(1);
};

int main() {

    f(1);
    f(A());

    // g<int>();
    // g<double>();

    auto x = (f(1), f(A()), false);

    std::cout << (IsConstructible<int>::value ? "true" : "false") << std::endl;
    std::cout << (IsConstructible<A, int, double>::value ? "true" : "false") << std::endl;
    std::cout << (IsConstructible<A>::value ? "true" : "false") << std::endl;

    return 0;
}
