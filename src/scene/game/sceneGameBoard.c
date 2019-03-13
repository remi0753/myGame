#include "sceneGameBoard.h"

#include "../gameUtils.h"
#include "../../shape/rect.h"
#include "gameField.h"

void drawBoard(){
  fontBegin();
  //rogo
  fontSetPosition(425.0, 305.0);
  fontSetSize(FONT_DEFAULT_SIZE * 0.3);
  fontSetWeight(4.0);
  fontSetColor(255, 150, 150);
  fontDraw("DANMAKU");
  fontSetPosition(440.0, 340.0);
  fontSetSize(FONT_DEFAULT_SIZE * 0.3);
  fontSetWeight(4.0);
  fontSetColor(255, 255, 100);
  fontDraw("SHOOTING");
  fontSetPosition(430.0, 380.0);
  fontSetSize(FONT_DEFAULT_SIZE * 0.12);
  fontSetWeight(1.0);
  fontSetColor(200, 200, 200);
  fontDraw("- respect for touhou -");

  //fps
  fontSetPosition(550.0, 440.0);
  fontSetSize(FONT_DEFAULT_SIZE * 0.15);
  fontSetWeight(2.0);
  fontSetColor(5, 5, 5);
  fontDraw("fps:%.1f", fpsGet());
  fontEnd();

  rectDraw(
      FIELD_START_X + FIELD_SIZE_X / 2.0f,
      FIELD_START_Y + FIELD_SIZE_Y / 2.0f,
      FIELD_SIZE_X,
      FIELD_SIZE_Y,
      0.0,
      10,
      10,
      10);
}
