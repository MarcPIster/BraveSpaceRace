#include "ShopSystem.hpp"

void createStarShip(EntityManager& t_entity_manager, sf::Vector2i t_window_size, sf::Vector2f t_pos);

ShopSystem::ShopSystem(std::shared_ptr<EntityManager> t_em) {
  m_em = t_em;
}

ShopSystem::~ShopSystem() {
}

void ShopSystem::update() {
  int *live;
  Shop* shop;
  for (EntityID ent : EntityViewer<sf::CircleShape, int, Shop, PlayerRange>(*m_em.get())) {
    live = (*m_em.get()).Get<int>(ent);
    shop = (*m_em.get()).Get<Shop>(ent);
    if (*live < 1)
      return ;
    std::vector<UnitClass> spawnQueue = shop->getSpawnQueue();
    if (shop->getSpawnQueue().size() > 0) {
      for (int i = 0; i < spawnQueue.size(); i++) {
        const sf::Vector2i size = {static_cast<int>(m_window->getSize().x), static_cast<int>(m_window->getSize().y)};
        if (spawnQueue[i] == UnitClass::STARSHIP)
          createStarShip(*m_em.get(), size, sf::Vector2f(600, 100));
      }
      shop->clearSpawnQueue();
    }
    break ;
  }
}

void ShopSystem::updateData(SystemData &t_data) {
  m_window = t_data.window;
}

