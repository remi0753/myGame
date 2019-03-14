#ifndef ___HEADER_ENEMYMANAGER

#define ___HEADER_ENEMYMANAGER


enum eEnemyType {
  enemyType1,
  enemyType2,
  enemyType3,
  enemyTypeMax
};

typedef struct enemy_ {
  enum eEnemyType m_type;
  int m_flag;
  float m_x;
  float m_y;
  float m_speed;
  float m_angle;
  int m_count;
} enemy_t;

void enemyManagerInit();
void enemyManagerUpdate();
void enemyManagerDraw();

#endif
