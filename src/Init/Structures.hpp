#ifndef BRAVESPACERACE_STRUCTURES_HPP
#define BRAVESPACERACE_STRUCTURES_HPP

struct PlayerRange {
  float min;
  const int max = 200;
  float current;
  bool active;
};

struct Animation {
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
  ASTEROIDSHOOTER
};

#endif // BRAVESPACERACE_STRUCTURES_HPP
