#include <iostream>

using namespace std;

int main(){
  const int x = 0;
  auto x2 = x; // int
  // deceltype(auto) will consider cv qualifier in type deduction, using only auto doesn't deduct cv
  decltype(auto) x3 = x; // const int

  x2++;
  // x3++; error: can not modify const 

  int y = 0;
  int& y2 = y;
  auto y3 = y2; // int
  y3++;
  // cout << y2 << endl; // still 0

  decltype(auto) y4 = y2; // int&
  y4++;
  cout << y << endl; // y becomes 1

}
