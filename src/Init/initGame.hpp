#ifndef BRAVESPACERACE_INITGAME_HPP
#define BRAVESPACERACE_INITGAME_HPP

#include "../ECS/EntityManager.hpp"



void createPlayer(EntityManager& t_entity_manager);
void createBackground(EntityManager& t_entity_manager);
void createEnemys(EntityManager& t_entity_manager, int t_how_many, sf::Vector2i t_window_size);

#endif//BRAVESPACERACE_INITGAME_HPP