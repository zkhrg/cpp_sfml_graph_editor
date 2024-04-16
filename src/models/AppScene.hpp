#include <SFML/Graphics.hpp>
#include <iostream>
#include <unordered_map>

namespace App {
class Scene {
 public:
  sf::CircleShape& GetElementByID(int id) {}
  int AddElement(sf::Vector2i position) {
    sf::CircleShape sc(50);
    position.x -= 50;
    position.y -= 50;
    sc.setFillColor(sf::Color::Red);
    sc.setPosition(sf::Vector2f(position));
    std::cout << position.x << ", " << position.y << "id: " << _current_id
              << std::endl;
    _elements.insert({_current_id, sc});
    _current_id++;
    return _current_id;
  }

  int _current_id;
  // {"id": "element"}
  std::unordered_map<int, sf::CircleShape> _elements;
};
}  // namespace App