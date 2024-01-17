#include <iostream>

using namespace std;

int main(){
  int num = 0b10;
  int num2 = 0b11; // or 0B , also support 0x
  // unlike supported by compiler before, c++ now have standardrized this syntax

  cout << num << ' ' << num2 << endl;

}
