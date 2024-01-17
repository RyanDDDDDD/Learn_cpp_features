#include <iostream>

using namespace std;

int main(){
  // before c++ 14, it didn't support using auto keyword to specify lambda parameter
  auto add = [](auto x, auto y){return x + y;};

  int num1 = 2;
  int num2 = 4;

  cout << add(1, 2) << endl;
  cout << add(num1, num2) << endl;

  return 0;
}
