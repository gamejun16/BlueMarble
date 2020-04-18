#ifndef __DRAW_H__
#define __DRAW_H__

#include <stdio.h>
#include <conio.h>
#include <Windows.h>

//색상 매크로 정의
#define RED				(FOREGROUND_RED | FOREGROUND_INTENSITY)
#define GREEN			(FOREGROUND_GREEN | FOREGROUND_INTENSITY)
#define BLUE			(FOREGROUND_BLUE | FOREGROUND_INTENSITY)
#define PURPLE			(RED | BLUE)
#define WHITE			(RED | GREEN | BLUE)
#define YELLOW			(RED | GREEN)
#define SKYBLUE			(GREEN | BLUE)

#define BG_RED			(BACKGROUND_RED | BACKGROUND_INTENSITY)
#define BG_GREEN		(BACKGROUND_GREEN | BACKGROUND_INTENSITY)
#define BG_BLUE			(BACKGROUND_BLUE | BACKGROUND_INTENSITY)
#define BG_PURPLE		(BG_RED | BG_BLUE)
#define BG_WHITE		(BG_RED | BG_GREEN | BG_BLUE)
#define BG_YELLOW		(BG_RED | BG_GREEN)
#define BG_SKYBLUE		(BG_GREEN | BG_BLUE)

//Draw 함수
void Draw(int x, int y, int color, char *text, ...);
//글자색 변경
void textcolor(int color_number);

#endif

