#ifndef ECS_DATATYPESECS_HPP_
#define ECS_DATATYPESECS_HPP_

#include "../InputManager/EventQueue/EventQueue.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

struct SystemData {
  EventQueue event_queue;
  sf::RenderWindow* window;
  int max_screen_width;
  int max_screen_height;
};

struct Pos {
  sf::Vector2f velocity;
  sf::Vector2f position;
};

struct Level {
  float process;
  int level;
};


class SpriteECS {
 public:
  SpriteECS(std::string t_sprite_path) {
    m_texture->loadFromFile(t_sprite_path);
    m_sprite.setTexture(*m_texture);
  }

  sf::Sprite* getSprite() { return &m_sprite; }

  const sf::Texture* getTexture() const { return m_texture; }

  bool loadFromFile(std::string t_filepath) {
    if (!m_texture->loadFromFile(t_filepath)) {
      std::cerr << "Error loading sprite" << std::endl;
      return false;
    }
    m_sprite.setTexture(*m_texture);
    return true;
  }

 private:
  sf::Sprite m_sprite;
  sf::Texture* m_texture = new sf::Texture();

};

#endif  // ECS_DATATYPESECS_HPP_
