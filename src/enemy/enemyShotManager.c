#include "enemyShotManager.h"

#include "enemyInfo.h"
#include "enemyShare.h"
#include <stdio.h>
#include <stdlib.h>

static enemyShotNode_t *enemyShotList;

void enemyShotManagerInit(){
  enemyShareSetEnemyShotStack(&enemyShotList);
}

void enemyShotManagerUpdate(){
  enemyShotNode_t **epp = &enemyShotList;
  int num = 0;
  while (*epp != NULL) {
    epp = &((*epp)->m_next);
  }

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

void enemyShotManagerClean(){
  enemyShotNodeFree(&enemyShotList);
}
