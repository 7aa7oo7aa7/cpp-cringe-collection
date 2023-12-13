#include <iostream>
#include <functional>

// functors, lambda functions

// int (*f)(int, int);

struct ComparatorLess {
    bool operator()(const int& lhs, const int& rhs) {
        return lhs < rhs;
    }
};

// std::function<int(int, int)> f = [](int a, int){ return a; };
auto f = [](int a, int){ return a; };

// void Sort(int* arr, size_t size, std::function<int(int, int)> comp) {
//     //
// }

void Sort(int* arr, size_t size, auto comp = [](int l, int r) { return l < r; }) {
    std::sort(arr, arr + size, comp);
    std::sort(arr, arr + size, ComparatorLess());
}

class MatrixIsDegenerateError {
};

class Class {
public:

    ~Class() {
        delete[] arr;
    }

    // trivial destructor
    // call destructor for all fields

    int* arr;
private:

    // CE
    // ~Class() {
    //     delete[] arr;
    // }
};

template <class T, size_t N>
class Array;

template <class T, size_t Rows, size_t Columns>
class Matrix {
public:
    using Arr = Array<Array<T, Rows>, Columns>;
    Arr arr;

    Matrix<T, Rows, Columns> operator+(const Matrix<T, Rows, Columns>& other);

    template <size_t ResultColumns>
    Matrix<T, Rows, ResultColumns> operator*(
        const Matrix<T, Columns, ResultColumns>& other
    );
};

template <class T, size_t Rows>
class Matrix<T, Rows, Rows> {
    //
};

Matrix<int, 1, 2>::Arr arr;
Matrix<int, 1, 2> matrix1{{{1, 2}, {2, 3}}};
Matrix<int, 1, 2> matrix2{
    .arr = {{1, 2}, {2, 3}}
};

int main() {
    ComparatorLess comp;
    comp(1, 2);
    int* arr = new int[10];
    int a = 1000;
    Sort(arr, 10, [](int l, int r) { return l > r; });

    auto g = [b = a]() -> int {
        // b = 99999;
        std::cout << b << std::endl;
        // std::cout << a << std::endl;
        return 0;
    };

    auto compare_with_int = [](int lhs, int rhs) -> bool {
        if (lhs < rhs) {
            return true;
        }
        return 0;
    };

    1;

    g();

    std::cout << a << std::endl;

    Class c{{1, 2}, {2, 3}};

    delete[] arr;
    throw MatrixIsDegenerateError();

    // try {
    //     int x = 0;
    //     throw MatrixIsDegenerateError();
    // } catch (MatrixIsDegenerateError err) {
    //     std::cout << 111 << std::endl;
    // }

    delete[] arr;
    return 0;
    // c.~Class();
}
