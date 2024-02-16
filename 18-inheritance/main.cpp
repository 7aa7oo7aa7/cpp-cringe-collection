#include <iostream>

class Base {
public:
    Base(int a) : a(a) {}

    void f() {
        std::cout << a << std::endl;
    }

protected:
    int a;
};

class Derived : public Base {
public:
    Derived(int a_, int b) : Base(a_), b(b) {
        a = 10;
        Base::a = 10;
        f(10);
        Base::f();
    }

    void f(int x) {
        std::cout << a << " " << b << " " << x << std::endl;
    }

protected:
    int a;
    int b;
};

class Derived1 : private Base {
public:
    Derived1(int a_, int b) : Base(a_), b(b) {
        a = 10;
        Base::a = 10;
    }

protected:
    int a;
    int b;
};

class Derived2 : public Base, private Derived {};

// struct, class

// struct -> public
// class -> private
class Derived3 : Derived1 {};

template <class T>
class BaseString {
public:
    // 
private:
    size_t size;
    size_t capacity;
    T* arr;
};

class String : public BaseString<char> {
public:
private:
};

class Derived3 : public Base {};
class Derived4 : public Base {};
class Derived5 : public Base {};

class Derived6 : public Derived {
public:
    Derived6(int a, int b, int c) : Derived(a, b), c(c) {
        a = 10;
        Derived::a = 11;
        Base::a = 12;
    }

private:
    int a;
    int b;
    int c;
};

class Derived7 : public Derived1 {
public:
    Derived7(int a, int b, int c) : Derived1(a, b), c(c) {
        a = 10;
        Derived1::a = 11;
        Base::a = 12;
    }

private:
    int a;
    int b;
    int c;
};

void f(Base& b) {}

int main() {
    Derived d(1, 2);

    Base b_copy = d;
    Base& b_ref = d;
    Base* b_ptr = &d;

    return 0;
}
