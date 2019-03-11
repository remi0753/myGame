#include "rect.h"

#include <GL/glut.h>

void rectDraw(float x, float y, float width, float height, float angle, unsigned char red, unsigned char green, unsigned char blue){
  glPushMatrix();
  glTranslatef(x, y, 0.0f);
  glColor3ub(red, green, blue);
  glRotatef(angle, 0.0f, 0.0f, 1.0f);
  glRectf(-width / 2.0f, -height / 2.0f, width / 2.0f, height / 2.0f);
  
  glPopMatrix();
}
