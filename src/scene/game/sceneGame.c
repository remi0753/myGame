#include "sceneGame.h"

#include <GL/glut.h>
#include "../gameUtils.h"
#include "../../player.h"

static int count = 0;
static unsigned char param[SCENE_PARAMETER_MAX];
static player_t player;

void sceneGameInit(unsigned char *p){
  for (int i = 0; i < SCENE_PARAMETER_MAX; i++)
    param[i] = p[i];
  playerInit(&player);
}

void sceneGameUpdate(void (*changeSceneFunc)(enum eScene, unsigned char *, int)){
  //update
  count++;
  playerUpdate(&player);
  glutPostRedisplay();
}

void sceneGameDispaly(){
  glClear(GL_COLOR_BUFFER_BIT);
  
  //font test
  fontBegin();
  fontSetPosition(0.0, 100.0);
  fontSetSize(FONT_DEFAULT_SIZE * 0.5);
  fontSetWeight(3.0);
  fontSetColor(0, 0, 255);
  fontDraw("game");
  fontSetPosition(500.0, 400.0);
  fontSetSize(FONT_DEFAULT_SIZE * 0.15);
  fontSetWeight(1.0);
  fontSetColor(255, 255, 255);
  fontDraw("fps:%.1f", fpsGet());
  fontEnd();

  playerDraw(&player);

  glutSwapBuffers();

}
