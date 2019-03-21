#include "enemyBullet.h"

#include "../shape/rect.h"
#include "../scene/game/gameField.h"
#include "../define.h"
#include <GL/glut.h>

static const float ENEMY_BULLET_WIDTH = 8.0f;
static const float ENEMY_BULLET_HEIGHT = 10.0f;
static const unsigned char ENEMY_BULLET_COLOR[3] = {240, 240, 150};

void drawBullet(enemyBullet_t *bullet){
  rectBegin();
  glViewport(
      (int)FIELD_START_X, 
      (int)FIELD_START_Y, 
      (int)FIELD_SIZE_X, 
      (int)FIELD_SIZE_Y);
  glScalef(
      (float)WINDOW_WIDTH / FIELD_SIZE_X, 
      (float)WINDOW_HEIGHT / FIELD_SIZE_Y, 
      1.0f);

  //図形描画
  rectDraw(
      bullet->m_x,
      bullet->m_y,
      ENEMY_BULLET_WIDTH,
      ENEMY_BULLET_HEIGHT,
      bullet->m_angle,
      ENEMY_BULLET_COLOR[0],
      ENEMY_BULLET_COLOR[1],
      ENEMY_BULLET_COLOR[2]);

  glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
  rectEnd();
}
