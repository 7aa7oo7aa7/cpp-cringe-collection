#include <iostream>

// OOP, classes

template <class T>
class DynArray {
public:
    // constructor
    DynArray()
        : arr_(nullptr)
        , size_(0)
        , capacity_(0) {
    }

    DynArray(size_t size, size_t capacity = 1, T default_value = 0)
        : arr_(new T[capacity])
        , size_(size)
        , capacity_(size > capacity ? size : capacity) {
        // initialization list
        // arr_ = new T[size];
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

    DynArray(const DynArray<T>& other) {
        // default - copy every field
        size_ = other.size_;
        capacity_ = other.capacity_;
        arr_ = new T[other.capacity_];
        for (size_t i = 0; i < size_; ++i) {
            arr_[i] = other.arr_[i];
        }
    }

    DynArray<T>& operator=(const DynArray<T>& other) {
        delete[] arr_;
        size_ = other.size_;
        capacity_ = other.capacity_;
        arr_ = new T[other.capacity_];
        for (size_t i = 0; i < size_; ++i) {
            arr_[i] = other.arr_[i];
        }
        return *this;
    }

    // rule of three
    // destructor, copy constructor, copy assignment operator

    // DynArray&& - rvalue reference

    DynArray(DynArray<T>&& other) {
        size_ = other.size_;
        capacity_ = other.capacity_;
        arr_ = other.arr_;
        other.arr_ = nullptr;
    }

    DynArray<T>& operator=(DynArray<T>&& other) {
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

    T& At(size_t i) {
        return arr_[i];
    }

    T At(size_t i) const {
        return arr_[i];
    }

    // operator overloading
    T& operator[](size_t i) {
        return arr_[i];
    }

    T operator[](size_t i) const {
        return arr_[i];
    }

    // DynArray operator+(const DynArray& other) {
        //
    // }

    void PushBack(T value) {
        if (size_ >= capacity_) {
            Increase(capacity_ * 2);
        }
        arr_[size_] = value;
        ++size_;
    }

private:
    T* arr_ = nullptr;
    size_t size_ = 0;
    size_t capacity_ = 0;

    void Increase(size_t new_capacity);
};

template <class T>
void DynArray<T>::Increase(size_t new_capacity) {
    T* new_arr = new T[new_capacity];  // new_capacity > capacity_
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

template <>
class DynArray<bool> {
public:
    DynArray() : arr_(new uint8_t[8]), size_(0), capacity_(8) {
    }

    ~DynArray() {
        delete[] arr_;
    }

    void PushBack(bool value) {
        SetBit(size_++, value);
    }

    bool operator[](const size_t i) const {
        return GetBit(i);
    } 

private:
    uint8_t* arr_;
    size_t size_;
    size_t capacity_;

    bool GetBit(const size_t i) const {
        size_t arr_idx = i / 8;
        uint8_t ith_arr_element = arr_[arr_idx];
        size_t bit_idx = i % 8;
        uint8_t bit = ((ith_arr_element >> bit_idx) & 1);
        return bit == 1;
    }

    void SetBit(const size_t i, bool value) {
        size_t arr_idx = i / 8;
        uint8_t& ith_arr_element = arr_[arr_idx];
        size_t bit_idx = i % 8;
        if (value) {
            ith_arr_element |= (1 << bit_idx);
        } else {
            ith_arr_element &= ~(1 << bit_idx);
        }
    }
};

void PrintZeroValue(const DynArray<int>& arr) {
    std::cout << arr.At(0) << std::endl;
}

void PrintOneValue(const DynArray<int>& arr) {
    std::cout << arr[1] << std::endl;
}

int main() {
    DynArray<int> arr(10);
    std::cout << arr.Size() << std::endl;

    arr;  // lvalue
    10;  // rvalue

    arr.At(0) = 100500;
    PrintZeroValue(arr);

    arr[1] = -10;
    PrintOneValue(arr);

    DynArray<int> arr2;

    // DynArray<int> arr2(10);
    // auto arr3 = arr + arr2;

    // int* arr2 = new int[10];
    // delete[] arr2;
    // delete[] arr2;

    DynArray<int> vector(0);
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

    DynArray<int> vector1(0);
    vector1.PushBack(1);
    vector1.PushBack(2);
    vector1.PushBack(3);
    DynArray<int> vector2(vector1);
    vector2 = vector1;
    DynArray<int> vector3(DynArray<int>(2));
    vector3 = DynArray<int>(2);

    DynArray<bool> array_bool;
    array_bool.PushBack(true);
    array_bool.PushBack(false);
    for (size_t i = 0; i < 2; ++i) {
        std::cout << array_bool[i] << std::endl;
    }

    // arr.Delete();
    return 0;
    // arr destructor
}
