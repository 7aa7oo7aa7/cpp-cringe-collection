#include "dyn_arr.h"

void Print(const DynArray<int>& dyn_arr) {
    for (size_t i = 0; i < dyn_arr.size; ++i) {
        std::cout << dyn_arr.arr[i] << std::endl;
    }
}
