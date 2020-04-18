/*
#include <conio.h>
#include <iostream>
using namespace std;

#include "fmod.hpp"
#pragma	comment (lib, "fmodex_vc.lib")
using namespace FMOD;

System*			pSystem;

//	사운드의 개수만큼 필요
Sound*			pSound[2];

//	동시에 출력될 사운드 만큼 필요
Channel*		pChannel[2];

void main(void)
{
	//사운드 시스템을 생성
	System_Create(&pSystem);
	//	사운드 시스템 기본 세팅
	pSystem->init(2, FMOD_INIT_NORMAL, NULL );

	//	음악파일 생성
	pSystem->createSound( 
		"04.Over_The_Rainbow-hyung729.wma",	//	사운드파일경로
		FMOD_HARDWARE,	//	사운드파일옵션
		NULL,			//	확장데이터(쓰지않음)
		&pSound[0] );	//	저장할 사운드 포인터

	pSystem->createSound( 
		"효과음-성공.mp3", 
		FMOD_LOOP_OFF  | FMOD_HARDWARE, 
		NULL, 
		&pSound[1] );

	bool	bPlay			=	true;
	bool	IsBGPlaying		=	false;
	bool	IsEffectPlaying	=	false;
	float	fVolume			=	1;
	
	while(bPlay)
	{
		pChannel[0]->isPlaying(&IsBGPlaying);
		pChannel[1]->isPlaying(&IsEffectPlaying);

		cout << "배경음악 : ";

		if( IsBGPlaying )
		{
			cout << "재생중" << endl;
		}
		else
		{
			cout << "정  지" << endl;
		}

		cout << "효 과 음 : "; 

		if( IsEffectPlaying )
		{
			cout << "재생중" << endl;
		}
		else
		{
			cout << "정  지" << endl;
		}

		cout << "배경음볼륨 : " << fVolume << endl;
		
		cout << "1. 배경음악재생" << endl;
		cout << "2. 배경음악정지" << endl;
		cout << "3. 효과음 재 생" << endl;
		cout << "4. 프로그램종료" << endl;
		cout << "+. 배경음키우기" << endl;
		cout << "-. 배경음줄이기" << endl;
		cout << "바로 입력 >>";

		if( _kbhit() )
		{
			char cChar	=	_getch();

			switch( cChar )
			{
			case '1':
				{
					pSystem->playSound( FMOD_CHANNEL_REUSE, pSound[0], false, &pChannel[0] );
					pChannel[0]->setVolume(fVolume);
				}
				break;
			case '2':
				{
					pChannel[0]->stop();
				}	
				break;
			case '3':
				{
					pSystem->playSound( FMOD_CHANNEL_REUSE, pSound[1], false, &pChannel[1] );
				}
				break;
			case '4':
				{
					bPlay = false;
				}
				break;
			case '+':
				{
					pChannel[0]->getVolume(&fVolume);
					pChannel[0]->setVolume(fVolume+0.1f);
				}
				break;
			case '-':
				{
					pChannel[0]->getVolume(&fVolume);
					pChannel[0]->setVolume(fVolume-0.1f);
				}
				break;
			}
		}

		_sleep(50);
		system("cls");
	}

	//	음악파일 해제
	pSound[0]->release();
	pSound[1]->release();

	//	시스템 해제
	pSystem->release();
	//	시스템 닫기
	pSystem->close();
}
*/