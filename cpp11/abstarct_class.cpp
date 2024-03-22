#include <iostream>

// abstract base class
class B {
    public:
    virtual void func () = 0;
};

class D : public B {
    public:
    virtual void func () {
    }
};

int main () {
    // B objB;
    // error, abstarct class can not be initialzed, since its interface is partily deinfed
    //

    D objD;
}