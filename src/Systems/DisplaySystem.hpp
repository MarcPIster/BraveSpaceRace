#ifndef CLIENT_SRC_SYSTEMS_IDISPLAY_HPP_
#define CLIENT_SRC_SYSTEMS_IDISPLAY_HPP_

#include "../ECS/ISystem.hpp"
#include "../Hud.hpp"
#include "../Systems/CombatSystem.hpp"
#include "../Shop/Shop.hpp"


class DisplaySystem : public ISystem {
 public:
  DisplaySystem(std::shared_ptr<EntityManager> t_em, sf::RenderWindow &t_window);
  ~DisplaySystem();

  virtual void update();
  virtual void updateData(SystemData &t_data);

  void displayHUD();

  private:
   sf::RenderWindow* m_window;
   Hud* m_hud;
   void displayEnemies();
   void animateAstroids(EntityID ent, sf::RectangleShape *body) const;
};

#endif  // CLIENT_SRC_SYSTEMS_IDISPLAY_HPP_
