#include <iostream>
#include <compare>

struct Point {
  int x, y;

  std::strong_ordering operator<=>(const Point&) const = default;
};

int main() {
  Point p1{3, 2}, p2{2, 3};

  if (p1 < p2) {
    std::cout << "p1 is less than p2\n";
  }

  auto result = (p1 <=> p2);
  if (result < 0) {
    std::cout << "p1 is less than p2\n";
  } else if (result == 0) {
    std::cout << "p1 is equal to p2\n";
  } else {
    std::cout << "p1 is greater than p2\n";
  }
}