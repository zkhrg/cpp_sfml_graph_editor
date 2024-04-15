#include <SFML/Graphics.hpp>
#include <iostream>

#include "../models/fps.hpp"

namespace App {
class EventHandler {
 public:
  EventHandler(sf::RenderWindow& w) : _w(w) {}
  void Handle(sf::Event& event) {
    switch (event.type) {
      case sf::Event::MouseButtonPressed:
        if (event.mouseButton.button == sf::Mouse::Left) {
          std::cout << "left mouse button pressed!" << std::endl;
        }
    }
  }

 private:
  sf::RenderWindow& _w;
};
}  // namespace App