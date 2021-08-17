#include "circle.hpp"

const double PI = 3.141592;

Circle::Circle(double radius_) : radius(radius_) {}

int Circle::get_area() const {
  return PI * radius * radius;
}

double Circle::get_circumference() const {
  double circumference = 2.0 * PI * radius;
  return circumference;
}
