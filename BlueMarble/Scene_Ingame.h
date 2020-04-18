#ifndef __SCENE_INGAME_H__
#define __SCENE_INGAME_H__

//예제장면(Scene Example) 초기화 함수
void Scene_Ingame_Init();
//예제장면(Scene Example) 렌더링 함수
bool Scene_Ingame_Render(float timeDelta);

///////////////////////////////////////

/// extern ///
extern bool Sn_Inform; //해당 함수 호출용 함수
extern int TURN, dice1, dice2;
extern int jail_count[5]; // 울릉 체류 카운트 -> Game_Play.cpp

extern PLAYER user, com1, com2, com3; //유저들의 정보를 extern? ( user_pos(), earse_pos()를  위해 설정 )
extern fields field[36];

// 헤더파일 //
#include "Draw_Field.h"
#include "Set_Area.h"
#include "Set_User.h"
#include "Scene_Inform.h"
#include"Game_Play.h"
#include "Chance.h"

#endif