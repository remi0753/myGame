#ifndef ___HEADER_SCENEGAME

#define ___HEADER_SCENEGAME


#include "scene.h"

void sceneGameUpdate(void (*changeSceneFunc)(enum eScene, unsigned char *, int));
void sceneGameDispaly();

void sceneGameInit(unsigned char *p);


#endif