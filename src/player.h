#ifndef ___HEADER_PLAYER

#define ___HEADER_PLAYER


typedef struct player_ {
  float m_x;
  float m_y;
} player_t;

void playerInit(player_t *player);
void playerUpdate(player_t *player);
void playerDraw(const player_t *player);


#endif
