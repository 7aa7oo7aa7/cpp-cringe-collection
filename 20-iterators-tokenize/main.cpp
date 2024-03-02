#include <iostream>
#include <iterator>
#include <string_view>
#include <vector>

std::vector<int> v(100000);  // size = 100000, filled with 0, O(1)
std::vector<int> v(100000, 10);  // size = 100000, filled with 10, O(1)

struct Tokens;  // = std::vector<std::variant<token, token, ...>>

std::vector<int> f() {  // O(n)
    std::vector<int> v;
    for (int i = 0; i < 100000; ++i) {
        v.push_back(0);
    }
    return v;
}

Tokens Tokenize(std::string_view str) {
    for (size_t i = 0; i < str.size(); ++i) {
        str[i];
    }
    // for c in str
    for (auto it = str.begin(); it < str.end(); ++it) {
        *it;
    }
    // C++11: range-based for
    for (const auto& c : str) {
        c;
    }
    for (const auto& x : f() /* executes once */) {
        x;
    }
    // for i in ['a', 'b', 'c']
    for (const auto& i : std::vector<char>{'a', 'b', 'c'}) {
        i;
    }

    std::string_view::iterator it = str.begin();
    *it;
    /*
        iterator: input_iterator, output_iterator
        input_iterator: forward, bidirectional, random_access
        forward: ++, ==, !=
        bidirectional: ++, --, ==, !=
        random_access: ++, --, +, -, +=, -=, ==, !=, <=, >=, <, >
        begin: first element
        end: after last element
    */
    std::vector<int> v;
    for (std::vector<int>::iterator it = v.begin(); it < v.end(); ++it) {
        *it;
        *it = 1;
    }
    for (std::vector<int>::const_iterator it = v.cbegin(); it < v.cend(); ++it) {
        *it;
        *it = 1;  // const
    }
    for (std::vector<int>::reverse_iterator it = v.rbegin(); it < v.rend(); ++it) {
        *it;
        *it = 1;
    }
    for (std::vector<int>::const_reverse_iterator it = v.crbegin(); it < v.crend(); ++it) {
        *it;
        *it = 1;  // const
    }
}

int main() {
    return 0;
}
