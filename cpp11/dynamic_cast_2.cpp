// C++ Program demonstrates successful
// dynamic casting and it returns a
// value of type new_type
#include <iostream>

using namespace std;
// Base Class declaration
class Base {
public:
  // need to use virtual to mark the base class to be polymorphic
  virtual void print() { cout << "Base" << endl; }
};

// Derived1 class declaration
class Derived1 : public Base {
public:
  void print() { cout << "Derived1" << endl; }
};

// Derived2 class declaration
class Derived2 : public Base {
public:
  void print() { cout << "Derived2" << endl; }
};

// Driver Code
int main() {
  Derived1 d1;

  // Base class pointer holding
  // Derived1 Class object
  Base *bp = dynamic_cast<Base *>(&d1);

  // Dynamic_casting
  Derived1 *dp2 = dynamic_cast<Derived1 *>(bp);
  if (dp2 == nullptr) {
    // if we try to convert to Derived2*, it would fail and return nullptr
    cout << "null" << endl;

  } else {
    dp2->print();
    cout << "not null" << endl;
  }

  return 0;
}
