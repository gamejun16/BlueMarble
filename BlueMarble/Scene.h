#ifndef __SCENE_H__
#define __SCENE_H__

//Draw / Input / FILEIO 헤더(h) Include
#include "Draw.h"
#include "Input.h"
#include "FileIO.h"
//장면선택 렌더링 함수
bool SceneRender(float timeDelta);

// FMOD. 노래 선택용 변수



//현재 보여지는 장면번호
enum{ INTRO, MAINTAP, MANUAL, OPTION, FIXAREA,INGAME,INGAME_OPTION, GAMEOVER};

//소리 관련 
enum {Intro, BGM1, BGM2, BGM3,BGM4, Dice, Button, Enter,Bell ,Oops,Money,Error, Ending};



//

//extern
extern int SceneNumber;
extern int select_BGM;


/// FMOD ///
#include <conio.h>
#include <iostream>
using namespace std;
#include "fmod.hpp"
#pragma	comment (lib, "fmodex_vc.lib")
using namespace FMOD;

// 선언부 - main.cpp //
extern System *pSystem;
extern Sound *pSound[13];
extern Channel *pChannel[2];


//땅 정보
struct fields {
	char region_name[11]; // 지역명
	int area_pay; // 땅값
	int upgrade_pay; // 업그레이드 비용
	int upgrade_data; // 업그레이드 상태
	int anyhas; // 0 = 아무도 소유 x, 1~4 = 해당 플레이어의 땅, -1 = 구매불가 땅
	int on; // 몇명이 밟고 있는가
};

//유저 정보
struct PLAYER {
	int who; // 1~4. n번 플레이어.
	char name[10]; // 이름
	int money; // 소지금
	int all_money; // 총자산
	int where; // 위치
	int around; // 몇 바퀴
	int color; // 유저 색
	// 게임종료시 //
	//int rank; // 순위
};

//게임에 사용되는 모든 장면 헤더(h)파일
#include "Game_Play.h"

#include "Scene_Intro.h" // 인트로 씬
#include "Scene_Ingame.h" // 인게임 씬
#include "Scene_Ingame_option.h" // 인게임 - 옵션탭
#include "Scene_Maintap.h" // 메인탭
#include "Scene_Manual.h" // 메인탭 - 메뉴얼탭
#include "Scene_Option.h" // 메인탭 - 옵션탭
#include "Scene_FixArea.h" // 메인탭 - 땅설정탭
#include "Scene_Gameover.h" // 게임오버 씬


#include "fmod.hpp" // fmod관련



//////////////////////////////////////////
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <mmsyscom.h> // 소리

#pragma comment(lib,"winmm.lib")

#endif
