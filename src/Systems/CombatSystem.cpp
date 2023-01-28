#include "CombatSystem.hpp"
#include <utility>

CombatSystem::CombatSystem(std::shared_ptr<EntityManager> t_em) {
    m_em = std::move(t_em);
}

CombatSystem::~CombatSystem() {}

void CombatSystem::update() {
    std::vector<EntityID> enemies;
    for (EntityID ent : EntityViewer<sf::RectangleShape, Pos, float, int, Timer>(*m_em.get())) {
      Timer *timer = (*m_em.get()).Get<Timer>(ent);
      int* alive =  (*m_em.get()).Get<int>(ent);
      if (timer->checkStartTime()){
        if (*alive == 0) {
          *alive = 1;
        }
      }
      if (*alive >= 1) {
        enemies.push_back(ent);
        continue ;
      }
    }
    int i = 0;
    sf::CircleShape* body;
    int *life;
    for (EntityID ent : EntityViewer<sf::CircleShape, Level>(*m_em.get())) {
        body = (*m_em.get()).Get<sf::CircleShape>(ent);
        life = (*m_em.get()).Get<int>(ent);
    }
    for (auto enemy : enemies) {
        if (body->getGlobalBounds().intersects((*m_em.get()).Get<sf::RectangleShape>(enemy)->getGlobalBounds())) {
            std::cout << "Collision "<< i << std::endl;
            *life -= 10;
            int* alive = (*m_em.get()).Get<int>(enemy);
            //set live to -1 to despawn, 0 to respawn
            *alive = -1;
        }
        i++;
    }
    if (*life <= 0) {
        std::cout << "You died" << std::endl;
    }
}

void CombatSystem::updateData(SystemData &t_data) {
}