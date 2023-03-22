#ifndef BRAVESPACERACE_SHOPSYSTEM_HPP
#define BRAVESPACERACE_SHOPSYSTEM_HPP
#include "../ECS/ISystem.hpp"
#include "../ECS/DataTypesECS.hpp"
#include "../Hud.hpp"
#include "../Systems/CombatSystem.hpp"
#include "../Shop/Shop.hpp"

class ShopSystem : public ISystem {
public:
  ShopSystem(std::shared_ptr<EntityManager> t_em);
  ~ShopSystem();

  void update();
  void updateData(SystemData &t_data);
private:
  sf::Window* m_window;
};

#endif // BRAVESPACERACE_SHOPSYSTEM_HPP
