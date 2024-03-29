#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <vector>

#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <deque>

template <class T, class Container = std::deque<T>>
class Stack;

template <class T>
class Vector {
public:
    using ValueType = T;
    using Pointer = T*;
    using SizeType = size_t;
    SizeType size() {}

    class Iterator {
        // ++, --, *
    private:
        Pointer pointer;
    };

    Iterator begin() {}
    Iterator end() {}
};

std::map<int, std::string> map;
// std::map<int, std::string, std::less<int>> map;
// std::map<int, std::string, std::greater<int>> map;
std::set<int> set;

std::unordered_map<int, std::string> unordered_map;
// std::unordered_map<int, std::string, std::hash<int>> unordered_map;
std::unordered_set<int> unordered_set;

void f() {
    map[1] = "a";
    map[2];
    map.at(1);
    map.insert({3, "b"});
    map.emplace(4, "c");
    map.erase(4);
    auto iter4 = map.find(4);
    if (auto it = map.find(3); it != map.end()) {
        // found 3
    }
    // C++20
    if (map.contains(3)) {
        // found 3
    }
}

class A {

auto f() const noexcept -> void try {
    throw 1;
} catch(...) {
    //
}

};

int main() {

    int x = 0;

    try {
        throw 1;
    } catch(const std::runtime_error& e) {
        x = 1;
        std::cout << "runtime error\n";
        std::cout << e.what() << std::endl;
    } catch(const std::exception& e) {
        x = 2;
        std::cout << "exception\n";
        std::cout << e.what() << std::endl;
    } catch(...) {
        std::cout << "unknown exception\n";
    }

    std::vector<int> arr;
    std::sort(arr.begin(), arr.end());
    std::sort(
        arr.begin(),
        arr.end(),
        [](const int& lhs, const int& rhs) -> bool {
            return lhs < rhs;
        }
    );

    return 0;
}
