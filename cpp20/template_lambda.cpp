#include <iostream>
#include <vector>

int main() {
   auto f = []<typename T>(std::vector<T> v) {
        for (auto n : v) {
            std::cout << n << std::endl;
        }
   };

   std::vector<int> num{1, 2, 3, 4, 5};

   f(num);

}
