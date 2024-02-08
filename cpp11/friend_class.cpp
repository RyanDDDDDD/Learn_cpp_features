#include <iostream>
#include <string>

using namespace std;

class third{
    public:
        void print_helloworld(string str){
            cout << str << endl;
        };

    private:
        int mem = 20;
};

class first{
    public:
        friend class second;                                                    // friend class declaration
        friend void third::print_helloworld(string str);                        // friend method of class declaration, the class(third) of this friend method must be defined before this class (first)

        void my_print(third obj1,string str = "hello wolrd"){
            obj1.print_helloworld(str);
        }

    private:
        int mem = 10;

};

class second{
    public:
        void print_first(class first obj1){
            cout << obj1.mem << endl;
        }
    private:
        int mem = 10;
};


int main(){
    first A;
    second B;
    third C;
    B.print_first(A);
    A.my_print(C,"hello world");

}