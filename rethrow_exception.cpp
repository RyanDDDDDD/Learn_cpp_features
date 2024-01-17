#include <iostream>
#include <exception>

using namespace std;

int main()
{
    try
    {
        try
        {
            throw 1;
        }
        catch (...)
        {
            cout << "exception happens " << endl;
            throw;
        }
    }
    catch (...)
    {
        cout << "upper level exception" << endl;
    }
}