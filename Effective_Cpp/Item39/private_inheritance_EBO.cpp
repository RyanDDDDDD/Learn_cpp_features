#include <iostream>

class B {};

class PuD : public B {
    int num;
};

class PrD : private B {
    int num;
};

// composition of B
class CP {
    int num;
    B obj;
};

int main () {
    std::cout << sizeof (B) << std::endl;

    // due to the compiler optimization: EBO (empty base optimization),
    // the base class takes empty space in inheritance
    std::cout << sizeof (PuD) << std::endl;
    std::cout << sizeof (PrD) << std::endl;

    // Empty base still take 1 byte by silently inserting a char into base class
    // due to memroy alignment, the size of CP needs to be resized to 8 bytes
    std::cout << sizeof (CP) << std::endl;
}