#include <iostream>

int main () {
    enum byte : unsigned char {};
    byte b{ 0 }; // OK
    // byte c{ -1 };         // ERROR
    byte d = byte{ 1 };   // OK
    byte e = byte{ 256 }; // ERROR, unsigned char has only 256 value(0 - 255)
}