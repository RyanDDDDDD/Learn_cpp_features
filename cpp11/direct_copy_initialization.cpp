#include <iostream>

using namespace std;

class A{
    public:
        A() = default;

        explicit A(int){
            cout << "using int to construct" << endl;
        }

        A(double){
            cout << "using double to construct" << endl;
        }

        A(A& rhs){
            cout << "copy constructor" << endl;
        }

        A& operator=(A& rhs){
            // The equals sign, =, in copy-initialization of a named variable is not related 
            // to the assignment operator. Assignment operator overloads have no effect on copy-initialization.
            cout << "copy assignment" << endl;
            return *this;
        }

};

int main(){
    A obj_1(10);
    A obj_2(10.2);

    A obj_3 = 10;
    // copy-initialization would perform implicit converstion on the rhs
    // it try to convert the rhs to a possible type as a parameter for constructors it will call the best matching constructor for obj_3
    // there is nothing to do with the '=' sign even though we overload the '=' opeartor
    // copy-initialization only considers non-explicit constructors and user-defined conversion functions.
    A obj_4;
    obj_4 = obj_3;
}