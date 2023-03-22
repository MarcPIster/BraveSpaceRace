#ifndef BRAVESPACERACE_SHOP_HPP
#define BRAVESPACERACE_SHOP_HPP

#include "SFML/Graphics.hpp"
#include <iostream>
#include "../Init/Structures.hpp"


class Shop {
public:
  Shop(sf::Vector2i t_window_size);
  ~Shop();

  void levelUp();
  int getExp() const;
  int getLevel() const;
  sf::RectangleShape *getMBackground();
  std::vector<Unit> getCards() const;
  void createCard(std::string t_name, int t_cost, sf::Vector2i t_shop_size, UnitClass t_unit_class);
  void clickCard(Unit *t_card, sf::Vector2i t_mouse_pos, float t_player_money);
  void addToSpawnQueue(UnitClass t_unit);
  std::vector<UnitClass> getSpawnQueue() const;
  void clearSpawnQueue();

private:
  int m_level;
  int m_exp;
  sf::RectangleShape* m_background;
  std::vector<Unit> m_unit_cards;
  sf::Font *m_font;
  std::vector<UnitClass> m_spawnQueue;
};

#endif // BRAVESPACERACE_SHOP_HPP
