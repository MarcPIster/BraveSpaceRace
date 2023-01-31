#ifndef BRAVESPACERACE_SHOP_HPP
#define BRAVESPACERACE_SHOP_HPP

#include "SFML/Graphics.hpp"

struct Unit {
  std::string name;
  int cost;
  sf::RectangleShape* card;
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

private:
  int m_level;
  int m_exp;
  sf::RectangleShape* m_background;
  std::vector<Unit> m_unit_cards;
};

#endif // BRAVESPACERACE_SHOP_HPP
