#include "enemyAppearance.h"

#include "../shape/rect.h"
#include <GL/glut.h>
#include "../scene/game/gameField.h"
#include "../define.h"
#include <math.h>

const static float ENEMY_TYPE1_SIZE = 25.0f;
const static unsigned char ENEMY_TYPE1_COLOR[3] = {250, 250, 250};

void enemyType1Draw(const enemy_t *enemy){
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
      enemy->m_x,
      enemy->m_y,
      ENEMY_TYPE1_SIZE,
      ENEMY_TYPE1_SIZE,
      (float)(enemy->m_count) * 2.0f,
      ENEMY_TYPE1_COLOR[0],
      ENEMY_TYPE1_COLOR[1],
      ENEMY_TYPE1_COLOR[2]);

  glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
  rectEnd();
}

void enemyType1Size(float size[2]){
  size[0] = size[1] = ENEMY_TYPE1_SIZE * sqrt(2.0);
}
