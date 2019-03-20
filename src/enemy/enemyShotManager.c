#include "enemyShotManager.h"

#include "enemyInfo.h"
#include "enemyShare.h"
#include <stdio.h>

static enemyShotNode_t *enemyShotList;

void enemyShotManagerInit(){
  enemyShareSetEnemyShotStack(&enemyShotList);
}

void enemyShotManagerUpdate(){

}

void enemyShotManagerDraw(){
  enemyShotNode_t **epp = &enemyShotList;
  int num = 0;
  while (*epp != NULL) {
    num++;
    epp = &((*epp)->m_next);
  }
  printf("enemyNum:%d\n", num);
}
