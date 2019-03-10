#include "sceneGame.h"

#include <GL/glut.h>
#include "../gameUtils.h"

static int count = 0;
static unsigned char param[SCENE_PARAMETER_MAX];

void sceneGameInit(unsigned char *p){
  for (int i = 0; i < SCENE_PARAMETER_MAX; i++)
    param[i] = p[i];
}

void sceneGameUpdate(void (*changeSceneFunc)(enum eScene, unsigned char *, int)){
  //update
  count++;

  if (count == 500){
    count = 0;
    changeSceneFunc(SCENE_MENU, param, 1);
  }
  
  glutPostRedisplay();
}

void sceneGameDispaly(){
  glClear(GL_COLOR_BUFFER_BIT);
  
  float test1 = 1.0f;
  int test2 = 23;

  //font test
  fontBegin();
  fontSetPosition(0.0, 100.0);
  fontSetSize(FONT_DEFAULT_SIZE * 0.25);
  fontSetWeight(1.0);
  fontSetColor(0, 0, 255);
  fontDraw("game(%d, %d, %d)", param[0], param[1], param[2]);
  fontEnd();

  glutSwapBuffers();

}
