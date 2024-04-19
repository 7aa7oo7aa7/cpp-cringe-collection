#include <iostream>
#include <cstdint>

template <size_t N>
struct Sqrt {
    static constexpr size_t value = BinarySearch<N, 1, N>;
};

template <size_t N, size_t Left, size_t Right>
struct BinarySearch {
    static constexpr size_t value = 
        ((Left + Right) / 2) * ((Left + Right) / 2) < N
    ;
};

template <size_t N, size_t Left>
struct BinarySearch<N, Left, Left> {
    static constexpr size_t value = ;
};

