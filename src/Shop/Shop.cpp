#include "Shop.hpp"

void Shop::createCard(std::string t_name, int t_cost, sf::Vector2i t_shop_size) {
  int multiplier = (m_unit_cards.size() * 150) + (25 * m_unit_cards.size()) +25;
  Unit unit = {
      .name = t_name,
      .cost = t_cost,
      .card = new sf::RectangleShape() };
  unit.card->setSize({150, 200});
  unit.card->setOutlineColor(sf::Color::Green);
  unit.card->setOutlineThickness(2);
  unit.card->setPosition(t_shop_size.x + multiplier,t_shop_size.y);
  m_unit_cards.push_back(unit);
}

Shop::Shop(sf::Vector2i t_window_size) {
    m_level = 1;
    m_exp = 0;
    float width = 900;
    float height = 200;
    m_background = new sf::RectangleShape();
    m_background->setSize({width, height});
    m_background->setFillColor(sf::Color::Transparent);
    m_background->setOutlineThickness(3);
    m_background->setOutlineColor(sf::Color::White);
    m_background->setPosition({(static_cast<float>(t_window_size.x) / 2) - (width/2),
                               static_cast<float>(t_window_size.y) - height - 5});

    createCard("", 2, {(int(t_window_size.x) / 2) - int(width/2),
                           int(t_window_size.y) - int(height + 5)});
    createCard("", 2, {(int(t_window_size.x) / 2) - int(width/2),
                           int(t_window_size.y) - int(height + 5)});
    createCard("", 2, {(int(t_window_size.x) / 2) - int(width/2),
                           int(t_window_size.y) - int(height + 5)});
    createCard("", 2, {(int(t_window_size.x) / 2) - int(width/2),
                           int(t_window_size.y) - int(height + 5)});
    createCard("", 2, {(int(t_window_size.x) / 2) - int(width/2),
                           int(t_window_size.y) - int(height + 5)});
}

Shop::~Shop() {
;
}

void Shop::levelUp() {
    m_level++;
    m_exp = 0;
}

std::vector<Unit> Shop::getCards() const { return m_unit_cards; }

int Shop::getExp() const { return m_exp; }

int Shop::getLevel() const { return m_level; }

sf::RectangleShape *Shop::getMBackground() { return m_background; }
