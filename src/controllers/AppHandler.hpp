#include <SFML/Graphics.hpp>
#include <iostream>

#include "../models/AppNode.hpp"
#include "../models/fps.hpp"

namespace App {
class EventHandler {
 public:
  EventHandler(App::Scene& scene, sf::RenderWindow& window)
      : _scene(scene), _window(window) {}
  void Handle(sf::Event& event) {
    switch (event.type) {
      case sf::Event::MouseButtonPressed: {
        if (event.mouseButton.button == sf::Mouse::Left) {
          std::cout << "left mouse button pressed!" << std::endl;
          _scene.AddElement(sf::Mouse::getPosition(_window));
        }
      }; break;
      default:
        break;
    }
  }

 private:
  App::Scene& _scene;
  sf::RenderWindow& _window;
};
}  // namespace App