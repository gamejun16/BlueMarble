#include "Scene.h"
#include "Scene_Manual.h"

void Scene_Manual_Init()
{
	system("cls");
}

bool Scene_Manual_Render(float timeDelta)
{
	Draw(8, 2, BG_GREEN, "Θ 게임 설명 Θ       「 제작 진민준 」");
	Draw(4, 5, GREEN, "- 본 게임은 기존 \"부루마블\" 을 카피하여 제작하였습니다.");
	Draw(4, 8, GREEN, "- 각 플레이어는 자신의 턴 마다 주사위를 굴려가며 게임을 진행합니다.");
	Draw(4, 11, GREEN, "- 통행료의 부과, 건물 업그레이드는 물론 인수 및 찬스 기능까지 구현 되었습니다.");
	Draw(4, 14, GREEN, "- 현재 더블은 발생하지 않으며, 오직 울릉도를 탈출할 때에만 기능합니다.");
	Draw(4, 17, GREEN, "- 소지금이 0미만이 되면 파산하게됩니다. (되팔기 기능은 구현되지 않았습니다)");
	Draw(4, 20, GREEN, "- 한 명의 플레이어라도 파산하게 되면 꼴찌 확정과 동시에 게임이 종료됩니다.");
	Draw(4, 23, GREEN, "- 파산한 플레이어를 제외한 나머지는 총 자산을 기준으로 순위가 메겨집니다.");
	Draw(4, 26, GREEN, "- 유저가 1등을 하게 되면 총 자산이 랭킹에 기록됩니다.");



	if (KeyDown(KEY_ENTER)) {
		//pChannel[1]->stop();
		pSystem->playSound(FMOD_CHANNEL_REUSE, pSound[Enter], false, &pChannel[1]); // 엔터효과음
		Scene_Maintap_Init();
		SceneNumber = MAINTAP;
	}

	return true;
}

