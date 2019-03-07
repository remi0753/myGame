#include "scene.h"

#include <GL/glut.h>

void sceneStackPush(sceneStack_t *stk, updateFunc update, displayFunc display, unsigned char *p){
  if (stk->m_top < (SCENE_STACK_MAX - 1)) {
    stk->m_top++;
    int t = stk->m_top;
    stk->m_scene[t].m_update = update;
    stk->m_scene[t].m_display = display;
    for (int i = 0; i < SCENE_PARAMETER_MAX; i++)
      stk->m_scene[t].m_parameter[i] = p[i];

  } else {
    //スタックプッシュエラー
  }
}

void sceneStackPop(sceneStack_t *stk){
  if (stk->m_top > 0) {
    stk->m_top--;
  } else {
    //スタックポップエラー
  }
}

void sceneStackInit(sceneStack_t *stk){
  stk->m_top = 0;
}

scene_t *sceneStackTop(sceneStack_t *stk){
  return &(stk->m_scene[stk->m_top]);
}

