#include <iostream>
#include <string>
#include <variant>

int main () {
    std::variant<int, float, std::string> v{ 12 };

    // std::cout << std::get<float>(v) << std::endl; // raise exception
    // std::cout << std::get<std::string>(v) << std::endl; // raise exception
    std::cout << std::get<int> (v) << std::endl; // raise exception
}