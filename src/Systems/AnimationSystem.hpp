#ifndef BRAVESPACERACE_ANIMATIONSYSTEM_HPP_
#define BRAVESPACERACE_ANIMATIONSYSTEM_HPP_

#include "../ECS/ISystem.hpp"
#include "../Timer.hpp"


class AnimationSystem : public ISystem {
 public:
  AnimationSystem(std::shared_ptr<EntityManager> t_em);
  ~AnimationSystem();

  void update();
  void updateData(SystemData &t_data);

 private:
  Timer m_timer;
};

#endif  // BRAVESPACERACE_ANIMATIONSYSTEM_HPP_
