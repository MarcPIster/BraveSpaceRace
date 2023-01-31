#ifndef BRAVESPACERACE_SHOP_HPP
#define BRAVESPACERACE_SHOP_HPP

#include "SFML/Graphics.hpp"
#include <iostream>

struct Unit {
  std::string name;
  int cost;
  sf::RectangleShape* card;
  sf::Text* text;
};

class Shop {
public:
  Shop(sf::Vector2i t_window_size);
  ~Shop();

  void levelUp();
  int getExp() const;
  int getLevel() const;
  sf::RectangleShape *getMBackground();
  std::vector<Unit> getCards() const;
  void createCard(std::string t_name, int t_cost, sf::Vector2i t_shop_size);
  void clickCard(Unit *t_card);
private:
  int m_level;
  int m_exp;
  sf::RectangleShape* m_background;
  std::vector<Unit> m_unit_cards;
  sf::Font *m_font;
};

#endif // BRAVESPACERACE_SHOP_HPP
