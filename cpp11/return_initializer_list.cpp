#include <iostream>
#include <vector>

using namespace std;

vector<int> get_vector(){
    return {1,2,3,4};
}

int main(){
    auto vec = get_vector();

    for (auto const& i : vec){
        cout << i << endl;
    }
    
}