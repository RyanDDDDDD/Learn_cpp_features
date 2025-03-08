#include <iostream>
#include <vector>
#include <string>

struct foo {
    template <typename T>
    explicit(!std::is_integral_v<T>) foo(T) {};
};

int main() {
  foo a = 123;

//   foo b = "123";
//   foo c = std::string("123");
}
