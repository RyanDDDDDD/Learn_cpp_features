#include <iostream>

using namespace std;

int main(){
    int a = 10;
    int* const i = &a;          // top level const, pointer itself can not point to another address
    //i++;                      // error 
    *i = 20;
    cout << *i << endl;

    const int* j = &a;          // low level const, pointer points to a const object
    //*j = 30;                  // error
    cout << *j;


}