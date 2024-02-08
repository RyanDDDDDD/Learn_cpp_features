#include <iostream>

using namespace std;

class A{
    public:
        A(int num):mem1(num),mem2(num+1),mem3(num+2){}; // sequence of initialization follows the sequence in private section, 
                                                        // initializer list doesn't specify the sequence for initializting member

        //A(int num){
        //    mem1 = num;               
        //    mem2 = num;                   const mem2 has been initialized  before assignment;
        //    mem3 = num;
        //}

        void print_mem(){
            cout << mem1 << ' ' << mem2 << ' ' << mem3 << endl;
        }

    private:
        int mem1;
        const int mem2;
        double mem3;
};

int main(){
    A obj1(10);
    obj1.print_mem();

}