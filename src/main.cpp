#include "hub.hpp"

int main() {
  sf::RenderWindow window{{800u, 600u}, "sfml project", sf::Style::Close};
  App::AppLoop app_loop(window);
  app_loop.Start();
}