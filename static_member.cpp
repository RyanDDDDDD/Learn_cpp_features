#include <iostream>

using namespace std;


class A{
    public:
        A(){
            mem_1 += 1;
            cout << mem_1 << endl;
        };
        void get_mem2(){
            cout << mem_2 << endl;
        }
    private:
        static int mem_1;                   // non-const static member, need to be initialized outside of class
        static constexpr int mem_2 = 10;    // const static member 
};

int A::mem_1 = 0;

int main(){
    A obj1;
    A obj2;
    obj1.get_mem2();

}