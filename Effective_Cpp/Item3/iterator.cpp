#include <iostream>
// #include <iterator>
#include <vector>

using namespace std;

int main() {
    vector<int> vec{1,2,3,4,5};

    const vector<int>::iterator iter = vec.begin();
    // iter++;    error, iter is const

    vector<int>::const_iterator iter2 = vec.begin();
    // *iter2 = 10;  error, const_iterator can not modify value

    iter2++;
}