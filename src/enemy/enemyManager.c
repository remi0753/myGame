#include "enemyManager.h"

#include <GL/glut.h>
#include "./types/enemyAppearance.h"
#include "../scene/game/gameField.h"
#include <stdio.h>
#include "./moves/enemyMove.h"
#include "enemyInfo.h"
#include <math.h>
#include "./share/enemyShare.h"

const static void (*enemyDraw[enemyTypeMax])(const enemy_t *) = {
  enemyType1Draw,
  enemyType2Draw,
};

const static void (*enemySize[enemyTypeMax])(float size[2]) = {
  enemyType1Size,
  enemyType2Size,
};

static enemyNode_t *enemyList;

void enemyUpdate(enemy_t *enemy);
int isInside(enemy_t *enemy);
/*
  enum eEnemyType m_type;
  int m_flag;
  float m_x;
  float m_y;
  float m_speed;
  float m_angle;
  int m_count;
  int m_movePattern;
  int m_shotPattern;
  int m_id;
  int m_shotStartCount;
  */
void enemyManagerInit(){
  enemyShareSetEnemyStack(&enemyList);
  enemy_t enemy1 = {enemyType1, 1, 100.0f, -100.0f, 2.0f, M_PI / 2.0f, 0, 0, 1, 0, 100};
  enemy_t enemy2 = {enemyType2, 1, 200.0f, 100.0f, 0.0f, 0.0f, 0, 0, 0, 1, 200};
  enemyNodeAppend(&enemyList, &enemy1);
  enemyNodeAppend(&enemyList, &enemy2);
}

void enemyManagerUpdate(){
  enemyNode_t **epp = &enemyList;
  while (*epp != NULL) {
    if ((*epp)->m_enemyData.m_flag) {
      enemyUpdate(&((*epp)->m_enemyData));
    } else {
      if ((*epp)->m_next != NULL) {
        enemyNode_t *temp = (*epp)->m_next;
        free(*epp);
        *epp = temp;
      } else {
        free(*epp);
        enemyList = NULL;
        break;
      }
    }
    epp = &((*epp)->m_next);
  }
}

void enemyManagerDraw(){
  enemyNode_t **epp = &enemyList;
  int num = 0;
  while (*epp != NULL) {
    if ((*epp)->m_enemyData.m_flag) {
      enemyDraw[(*epp)->m_enemyData.m_type](&((*epp)->m_enemyData));
      num++;
    }
    epp = &((*epp)->m_next);
  }
  //printf("enemyNum:%d\n", num);
}

void enemyManagerClean(){
  enemyNodeFree(&enemyList);
}

void enemyUpdate(enemy_t *enemy){
  enemyMove(enemy);
  enemy->m_count++;
  if (enemy->m_count == enemy->m_shotStartCount)
    //enterShot
    enemyShareEnterEnemyShot(enemy);
  if (isInside(enemy))
    enemy->m_flag = 0;
}

int isInside(enemy_t *enemy){
  if (enemy->m_count < 60)
    return 0;

  float size[2];
  enemySize[enemy->m_type](size);
  if (enemy->m_x < FIELD_START_X - size[0] / 2.0f ||
      enemy->m_x > FIELD_START_X + FIELD_SIZE_X + size[0] / 2.0f ||
      enemy->m_y < FIELD_START_Y - size[1] / 2.0f ||
      enemy->m_y > FIELD_START_Y + FIELD_SIZE_Y + size[1] / 2.0f)
    return 1;

  return 0;
}
