#ifndef __GAME_PLAY__
#define __GAME_PLAY__

// Game_Play

//Ÿ�̸� ( Sleep() ��� )
void Timer(float t_1);

//������ ����
void Game_Play(struct fields *field, struct PLAYER *user, struct PLAYER *com1, struct PLAYER *com2, struct PLAYER *com3, int option);
//ai�� ����
void AI_Play(struct fields *field, struct PLAYER *user, struct PLAYER *com1, struct PLAYER *com2, struct PLAYER *com3, int option);
//���ӿ��� üũ
bool Over_Check(struct PLAYER *user, struct PLAYER *com1, struct PLAYER *com2, struct PLAYER *com3);

// extern //
extern const float TIME;


//bool OVER_lock; // �������� ������ġ



/*
optino�� ���
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
