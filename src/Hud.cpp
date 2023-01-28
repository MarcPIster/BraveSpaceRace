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
    m_health_bar = new sf::RectangleShape();
    sf::Texture* texture = new sf::Texture();
    texture->loadFromFile("../src/Sprites/heartfull.png");
    m_health_bar->setTexture(texture);
    m_health_bar->setSize({30, 30});
    m_health_bar->setPosition({static_cast<float>(t_window_size.x - 205), 5});

    m_active = t_active;

}
sf::RectangleShape *Hud::getMBackground() const {
    return m_background;
}

sf::RectangleShape *Hud::getMHeart() const {
    return m_health_bar;
}

bool Hud::getHudStatus() const {
    return m_active;
}

void Hud::setHudStatus(bool t_status) {
    m_active = t_status;
}