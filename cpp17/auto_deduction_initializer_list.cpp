#include <iostream>

int main () {
    // auto x0{ 1, 2, 3 }; // error: not a single element
    auto x1{ std::initializer_list<int>{ 1, 2, 3 } };
    auto x2 = { 1, 2, 3 }; // x2 is std::initializer_list<int>
    auto x3{ 3 }; // x3 is int, before c++17, it would be deduced as std::initializer_list<int>
    auto x4{ 3.0 }; // x4 is double
}