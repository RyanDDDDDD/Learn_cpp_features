#include <iostream>

using namespace std;

class A{
    public:
        A() = default;
        int mem_2 = 20;         
    protected:
        int mem_1 = 10;
};

class B:public A{
    public:
        B() = default;

        void get_mem(){
            cout << mem_1 << endl;
        }
};

int main(){
    B obj1;
    obj1.get_mem();
    cout << obj1.mem_2 << endl;

}