#include "Shop.hpp"

#include <utility>


void Shop::createCard(std::string t_name, int t_cost, sf::Vector2i t_shop_size) {
  int multiplier = (m_unit_cards.size() * 150) + (25 * m_unit_cards.size()) +25;
  Unit unit = {
      .name = std::move(t_name),
      .cost = t_cost,
      .card = new sf::RectangleShape(),
      .text = new sf::Text() };
  unit.text->setFont(*m_font);
  unit.text->setCharacterSize(24);
  unit.text->setFillColor(sf::Color::Black);
  unit.text->setString(unit.name + " " + std::to_string(unit.cost));
  unit.card->setSize({150, 200});
  unit.card->setOutlineColor(sf::Color::Red);
  unit.card->setOutlineThickness(2);
  unit.card->setPosition(t_shop_size.x + multiplier,t_shop_size.y);
  unit.text->setOrigin(unit.text->getGlobalBounds().width / 2, (unit.text->getGlobalBounds().height / 2) - 5);
  unit.text->setPosition(unit.card->getPosition().x + unit.card->getSize().x / 2, unit.card->getPosition().y );
  m_unit_cards.push_back(unit);
}

Shop::Shop(sf::Vector2i t_window_size) {
    m_level = 1;
    m_exp = 0;
    float width = 900;
    float height = 200;
    m_font = new sf::Font();
    m_font->loadFromFile("../src/Sprites/Fonts/SpaceMono-Bold.ttf");
    m_background = new sf::RectangleShape();
    m_background->setSize({width, height});
    m_background->setFillColor(sf::Color::Transparent);
    m_background->setOutlineThickness(3);
    m_background->setOutlineColor(sf::Color::White);
    m_background->setPosition({(static_cast<float>(t_window_size.x) / 2) - (width/2),
                               static_cast<float>(t_window_size.y) - height - 5});

    createCard("TEST", 8, {(int(t_window_size.x) / 2) - int(width/2),
                           int(t_window_size.y) - int(height + 5)});
    createCard("Unit", 9, {(int(t_window_size.x) / 2) - int(width/2),
                           int(t_window_size.y) - int(height + 5)});
    createCard("Broski", 1, {(int(t_window_size.x) / 2) - int(width/2),
                           int(t_window_size.y) - int(height + 5)});
    createCard("Lama", 3, {(int(t_window_size.x) / 2) - int(width/2),
                           int(t_window_size.y) - int(height + 5)});
    createCard("Krieger", 2, {(int(t_window_size.x) / 2) - int(width/2),
                           int(t_window_size.y) - int(height + 5)});
}

Shop::~Shop() {
;
}

void Shop::levelUp() {
    m_level++;
    m_exp = 0;
}

void Shop::clickCard(Unit *t_card) {
    for (auto &m_unit_card : m_unit_cards) {
        if (m_unit_card.card == t_card->card) {
            m_unit_card.card->setOutlineColor(sf::Color::Green);
            std::cout << "Clicked on " << m_unit_card.name << std::endl;
        } else {
            m_unit_card.card->setOutlineColor(sf::Color::Red);
        }
    }
}

std::vector<Unit> Shop::getCards() const { return m_unit_cards; }

int Shop::getExp() const { return m_exp; }

int Shop::getLevel() const { return m_level; }

sf::RectangleShape *Shop::getMBackground() { return m_background; }
