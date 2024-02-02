#include <iostream>

template <class T>
class Stack {
public:
    Stack() : buffer(new T[10]), size(10) {}

    ~Stack() {
        delete[] buffer;
    }

    Stack(const Stack& copy) : buffer(new T[copy.size]), size(copy.size) {
        std::cout << "copy constructor\n";
        for (size_t i = 0; i < size; ++i) {
            buffer[i] = copy.buffer[i];
        }
    }

    // Stack(const Stack<double>& copy) : buffer(new T[copy.size]), size(copy.size) {
    //     std::cout << "copy constructor\n";
    //     for (size_t i = 0; i < size; ++i) {
    //         buffer[i] = copy.buffer[i];
    //     }
    // }

    Stack& operator=(const Stack& copy) {
        // Stack stack;
        // Stack stack2;
        // stack2 = stack; утечка памяти без delete

        std::cout << "copy assignment operator\n";
        delete[] buffer;
        // buffer[1];  RE
        // delete[] buffer;  RE
        buffer = new T[copy.size];
        size = copy.size;
        for (size_t i = 0; i < size; ++i) {
            buffer[i] = copy.buffer[i];
        }
        return *this;
    }

private:
    T* buffer;
    size_t size;
};

class MinQueue {
public:
    // ~MinQueue() {
    //     // first.~Stack();
    //     // second.~Stack();
    //     first.Clear();
    //     second.Clear();
    // }
private:
    Stack<int> first;
    Stack<int> second;
};

struct B {
};

class A {
public:
    ~A();
    A();

    A(const A& copy) {
        //
    }

    A& operator=(const A& copy) {
        // copy += 2;
        // copy.f();
        //
        return *this;
    }

    // A(const A& copy) = delete;
    // A& operator=(const A& copy) = delete;

    // ~A() = delete;

    // ~A() = default;

private:
    // ~A();
    int a;
    double d;
    int* c;
    B b;
};

A::~A() {
    //
    std::cout << "destructor\n";
}



// RAII - resource acquisition is initialization

class Pointer {
public:
    Pointer() : ptr(new int) {}

    ~Pointer() {
        delete ptr;
    }

    Pointer(const Pointer& copy) {
        ptr = new int(*(copy.ptr));
    }

    Pointer& operator=(const Pointer& copy) {
        delete ptr;
        ptr = new int(*(copy.ptr));
        return *this;
    }

private:
    int* ptr;
};


class A1 {
public:
    A1() {
        ptr = new int;
        std::cout << "constructor A1\n";
    }

    ~A1() {
        delete ptr;
        std::cout << "destructor A1\n";
    }

    int* ptr;
};

class A2 {
public:
    A2(int* ptr) : ptr(ptr) {
        std::cout << "constructor A2\n";
    }
    
    ~A2() {
        delete ptr;
        std::cout << "destructor A2\n";
    }

    int* ptr;
};


int main() {
    // Stack* stack = new Stack;
    // A a;
    // A a_copy(a);
    // a = a_copy;

    // Stack stack(10);
    // Stack stack_copy(stack);
    // Stack stack1(Stack());

    Stack<int> stack;
    Stack<int> stack_copy_1(stack);
    Stack<int> stack_copy_2 = stack;  // copy constructor
    Stack<int> stack_copy_3;
    stack_copy_3 = stack;  // copy assignment operator

    // A a;
    // A a_copy(a);

    Pointer ptr;



    A1 a1;
    A2 a2(a1.ptr);



    // error
    // stack.Clear();
    // a.~A();
    return 0;
    // ~A();
}
