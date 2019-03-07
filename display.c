#include "display.h"

#include <GL/glut.h>
#include "font.h"

void displayMain(){
  glClear(GL_COLOR_BUFFER_BIT);
  
  float test1 = 1.0f;
  int test2 = 23;

  //font test
  fontBegin();
  fontSetPosition(0.0, 100.0);
  fontSetSize(FONT_DEFAULT_SIZE * 0.25);
  fontSetWeight(1.0);
  fontSetColor(0, 0, 255);
  fontDraw("float:%f, int:%d", test1, test2);
  fontEnd();

  glutSwapBuffers();

}
