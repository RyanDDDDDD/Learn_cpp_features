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

void processArg(std::shared_ptr<A> arg1, int arg2) {};

int main() {
    // due to compiler optimization, the order to evaluate the arguments is different
    // windows g++ 11.2.0 
    //      call priority
    //      new A
    //      deconstruct A

    // macos clang++ 14.2.0 
    //      new A
    //      call priority
    //      deconstruct A
    
    //  if priority() throw exception, memory leak would happens and the A object on heap cannot be freed
    
    processArg(std::shared_ptr<A>(new A), priority());

    // processArg(std::make_shared<A>(), priority());
}