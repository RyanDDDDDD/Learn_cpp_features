#include <iostream>

using namespace std;

int main(){
  int a = 10;

  auto b = std::move(a);

  cout << a << endl;
  cout << b << endl;
  return 0;
}