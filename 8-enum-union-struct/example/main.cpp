#include <iostream>
#include "dyn_arr.h"

int main() {
    auto dyn_arr = CreateDynArray<int>(1024);
    Print(dyn_arr);
    DestroyDynArray(dyn_arr);
    return 0;
}
