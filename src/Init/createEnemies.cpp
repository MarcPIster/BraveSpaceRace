#include "initGame.hpp"

sf::Vector2f getRandomVectorOutsideScreen(sf::Vector2i screenSize) {
    float x, y;
    int randNum = std::rand() % 4;
    switch (randNum) {
        case 0:
            x = -std::rand() % 100;
            y = std::rand() % (int)screenSize.y;
            break;
        case 1:
            x = screenSize.x + std::rand() % 100;
            y = std::rand() % (int)screenSize.y;
            break;
        case 2:
            x = std::rand() % (int)screenSize.x;
            y = -std::rand() % 100;
            break;
        case 3:
            x = std::rand() % (int)screenSize.x;
            y = screenSize.y + std::rand() % 100;
            break;
    }
    return sf::Vector2f(x, y);
}

void createEnemy(EntityManager& t_entity_manager, sf::Vector2f t_pos) {
    EntityID enemy = t_entity_manager.createNewEntity();
    SpriteECS enemy_sprite = SpriteECS("../src/Sprites/astroids.png");

    sf::RectangleShape body;
    body.setSize(sf::Vector2f(50, 50));
    body.setTexture(enemy_sprite.getTexture());
    Timer timer = Timer(1);
    timer.startTimer(1);
    t_entity_manager.Assign<Timer>(enemy, timer);
    body.setPosition(t_pos);
    double* currentFrame = t_entity_manager.Assign<double>(enemy, 0);
    int *life = t_entity_manager.Assign<int>(enemy, 0);
    float* speed = t_entity_manager.Assign<float>(enemy, 5);
    Pos *pos = t_entity_manager.Assign<Pos>(enemy, Pos{ t_pos, t_pos});
    sf::RectangleShape *enemy_body = t_entity_manager.Assign<sf::RectangleShape>(enemy, body);
}

void createEnemys(EntityManager& t_entity_manager, int t_how_many, sf::Vector2i t_window_size) {
    for (int i = 0; i < t_how_many; i++) {
        createEnemy(t_entity_manager, getRandomVectorOutsideScreen(t_window_size));
    }
}
