#include <iostream>

class MyClass {
private:
  int data;

public:
  MyClass(int value) : data(value) {}

  friend std::ostream &operator<<(std::ostream &os, const MyClass &obj);
  // needs to declear as friend, for operators chianing and accesss private
  // member
};

std::ostream &operator<<(std::ostream &os, const MyClass &obj) {
  return os << "MyClass: " << obj.data;
}

int main() {
  MyClass myObject(42);
  std::cout << myObject << std::endl;
  return 0;
}
