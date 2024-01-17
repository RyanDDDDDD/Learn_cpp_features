#include <iostream>

class Shape {
public:
  virtual double area() = 0;
  // by specifying this function = 0, we tell the compiler this is a pure
  // virtual function, when we call this function on a subclass, using a pointer
  // to parent class, it actually call the subclass function
  virtual ~Shape() = default;
  // need to declare destructor as virtual
};

class Rectangle : public Shape {
public:
  double length, width;
  Rectangle(double l, double w) : length(l), width(w) {}
  double area() { return length * width; }
};

class Circle : public Shape {
public:
  double radius;
  Circle(double r) : radius(r) {}
  double area() { return 3.14159 * radius * radius; }
};

int main() {
  Shape *pShape = new Rectangle(10, 5);
  std::cout << "Area of the rectangle: " << pShape->area() << std::endl;
  delete pShape;
  pShape = new Circle(10);
  std::cout << "Area of the circle: " << pShape->area() << std::endl;
  delete pShape;
  return 0;
}