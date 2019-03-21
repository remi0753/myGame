#include "enemyShotManager.h"

#include "enemyInfo.h"
#include "enemyShare.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "danmaku.h"
#include "enemyBullet.h"
#include "../scene/game/gameField.h"

static enemyShotNode_t *enemyShotList;

void updateShot(enemyShot_t *shot);
void drawShot(enemyShot_t *shot);

void enemyShotManagerInit(){
  enemyShareSetEnemyShotStack(&enemyShotList);
}

void enemyShotManagerUpdate(){
  enemyShotNode_t **epp = &enemyShotList;
  while (*epp != NULL) {
    if ((*epp)->m_shotData.m_status > 0) {
      danmaku(&((*epp)->m_shotData));
      updateShot(&((*epp)->m_shotData));
    } else {
      if ((*epp)->m_shotData.m_bulletList != NULL) 
        enemyBulletNodeFree(&((*epp)->m_shotData.m_bulletList));

      if ((*epp)->m_next != NULL) {
        enemyShotNode_t *temp = (*epp)->m_next;
        free(*epp);
        *epp = temp;
      } else {
        free(*epp);
        enemyShotList = NULL;
        break;
      }
    }
    epp = &((*epp)->m_next);
  }
}

void enemyShotManagerDraw(){
  enemyShotNode_t **epp = &enemyShotList;
  int num = 0;
  while (*epp != NULL) {
    if ((*epp)->m_shotData.m_status > 0) {
      num++;
      drawShot(&((*epp)->m_shotData));
    }
    epp = &((*epp)->m_next);
  }
  //printf("enemyNum:%d\n", num);
}

void enemyShotManagerClean(){
  enemyShotNodeFree(&enemyShotList);
}

void updateShot(enemyShot_t *shot){
  int eflag = enemyShareGetEnemyFlag(shot->m_enemyId);
  
  if (eflag != 1)
    shot->m_status = 2;

  int num = 0;
  enemyBulletNode_t **epp = &(shot->m_bulletList);
  while (*epp != NULL) {
    if ((*epp)->m_bulletData.m_flag) {
      (*epp)->m_bulletData.m_x +=
        cos((*epp)->m_bulletData.m_angle) * (*epp)->m_bulletData.m_speed;
      (*epp)->m_bulletData.m_y +=
        sin((*epp)->m_bulletData.m_angle) * (*epp)->m_bulletData.m_speed;
      (*epp)->m_bulletData.m_count++;
      num++;
    } else {
      if ((*epp)->m_next != NULL) {
        enemyBulletNode_t *temp = (*epp)->m_next;
        free(*epp);
        *epp = temp;
      } else {
        free(*epp);
        *epp = NULL;
        break;
      }
    }
    //outside judge
    if ((*epp)->m_bulletData.m_x < FIELD_START_X - 20.0f ||
        (*epp)->m_bulletData.m_y < FIELD_START_Y - 20.0f ||
        (*epp)->m_bulletData.m_x > FIELD_START_X + FIELD_SIZE_X + 20.0f ||
        (*epp)->m_bulletData.m_y > FIELD_START_Y + FIELD_SIZE_Y + 20.0f)
      (*epp)->m_bulletData.m_flag = 0;

    epp = &((*epp)->m_next);
  }
  //printf("bulnum:%d\n", num);

  if (*epp == NULL && eflag != 1) {
    shot->m_status = 0;
    return;
  }

  shot->m_count++;
}

void drawShot(enemyShot_t *shot){
  enemyBulletNode_t **epp = &(shot->m_bulletList);
  while (*epp != NULL) {
    if ((*epp)->m_bulletData.m_flag) {
      drawBullet(&((*epp)->m_bulletData));
    }
    epp = &((*epp)->m_next);
  }
}
