#pragma once

#include <SFML/Graphics.hpp>

#include "../models/AppModel.hpp"
#include "../views/AppView.hpp"
#include "AppHandler.hpp"

namespace App {
class AppLoop {
 public:
  AppLoop(sf::RenderWindow& w) : _w(w), _eh(w), _fps() {}
  void Start() {
    while (_w.isOpen()) {
      for (sf::Event event{}; _w.pollEvent(event);) {
        if (event.type == sf::Event::Closed) {
          _w.close();
        }
        _eh.Handle(event);
      }
      Update();
      _w.clear();
      _w.display();
    }
  }

  void Update() {
    _fps.update();
    _w.setTitle(std::to_string(_fps.getFPS()));
  }

 private:
  sf::RenderWindow& _w;
  App::EventHandler _eh;
  App::FPS _fps;
};
}  // namespace App