#include <conio.h>
#include <iostream>
using namespace std;

#include "Scene.h"
#include "Scene_Ingame_Option.h"

#include "fmod.hpp"
#pragma	comment (lib, "fmodex_vc.lib")
using namespace FMOD;

// bgm ����
//float fVolume = 0.5;
//int fVolume_int = 5;

// ȿ���� ����
//float eVolume = 0.5;
//int eVolume_int = 5;

// ������ġ
//bool BGM_on = false;

void Scene_Ingame_Option_Init()
{
	//Ingame�� �˸�â�� ����//

	Draw(46, 13, WHITE, "������������");
	Draw(46, 14, WHITE, "��������������������"); // test_ver
	Draw(46, 15, WHITE, "��������");
	Draw(46, 16, WHITE, "��������������");

	//system("cls");
}


bool Scene_Ingame_Option_Render(float timeDelta)
{

	switch (fVolume_int) {
	case 10:
		Draw(48, 12, BG_RED, " ");
	case 9:
		Draw(46, 12, BG_RED, " ");
	case 8:
		Draw(44, 12, BG_RED, " ");
	case 7:
		Draw(42, 12, BG_YELLOW, " ");
	case 6:
		Draw(40, 12, BG_YELLOW, " ");
	case 5:
		Draw(38, 12, BG_YELLOW, " ");
	case 4:
		Draw(36, 12, BG_GREEN, " ");
	case 3:
		Draw(34, 12, BG_GREEN, " ");
	case 2:
		Draw(32, 12, BG_GREEN, " ");
	case 1:
		Draw(30, 12, BG_GREEN, " ");
	}

	Draw(30, 14, WHITE, "+.    �����Ű���");
	//cout << "-. ��������̱�" << endl;
	Draw(30, 16, WHITE, "-.    ��������̱�");
	//cout << "�ٷ� �Է� >>";
	Draw(30, 18, WHITE, "select_BGM: %d", select_BGM);

	Draw(30, 20, WHITE, ">.    BGM �ٲٱ�");

	Draw(30, 22, WHITE, "<.    BGM �ٲٱ�");

	Draw(30, 24, WHITE, "ENTER.���� �� ������");

	Draw(30, 26, WHITE, "SPACE.���� ����");

	if (_kbhit())
	{
		char cChar = _getch();

		if (cChar == '+') {
			pChannel[0]->getVolume(&fVolume);
			pChannel[0]->setVolume(fVolume + 0.1f);
			if (fVolume_int != 10)fVolume_int++;
			Draw(30, 12, WHITE, "��������������������");
		}
		else if (cChar == '-') {
			pChannel[0]->getVolume(&fVolume);
			pChannel[0]->setVolume(fVolume - 0.1f);
			if (fVolume_int != 0)fVolume_int--;
			Draw(30, 12, WHITE, "��������������������");
		}

		else if (cChar == '>') {
			BGM_on = false;
			pSystem->playSound(FMOD_CHANNEL_REUSE, pSound[Bell], false, &pChannel[1]);
			//pChannel[0]->stop();
			if (select_BGM == BGM1) select_BGM = BGM2;
			else if (select_BGM == BGM2) select_BGM = BGM3;
			else if (select_BGM == BGM3) select_BGM = BGM4;
			else if (select_BGM == BGM4) select_BGM = BGM1;

			if (BGM_on == false) {
				pSystem->playSound(FMOD_CHANNEL_REUSE, pSound[select_BGM], false, &pChannel[0]);
				pChannel[0]->setVolume(fVolume);
				BGM_on = true;
			}
		}

		else if (cChar == '<') {
			BGM_on = false;
			pSystem->playSound(FMOD_CHANNEL_REUSE, pSound[Bell], false, &pChannel[1]);
			//pChannel[0]->stop();
			if (select_BGM == BGM1) select_BGM = BGM4;
			else if (select_BGM == BGM4) select_BGM = BGM3;
			else if (select_BGM == BGM3) select_BGM = BGM2;
			else if (select_BGM == BGM2) select_BGM = BGM1;

			if (BGM_on == false) {
				pSystem->playSound(FMOD_CHANNEL_REUSE, pSound[select_BGM], false, &pChannel[0]);
				pChannel[0]->setVolume(fVolume);
				BGM_on = true;
			}


		}

		else if (cChar == KEY_ENTER) {
			pSystem->playSound(FMOD_CHANNEL_REUSE, pSound[Enter], false, &pChannel[1]); // ����ȿ����
			pChannel[0]->stop();// ����bgm����? -> �ٽ� ������
			//TURN = 1; // ������ �ٽ� �ڽ��� ���� �����ϰ� ��

			Draw(30, 12, WHITE, "��������������������");

			Draw(30, 14, WHITE, "������������������");
			//cout << "-. ��������̱�" << endl;
			Draw(30, 16, WHITE, "������������������");
			//cout << "�ٷ� �Է� >>";
			Draw(30, 18, WHITE, "��������������");

			Draw(30, 20, WHITE, "������������������");

			Draw(30, 22, WHITE, "������������������");

			Draw(30, 24, WHITE, "��������������������");

			Draw(30, 26, WHITE, "����������������");

			/*
			// ���� �ʵ带 �׷���
			DrawField(field, &user, &com1, &com2, &com3);
			user_pos(field);
			Check_Whose_Area(field, &user);
			Check_Whose_Area(field, &com1);
			Check_Whose_Area(field, &com2);
			Check_Whose_Area(field, &com3);
			*/
			
			//�Ҹ���� �� �� ��ȣ�� �ٽ� �ѱ�

			pSystem->playSound(FMOD_CHANNEL_REUSE, pSound[select_BGM], false, &pChannel[0]);
			pChannel[0]->setVolume(fVolume);
			SceneNumber = INGAME;
		}

		else if (cChar == KEY_SPACE) {
			Scene_Maintap_Init();
			SceneNumber = MAINTAP;
		}
	}

	return true;
}