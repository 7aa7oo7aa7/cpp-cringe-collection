#include <iostream>

template <class T>
void Swap(T& a, T& b) {
    auto t = a;
    // auto x;
    a = b;
    b = t;
}

template <class T>
bool BinarySearch(const T* begin, const T* end, const T& value);

template <class T>
void Sort(T* begin, T* end);

std::distance(begin, end);  // вычисление расстояния между begin и end за O(N)

template <class T>
void Fill(T* begin, T* end, const T& value) {
    for (T* i = begin; i < end; ++i) {
        *i = value;
    }
    *end;  // end - первый элемент после конца массива
}

// 1 2 4 7 10 3 --> Fill(begin, end, 2) --> 2 2 2 2 2 2

template <int N, int M>
int Sum() {
    return N + M;
}

template <uint64_t N>
uint64_t Fact() {
    if constexpr (N == 0) {
        return 1;
    } else {
        return N * Fact<N - 1>();
    }
}

// template <>
// uint64_t Fact<0>() {
//     return 1;
// }

int main() {
    int* arr = new int[6];

    Fill(arr, arr + 6, 2);  // заполняет весь массив элементами 2
    Fill(arr + 1, arr + 4, 3);

    for (size_t i = 0; i < 6; ++i) {
        std::cout << arr[i] << std::endl;
    }

    delete[] arr;

    int a = 0;
    int b = 1;
    int& ref = a;
    int* ptr = &a;
    // Swap(a, b);

    std::cout << Sum<10, 25>() << std::endl;

    std::cout << Fact<10>() << std::endl;

    return 0;
}
