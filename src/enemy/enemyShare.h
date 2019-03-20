#ifndef ___HEADER_ENEMYSHARE

#define ___HEADER_ENEMYSHARE


#include "enemyInfo.h"

void enemyShareSetEnemyStack(enemyNode_t **mainEnemyList);
const enemyNode_t* const enemyShareGetEnemyStack();

void enemyShareSetEnemyShotStack(enemyShotNode_t **mainEnemyShotList);

void enemyShareEnterEnemyShot(const enemy_t* const enemy);

#endif
