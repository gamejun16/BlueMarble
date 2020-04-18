#ifndef __GAME_PLAY__
#define __GAME_PLAY__

// Game_Play

//타이머 ( Sleep() 대신 )
void Timer(float t_1);

//유저의 진행
void Game_Play(struct fields *field, struct PLAYER *user, struct PLAYER *com1, struct PLAYER *com2, struct PLAYER *com3, int option);
//ai의 진행
void AI_Play(struct fields *field, struct PLAYER *user, struct PLAYER *com1, struct PLAYER *com2, struct PLAYER *com3, int option);
//게임오버 체크
bool Over_Check(struct PLAYER *user, struct PLAYER *com1, struct PLAYER *com2, struct PLAYER *com3);

// extern //
extern const float TIME;


//bool OVER_lock; // 게임종료 안전장치



/*
optino의 사용
0:
a = user
b = com1
c = com2
d = com3

1:
a = user
b = com2
c = com1
d = com3

*/



//void AI_Play(struct fields *field, struct PLAYER *user, struct PLAYER *com1, struct PLAYER *com2, struct PLAYER *com3);
#endif
