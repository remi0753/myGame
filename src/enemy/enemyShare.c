#include "enemyShare.h"

#include "enemyInfo.h"

static enemyNode_t **copyEnemyList;
static enemyShotNode_t **copyEnemyShotList;

void enemyShareSetEnemyStack(enemyNode_t **mainEnemyList){
  copyEnemyList = mainEnemyList;
}

const enemyNode_t* const enemyShareGetEnemyStack(){
  return *copyEnemyList;
}

void enemyShareSetEnemyShotStack(enemyShotNode_t **mainEnemyShotList){
  copyEnemyShotList = mainEnemyShotList;
}

void enemyShareEnterEnemyShot(const enemy_t* const enemy){
  enemyShot_t s = {
    enemy->m_shotPattern,
    enemy->m_id,
    0,
    0};
  enemyShotNodeAppend(copyEnemyShotList, &s);
}
