#include <iostream>

using namespace std;

namespace {
    int a = 10;
    // the variable defined within the anonymous namespace with only accessible in this file
}

class A {
    public:
        static void print(){
            // with static keyword, we don't have to initialize class to call the member function
            cout << "hello world" << endl;
        };
};


int main(){
    A::print();
    // call member function directly without initialization

    cout << a << endl;
}