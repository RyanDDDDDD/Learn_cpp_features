#include <iostream>

using namespace std;

int count = 10;

int main(){
  ::count = 12;

  cout << ::count << endl;

  int &&ref = 10;
  {

  }

}
