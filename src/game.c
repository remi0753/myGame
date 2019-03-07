#include "game.h"

#include <GL/glut.h>
#include "define.h"
#include "display.h"

void glInit(int *argc, char **argv);


void gameInit(int *argc, char **argv){
  glInit(argc, argv);
}

void gameRun(){
  glutMainLoop();
}

void glInit(int *argc, char **argv){
  //initialization
  glutInit(argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE);
  glutInitWindowPosition(100, 100);
  glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
  glutCreateWindow("myGame");
  glutDisplayFunc(displayMain);
}
