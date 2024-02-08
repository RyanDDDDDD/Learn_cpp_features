#include <iostream>

using namespace std;

class A{
  public:
    A() {
      cout << "init A" << endl;
    };
    A(int i):mem{i} {
      cout << "init A 2" << endl;
    };
    int mem;
};

class B: public A {
  using A::A;
  
};

int main(){
  A obj(10);
  B obj2(10);

}
