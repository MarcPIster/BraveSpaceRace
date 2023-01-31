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

    sf::RectangleShape *getMHeart(int t_player_live) const;
    sf::RectangleShape *getMBackground() const;
    bool getHudStatus() const;
    void updateLives(int t_player_live);
    void setHudStatus(bool t_status);
    sf::Text *getMLive() const;

private:
    sf::RectangleShape* m_background;
    std::vector<sf::RectangleShape*> m_health_bar;
    sf::Font* m_font;
    sf::Text* m_live;
    bool m_active;
    void initHealthSprite(std::string t_path, int t_index, sf::Vector2u t_window_size);
};


#endif//BRAVESPACERACE_HUD_HPP
