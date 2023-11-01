#include "dyn_array.h"

DynArray::DynArray()
    : arr_(nullptr)
    , size_(0)
    , capacity_(0) {
}

DynArray::DynArray(size_t size, size_t capacity, int default_value)
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

size_t DynArray::Size() const {
    return size_;
}

int& DynArray::At(size_t i) {
    return arr_[i];
}

int DynArray::At(size_t i) const {
    return arr_[i];
}

int& DynArray::operator[](size_t i) {
    return arr_[i];
}

int DynArray::operator[](size_t i) const {
    return arr_[i];
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
