#include <iostream>
#include <string>
using namespace std;

int main(){
  string str{"Hello World"};

  int count = 0;
  auto fnc = [&count](char c){
    if (isupper(c)) count++;
  };

  for (char c : str){
    fnc(c);
  }

  cout << count << endl;

  return 0;
}