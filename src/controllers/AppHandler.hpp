#include <SFML/Graphics.hpp>
#include <iostream>

namespace App {
class EventHandler {
 public:
  EventHandler(sf::RenderWindow& w) : _w(w) {}
  void Handle(sf::Event& event) {
    if (event.type == sf::Event::MouseButtonPressed &&
        event.mouseButton.button == sf::Mouse::Left) {
      // Получаем позицию курсора мыши относительно окна
      sf::Vector2i mousePosition = sf::Mouse::getPosition(_w);
      std::cout << "Mouse position: " << mousePosition.x << ", "
                << mousePosition.y << std::endl;
    }
  }

 private:
  sf::RenderWindow& _w;
};
}  // namespace App