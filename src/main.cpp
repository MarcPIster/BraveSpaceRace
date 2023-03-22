#include "./Hud.hpp"
#include "./Init/initGame.hpp"
#include "./InputManager/InputManager.hpp"
#include "./Systems/CombatSystem.hpp"
#include "Systems/DisplaySystem.hpp"
#include "Systems/MovementSystem.hpp"
#include "Systems/AnimationSystem.hpp"

int counter;

EntityManager initGameManager(sf::Vector2i t_window_size) {
    EntityManager entity_manager;

    createBackground(entity_manager);
    createPlayer(entity_manager, t_window_size);
    createEnemys(entity_manager, 3, t_window_size);

    EntityID hud_status = entity_manager.createNewEntity();
    HudData *hud_stat = entity_manager.Assign<HudData>(hud_status, HudData{false});
    return entity_manager;
}


int main() {

    // Create the main window
    int maxFPS = 60;
    int width = 1440;
    int height = 700;
    sf::RenderWindow window(sf::VideoMode(width, height), "PRIVAT WIP GAME");
    window.setFramerateLimit(maxFPS);
    window.setMouseCursorVisible(false);
    // init EntityManager
    EntityManager entity_manager = initGameManager({width, height});

    // init systems
    std::vector<std::shared_ptr<ISystem>> systems;

    systems.push_back(std::make_shared<MovementSystem>(std::make_shared<EntityManager>(entity_manager)));
    systems.push_back(std::make_shared<CombatSystem>(std::make_shared<EntityManager>(entity_manager)));
    systems.push_back(std::make_shared<DisplaySystem>(std::make_shared<EntityManager>(entity_manager), window));
    systems.push_back(std::make_shared<AnimationSystem>(std::make_shared<EntityManager>(entity_manager)));


    // init input manager
    InputManager input_manager;

    //Start GameLoop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
            input_manager.recordInputs(event);

        }
        SystemData data = {.event_queue= input_manager.getInputs(), .max_screen_height = height, .max_screen_width = width, .window = &window};

        for (std::shared_ptr<ISystem> system : systems) {
            system->updateData(data);
            system->update();
        }

    }
    return 0;
}
