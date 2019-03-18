#include "enemyManager.h"

#include <GL/glut.h>
#include <stdlib.h>
#include "enemyAppearance.h"
#include "../scene/game/gameField.h"
#include <stdio.h>
#include "enemyMove.h"
#include <math.h>

typedef struct enemyNode_ {
  enemy_t m_enemyData;
  struct enemyNode_ *m_next; 
} enemyNode_t;

const static void (*enemyDraw[enemyTypeMax])(const enemy_t *) = {
  enemyType1Draw,
  enemyType2Draw,
};

const static void (*enemySize[enemyTypeMax])(float size[2]) = {
  enemyType1Size,
  enemyType2Size,
};

static enemyNode_t *enemyList;

void enemyInit(const enemy_t const *e1, enemy_t *e2);
enemyNode_t *enemyNodeNew(const enemy_t const *enemyData, enemyNode_t *next);
int enemyNodeAppend(enemyNode_t **epp, const enemy_t const *enemy);
void enemyUpdate(enemy_t *enemy);
int isInside(enemy_t *enemy);

void enemyManagerInit(){
  enemy_t enemy1 = {enemyType1, 1, 100.0f, -100.0f, 2.0f, M_PI / 2.0f, 0, 0};
  enemy_t enemy2 = {enemyType2, 1, 200.0f, 100.0f, 0.0f, 0.0f, 0, 0};
  enemyNodeAppend(&enemyList, &enemy1);
  enemyNodeAppend(&enemyList, &enemy2);
}

static int c = 0;

void enemyManagerUpdate(){
  c++;
  if (c == 1000) {
    enemy_t e = {enemyType1, 1, 100.0f, 50.0f, 2.0f, M_PI / 2.0f, 0, 0};
    enemyNodeAppend(&enemyList, &e);
  }
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
  printf("enemyNum:%d\n", num);
}

void enemyManagerClean(){
  enemyNode_t **epp = &enemyList;
  enemyNode_t *temp;
  while (*epp != NULL) {
    temp = (*epp)->m_next;
    free(*epp);
    *epp = temp;
  }
}

void enemyInit(const enemy_t const *e1, enemy_t *e2){
  e2->m_type = e1->m_type;
  e2->m_flag = e1->m_flag;
  e2->m_x = e1->m_x;
  e2->m_y = e1->m_y;
  e2->m_speed = e1->m_speed;
  e2->m_angle = e1->m_angle;
  e2->m_count = e1->m_count;
  e2->m_movePattern = e1->m_movePattern;
}

enemyNode_t *enemyNodeNew(const enemy_t const *enemyData, enemyNode_t *next){
  enemyNode_t *ep;
  ep = (enemyNode_t *)malloc(sizeof(enemyNode_t));
  if (ep == NULL)
    return NULL;

  enemyInit(enemyData, &(ep->m_enemyData));
  ep->m_next = next;
  
  return ep;
}

int enemyNodeAppend(enemyNode_t **epp, const enemy_t const *enemy){
  enemyNode_t *ep;
  ep = enemyNodeNew(enemy, NULL);
  if (ep == NULL) return 1;

  while (*epp != NULL) {
    epp = &((*epp)->m_next);
  }

  *epp = ep;
  return 0;
}

void enemyUpdate(enemy_t *enemy){
  enemyMove(enemy);
  enemy->m_count++;
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
