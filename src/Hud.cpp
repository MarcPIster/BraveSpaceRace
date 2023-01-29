#include "Hud.hpp"

Hud::Hud(sf::Vector2u t_window_size, bool t_active) {

    //init Background
    m_background = new sf::RectangleShape();
    m_background->setSize({200, 100});
    m_background->setFillColor(sf::Color::Transparent);
    m_background->setOutlineThickness(3);
    m_background->setOutlineColor(sf::Color::White);
    m_background->setPosition({static_cast<float>(t_window_size.x - 205), 5});

    //init Health Bar

    m_health_bar.push_back(new sf::RectangleShape());
    sf::Texture* texture = new sf::Texture();
    texture->loadFromFile("../src/Sprites/heart100.png");
    m_health_bar[0]->setSize({50, 50});
    m_health_bar[0]->setTexture(texture);
    m_health_bar[0]->setPosition({static_cast<float>(t_window_size.x - 205 ), 5});

    m_health_bar.push_back(new sf::RectangleShape());
    sf::Texture* texture1 = new sf::Texture();
    texture1->loadFromFile("../src/Sprites/heart90.png");
    m_health_bar[1]->setSize({50, 50});
    m_health_bar[1]->setTexture(texture1);
    m_health_bar[1]->setPosition({static_cast<float>(t_window_size.x - 205 ), 5});

    m_health_bar.push_back(new sf::RectangleShape());
    sf::Texture* texture2 = new sf::Texture();
    texture2->loadFromFile("../src/Sprites/heart80.png");
    m_health_bar[2]->setSize({50, 50});
    m_health_bar[2]->setTexture(texture2);
    m_health_bar[2]->setPosition({static_cast<float>(t_window_size.x - 205 ), 5});

    m_health_bar.push_back(new sf::RectangleShape());
    sf::Texture* texture3 = new sf::Texture();
    texture3->loadFromFile("../src/Sprites/heart70.png");
    m_health_bar[3]->setSize({50, 50});
    m_health_bar[3]->setTexture(texture3);
    m_health_bar[3]->setPosition({static_cast<float>(t_window_size.x - 205 ), 5});

    m_health_bar.push_back(new sf::RectangleShape());
    sf::Texture* texture4 = new sf::Texture();
    texture4->loadFromFile("../src/Sprites/heart60.png");
    m_health_bar[4]->setSize({50, 50});
    m_health_bar[4]->setTexture(texture4);
    m_health_bar[4]->setPosition({static_cast<float>(t_window_size.x - 205 ), 5});

    m_health_bar.push_back(new sf::RectangleShape());
    sf::Texture* texture5 = new sf::Texture();
    texture5->loadFromFile("../src/Sprites/heart50.png");
    m_health_bar[5]->setSize({50, 50});
    m_health_bar[5]->setTexture(texture5);
    m_health_bar[5]->setPosition({static_cast<float>(t_window_size.x - 205 ), 5});

    m_health_bar.push_back(new sf::RectangleShape());
    sf::Texture* texture6 = new sf::Texture();
    texture6->loadFromFile("../src/Sprites/heart40.png");
    m_health_bar[6]->setSize({50, 50});
    m_health_bar[6]->setTexture(texture6);
    m_health_bar[6]->setPosition({static_cast<float>(t_window_size.x - 205 ), 5});

    m_health_bar.push_back(new sf::RectangleShape());
    sf::Texture* texture7 = new sf::Texture();
    texture7->loadFromFile("../src/Sprites/heart30.png");
    m_health_bar[7]->setSize({50, 50});
    m_health_bar[7]->setTexture(texture7);
    m_health_bar[7]->setPosition({static_cast<float>(t_window_size.x - 205 ), 5});

    m_health_bar.push_back(new sf::RectangleShape());
    sf::Texture* texture8 = new sf::Texture();
    texture8->loadFromFile("../src/Sprites/heart20.png");
    m_health_bar[8]->setSize({50, 50});
    m_health_bar[8]->setTexture(texture8);
    m_health_bar[8]->setPosition({static_cast<float>(t_window_size.x - 205 ), 5});

    m_health_bar.push_back(new sf::RectangleShape());
    sf::Texture* texture9 = new sf::Texture();
    texture9->loadFromFile("../src/Sprites/heart10.png");
    m_health_bar[9]->setSize({50, 50});
    m_health_bar[9]->setTexture(texture9);
    m_health_bar[9]->setPosition({static_cast<float>(t_window_size.x - 205 ), 5});


    m_health_bar.push_back(new sf::RectangleShape());
    sf::Texture* texture10 = new sf::Texture();
    texture10->loadFromFile("../src/Sprites/heart0.png");
    m_health_bar[10]->setSize({50, 50});
    m_health_bar[10]->setTexture(texture10);
    m_health_bar[10]->setPosition({static_cast<float>(t_window_size.x - 205 ), 5});

    m_active = t_active;

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

bool Hud::getHudStatus() const {
    return m_active;
}

void Hud::setHudStatus(bool t_status) {
    m_active = t_status;
}