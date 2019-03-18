#include "enemyMove.h"

#include <math.h>

enum eMovePattern {
  movePattern0,
  movePatternMax
};

void pattern0(enemy_t *enemy);

const static void (*moveFunc[movePatternMax])(enemy_t *) = {
  pattern0
};

void enemyMove(enemy_t *enemy){
  moveFunc[enemy->m_movePattern](enemy);
  enemy->m_x += cos(enemy->m_angle) * enemy->m_speed;
  enemy->m_y += sin(enemy->m_angle) * enemy->m_speed;
}

void pattern0(enemy_t *enemy){
  const int t = enemy->m_count;
  if (t == 0) {
    enemy->m_speed = 3.0f;
    enemy->m_angle = M_PI / 2.0f;
  }
  if (t == 40)
    enemy->m_speed = 0.0f;
  if (t == (40 + 600)) {
    enemy->m_speed = 3.0f;
    enemy->m_angle = - M_PI / 2.0f;
  }
}

