#include <iostream>
#include <memory>
#include <iterator>

class IExpression {
public:
    virtual int Calculate() const = 0;
};

class Constant : public IExpression {
public:
    Constant(int value) : value(value) {}

    virtual int Calculate() const override {
        return value;
    }

private:
    int value;
};

class IUnaryOperation : public IExpression {
public:
    IUnaryOperation(std::unique_ptr<IExpression> child)
        : child(std::move(child))
    {
    }

    virtual int Calculate() const = 0;
protected:
    virtual int Operation(int operand) const = 0;
    // T* left;
    // T* right;
    std::unique_ptr<IExpression> child;
};

class IBinaryOperation : public IExpression {
    // 2 children
    // Operation(left, right)
};

class Square : public IUnaryOperation {
public:
    virtual int Calculate() const override {
        return Operation(child->Calculate());
    }
protected:
    virtual int Operation(int operand) const override {
        return operand * operand;
    }
private:
};

class BinaryTree {
    T* left;
    T* right;
}

T* root;

class BinaryTree {
    std::unique_ptr<T> left;
    std::unique_ptr<T> right;
}

std::unique_ptr<T> root;

// part 2

int CalculatePolishNotation(std::string_view input) {
    auto tokens = Tokenize(input);
    // check correct tokens
    std::unique_ptr<IExpression> root;
    // build tree, recursion
    return root->Calculate();
}

// part 3

int CalculateExpression(std::string_view input) {
    auto tokens = Tokenize(input);
    // check correct tokens
    // build polish notation (stack)
    std::unique_ptr<IExpression> root;
    // build tree, recursion
    return root->Calculate();
}

std::unique_ptr<IExpression> ptr = std::make_unique<Constant>(1);
ptr->Calculate();

template <class TForwardIterator>
UnorderedSet(TForwardIterator begin, TForwardIterator end) {
    for (auto it = begin; it != end; ++it) {
        // write to hash table
    }
}

int main() {
    return 0;
}
