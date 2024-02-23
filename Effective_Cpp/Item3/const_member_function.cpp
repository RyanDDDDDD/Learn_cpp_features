#include <iostream>
#include <string>

class A {
public:
    A(std::string str): m_str{ str } {};

    // const specify which member function can be called on a const object
    const char& operator[](size_t pos) const {
        return m_str[pos];
    }

    char& operator[](size_t pos) {
        return m_str[pos];
    }
private:
    std::string m_str;
};

int main() {
    const A obj{"hello world"};
    A obj2{"hello world"};
    obj2[5] = 10;

    std::cout << obj[4] << std::endl;
    std::cout << obj2[6] << std::endl;
}