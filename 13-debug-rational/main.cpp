#include <iostream>

class BigInteger {
public:
private:
    static const int BASE = 1000000;
    int* arr;
};

BigInteger::BASE;

class Rational {
public:
    Rational operator+(const Rational& other) {
        Rational this_copy(*this);
        return this_copy += other;
    }

    Rational(int value);

    Rational operator+(const int& other) {
        Rational this_copy(*this);
        return this_copy += other;
    }

    friend Rational operator+(const Rational& left, const Rational& right);

    Rational& operator+=(const Rational& other) {
        // *this = *this + other;  // BAD: calls copy constructor and assignment operator
        return *this;
    }

    Rational& operator++() {
        // ++this;
        return (*this += 1);
    }

    Rational operator++(int) {
        // this++;
        auto this_copy = *this;
        ++(*this);
        return this_copy;
    }

    Rational operator-() {
        // -a;
        auto this_copy = *this;
        this_copy.negative = !this_copy.negative;
        return this_copy;
    }

    bool operator<(const Rational& other) {
        return *this < other;
    }

    bool operator>(const Rational& other) {
        return other < *this;
    }

    bool operator!=(const Rational& other) {
        return *this < other || other < *this;
    }

    bool operator==(const Rational& other) {
        return !(*this != other);
    }

    bool operator<=(const Rational& other) {
        return *this < other || *this == other;
    }

    bool operator>=(const Rational& other) {
        return *this > other || *this == other;
    }
private:
    BigInteger p;
    BigInteger q;
    bool negative;
};

Rational operator+(const Rational& left, const Rational& right) {
    // a + b = operator+(a, b)
    left.p; left.q; right.p; right.q; 
    return Rational(left.p, right.q);
}

Rational& operator+=(Rational& left, const Rational& right) {
    return left;
}

// a + b = a.operator+(b)

// p / q

// int <= 2^64 - 1

int main() {
    BigInteger a(10000);
    BigInteger b(20000);
    a += b;
    ++b;
    a = b + b;
    a %= b;
    std::cin >> a;
    std::cout << a << std::endl;

    (a += b) = 2;
    if ((a += b) == 2) {
        //
    }
    ((a += b) += c) += d;

    return 0;
}
