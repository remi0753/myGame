#ifndef ___HEADER_ENEMYSHARE

#define ___HEADER_ENEMYSHARE


#include "enemyInfo.h"

void enemyShareSetEnemyStack(enemyNode_t **mainEnemyList);
void enemyShareSetEnemyShotStack(enemyShotNode_t **mainEnemyShotList);

void enemyShareGetEnemyPosition(float p[2], int id);
void enemyShareEnterEnemyShot(const enemy_t* const enemy);

#endif
