#include "font.h"

#include <GL/glut.h>
#include <stdio.h>
#include <stdarg.h>

static float positionX;
static float positionY;
static float size = FONT_DEFAULT_SIZE;
static unsigned char color[3];
static float weight = 1.0;

void fontBegin(){
  glPushMatrix();
  glPushAttrib(GL_ALL_ATTRIB_BITS);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  GLint viewport[4];
  glGetIntegerv(GL_VIEWPORT, viewport);
  gluOrtho2D(0, viewport[2], viewport[3], 0);// left right bottom top

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

void fontEnd(){
  glPopMatrix();
  glPopAttrib();
}

void fontSetPosition(float _x, float _y){
  positionX = _x;
  positionY = _y;
}

void fontSetSize(float _size){
  size = _size;
}

float fontGetSize(){
  return size;
}

float fontGetWeightMin(){
  GLfloat weight[2];
  glGetFloatv(GL_LINE_WIDTH_RANGE, weight);
  return weight[0];
}

float fontGetWeightMax(){
  GLfloat weight[2];
  glGetFloatv(GL_LINE_WIDTH_RANGE, weight);
  return weight[1];
}

void fontSetWeight(float _weight){
  weight = _weight;
}

void fontSetColor(unsigned char _red, unsigned char _green, unsigned char _blue){
  color[0] = _red;
  color[1] = _green;
  color[2] = _blue;
}

void fontDraw(const char *_format, ...){
  va_list argList;
  va_start(argList, _format);
  char str[256];
  vsprintf(str, _format, argList);
  va_end(argList);

  glLineWidth(weight);
  glColor3ub(color[0], color[1], color[2]);
  glPushMatrix();
  {
    glTranslatef(positionX, positionY + size, 0.0);
    float s = size / FONT_DEFAULT_SIZE;
    glScalef(s, -s, s);
    for (char *p = str; *p != '\0'; p++)
      glutStrokeCharacter(GLUT_STROKE_ROMAN, *p);
  }
  glPopMatrix();
}
