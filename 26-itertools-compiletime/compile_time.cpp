#include <iostream>
#include <cstdint>

template <int64_t value>
struct Square {
    static const uint64_t Value = value * value;
};

template <uint64_t value, uint64_t pow>
struct Pow {
    // O(pow) -> bad
    // static const uint64_t Value = value * Pow<value, pow - 1>::Value;

    // O(log(pow)) -> better
    static const uint64_t Value = 
        (pow % 2 == 0)
        ? 
        (Pow<value, pow / 2>::Value * Pow<value, pow / 2>::Value)
        :
        (value * Pow<value, pow - 1>::Value)
    ;
};

template <uint64_t value>
struct Pow<value, 0> {
    static const uint64_t Value = 1;
};

template <uint64_t value>
struct Pow<value, 1> {
    static const uint64_t Value = value;
};

constexpr uint64_t PowFunc(const uint64_t value, const uint64_t pow) {
    if (pow == 0) {
        return 1;
    } else if (pow == 1) {
        return value;
    } else if (pow % 2 == 1) {
        return value * PowFunc(value, pow - 1);
    } else {
        auto pow_div_2 = PowFunc(value, pow / 2);
        return pow_div_2 * pow_div_2;
    }
}

int main() {

    std::cout << Square<400>::Value << std::endl;
    std::cout << Pow<2, 62>::Value << std::endl;

    constexpr uint64_t x = 0;
    constexpr uint64_t y = PowFunc(2, 62);

    uint64_t z = 0;
    std::cin >> z;
    uint64_t v = PowFunc(z, 2);

    return 0;
}
