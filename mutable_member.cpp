#include <iostream>

using namespace std;

class A{
    public:
        A() = default;

        void change(int first,int second) const {        
            // const member method, we can still modify the member variable inside 
            // the function body since they are specified as mutable
            mem_1 = first;
            mem_2 = second;
        }

        void print(){
            cout << mem_1 << ' ' << mem_2 << endl;
        }

    private:
        mutable int mem_1 = 0;
        mutable int mem_2 = 0;
};

int main(){
    A obj_1;
    obj_1.print();
    obj_1.change(10,10);
    obj_1.print();


}