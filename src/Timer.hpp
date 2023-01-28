#ifndef TIMER_HPP_
#define TIMER_HPP_

#include <ctime>
#include <chrono>

class Timer {
public:
  Timer() {
    m_start_time = 0;
  };
  Timer(int t_enemyType) {
    if (t_enemyType == 1)
      m_start_time = std::rand() % 60;
    else
      m_start_time = 0;
  };
  ~Timer() {};
  void startTimer(int t_enemyType) {
    if (t_enemyType == 1) {
      m_pause_time = 0;
      m_animation_time = 0;
      m_start = std::chrono::system_clock::now();
    }
  };

  void startTimer() {
    m_pause_time = 0;
    m_start_time = 0;
    m_animation_time = 0;
    m_start = std::chrono::system_clock::now();
  };

  float returnTime() {
    m_current_time = std::chrono::system_clock::now();
    std::chrono::duration<float> diff = m_current_time - m_start;
    // std::chrono::duration<float> diff = std::chrono::duration_cast<std::chrono::seconds>(m_current_time - m_start);

    float elapsedTime = diff.count() - m_pause_time;

    return elapsedTime;
  };

  bool checkStartTime(){
    if (returnTime() > m_start_time) {
      restartTimer();
      return true;
    }
    return false;
  };

  float returnAnimationTime() {
    m_current_time = std::chrono::system_clock::now();
    std::chrono::duration<float> diff = m_current_time - m_start;
    // std::chrono::duration<float> diff = std::chrono::duration_cast<std::chrono::seconds>(m_current_time - m_start);
    float elapsedTime = diff.count() - m_pause_time - m_animation_time;
    return elapsedTime;
  };

  void setAnimationTime(float t_time) { m_animation_time = t_time;
  };

  void restartTimer() {
    m_pause_time = 0;
    m_animation_time = 0;
    m_start = std::chrono::system_clock::now();
  };

  void startPause() { m_pause_start = std::chrono::system_clock::now();
  };
  void stopPause() {
    m_pause_end = std::chrono::system_clock::now();
    std::chrono::duration<float> diff = m_pause_end - m_pause_start;
    m_pause_time += diff.count();
  };

private:
  std::chrono::system_clock::time_point m_start;
  std::chrono::system_clock::time_point m_current_time;
  std::chrono::system_clock::time_point m_pause_start;
  std::chrono::system_clock::time_point m_pause_end;
  float m_pause_time;
  float m_animation_time;
  float m_start_time;
};

#endif /* !TIMER_HPP_ */