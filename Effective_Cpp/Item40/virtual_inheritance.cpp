#include <iostream>

class B {
    int mem1;
    int mem2;
};

class D1 : public B {};
class D2 : public B {};

class DD : public D1, public D2 {};
class VirtualDD : virtual public D1, virtual public D2 {};

int main () {
    std::cout << sizeof (DD) << std::endl;

    // virtual base class is usually larger than a normal MI class

    // the compiler introduce virtual base table to keep track of the virtual
    // base class and ensure only one copy of base class would be initialized
    // when accessing member in virtual base class, the compiler would use the
    // virtual base table to determine the correct member

    // the common base class would be constructed by most derived class during construction.
    std::cout << sizeof (VirtualDD) << std::endl;
}