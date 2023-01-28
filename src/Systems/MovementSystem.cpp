#include "MovementSystem.hpp"

void MovementSystem::keepPlayerInsideScreen(sf::Vector2f& t_position, const sf::Vector2f& t_size) {
  if (t_position.x - t_size.x <= 0) {
    t_position.x = t_size.x;
  } else if (t_position.x >= m_max_width) {
    t_position.x = m_max_width;
  }
  if (t_position.y < 0) {
    t_position.y = 0;
  } else if (t_position.y + t_size.y  >= m_max_height) {
    t_position.y = m_max_height - t_size.y;
  }
}

MovementSystem::MovementSystem(std::shared_ptr<EntityManager> t_em) {
  m_em = t_em;
}

MovementSystem::~MovementSystem() {}

void MovementSystem::updateData(SystemData &t_data) {
  m_event_queue = t_data.event_queue;
  m_max_height = t_data.max_screen_height;
  m_max_width = t_data.max_screen_width;
  m_window = t_data.window;
}

void MovementSystem::update() {
  for (EntityID ent : EntityViewer<sf::CircleShape>(*m_em.get())) {
    sf::CircleShape* body = (*m_em.get()).Get<sf::CircleShape>(ent);

    if (m_event_queue.checkIfKeyPressed(sf::Mouse::Left)) {
      movePlanet(body, sf::Mouse::getPosition(*m_window));
    }
    if (m_event_queue.checkIfKeyPressed(sf::Mouse::Right)) {
      ;
    }
  }

  sf::Vector2f player_position;

  for (EntityID ent : EntityViewer<sf::CircleShape, Level>(*m_em.get())) {
    player_position = (*m_em.get()).Get<sf::CircleShape>(ent)->getPosition();
  }

  for (EntityID ent : EntityViewer<sf::RectangleShape, Pos, float>(*m_em.get())) {
    sf::RectangleShape* enemy = (*m_em.get()).Get<sf::RectangleShape>(ent);

    Pos *pos = (*m_em.get()).Get<Pos>(ent);
    float *speed = (*m_em.get()).Get<float>(ent);
    pos->position = moveEnemies(pos->position, player_position, *speed);
    enemy->setPosition(pos->position);
  }

  checkHUD();


}
void MovementSystem::checkHUD() {
  for (EntityID ent : EntityViewer<HudData>(*m_em.get())) {
    HudData* hudData = (*m_em.get()).Get<HudData>(ent);
    if (m_event_queue.checkIfKeyPressed(sf::Keyboard::K)) {
      hudData->active = !hudData->active;
      std::cout << "Set hud status to: " << hudData->active << std::endl;
    }
  }
}

void MovementSystem::movePlanet(sf::CircleShape *body, const sf::Vector2i &mouse_pos) const {
  if (mouse_pos.x >= body->getPosition().x && mouse_pos.x <= body->getPosition().x + body->getRadius() * 2 &&
        mouse_pos.y >= body->getPosition().y && mouse_pos.y <= body->getPosition().y + body->getRadius() * 2) {

      float new_x = mouse_pos.x - body->getRadius();
      float new_y = mouse_pos.y - body->getRadius();
      if (new_x > 0 && new_x + body->getRadius() * 2 < m_max_width) {
          body->setPosition(new_x, body->getPosition().y);
      }
      if (new_y > 0 && new_y + body->getRadius() * 2 < m_max_height) {
          body->setPosition(body->getPosition().x, new_y);
      }
    }
}

sf::Vector2f MovementSystem::moveEnemies(sf::Vector2f current_position, sf::Vector2f target_position, float speed) {
    sf::Vector2f direction = target_position - current_position;
    float distance = sqrt(direction.x * direction.x + direction.y * direction.y);
    if (distance > speed) {
      direction = direction / distance;
      current_position = current_position + direction * speed;
    } else {
      current_position = target_position;
    }
    return current_position;
}
