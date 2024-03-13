#include <iostream>
#include <typeinfo>

class B
{
};

class D : public B
{
};

void doFunc(class B &obj)
{
    std::cout << "accept obj" << std::endl;
    if (typeid(obj) == typeid(B))
    {
        std::cout << "is B" << std::endl;
    }
    else
    {
        std::cout << "is D" << std::endl;
    }
};

int main()
{
    B objB;
    D objD;
    doFunc(objB);
}