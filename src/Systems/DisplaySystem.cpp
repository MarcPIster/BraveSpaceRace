#include "DisplaySystem.hpp"

DisplaySystem::DisplaySystem(std::shared_ptr<EntityManager> t_em, sf::RenderWindow &t_window) {
    m_em = t_em;
    m_window = &t_window;
    for (EntityID ent : EntityViewer<HudData>(*m_em.get())) {
        HudData* hudData = (*m_em.get()).Get<HudData>(ent);
        m_hud = new Hud(m_window->getSize(), hudData->active);
    }
}

DisplaySystem::~DisplaySystem() {
    delete m_hud;
}

void DisplaySystem::update() {
    m_window->clear();
    for (EntityID ent : EntityViewer<SpriteECS>(*m_em.get()))
    {
      SpriteECS* sprite = (*m_em.get()).Get<SpriteECS>(ent);
      m_window->draw(*(sprite)->getSprite());
    }

    for (EntityID ent : EntityViewer<sf::CircleShape>(*m_em.get()))
    {
      sf::CircleShape* body = (*m_em.get()).Get<sf::CircleShape>(ent);
      m_window->draw(*body);
    }

    for (EntityID ent : EntityViewer<sf::RectangleShape, Pos, float, int>(*m_em.get()))
    {
      sf::RectangleShape* body = (*m_em.get()).Get<sf::RectangleShape>(ent);
      int *alive = (*m_em.get()).Get<int>(ent);
        if (*alive == 1) {
            m_window->draw(*body);
        }
    }


    displayHUD();
    m_window->display();
}

void DisplaySystem::updateData(SystemData &t_data) {}

void DisplaySystem::displayHUD() {
for (EntityID ent : EntityViewer<HudData>(*m_em.get())) {
        HudData* hudData = (*m_em.get()).Get<HudData>(ent);
        m_hud->setHudStatus(hudData->active);
    }
    if (m_hud->getHudStatus()) {
      m_window->draw(*(m_hud)->getMBackground());
      m_window->draw(*(m_hud)->getMHeart());
    }
}