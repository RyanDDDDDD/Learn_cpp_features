#include <iostream>

using namespace std;

class A
{
public:
    int foo = 10;
};

class B : public A
{
public:
    int bar = 20;
};

main()
{
    B b;

    A a = b;
    // information of b get lost after assignment
}