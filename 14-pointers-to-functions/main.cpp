#include <iostream>
#include <algorithm>

// git config --global user.name USERNAME
// git config --global user.email EMAIL

// pointers to functions

bool CompareLess(const int& left, const int& right) {
    return left < right;
}

bool CompareGreater(const int& lhs, const int& rhs) {
    // left/right hand side/site
    return lhs > rhs;
}

// bool compare(const int&, const int&);
// bool (*compare)(const int&, const int&);

void Sort(int* arr, size_t size, bool (*compare)(const int&, const int&) = CompareLess) {
    for (size_t i = 0; i < size; ++i) {
        for (size_t j = i + 1; j < size; ++j) {
            if (compare(arr[j], arr[i])) {
                std::swap(arr[i], arr[j]);
            }
        }   
    }
}

struct ComparatorLess {
    bool operator()(const int& lhs, const int& rhs) {
        return lhs < rhs;
    }
};

template <class Comparator>
void Sort(int* arr, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        for (size_t j = i + 1; j < size; ++j) {
            if (Comparator()(arr[j], arr[i])) {
                std::swap(arr[i], arr[j]);
            }
        }   
    }
}

struct Struct {
    int a;
    bool operator<(const Struct& other) {
        return a < other.a;
    }
};

void Sort(Struct* arr, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        for (size_t j = i + 1; j < size; ++j) {
            if (arr[j] < arr[i]) {
                std::swap(arr[i], arr[j]);
            }
        }   
    }
}

int main() {
    int* arr = new int[10]{4, 6, 1, 5, 9, 0, 3, 2, 8, 7};
    Sort(arr, 10, CompareLess);
    Sort(arr, 10, CompareGreater);
    Sort(arr, 10);
    for (size_t i = 0; i < 10; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    delete[] arr;
    return 0;
}
