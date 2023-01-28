#ifndef CLIENT_SRC_SYSTEMS_MOVEMENTSYSTEM_HPP_
#define CLIENT_SRC_SYSTEMS_MOVEMENTSYSTEM_HPP_

#include "../ECS/ISystem.hpp"
#include "../ECS/DataTypesECS.hpp"
#include "../Hud.hpp"
#include "../Systems/CombatSystem.hpp"

#include "math.h"


class MovementSystem : public ISystem {
 public:
  MovementSystem(std::shared_ptr<EntityManager> t_em);
  ~MovementSystem();

  void update();
  void updateData(SystemData &t_data);
  void keepPlayerInsideScreen(sf::Vector2f& t_position, const sf::Vector2f& t_size);

 private:
  EventQueue m_event_queue;
  int m_max_width;
  int m_max_height;
  sf::Window* m_window;

  sf::Vector2f moveEnemies(sf::Vector2f current_position, sf::Vector2f target_position, float speed);
  void movePlanet(sf::CircleShape *body, const sf::Vector2i &mouse_pos) const;
  void checkHUD();
};

#endif  // CLIENT_SRC_SYSTEMS_MOVEMENTSYSTEM_HPP_
