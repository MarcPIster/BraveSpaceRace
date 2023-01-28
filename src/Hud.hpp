#ifndef BRAVESPACERACE_HUD_HPP
#define BRAVESPACERACE_HUD_HPP

#include "SFML/Graphics.hpp"

struct HudData {
    bool active;
};

class Hud {
public:
    Hud(sf::Vector2u t_window_size, bool t_active);
    ~Hud(){};

    sf::RectangleShape *getMHeart() const;
    sf::RectangleShape *getMBackground() const;
    bool getHudStatus() const;
    void setHudStatus(bool t_status);
private:
    sf::RectangleShape* m_background;
    sf::RectangleShape* m_health_bar;
    bool m_active;
};


#endif//BRAVESPACERACE_HUD_HPP
