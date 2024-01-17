#include <iostream>

using namespace std;

int main()
{
    const int x = 10;
    const int &i = x;
    int &y = const_cast<int &>(i);
    // delete const reference on int reference i

    y = 100;

    cout << x << endl;
}