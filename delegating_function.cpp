#include <iostream>
#include <string>

using namespace std;

class A{
    public:
        A() = default;      // default constructor
        A(int par1,double par2,string par3):mem_1(par1),mem_2(par2),mem_3(par3){};

        A(int first): A(first,0,"hello world"){};               // function delegation

        void print_par(){
            cout << mem_1 << ' ' << mem_2 << ' ' << mem_3 << endl;
        };

    private:
        int mem_1;
        double mem_2;
        string mem_3;

};

int main(){
    A obj_1 = {};                      // calling default constructor
    A obj_2(10,20.0,"hello");       

    obj_2.print_par();

    A obj_3(30);
    obj_3.print_par();

}
