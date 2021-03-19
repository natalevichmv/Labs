#include "containers.h"
#include <cmath>
#include <string>

void CheckEqual(double left, double right) {
  if (fabs(left - right) > 1e-6) {
    throw std::runtime_error("Wrong answer: " + to_string(left));
  }
}

int main() {
  Triangle* triangle = new Triangle({{0, 0}, {0, 1}, {1, 0}});
  Polygon* polygon = new Polygon({{0, 0}, {0, 1}, {1, 1}, {1, 0}});

  {  // inheritance test 
    static_cast<Shape*>(new Square(5));
    static_cast<Shape*>(new Circle(5));
    static_cast<Shape*>(polygon);
    static_cast<Shape*>(triangle);
    static_cast<Polygon*>(triangle);
  }

  {  // area test
    CheckEqual(Square(2.5).Area(), 6.25);
    CheckEqual(Circle(1).Area(), acos(-1.0));
    CheckEqual(triangle->Area(), 0.5);
    CheckEqual(polygon->Area(), 1.0);
  }

  {  // perimeter test
    CheckEqual(Square(1.5).Perimeter(), 6);
    CheckEqual(Circle(2).Perimeter(), 4 * acos(-1.0));
    CheckEqual(triangle->Perimeter(), 2 + sqrt(2));
    CheckEqual(polygon->Perimeter(), 4);
  }

  {  // test that triangle throws exception in case of wrong number of vertices
    try {
      try { 
        Triangle({{0, 0}, {0, 1}});
      } catch (...) {
        throw std::runtime_error();
      }
      throw "No exception for triangle";
    } catch (const std::runtime_error&) {
    }
  }
}