#include "sum.h"
#include <iostream>

int main() {
    std::cout << Sum<int>(1, 2) << std::endl;
    std::cout << Sum<double>(1.5, 2.75) << std::endl;
    return 0;
}
