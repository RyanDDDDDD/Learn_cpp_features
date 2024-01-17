#include <iostream>

using namespace std;

[[deprecated("This function is depreacted if you try to use it")]]
int add(int a, int b){return a + b;}

int main(){

  cout << add(1, 2) << endl;
}
