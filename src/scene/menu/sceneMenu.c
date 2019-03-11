#include "sceneMenu.h"

#include <GL/glut.h>
#include "../gameUtils.h"

static int count = 0;
static unsigned char param[SCENE_PARAMETER_MAX] = {1,2,3};

void sceneMenuUpdate(void (*changeSceneFunc)(enum eScene, unsigned char *, int)){
  //update
  count++;

  if (count > 60 && keyGetState('s'))
    changeSceneFunc(SCENE_GAME, param, 1);

  glutPostRedisplay();
}

void sceneMenuDispaly(){
  glClear(GL_COLOR_BUFFER_BIT);

  fontBegin();
  fontSetPosition(0.0, 100.0);
  fontSetSize(FONT_DEFAULT_SIZE * 0.25);
  fontSetWeight(1.0);
  fontSetColor(0, 0, 255);
  fontDraw("meun");
  fontSetPosition(500.0, 400.0);
  fontSetSize(FONT_DEFAULT_SIZE * 0.15);
  fontSetWeight(1.0);
  fontSetColor(255, 255, 255);
  fontDraw("fps:%.1f", fpsGet());
  fontEnd();

  glutSwapBuffers();
}
