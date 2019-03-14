#ifndef ___HEADER_BALL

#define ___HEADER_BALL


typedef struct ball_ {
  float m_x;
  float m_y;
  float m_r;
  unsigned char m_color[3];
} ball_t;

void ballBegin();
void ballEnd();
void ballDraw(float x, 
              float y, 
              float r, 
              unsigned char red, 
              unsigned char green, 
              unsigned char blue);


#endif
