#include "InputManager.hpp"
#include <iostream>

InputManager::InputManager()
{
  //SetExitKey(KEY_CAPS_LOCK);
}


// -4 = UP ; -3 = LEFT ; -2 = DOWN ; -1 = RIGHT
void InputManager::recordInputs(const sf::Event &t_event)
{
  if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
      this->m_input_queue.push_back(sf::Mouse::Left);
      printf("Left");
  }
  if(sf::Mouse::isButtonPressed(sf::Mouse::Right)){
      this->m_input_queue.push_back(sf::Mouse::Right);
      printf("Right");
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::K)) {
        this->m_input_queue.push_back(sf::Keyboard::K);
        printf("K");
    }

    //std::this_thread::sleep_for(std::chrono::milliseconds(100)); // This should change
}


void InputManager::popInputs()
{
  if (!this->m_input_queue.empty())
    this->m_input_queue.clear();
}


EventQueue InputManager::getInputs()
{
  std::vector<int> inputs = this->m_input_queue;
  EventQueue eventQueue(inputs);
  this->popInputs();
  return eventQueue;
}


sf::Vector2i InputManager::getMousePosition()
{
  return sf::Mouse::getPosition();
}

bool InputManager::isMouseLeftClicked()
{
  return sf::Mouse::isButtonPressed(sf::Mouse::Left);
  // Needs click position
}

bool InputManager::isMouseRightClicked()
{
  return sf::Mouse::isButtonPressed(sf::Mouse::Right);
  // Needs click position
}