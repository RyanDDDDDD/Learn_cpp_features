#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

int main(){
    vector<int>  vec{};
    auto ite = back_inserter(vec);
    *ite = 10;
    *ite = 20;
    *ite = 30;

    for(auto i : vec){
        cout << i << endl;
    }


}