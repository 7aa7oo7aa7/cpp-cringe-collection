#include <iostream>
#include <vector>

struct Point {
    Point(int x, int y, int z) : x(x), y(y), z(z) {}
    int x;
    int y;
    int z;
};

void PushBack(const Point& p) {
    // grow
    arr[size++] = p;
}

template <class... Args>
void EmplaceBack(Args&&... args) {
    // grow
    arr[size++] = Point(std::forward<Args>(args)...);
    new(&arr[size++]) Point(std::forward<Args>(args)...);
}

int main() {
    std::vector<Point> v;
    v.push_back(Point(1, 2, 3));
    v.push_back({1, 2, 3});
    v.emplace_back(1, 2, 3);

    int* x = new int(1);
    // void* v = malloc(sizeof(int));
    // free(v);
    void* v = operator new[](1);


    new(v) int(1);


    operator delete[] v;

    delete x;

    return 0;
}
