#ifndef __SCENE_H__
#define __SCENE_H__

//Draw / Input / FILEIO ���(h) Include
#include "Draw.h"
#include "Input.h"
#include "FileIO.h"
//��鼱�� ������ �Լ�
bool SceneRender(float timeDelta);

// FMOD. �뷡 ���ÿ� ����



//���� �������� ����ȣ
enum{ INTRO, MAINTAP, MANUAL, OPTION, FIXAREA,INGAME,INGAME_OPTION, GAMEOVER};

//�Ҹ� ���� 
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

// ����� - main.cpp //
extern System *pSystem;
extern Sound *pSound[13];
extern Channel *pChannel[2];


//�� ����
struct fields {
	char region_name[11]; // ������
	int area_pay; // ����
	int upgrade_pay; // ���׷��̵� ���
	int upgrade_data; // ���׷��̵� ����
	int anyhas; // 0 = �ƹ��� ���� x, 1~4 = �ش� �÷��̾��� ��, -1 = ���źҰ� ��
	int on; // ����� ��� �ִ°�
};

//���� ����
struct PLAYER {
	int who; // 1~4. n�� �÷��̾�.
	char name[10]; // �̸�
	int money; // ������
	int all_money; // ���ڻ�
	int where; // ��ġ
	int around; // �� ����
	int color; // ���� ��
	// ��������� //
	//int rank; // ����
};

//���ӿ� ���Ǵ� ��� ��� ���(h)����
#include "Game_Play.h"

#include "Scene_Intro.h" // ��Ʈ�� ��
#include "Scene_Ingame.h" // �ΰ��� ��
#include "Scene_Ingame_option.h" // �ΰ��� - �ɼ���
#include "Scene_Maintap.h" // ������
#include "Scene_Manual.h" // ������ - �޴�����
#include "Scene_Option.h" // ������ - �ɼ���
#include "Scene_FixArea.h" // ������ - ��������
#include "Scene_Gameover.h" // ���ӿ��� ��


#include "fmod.hpp" // fmod����



//////////////////////////////////////////
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <mmsyscom.h> // �Ҹ�

#pragma comment(lib,"winmm.lib")

#endif
