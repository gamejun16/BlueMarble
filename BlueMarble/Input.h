#ifndef __INPUT_H__
#define __INPUT_H__


#include <stdio.h>
#include <conio.h>
#include <Windows.h>

//��ǥ Ű�ڵ� ��
#define KEY_UP 0x48
#define KEY_LEFT 0x4B
#define KEY_RIGHT 0x4D
#define KEY_DOWN 0x50
#define KEY_ENTER 13
#define KEY_SPACE 32
#define KEY_P 'P'
#define KEY_p 'p'


//Ű���� �Է� - ������Ʈ �Լ�
void InputUpdate();
//Ű���� �Է� - �� ������Ʈ �Լ�
void InputLateUpdate();
//Ű���� �Է� Ȯ�� �Լ�
bool KeyDown(int keyCode);
//Ŀ�� ������ ���� �Լ�
void removeCursor(void);
#endif

