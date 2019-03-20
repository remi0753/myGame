#include "enemyShare.h"

#include "enemyInfo.h"
#include <stdio.h>

static enemyNode_t **copyEnemyList;
static enemyShotNode_t **copyEnemyShotList;

void enemyShareSetEnemyStack(enemyNode_t **mainEnemyList){
  copyEnemyList = mainEnemyList;
}

void enemyShareSetEnemyShotStack(enemyShotNode_t **mainEnemyShotList){
  copyEnemyShotList = mainEnemyShotList;
}

void enemyShareGetEnemyPosition(float p[2], int id){
  enemyNode_t **epp = copyEnemyList;
  while (*epp != NULL) {
    if ((*epp)->m_enemyData.m_id == id) {
      p[0] = (*epp)->m_enemyData.m_x;
      p[1] = (*epp)->m_enemyData.m_y;
      return;
    }
    epp = &((*epp)->m_next);
  }
  p[0] = -1.0f;
  return;
}

void enemyShareEnterEnemyShot(const enemy_t* const enemy){
  enemyShot_t s = {
    enemy->m_shotPattern,
    enemy->m_id,
    0,
    1};
  enemyShotNodeAppend(copyEnemyShotList, &s);
}
