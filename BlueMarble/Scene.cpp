#include "Scene.h"


//���� �������� ��� ��ȣ
int SceneNumber = INTRO;


//BGM��ȣ
int select_BGM = BGM1; // �ʱ��ȣ 1

//��鼱�� ������ �Լ�
bool SceneRender(float timeDelta)
{
	//��� ��ȣ�� ���� Render ȣ�� ����
	if (SceneNumber == INTRO) Scene_Intro_Render(timeDelta);
	else if (SceneNumber == MAINTAP) { if (Scene_Maintap_Render(timeDelta) == false) return false; }
	else if (SceneNumber == MANUAL) Scene_Manual_Render(timeDelta); // MAINTAP / MANUAL
	else if (SceneNumber == OPTION) Scene_Option_Render(timeDelta);
	else if (SceneNumber == INGAME) Scene_Ingame_Render(timeDelta);
	else if (SceneNumber == INGAME_OPTION) Scene_Ingame_Option_Render(timeDelta);
	else if (SceneNumber == FIXAREA) Scene_FixArea_Render(timeDelta);
	else if (SceneNumber == GAMEOVER) Scene_Gameover_Render(timeDelta);

	return true;
}
