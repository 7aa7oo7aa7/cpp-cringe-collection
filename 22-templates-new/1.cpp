#include <iostream>
#include <algorithm>
#include <vector>

class A {
public:
    A(int x) : x(x) {}
    A(const A& other) : x(other.x) {}
    A(A&& other) : x(std::move(other.x)) {}

    template <class T>  // T = A
    A(T&& value) {
        std::cout << "AAAAA" << std::endl;
    }

private:
    int x;
};

template <class Head>
int CountEven(Head&& head) {
    return (head % 2 == 0) ? 1 : 0;
}

template <class Head, class... Args>
int CountEven(Head&& head, Args&&... args) {
    return CountEven(head) + CountEven(args...);
}

template <class Head>
bool AllEqualToZero(Head&& head) {
    return head == 0;
}

template <class Head, class... Args>
bool AllEqualToZero(Head&& head, Args&&... args) {
    return AllEqualToZero(head) && AllEqualToZero(args...);
}

template <class Head>
bool AllEqual(int value, Head&& head) {
    return value == head;
}

template <class Head, class... Args>
bool AllEqual(int value, Head&& head, Args&&... args) {
    return AllEqual(value, head) && AllEqual(value, args...);
}

template <class Head>
bool AllEqualToEachOther(Head&& head) {
    return true;
}

template <class Head, class... Args>
bool AllEqualToEachOther(Head&& head, Args&&... args) {
    return AllEqual(head, args...);
}

template <class Head>
void PrintReverse(Head&& head) {
    std::cout << head << ' ';
}

template <class Head, class... Args>
void PrintReverse(Head&& head, Args&&... args) {
    PrintReverse(args...);
    PrintReverse(head);
}

int main() {

    std::vector<int> arr({1, 2, 3, 4, 5, 6, 7, 8, 9, 10});

    bool has_even = std::any_of(
        arr.begin(),
        arr.end(),
        [](int value) { return value % 2 == 0; }
    );
    bool all_even = std::all_of(
        arr.begin(),
        arr.end(),
        [](int value) { return value % 2 == 0; }
    );
    bool all_small = std::all_of(
        arr.begin(),
        arr.end(),
        [](int value) { return value <= 10; }
    );

    std::cout << has_even << all_even << all_small << std::endl;

    std::cout << CountEven(1, 2, 3, 4, 5, 6, 7) << std::endl;

    std::cout << AllEqualToZero(0, 1, 2, 3, 4, 5, 6, 7, 0) << std::endl;
    std::cout << AllEqualToZero(0, 0, 0, 0) << std::endl;

    std::cout << AllEqualToEachOther(0, 1, 2, 3, 4, 5, 6, 7, 0) << std::endl;
    std::cout << AllEqualToEachOther(4, 4, 4, 4) << std::endl;

    PrintReverse(1, 2, 3, 4, 5, 6, 7);
    std::cout << std::endl;

    A a1(1);
    A a2(a1);

    return 0;
}
