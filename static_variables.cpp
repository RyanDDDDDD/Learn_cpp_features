#include <iostream>

using namespace std;

void func(){
  static int var = 0;
  var++;

  cout << var << endl;
}

int main(){
  func();
  func();
}
