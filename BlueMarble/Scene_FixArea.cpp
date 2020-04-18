#include "Scene.h"
#include "Scene_FixArea.h"


int choice = 1;
bool fix_on = false;
char newname[7]; // 새 이름

void Scene_FixArea_Init()
{
	fix_on = false;

	choice = 1;

	system("cls");

	Draw(45, 4, GREEN, "땅 이름 바꾸기");

	Draw(28, 7, GREEN, "┏━━━━━━━━━━━━━━━━━━━━━━┓");

	Draw(28, 11, GREEN, "┗━━━━━━━━━━━━━━━━━━━━━━┛");

}

bool Scene_FixArea_Render(float timeDelta)
{

	Draw(49, 8, WHITE, ""); textcolor(8); printf("%s", field[(choice - 1 > 0 && (choice - 1) % 3 != 0) ? choice - 1 : (choice - 1 > 0 ? choice - 2 : 35 )].region_name);
	Draw(49, 9, WHITE, "%s", field[choice].region_name);
	Draw(49, 10, WHITE, ""); textcolor(8); printf("%s", field[(choice+1<36&&(choice+1)%3!=0)?choice+1:(choice+1<35?choice+2:1)].region_name);
	Draw(44, 20, WHITE, "SPACE : 땅 선택");
	Draw(39, 22, WHITE, "ENTER : 저장 후 돌아가기");


	if (fix_on) {
		Draw(40, 15, WHITE, "%s    →  ", field[choice].region_name);

		Draw(55, 15, WHITE, ""); textcolor(7); scanf("%s", &newname); // 새 이름 입력받음
		newname[6] = NULL;
		for (int i = 0; i < 6; i++)
			field[choice].region_name[i] = NULL;
		strcpy(field[choice].region_name, newname); // 변경
		Draw(40, 15, WHITE, "　　　　　　　　　　　　　　　　　　　　　　　　");
		Draw(49, 9, WHITE, "　　　");
		fix_on = false;
	}


	if (KeyDown(KEY_UP)) {
		Draw(49, 8, WHITE, "　　　");
		Draw(49, 9, WHITE, "　　　");
		Draw(49, 10, WHITE, "　　　");
		pSystem->playSound(FMOD_CHANNEL_REUSE, pSound[Button], false, &pChannel[1]);

		if (choice == 1) choice = 35;
		else if (choice % 3 == 1) choice -= 2;
		else choice -= 1;
	}
	
	else if (KeyDown(KEY_DOWN)) {
		Draw(49, 8, WHITE, "　　　");
		Draw(49, 9, WHITE, "　　　");
		Draw(49, 10, WHITE, "　　　");
		pSystem->playSound(FMOD_CHANNEL_REUSE, pSound[Button], false, &pChannel[1]);

		if (choice == 35) choice = 1;
		else if (choice % 3 == 2) choice += 2;
		else choice += 1;
	}

	else if (KeyDown(KEY_SPACE)) {

		if (fix_on) {
			fix_on = false;
			Draw(49, 9, WHITE, "　　　");
			Draw(40, 15, WHITE, "　　　　　　　　　　　　　　　　　　　　　　　　");
		}
		else fix_on = true;
	}

	else  if (KeyDown(KEY_ENTER)) {
		pSystem->playSound(FMOD_CHANNEL_REUSE, pSound[Enter], false, &pChannel[1]);

		Scene_Maintap_Init();
		SceneNumber = MAINTAP;
	}


	return true;
}