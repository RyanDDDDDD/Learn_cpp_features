#include <iostream>
#include <optional>
#include <string>

int main () {
    std::optional<std::string> obj{};

    // std::cout << obj.value () << std::endl; // raise exception for trying to access non-existing value
    std::cout << obj.value_or ("hello world") << std::endl;

    std::optional<int> obj1{ 10 };
    std::cout << obj1.value_or (20) << std::endl;
    std::cout << obj1.value () << std::endl;
}