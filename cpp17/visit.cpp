#include <iostream>
#include <variant>
#include <vector>
#include <string>

void func1(int n)
{
    std::cout << "This is num : " << n << std::endl;
}

void func1(double n)
{
    std::cout << "This is double : " << n << std::endl;
}

void func1(std::string n)
{
    std::cout << "This is string : " << n << std::endl;
}

int main()
{
    std::vector<std::variant<int, double, std::string>> vec{1, 3.14, "hello world"};

    for (auto &arg : vec)
    {
        // visit will do the runtime conversion on variant to the real type it stores, and call the matching function
        std::visit([](auto &&arg)
                   { func1(arg); }, arg);
    }
}