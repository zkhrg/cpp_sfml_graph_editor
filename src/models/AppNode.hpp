#include <SFML/Graphics.hpp>

namespace App {
class Node {
 public:
  Node(sf::Vector2u v2u) : _cs(10, 40) { _cs.setPosition({200.0, 200.0}); }
  void Print() {}

  sf::CircleShape _cs;
};
}  // namespace App