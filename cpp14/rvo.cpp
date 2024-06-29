#include <iostream>
#include <memory>
#include <type_traits>

class MyClass {
public:
    MyClass () {
        std::cout << "default constructor" << std::endl;
    }

    MyClass (const MyClass& other) {
        std::cout << "copy constructor" << std::endl;
    }

    MyClass (MyClass&& other) {
        std::cout << "move constructor" << std::endl;
    }

    ~MyClass () {
        std::cout << "destructor" << std::endl;
    }
};

MyClass getObj () {
    MyClass obj;

    // when return value is a local object, compiler will initialize obj in the memory allocated for the caller
    return obj;
    // when when return value is a rvalue-reference, compiler still need to
    // intialize local obj in the fucntion body and convert to reference to
    // return return std::move (obj);
};

int main () {
    MyClass obj = getObj ();
}