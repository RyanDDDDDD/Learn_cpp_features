#include <iostream>
#include <vector>

// Template template parameter
template <template <typename> class Container, class T>
void printContainer(const Container<T> &container) {
  for (int i = 0; i < 5; i++) {
    std::cout << container.array[i] << std::endl;
  }
};

// Example of a template class
template <typename T> class MyContainer {
private:
public:
  T array[5];
  MyContainer(T (&arr)[5]) {
    for (int i = 0; i < 5; ++i) {
      array[i] = arr[i];
    }
  }

  const T &operator[](int index) const { return array[index]; }
};

int main() {
  int arr[] = {1, 2, 3, 4, 5};

  // Using the template template parameter
  printContainer<MyContainer, int>(MyContainer<int>(arr));

  std::cout << "=====" << std::endl;

  // using template auto deduction
  printContainer(MyContainer<int>(arr));

  return 0;
}
