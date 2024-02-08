#include <iostream>
#include <vector>

using namespace std;

class A{
    public:
        A(int a,int b):first(a),second(b){};                                // customized constructor
        void get_mem() const {
            cout << first << ' ' << second << endl;
        }

        void change_first(int a){
            first = a;
        }

    private:
        int first;
        int second;

};

int main(){
 
    auto first = A(1,10);

    auto second = A(2,20);

    second = first;
    
    second.get_mem();
    
    

}