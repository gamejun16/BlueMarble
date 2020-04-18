#include "Scene.h"
#include "Scene_Manual.h"

void Scene_Manual_Init()
{
	system("cls");
}

bool Scene_Manual_Render(float timeDelta)
{
	Draw(8, 2, BG_GREEN, "�� ���� ���� ��       �� ���� ������ ��");
	Draw(4, 5, GREEN, "- �� ������ ���� \"�η縶��\" �� ī���Ͽ� �����Ͽ����ϴ�.");
	Draw(4, 8, GREEN, "- �� �÷��̾�� �ڽ��� �� ���� �ֻ����� �������� ������ �����մϴ�.");
	Draw(4, 11, GREEN, "- ������� �ΰ�, �ǹ� ���׷��̵�� ���� �μ� �� ���� ��ɱ��� ���� �Ǿ����ϴ�.");
	Draw(4, 14, GREEN, "- ���� ������ �߻����� ������, ���� �︪���� Ż���� ������ ����մϴ�.");
	Draw(4, 17, GREEN, "- �������� 0�̸��� �Ǹ� �Ļ��ϰԵ˴ϴ�. (���ȱ� ����� �������� �ʾҽ��ϴ�)");
	Draw(4, 20, GREEN, "- �� ���� �÷��̾�� �Ļ��ϰ� �Ǹ� ���� Ȯ���� ���ÿ� ������ ����˴ϴ�.");
	Draw(4, 23, GREEN, "- �Ļ��� �÷��̾ ������ �������� �� �ڻ��� �������� ������ �ް����ϴ�.");
	Draw(4, 26, GREEN, "- ������ 1���� �ϰ� �Ǹ� �� �ڻ��� ��ŷ�� ��ϵ˴ϴ�.");



	if (KeyDown(KEY_ENTER)) {
		//pChannel[1]->stop();
		pSystem->playSound(FMOD_CHANNEL_REUSE, pSound[Enter], false, &pChannel[1]); // ����ȿ����
		Scene_Maintap_Init();
		SceneNumber = MAINTAP;
	}

	return true;
}

