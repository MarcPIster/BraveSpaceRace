#include "initGame.hpp"


void createPlayer(EntityManager& t_entity_manager) {
    EntityID player = t_entity_manager.createNewEntity();
    SpriteECS player_sprite = SpriteECS("../src/Sprites/world.png");
    sf::CircleShape body;

    body.setRadius(50);
    body.setPosition(600, 100);
    body.setTexture(player_sprite.getTexture());
    sf::CircleShape *player_body = t_entity_manager.Assign<sf::CircleShape>(player, body);
    Level *player_level = t_entity_manager.Assign<Level>(player, {.level= 1, .process= 0});
    int *player_health = t_entity_manager.Assign<int>(player, 100);
}