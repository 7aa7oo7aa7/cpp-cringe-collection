#include <iostream>
#include <vector>
#include <cstring>

class Iterator {
public:
    // 0, 1, 2, ..., 10

    Iterator(int counter, int end_value)
        : counter(counter) 
        , end_value(end_value)
    {}

    void operator++() {
        ++counter;
    }

    bool ReachedEnd() const {
        return counter >= end_value;
    }

    bool operator==(const Iterator& other) const {
        return counter == other.counter && end_value == other.end_value;
    }

    bool operator!=(const Iterator& other) const {
        return !(*this == other);
    }

    int operator*() const {
        return counter;
    }

private:
    int counter = 0;
    const int end_value = 10;
};

class Range {
public:
    Range() {}  // TODO: add arguments

    Iterator begin() {
        return Iterator(0, 10);
    }

    Iterator end() {
        return Iterator(10, 10);
    }

    // Reversed task
    Iterator rbegin() {}
    Iterator rend() {}

private:
    // TODO: range bounds, step
};

int main() {

    std::vector<char> arr(10, 'A');

    for (const auto& i : arr) {
        //
    }

    for (const auto& i : std::vector<bool>(20, true)) {
        // vector is created only once
    }

    for (int i = 0; i < strlen("aaa"); ++i) {
        // O(n) each iteration
    }

    // for (const auto& i : ???) {
        // ??? - begin(), end(), iterator class, ++, !=, ==
    // }

    for (auto i = Range().begin(); i != Range().end(); ++i) {
        //
    }

    for (auto i = Range().rbegin(); i != Range().rend(); ++i) {
        //
    }

    for (auto i : Range()) {
        std::cout << i << " ";
    }

    for (auto&& [i, x] : Enumerate(l)) {
        // Enumerate -> std::pair<size_t, T> -> i, x variables
    }

    return 0;
}
