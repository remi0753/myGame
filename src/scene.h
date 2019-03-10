#ifndef ___HEADER_SCENE

#define ___HEADER_SCENE

enum eScene {
  SCENE_MENU,
  SCENE_GAME,
  SCENE_MAX
};

#define SCENE_PARAMETER_MAX 3

#define SCENE_STACK_MAX 8

typedef void (*updateFunc)(void (*changeSceneFunc)(enum eScene, unsigned char *, int));
typedef void (*displayFunc)(void);
typedef struct scene_ {
  updateFunc m_update;
  displayFunc m_display;
  unsigned char m_parameter[SCENE_PARAMETER_MAX];
} scene_t;

typedef struct sceneStack_ {
  scene_t m_scene[SCENE_STACK_MAX];
  int m_top;
} sceneStack_t;

void sceneStackPush(sceneStack_t *stk, updateFunc update, displayFunc display, unsigned char *p);
void sceneStackPop(sceneStack_t *stk);
void sceneStackInit(sceneStack_t *stk);
scene_t *sceneStackTop(sceneStack_t *stk);


#endif
