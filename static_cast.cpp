#include <iostream>

using namespace std;

int main(){
  // should not use static_cast to convert pointer, this will raise runtime error
  // when trying to write value using the converted pointer
  int var = 1;

  int* var2 = static_cast<int*>(&var);
  cout << *var2 << endl;

  int var3 = 10;

  short var4 = static_cast<short>(var3);

  cout << var4 << endl;

  // no error raise when using c style type conversion
  char c = 65; //1-byte data. ASCII of ‘A’
  int *ptr = (int*)&c; //4-byte

  // raise error that an int pointer pointing to 4 bytes memory can not points to char (only 1 byte) 
  //int *ptr2 = static_cast<int*>(&c);

}