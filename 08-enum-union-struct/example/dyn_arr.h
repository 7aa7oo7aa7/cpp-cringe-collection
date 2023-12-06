#ifndef DYN_ARR_H
#define DYN_ARR_H

#include <iostream>

template <class T>
struct DynArray {
    T* arr = nullptr;
    size_t size = 0;
};

// size_t i;

template <class T>
DynArray<T> CreateDynArray(size_t size) {
    DynArray<T> dyn_arr = {
        .arr = new T[size],
        .size = size,
    };
    // DynArray<T> dyn_arr = { new T[size], size };
    // dyn_arr.arr = new T[size];
    // dyn_arr.size = size;
    return dyn_arr;
}

template <class T>
void DestroyDynArray(DynArray<T>& dyn_arr) {
    delete[] dyn_arr.arr;
}

void Print(const DynArray<int>& dyn_arr);

#endif
