#include "AnimationSystem.hpp"

AnimationSystem::AnimationSystem(std::shared_ptr<EntityManager> t_em) {
  m_em = t_em;
  m_timer = Timer();
  m_timer.startTimer();
}

AnimationSystem::~AnimationSystem() {}

void AnimationSystem::updateData(SystemData &t_data) {}

void AnimationSystem::update() {
  for (EntityID ent : EntityViewer<Animation, Pos, float, int>(*m_em.get())) {
    Animation *animation_enemy = (*m_em.get()).Get<Animation>(ent);

    if (animation_enemy->last_time - animation_enemy->current_time > 0.07) {
      animation_enemy->current_frame += 1;
      animation_enemy->current_time = animation_enemy->last_time;
    }
    // check current frame and set texture
    if (animation_enemy->current_frame  < 8) {
      sf::IntRect rect = sf::IntRect(125 * (animation_enemy->current_frame), 0, 125, 125);
      animation_enemy->body.setTextureRect(rect);
    } else if (animation_enemy->current_frame  < 16) {
      animation_enemy->body.setTextureRect(
          sf::IntRect(125 * ((int)animation_enemy->current_frame  - 8), 125, 125, 125));
    } else if (animation_enemy->current_frame  < 24) {
      animation_enemy->body.setTextureRect(
          sf::IntRect(125 * ((int)animation_enemy->current_frame  - 16), 250, 125, 125));
    } else if (animation_enemy->current_frame  < 32) {
      animation_enemy->body.setTextureRect(
          sf::IntRect(125 * ((int)animation_enemy->current_frame  - 24), 375, 125, 125));
    } else if (animation_enemy->current_frame < 40) {
      animation_enemy->body.setTextureRect(
          sf::IntRect(125 * ((int)animation_enemy->current_frame  - 32), 375, 125, 125));
    } else if (animation_enemy->current_frame < 48) {
      animation_enemy->body.setTextureRect(
          sf::IntRect(125 * ((int)animation_enemy->current_frame  - 40), 375, 125, 125));
    } else if (animation_enemy->current_frame < 56) {
      animation_enemy->body.setTextureRect(
          sf::IntRect(125 * ((int)animation_enemy->current_frame  - 48), 375, 125, 125));
    } else if (animation_enemy->current_frame < 64) {
      animation_enemy->body.setTextureRect(
          sf::IntRect(125 * ((int)animation_enemy->current_frame  - 56), 375, 125, 125));
    } else {
      animation_enemy->current_frame  = 0;
    }
        animation_enemy->last_time = m_timer.returnTime();
  }
}
