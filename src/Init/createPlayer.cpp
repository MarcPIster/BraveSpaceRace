#include "initGame.hpp"


void createPlayer(EntityManager& t_entity_manager, sf::Vector2i t_window_size) {
    EntityID player = t_entity_manager.createNewEntity();
    SpriteECS player_sprite = SpriteECS("../src/Sprites/world.png");
    sf::CircleShape body;

    Shop *shop = t_entity_manager.Assign<Shop>(player, Shop(t_window_size));

    body.setRadius(40);
    body.setPosition(600, 100);
    body.setOrigin(40, 40);
    body.setTexture(player_sprite.getTexture());
    PlayerRange *player_range = t_entity_manager.Assign<PlayerRange>(player, {.min= 40, .current= 90, true});
    sf::CircleShape *player_body = t_entity_manager.Assign<sf::CircleShape>(player, body);
    Level *player_level = t_entity_manager.Assign<Level>(player, {.level= 1, .process= 0});
    int *player_health = t_entity_manager.Assign<int>(player, 100);
}