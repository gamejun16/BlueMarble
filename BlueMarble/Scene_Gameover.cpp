#include "Scene_Gameover.h"
#include "Scene.h"

float Timer_ov = 0.0f;
int Timer_sub = 0;
void Scene_Gameover_Init()
{
	Timer_ov = 0;
	Timer_sub = 0;
	system("mode con:cols=102 lines=34");
	pSystem->playSound(FMOD_CHANNEL_REUSE, pSound[Ending], false, &pChannel[0]); // 壕井製
	system("cls");


	Draw(0, 14, BG_BLUE, "");
	Draw(0, 15, BG_BLUE, "　");
	Draw(0, 16, BG_BLUE, "　");
	Draw(0, 17, BG_BLUE, "　　　");
	Draw(0, 17, BG_SKYBLUE, "　");

	for (int i = 18; i <= 32; i++) {
		Draw(0, i, BG_BLUE, "　　　　");
		if (i % 2 == 1 && i < 30) {
			Draw(0, i, BG_SKYBLUE, "　"); Draw(4, i, BG_SKYBLUE, "　");
		}
	}


	Draw(10, 22, BG_RED, "　　");
	Draw(10, 23, BG_RED, "　　　");
	Draw(12, 23, BG_SKYBLUE, "　");
	Draw(10, 24, BG_RED, "　　");
	Draw(10, 25, BG_RED, "　　　");
	Draw(12, 25, BG_SKYBLUE, "　");
	Draw(10, 26, BG_RED, "　　");
	Draw(10, 27, BG_RED, "　　　"); Draw(20, 27, BG_RED, "　　");
	Draw(12, 27, BG_SKYBLUE, "　");
	Draw(10, 28, BG_RED, "　　　　　　　");
	Draw(10, 29, BG_RED, "　　　　　　　");
	Draw(12, 29, BG_SKYBLUE, "　"); Draw(16, 29, BG_SKYBLUE, "　"); Draw(20, 29, BG_SKYBLUE, "　");
	Draw(10, 30, BG_RED, "　　　　　　　");
	Draw(10, 31, BG_RED, "　　　　　　　");
	Draw(10, 32, BG_RED, "　　　　　　　");


	Draw(32, 20, BG_YELLOW, "　　");
	Draw(32, 21, BG_YELLOW, "　　");
	Draw(28, 22, BG_YELLOW, "　　　　");
	Draw(28, 22, BG_SKYBLUE, "　"); Draw(32, 22, BG_SKYBLUE, "　");
	Draw(26, 23, BG_YELLOW, "　　　　　");
	for (int i = 24; i <= 32; i++) {
		Draw(26, i, BG_YELLOW, "　　　　　");
		if (i % 2 == 1 && i < 30) {
			Draw(28, i, BG_SKYBLUE, "　"); Draw(32, i, BG_SKYBLUE, "　");
		}
	}


	Draw(38, 21, BG_PURPLE, "　　　");
	Draw(38, 22, BG_PURPLE, "　　");

	Draw(38, 23, BG_PURPLE, "　　");
	Draw(38, 24, BG_PURPLE, "　　");
	Draw(40, 24, BG_SKYBLUE, "　");
	Draw(38, 25, BG_PURPLE, "　　　　　");
	Draw(38, 26, BG_PURPLE, "　　　");
	Draw(40, 26, BG_SKYBLUE, "　");
	Draw(38, 27, BG_PURPLE, "　　　　");
	Draw(38, 28, BG_PURPLE, "　　　　　　");
	Draw(40, 28, BG_SKYBLUE, "　"); Draw(44, 28, BG_SKYBLUE, "　"); Draw(48, 28, BG_SKYBLUE, "　");
	Draw(38, 29, BG_PURPLE, "　　　　　　　　　");
	Draw(38, 30, BG_PURPLE, "　　　　　　　　　");
	Draw(38, 31, BG_PURPLE, "　　　　　　　　　");
	Draw(38, 32, BG_PURPLE, "　　　　　　　　　");


	Draw(70, 2, BG_RED, "　　　　　　　　　　　　　");
	Draw(70, 3, BG_RED, "　"); Draw(72, 3, BG_YELLOW, "　　　　　　　　　　　"); Draw(94, 3, BG_RED, "　");
	Draw(70, 4, BG_RED, "　"); Draw(72, 4, BG_YELLOW, "　　　　　　　　　　　"); Draw(94, 4, BG_RED, "　");
	Draw(70, 5, BG_RED, "　"); Draw(72, 5, BG_YELLOW, "　　　　　　　　　　　"); Draw(94, 5, BG_RED, "　");
	Draw(70, 6, BG_RED, "　"); Draw(72, 6, BG_YELLOW, "　　　　　　　　　　　"); Draw(94, 6, BG_RED, "　");
	Draw(70, 7, BG_RED, "　"); Draw(72, 7, BG_YELLOW, "　　　　　　　　　　　"); Draw(94, 7, BG_RED, "　");
	Draw(72, 8, BG_RED, "　"); Draw(74, 8, BG_YELLOW, "　　　　　　　　　"); Draw(92, 8, BG_RED, "　");
	Draw(74, 9, BG_RED, "　"); Draw(76, 9, BG_YELLOW, "　　　　　　　"); Draw(90, 9, BG_RED, "　");
	Draw(76, 10, BG_RED, "　"); Draw(78, 10, BG_YELLOW, "　　　　　"); Draw(88, 10, BG_RED, "　");
	Draw(78, 11, BG_RED, "　"); Draw(80, 11, BG_YELLOW, "　　　"); Draw(86, 11, BG_RED, "　");
	Draw(80, 12, BG_RED, "　"); Draw(82, 12, BG_YELLOW, "　"); Draw(84, 12, BG_RED, "　");
	Draw(82, 13, BG_RED, "　");

	Draw(82, 4, BG_RED, "　");
	Draw(80, 5, BG_RED, "　　");
	Draw(82, 6, BG_RED, "　");
	Draw(82, 7, BG_RED, "　");
	Draw(82, 8, BG_RED, "　");
	Draw(82, 9, BG_RED, "　");
	Draw(80, 10, BG_RED, "　　　");
}



