#ifndef ___HEADER_FONT
#define ___HEADER_FONT


#define FONT_DEFAULT_SIZE (100.0f)

void fontBegin();
void fontEnd();

void fontSetPosition(float _x, float _y);
void fontSetSize(float _size);
float fontGetSize();

float fontGetWeightMin();
float fontGetWeightMax();
void fontSetWeight(float _weight);

void fontSetColor(unsigned char _red, unsigned char _green, unsigned char _blue);
void fontDraw(const char *_format, ...);

#endif
