#include <iostream>  // search include path
#include "sum.h"  // search directory + include path

// ODR - One Defition Rule
// int Sum(int a, int b) {
//     return a - b;
// }

int Diff(int a, int b) {
    return a - b;
}

int main() {
    std::cout << Sum(1, 2) << std::endl;
    return 0;
}
