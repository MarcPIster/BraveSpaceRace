#include "CombatSystem.hpp"
#include <utility>

CombatSystem::CombatSystem(std::shared_ptr<EntityManager> t_em) {
    m_em = std::move(t_em);
}

CombatSystem::~CombatSystem() {}

void CombatSystem::update() {
    std::vector<EntityID> enemies;
        for (EntityID ent : EntityViewer<AnimationEnemy, int>(*m_em.get())) {
               int *alive = (*m_em.get()).Get<int>(ent);
                 if (*alive >= 1) {
                     enemies.push_back(ent);
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
        if (body->getGlobalBounds().intersects((*m_em.get()).Get<AnimationEnemy>(enemy)->body.getGlobalBounds())) {
            std::cout << "Collision "<< enemy << std::endl;
            *life -= 10;
            int* alive = (*m_em.get()).Get<int>(enemy);
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