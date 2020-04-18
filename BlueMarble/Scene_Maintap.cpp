#include "Scene.h"
#include "Scene_Maintap.h"

int choose = 1;

void Scene_Maintap_Init()
{
	system("cls");
	textcolor(0);
	choose = 1;
	system("mode con:cols=102 lines=34");
	//�ܼ�â ũ�� ����

	pSystem->playSound(FMOD_CHANNEL_REUSE, pSound[select_BGM], false, &pChannel[0]);
	pChannel[0]->setVolume(fVolume);

	/*
	PlaySound(TEXT("Maintap.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP | SND_NODEFAULT);
	//���.wav������ ��������Ű�� ���ÿ� �����ŵ�ϴ�
	//bgm�� ��
	*/
}

bool Scene_Maintap_Render(float timeDelta)
{
	Draw(2, 2, GREEN, "Geeeeeeee5   ee       ee,      ee  eeeeeeee");
	Draw(2, 3, GREEN, "ee      eX   ee       ee       ee  eW      ");
	Draw(2, 4, GREEN, "ee      e    ee       ee       ee  eu      ");
	Draw(2, 5, GREEN, "GeeeeeeeeeE #ee       eee      ee  eeeeeeee");
	Draw(2, 6, GREEN, "Eee      ee eee       eee      ee  ee      ");
	Draw(2, 7, GREEN, "Eee      ee eee       eee      ee  ee      ");
	Draw(2, 8, GREEN, "Eeeeeeeeeee eeeeeeeee 9eeeeeeeeee  eeeeeeee");

	Draw(30, 10, GREEN, "ueeeeeeeeeeee  zeeeeeeeee  eeeeeeeeeG  Deeeeeeeee    ee       eeeeeeee");
	Draw(30, 11, GREEN, "Ke    ee   ee  #e      ee  ee      ee  #e      Ee    ee       ee      ");
	Draw(30, 12, GREEN, "ue    ee   ee  5e      ee  ee      eE  ze      9e    ee       ee      ");
	Draw(30, 13, GREEN, "uee   ee   ee  eeeeeeeeeee eeeeeeeeeee Xeeeeeeeeee  eee       eeeeeeee");
	Draw(30, 14, GREEN, "uee   ee   ee zee      eee eee      9e yee       e  eee       eey     ");
	Draw(30, 15, GREEN, "uee   ee   ee Xee      eee eee      ee yee       e  eee       eeX     ");
	Draw(30, 16, GREEN, "Wee   ee   ee Xee      eee eee      ee yeeeeeeeeee  eeeeeeeee eeeeeeee");


	Draw(46, 20, WHITE, ""); textcolor(8); printf("���ӽ���");
	Draw(46, 22, WHITE, ""); textcolor(8); printf("�� �� ��");
	Draw(46, 24, WHITE, ""); textcolor(8); printf("��  ����");
	Draw(46, 26, WHITE, ""); textcolor(8); printf("BGM ����");
	Draw(46, 28, WHITE, ""); textcolor(8); printf("��������");

	switch (choose) {
	case 1:
		Draw(46, 20, WHITE, "���ӽ���");
		break;
	case 2:
		Draw(46, 22, WHITE, "�� �� ��");
		break;
	case 3:
		Draw(46, 24, WHITE, "��  ����");
		break;
	case 4:
		Draw(46, 26, WHITE, "BGM ����");
		break;
	case 5:
		Draw(46, 28, WHITE, "��������");
		break;
	}
	


	if (KeyDown(KEY_UP)) {
		pSystem->playSound(FMOD_CHANNEL_REUSE, pSound[Button], false, &pChannel[1]);

		if (choose == 1) choose = 5;
		else choose--;
	}
	else if (KeyDown(KEY_DOWN)) {
		pSystem->playSound(FMOD_CHANNEL_REUSE, pSound[Button], false, &pChannel[1]);

		if (choose == 5) choose = 1;
		else choose++;
	}

	if (KeyDown(KEY_ENTER)) {
		pSystem->playSound(FMOD_CHANNEL_REUSE, pSound[Enter], false, &pChannel[1]); // ����ȿ����
		if (choose == 1) { // START GAME

			//Scene_Gameover_Init();
			//SceneNumber = GAMEOVER;
			Scene_Ingame_Init();
			SceneNumber = INGAME;
		}
		else if (choose == 2) {
			Scene_Manual_Init();
			SceneNumber = MANUAL;
		}
		else if (choose == 3) {
			Scene_FixArea_Init();
			SceneNumber = FIXAREA;
		}
		else if (choose == 4) {
			Scene_Option_Init();
			SceneNumber = OPTION;
		}
		else if (choose == 5)
			return false;
	}


	return true;
}