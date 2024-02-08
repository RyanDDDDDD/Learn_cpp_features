#include <iostream>

using namespace std;

int main(){
    auto str = "hello world";
    cout << typeid(str).name() << endl;

    auto num = 10;
    cout << typeid(num).name() << endl;

    float fl = 10.21;
    auto auto_fl = fl;
    cout << typeid(auto_fl).name() << endl;



}