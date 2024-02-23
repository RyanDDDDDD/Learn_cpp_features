#include <iostream>
#include <string>

class A {
public:
    A(std::string str): m_str{ str } {
        std::cout << "init A" << std::endl;
    };

    const char& operator[](size_t pos) const {
        std::cout << "call const" << std::endl;
        return m_str[pos];
    }

    char& operator[](size_t pos) {
        std::cout << "call non const" << std::endl;
        return const_cast<char&>(
            static_cast<const A&>(*this)[pos]
        );
    }
private:
    std::string m_str;
};


int main() {
    const A obj{"hello world"};
    A obj2{"hello world"};

    std::cout << obj[4] << std::endl;
    std::cout << obj2[6] << std::endl;
}