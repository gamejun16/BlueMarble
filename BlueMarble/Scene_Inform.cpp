#include "Scene.h"
#include "Scene_Inform.h"

int inform_choice = 4;
int ui_choice = 1;
bool area_inform = false;
void Scene_Inform(void)
{
	Draw(118, 1, RED, "旨收收收收收收收收收收收旬");
	Draw(118, 2, RED, "早"); Draw(142, 2, RED, "早");
	Draw(118, 3, RED, "早"); Draw(142, 3, RED, "早");
	Draw(118, 4, RED, "早"); Draw(142, 4, RED, "早");
	Draw(118, 5, RED, "早"); Draw(142, 5, RED, "早");
	Draw(118, 6, RED, "早"); Draw(142, 6, RED, "早");
	Draw(118, 7, RED, "早"); Draw(142, 7, RED, "早");
	Draw(118, 8, RED, "早"); Draw(142, 8, RED, "早");
	Draw(118, 9, RED, "早"); Draw(142, 9, RED, "早");
	Draw(118, 10, RED, "早"); Draw(142, 10, RED, "早");
	Draw(118, 11, RED, "早"); Draw(142, 11, RED, "早");
	Draw(118, 12, RED, "早"); Draw(142, 12, RED, "早");
	Draw(118, 13, RED, "曲收收收收收收收收收收收旭");
	
	
	if (KeyDown(KEY_DOWN)) {
		if (inform_choice != 10) {
			Draw(124, inform_choice, WHITE, "﹛");
			inform_choice += 2;
		}
			
		else {
			Draw(124, inform_choice, WHITE, "﹛");
			inform_choice = 4;
		}
	}
	else if (KeyDown(KEY_UP)) {
		if (inform_choice != 4) {
			Draw(124, inform_choice, WHITE, "﹛");
			inform_choice -= 2;
		}
		else {
			Draw(124, inform_choice, WHITE, "﹛");
			inform_choice = 10;
		}
	}


	switch (inform_choice)
	{
	case 4:
		Draw(124, 4, WHITE, "Ⅱ");
		break;
	case 6:
		Draw(124, 6, WHITE, "Ⅱ");
		break;
	case 8:
		Draw(124, 8, WHITE, "Ⅱ");
		break;
	case 10:
		Draw(124, 10, WHITE, "Ⅱ");
		break;
	}
	
	if(KeyDown(KEY_ENTER)){
		// 給嬴陛晦
		if (inform_choice == 4) {
			Draw(118, 1, RED, "﹛﹛﹛﹛﹛﹛﹛﹛﹛﹛﹛﹛﹛");
			Draw(118, 2, RED, "﹛"); Draw(142, 2, RED, "﹛");
			Draw(118, 3, RED, "﹛"); Draw(142, 3, RED, "﹛");
			Draw(118, 4, RED, "﹛"); Draw(142, 4, RED, "﹛");
			Draw(118, 5, RED, "﹛"); Draw(142, 5, RED, "﹛");
			Draw(118, 6, RED, "﹛"); Draw(142, 6, RED, "﹛");
			Draw(118, 7, RED, "﹛"); Draw(142, 7, RED, "﹛");
			Draw(118, 8, RED, "﹛"); Draw(142, 8, RED, "﹛");
			Draw(118, 9, RED, "﹛"); Draw(142, 9, RED, "﹛");
			Draw(118, 10, RED, "﹛"); Draw(142, 10, RED, "﹛");
			Draw(118, 11, RED, "﹛"); Draw(142, 11, RED, "﹛");
			Draw(118, 12, RED, "﹛"); Draw(142, 12, RED, "﹛");
			Draw(118, 13, RED, "﹛﹛﹛﹛﹛﹛﹛﹛﹛﹛﹛﹛﹛");
			Sn_Inform = false;
		}

		/*
		// 階 薑爾
		else if (inform_choice == 6) {
			erase_ui(); // ui龔 餉薯
			print_area_ui();
			area_inform = true;
		}

		
		if (area_inform == true) {
			if (KeyDown(KEY_RIGHT)) {
				if (ui_choice >= 1 && ui_choice <= 8)
					ui_choice++;
				else if (ui_choice >= 9 && ui_choice <= 16)
					ui_choice += 16;
				else if (ui_choice >= 17 && ui_choice <= 24)
					ui_choice--;
				else if (ui_choice >= 25 && ui_choice <= 32)
					ui_choice -= 16;
			}
			else if (KeyDown(KEY_LEFT)) {
				if (ui_choice >= 1 && ui_choice <= 8) {
					if (ui_choice == 1)
						ui_choice = 32;
					else
						ui_choice--;
				}
				else if (ui_choice >= 9 && ui_choice <= 16)
					ui_choice += 16;
				else if (ui_choice >= 17 && ui_choice <= 24)
					ui_choice++;
				else if (ui_choice >= 25 && ui_choice <= 32)
					ui_choice -= 16;
			}
			else if (KeyDown(KEY_UP)) {
				if (ui_choice >= 1 && ui_choice <= 8)
					ui_choice += 16;
				else if (ui_choice >= 9 && ui_choice <= 16)
					ui_choice--;
				else if (ui_choice >= 17 && ui_choice <= 24)
					ui_choice -= 16;
				else if (ui_choice >= 25 && ui_choice <= 32)
					if (ui_choice == 25)
						ui_choice = 1;
					else
						ui_choice--;
			}
			else if (KeyDown(KEY_DOWN)) {
				if (ui_choice >= 1 && ui_choice <= 8)
					ui_choice += 16;
				else if (ui_choice >= 9 && ui_choice <= 16)
					ui_choice++;
				else if (ui_choice >= 17 && ui_choice <= 24)
					ui_choice -= 16;
				else if (ui_choice >= 25 && ui_choice <= 32)
					if (ui_choice == 25)
						ui_choice = 1;
					else
						ui_choice--;
			}

			Draw(122, 3, WHITE, "﹛﹛﹛﹛﹛﹛﹛﹛");
			Draw(122, 4, WHITE, "﹛"); Draw(136, 4, WHITE, "﹛");
			Draw(122, 5, WHITE, "﹛"); Draw(136, 5, WHITE, "﹛");
			Draw(122, 6, WHITE, "﹛"); Draw(136, 6, WHITE, "﹛");
			Draw(122, 7, WHITE, "﹛"); Draw(136, 7, WHITE, "﹛");
			Draw(122, 8, WHITE, "﹛"); Draw(136, 8, WHITE, "﹛");
			Draw(122, 9, WHITE, "﹛"); Draw(136, 9, WHITE, "﹛");
			Draw(122, 10, WHITE, "﹛﹛﹛﹛﹛﹛﹛﹛");



			if (ui_choice >= 1 && ui_choice <= 8)
				Draw(120 + ui_choice * 2, 3, WHITE, "∟");
			else if (ui_choice >= 9 && ui_choice <= 16)
				Draw(136, ui_choice - 6, WHITE, "⊥");
		}
		*/


		// 啪歜 謙猿
		else if (inform_choice == 10) {
			Scene_Intro_Init();
			SceneNumber = INTRO;
		}
	}
}


