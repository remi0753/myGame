#include "game.h"

#include <GL/glut.h>
#include "define.h"
#include "sceneManager.h"
#include "allScene.h"
#include "key.h"
#include "fps.h"

static sceneStack_t stk;
static scene_t allScene[SCENE_MAX] = {
  {sceneMenuUpdate, sceneMenuDispaly, 0},  //sceneMenu
  {sceneGameUpdate, sceneGameDispaly, 0}   //sceneGame
};

void glInit(int *argc, char **argv);
void gameLoop();

void gameInit(int *argc, char **argv){
  glInit(argc, argv);
  keyInit();
  fpsInit();
  sceneStackInit(&stk);

  unsigned char p[3] = {};
  sceneStackPush(
      &stk, 
      allScene[SCENE_MENU].m_update,
      allScene[SCENE_MENU].m_display,
      allScene[SCENE_MENU].m_parameter);
  glutDisplayFunc(allScene[SCENE_MENU].m_display);
}

void gameRun(){
  // test message
  glutMainLoop();
}

void glInit(int *argc, char **argv){
  //initialization
  glutInit(argc, argv);
  glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
  glutInitWindowPosition(500, 100);
  glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
  glutCreateWindow("myGame");
  glutIdleFunc(gameLoop);
}

void changeScene(enum eScene s, unsigned char *p, int clear){
  if (clear)
    sceneStackInit(&stk);

  sceneStackPush(
    &stk, 
    allScene[s].m_update,
    allScene[s].m_display,
    p);
  glutDisplayFunc(allScene[s].m_display);

  switch (s) {
    case SCENE_MENU:
      break;
    case SCENE_GAME:
      sceneGameInit(p);
      break;
    default:
      // error
      break;
  }
}
void gameLoop(){
  sceneStackTop(&stk)->m_update(changeScene);
  fpsWait();
}
