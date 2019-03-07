#include "sceneMenu.h"

#include <GL/glut.h>
#include "font.h"

static int count = 0;
static unsigned char p[SCENE_PARAMETER_MAX] = {1,2,3};

void sceneMenuUpdate(void (*changeSceneFunc)(enum eScene, unsigned char *, int)){
  //update
  count++;

  if (count == 500){
    count = 0;
    changeSceneFunc(SCENE_GAME, p, 1);
  }
  
  glutPostRedisplay();
}

void sceneMenuDispaly(){
  glClear(GL_COLOR_BUFFER_BIT);
  
  float test1 = 1.0f;
  int test2 = 23;

  //font test
  fontBegin();
  fontSetPosition(0.0, 100.0);
  fontSetSize(FONT_DEFAULT_SIZE * 0.25);
  fontSetWeight(1.0);
  fontSetColor(0, 0, 255);
  fontDraw("meun");
  fontEnd();

  glutSwapBuffers();

}
