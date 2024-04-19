#include <iostream>
#include <cstdint>

template <size_t N, size_t Left, size_t Right>
struct HasDivisors {
    static constexpr bool value =
        HasDivisors<N, Left, (Left + Right) / 2>
        &&
        HasDivisors<N, (Left + Right) / 2, Right>;
};

template <size_t N, size_t Left>
struct HasDivisors<N, Left, Left> {
    static constexpr bool value = ;
};

