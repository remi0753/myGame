#ifndef ___HEADER_SCENEGAME

#define ___HEADER_SCENEGAME


#include "../../sceneManager.h"

void sceneGameUpdate(void (*changeSceneFunc)(enum eScene, unsigned char *, int));
void sceneGameDispaly();

void sceneGameInit(unsigned char *p);
void sceneGameClean();


#endif
