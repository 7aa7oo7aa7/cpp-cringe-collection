#include "dyn_array.h"

DynArray::DynArray(size_t size, size_t capacity = 1, int default_value = 0)
    : arr_(new int[capacity])
    , size_(size)
    , capacity_(size > capacity ? size : capacity) {
    // initialization list
    // arr_ = new int[size];
    // std::cout << size_;
    // size_ = size;
    for (size_t i = 0; i < capacity; ++i) {
        arr_[i] = default_value;
    }
}

DynArray::~DynArray() {
    delete[] arr_;
}

void DynArray::Increase(size_t new_capacity) {
    int* new_arr = new int[new_capacity];  // new_capacity > capacity_
    for (size_t i = 0; i < capacity_; ++i) {
        new_arr[i] = arr_[i];
    }
    for (size_t i = capacity_; i < new_capacity; ++i) {
        new_arr[i] = 0;
    }
    delete[] arr_;
    arr_ = new_arr;
    capacity_ = new_capacity;
}

void DynArray::PushBack(int value) {
    if (size_ >= capacity_) {
        Increase(capacity_ * 2);
    }
    arr_[size_] = value;
    ++size_;
}
