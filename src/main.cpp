#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
  auto window = sf::RenderWindow{{800u, 600u}, "CMake SFML Project"};

  window.setFramerateLimit(144);
  sf::Clock clock;

  sf::CircleShape shape(50);
  // set the shape color to green
  shape.setFillColor(sf::Color(100, 100, 100));
  shape.setPosition(200, 200);

  std::vector<sf::Color> colors = {sf::Color::Red, sf::Color::Green,
                                   sf::Color::Blue, sf::Color::Yellow,
                                   sf::Color::Magenta};
  size_t currentColorIndex = 0;

  while (window.isOpen()) {
    auto event = sf::Event{};
    for (; window.pollEvent(event);) {
      if (event.type == sf::Event::MouseButtonPressed &&
          event.mouseButton.button == sf::Mouse::Left) {
        // Получаем позицию курсора мыши относительно окна
        sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
        std::cout << "Mouse position: " << mousePosition.x << ", "
                  << mousePosition.y << std::endl;
      }
      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }
    window.clear();
    if (clock.getElapsedTime().asSeconds() >= 5.0f) {
      shape.setFillColor(colors[currentColorIndex]);
      currentColorIndex = (currentColorIndex + 1) % colors.size();
      clock.restart();
    }

    window.draw(shape);
    window.display();
  }
}