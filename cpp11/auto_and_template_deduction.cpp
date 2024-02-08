#include <iostream>

using namespace std;

template <typename T> void func (T x) {
    cout << x << endl;
}

template <typename T> void func (std::initializer_list<T> x) {
    cout << "get initializer list" << endl;
    // cout << x << endl;
}

int main () {
    auto x = { 1, 2, 3 };
    cout << typeid (x).name () << endl;
    func (x);
}