#include "sceneGameBoard.h"

#include "../gameUtils.h"
#include "../../shape/rect.h"
#include "gameField.h"

const static float BOARD_ROGO_1_POSITION_X = 425.0f;
const static float BOARD_ROGO_1_POSITION_Y = 305.0f;
const static float BOARD_ROGO_1_SIZE = 0.3f;
const static float BOARD_ROGO_1_WEIGHT = 4.0f;
const static unsigned char BOARD_ROGO_1_COLOR[3] = {255, 150, 150};
const static char BOARD_ROGO_1_STRING[8] = "DANMAKU";
const static float BOARD_ROGO_2_POSITION_X = 440.0f;
const static float BOARD_ROGO_2_POSITION_Y = 340.0f;
const static float BOARD_ROGO_2_SIZE = 0.3f;
const static float BOARD_ROGO_2_WEIGHT = 4.0f;
const static unsigned char BOARD_ROGO_2_COLOR[3] = {255, 255, 100};
const static char BOARD_ROGO_2_STRING[9] = "SHOOTING";
const static float BOARD_ROGO_3_POSITION_X = 430.0f;
const static float BOARD_ROGO_3_POSITION_Y = 380.0f;
const static float BOARD_ROGO_3_SIZE = 0.12f;
const static float BOARD_ROGO_3_WEIGHT = 1.0f;
const static unsigned char BOARD_ROGO_3_COLOR[3] = {210, 210, 210};
const static char BOARD_ROGO_3_STRING[23] = "- respect for touhou -";
const static float BOARD_FPS_POSITION_X = 550.0f;
const static float BOARD_FPS_POSITION_Y = 440.0f;
const static float BOARD_FPS_SIZE = 0.15f;
const static float BOARD_FPS_WEIGHT = 2.0f;
const static unsigned char BOARD_FPS_COLOR[3] = {210, 210, 210};

const static unsigned char FIELD_COLOR[3] = {10, 10, 10};

void drawBoard(){
  fontBegin();
  //rogo
  fontSetPosition(BOARD_ROGO_1_POSITION_X, BOARD_ROGO_1_POSITION_Y);
  fontSetSize(FONT_DEFAULT_SIZE * BOARD_ROGO_1_SIZE);
  fontSetWeight(BOARD_ROGO_1_WEIGHT);
  fontSetColor(BOARD_ROGO_1_COLOR[0], BOARD_ROGO_1_COLOR[1], BOARD_ROGO_1_COLOR[2]);
  fontDraw(BOARD_ROGO_1_STRING);
  fontSetPosition(BOARD_ROGO_2_POSITION_X, BOARD_ROGO_2_POSITION_Y);
  fontSetSize(FONT_DEFAULT_SIZE * BOARD_ROGO_2_SIZE);
  fontSetWeight(BOARD_ROGO_2_WEIGHT);
  fontSetColor(BOARD_ROGO_2_COLOR[0], BOARD_ROGO_2_COLOR[1], BOARD_ROGO_2_COLOR[2]);
  fontDraw(BOARD_ROGO_2_STRING);
  fontSetPosition(BOARD_ROGO_3_POSITION_X, BOARD_ROGO_3_POSITION_Y);
  fontSetSize(FONT_DEFAULT_SIZE * BOARD_ROGO_3_SIZE);
  fontSetWeight(BOARD_ROGO_3_WEIGHT);
  fontSetColor(BOARD_ROGO_3_COLOR[0], BOARD_ROGO_3_COLOR[1], BOARD_ROGO_3_COLOR[2]);
  fontDraw(BOARD_ROGO_3_STRING);

  //fps
  fontSetPosition(BOARD_FPS_POSITION_X, BOARD_FPS_POSITION_Y);
  fontSetSize(FONT_DEFAULT_SIZE * BOARD_FPS_SIZE);
  fontSetWeight(BOARD_FPS_WEIGHT);
  fontSetColor(BOARD_FPS_COLOR[0], BOARD_FPS_COLOR[1], BOARD_FPS_COLOR[2]);
  fontDraw("fps:%.1f", fpsGet());
  fontEnd();

  rectDraw(
      FIELD_START_X + FIELD_SIZE_X / 2.0f,
      FIELD_START_Y + FIELD_SIZE_Y / 2.0f,
      FIELD_SIZE_X,
      FIELD_SIZE_Y,
      0.0,
      FIELD_COLOR[0],
      FIELD_COLOR[1],
      FIELD_COLOR[2]);
}
