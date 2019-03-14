#include "enemyManager.h"

#include <GL/glut.h>
#include <math.h>
#include <stdlib.h>
#include "enemyAppearance.h"

typedef struct enemyNode_ {
  enemy_t m_enemyData;
  struct enemyNode_ *m_next; 
} enemyNode_t;

const static void (*enemyDraw[enemyTypeMax])(const enemy_t *) = {
  enemyType1Draw,
  enemyType2Draw,
};

static enemyNode_t *enemyList;

void enemyInit(const enemy_t const *e1, enemy_t *e2);
enemyNode_t *enemyNodeNew(const enemy_t const *enemyData, enemyNode_t *next);
int enemyNodeAppend(enemyNode_t **epp, const enemy_t const *enemy);
void enemyUpdate(enemy_t *enemy);

void enemyManagerInit(){
  enemy_t enemy1 = {enemyType1, 1, 100.0f, -100.0f, 2.0f, M_PI / 2.0f, 0};
  enemy_t enemy2 = {enemyType2, 1, 200.0f, 100.0f, 0.0f, 0.0f, 0};
  enemyNodeAppend(&enemyList, &enemy1);
  enemyNodeAppend(&enemyList, &enemy2);
}

void enemyManagerUpdate(){
  enemyNode_t **epp = &enemyList;
  while (*epp != NULL) {
    if ((*epp)->m_enemyData.m_flag) {
      enemyUpdate(&((*epp)->m_enemyData));
    }
    epp = &((*epp)->m_next);
  }
}

void enemyManagerDraw(){
  enemyNode_t **epp = &enemyList;
  while (*epp != NULL) {
    if ((*epp)->m_enemyData.m_flag) {
      enemyDraw[(*epp)->m_enemyData.m_type](&((*epp)->m_enemyData));
    }
    epp = &((*epp)->m_next);
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
}

enemyNode_t *enemyNodeNew(const enemy_t const *enemyData, enemyNode_t *next){
  enemyNode_t *ep;
  ep = (enemyNode_t *)malloc(sizeof(enemyNode_t));
  if (ep == NULL)
    return NULL;

  enemyInit(enemyData, &(ep->m_enemyData));
  ep->m_next = next;
  
  return ep;;
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
  enemy->m_count++;
  enemy->m_x += cos(enemy->m_angle) * enemy->m_speed;
  enemy->m_y += sin(enemy->m_angle) * enemy->m_speed;
}
