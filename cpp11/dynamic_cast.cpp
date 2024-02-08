#include <iostream>
// https://pabloariasal.github.io/2017/06/10/understanding-virtual-tables/

using namespace std;

class Base{
    public:
        Base() = default;
        virtual void print(){
            cout << "base class" << endl;
        }

        virtual ~Base(){
            cout << "delete Base" << endl;
        };
};

class Derived : public Base {
    public:
        virtual void print(){
            cout << "derived class" << endl;
        }

        virtual ~Derived(){
            cout << "delete derived" << endl;
        };
};

int main(){
    Base *obj = new Derived();
    
    obj -> Base::print();
    // calling the print of Base class

    Derived *obj2 = dynamic_cast<Derived*>(obj);
    // used for safely convert a pointer to base class to a pointer to derived class
    // if can not perform conversion, return an nullptr
    // if convert successfully, these two pointers now point to same memory
    if (obj2 != nullptr){
        obj2 -> print();
    }  

    delete obj;
    // call destructor for the allocated memory on heap
    // when deconstruct object, first deconstruct the derived part of object, then base part



}