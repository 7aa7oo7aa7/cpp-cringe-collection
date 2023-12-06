#include <iostream>
#include <cstdint>
#include <cmath>
#include <vector>

int s = 0;

int main() {

    // целочисленные типы
    int a = 1;  // 4 байта [-2^31, 2^31 - 1]
    short s = 1;  // 2 байта [-32768, 32767]
    long b = 1;  // >=int, 4 байта
    long long l = 0;  // 8 байт [-2^63, 2^63 - 1]

    s = -32768;
    s = s - 1; // undefined behavior

    // беззнаковые типы >=0
    unsigned int c = 1;  // 4 байта [0, 2^32 - 1]
    unsigned long long x = 0;  // [0, 2^64 - 1]

    c = 0;
    c = c - 1;  // c = 2^32 - 1
    c = c + 2;  // (2^32 - 1) + 2 = 1;

    char s = 0;  // 1 байт [-128, 127]
    s = 'a';

    unsigned char p = 0;  // 1 байт [0, 255 = 2^8 - 1]

    signed int a = -1;

    int32_t a = 0;  // ровно 4 байта
    int16_t;
    int8_t;
    int64_t;
    uint8_t;
    uint16_t;
    uint32_t;
    uint64_t;

    // bool

    bool v = false;  // true, false; 1 байт
    v = true;
    // 0 -> false, !0 -> true
    v = 1;  // true
    v = -1;  // true
    v = 0;  // false

    // false -> 0, true -> 1

    int v_int = 0;
    v_int = true;  // 1
    v_int = false; // 0

    // типы с плавающей точкой
    float a = 0;  // 4 байта
    double d = 1.5555555;  // 8 байт
    long double dd = 1.5555555;  // 16 байт

    // #include <cmath>

    round(a);  // 2
    ceil(a);  // 2
    floor(a);  // 1

    sqrt(a);  // 1.41...

    // приведение типов

    /// int
    // size ^
    // signed -> unsigned

    /// float
    // size ^
    // int, float -> float

    float a = 0.5;
    int b = 2;

    std::cout << a / b << std::endl;

    // операторы

    // a + b --> operator+(int a, int b)

    1 + 1;
    1 - 1;
    1 * 2;
    3 / 2;  // целочисленное деление (int, int), обычное деление (float)
    3 % 2;  // деление с остатком

    bool a = true;
    bool b = false;

    !(a && b);  // true <==> a == true и b == true, амперсанд
    a || b;  // true <==> a == true или b == true
    !a;  // true <==> a == false

    // ! -> && -> ||

    int a = 0;
    int b = 0;
    a = a + 1;  // создаётся копия a, выполняется сложение, записано в a
    a += 1;  // прибавление напрямую к a
    ++a;  // возвращается новое значение a
    a++;  // возвращается старое значение a

    std::cout << a++ << std::endl << a << std::endl;

    std::vector<int> v(3);  // 0, 1
    int i = 0;
    while (i <= 2) {
        std::cout << v[i++]; // v[0], i++, v[1], i++, v[2], i++, i = 3
    }

    // побитовые операторы
    1 & 1;  // and
    1 | 1;  // or
    ~1;  // not
    1 ^ 1;  // xor

    // a = 0 = 00000000
    // b = 2 = 00000010
    // a & b = 00000000
    // a | b = 00000010
    // ~a = 11111111 = 2^8 - 1 = 255
    // a ^ b = 00000000 ^ 00000010 = 00000010

    // uint8_t a;
    // uint16_t b;
    // a ^ b = uint16_t
    // uint16_t(a) = 00000000 00000000

    const int x = 0;

    // операторы преобразования типов
    int a = 0;
    char c = static_cast<char>(a);
    float b = reinterpret_cast<float>(a);
    const int d = const_cast<const int>(a);
    (float) a;

    // область видимости
    int s = 0;
    ::s = 1;
    s = 1;
    {
        int s = 0;
        s = 1;
        ::s = 1;
        {
            int s = 0;
            int t = 0;
            t = 1;
            s = 1;
            p = 1;
        }
        s = 1;
        p = 1;
        t;
    }
    s = 1;

    unsigned long long l = 1111111111111uLL;

    std::cout << 9 + 8L / 3uL * 7 - 36 << std::endl;

    return 0;
}
