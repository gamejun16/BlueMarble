#include <conio.h>
#include <iostream>
using namespace std;

#include "Scene.h"
#include "Scene_Option.h"

#include "fmod.hpp"
#pragma	comment (lib, "fmodex_vc.lib")
using namespace FMOD;

// bgm 볼륨
float fVolume = 0.5;
int fVolume_int = 5;

// 효과음 볼륨


// 안전장치
bool BGM_on = false;

void Scene_Option_Init()
{
	system("cls");

}


bool Scene_Option_Render(float timeDelta)
{

	


	//pChannel[0]->isPlaying(&IsBGPlaying);
	//pChannel[1]->isPlaying(&IsEffectPlaying);


	//cout << "배경음볼륨 : " << fVolume << endl;
	//Draw(20, 6, WHITE, "배경음볼륨 : %f", fVolume);



	//cout << "1. 배경음악재생" << endl;
	//Draw(40, 14, WHITE, "1.    배경음악재생");
	//cout << "2. 배경음악정지" << endl;
	//Draw(40, 14, WHITE, "2.    배경음악정지");
	//cout << "3. 효과음 재 생" << endl;
	//Draw(20, 9, WHITE, "3. 효과음 재생");
	//cout << "4. 프로그램종료" << endl;
	//Draw(20, 10, WHITE, "4. 프로그램종료");
	//cout << "+. 배경음키우기" << endl;
	//Draw(38, 12, WHITE, "      ");
	//Draw(40, 12, WHITE, "%d", fVolume_int);

	
	switch (fVolume_int) {
	case 10:
		Draw(58, 12, BG_RED, " ");
	case 9:
		Draw(56, 12, BG_RED, " ");
	case 8:
		Draw(54, 12, BG_RED, " ");
	case 7:
		Draw(52, 12, BG_YELLOW, " ");
	case 6:
		Draw(50, 12, BG_YELLOW, " ");
	case 5:
		Draw(48, 12, BG_YELLOW, " ");
	case 4:
		Draw(46, 12, BG_GREEN, " ");
	case 3:
		Draw(44, 12, BG_GREEN, " ");
	case 2:
		Draw(42, 12, BG_GREEN, " ");
	case 1:
		Draw(40, 12, BG_GREEN, " ");
	}

	/*
	switch (eVolume_int) {
	case 10:
		Draw(58, 18, BG_RED, " ");
	case 9:
		Draw(56, 18, BG_RED, " ");
	case 8:
		Draw(54, 18, BG_RED, " ");
	case 7:
		Draw(52, 18, BG_YELLOW, " ");
	case 6:
		Draw(50, 18, BG_YELLOW, " ");
	case 5:
		Draw(48, 18, BG_YELLOW, " ");
	case 4:
		Draw(46, 18, BG_GREEN, " ");
	case 3:
		Draw(44, 18, BG_GREEN, " ");
	case 2:
		Draw(42, 18, BG_GREEN, " ");
	case 1:
		Draw(40, 18, BG_GREEN, " ");
	}
	*/

	Draw(40, 14, WHITE, "+.    배경음키우기");
	//cout << "-. 배경음줄이기" << endl;
	Draw(40, 16, WHITE, "-.    배경음줄이기");
	//cout << "바로 입력 >>";
	Draw(40, 18, WHITE, "select_BGM: %d", select_BGM);
	
	Draw(40, 20, WHITE, ">.    BGM 바꾸기");

	Draw(40, 22, WHITE, "<.    BGM 바꾸기");
	
	Draw(40, 24, WHITE, "ENTER.저장 후 나가기");

	if (_kbhit())
	{
		char cChar = _getch();

		if (cChar == '+') {
			pChannel[0]->getVolume(&fVolume);
			pChannel[0]->setVolume(fVolume + 0.1f);
			if (fVolume_int != 10)fVolume_int++;
			Draw(40, 12, WHITE, "　　　　　　　　　　");
		}
		else if (cChar == '-') {
			pChannel[0]->getVolume(&fVolume);
			pChannel[0]->setVolume(fVolume - 0.1f);
			if (fVolume_int != 0)fVolume_int--;
			Draw(40, 12, WHITE, "　　　　　　　　　　");
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
			pSystem->playSound(FMOD_CHANNEL_REUSE, pSound[Enter], false, &pChannel[1]); // 엔터효과음
			pChannel[0]->stop();
			Scene_Maintap_Init();
			SceneNumber = MAINTAP;
		}

			/*
		case '1':
			pSystem->playSound(FMOD_CHANNEL_REUSE, pSound[1], false, &pChannel[1]);
			pChannel[1]->setVolume(fVolume);
			break;

		case '2':
			pChannel[1]->stop();
			break;
			


		case '+':
			pChannel[0]->getVolume(&fVolume);
			pChannel[0]->setVolume(fVolume + 0.1f);
			if (fVolume_int != 10)fVolume_int++;
			Draw(40, 12, WHITE, "　　　　　　　　　　");
			break;

		case '-':
			pChannel[0]->getVolume(&fVolume);
			pChannel[0]->setVolume(fVolume - 0.1f);
			if (fVolume_int != 0)fVolume_int--;
			Draw(40, 12, WHITE, "　　　　　　　　　　");
			break;

		case 3:
			pChannel[1]->getVolume(&eVolume);
			pChannel[1]->setVolume(eVolume - 0.1f);
			if (eVolume_int != 0)eVolume_int--;
			Draw(40, 18, WHITE, "　　　　　　　　　　");
			pSystem->playSound(FMOD_CHANNEL_REUSE, pSound[2], false, &pChannel[1]);

			break;

		case 4:
			pChannel[1]->getVolume(&eVolume);
			pChannel[1]->setVolume(eVolume - 0.1f);
			if (eVolume_int != 0)eVolume_int--;
			Draw(40, 18, WHITE, "　　　　　　　　　　");
			pSystem->playSound(FMOD_CHANNEL_REUSE, pSound[2], false, &pChannel[1]);

			break;

		case KEY_ENTER:
			pSystem->playSound(FMOD_CHANNEL_REUSE, pSound[4], false, &pChannel[1]); // 엔터효과음
			pChannel[0]->stop();
			Scene_Maintap_Init();
			SceneNumber = MAINTAP;
			break;
			*/

		
		
	}

	//_sleep(50);
	//system("cls");

	//	음악파일 해제
	//pSound[0]->release();
	//pSound[1]->release();

	//	시스템 해제
	//pSystem->release();
	//	시스템 닫기
	//pSystem->close();

	return true;
}