#include <iostream>
#include <stdexcept>

struct Point {
    Point(int x, int y, int z) : x(x), y(y), z(z) {}
    int x;
    int y;
    int z;

    Point(const Point& other) = delete;
    Point(Point&& other) {
        if (other.x == 0) {
            throw std::runtime_error("");
        }
        x = other.x;
        y = other.y;
        z = other.z;
    }
};

template <class T>
bool Reserve(size_t new_capacity) noexcept {
    T* new_arr = new T[new_capacity];
    size_t i = 0;
    try {
        for (; i < std::min(size, new_capacity); ++i) {
            new_arr[i] = std::move(arr[i]);  // move throws exception
        }
    } catch (...) {
        for (; i >= 0; --i) {
            arr[i] = std::move(new_arr[i]);
        }
        delete[] new_arr;
        return false;
    }
    delete[] arr;
    arr = new_arr;
    capacity = new_capacity;
    return true;
}

template <class T>
void PushBack(const T& value) {
    if (size == capacity) {
        if (Reserve(capacity * 2)) {
            // success
        } else {
            // fail
            throw std::runtime_error("");
        }
    }
}

void Insert(const Point& p, size_t index) {
    try {
        if (size == capacity) {
            Reserve(capacity * 2);
        }
    } catch (std::bad_alloc& e) {
        // delete[] arr;
        throw;
    }
    try {
        for (size_t i = size - 1; i >= index; --i) {
            arr[i + 1] = arr[i];
        }
        arr[index] = p;
    } catch (...) {

        delete[] arr;
        throw;
    }
    ++size;
}

template <class... Args>
void EmplaceBack(Args&&... args) {
    // grow

    arr[size++] = Point(std::forward<Args>(args)...);
    new(&arr[size++]) Point(std::forward<Args>(args)...);
}

int main() {
    return 0;
}
