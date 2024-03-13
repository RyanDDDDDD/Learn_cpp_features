#include <iostream>

class B
{
public:
    virtual void mf1() = 0;

    virtual void mf1(int)
    {
        std::cout << "get int" << std::endl;
    };
};

class D : public B
{
public:
    // to make method from B visible for compiler
    // using B::mf1;

    D() = default;

    virtual void mf1()
    {
        std::cout << "get default" << std::endl;
    }
};

int main()
{
    D obj;
    obj.mf1();
    // D::mf1 exists, it hides B::mf1(int) and compiler would not get further to the base class
    // obj.mf1(1);

    // we have to explictly call B::mf1 to let compiler know
    obj.B::mf1(1);
}