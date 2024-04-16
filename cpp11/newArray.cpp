#include <iostream>

class A
{
public:
    A()
    {
        std::cout << "constructed" << std::endl;
    }

    ~A()
    {
        std::cout << "de-constructed" << std::endl;
    }

private:
    int mem;
};

A *getArray()
{
    return new A[5]();
}

int main()
{
    A *arr = getArray();

    delete[] arr;

    // error, can only delete one element
    //  delete arr;
}