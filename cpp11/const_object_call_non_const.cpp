#include <iostream>

using namespace std;

class A{
    public:
        A() = default; 

        void print() const {                        
            // const member_method
            // cannot call this withour const keyword 
            // to specify the body of method
            cout << mem_1 << ' ' << mem_2 << endl;
        }
    private:
        int mem_1 = 0;
        int mem_2 = 0;
};

int main(){

    const A obj_1;
    obj_1.print();

}