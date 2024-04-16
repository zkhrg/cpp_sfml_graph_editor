#include <SFML/Graphics.hpp>
#include <iostream>
#include <unordered_map>

class MyClass {
 public:
  void addCircle(int key) {
    sf::CircleShape circle(50.f);
    circle.setFillColor(sf::Color::Red);
    std::cout << map.size() << std::endl;
    map[key] = circle;
  }

  sf::CircleShape& getCircle(int key) { return map[key]; }

 private:
  std::unordered_map<int, sf::CircleShape> map;
};

int main() {
  MyClass myObj;

  myObj.addCircle(1);

  // Access the circle created inside addCircle function
  sf::CircleShape& circleRef = myObj.getCircle(1);

  return 0;
}
