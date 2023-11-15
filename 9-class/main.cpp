#include <iostream>

// OOP, classes

class DynArray {
public:
    // constructor
    DynArray()
        : arr_(nullptr)
        , size_(0)
        , capacity_(0) {
    }

    DynArray(size_t size, size_t capacity = 1, int default_value = 0)
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

    // destructor
    ~DynArray() {
        delete[] arr_;
    }

    DynArray(const DynArray& other) {
        // default - copy every field
        size_ = other.size_;
        capacity_ = other.capacity_;
        arr_ = new int[other.capacity_];
        for (size_t i = 0; i < size_; ++i) {
            arr_[i] = other.arr_[i];
        }
    }

    DynArray& operator=(const DynArray& other) {
        delete[] arr_;
        size_ = other.size_;
        capacity_ = other.capacity_;
        arr_ = new int[other.capacity_];
        for (size_t i = 0; i < size_; ++i) {
            arr_[i] = other.arr_[i];
        }
        return *this;
    }

    // rule of three
    // destructor, copy constructor, copy assignment operator

    // DynArray&& - rvalue reference

    DynArray(DynArray&& other) {
        size_ = other.size_;
        capacity_ = other.capacity_;
        arr_ = other.arr_;
        other.arr_ = nullptr;
    }

    DynArray& operator=(DynArray&& other) {
        delete[] arr_;
        size_ = other.size_;
        capacity_ = other.capacity_;
        arr_ = other.arr_;
        other.arr_ = nullptr;
        return *this;
    }

    // since C++11 - rule of five
    // destructor, copy constructor, copy assignment operator
    // move constructor, move assignment operator

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

    void PushBack(int value) {
        if (size_ >= capacity_) {
            Increase(capacity_ * 2);
        }
        arr_[size_] = value;
        ++size_;
    }

private:
    int* arr_ = nullptr;
    size_t size_ = 0;
    size_t capacity_ = 0;

    void Increase(size_t new_capacity);
};

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

// struct - only public fields
// class - public methods, private fields and/or methods

void PrintZeroValue(const DynArray& arr) {
    std::cout << arr.At(0) << std::endl;
}

void PrintOneValue(const DynArray& arr) {
    std::cout << arr[1] << std::endl;
}

int main() {
    DynArray arr(10);
    std::cout << arr.Size() << std::endl;

    arr;  // lvalue
    10;  // rvalue

    arr.At(0) = 100500;
    PrintZeroValue(arr);

    arr[1] = -10;
    PrintOneValue(arr);

    DynArray arr2;

    // DynArray arr2(10);
    // auto arr3 = arr + arr2;

    // int* arr2 = new int[10];
    // delete[] arr2;
    // delete[] arr2;

    DynArray vector(0);
    vector.PushBack(1);
    vector.PushBack(2);
    vector.PushBack(3);
    vector.PushBack(4);
    vector.PushBack(5);
    vector.PushBack(6);
    std::cout << vector.Size() << std::endl;
    for (size_t i = 0; i < vector.Size(); ++i) {
        std::cout << vector[i] << " ";
    }
    std::cout << std::endl;

    DynArray vector1(0);
    vector1.PushBack(1);
    vector1.PushBack(2);
    vector1.PushBack(3);
    DynArray vector2(vector1);
    vector2 = vector1;
    DynArray vector3(DynArray(2));
    vector3 = DynArray(2);

    // arr.Delete();
    return 0;
    // arr destructor
}
