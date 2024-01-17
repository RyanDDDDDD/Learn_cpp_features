#include <iostream>
#include <utility>

using namespace std;

template<typename T>
void printvalue(T& arg){
  cout << "Lvalue accepted" << endl;
}

template<typename T>
void printvalue(T&& arg){
  cout << "Rvalue accepted" << endl;
}

template<typename T>
void printType(T&& arg){
  // arg is lvalue in template function
  // printvalue could be a template or normal function
  printvalue(std::forward<T>(arg));
}

int main(){
  int num = 1;
  int num_2 = 10;
  printType(num);
  printType(std::move(num_2));
  printType(1);

}