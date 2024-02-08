#include <iostream>

using namespace std;

class A {
public:
  A() = default;

  A(int i) : mem_(i) { cout << "normal constructor" << endl; }

  // copy constructor
  A(A &i) { cout << "copy constructor" << endl; }

  // move constructor
  A(A &&i) { cout << "move constructor" << endl; }

private:
  int mem_;
};

int main() {
  A obj1(1);
  A obj2(obj1);
  A obj3(std::move(obj2));
}
