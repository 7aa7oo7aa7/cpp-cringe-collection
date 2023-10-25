#include <iostream>

// enum, union, struct

// 2
// zabacabab

// za - ZAbacabab
// ab - zABAcabab +
// ba - zaBAcabab
// ac - zabACAbab + 
// ca - zabaCAbab
// ab - zabacABab +
// ab - zabacABAb +
// ab - zabacABAB +
// ba - zabacaBAB + 
// ab - zabacabAB

enum Enum {
    ConstA = 0,
    ConstB = 1,
    ConstC = 2,
};

enum class EnumCPP {
    ConstA,
    ConstB,
    ConstC,
};

enum class ENotebookType {
    Line,
    VerticalLine,
    Square,
    Unknown,
};

ENotebookType NotebookType() {
    bool IsLine = true;
    bool IsVerticalLine = true;
    bool IsSquare = true;
    if (IsLine) {
        return ENotebookType::Line;
    } else if (IsVerticalLine) {
        return ENotebookType::VerticalLine;
    } else if (IsSquare) {
        return ENotebookType::Square;
    }
    return ENotebookType::Unknown;
}

int F() {
    if (true) {
        return 1;
    }
    return 2;
}

union IntDouble {
    int i;
    double d;
};

struct IntDoubleStruct {
    int i;
    double d;
};

union IntBytes {
    uint64_t i64;
    uint32_t i32;
    uint16_t i16;
    uint8_t i8;
};

template <class T>
struct DynArray {
    T* arr;
    size_t size;
};

template <class T>
void AllocateMemory(DynArray<T>& dyn_arr, size_t size) {
    dyn_arr.arr = new T[size];
    dyn_arr.size = size;
}

template <class T>
void DeallocateMemory(DynArray<T>& dyn_arr) {
    delete[] dyn_arr.arr;
}

template <class T>
void Print(const DynArray<T>& dyn_arr) {
    for (size_t i = 0; i < dyn_arr.size; ++i) {
        std::cout << dyn_arr.arr[i] << std::endl;
    }
}

struct A {
    int a;
};

struct BigInt {
    int* arr = nullptr;  // 0-9 -> 0-9999
    size_t size = 0;
    static const int base = 10000;
};

// 1 2 3 1 2 5 2 3 1 2 3 3 1 1 2
// 1231 2523 1233 112
// arr[3] + base * arr[2] + base * base * arr[1] + base * base * base * arr[0]

int main() {
    std::cout << BigInt::base << std::endl;
    ENotebookType type = NotebookType();
    if (type == ENotebookType::Line) {
        // std::cout << "Line";
    } else if (type == ENotebookType::VerticalLine) {
        // std::cout << "Vertical Line";
    }
    int f = F();
    ++f;
    f %= 2;

    IntDouble id;
    id.i = 1;
    id.d = 2.0;

    std::cout << id.i << " " << id.d << std::endl;  // UB

    IntDoubleStruct id_struct;
    id_struct.i = 1;
    id_struct.d = 2.0;

    std::cout << id_struct.i << " " << id_struct.d << std::endl;

    IntBytes a;
    a.i64 = (1ULL << 48) + 1;
    std::cout << a.i64 << " " << a.i32 << " " << a.i16 << " " << a.i8 << std::endl;

    DynArray<double> dyn_array;
    AllocateMemory(dyn_array, 1024);
    // Print(dyn_array);
    DeallocateMemory(dyn_array);

    A a_struct;
    std::cout << a_struct.a << std::endl;

    return 0;
}
