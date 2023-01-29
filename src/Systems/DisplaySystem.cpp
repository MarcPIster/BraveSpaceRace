#include "DisplaySystem.hpp"

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>


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
    // Draw all entities with a sprite
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

    displayEnemies();
    displayHUD();
    m_window->display();
}

void DisplaySystem::displayEnemies() {
    for (EntityID ent : EntityViewer<sf::RectangleShape, Pos, float, int, double>(*m_em.get()))
    {
      sf::RectangleShape* body = (*m_em.get()).Get<sf::RectangleShape>(ent);

      int *alive = (*m_em.get()).Get<int>(ent);
        if (*alive >= 1) {
          animateAstroids(ent, body);
          m_window->draw(*body);
        }
    }
}

void DisplaySystem::animateAstroids(EntityID ent, sf::RectangleShape *body) const {
    double *currentFrame = (*m_em.get()).Get<double>(ent);
    Timer *timer = (*m_em.get()).Get<Timer>(ent);
    if (timer->returnTime() > 0.05) {
        *currentFrame += 1;
        timer->restartTimer();
    }

    if (*currentFrame < 8) {
      body->setTextureRect(sf::IntRect(125 * (int)*currentFrame, 0, 125, 125));
    } else if (*currentFrame < 16) {
      body->setTextureRect(sf::IntRect(125 * ((int)*currentFrame - 8), 125, 125, 125));
    } else if (*currentFrame < 24) {
      body->setTextureRect(sf::IntRect(125 * ((int)*currentFrame - 16), 250, 125, 125));
    } else if (*currentFrame < 32) {
      body->setTextureRect(sf::IntRect(125 * ((int)*currentFrame - 24), 375, 125, 125));
    } else if (*currentFrame < 40) {
      body->setTextureRect(sf::IntRect(125 * ((int)*currentFrame - 32), 375, 125, 125));
    } else if (*currentFrame < 48) {
      body->setTextureRect(sf::IntRect(125 * ((int)*currentFrame - 40), 375, 125, 125));
    } else if (*currentFrame < 56) {
      body->setTextureRect(sf::IntRect(125 * ((int)*currentFrame - 48), 375, 125, 125));
    } else if (*currentFrame < 64) {
      body->setTextureRect(sf::IntRect(125 * ((int)*currentFrame - 56), 375, 125, 125));
    } else {
      *currentFrame = 0;
    }
}

void DisplaySystem::updateData(SystemData &t_data) {}

void DisplaySystem::displayHUD()
{
for (EntityID ent : EntityViewer<HudData>(*m_em.get())) {
        HudData* hudData = (*m_em.get()).Get<HudData>(ent);
        m_hud->setHudStatus(hudData->active);
    }
    if (m_hud->getHudStatus()) {
        int *live;
        for (EntityID ent : EntityViewer<sf::CircleShape, int>(*m_em.get())) {
          live = (*m_em.get()).Get<int>(ent);
          break ;
        }
          m_window->draw(*(m_hud)->getMBackground());
          m_window->draw(*(m_hud)->getMHeart(*live));
        }
}
