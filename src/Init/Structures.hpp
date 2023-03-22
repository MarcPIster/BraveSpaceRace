#ifndef BRAVESPACERACE_STRUCTURES_HPP
#define BRAVESPACERACE_STRUCTURES_HPP


struct PlayerRange {
  float min;
  const int max = 200;
  float current;
  bool active;
};

struct AnimationUnit {
        sf::RectangleShape body;
        int current_frame;
        float current_time;
        float last_time;
        int max_frame;
        int frame_width;
        int frame_height;
        int frame_x;
        int frame_y;
        int frame_speed;
        int frame_speed_count;
        bool active;
};

struct AnimationEnemy {
  sf::RectangleShape body;
  int current_frame;
  float current_time;
  float last_time;
  int max_frame;
  int frame_width;
  int frame_height;
  int frame_x;
  int frame_y;
  int frame_speed;
  int frame_speed_count;
  bool active;
};

enum UnitClass {
  STARSHIP,
  ASTROIDSHOOTER,
  WIP,
};

struct Unit {
  std::string name;
  int cost;
  sf::RectangleShape* card;
  sf::Text* text;
  UnitClass unit_class;
};
#endif // BRAVESPACERACE_STRUCTURES_HPP
