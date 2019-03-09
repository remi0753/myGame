#include "fps.h"

#include <time.h>
#include <sys/time.h>
#include <unistd.h>
#include <math.h>
#include "font.h"
#include <GL/glut.h>

#define FPS 60
#define UPDATE_INTERVAL 60
#define STOCK_MAX 120

typedef struct stock_ {
  unsigned int m_d[STOCK_MAX];
  int m_pos;
  int m_len;
  int m_oldestPos;
} stock_t;

static struct timeval start;
static int count;
static float fps;
static stock_t stockTime;

unsigned int waitTime();
void regist();
unsigned int getMilliSecond();
void updateFps();

void fpsInit(){
  count = 0;
  fps = 0.0f;
  stockTime.m_pos = 0;
  stockTime.m_len = 0;
  stockTime.m_oldestPos = 0;
  gettimeofday(&start, NULL);
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

void fpsDraw(){
  fontBegin();
  fontSetPosition(500, 400);
  fontSetSize(FONT_DEFAULT_SIZE * 0.15);
  fontSetWeight(1.0);
  fontSetColor(255, 255, 255);
  fontDraw("fps:%.1f", fps);
  fontEnd();
}

unsigned int waitTime(){
  int len = stockTime.m_len;
  if (len == 0)
    return 0;

  int calcTime = (unsigned int)(1000.f / 60.f * len);
  int realTime = getMilliSecond() - stockTime.m_d[stockTime.m_oldestPos];
  int wait = calcTime - realTime;
  if (wait < 0) wait = 0;
  return wait;
}

void regist(){
  stockTime.m_d[stockTime.m_pos] = getMilliSecond();
  stockTime.m_pos++;
  if (stockTime.m_pos == STOCK_MAX)
    stockTime.m_pos = 0;
  if (stockTime.m_len < (STOCK_MAX - 1))
    stockTime.m_len++;
  else
    stockTime.m_oldestPos = stockTime.m_pos;
}

unsigned int getMilliSecond(){
  struct timeval tv;
  gettimeofday(&tv, NULL);
  time_t diffsec = difftime(tv.tv_sec, start.tv_sec);
  suseconds_t diffusec = tv.tv_usec - start.tv_usec;
  return (unsigned int)diffsec * 1000 + (unsigned int)(diffusec / 1000);
}

void updateFps(){
  int len = stockTime.m_len;
  if (len < (STOCK_MAX - 1))
    return;
  int op = stockTime.m_oldestPos;
  unsigned int realTime = op == 0 ?
    stockTime.m_d[STOCK_MAX - 1] - stockTime.m_d[0] :
    stockTime.m_d[op - 1] - stockTime.m_d[op];
  float average = (float)realTime / (float)STOCK_MAX;
  if (average == 0)
    return;
  fps = 1000.f / average;
}

