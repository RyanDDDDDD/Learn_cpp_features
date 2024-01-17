#include <iostream>
#include <iterator>
#include <vector>

template <typename T> struct container {
    container (T t) {
        vec = { t };
    };

    template <typename Iter> container (Iter beg, Iter end) {
        vec = { beg, end };
    };

    std::vector<T> vec;
};

// deduction guide to tell compiler how to initialize template class
template <typename Iter>
container (Iter b, Iter e)
-> container<typename std::iterator_traits<Iter>::value_type>;

int main () {
    container a{ 7 }; // OK: deduces container<int>

    std::vector<double> v{ 1.0, 2.0, 3.0 };

    auto b = container{ v.begin (), v.end () }; // OK: deduces container<double>
    auto vec = b.vec;
    for (auto n : vec) {
        std::cout << n << std::endl;
    }

    // container c{ 5, 6 }; // ERROR: std::iterator_traits<int>::value_type is not a type
}