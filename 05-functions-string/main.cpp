#include <iostream>
#include <cstring>

// functions

int f2(int a);  // definition, определение

int f1(int a) {
    return f2(0);
}

int f2(int a) {  // declaration, объявление
    if (a == 0) {
        return 0;
    } else {
        return f1(a);
    }
}

// int a;  // всегда declaration


int f(int a, int b) {
    // code
    return a;
}

void g() {
    int a = f(1, 2);
    std::cout << a << std::endl;
}

// recursion

int recursion(int a) {
    if (a == 0) {
        return 0;
        a++;  // не произойдёт
    }
    return recursion(a - 1) + 1;
}

int h(int a, int b) {
    return b;
}

int h(int a) {
    return a;
}

int h(float a) {
    return a + 1;
}

void increment(int* p) {
    ++(*p);
    ++p;  // ???
    // 1. обращение через *p
    // 2. модификация указателя
}

void increment_int(int a) {
    ++a;
    // икремента не будет
    // а - копия
}

// void f_const(const int x) {
//     ++x;
// }

int f3(int a, int) {
    return a;
}

int sum(int a = 1, int b = 0, int c = 0) {
    return a + b;
}

int sum2(int a, int b = 0) {
    return a + b;
}

int sum2(int a) {
    return a * 2;
}

// references

void increment_ref(int& a) {
    ++a;
}

void print(const int& a) {  // a не копируется
    std::cout << a;
}

void swap(int& a, int& b) {
    int tmp = a;
    a = b;
    b = tmp;
}

// dangling reference

int& dangling_reference() {
    int a = 0;
    int& a_ref = a;
    return a_ref;
}

void f_bad(int n) {
    int* arr = new int[n];
    delete[] arr;
}

void f_dyn_arr(int* arr, int length) {
    arr[0] = 1;
    arr[length - 1] = 1;
}

void f_dyn_arr_2d(int** arr, int length) {
    //
}

void f_arr(int arr[]) {
    arr[0] = 100;
}

// string

int main() {
    // std::endl -> \n
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    bool b = true;
    if (b) {
        // if (b == true)
    }
    if (!b) {
        // if ((not b) == true)
    }

    // std::cout << h(1.0) << " " << h(1, 2) << std::endl;
    // int a = 0;
    // int* p = &a;
    // increment(p);
    // increment_int(a);
    // std::cout << a << std::endl;
    std::cout << sum(1, 2, 3) << " " << sum(1, 2) << " " << sum(1) << " " << sum() << std::endl;
    // std::cout << sum2(1, 2) << " " << sum2(1) << std::endl;
    int a = 0;
    int& a_ref = a;
    int* p = &a;  // not a reference
    ++a_ref;
    std::cout << a << " " << a_ref << std::endl;
    std::cout << sizeof(int&) << std::endl;
    increment_ref(a_ref);
    increment_ref(a);
    std::cout << a << std::endl;
    const int& a_const_ref = a;  // константная ссылка, const reference
    const int* p_const = &a;
    ++p_const;
    // ++(*p_const);
    // ++a_const_ref;
    int*& p_ref = p;
    // (int*)&
    *p_ref = 100500;
    ++p_ref;
    int& dangling = dangling_reference();
    int arr[50];  // sizeof(arr) = sizeof(int[50]) = 50 * sizeof(int)
    int* arr_dyn[a];  // sizeof(arr_dyn) = sizeof(int*) = 8
    f_arr(arr);
    std::cout << arr[0] << std::endl;

    // C-style string
    "Hello, world!";  // array of char
    std::string s = "Hello, world!";  // not the same
    s.length();
    s.clear();
    std::string x = std::to_string(1);
    std::strcat(a, b);
    a + b;
    a += b;
    s.substr(1, 3);  // abcde -> bcd

    const char s1[4] = "aaa";
    "aaa"; // 4 символа, 4-й символ конца строки '\0'
    '\0';
    s1[0];
    s1;
    char* s_dyn = new char[4]{"aaa"};
    std::cout << static_cast<int>(s1[3]) << std::endl;
    delete[] s_dyn;
    std::cout << s1 << std::endl;
    char char_arr[3] = {'a', 'b', 'c'};  // not a string
    std::cout << char_arr << std::endl;

    std::strlen(s.c_str());
    s.c_str();  // std::string -> const char*
    s.data();  // std::string -> const char* без '\0'

    const char* s3 = "aaa";
    const char* s4 = "abb";
    std::cout << (s3 == s4) << std::endl;

    return 0;
}
