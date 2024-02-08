#include <iostream>

// template needs to be defined in .hpp file, because compiler needs to know the template 
// definition at compile time (before linking phase), otherwise the template cannot be instantiated
// only the function that are called will be instantiated
// static member also needs to be defined in .hpp file
template <typename T>
void fun(T a) {
    // argument replacement (T) happens at compile time, not run time
    std::cout << "The main template fun(): "
    << a << std::endl;
}

template<> // may be skipped, but prefer overloads
void fun(int a) {
    std::cout << "Explicit specialisation for int type: "
    << a << std::endl;
}

int main() {
    fun<char>('a');
    fun<int>(10);
    fun<float>(10.14);
}