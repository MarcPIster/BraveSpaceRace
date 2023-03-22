#include "initGame.hpp"


void createBackground(EntityManager& t_entity_manager) {
    EntityID background = t_entity_manager.createNewEntity();
    SpriteECS *background_sprite = t_entity_manager.Assign<SpriteECS>(background, SpriteECS("../src/Sprites/Backgrounds/spaceBG.jpg"));
    Pos *background_pos = t_entity_manager.Assign<Pos>(background, Pos{ sf::Vector2f(0, 0), sf::Vector2f(800, 800)});
}
