#include <iostream>
#include <cstring>
#include <vector>
#include <utility>  // move
#include <memory>  // unique_ptr, shared_ptr

// std::string
// move
// smart pointers

void Swap(std::vector<int>& lhs, std::vector<int>& rhs) {
    std::vector<int> tmp = std::move(lhs);
    lhs = std::move(rhs);
    rhs = std::move(tmp);
}

// rvalue reference

template <class T>
T&& Move(T& object) {
    return static_cast<std::remove_reference_t<T>&&>(object);
}

// rvalue reference variable is lvalue
// int&& rvalue_ref_int_1 = 0;
// int&& rvalue_ref_int_2 = rvalue_ref_int_1;

class A {
public:
    A(A&& other) {
        // std::swap(*this, other);
    }
};

// reference collapsing

// A + && = A&&
// A& + && = A&
// A&& + & = A&
// A&& + && = A&&

// A a;
// A& a_ref = a;
// auto a_rvalue_ref = static_cast<A&&>(a);

class String {
public:
    String(size_t size = 8)
        : length(0)
        , capacity(size ? size : 8)
        , str(new char[capacity])
    {}

    String(const char* cstr)
        : length(strlen(cstr))
        , capacity(length + 1)
        , str(new char[length + 1])
    {
        for (size_t i = 0; i < length; ++i) {
            str[i] = cstr[i];
        }
    }

    size_t Length() const {
        return length;
    }

    char& operator[](const size_t idx) {
        return str[idx];
    }

    const char& operator[](const size_t idx) const {
        return str[idx];
    }

    ~String() {
        if (str) {
            delete[] str;
        }
    }

    String(const String& other)
        : length(other.length)
        , capacity(other.capacity)
        , str(new char[capacity])
    {
        for (size_t i = 0; i < length; ++i) {
            str[i] = other.str[i];
        }
    }

    String& operator=(const String& other) {
        if (str == other.str) {
            return *this;
        }
        length = other.length;
        capacity = other.capacity;
        delete[] str;
        str = new char[capacity];
        for (size_t i = 0; i < length; ++i) {
            str[i] = other.str[i];
        }
        return *this;
    }

    // C++11: rule of three -> rule of five

    String(String&& other)
        : length(std::move(other.length))
        , capacity(std::move(other.capacity))
        , str(other.str)
    {
        other.str = nullptr;
    }

    String& operator=(String&& other) {
        if (str == other.str) {
            return *this;
        }
        length = std::move(other.length);
        capacity = std::move(other.capacity);
        str = other.str;
        other.str = nullptr;
        return *this;
    }

private:
    size_t length;
    size_t capacity;
    char* str;

    void Grow() {
        char* new_str = new char[capacity * 2];
        for (size_t i = 0; i < length; ++i) {
            new_str[i] = str[i];
        }
        delete[] str;
        str = new_str;
        capacity *= 2;
    }
};

// smart pointers

// C++03: std::auto_ptr

class Pointer {
public:
    Pointer() : ptr(new int) {}

    ~Pointer() {
        delete ptr;
    }

    Pointer(const Pointer& copy) {
        ptr = new int(*(copy.ptr));
        // ptr = copy.ptr;
    }

    Pointer& operator=(const Pointer& copy) {
        delete ptr;
        ptr = new int(*(copy.ptr));
        return *this;
    }

    Pointer(Pointer&& copy) {
        if (copy.ptr != ptr) {
            ptr = copy.ptr;
            copy.ptr = nullptr;
        }
    }

    Pointer& operator=(Pointer&& copy) {
        if (copy.ptr != ptr) {
            ptr = copy.ptr;
            copy.ptr = nullptr;
        }
        return *this;
    }

    int& operator*() {
        return *ptr;
    }

    int* operator->() {
        return ptr;
    }

private:
    int* ptr;
};

// (*ptr).field;
// ptr->field;

// C++11: auto_ptr -> deprecated, std::unique_ptr, std::shared_ptr, std::weak_ptr

template <class T>
class UniquePtr {
public:
    UniquePtr(T* value) : value(value) {}

    ~UniquePtr() {
        delete value;
    }

    UniquePtr(const UniquePtr<T>& other) = delete;
    UniquePtr& operator=(const UniquePtr<T>& other) = delete;

    UniquePtr(UniquePtr<T>&& other) {
        value = other.value;
        other.value = nullptr;
    }

    UniquePtr& operator=(UniquePtr<T>&& other) {
        if (value != other.value) {
            value = other.value;
            other.value = nullptr;
        }
        return *this;
    }

    T& operator*() {
        return *value;
    }

    T* Get() {
        return value;
    }

private:
    T* value;
};

template <class T>
class SharedPtr {
public:
    SharedPtr(T* value) : value(value), counter(new int(1)) {}

    SharedPtr(const SharedPtr<T>& other)
        : value(other.value)
        , counter(other.counter)
    {
        ++(*counter);
    }

    ~SharedPtr() {
        --(*counter);
        if (*counter == 0) {
            delete value;
        } else {
            // nothing
        }
    }

    T& operator*() {
        return *value;
    }

    T* Get() {
        return value;
    }

private:
    T* value;
    size_t* counter;
};

int main() {
    String s;
    s = s;
    UniquePtr<int> uni_ptr(new int(10));
    std::cout << *uni_ptr << std::endl;
    *uni_ptr = 20;
    std::cout << *uni_ptr << std::endl;
    // UniquePtr<int> uni_ptr_2(uni_ptr);  // BAD, can't create a copy
    UniquePtr<int> uni_ptr_2(std::move(uni_ptr));  // moves
    UniquePtr<int> uni_ptr_3(uni_ptr.Get());  // BAD, no longer unique

    SharedPtr<int> shared_ptr(new int(10));
    SharedPtr<int> shared_ptr_2(shared_ptr);  // copies and increments counter
    SharedPtr<int> shared_ptr_3(std::move(shared_ptr));  // moves and doesn't increment counter
    SharedPtr<int> shared_ptr_4(shared_ptr.Get());  // BAD, creates new counter

    return 0;
}
