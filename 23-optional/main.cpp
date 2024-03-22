#include <iostream>
#include <optional>

// Optional

template <class T>
class Optional {
public:
    Optional() : memory(operator new(sizeof(T))) {}
    ~Optional() {
        if (has_value) {
            static_cast<T*>(memory)->~T();
        }
        operator delete(memory);
    }

    // Optional& operator=(const T& new_value) {
    //     delete value;
    //     value = new T(new_value);
    // }

    Optional& operator=(const T& new_value) {
        if (has_value) {
            static_cast<T*>(memory)->~T();
        }
        new(memory) T(new_value);
    }

private:
    // T value;
    // T* value;
    void* memory;
    bool has_value;
};

void PrintValueOrDefault(std::optional<int> x = std::nullopt) {
    if (x.has_value()) {
    // if (x) {
        std::cout << *x;
    } else {
        std::cout << 1;
    }
    std::cout << std::endl;
}

struct Vector {
    ~Vector();
    size_t size() const;
    size_t capacity() const;
};

struct String {
    ~String();
    size_t size() const;
    size_t capacity() const;
};

int main() {
    std::optional<int> x;
    x = 2;
    // *x -> int
    // .has_value() -> bool
    // operator bool() <=> has_value
    x = std::nullopt;
    int y;

    PrintValueOrDefault(101);
    PrintValueOrDefault(x);
    PrintValueOrDefault(y);
    PrintValueOrDefault();

    std::cout << x.has_value() << bool(x) << std::endl;

    return 0;
}