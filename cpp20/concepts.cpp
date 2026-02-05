#include <concepts>
#include <iostream>
using namespace std;

template <typename T>
  requires integral<T>  // Requires clause
auto max1(T a, T b) {
  return a >= b ? a : b;
}

template <typename T>
auto max2(T a, T b)
  requires integral<T>  // Trailing requires clause
{
  return a >= b ? a : b;
}

template <integral T>  // Constrained template parameter
auto max3(T a, T b) {
  return a >= b ? a : b;
}

auto max4(integral auto a,  // Abbreviated function
          integral auto b)  // template
{
  return a >= b ? a : b;
}

int main() {
  cout << "max1(1,2) = " << max1(1, 2) << '\n';
  cout << "max2(1,2) = " << max2(1, 2) << '\n';
  cout << "max3(1,2) = " << max3(1, 2) << '\n';
  cout << "max4(1,2) = " << max4(1, 2) << '\n';
//   cout << "max4(1,2) = " << max4(1, 2.1) << '\n'; error: no matching function for call to 'max4(int, double)'
}