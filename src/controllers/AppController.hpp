#pragma once

#include <SFML/Graphics.hpp>

#include "../models/AppModel.hpp"
#include "../models/AppScene.hpp"
#include "../views/AppView.hpp"
#include "AppHandler.hpp"

namespace App {
class AppLoop {
 public:
  AppLoop(sf::RenderWindow& w)
      : _window(w), _scene(), _event_handler(_scene, w), _fps() {}
  void Start() {
    while (_window.isOpen()) {
      for (sf::Event event{}; _window.pollEvent(event);) {
        if (event.type == sf::Event::Closed) {
          _window.close();
        }
        _event_handler.Handle(event);
      }
      Update();
    }
  }

  void Update() {
    _window.clear();
    // TODO: separate logic module for this
    _fps.update();
    //-----------------------------------------------
    std::unordered_map<int, sf::CircleShape>::iterator it =
        _scene._elements.begin();
    while (it != _scene._elements.end()) {
      _window.draw(it->second);
      it++;
    }
    //-----------------------------------------------
    _window.setTitle(std::to_string(_fps.getFPS()));
    // END TODO
    _window.display();
  }

 private:
  sf::RenderWindow& _window;
  App::EventHandler _event_handler;
  App::FPS _fps;
  App::Scene _scene;
};
}  // namespace App