#include "ball.h"

#include <GL/glut.h>

void ballDraw(float x, float y, float r, unsigned char red, unsigned char green, unsigned char blue){
  glPushMatrix();
  
  glTranslatef(x, y, 0.0f);
  glColor3ub(red, green, blue);
  glScalef(r, r, 0.0f);
  glutSolidSphere(1, 16, 16);

  glPopMatrix();
}
