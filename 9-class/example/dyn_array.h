#ifndef DYNARRAY
#define DYNARRAY

#include <iostream>

class DynArray {
public:
    // constructor
    DynArray()
        : arr_(nullptr)
        , size_(0)
        , capacity_(0) {
    }

    DynArray(size_t size, size_t capacity, int default_value);

    // destructor
    ~DynArray();

    size_t Size() const {
        return size_;
    }

    int& At(size_t i) {
        return arr_[i];
    }

    int At(size_t i) const {
        return arr_[i];
    }

    // operator overloading
    int& operator[](size_t i) {
        return arr_[i];
    }

    int operator[](size_t i) const {
        return arr_[i];
    }

    // DynArray operator+(const DynArray& other) {
        //
    // }

    void PushBack(int value);

private:
    int* arr_ = nullptr;
    size_t size_ = 0;
    size_t capacity_ = 0;

    void Increase(size_t new_capacity);
};

#endif
