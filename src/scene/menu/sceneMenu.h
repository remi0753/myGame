#ifndef ___HEADER_SCENEMENU

#define ___HEADER_SCENEMENU


#include "../../sceneManager.h"

void sceneMenuUpdate(void (*changeSceneFunc)(enum eScene, unsigned char *, int));
void sceneMenuDispaly();


#endif
