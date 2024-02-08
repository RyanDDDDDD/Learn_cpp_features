#include <iostream>
template <class T>
class Test {
    // Data members of test
    public:
        Test() {
            // Initialization of data members
            std::cout << "General template object \n";
        }
        // Other methods of Test
};
template <>
class Test<int> {
    public:
        Test() {
            // Initialization of data members
            std::cout << "Class template specialisation\n";
        }
};
int main() {
    Test<int> a;
    Test<char> b;
    Test<float> c;

    return 0;
}