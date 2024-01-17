#include <iostream>
#include <string>
#include <vector>

template <typename... T> auto sum (T... numbers) {
    // unary right fold (pack + op)
    return (numbers + ...);
}

template <typename... T> auto concate (T... strings) {
    // binary left fold (init + op + pack)
    return ("hello " + ... + strings);
}

int main () {
    std::cout << sum (1, 2, 3, 4) << '\n';

    std::cout << concate (std::string ("hello "), "world ", "world") << '\n';

    return 0;
}