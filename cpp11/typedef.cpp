#include <iostream>

using namespace std;

#define mysecondtype int
// preprocessor directive(macro), this will be processed in preprocess phase
// can be used for define a constant

typedef int mytype;
// compiler directive
// will be processed in compiling time

int main()
{
    mytype var = 10;
    int i;
    cout << (typeid(var).name() == typeid(mysecondtype).name()) << endl;
}