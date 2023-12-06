#ifndef DYNARRAY
#define DYNARRAY

#include <iostream>

class DynArray {
public:
    // constructor
    DynArray();
    DynArray(size_t size, size_t capacity = 1, int default_value = 0);

    // destructor
    ~DynArray();

    size_t Size() const;

    // operator overloading
    int& At(size_t i);
    int At(size_t i) const;
    int& operator[](size_t i);
    int operator[](size_t i) const;

    void PushBack(int value);

private:
    int* arr_ = nullptr;
    size_t size_ = 0;
    size_t capacity_ = 0;

    void Increase(size_t new_capacity);
};

#endif
