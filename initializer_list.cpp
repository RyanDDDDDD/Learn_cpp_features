#include <iostream>
#include <initializer_list>

using namespace std;

class A{
    public:
        explicit A(int a){
            cout << "normal constructor" << endl;
        }
        
        explicit A(std::initializer_list<int>){
            cout << "initializer_list" << endl;
        }

        
};

int main(){
    A vec(std::initializer_list<int>{1}); 
    A vec_2(1);   

}