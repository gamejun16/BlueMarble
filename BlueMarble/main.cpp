#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <time.h>

/////////////////////////////////////FMOD//////////////////////////////////////////////

#include <conio.h>
#include <iostream>
using namespace std;

#include "fmod.hpp"
#pragma	comment (lib, "fmodex_vc.lib")
using namespace FMOD;

System*	pSystem;

//	사운드의 개수만큼 필요
Sound*	pSound[13];

//	동시에 출력될 사운드 만큼 필요
Channel*pChannel[2];


bool FMOD_check = true;




///////////////////////////////////////////////////////////////////////////////////

#include "Scene.h"

void main()
{
	if (FMOD_check) {
		//////////////////FMOD///////////////////
		FMOD_check = false; // 한 번만 세팅


		//사운드 시스템을 생성
		System_Create(&pSystem);
		//	사운드 시스템 기본 세팅
		pSystem->init(2, FMOD_INIT_NORMAL, NULL);

		//	음악파일 생성
		pSystem->createSound(
			"Intro.wav",	//	사운드파일경로 // Intro bgm
			FMOD_HARDWARE,	//	사운드파일옵션
			NULL,			//	확장데이터(쓰지않음)
			&pSound[Intro]);	//	저장할 사운드 포인터

		pSystem->createSound(
			"BGM1.wav", // maintap bgm
			FMOD_HARDWARE,
			NULL,
			&pSound[BGM1]);

		pSystem->createSound(
			"BGM2.wav", // maintap bgm
			FMOD_HARDWARE,
			NULL,
			&pSound[BGM2]);

		pSystem->createSound(
			"BGM3.wav", // maintap bgm
			FMOD_HARDWARE,
			NULL,
			&pSound[BGM3]);

		pSystem->createSound(
			"BGM4.wav", // maintap bgm
			FMOD_HARDWARE,
			NULL,
			&pSound[BGM4]);

		pSystem->createSound(
			"Ending.wav", // 엔딩 bgm
			FMOD_HARDWARE,
			NULL,
			&pSound[Ending]);

		pSystem->createSound(
			"Dice.wav", // 주사위 굴리는 소리
			FMOD_LOOP_OFF | FMOD_HARDWARE,// 효과음. loop - OFF
			NULL,
			&pSound[Dice]);

		pSystem->createSound(
			"Button.wav",  // 메인탭 탭 이동 효과음
			FMOD_LOOP_OFF | FMOD_HARDWARE,// 효과음. loop - OFF
			NULL,
			&pSound[Button]);

		pSystem->createSound(
			"Enter.wav",  // 메인탭 Enter 입력 효과음
			FMOD_LOOP_OFF | FMOD_HARDWARE,// 효과음. loop - OFF
			NULL,
			&pSound[Enter]);

		pSystem->createSound(
			"Bell.wav",  // 메인탭 탭 이동 효과음
			FMOD_LOOP_OFF | FMOD_HARDWARE,// 효과음. loop - OFF
			NULL,
			&pSound[Bell]);

		pSystem->createSound(
			"Oops.wav",  // 메인탭 Enter 입력 효과음
			FMOD_LOOP_OFF | FMOD_HARDWARE,// 효과음. loop - OFF
			NULL,
			&pSound[Oops]);

		pSystem->createSound(
			"Error.wav",  // 메인탭 Enter 입력 효과음
			FMOD_LOOP_OFF | FMOD_HARDWARE,// 효과음. loop - OFF
			NULL,
			&pSound[Error]);

		pSystem->createSound(
			"Money.wav",  // 메인탭 Enter 입력 효과음
			FMOD_LOOP_OFF | FMOD_HARDWARE,// 효과음. loop - OFF
			NULL,
			&pSound[Money]);
		/////////////////////////////////////
	}


	float timeDelta = 0.0f;		//한번의 렌더링을 수행한 시간
	float lastTime = 0.0f;		//마지막으로 렌더링 완료한 시간

	float Timer = 0.0f;			//타이머
	int FrameCount = 0;			//Frame 카운트
	int FPS = 0;				//Frame Per Second(초당 프레임 수)
	
	//랜덤 시드값 초기화
	srand((int)time(NULL));
    //화면크기 변경
	system("mode con:cols=80 lines=28");
	//커서 깜빡임 제거
	removeCursor();
	//창 이름 변경
	SetConsoleTitle(TEXT("BLUE_MARBLE"));

	while (true)
	{
		//현재 시간 가져오기
		float currentTime = clock() * 0.001;
		//이전 시간과 현재 시간의 차로 TimeDelta 구하기
		timeDelta = currentTime - lastTime;

		//키보드 입력 업데이트
		InputUpdate();
		
		//렌더링(Rendering)
		if (!SceneRender(timeDelta)) break;

		//렌더링 후, 키보드 입력 후 업데이트
		InputLateUpdate();

		//화면 지우기
		//system("cls");
		//현재 시간을 이전 시간으로 저장하기
		lastTime = currentTime;
		//Frame Per Second 측정
		Timer += timeDelta;
		FrameCount++;			//Frame 카운트
								//1초가 될 때 마다 수행
		if (Timer >= 1.0f)
		{
			//FPS 저장
			FPS = FrameCount;
			//카운트 초기화
			FrameCount = 0;
			//타이머 초기화(0초부터 다시 시작)
			Timer = 0.0f;
		}
	}
}

