#include "key.h"

#include <GL/glut.h>
#include <stdio.h>

static unsigned char keys[256] = {};

void keyboard(unsigned char key, int x, int y);
void keyboardUp(unsigned char key, int x, int y);

void keyInit(){
  glutKeyboardFunc(keyboard);
  glutKeyboardUpFunc(keyboardUp);
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
