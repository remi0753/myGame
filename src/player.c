#include "player.h"

#include "key.h"
#include <math.h>
#include <GL/glut.h>
#include "./shape/rect.h"
#include "./shape/ball.h"

static const float PLAYER_SPEED = 5.0f;
static const float PLAYER_RECT_SIZE = 15.0f;
static const float PLAYER_BALL_R = 4.0f;
static const float PLAYER_FIRST_POSITION_X = 200.0f;
static const float PLAYER_FIRST_POSITION_Y = 400.0f;

void move(player_t *player);

void playerInit(player_t *player){
  player->m_x = PLAYER_FIRST_POSITION_X;
  player->m_y = PLAYER_FIRST_POSITION_Y;
}

void playerUpdate(player_t *player){
  move(player);
}

void playerDraw(const player_t *player){
  rectDraw(player->m_x, 
           player->m_y,
           PLAYER_RECT_SIZE,
           PLAYER_RECT_SIZE,
           45.0f,
           240,
           240,
           240);
  ballDraw(player->m_x,
           player->m_y,
           PLAYER_BALL_R,
           255,
           128,
           128);
}

void move(player_t *player){
  float x = 0.0f;
  float y = 0.0f;
  if (keyGetState(KEY_UP))
    y -= PLAYER_SPEED;

  if (keyGetState(KEY_DOWN))
    y += PLAYER_SPEED;

  if (keyGetState(KEY_LEFT))
    x -= PLAYER_SPEED;

  if (keyGetState(KEY_RIGHT))
    x += PLAYER_SPEED;

  if (x != 0.0f && y != 0.0f){
    x /= (float)sqrt(2.0);
    y /= (float)sqrt(2.0);
  }

  if (keyGetState(KEY_SHIFT)){
    x /= 2.0f;
    y /= 2.0f;
  }

  player->m_x += x;
  player->m_y += y;
}
