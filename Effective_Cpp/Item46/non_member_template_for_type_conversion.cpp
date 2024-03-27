#include <iostream>

template <typename T> class Rational {
    public:
    Rational (const T& par1 = 10, const T& par2 = 5) {
    }
};

template <typename T>
const Rational<T> operator* (const Rational<T>& rhs, const Rational<T>& lhs) {

    return Rational<T> ();
};

int main () {
    Rational<int> r1;

    // error, implicit type conversion is not available during template
    // deduction. Such conversion only happens before functional call

    // Rational<int> r2 = r1 * 20;

    Rational<int> r2 = r1 * Rational<int> (20);
}
