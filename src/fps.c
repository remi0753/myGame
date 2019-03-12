#include "fps.h"

#include <unistd.h>
#include "font.h"
#include <GL/glut.h>
//#include <stdio.h>

#define FPS 60
#define UPDATE_INTERVAL 60
#define STOCK_MAX 120

typedef struct stock_ {
  unsigned int m_d[STOCK_MAX];
  int m_pos;
  int m_len;
  int m_oldestPos;
} stock_t;

static int count;
static float fps;
static stock_t stockTime;

unsigned int waitTime();
void regist();
void updateFps();

void fpsInit(){
  count = 0;
  fps = 0.0f;
  stockTime.m_pos = 0;
  stockTime.m_len = 0;
  stockTime.m_oldestPos = 0;
  for (int i = 0; i < STOCK_MAX; i++)
    stockTime.m_d[i] = 0;
}

void fpsWait(){
  count++;
  usleep(waitTime() * 1000);
  regist();
  if (count == UPDATE_INTERVAL){
    updateFps();
    count = 0;
  }
}

float fpsGet(){
  return fps;
}

unsigned int waitTime(){
  int len = stockTime.m_len;
  if (len == 0)
    return 0;

  float calcTime = 1000.f / (float)FPS * ((float)len);
  int realTime = 
    glutGet(GLUT_ELAPSED_TIME) - (int)stockTime.m_d[stockTime.m_oldestPos];
  float wait = calcTime - (float)realTime;
  //printf("%.2f\n", wait);
  if (wait > 17){
    wait = 17;
  }
  if (wait < 0) wait = 0;
  return (unsigned int)wait;
}

void regist(){
  stockTime.m_d[stockTime.m_pos] = (unsigned int)glutGet(GLUT_ELAPSED_TIME);
  stockTime.m_pos++;
  if (stockTime.m_pos == STOCK_MAX)
    stockTime.m_pos = 0;
  if (stockTime.m_len < STOCK_MAX)
    stockTime.m_len++;
  else
    stockTime.m_oldestPos = stockTime.m_pos;
}

void updateFps(){
  int len = stockTime.m_len;
  if (len < STOCK_MAX)
    return;

  const int op = stockTime.m_oldestPos;
  unsigned int realTime = op == 0 ?
    stockTime.m_d[STOCK_MAX - 1] - stockTime.m_d[0] :
    stockTime.m_d[op - 1] - stockTime.m_d[op];
  float average = (float)realTime / (float)(STOCK_MAX - 1);
  if (average == 0)
    return;
  fps = 1000.f / average;
}

