#include <iostream>

using namespace std;

class A {
public:
  A() = default;

  void print() { cout << "hello world" << endl; }
};

class B : public A {
public:
  B() = default;
  void print() { cout << "hello world from derived" << endl; }
};

int main() {

  B obj2;

  A *obj1 = &obj2;

  obj1->print(); // this is not a virtual member function, therefore compiler
                 // will choose the calling function at compile time
                 // if we want to call the print() from B, declare A::print() as
                 // virtual then override B::print(), this is called dynamic
                 // binding: determine the correct function to run during
                 // running time since the compiler can not make decision

  //   A obj4; // error, cannot convert base class object into derived class

  //   B *obj3 = &obj4;
}