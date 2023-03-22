#include "initGame.hpp"

void createUnit(EntityManager& t_entity_manager, sf::Vector2i t_window_size, UnitClass t_unit_class) {
  EntityID unit = t_entity_manager.createNewEntity();
  SpriteECS unit_sprite = SpriteECS("../src/Sprites/Units/astroids.png");

  sf::RectangleShape body;
  body.setSize(sf::Vector2f(50, 50));
  body.setTexture(unit_sprite.getTexture());
  //body.setPosition(t_pos);
  int *life = t_entity_manager.Assign<int>(unit, 1);
  float* speed = t_entity_manager.Assign<float>(unit, 5);
  //Pos *pos = t_entity_manager.Assign<Pos>(unit, Pos{ t_pos, t_pos});
  Animation unit_animation = {
      body, 0,0,0, 0,0,0,0,0,0,0, true
  };
  Animation *animation = t_entity_manager.Assign<Animation>(unit, unit_animation);
}

