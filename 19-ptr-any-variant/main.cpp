#include <iostream>
#include <memory>
#include <variant>
#include <vector>

class Any {
public:
    Any() : base(nullptr) {}

    template <class T>
    Any(const T& object) : base(new AnyHolder<T>(object)) {}

    template <class T>
    friend T& AnyCast<T>(Any& any);

    ~Any() {
        delete base;
    }

    Any(const Any& other) : base(other.base->Clone()) {}

private:

    struct IHolder {
        virtual ~IHolder() = 0;
        virtual IHolder* Clone() = 0;
    };

    template <class T>
    struct AnyHolder : public IHolder {
        T value;
        AnyHolder(T value) : value(value) {}
        virtual IHolder* Clone() override {
            // create new T object in heap
            return new AnyHolder<T>(value);
            return std::make_unique<AnyHolder<T>>(value);
        }
    };

    IHolder* base;

};

template <class T>
T& AnyCast(Any& any) {
    return dynamic_cast<Any::AnyHolder<T&>>(*any.base);
}

struct A {
    A(int a, int b) : a(a), b(b) {}
    int a;
    int b;
};

struct Base {
    //
};

struct Derived : public Base {
    //
};

struct Base2 {
    //
};

Derived d;
Base& b = dynamic_cast<Base&>(d);
Base2& b = dynamic_cast<Base2&>(d);  // exception: std::bad_cast

struct BadAnyCast : public std::exception {
    //
};

template <class T>
T& AnyCast(Any& any) {
    try {
        return dynamic_cast<Any::AnyHolder<T&>>(*any.base);
    } catch (std::bad_cast e) {
        throw BadAnyCast();
    }
}

// reference collapsing
void f(int&& a) {}

int a = 1;
int& b = a;  // & + && = &
int&& c = a;  // && + && = &&
f(b);
f(c);

template <class T>
T&& Forward(T& value) {
    return static_cast<T&&>(value);
}

template <class T, class... Args>
std::unique_ptr<T> MakeUnique(Args&&... args) {
    return std::unique_ptr<T>(new T(std::forward<T>(args)...));
}

int main() {

    Any any;
    Any::IHolder;  // private

    std::shared_ptr<int>;
    std::unique_ptr<int>;

    std::make_unique;
    std::make_shared;

    std::shared_ptr<A> ptr(new A(10, 20));
    std::shared_ptr<A> ptr = std::make_shared<A>(10, 20);
    std::unique_ptr<A> ptr = std::make_unique<A>(10, 20);

    std::variant<int, double, char, bool> variant;
    variant = 1;
    variant = 1.2;
    variant = true;
    if (std::holds_alternative<bool>(variant)) {
        bool x = std::get<bool>(variant);
    } else {
        // variant has int, double or char
    }

    using Tokens = std::variant<PlusToken, MinusToken, NumberToken, ...>;

    std::vector<Tokens> v(len);
    for (size_t i = 0; i < len; ++i) {
        // s[i]
        v[i] = PlusToken();
    }

    return 0;
}
