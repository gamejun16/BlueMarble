#include "Scene.h"
#include "Scene_Intro.h"

int start = 0;
int Timer_3 = -15; // 0.1ÃÊ Áö³¯¶§¸¶´Ù 1¾¿Áõ°¡
extern fields field[36];
bool Intro_ = true;

float Timer_2;

//¿¹Á¦Àå¸é(Scene Example) ÃÊ±âÈ­ ÇÔ¼ö
void Scene_Intro_Init()
{
	system("mode con:cols=80 lines=28");


	//¶¥ Á¤º¸ È£Ãâ
	Set_Area(field);

	system("cls");

	// ÀÎÆ®·Î °Ç¹° ½×À» Å¸ÀÌ¸Ó
	Timer_2 = 0;
	Timer_3 = -15;
}

//¿¹Á¦Àå¸é(Scene Example) ·»´õ¸µ ÇÔ¼ö
bool Scene_Intro_Render(float timeDelta)
{
	if (Intro_) {
		Scene_Intro_Init();
		Intro_ = false; // InitÀº Ã³À½ÇÑ¹ø¸¸.
	}
	if (Timer_3 == -15) {
		pSystem->playSound(FMOD_CHANNEL_REUSE, pSound[Intro], false, &pChannel[0]);
		pChannel[0]->setVolume(fVolume);
	}

	/*
	PlaySound(TEXT("Intro.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP | SND_NODEFAULT);
	//¹è°æ.wavÆÄÀÏÀ» °è¼ÓÀç»ý½ÃÅ°°í µ¿½Ã¿¡ ÁøÇà½ÃÅµ´Ï´Ù
	//bgm±ò¶§ ¾¸
	*/

	Timer_2 += timeDelta;
	if (Timer_2 >= 0.1) {
		Timer_3++;
		Timer_2 = 0;
	}

	//Draw(36, 8, BLUE, "ºÎ·ç¸¶ºí");



	if (Timer_3 > 30&&Timer_3<56) {
		Draw(30, 26, RED, ""); textcolor(15); printf("¢· PRESS ENTER ¢¹");
	}

	Draw(0, 25, BG_GREEN, "¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬");


	/*********************   °Ç   ¹°   ½×   ±â   *********************/


	switch (Timer_3) {

		// building_1 //
	case 1:
		Draw(2, 24, BG_BLUE, "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡");
		Draw(2, 23, BG_BLUE, "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡");
		break;

	case 2:
		Draw(2, 22, BG_BLUE, "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡");
		Draw(2, 21, BG_BLUE, "¡¡"); Draw(6, 21, BG_BLUE, "¡¡"); Draw(10, 21, BG_BLUE, "¡¡"); Draw(14, 21, BG_BLUE, "¡¡"); Draw(18, 21, BG_BLUE, "¡¡");
		Draw(4, 21, BG_SKYBLUE, "¡¡"); Draw(8, 21, BG_SKYBLUE, "¡¡"); Draw(12, 21, BG_SKYBLUE, "¡¡"); Draw(16, 21, BG_SKYBLUE, "¡¡");
		break;

	case 3:
		Draw(2, 20, BG_BLUE, "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡");
		Draw(2, 19, BG_BLUE, "¡¡"); Draw(6, 19, BG_BLUE, "¡¡"); Draw(10, 19, BG_BLUE, "¡¡"); Draw(14, 19, BG_BLUE, "¡¡"); Draw(18, 19, BG_BLUE, "¡¡");
		Draw(4, 19, BG_SKYBLUE, "¡¡"); Draw(8, 19, BG_SKYBLUE, "¡¡"); Draw(12, 19, BG_SKYBLUE, "¡¡"); Draw(16, 19, BG_SKYBLUE, "¡¡");
		break;
	case 4:
		Draw(2, 18, BG_BLUE, "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡");
		Draw(2, 17, BG_BLUE, "¡¡"); Draw(6, 17, BG_BLUE, "¡¡"); Draw(10, 17, BG_BLUE, "¡¡"); Draw(14, 17, BG_BLUE, "¡¡"); Draw(18, 17, BG_BLUE, "¡¡");
		Draw(4, 17, BG_SKYBLUE, "¡¡"); Draw(8, 17, BG_SKYBLUE, "¡¡"); Draw(12, 17, BG_SKYBLUE, "¡¡"); Draw(16, 17, BG_SKYBLUE, "¡¡");
		break;
	case 5:
		Draw(2, 16, BG_BLUE, "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡");
		Draw(2, 15, BG_BLUE, "¡¡"); Draw(6, 15, BG_BLUE, "¡¡"); Draw(10, 15, BG_BLUE, "¡¡"); Draw(14, 15, BG_BLUE, "¡¡"); Draw(18, 15, BG_BLUE, "¡¡");
		Draw(4, 15, BG_SKYBLUE, "¡¡"); Draw(8, 15, BG_SKYBLUE, "¡¡"); Draw(12, 15, BG_SKYBLUE, "¡¡"); Draw(16, 15, BG_SKYBLUE, "¡¡");
		break;
	case 6:
		Draw(2, 14, BG_BLUE, "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡");
		Draw(2, 13, BG_BLUE, "¡¡"); Draw(6, 13, BG_BLUE, "¡¡"); Draw(10, 13, BG_BLUE, "¡¡"); Draw(14, 13, BG_BLUE, "¡¡"); Draw(18, 13, BG_BLUE, "¡¡");
		Draw(4, 13, BG_SKYBLUE, "¡¡"); Draw(8, 13, BG_SKYBLUE, "¡¡"); Draw(12, 13, BG_SKYBLUE, "¡¡"); Draw(16, 13, BG_SKYBLUE, "¡¡");
		break;
	case 7:
		Draw(2, 12, BG_BLUE, "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡");
		Draw(2, 11, BG_BLUE, "¡¡"); Draw(6, 11, BG_BLUE, "¡¡"); Draw(10, 11, BG_BLUE, "¡¡"); Draw(14, 11, BG_BLUE, "¡¡"); Draw(18, 11, BG_BLUE, "¡¡");
		Draw(4, 11, BG_SKYBLUE, "¡¡"); Draw(8, 11, BG_SKYBLUE, "¡¡"); Draw(12, 11, BG_SKYBLUE, "¡¡"); Draw(16, 11, BG_SKYBLUE, "¡¡");
		break;
	case 8:
		Draw(2, 10, BG_BLUE, "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡");
		Draw(2, 9, BG_BLUE, "¡¡"); Draw(6, 9, BG_BLUE, "¡¡"); Draw(10, 9, BG_BLUE, "¡¡"); Draw(14, 9, BG_BLUE, "¡¡"); Draw(18, 9, BG_BLUE, "¡¡");
		Draw(4, 9, BG_SKYBLUE, "¡¡"); Draw(8, 9, BG_SKYBLUE, "¡¡"); Draw(12, 9, BG_SKYBLUE, "¡¡"); Draw(16, 9, BG_SKYBLUE, "¡¡");
		break;
	case 9:
		// building_1//
		Draw(2, 8, BG_BLUE, "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡");
		Draw(2, 7, BG_BLUE, "¡¡"); Draw(6, 7, BG_BLUE, "¡¡"); Draw(10, 7, BG_BLUE, "¡¡"); Draw(14, 7, BG_BLUE, "¡¡"); Draw(18, 7, BG_BLUE, "¡¡");
		Draw(4, 7, BG_SKYBLUE, "¡¡"); Draw(8, 7, BG_SKYBLUE, "¡¡"); Draw(12, 7, BG_SKYBLUE, "¡¡"); Draw(16, 7, BG_SKYBLUE, "¡¡");

		// building_2//
		Draw(22, 24, BG_RED, "¡¡¡¡¡¡¡¡¡¡¡¡¡¡");
		Draw(22, 23, BG_RED, "¡¡¡¡¡¡¡¡¡¡¡¡¡¡");

		break;
	case 10:
		// building_1//
		Draw(2, 6, BG_BLUE, "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡");

		// building_2//
		Draw(22, 22, BG_RED, "¡¡¡¡¡¡¡¡¡¡¡¡¡¡");
		Draw(22, 21, BG_RED, "¡¡"); Draw(26, 21, BG_RED, "¡¡"); Draw(30, 21, BG_RED, "¡¡"); Draw(34, 21, BG_RED, "¡¡");
		Draw(24, 21, BG_SKYBLUE, "¡¡"); Draw(28, 21, BG_SKYBLUE, "¡¡"); Draw(32, 21, BG_SKYBLUE, "¡¡");
		break;
	case 11:
		Draw(22, 20, BG_RED, "¡¡¡¡¡¡¡¡¡¡¡¡¡¡");
		Draw(22, 19, BG_RED, "¡¡"); Draw(26, 19, BG_RED, "¡¡"); Draw(30, 19, BG_RED, "¡¡"); Draw(34, 19, BG_RED, "¡¡");
		Draw(24, 19, BG_SKYBLUE, "¡¡");  Draw(28, 19, BG_SKYBLUE, "¡¡"); Draw(32, 19, BG_SKYBLUE, "¡¡");
		break;
	case 12:
		Draw(22, 18, BG_RED, "¡¡¡¡¡¡¡¡¡¡¡¡¡¡");
		Draw(22, 17, BG_RED, "¡¡"); Draw(26, 17, BG_RED, "¡¡"); Draw(30, 17, BG_RED, "¡¡"); Draw(34, 17, BG_RED, "¡¡");
		Draw(24, 17, BG_SKYBLUE, "¡¡"); Draw(28, 17, BG_SKYBLUE, "¡¡"); Draw(32, 17, BG_SKYBLUE, "¡¡");
		break;
	case 13:
		// building_2 //
		Draw(22, 16, BG_RED, "¡¡¡¡¡¡¡¡¡¡¡¡¡¡");
		Draw(22, 15, BG_RED, "¡¡"); Draw(26, 15, BG_RED, "¡¡"); Draw(30, 15, BG_RED, "¡¡"); Draw(34, 15, BG_RED, "¡¡");
		Draw(24, 15, BG_SKYBLUE, "¡¡"); Draw(28, 15, BG_SKYBLUE, "¡¡"); Draw(32, 15, BG_SKYBLUE, "¡¡");

		// building_3 //
		Draw(38, 24, BG_YELLOW, "¡¡¡¡¡¡¡¡¡¡");
		Draw(38, 23, BG_YELLOW, "¡¡¡¡¡¡¡¡¡¡");
		break;
	case 14:
		// building_2 //
		Draw(22, 14, BG_RED, "¡¡¡¡¡¡¡¡¡¡¡¡¡¡");

		// building_3 //
		Draw(38, 22, BG_YELLOW, "¡¡¡¡¡¡¡¡¡¡");
		Draw(38, 21, BG_YELLOW, "¡¡"); Draw(42, 21, BG_YELLOW, "¡¡"); Draw(46, 21, BG_YELLOW, "¡¡");
		Draw(40, 21, BG_SKYBLUE, "¡¡"); Draw(44, 21, BG_SKYBLUE, "¡¡");
		break;


	case 15:
		Draw(38, 20, BG_YELLOW, "¡¡¡¡¡¡¡¡¡¡");
		Draw(38, 19, BG_YELLOW, "¡¡"); Draw(42, 19, BG_YELLOW, "¡¡"); Draw(46, 19, BG_YELLOW, "¡¡");
		Draw(40, 19, BG_SKYBLUE, "¡¡"); Draw(44, 19, BG_SKYBLUE, "¡¡");
		break;

	case 16:
		Draw(38, 18, BG_YELLOW, "¡¡¡¡¡¡¡¡¡¡");
		Draw(38, 17, BG_YELLOW, "¡¡"); Draw(42, 17, BG_YELLOW, "¡¡"); Draw(46, 17, BG_YELLOW, "¡¡");
		Draw(40, 17, BG_SKYBLUE, "¡¡"); Draw(44, 17, BG_SKYBLUE, "¡¡");
		break;
	case 17:
		Draw(38, 16, BG_YELLOW, "¡¡¡¡¡¡¡¡¡¡");
		Draw(38, 15, BG_YELLOW, "¡¡"); Draw(42, 15, BG_YELLOW, "¡¡"); Draw(46, 15, BG_YELLOW, "¡¡");
		Draw(40, 15, BG_SKYBLUE, "¡¡"); Draw(44, 15, BG_SKYBLUE, "¡¡");
		break;
	case 18:
		Draw(38, 14, BG_YELLOW, "¡¡¡¡¡¡¡¡¡¡");
		Draw(38, 13, BG_YELLOW, "¡¡"); Draw(42, 13, BG_YELLOW, "¡¡"); Draw(46, 13, BG_YELLOW, "¡¡");
		Draw(40, 13, BG_SKYBLUE, "¡¡"); Draw(44, 13, BG_SKYBLUE, "¡¡");
		break;
	case 19:
		Draw(38, 12, BG_YELLOW, "¡¡¡¡¡¡¡¡¡¡");
		Draw(38, 11, BG_YELLOW, "¡¡"); Draw(42, 11, BG_YELLOW, "¡¡"); Draw(46, 11, BG_YELLOW, "¡¡");
		Draw(40, 11, BG_SKYBLUE, "¡¡"); Draw(44, 11, BG_SKYBLUE, "¡¡");
		break;
	case 20:
		Draw(38, 10, BG_YELLOW, "¡¡¡¡¡¡¡¡¡¡");
		Draw(38, 9, BG_YELLOW, "¡¡"); Draw(42, 9, BG_YELLOW, "¡¡"); Draw(46, 9, BG_YELLOW, "¡¡");
		Draw(40, 9, BG_SKYBLUE, "¡¡"); Draw(44, 9, BG_SKYBLUE, "¡¡");
		break;
	case 21:
		Draw(38, 8, BG_YELLOW, "¡¡¡¡¡¡¡¡¡¡");
		Draw(38, 7, BG_YELLOW, "¡¡"); Draw(42, 7, BG_YELLOW, "¡¡"); Draw(46, 7, BG_YELLOW, "¡¡");
		Draw(40, 7, BG_SKYBLUE, "¡¡"); Draw(44, 7, BG_SKYBLUE, "¡¡");
		break;
	case 22:
		Draw(38, 6, BG_YELLOW, "¡¡¡¡¡¡¡¡¡¡");
		Draw(38, 5, BG_YELLOW, "¡¡"); Draw(42, 5, BG_YELLOW, "¡¡"); Draw(46, 5, BG_YELLOW, "¡¡");
		Draw(40, 5, BG_SKYBLUE, "¡¡"); Draw(44, 5, BG_SKYBLUE, "¡¡");
		break;
	case 23:
		Draw(38, 4, BG_YELLOW, "¡¡¡¡¡¡¡¡¡¡");
		Draw(38, 3, BG_YELLOW, "¡¡"); Draw(42, 3, BG_YELLOW, "¡¡"); Draw(46, 3, BG_YELLOW, "¡¡");
		Draw(40, 3, BG_SKYBLUE, "¡¡"); Draw(44, 3, BG_SKYBLUE, "¡¡");
		break;
	case 24:
		// building_3 //
		Draw(38, 2, BG_YELLOW, "¡¡¡¡¡¡¡¡¡¡");
		Draw(38, 1, BG_YELLOW, "¡¡"); Draw(42, 1, BG_YELLOW, "¡¡"); Draw(46, 1, BG_YELLOW, "¡¡");
		Draw(40, 1, BG_SKYBLUE, "¡¡"); Draw(44, 1, BG_SKYBLUE, "¡¡");

		// building_4 //
		Draw(50, 24, BG_PURPLE, "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡");
		Draw(50, 23, BG_PURPLE, "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡");
		break;
	case 25:
		// building_3 //
		Draw(38, 0, BG_YELLOW, "¡¡¡¡¡¡¡¡¡¡");
		// building_4 //
		Draw(50, 22, BG_PURPLE, "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡");
		Draw(50, 21, BG_PURPLE, "¡¡"); Draw(54, 21, BG_PURPLE, "¡¡"); Draw(58, 21, BG_PURPLE, "¡¡"); Draw(62, 21, BG_PURPLE, "¡¡"); Draw(66, 21, BG_PURPLE, "¡¡");
		Draw(52, 21, BG_SKYBLUE, "¡¡"); Draw(56, 21, BG_SKYBLUE, "¡¡"); Draw(60, 21, BG_SKYBLUE, "¡¡"); Draw(64, 21, BG_SKYBLUE, "¡¡");
		break;
	case 26:
		// building_4//
		Draw(50, 20, BG_PURPLE, "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡");
		Draw(50, 19, BG_PURPLE, "¡¡"); Draw(54, 19, BG_PURPLE, "¡¡"); Draw(58, 19, BG_PURPLE, "¡¡"); Draw(62, 19, BG_PURPLE, "¡¡"); Draw(66, 19, BG_PURPLE, "¡¡");
		Draw(52, 19, BG_SKYBLUE, "¡¡"); Draw(56, 19, BG_SKYBLUE, "¡¡"); Draw(60, 19, BG_SKYBLUE, "¡¡"); Draw(64, 19, BG_SKYBLUE, "¡¡");
		break;
	case 27:
		Draw(50, 18, BG_PURPLE, "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡");
		Draw(50, 17, BG_PURPLE, "¡¡"); Draw(54, 17, BG_PURPLE, "¡¡"); Draw(58, 17, BG_PURPLE, "¡¡"); Draw(62, 17, BG_PURPLE, "¡¡"); Draw(66, 17, BG_PURPLE, "¡¡");
		Draw(52, 17, BG_SKYBLUE, "¡¡"); Draw(56, 17, BG_SKYBLUE, "¡¡"); Draw(60, 17, BG_SKYBLUE, "¡¡"); Draw(64, 17, BG_SKYBLUE, "¡¡");
		break;
	case 28:
		Draw(50, 16, BG_PURPLE, "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡");
		Draw(50, 15, BG_PURPLE, "¡¡"); Draw(54, 15, BG_PURPLE, "¡¡"); Draw(58, 15, BG_PURPLE, "¡¡"); Draw(62, 15, BG_PURPLE, "¡¡"); Draw(66, 15, BG_PURPLE, "¡¡");
		Draw(52, 15, BG_SKYBLUE, "¡¡"); Draw(56, 15, BG_SKYBLUE, "¡¡"); Draw(60, 15, BG_SKYBLUE, "¡¡"); Draw(64, 15, BG_SKYBLUE, "¡¡");
		break;
	case 29:
		Draw(50, 14, BG_PURPLE, "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡");
		Draw(50, 13, BG_PURPLE, "¡¡"); Draw(54, 13, BG_PURPLE, "¡¡"); Draw(58, 13, BG_PURPLE, "¡¡"); Draw(62, 13, BG_PURPLE, "¡¡"); Draw(66, 13, BG_PURPLE, "¡¡");
		Draw(52, 13, BG_SKYBLUE, "¡¡"); Draw(56, 13, BG_SKYBLUE, "¡¡"); Draw(60, 13, BG_SKYBLUE, "¡¡"); Draw(64, 13, BG_SKYBLUE, "¡¡");
		break;
	case 30:
		Draw(50, 12, BG_PURPLE, "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡");
		break;
		/***********   °Ç¹°ÀÌµ¿   ***********/
	case 31:
		system("cls");
		for (int i = 6; i <= 24; i++) {
			Draw(0, i, BG_BLUE, "¡¡¡¡¡¡¡¡");
			if (i % 2 == 1 && i < 22) {
				Draw(0, i, BG_SKYBLUE, "¡¡"); Draw(4, i, BG_SKYBLUE, "¡¡");
			}
		}
		for (int i = 14; i <= 24; i++) {
			Draw(10, i, BG_RED, "¡¡¡¡¡¡¡¡¡¡¡¡¡¡");
			if (i % 2 == 1 && i < 22) {
				Draw(12, i, BG_SKYBLUE, "¡¡"); Draw(16, i, BG_SKYBLUE, "¡¡"); Draw(20, i, BG_SKYBLUE, "¡¡");
			}
		}
		for (int i = 0; i <= 24; i++) {
			Draw(26, i, BG_YELLOW, "¡¡¡¡¡¡¡¡¡¡");
			if (i % 2 == 1 && i < 22) {
				Draw(28, i, BG_SKYBLUE, "¡¡"); Draw(32, i, BG_SKYBLUE, "¡¡");
			}
		}
		for (int i = 12; i <= 24; i++) {
			Draw(38, i, BG_PURPLE, "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡");
			if (i % 2 == 1 && i < 22) {
				Draw(40, i, BG_SKYBLUE, "¡¡"); Draw(44, i, BG_SKYBLUE, "¡¡"); Draw(48, i, BG_SKYBLUE, "¡¡"); Draw(52, i, BG_SKYBLUE, "¡¡");
			}
		}
		break;
		
	case 32:
		system("cls");

		for (int i = 14; i <= 24; i++) {
			Draw(0, i, BG_RED, "¡¡¡¡¡¡¡¡¡¡¡¡");
			if (i % 2 == 1 && i < 22) {
				Draw(0, i, BG_SKYBLUE, "¡¡"); Draw(4, i, BG_SKYBLUE, "¡¡"); Draw(8, i, BG_SKYBLUE, "¡¡");
			}
		}
		for (int i = 0; i <= 24; i++) {
			Draw(14, i, BG_YELLOW, "¡¡¡¡¡¡¡¡¡¡");
			if (i % 2 == 1 && i < 22) {
				Draw(16, i, BG_SKYBLUE, "¡¡"); Draw(20, i, BG_SKYBLUE, "¡¡");
			}
		}
		for (int i = 12; i <= 24; i++) {
			Draw(26, i, BG_PURPLE, "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡");
			if (i % 2 == 1 && i < 22) {
				Draw(28, i, BG_SKYBLUE, "¡¡"); Draw(32, i, BG_SKYBLUE, "¡¡"); Draw(36, i, BG_SKYBLUE, "¡¡"); Draw(40, i, BG_SKYBLUE, "¡¡");
			}
		}
		break;
		
	case 33:
		system("cls");
		for (int i = 0; i <= 24; i++) {
			Draw(2, i, BG_YELLOW, "¡¡¡¡¡¡¡¡¡¡");
			if (i % 2 == 1 && i < 22) {
				Draw(4, i, BG_SKYBLUE, "¡¡"); Draw(8, i, BG_SKYBLUE, "¡¡");
			}
		}
		for (int i = 12; i <= 24; i++)
			Draw(14, i, BG_PURPLE, "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡");
		break;
	case 34:
		system("cls");
		for (int i = 12; i <= 24; i++) {
			Draw(2, i, BG_PURPLE, "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡");
			if (i % 2 == 1 && i < 22) {
				Draw(4, i, BG_SKYBLUE, "¡¡"); Draw(8, i, BG_SKYBLUE, "¡¡"); Draw(12, i, BG_SKYBLUE, "¡¡"); Draw(16, i, BG_SKYBLUE, "¡¡");
			}
		}
		break;
		///// °Ç¹° ½×±â /////
	case 35:
		Draw(22, 24, RED, ""); textcolor(112); printf("¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡");
		Draw(22, 23, RED, ""); textcolor(112); printf("¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡");
		break;
	case 36:
		Draw(22, 22, RED, "");  textcolor(112); printf("¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡");
		Draw(22, 21, RED, "");  textcolor(112); printf("¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡");
		Draw(24, 21, BG_SKYBLUE, "¡¡"); Draw(28, 21, BG_SKYBLUE, "¡¡"); Draw(32, 21, BG_SKYBLUE, "¡¡"); Draw(36, 21, BG_SKYBLUE, "¡¡"); Draw(40, 21, BG_SKYBLUE, "¡¡"); Draw(44, 21, BG_SKYBLUE, "¡¡");
		break;
	case 37:
		Draw(22, 20, RED, ""); textcolor(112); printf("¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡");
		Draw(22, 19, RED, ""); textcolor(112); printf("¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡");
		Draw(24, 19, BG_SKYBLUE, "¡¡"); Draw(28, 19, BG_SKYBLUE, "¡¡"); Draw(32, 19, BG_SKYBLUE, "¡¡"); Draw(36, 19, BG_SKYBLUE, "¡¡"); Draw(40, 19, BG_SKYBLUE, "¡¡"); Draw(44, 19, BG_SKYBLUE, "¡¡");
		break;
	case 38:
		Draw(22, 18, RED, ""); textcolor(112); printf("¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡");
		Draw(22, 17, RED, ""); textcolor(112); printf("¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡");
		Draw(24, 17, BG_SKYBLUE, "¡¡"); Draw(28, 17, BG_SKYBLUE, "¡¡"); Draw(32, 17, BG_SKYBLUE, "¡¡"); Draw(36, 17, BG_SKYBLUE, "¡¡"); Draw(40, 17, BG_SKYBLUE, "¡¡"); Draw(44, 17, BG_SKYBLUE, "¡¡");

		Draw(48, 24, RED, ""); textcolor(128); printf("¡¡¡¡¡¡¡¡¡¡");
		Draw(48, 23, RED, ""); textcolor(128); printf("¡¡¡¡¡¡¡¡¡¡");
		break;
	case 39:
		Draw(22, 16, RED, ""); textcolor(112); printf("¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡");

		Draw(48, 22, RED, ""); textcolor(128); printf("¡¡¡¡¡¡¡¡¡¡");
		Draw(50, 22, BG_SKYBLUE, "¡¡"); Draw(54, 22, BG_SKYBLUE, "¡¡");
		Draw(48, 21, RED, ""); textcolor(128); printf("¡¡¡¡¡¡¡¡¡¡");
		break;
	case 40:
		Draw(48, 20, RED, ""); textcolor(128); printf("¡¡¡¡¡¡¡¡¡¡");
		Draw(50, 20, BG_SKYBLUE, "¡¡"); Draw(54, 20, BG_SKYBLUE, "¡¡");
		Draw(48, 19, RED, ""); textcolor(128); printf("¡¡¡¡¡¡¡¡¡¡");
		break;
	case 41:
		Draw(48, 18, RED, ""); textcolor(128); printf("¡¡¡¡¡¡¡¡¡¡");
		Draw(50, 18, BG_SKYBLUE, "¡¡"); Draw(54, 18, BG_SKYBLUE, "¡¡");
		Draw(48, 17, RED, ""); textcolor(128); printf("¡¡¡¡¡¡¡¡¡¡");
		break;
	case 42:
		Draw(48, 16, RED, ""); textcolor(128); printf("¡¡¡¡¡¡¡¡¡¡");
		Draw(50, 16, BG_SKYBLUE, "¡¡"); Draw(54, 16, BG_SKYBLUE, "¡¡");
		Draw(40, 15, RED, ""); textcolor(128); printf("¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡");
		break;
	case 43:
		Draw(40, 14, RED, ""); textcolor(128); printf("¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡");
		Draw(42, 14, BG_SKYBLUE, "¡¡"); Draw(46, 14, BG_SKYBLUE, "¡¡"); Draw(50, 14, BG_SKYBLUE, "¡¡"); Draw(54, 14, BG_SKYBLUE, "¡¡");
		Draw(40, 13, RED, ""); textcolor(128); printf("¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡");
		break;
	case 44:
		Draw(40, 12, RED, ""); textcolor(128); printf("¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡");
		Draw(42, 12, BG_SKYBLUE, "¡¡"); Draw(46, 12, BG_SKYBLUE, "¡¡"); Draw(50, 12, BG_SKYBLUE, "¡¡"); Draw(54, 12, BG_SKYBLUE, "¡¡");
		Draw(40, 11, RED, ""); textcolor(128); printf("¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡");
		break;
	case 45:
		Draw(40, 10, RED, ""); textcolor(128); printf("¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡");
		Draw(42, 10, BG_SKYBLUE, "¡¡"); Draw(46, 10, BG_SKYBLUE, "¡¡"); Draw(50, 10, BG_SKYBLUE, "¡¡"); Draw(54, 10, BG_SKYBLUE, "¡¡");
		Draw(40, 9, RED, ""); textcolor(128); printf("¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡");
		break;
	case 46:
		Draw(40, 8, RED, ""); textcolor(128); printf("¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡");
		Draw(42, 8, BG_SKYBLUE, "¡¡"); Draw(46, 8, BG_SKYBLUE, "¡¡"); Draw(50, 8, BG_SKYBLUE, "¡¡"); Draw(54, 8, BG_SKYBLUE, "¡¡");
		Draw(40, 7, RED, ""); textcolor(128); printf("¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡");

		Draw(60, 24, BG_BLUE, "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡");
		Draw(60, 23, BG_BLUE, "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡");
		break;
	case 47:
		Draw(40, 6, RED, ""); textcolor(128); printf("¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡");
		Draw(42, 6, BG_SKYBLUE, "¡¡"); Draw(46, 6, BG_SKYBLUE, "¡¡"); Draw(50, 6, BG_SKYBLUE, "¡¡"); Draw(54, 6, BG_SKYBLUE, "¡¡");
		Draw(40, 5, RED, ""); textcolor(128); printf("¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡");

		Draw(60, 22, BG_BLUE, "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡");
		Draw(60, 21, BG_BLUE, "¡¡"); Draw(64, 21, BG_BLUE, "¡¡"); Draw(68, 21, BG_BLUE, "¡¡"); Draw(72, 21, BG_BLUE, "¡¡"); Draw(76, 21, BG_BLUE, "¡¡");
		Draw(62, 21, BG_SKYBLUE, "¡¡"); Draw(66, 21, BG_SKYBLUE, "¡¡"); Draw(70, 21, BG_SKYBLUE, "¡¡"); Draw(74, 21, BG_SKYBLUE, "¡¡");
		break;
	case 48:
		Draw(60, 20, BG_BLUE, "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡");
		Draw(60, 19, BG_BLUE, "¡¡"); Draw(64, 19, BG_BLUE, "¡¡"); Draw(68, 19, BG_BLUE, "¡¡"); Draw(72, 19, BG_BLUE, "¡¡"); Draw(76, 19, BG_BLUE, "¡¡");
		Draw(62, 19, BG_SKYBLUE, "¡¡"); Draw(66, 19, BG_SKYBLUE, "¡¡"); Draw(70, 19, BG_SKYBLUE, "¡¡"); Draw(74, 19, BG_SKYBLUE, "¡¡");
		break;
	case 49:
		Draw(60, 18, BG_BLUE, "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡");
		Draw(60, 17, BG_BLUE, "¡¡"); Draw(64, 17, BG_BLUE, "¡¡"); Draw(68, 17, BG_BLUE, "¡¡"); Draw(72, 17, BG_BLUE, "¡¡"); Draw(76, 17, BG_BLUE, "¡¡");
		Draw(62, 17, BG_SKYBLUE, "¡¡"); Draw(66, 17, BG_SKYBLUE, "¡¡"); Draw(70, 17, BG_SKYBLUE, "¡¡"); Draw(74, 17, BG_SKYBLUE, "¡¡");
		break;
	case 50:
		Draw(60, 16, BG_BLUE, "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡");
		Draw(60, 15, BG_BLUE, "¡¡"); Draw(64, 15, BG_BLUE, "¡¡"); Draw(68, 15, BG_BLUE, "¡¡"); Draw(72, 15, BG_BLUE, "¡¡"); Draw(76, 15, BG_BLUE, "¡¡");
		Draw(62, 15, BG_SKYBLUE, "¡¡"); Draw(66, 15, BG_SKYBLUE, "¡¡"); Draw(70, 15, BG_SKYBLUE, "¡¡"); Draw(74, 15, BG_SKYBLUE, "¡¡");
		break;
	case 51:
		Draw(60, 14, BG_BLUE, "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡");
		Draw(60, 13, BG_BLUE, "¡¡"); Draw(64, 13, BG_BLUE, "¡¡"); Draw(68, 13, BG_BLUE, "¡¡"); Draw(72, 13, BG_BLUE, "¡¡"); Draw(76, 13, BG_BLUE, "¡¡");
		Draw(62, 13, BG_SKYBLUE, "¡¡"); Draw(66, 13, BG_SKYBLUE, "¡¡"); Draw(70, 13, BG_SKYBLUE, "¡¡"); Draw(74, 13, BG_SKYBLUE, "¡¡");
		break;
	case 52:
		Draw(60, 12, BG_BLUE, "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡");
		Draw(60, 11, BG_BLUE, "¡¡"); Draw(64, 11, BG_BLUE, "¡¡"); Draw(68, 11, BG_BLUE, "¡¡"); Draw(72, 11, BG_BLUE, "¡¡"); Draw(76, 11, BG_BLUE, "¡¡");
		Draw(62, 11, BG_SKYBLUE, "¡¡"); Draw(66, 11, BG_SKYBLUE, "¡¡"); Draw(70, 11, BG_SKYBLUE, "¡¡"); Draw(74, 11, BG_SKYBLUE, "¡¡");
		break;
	case 53:
		Draw(60, 10, BG_BLUE, "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡");
		Draw(60, 9, BG_BLUE, "¡¡"); Draw(64, 9, BG_BLUE, "¡¡"); Draw(68, 9, BG_BLUE, "¡¡"); Draw(72, 9, BG_BLUE, "¡¡"); Draw(76, 9, BG_BLUE, "¡¡");
		Draw(62, 9, BG_SKYBLUE, "¡¡"); Draw(66, 9, BG_SKYBLUE, "¡¡"); Draw(70, 9, BG_SKYBLUE, "¡¡"); Draw(74, 9, BG_SKYBLUE, "¡¡");
		break;
	case 54:
		Draw(60, 8, BG_BLUE, "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡");
		Draw(60, 7, BG_BLUE, "¡¡"); Draw(64, 7, BG_BLUE, "¡¡"); Draw(68, 7, BG_BLUE, "¡¡"); Draw(72, 7, BG_BLUE, "¡¡"); Draw(76, 7, BG_BLUE, "¡¡");
		Draw(62, 7, BG_SKYBLUE, "¡¡"); Draw(66, 7, BG_SKYBLUE, "¡¡"); Draw(70, 7, BG_SKYBLUE, "¡¡"); Draw(74, 7, BG_SKYBLUE, "¡¡");
		break;
	case 55:
		Draw(60, 6, BG_BLUE, "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡");
		break;
		/***********   °Ç¹°ÀÌµ¿   ***********/
	case 56:
		system("cls");
		for (int i = 12; i <= 24; i++) {
			Draw(0, i, BG_PURPLE, "¡¡¡¡");
			if (i % 2 == 1 && i < 22) {
				Draw(0, i, BG_SKYBLUE, "¡¡");
			}
		}
		for (int i = 16; i <= 24; i++) {
			Draw(8, i, RED, ""); textcolor(112); printf("¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡");
			Draw(34, i, RED, ""); textcolor(128); printf("¡¡¡¡¡¡¡¡¡¡");
			if (i % 2 == 1 && i < 22) {
				Draw(10, i, BG_SKYBLUE, "¡¡"); Draw(14, i, BG_SKYBLUE, "¡¡"); Draw(18, i, BG_SKYBLUE, "¡¡"); Draw(22, i, BG_SKYBLUE, "¡¡"); Draw(26, i, BG_SKYBLUE, "¡¡"); Draw(30, i, BG_SKYBLUE, "¡¡");
			}
			if (i % 2 == 0 && i < 22) {
				Draw(36, i, BG_SKYBLUE, "¡¡"); Draw(40, i, BG_SKYBLUE, "¡¡");
			}
		}
		for (int i = 5; i <= 15; i++) {
			Draw(26, i, RED, ""); textcolor(128); printf("¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡");
			if (i % 2 == 0) {
				Draw(28, i, BG_SKYBLUE, "¡¡"); Draw(32, i, BG_SKYBLUE, "¡¡"); Draw(36, i, BG_SKYBLUE, "¡¡"); Draw(40, i, BG_SKYBLUE, "¡¡");
			}
		}
		for (int i = 6; i <= 24; i++) {
			Draw(46, i, BG_BLUE, "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡");
			if (i % 2 == 1 && i < 22) {
				Draw(48, i, BG_SKYBLUE, "¡¡"); Draw(52, i, BG_SKYBLUE, "¡¡"); Draw(56, i, BG_SKYBLUE, "¡¡"); Draw(60, i, BG_SKYBLUE, "¡¡");
			}
		}
		break;
	case 57:
		system("cls");
		for (int i = 16; i <= 24; i++) {
			Draw(0, i, RED, ""); textcolor(112); printf("¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡");
			Draw(18, i, RED, ""); textcolor(128); printf("¡¡¡¡¡¡¡¡¡¡");
			if (i % 2 == 1 && i < 22) {
				Draw(2, i, BG_SKYBLUE, "¡¡"); Draw(6, i, BG_SKYBLUE, "¡¡"); Draw(10, i, BG_SKYBLUE, "¡¡"); Draw(14, i, BG_SKYBLUE, "¡¡");
			}
			if (i % 2 == 0 && i < 22) {
				Draw(20, i, BG_SKYBLUE, "¡¡"); Draw(24, i, BG_SKYBLUE, "¡¡");
			}
		}
		for (int i = 5; i <= 15; i++) {
			Draw(10, i, RED, ""); textcolor(128); printf("¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡");
			if (i % 2 == 0) {
				Draw(12, i, BG_SKYBLUE, "¡¡"); Draw(16, i, BG_SKYBLUE, "¡¡"); Draw(20, i, BG_SKYBLUE, "¡¡"); Draw(24, i, BG_SKYBLUE, "¡¡");
			}
		}
		for (int i = 6; i <= 24; i++) {
			Draw(30, i, BG_BLUE, "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡");
			if (i % 2 == 1 && i < 22) {
				Draw(32, i, BG_SKYBLUE, "¡¡"); Draw(36, i, BG_SKYBLUE, "¡¡"); Draw(40, i, BG_SKYBLUE, "¡¡"); Draw(44, i, BG_SKYBLUE, "¡¡");
			}
		}
		break;
	case 58:
		system("cls");
		for (int i = 16; i <= 24; i++) {
			Draw(0, i, RED, ""); textcolor(112); printf("¡¡¡¡");
			Draw(4, i, RED, ""); textcolor(128); printf("¡¡¡¡¡¡¡¡¡¡");
			if (i % 2 == 1 && i < 22) {
				Draw(0, i, BG_SKYBLUE, "¡¡");
			}
			if (i % 2 == 0 && i < 22) {
				Draw(6, i, BG_SKYBLUE, "¡¡"); Draw(10, i, BG_SKYBLUE, "¡¡");
			}
		}
		for (int i = 5; i <= 15; i++) {
			Draw(0, i, RED, ""); textcolor(128); printf("¡¡¡¡¡¡¡¡¡¡¡¡¡¡");
			if (i % 2 == 0) {
				Draw(2, i, BG_SKYBLUE, "¡¡"); Draw(6, i, BG_SKYBLUE, "¡¡"); Draw(10, i, BG_SKYBLUE, "¡¡");
			}
		}
		for (int i = 6; i <= 24; i++) {
			Draw(16, i, BG_BLUE, "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡");
			if (i % 2 == 1 && i < 22) {
				Draw(18, i, BG_SKYBLUE, "¡¡"); Draw(22, i, BG_SKYBLUE, "¡¡"); Draw(26, i, BG_SKYBLUE, "¡¡"); Draw(30, i, BG_SKYBLUE, "¡¡");
			}
		}
		break;
	case 59:
		system("cls");
		for (int i = 6; i <= 24; i++) {
			Draw(2, i, BG_BLUE, "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡");
			if (i % 2 == 1 && i < 22) {
				Draw(4, i, BG_SKYBLUE, "¡¡"); Draw(8, i, BG_SKYBLUE, "¡¡"); Draw(12, i, BG_SKYBLUE, "¡¡"); Draw(16, i, BG_SKYBLUE, "¡¡");
			}
		}
		Timer_3 = 8;
		break;
	}

	if (start == 0) {
		system("cls");
	}
	start++;

	if (KeyDown(KEY_ENTER)) {
		pSystem->playSound(FMOD_CHANNEL_REUSE, pSound[Enter], false, &pChannel[1]); // ¿£ÅÍÈ¿°úÀ½
		pChannel[0]->stop();
		Scene_Maintap_Init();
		SceneNumber = MAINTAP;
	}

	return true;
}
