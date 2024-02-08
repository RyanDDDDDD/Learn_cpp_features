#include <iostream>

using namespace std;

int printType(int i){
    cout << typeid(i).name() << endl;
    return i;
}

double printType(double i){
    cout << typeid(i).name() << endl;    
    return i;
}


int main(){
    printType(10);

    printType(5.55);

    int i = 1;
    printType(i);

    // printType(10l);
    // this is wrong


}