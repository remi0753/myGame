#include "player.h"

#include "key.h"
#include <math.h>
#include <GL/glut.h>
#include "./shape/rect.h"
#include "./shape/ball.h"

static const float PLAYER_SPEED = 6.0f;
static const float PLAYER_RECT_SIZE = 15.0f;
static const unsigned char PLAYER_RECT_COLOR[3] = {230, 230, 230};
static const float PLAYER_CENTER_BALL_R = 4.0f;
static const unsigned char PLAYER_CENTER_BALL_COLOR[3] = {255, 100, 100};
static const float PLAYER_SIDE_BALL_POSITION = 16.0f;
static const float PLAYER_SIDE_BALL_R = 4.5f;
static const unsigned char PLAYER_SIDE_BALL_COLOR[3] = {64, 64, 255};
static const float PLAYER_FIRST_POSITION_X = 200.0f;
static const float PLAYER_FIRST_POSITION_Y = 400.0f;

static int count;

void move(player_t *player);

void playerInit(player_t *player){
  player->m_x = PLAYER_FIRST_POSITION_X;
  player->m_y = PLAYER_FIRST_POSITION_Y;
  count = 0;
}

void playerUpdate(player_t *player){
  move(player);
  count++;
}

void playerDraw(const player_t *player){
  rectDraw(player->m_x, 
           player->m_y,
           PLAYER_RECT_SIZE,
           PLAYER_RECT_SIZE,
           (float)(count % 360),
           PLAYER_RECT_COLOR[0],
           PLAYER_RECT_COLOR[1],
           PLAYER_RECT_COLOR[2]);

  if (player->m_slow)
    ballDraw(player->m_x,
             player->m_y,
             PLAYER_CENTER_BALL_R,
             PLAYER_CENTER_BALL_COLOR[0],
             PLAYER_CENTER_BALL_COLOR[1],
             PLAYER_CENTER_BALL_COLOR[2]);

  ballDraw(player->m_x - PLAYER_SIDE_BALL_POSITION,
           player->m_y,
           PLAYER_SIDE_BALL_R,
           PLAYER_SIDE_BALL_COLOR[0],
           PLAYER_SIDE_BALL_COLOR[1],
           PLAYER_SIDE_BALL_COLOR[2]);
  ballDraw(player->m_x + PLAYER_SIDE_BALL_POSITION,
           player->m_y,
           PLAYER_SIDE_BALL_R,
           PLAYER_SIDE_BALL_COLOR[0],
           PLAYER_SIDE_BALL_COLOR[1],
           PLAYER_SIDE_BALL_COLOR[2]);
}

void move(player_t *player){
  float x = 0.0f;
  float y = 0.0f;
  if (keyGetState('v'))
    player->m_slow = 1;
  if (!keyGetState('v') && player->m_slow)
    player->m_slow = 0;
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

  if (player->m_slow){
    x /= 3.0f;
    y /= 3.0f;
  }

  player->m_x += x;
  player->m_y += y;
}
