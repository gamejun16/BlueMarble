#ifndef __SCENE_INGAME_H__
#define __SCENE_INGAME_H__

//�������(Scene Example) �ʱ�ȭ �Լ�
void Scene_Ingame_Init();
//�������(Scene Example) ������ �Լ�
bool Scene_Ingame_Render(float timeDelta);

///////////////////////////////////////

/// extern ///
extern bool Sn_Inform; //�ش� �Լ� ȣ��� �Լ�
extern int TURN, dice1, dice2;
extern int jail_count[5]; // �︪ ü�� ī��Ʈ -> Game_Play.cpp

extern PLAYER user, com1, com2, com3; //�������� ������ extern? ( user_pos(), earse_pos()��  ���� ���� )
extern fields field[36];

// ������� //
#include "Draw_Field.h"
#include "Set_Area.h"
#include "Set_User.h"
#include "Scene_Inform.h"
#include"Game_Play.h"
#include "Chance.h"

#endif