bool Scene_Gameover_Render(float timeDelta)
{
	Timer_ov += timeDelta;
	if (Timer_ov > 0.05) {
		Timer_sub++; Timer_ov = 0;
	}


	switch (Timer_sub) {
	case 1:
		Draw(10, 16, BG_YELLOW, "　");
		break;
	case 2:
		Draw(10, 16, YELLOW, "　");
		Draw(10, 14, BG_YELLOW, "　");
		break;
	case 3:
		Draw(10, 14, YELLOW, "　");
		Draw(10, 12, BG_YELLOW, "　");
		break;
	case 4:
		Draw(10, 12, YELLOW, "　");
		Draw(10, 10, BG_YELLOW, "　");
		break;
	case 5:
		Draw(10, 10, YELLOW, "　");
		Draw(10, 8, BG_YELLOW, "　");
		break;
	case 6:
		Draw(10, 8, YELLOW, "　");
		Draw(9, 7, BG_YELLOW, "　"); Draw(11, 7, BG_YELLOW, "　");
		Draw(6, 8, BG_YELLOW, "　"); Draw(14, 8, BG_YELLOW, "　");
		Draw(9, 9, BG_YELLOW, "　"); Draw(11, 9, BG_YELLOW, "　");
		break;
	case 7:
		Draw(9, 7, YELLOW, "　"); Draw(11, 7, YELLOW, "　");
		Draw(6, 8, YELLOW, "　"); Draw(14, 8, YELLOW, "　");
		Draw(9, 9, YELLOW, "　"); Draw(11, 9, YELLOW, "　");

		Draw(7, 5, BG_YELLOW, "　"); Draw(13, 5, BG_YELLOW, "　");
		Draw(2, 8, BG_YELLOW, "　"); Draw(18, 8, BG_YELLOW, "　");
		Draw(7, 11, BG_YELLOW, "　"); Draw(13, 11, BG_YELLOW, "　");

		break;
	case 8:
		Draw(7, 5,  YELLOW, "　"); Draw(13, 5,  YELLOW, "　");
		Draw(2, 8,  YELLOW, "　"); Draw(18, 8,  YELLOW, "　");
		Draw(7, 11,  YELLOW, "　"); Draw(13, 11,  YELLOW, "　");

		Draw(5, 3, BG_YELLOW, "　"); Draw(15, 3, BG_YELLOW, "　");
									 Draw(22, 8, BG_YELLOW, "　");
		Draw(5, 13, BG_YELLOW, "　"); Draw(15, 13, BG_YELLOW, "　");
		break;
	case 9:
		Draw(5, 3,  YELLOW, "　"); Draw(15, 3,  YELLOW, "　");
		Draw(22, 8,  YELLOW, "　");
		Draw(5, 13,  YELLOW, "　"); Draw(15, 13,  YELLOW, "　");

		Draw(3, 1,  BG_YELLOW, "　"); Draw(17, 1,  BG_YELLOW, "　");
									Draw(26, 8,  BG_YELLOW, "　");
		Draw(3, 15,  BG_YELLOW, "　"); Draw(17, 15,  BG_YELLOW, "　");

		break;
	case 10:
		Draw(3, 1,  YELLOW, "　"); Draw(17, 1,  YELLOW, "　");
		Draw(26, 8,  YELLOW, "　");
		Draw(3, 15,  YELLOW, "　"); Draw(17, 15,  YELLOW, "　");
		break;


	case 15:
		Draw(60, 32, BG_YELLOW, "　");
		break;
	case 16:
		Draw(60, 32, YELLOW, "　");
		Draw(60, 30, BG_YELLOW, "　");
		break;
	case 17:
		Draw(60, 30, YELLOW, "　");
		Draw(60, 28, BG_YELLOW, "　");
		break;
	case 18:
		Draw(60, 28, YELLOW, "　");
		Draw(60, 26, BG_YELLOW, "　");
		break;
	case 19:
		Draw(60, 26, YELLOW, "　");
		Draw(60, 24, BG_YELLOW, "　");
		break;
	case 20:
		Draw(60, 24, YELLOW, "　");
		Draw(59, 23, BG_YELLOW, "　"); Draw(61, 23, BG_YELLOW, "　");
		Draw(56, 24, BG_YELLOW, "　"); Draw(64, 24, BG_YELLOW, "　");
		Draw(59, 25, BG_YELLOW, "　"); Draw(61, 25, BG_YELLOW, "　");
		break;
	case 21:
		Draw(59, 23, YELLOW, "　"); Draw(61, 23, YELLOW, "　");
		Draw(56, 24, YELLOW, "　"); Draw(64, 24, YELLOW, "　");
		Draw(59, 25, YELLOW, "　"); Draw(61, 25, YELLOW, "　");

		Draw(57, 21, BG_YELLOW, "　"); Draw(63, 21, BG_YELLOW, "　");
		Draw(52, 24, BG_YELLOW, "　"); Draw(68, 24, BG_YELLOW, "　");
		Draw(57, 27, BG_YELLOW, "　"); Draw(63, 27, BG_YELLOW, "　");

		break;
	case 22:
		Draw(57, 21, YELLOW, "　"); Draw(63, 21, YELLOW, "　");
		Draw(52, 24, YELLOW, "　"); Draw(68, 24, YELLOW, "　");
		Draw(57, 27, YELLOW, "　"); Draw(63, 27, YELLOW, "　");

		Draw(55, 19, BG_YELLOW, "　"); Draw(65, 19, BG_YELLOW, "　");
		Draw(48, 24, BG_YELLOW, "　");	Draw(72, 24, BG_YELLOW, "　");
		Draw(55, 29, BG_YELLOW, "　"); Draw(65, 29, BG_YELLOW, "　");
		break;
	case 23:
		Draw(55, 19, YELLOW, "　"); Draw(65, 19, YELLOW, "　");
		Draw(48, 24, YELLOW, "　"); Draw(72, 24, YELLOW, "　");
		Draw(55, 29, YELLOW, "　"); Draw(65, 29, YELLOW, "　");

		Draw(53, 17, BG_YELLOW, "　"); Draw(67, 17, BG_YELLOW, "　");
		Draw(44, 24, BG_YELLOW, "　");	Draw(76, 24, BG_YELLOW, "　");
		Draw(53, 31, BG_YELLOW, "　"); Draw(67, 31, BG_YELLOW, "　");

		break;
	case 24:
		Draw(53, 17, YELLOW, "　"); Draw(67, 17, YELLOW, "　");
		Draw(44, 24, YELLOW, "　"); Draw(76, 24, YELLOW, "　");
		Draw(53, 31, YELLOW, "　"); Draw(67, 31, YELLOW, "　");
		Timer_sub = -5;
		break;
	}

	if (KeyDown(KEY_ENTER)) {
		Scene_Maintap_Init();
		SceneNumber = MAINTAP;

	}


	return true;
}