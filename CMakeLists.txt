cmake_minimum_required(VERSION 3.24)
project(braveSpaceRace)

set(CMAKE_CXX_STANDARD 23)

include(FetchContent)
FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

find_package(OpenGL REQUIRED OPTIONAL_COMPONENTS OpenGL)
include_directories(${OPENGL_INCLUDE_DIR})


add_executable(braveSpaceRace src/main.cpp src/ECS/ComponentPool.hpp
        src/ECS/DataTypesECS.hpp src/ECS/ECS.hpp src/ECS/EntityManager.hpp
        src/ECS/EntityViewer.hpp src/ECS/ISystem.hpp src/InputManager/InputManager.cpp
        src/InputManager/InputManager.hpp src/Systems/DisplaySystem.cpp
        src/Systems/DisplaySystem.hpp src/Systems/MovementSystem.cpp
        src/Systems/MovementSystem.hpp src/InputManager/EventQueue/EventQueue.cpp
        src/InputManager/EventQueue/EventQueue.hpp src/Hud.cpp src/Hud.hpp
        src/Systems/CombatSystem.cpp src/Systems/CombatSystem.hpp src/Init/createPlayer.cpp
        src/Init/initGame.hpp src/Init/createBackGround.cpp src/Init/createEnemies.cpp src/Timer.hpp src/Shop/Shop.cpp src/Shop/Shop.hpp src/Init/Structures.hpp)


target_link_libraries(braveSpaceRace PRIVATE ${OPENGL_LIBRARIES} sfml-graphics)


target_compile_features(braveSpaceRace PRIVATE cxx_std_17)
if (WIN32 AND BUILD_SHARED_LIBS)
    add_custom_command(TARGET braveSpaceRace POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:braveSpaceRace> $<TARGET_FILE_DIR:braveSpaceRace> COMMAND_EXPAND_LISTS)
endif()

install(TARGETS braveSpaceRace)