#include "Scene.h"


//현재 보여지는 장면 번호
int SceneNumber = INTRO;


//BGM번호
int select_BGM = BGM1; // 초기번호 1

//장면선택 렌더링 함수
bool SceneRender(float timeDelta)
{
	//장면 번호에 따라 Render 호출 변경
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
