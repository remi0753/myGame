#include "sceneGame.h"

#include <GL/glut.h>
#include "../gameUtils.h"
#include "../../player.h"
#include "sceneGameBoard.h"

static int count = 0;
static unsigned char param[SCENE_PARAMETER_MAX];
static player_t player;

void sceneGameInit(unsigned char *p){
  for (int i = 0; i < SCENE_PARAMETER_MAX; i++)
    param[i] = p[i];
  playerInit(&player);
  glClearColor(0.15f, 0.15f, 0.4f, 1.0f);
}

void sceneGameUpdate(void (*changeSceneFunc)(enum eScene, unsigned char *, int)){
  //update
  count++;
  playerUpdate(&player);
  glutPostRedisplay();
}

void sceneGameDispaly(){
  glClear(GL_COLOR_BUFFER_BIT);
  
  drawBoard();
  playerDraw(&player);

  glutSwapBuffers();

}
