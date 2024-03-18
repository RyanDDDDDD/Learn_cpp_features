#include <iostream>

class B {
    public:
    virtual void func (int num = 0) {
        std::cout << "From B, the num is " << num << std::endl;
    }
};

class D : public B {
    public:
    virtual void func (int num = 5) {
        std::cout << "From D, the num is " << num << std::endl;
    }
};

int main () {
    B objB;
    D objD;

    B* ptrB  = &objB;
    D* ptrD  = &objD;
    B* ptrDB = &objD;

    ptrB->func ();
    ptrD->func ();
    ptrDB->func ();
    // the default para is statically binding, reason to cause this: to improve
    // efficiency during run time, compiler has to do optimization,
    // resulting in pre-set the default value for function call in compile time
    // instead of run time
};