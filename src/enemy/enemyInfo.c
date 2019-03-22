#include "enemyInfo.h"

#include <stdlib.h>

void enemyCopy(const enemy_t const *e1, enemy_t *e2){
  e2->m_type = e1->m_type;
  e2->m_flag = e1->m_flag;
  e2->m_x = e1->m_x;
  e2->m_y = e1->m_y;
  e2->m_speed = e1->m_speed;
  e2->m_angle = e1->m_angle;
  e2->m_count = e1->m_count;
  e2->m_movePattern = e1->m_movePattern;
  e2->m_shotPattern = e1->m_shotPattern;
  e2->m_id = e1->m_id;
  e2->m_shotStartCount = e1->m_shotStartCount;
}

enemyNode_t *enemyNodeNew(const enemy_t const *enemyData, enemyNode_t *next){
  enemyNode_t *ep;
  ep = (enemyNode_t *)malloc(sizeof(enemyNode_t));
  if (ep == NULL)
    return NULL;

  enemyCopy(enemyData, &(ep->m_enemyData));
  ep->m_next = next;
  
  return ep;
}

int enemyNodeAppend(enemyNode_t **epp, const enemy_t* const enemy){
  enemyNode_t *ep;
  ep = enemyNodeNew(enemy, NULL);
  if (ep == NULL) return 1;

  while (*epp != NULL) {
    epp = &((*epp)->m_next);
  }

  *epp = ep;
  return 0;
}

void enemyShotCopy(const enemyShot_t const *s1, enemyShot_t *s2){
  s2->m_pattern = s1->m_pattern;
  s2->m_enemyId = s1->m_enemyId;
  s2->m_count = s1->m_count;
  s2->m_status = s1->m_status;
  s2->m_bulletList = NULL;
}

enemyShotNode_t *enemyShotNodeNew(const enemyShot_t const *shot, enemyShotNode_t *next){
  enemyShotNode_t *ep;
  ep = (enemyShotNode_t *)malloc(sizeof(enemyShotNode_t));
  if (ep == NULL)
    return NULL;

  enemyShotCopy(shot, &(ep->m_shotData));
  ep->m_next = next;
  
  return ep;
}

int enemyShotNodeAppend(enemyShotNode_t **epp, const enemyShot_t* const shot){
  enemyShotNode_t *ep;
  ep = enemyShotNodeNew(shot, NULL);
  if (ep == NULL) return 1;

  while (*epp != NULL) {
    epp = &((*epp)->m_next);
  }

  *epp = ep;
  return 0;
}

void enemyBulletCopy(const enemyBullet_t* const b1, enemyBullet_t *b2){
  b2->m_x = b1->m_x;
  b2->m_y = b1->m_y;
  b2->m_angle = b1->m_angle;
  b2->m_speed = b1->m_speed;
  b2->m_count = b1->m_count;
  b2->m_flag = b1->m_flag;
}

enemyBulletNode_t *enemyBulletNodeNew(const enemyBullet_t* const bullet, enemyBulletNode_t *next){
  enemyBulletNode_t *ep;
  ep = (enemyBulletNode_t *)malloc(sizeof(enemyBulletNode_t));
  if (ep == NULL)
    return NULL;

  enemyBulletCopy(bullet, &(ep->m_bulletData));
  ep->m_next = next;
  
  return ep;
}

int enemyBulletNodeAppend(enemyBulletNode_t **epp, const enemyBullet_t* const bullet){
  enemyBulletNode_t *ep;
  ep = enemyBulletNodeNew(bullet, NULL);
  if (ep == NULL) return 1;

  while (*epp != NULL) {
    epp = &((*epp)->m_next);
  }

  *epp = ep;
  return 0;
}

void enemyNodeFree(enemyNode_t **epp){
  enemyNode_t *temp;
  while (*epp != NULL) {
    temp = (*epp)->m_next;
    free(*epp);
    *epp = temp;
  }
}

void enemyBulletNodeFree(enemyBulletNode_t **epp){
  enemyBulletNode_t *temp;
  while (*epp != NULL) {
    temp = (*epp)->m_next;
    free(*epp);
    *epp = temp;
  }
}

void enemyShotNodeFree(enemyShotNode_t **epp){
  enemyShotNode_t *temp;
  while (*epp != NULL) {
    enemyBulletNodeFree(&((*epp)->m_shotData.m_bulletList));
    temp = (*epp)->m_next;
    free(*epp);
    *epp = temp;
  }
}
