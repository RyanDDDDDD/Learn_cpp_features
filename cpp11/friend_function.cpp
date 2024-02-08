#include <iostream>
#include <string>

using namespace std;

void print(const int& obj){
    cout << obj << endl;
}

void print_str(const string& str){
    cout << str << endl;
}

class A{
    friend void print(const int& obj);
    friend void print_str(const string& str);
    public:
        A() = default;

        void print2(){
            print(this -> mem1);
        }

        void print3(){
            print_str(this -> str);
        }

    private:
        int mem1 = 1;
        string str = "hello world";
};

int main(){
    auto a = A();
    a.print2();
    a.print3();
}