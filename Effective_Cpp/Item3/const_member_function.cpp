#include <iostream>
#include <string>

class A {
public:
    A(std::string str): m_str{ str } {};

    // const specify which member function can be called on a const object
    // static mmeber can be modified in const member function
    const char& operator[](size_t pos) const {
        num++;
        return m_str[pos];
    }

    char& operator[](size_t pos) {
        return m_str[pos];
    }
private:
    std::string m_str;

    static int num;
};

int A::num = 5;

int main() {
    const A obj{"hello world"};
    A obj2{"hello world"};
    obj2[5] = 10;

    std::cout << obj[4] << std::endl;
    std::cout << obj2[6] << std::endl;
}