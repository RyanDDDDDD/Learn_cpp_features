#include <any>
#include <iostream>

using namespace std;

int main() {
  // tpye safe container for holding value and cast them later safely (need to
  // be a copy constructable type)
  std::any x = 'c';
  std::any x2 = 5;
  std::any x3 = 5.0;
  cout << x.has_value() << endl;
  cout << x.type().name() << endl;
  auto c = std::any_cast<char>(x);
  auto y = std::any_cast<int>(x2);
  auto y2 = std::any_cast<double>(x3);
  cout << y << endl;
  cout << y2 << endl;
  // cout << typeid(y).name() << endl;
  // cout << typeid(c).name() << endl;
}