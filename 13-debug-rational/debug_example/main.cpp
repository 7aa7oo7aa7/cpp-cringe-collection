#include <iostream>
#include <vector>

struct Struct {
public:
    int v1 = 0;
    int v2 = 0;
private:
    int v3 = 0;
};

int f(int a, int& b) {
    int arr[10];
    for (size_t i = 0; i < 10; ++i) {
        arr[i] = i;
    }
    b = arr[9];
    return a + b;
}

void g(int x) {
    if (x == 1) {
        return;
    }
    Struct s;
    s.v1 = 1;
    s.v2 = 2;
    int* y = new int(10);
    int* arr = new int[10];
    std::vector<int> vector(10, 222);
    g(x - 1);
    delete y;
    delete[] arr;
}

// sudo apt-get install gdb

int main() {
    int a = 0;
    int b = 0;
    // std::cin >> a >> b;
    int c = f(a, b);
    std::cout << a << ' ' << b << ' ' << c << std::endl;
    g(3);
    return 0;
}
