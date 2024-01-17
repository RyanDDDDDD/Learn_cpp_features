#include <iostream>

namespace A {
namespace B {
namespace C {
int i = 10;
}
} // namespace B
} // namespace A

int main () {
    std::cout << A::B::C::i << std::endl;
}