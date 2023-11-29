#include <iostream>
#include <cassert>

template <class T, class U>
struct Struct {
    bool is_t_int = false;
    bool is_u_int = false;
};

template <class T>  // allowed
struct Struct<T, int> {
    bool is_t_int = false;
    bool is_u_int = true;
};

template <class U>  // allowed
struct Struct<int, U> {
    bool is_t_int = true;
    bool is_u_int = false;
};

template <>
struct Struct<int, int> {
    bool is_t_int = true;
    bool is_u_int = true;
};

template <class T, class U>
void Print(const T& value_t, const U& value_u) {
    std::cout << value_t << std::endl;
    std::cout << value_u << std::endl;
}

template <class T>  // not allowed, CE
void Print<T, int>(const T& value_t, const int& value_u) {
    std::cout << value_t << std::endl;
    std::cout << "DOUBLE, INT\n";
    std::cout << value_u << std::endl;
}

template <>
void Print<int, int>(const int& value_t, const int& value_u) {
    std::cout << value_t << std::endl;
    std::cout << "INT\n";
    std::cout << value_u << std::endl;
}

int main() {
    int a = 0;
    int b = 1;
    Print(1.0, 2.0);
    Print(1.0, a);
    Print(a, b);
    // assert(1 == 0);
    assert(1 == 1);
    return 0;
}
