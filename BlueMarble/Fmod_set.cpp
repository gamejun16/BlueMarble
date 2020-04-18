/*
#include <conio.h>
#include <iostream>
using namespace std;

#include "Scene.h"
#include "Scene_Option.h"

#include "fmod.hpp"
#pragma	comment (lib, "fmodex_vc.lib")
using namespace FMOD;

System*			pSystem;

//	사운드의 개수만큼 필요
Sound*			pSound[2];

//	동시에 출력될 사운드 만큼 필요
Channel*		pChannel[2];


//사운드 시스템을 생성
System_Create(&pSystem);
//	사운드 시스템 기본 세팅
pSystem->init(2, FMOD_INIT_NORMAL, NULL);

//	음악파일 생성
pSystem->createSound(
	"04.Over_The_Rainbow-hyung729.wma",	//	사운드파일경로
	FMOD_HARDWARE,	//	사운드파일옵션
	NULL,			//	확장데이터(쓰지않음)
	&pSound[0]);	//	저장할 사운드 포인터

pSystem->createSound(
	"효과음-성공.mp3",
	FMOD_LOOP_OFF | FMOD_HARDWARE,
	NULL,
	&pSound[1]);

	*/
