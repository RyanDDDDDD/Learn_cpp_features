#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> vec{};
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);

    const vector<int> vec_2 = vec;
    for (const int &i : vec_2)
    {
        cout << i << endl;
    }
}