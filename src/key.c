#include "key.h"

#include <GL/glut.h>
#include <stdio.h>

static unsigned char keys[256] = {};

void keyboard(unsigned char key, int x, int y);
void keyboardUp(unsigned char key, int x, int y);
void specialKey(int key, int x, int y);
void specialKeyUp(int key, int x, int y);

void keyInit(){
  glutKeyboardFunc(keyboard);
  glutKeyboardUpFunc(keyboardUp);
  glutSpecialFunc(specialKey);
  glutSpecialUpFunc(specialKeyUp);
  glutIgnoreKeyRepeat(GL_TRUE);
}

int keyGetState(unsigned char key){
  return keys[key];
}

void keyboard(unsigned char key, int x, int y){
  printf("keyboard: \"%c\"(%#x)\n", key, key);
  keys[key] = 1;
}

void keyboardUp(unsigned char key, int x, int y){
  printf("keyboardUp: \"%c\"(%#x)\n", key, key);
  keys[key] = 0;
}

void specialKey(int key, int x, int y){
  if (key == GLUT_KEY_UP) {
    keys[KEY_UP] = 1;
  }
  if (key == GLUT_KEY_DOWN) {
    keys[KEY_DOWN] = 1;
  }
  if (key == GLUT_KEY_LEFT) {
    keys[KEY_LEFT] = 1;
  }
  if (key == GLUT_KEY_RIGHT) {
    keys[KEY_RIGHT] = 1;
  }
}

void specialKeyUp(int key, int x, int y){
  if (key == GLUT_KEY_UP) {
    keys[KEY_UP] = 0;
  }
  if (key == GLUT_KEY_DOWN) {
    keys[KEY_DOWN] = 0;
  }
  if (key == GLUT_KEY_LEFT) {
    keys[KEY_LEFT] = 0;
  }
  if (key == GLUT_KEY_RIGHT) {
    keys[KEY_RIGHT] = 0;
  }
}
