#include "sceneMenu.h"

#include <GL/glut.h>
#include "../gameUtils.h"

static int count = 0;
static unsigned char p[SCENE_PARAMETER_MAX] = {1,2,3};
static int testKeyFlag = 0;

void sceneMenuUpdate(void (*changeSceneFunc)(enum eScene, unsigned char *, int)){
  //update
  count++;

  if (keyGetState('a') && (!testKeyFlag))
    testKeyFlag = 1;
  if ((!keyGetState('a')) && testKeyFlag)
    testKeyFlag = 0;

  glutPostRedisplay();
}

void sceneMenuDispaly(){
  //font test
  glClear(GL_COLOR_BUFFER_BIT);
  fontBegin();
  fontSetPosition(0.0, 100.0);
  fontSetSize(FONT_DEFAULT_SIZE * 0.25);
  fontSetWeight(1.0);
  fontSetColor(0, 0, 255);
  fontDraw("meun");
  if (testKeyFlag) {
    fontSetPosition(0.0, 200);
    fontSetSize(FONT_DEFAULT_SIZE * 0.25);
    fontSetWeight(1.0);
    fontSetColor(0, 255, 0);
    fontDraw("key 'a' is pushed");
  }
  if (keyGetState(KEY_UP)) {
    fontSetPosition(0.0, 250.0);
    fontSetSize(FONT_DEFAULT_SIZE * 0.25);
    fontSetWeight(1.0);
    fontSetColor(0, 255, 0);
    fontDraw("key UP is pushed");
  }
  fontSetPosition(500.0, 400.0);
  fontSetSize(FONT_DEFAULT_SIZE * 0.15);
  fontSetWeight(1.0);
  fontSetColor(255, 255, 255);
  fontDraw("fps:%.1f", fpsGet());
  fontEnd();

  glutSwapBuffers();
}
