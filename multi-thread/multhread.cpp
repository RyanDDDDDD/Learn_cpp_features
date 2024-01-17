#include <iostream>
#include <thread>

using namespace std;

int global = 10;

void increment(){
  cout << "run increment" << endl;
  global++;
}

void decrement(){
  cout << "run decrement" << endl;
  global--;
}

int main(){
  std::thread t(increment);
  std::thread t2(decrement);
  t.join();
  t2.join();

  cout << global << endl;
}