#include <iostream>

using namespace std;

extern "C" {
  // treat the code inside the code block to be written in c
  void print(){
    cout << "hello world" << endl;
  }
}

int main(){
  print();
}
