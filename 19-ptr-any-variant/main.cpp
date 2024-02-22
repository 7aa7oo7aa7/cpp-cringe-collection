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
            return T();
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
    variant = true;
    if (std::holds_alternative<bool>(variant)) {
        bool x = std::get<bool>(variant);
    } else {
        // variant has int, double or char
    }

    using Tokens = std::variant<...>;

    std::vector<Tokens> v(len);
    for (size_t i = 0; i < len; ++i) {
        // s[i]
        v[i] = PlusToken();
    }

    return 0;
}
