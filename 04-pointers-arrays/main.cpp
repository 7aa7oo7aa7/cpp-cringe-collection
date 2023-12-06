#include <iostream>

int main() {

    // pointers, arrays

    int a = 0;
    int* x = &a;
    x;
    // int*
    std::cout << x << std::endl;

    *x = 10;
    std::cout << a << std::endl;

    int* y = x + 1;  // 0x7ffff709c354 + 1 * sizeof(int)
    // 0x7ffff709c354 + 4 = 0x7ffff709c358
    // *y = 100500;  // undefined behaviour
    std::cout << y << std::endl;

    int* z = &a;
    {
        int b = -259;
        z = &b;
    }
    // b doesn't exist
    // z = &b
    // висячий указатель, dangling pointer

    // UB
    std::cout << *z << std::endl;

    int b = 0;
    z = &b;
    *z = 100501;
    std::cout << a << " " << b << std::endl;

    // new, delete
    // int* c = new int;
    // int* c = new int(0);
    int* c = new int{0};
    // выделяем sizeof(int) на куче

    *c = 11;
    std::cout << *c << std::endl;

    // std::cin >> *c;
    // if (*c == 0) {
    //     delete c;
    //     return 1;
    // }

    char* h = reinterpret_cast<char*>(c);
    *h = 'a';
    std::cout << *c << std::endl;

    delete c;
    // память из c очищается
    *c;  // UB

    // arrays

    int arr[10];  // n известно на этапе компиляции

    int n = 10;
    int arr1[n];

    // std::cin >> n;
    int arr2[n];

    // на стеке выделилось int * 10

    arr[0] = 1;
    arr[9] = 2;

    int arr3[3]{1, 3, 2};
    // int arr3[3] = {1, 3, 2};

    std::cout << arr3[0] << " " << arr3[1] << " " << arr3[2] << " " << std::endl;
    for (int i = 0; i < 3; ++i) {
        //
    }

    std::cout << arr3 << std::endl;

    std::cout << sizeof(arr3) << std::endl;  // 12 = sizeof(int) * 3
    // int[3]

    // dynamic arrays

    int size = 0;
    std::cin >> size;

    int* dyn_arr = new int[size];  // operator new[], массив на куче размера size
    dyn_arr[0] = 1;

    // dyn_arr = new int[100500];  // BAD!!!!!
    // new int;  // BAD!!!!!

    // while (true) {
    //     new int;
    // }

    // type(dyn_arr) = int*
    std::cout << sizeof(dyn_arr) << std::endl;

    // sizeof(type*) = 8 bytes

    // dyn_arr[2] ~=~ *(dyn_arr + 2)
    // 2[dyn_arr] ~=~ *(2 + dyn_arr)

    delete[] dyn_arr;
    // delete[] dyn_arr;  // runtime error -- double free

    // null pointer

    void* empty_ptr = reinterpret_cast<void*>(c);  // указатель на пустой объект
    // 1 байт сырой памяти

    *h = 'a';  // char
    // *empty_ptr;  // CE

    nullptr;  // std::nullptr_t -> (any type)*

    h = nullptr;  // не указывает ни на что

    if (h);  // равносильно if (h != nullptr);
    // nullptr -> false
    // не nullptr -> true

    NULL;  // use nullptr instead

    int arr2d[3][2];
    arr2d[0][0] = 0;
    std::cout << arr2d[0] << std::endl;

    int** dyn_arr2d = new int*[size];
    for (int i = 0; i < size; ++i) {
        dyn_arr2d[i] = new int[i + 1];
    }
    /*
    0
    0 0
    0 0 0
    0 0 0 0
    */
   dyn_arr2d[0][1] = 0;
    for (int i = 0; i < size; ++i) {
        delete[] dyn_arr2d[i];  // delete, delete[] - different operators
    }
    delete[] dyn_arr2d;

    int* dyn_arr_1 = new int[size];
    // code
    {
        int* dyn_arr_2 = new int[size * 2];
        for (int i = 0; i < size; ++i) {
            dyn_arr_2[i] = dyn_arr_1[i];
        }
        delete[] dyn_arr_1;
        dyn_arr_1 = dyn_arr_2;
        size *= 2;
        // здесь нельзя напрямую выделить дополнительную память в ячейке (dyn_arr_1 + size)
        // потому что delete[] всё равно удалит только первую половину
    }

    return 0;
}
