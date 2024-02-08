#include <iostream>

using namespace std;

class A{
    public:
        A(int a,int b):mem_1(a),mem_2(b){};

        void print_mem(){
            cout << "mem_1 = " << mem_1 << '\n' << "mem_2 = " << mem_2 << endl;
        }

        friend A operator+(const A& lhs,const A& rhs){                          // 非成员函数
            auto sum = lhs;
            sum.mem_1 += rhs.mem_1;
            sum.mem_2 += rhs.mem_2;
            return sum;
        }

    private:
        int mem_1;
        int mem_2;
};

int main(){
    auto obj1 = A(1,10);

    auto obj2 = A(2,20);

    auto obj3 = obj1 + obj2;
    
    obj3.print_mem();

}