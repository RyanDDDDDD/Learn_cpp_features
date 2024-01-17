#include <iostream>
#include <string>

// Automatic template argument deduction much like how it's done for functions,
// but now including class constructors.
template <typename T = std::string> class myClass {
public:
  myClass() = default;
  myClass(T a) : mem{a} {};
  T getMem() { return mem; };

private:
  T mem;
};

int main() {
  myClass<std::string> cl{"my string"};
  std::cout << cl.getMem() << std::endl;
  myClass<int> cl2{10};
  std::cout << cl2.getMem() << std::endl;
}
