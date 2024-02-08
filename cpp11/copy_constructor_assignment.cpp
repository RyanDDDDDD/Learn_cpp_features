#include <iostream>
#include <vector>

using namespace std;

class A{
    public:
        A(){
            cout << "default constructor" << endl;
        }

        A(const A& obj) = delete;

        A& operator=(const A& rhs){
            // return reference for chaining
            cout << "copy assignment" << endl;
            this->mem = rhs.mem;
            return *this;
        }

        int mem;
};


int main(){
    A obj{};
    obj.mem = 10;

    // A obj2 = obj;
    // this will call copy constructor,which will be implicitly create if we do not specify
    // in sample code, we delete copy constructor therefore the above line will cause error
    A obj2;
    obj2 = obj;
    cout << obj2.mem << endl;
}