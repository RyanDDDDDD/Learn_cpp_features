#include <iostream>

class MyClass {
public:
  int x, y;

  // Overload the output stream operator to return a const reference
  friend std::ostream& operator<<(std::ostream& os, const MyClass& obj) {
    os << "x: " << obj.x << ", y: " << obj.y;
    return os;
  }
};

int main() {
    MyClass obj { 1, 2 };
    std::cout << obj << std::endl;
    // equal to operator<<(std::cout,obj) therefore we cannot pass a const ostream object
    // and also, we can not return a const ostream because we need to chain expresion
    return 0;
}