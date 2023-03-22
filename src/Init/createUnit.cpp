#include "initGame.hpp"

void createStarShip(EntityManager& t_entity_manager, sf::Vector2i t_window_size, sf::Vector2f t_pos)
{
  EntityID unit = t_entity_manager.createNewEntity();
  SpriteECS unit_sprite = SpriteECS("../src/Sprites/Units/starship_blue.png");
  sf::RectangleShape body;
  body.setSize(sf::Vector2f(90, 90));
  body.setTexture(unit_sprite.getTexture());
  body.setPosition(t_pos);
  int *life = t_entity_manager.Assign<int>(unit, 100);
  float* speed = t_entity_manager.Assign<float>(unit, 7);
  Pos *pos = t_entity_manager.Assign<Pos>(unit, Pos{ t_pos, t_pos});
  AnimationEnemy unit_animation = {
      body, 0,0,0, 0,0,0,0,0,0,0, true
  };
  AnimationEnemy *animation = t_entity_manager.Assign<AnimationEnemy>(unit, unit_animation);
  std::cout << "Unit created" << unit << " as starship"<<  std::endl;
}

void createUnit(EntityManager& t_entity_manager, sf::Vector2i t_window_size,
                UnitClass t_unit_class)
{
  switch (t_unit_class) {
  case STARSHIP:
    createStarShip(t_entity_manager, t_window_size, sf::Vector2f(t_window_size.x / 2, t_window_size.y / 2));
    break;
  case ASTROIDSHOOTER:
    break;
  }

}

