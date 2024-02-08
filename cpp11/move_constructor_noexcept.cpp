#include <iostream>
#include <vector>

// https://gieseanw.wordpress.com/2020/08/28/friendly-reminder-to-mark-your-move-constructors-noexcept/
using namespace std;

class MyClass
{
    public:
        MyClass(int i)
        {
            std::cout << "normal construcor" << std::endl;
        if (i == 3)
            throw std::invalid_argument("How dare you");
        }
        MyClass(const MyClass&)
        {
            std::cout << "Copied\n";
        }
        MyClass(MyClass&&) noexcept
        // by default, for strong exception guarantees, it will use copy constructor to resize the vector, we can always roll back to 
        // previous state if copy constructor throw an exception during resizing
        // but in terms of using move constructor, there is no way to restore if an exception is thrown
        // by specifying as noexcept, we can force compiler to use move constructor when resizing the vector 
        // (even though it may still throw an exception)
        {
            std::cout << "Moved\n";
        }
};
 
int main()
{
    std::vector<MyClass> vec;
    vec.emplace_back(1);
    // resizing occur when emplace_back(2), we first construct the new vector using Myclass(int i), for 1,
    // then move Myclass(2) using move constructor
    vec.emplace_back(2);
}