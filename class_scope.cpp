#include <iostream>

using namespace std;

class A {
public:
  using newtype = int; // customized type is only available within class

  friend A::newtype get_mem2(class A obj1);

  void get_mem1() { cout << mem1 << endl; }

private:
  int mem1 = 10;
  newtype mem2 = 20;
};

A::newtype
get_mem2(class A obj1) { // to access the customized type, we need to specify
                         // the class containning customized type first
  return obj1.mem2;
};

int main() {
  A obj1;
  obj1.get_mem1(); // '.' for accessing member of class

  A *ptr = &obj1;
  ptr->get_mem1();   // '->' for accesing member of a class pointer
  (*ptr).get_mem1(); // equivalent expression as above

  auto obj2 = get_mem2(obj1);
  cout << obj2 << endl;
}