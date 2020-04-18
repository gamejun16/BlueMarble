#ifndef __INPUT_H__
#define __INPUT_H__


#include <stdio.h>
#include <conio.h>
#include <Windows.h>

//대표 키코드 값
#define KEY_UP 0x48
#define KEY_LEFT 0x4B
#define KEY_RIGHT 0x4D
#define KEY_DOWN 0x50
#define KEY_ENTER 13
#define KEY_SPACE 32
#define KEY_P 'P'
#define KEY_p 'p'


//키보드 입력 - 업데이트 함수
void InputUpdate();
//키보드 입력 - 후 업데이트 함수
void InputLateUpdate();
//키보드 입력 확인 함수
bool KeyDown(int keyCode);
//커서 깜빡임 제거 함수
void removeCursor(void);
#endif

