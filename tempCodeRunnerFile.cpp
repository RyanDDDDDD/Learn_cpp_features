#include <iostream>
#include <memory>

class A {
public:
    A() {
        std::cout << "new A" << std::endl;
    }

    ~A() {
        std::cout << "deconstruct A" << std::endl;
    }
};

int priority() {
    std::cout << "call priority" << std::endl;
    return 1;
};

void processArg(std::shared_ptr<A> arg1, int arg2) {


};

int main() {
    processArg(std::shared_ptr<A>(new A), priority());
}