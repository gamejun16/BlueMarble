/*
#include <conio.h>
#include <iostream>
using namespace std;

#include "fmod.hpp"
#pragma	comment (lib, "fmodex_vc.lib")
using namespace FMOD;

System*			pSystem;

//	������ ������ŭ �ʿ�
Sound*			pSound[2];

//	���ÿ� ��µ� ���� ��ŭ �ʿ�
Channel*		pChannel[2];

void main(void)
{
	//���� �ý����� ����
	System_Create(&pSystem);
	//	���� �ý��� �⺻ ����
	pSystem->init(2, FMOD_INIT_NORMAL, NULL );

	//	�������� ����
	pSystem->createSound( 
		"04.Over_The_Rainbow-hyung729.wma",	//	�������ϰ��
		FMOD_HARDWARE,	//	�������Ͽɼ�
		NULL,			//	Ȯ�嵥����(��������)
		&pSound[0] );	//	������ ���� ������

	pSystem->createSound( 
		"ȿ����-����.mp3", 
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

		cout << "������� : ";

		if( IsBGPlaying )
		{
			cout << "�����" << endl;
		}
		else
		{
			cout << "��  ��" << endl;
		}

		cout << "ȿ �� �� : "; 

		if( IsEffectPlaying )
		{
			cout << "�����" << endl;
		}
		else
		{
			cout << "��  ��" << endl;
		}

		cout << "��������� : " << fVolume << endl;
		
		cout << "1. ����������" << endl;
		cout << "2. �����������" << endl;
		cout << "3. ȿ���� �� ��" << endl;
		cout << "4. ���α׷�����" << endl;
		cout << "+. �����Ű���" << endl;
		cout << "-. ��������̱�" << endl;
		cout << "�ٷ� �Է� >>";

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

	//	�������� ����
	pSound[0]->release();
	pSound[1]->release();

	//	�ý��� ����
	pSystem->release();
	//	�ý��� �ݱ�
	pSystem->close();
}
*/