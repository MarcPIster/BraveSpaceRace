#ifndef BRAVESPACERACE_STRUCTURES_HPP
#define BRAVESPACERACE_STRUCTURES_HPP

struct PlayerRange {
  float min;
  const int max = 200;
  float current;
  bool active;
};

#endif // BRAVESPACERACE_STRUCTURES_HPP
