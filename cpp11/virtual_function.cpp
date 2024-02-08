#include <iostream>

using namespace std;

// https://stackoverflow.com/questions/39932391/should-i-use-virtual-override-or-both-keywords
// virtual is generally used for declaring the first member function as virtual function, don't need to specify
// for the overwritten function in derived class
// by declaring function as virtual function, compiler will perform dynamic despatching when exectuing code
// otherwise perform static despatching

// override is used for overriding derived class
// final is used for marking an override as unoverrideable

class Base
{
public:
    virtual void print()
    {
        cout << "Base class" << endl;
    }

    virtual ~Base() = default;
};

class Derived : public Base
{
public:
    void print() override
    // is fine not using override to declare the virtual function
    // but it can help compiler to detect whether we override the
    // function we want
    {
        cout << "Derived class" << endl;
    }
    virtual ~Derived() = default;
};

class Final : public Derived
{
public:
    void print() final
    {
        cout << "Final class" << endl;
    }
    virtual ~Final() = default;
};

int main()
{
    Base *obj = new Base();
    obj->print();

    delete obj;

    obj = new Derived();
    obj->print();

    delete obj;

    obj = new Final();
    obj->print();
}