// ui龔 餉薯
void erase_ui(void)
{
	Draw(120, 2, WHITE, "﹛﹛﹛﹛﹛﹛﹛﹛﹛﹛﹛");
	Draw(120, 3, WHITE, "﹛");										Draw(140, 3, WHITE, "﹛");
	Draw(120, 4, WHITE, "﹛"); Draw(128, 4, WHITE, "﹛﹛﹛﹛");		Draw(140, 4, WHITE, "﹛");
	Draw(120, 5, WHITE, "﹛");										Draw(140, 5, WHITE, "﹛");
	Draw(120, 6, WHITE, "﹛"); Draw(128, 6, WHITE, "﹛﹛﹛﹛");		Draw(140, 6, WHITE, "﹛");
	Draw(120, 7, WHITE, "﹛");										Draw(140, 7, WHITE, "﹛");
	Draw(120, 8, WHITE, "﹛"); Draw(128, 8, WHITE, "﹛﹛﹛﹛");		Draw(140, 8, WHITE, "﹛");
	Draw(120, 9, WHITE, "﹛");										Draw(140, 9, WHITE, "﹛");
	Draw(120, 10, WHITE, "﹛"); Draw(128, 10, WHITE, "﹛﹛﹛﹛");	Draw(140, 10, WHITE, "﹛");
	Draw(120, 11, WHITE, "﹛");										Draw(140, 11, WHITE, "﹛");
	Draw(120, 12, WHITE, "﹛﹛﹛﹛﹛﹛﹛﹛﹛﹛﹛");

	Draw(118, 1, RED, "﹛﹛﹛﹛﹛﹛﹛﹛﹛﹛﹛﹛﹛");
	Draw(118, 2, RED, "﹛"); Draw(142, 2, RED, "﹛");
	Draw(118, 3, RED, "﹛"); Draw(142, 3, RED, "﹛");
	Draw(118, 4, RED, "﹛"); Draw(142, 4, RED, "﹛");
	Draw(118, 5, RED, "﹛"); Draw(142, 5, RED, "﹛");
	Draw(118, 6, RED, "﹛"); Draw(142, 6, RED, "﹛");
	Draw(118, 7, RED, "﹛"); Draw(142, 7, RED, "﹛");
	Draw(118, 8, RED, "﹛"); Draw(142, 8, RED, "﹛");
	Draw(118, 9, RED, "﹛"); Draw(142, 9, RED, "﹛");
	Draw(118, 10, RED, "﹛"); Draw(142, 10, RED, "﹛");
	Draw(118, 11, RED, "﹛"); Draw(142, 11, RED, "﹛");
	Draw(118, 12, RED, "﹛"); Draw(142, 12, RED, "﹛");
	Draw(118, 13, RED, "﹛﹛﹛﹛﹛﹛﹛﹛﹛﹛﹛﹛﹛");

	Draw(124, inform_choice, WHITE, "﹛");
	Sn_Inform = false;
	
}

