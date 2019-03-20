#ifndef ___HEADER_ENEMYINFO

#define ___HEADER_ENEMYINFO


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
  int m_movePattern;
  int m_shotPattern;
  int m_id;
  int m_shotStartCount;
} enemy_t;

typedef struct enemyNode_ {
  enemy_t m_enemyData;
  struct enemyNode_ *m_next; 
} enemyNode_t;

typedef struct enemyShot_ {
  int m_pattern;
  int m_enemyId;
  int m_count;
  int m_status;
} enemyShot_t;

typedef struct enemyShotNode_ {
  enemyShot_t m_shotData;
  struct enemyShotNode_ *m_next;
} enemyShotNode_t;


int enemyNodeAppend(enemyNode_t **epp, const enemy_t const *enemy);
int enemyShotNodeAppend(enemyShotNode_t **epp, const enemyShot_t const *shot);


#endif
