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

//	������ ������ŭ �ʿ�
Sound*	pSound[13];

//	���ÿ� ��µ� ���� ��ŭ �ʿ�
Channel*pChannel[2];


bool FMOD_check = true;




///////////////////////////////////////////////////////////////////////////////////

#include "Scene.h"

void main()
{
	if (FMOD_check) {
		//////////////////FMOD///////////////////
		FMOD_check = false; // �� ���� ����


		//���� �ý����� ����
		System_Create(&pSystem);
		//	���� �ý��� �⺻ ����
		pSystem->init(2, FMOD_INIT_NORMAL, NULL);

		//	�������� ����
		pSystem->createSound(
			"Intro.wav",	//	�������ϰ�� // Intro bgm
			FMOD_HARDWARE,	//	�������Ͽɼ�
			NULL,			//	Ȯ�嵥����(��������)
			&pSound[Intro]);	//	������ ���� ������

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
			"Ending.wav", // ���� bgm
			FMOD_HARDWARE,
			NULL,
			&pSound[Ending]);

		pSystem->createSound(
			"Dice.wav", // �ֻ��� ������ �Ҹ�
			FMOD_LOOP_OFF | FMOD_HARDWARE,// ȿ����. loop - OFF
			NULL,
			&pSound[Dice]);

		pSystem->createSound(
			"Button.wav",  // ������ �� �̵� ȿ����
			FMOD_LOOP_OFF | FMOD_HARDWARE,// ȿ����. loop - OFF
			NULL,
			&pSound[Button]);

		pSystem->createSound(
			"Enter.wav",  // ������ Enter �Է� ȿ����
			FMOD_LOOP_OFF | FMOD_HARDWARE,// ȿ����. loop - OFF
			NULL,
			&pSound[Enter]);

		pSystem->createSound(
			"Bell.wav",  // ������ �� �̵� ȿ����
			FMOD_LOOP_OFF | FMOD_HARDWARE,// ȿ����. loop - OFF
			NULL,
			&pSound[Bell]);

		pSystem->createSound(
			"Oops.wav",  // ������ Enter �Է� ȿ����
			FMOD_LOOP_OFF | FMOD_HARDWARE,// ȿ����. loop - OFF
			NULL,
			&pSound[Oops]);

		pSystem->createSound(
			"Error.wav",  // ������ Enter �Է� ȿ����
			FMOD_LOOP_OFF | FMOD_HARDWARE,// ȿ����. loop - OFF
			NULL,
			&pSound[Error]);

		pSystem->createSound(
			"Money.wav",  // ������ Enter �Է� ȿ����
			FMOD_LOOP_OFF | FMOD_HARDWARE,// ȿ����. loop - OFF
			NULL,
			&pSound[Money]);
		/////////////////////////////////////
	}


	float timeDelta = 0.0f;		//�ѹ��� �������� ������ �ð�
	float lastTime = 0.0f;		//���������� ������ �Ϸ��� �ð�

	float Timer = 0.0f;			//Ÿ�̸�
	int FrameCount = 0;			//Frame ī��Ʈ
	int FPS = 0;				//Frame Per Second(�ʴ� ������ ��)
	
	//���� �õ尪 �ʱ�ȭ
	srand((int)time(NULL));
    //ȭ��ũ�� ����
	system("mode con:cols=80 lines=28");
	//Ŀ�� ������ ����
	removeCursor();
	//â �̸� ����
	SetConsoleTitle(TEXT("BLUE_MARBLE"));

	while (true)
	{
		//���� �ð� ��������
		float currentTime = clock() * 0.001;
		//���� �ð��� ���� �ð��� ���� TimeDelta ���ϱ�
		timeDelta = currentTime - lastTime;

		//Ű���� �Է� ������Ʈ
		InputUpdate();
		
		//������(Rendering)
		if (!SceneRender(timeDelta)) break;

		//������ ��, Ű���� �Է� �� ������Ʈ
		InputLateUpdate();

		//ȭ�� �����
		//system("cls");
		//���� �ð��� ���� �ð����� �����ϱ�
		lastTime = currentTime;
		//Frame Per Second ����
		Timer += timeDelta;
		FrameCount++;			//Frame ī��Ʈ
								//1�ʰ� �� �� ���� ����
		if (Timer >= 1.0f)
		{
			//FPS ����
			FPS = FrameCount;
			//ī��Ʈ �ʱ�ȭ
			FrameCount = 0;
			//Ÿ�̸� �ʱ�ȭ(0�ʺ��� �ٽ� ����)
			Timer = 0.0f;
		}
	}
}

