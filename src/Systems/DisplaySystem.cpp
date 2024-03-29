#include "DisplaySystem.hpp"
#include <SFML/Graphics/Sprite.hpp>

DisplaySystem::DisplaySystem(std::shared_ptr<EntityManager> t_em, sf::RenderWindow &t_window) {
    m_em = t_em;
    m_window = &t_window;
    m_mouseCircle = new sf::CircleShape(10);
    m_mouseCircle->setFillColor(sf::Color::Transparent);
    m_mouseCircle->setOutlineColor(sf::Color::Red);
    m_mouseCircle->setOutlineThickness(2);
    m_mouseCircle->setOrigin(10, 10);

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
    // Draw all entities with a sprite
    for (EntityID ent : EntityViewer<SpriteECS>(*m_em.get()))
    {
      SpriteECS* sprite = (*m_em.get()).Get<SpriteECS>(ent);
      m_window->draw(*(sprite)->getSprite());
    }

    for (EntityID ent : EntityViewer<sf::CircleShape, PlayerRange>(*m_em.get()))
    {
      sf::CircleShape* body = (*m_em.get()).Get<sf::CircleShape>(ent);
      PlayerRange* range = (*m_em.get()).Get<PlayerRange>(ent);
      m_window->draw(*body);
      if (range->active) {
        sf::CircleShape rangeCircle;
        rangeCircle.setRadius(range->current);
        rangeCircle.setOrigin(range->current, range->current);
        rangeCircle.setPosition(body->getPosition());
        rangeCircle.setFillColor(sf::Color(0, 0, 0, 0));
        rangeCircle.setOutlineColor(sf::Color::Red);
        rangeCircle.setOutlineThickness(1);
        m_window->draw(rangeCircle);
      }
    }

    //TODO: Draw all units here!

    displayEnemies();
    displayHUD();
    m_mouseCircle->setPosition(sf::Mouse::getPosition(*m_window).x, sf::Mouse::getPosition(*m_window).y);

    m_window->draw(*m_mouseCircle);
    m_window->display();
}

void DisplaySystem::displayEnemies() {
    for (EntityID ent : EntityViewer<AnimationEnemy, Pos, float, int>(*m_em.get()))
    {
      AnimationEnemy * animation = (*m_em.get()).Get<AnimationEnemy>(ent);

      int *alive = (*m_em.get()).Get<int>(ent);
        if (*alive >= 1) {
          m_window->draw((animation)->body);
        }
    }
}

void DisplaySystem::updateData(SystemData &t_data) {}

void DisplaySystem::displayHUD() {
    for (EntityID ent : EntityViewer<HudData>(*m_em.get())) {
        HudData* hudData = (*m_em.get()).Get<HudData>(ent);
        m_hud->setHudStatus(hudData->active);
    }
    int *live;
    Shop* shop;
    for (EntityID ent : EntityViewer<sf::CircleShape, int, Shop, PlayerRange>(*m_em.get())) {
        live = (*m_em.get()).Get<int>(ent);
        shop = (*m_em.get()).Get<Shop>(ent);
        break ;
    }
    if (m_hud->getHudStatus()) {
          for (auto card: shop->getCards()) {
            m_window->draw(*card.card);
            m_window->draw(*card.text);
          }
          m_window->draw(*(shop)->getMBackground());
    }
    m_window->draw(*(m_hud)->getMBackground());
    m_window->draw(*(m_hud)->getMHeart(*live));
    m_hud->updateLives(*live);
    m_window->draw(*(m_hud)->getMLive());

}
