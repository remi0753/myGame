#include "danmaku.h"

#include "../share/enemyShare.h"
#include <math.h>
/*
  float m_x;
  float m_y;
  float m_angle;
  float m_speed;
  int m_count;
  int m_flag;
  */

enum edanmakuPattern {
  pattern0,
  pattern1,
  patternMax
};

void danmakuPattern0(enemyShot_t *shot);
void danmakuPattern1(enemyShot_t *shot);

const static void (*danmakuFunc[patternMax])(enemyShot_t *) = {
  danmakuPattern0,
  danmakuPattern1,
};

void danmaku(enemyShot_t *shot){
  danmakuFunc[shot->m_pattern](shot);
}

void danmakuPattern0(enemyShot_t *shot){
  if (shot->m_count == 0) {
    float p[2];
    enemyShareGetEnemyPosition(p, shot->m_enemyId);
    if (p[0] < 0.0f) return;
    enemyBullet_t b = {
      p[0],
      p[1],
      M_PI / 2.0f,
      3.0f,
      0,
      1};
    enemyBulletNode_t **epp = &(shot->m_bulletList);
    enemyBulletNodeAppend(epp, &b);
  }
}

void danmakuPattern1(enemyShot_t *shot){
  if (shot->m_count <= 200 && shot->m_count % 5 == 0) {
    float p[2];
    enemyShareGetEnemyPosition(p, shot->m_enemyId);
    if (p[0] < 0.0f) return;
    enemyBullet_t b = {
      p[0],
      p[1],
      M_PI / 2.0f,
      5.0f,
      0,
      1};
    enemyBulletNode_t **epp = &(shot->m_bulletList);
    enemyBulletNodeAppend(epp, &b);
  }
}
