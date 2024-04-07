#include <iostream>
#include <type_traits>

class A {};

class B {};

int main () {
    A a;
    B b;
    // perform compilation-time type check
    std::cout << std::is_same<A, B>::value << std::endl;
    std::cout << std::is_same<int, int>::value << std::endl;
}