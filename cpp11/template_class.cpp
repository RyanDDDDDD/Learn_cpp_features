#include <iostream>

using namespace std;

template <typename T>                                           // template
int compare(const T& lhs, const T& rhs){
    return lhs > rhs ? 1 : lhs == rhs ? 0 : -1;                 // ternary operator 三元操作符                   
}

int main(){
    cout << compare(1,2) << endl;

}