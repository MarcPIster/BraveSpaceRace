#include "Hud.hpp"

Hud::Hud(sf::Vector2u t_window_size, bool t_active) {
    //init Background
    m_background = new sf::RectangleShape();
    m_font = new sf::Font();
    m_live = new sf::Text();
    m_font->loadFromFile("../src/Sprites/Fonts/SpaceMono-Regular.ttf");
    m_live->setFont(*m_font);
    m_live->setCharacterSize(20);
    m_background->setSize({200, 100});
    m_background->setFillColor(sf::Color::Transparent);
    m_background->setOutlineThickness(3);
    m_background->setOutlineColor(sf::Color::White);
    m_background->setPosition({static_cast<float>(t_window_size.x - 205), 5});


    //init Health Bar
    initHealthSprite("../src/Sprites/heart100.png", 0, t_window_size);
    initHealthSprite("../src/Sprites/heart90.png", 1, t_window_size);
    initHealthSprite("../src/Sprites/heart80.png", 2, t_window_size);
    initHealthSprite("../src/Sprites/heart70.png", 3, t_window_size);
    initHealthSprite("../src/Sprites/heart60.png", 4, t_window_size);
    initHealthSprite("../src/Sprites/heart50.png", 5, t_window_size);
    initHealthSprite("../src/Sprites/heart40.png", 6, t_window_size);
    initHealthSprite("../src/Sprites/heart30.png", 7, t_window_size);
    initHealthSprite("../src/Sprites/heart20.png", 8, t_window_size);
    initHealthSprite("../src/Sprites/heart10.png", 9, t_window_size);
    initHealthSprite("../src/Sprites/heart0.png", 10, t_window_size);
    m_active = t_active;
}

void Hud::initHealthSprite(std::string t_path, int t_index,sf::Vector2u t_window_size) {
    m_health_bar.push_back(new sf::RectangleShape());
    sf::Texture* texture = new sf::Texture();
    texture->loadFromFile(t_path);
    m_health_bar[t_index]->setSize({50, 50});
    m_health_bar[t_index]->setTexture(texture);
    m_health_bar[t_index]->setPosition({static_cast<float>(t_window_size.x - 205 ), 5});
}

sf::RectangleShape *Hud::getMBackground() const {
    return m_background;
}

sf::RectangleShape *Hud::getMHeart(int t_player_live) const {
    if (t_player_live >= 91)
      return m_health_bar[0];
    if (t_player_live >= 81)
      return m_health_bar[1];
    if (t_player_live >= 71)
      return m_health_bar[2];
    if (t_player_live >= 61)
      return m_health_bar[3];
    if (t_player_live >= 51)
      return m_health_bar[4];
    if (t_player_live >= 41)
      return m_health_bar[5];
    if (t_player_live >= 31)
      return m_health_bar[6];
    if (t_player_live >= 21)
      return m_health_bar[7];
    if (t_player_live >= 11)
      return m_health_bar[8];
    if (t_player_live >= 1)
      return m_health_bar[9];
    return m_health_bar[10];
}

void Hud::updateLives(int t_player_live) {
    m_live->setString(std::to_string(t_player_live));
    m_live->setOrigin(m_live->getGlobalBounds().width / 2, (m_live->getGlobalBounds().height / 2) - 20);
    m_live->setPosition(m_health_bar[0]->getPosition().x + m_health_bar[0]->getSize().x / 2, m_health_bar[0]->getPosition().y / 2 );
}

bool Hud::getHudStatus() const {
    return m_active;
}

void Hud::setHudStatus(bool t_status) {
    m_active = t_status;
}

sf::Text *Hud::getMLive() const { return m_live; }
