#include "sceneGame.h"

#include <GL/glut.h>
#include "../gameUtils.h"
#include "../../player.h"
#include "sceneGameBoard.h"
#include "../../enemy/enemyManager.h"
#include "../../enemy/enemyShotManager.h"
#include <stdio.h>
static int count;
static unsigned char param[SCENE_PARAMETER_MAX];
static player_t player;

void sceneGameInit(unsigned char *p){
  for (int i = 0; i < SCENE_PARAMETER_MAX; i++)
    param[i] = p[i];
  playerInit(&player);
  enemyManagerInit();
  enemyShotManagerInit();
  glClearColor(0.15f, 0.15f, 0.4f, 1.0f);
  count = 0;
}

void sceneGameUpdate(void (*changeSceneFunc)(enum eScene, unsigned char *, int)){
  //update
  count++;
  playerUpdate(&player);
  enemyManagerUpdate();
  enemyShotManagerUpdate();
  glutPostRedisplay();
}

void sceneGameDispaly(){
  glClear(GL_COLOR_BUFFER_BIT);
  
  drawBoard();
  playerDraw(&player);
  enemyManagerDraw();
  enemyShotManagerDraw();

  //draw count
  fontBegin();
  fontSetPosition(500, 50);
  fontSetSize(FONT_DEFAULT_SIZE * 0.2f);
  fontSetWeight(1.0f);
  fontSetColor(255, 255, 255);
  fontDraw("count:%d", count);
  fontEnd();

  glutSwapBuffers();

}

void sceneGameClean(){
  enemyShotManagerClean();
  enemyManagerClean();
}
