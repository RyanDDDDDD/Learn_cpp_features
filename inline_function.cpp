#include <iostream>

using namespace std;

inline void print(){
    for (int i = 0; i < 10; ++i){
        cout << "hello world" << endl;
    }
    cout << "end of loop" << endl;
}

int main(){
    print();

}