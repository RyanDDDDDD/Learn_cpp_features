#include <iostream>

[[nodiscard]] int getValue () {
    return 10;
}

int main () {
    getValue (); // warning: ignoring return value of function declared with 'nodiscard' attribute [-Wunused-result]
}
