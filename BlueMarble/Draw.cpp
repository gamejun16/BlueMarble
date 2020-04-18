#include "Draw.h"

void Draw(int x, int y, int color, char *text, ...)
{
	//콘솔 내 커서위치 지정
	COORD cur;
	cur.X = x;
	cur.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cur);
	//"..."을 통해 들어온 변수들을 문자열로 처리하기 위한 방법
	va_list va_ptr;
	char msg[512] = { NULL, };
	va_start(va_ptr, text);
	vsprintf(msg, text, va_ptr);
	va_end(va_ptr);
	//색상지정
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	//그리기
	printf("%s", msg);
	//색상 원래대로 지정
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
}


//글자 색을 임의로 변경해줌

//0번부터 차례로 검정_파랑_초록_옥_빨강_자주_노랑_흰_회_연한파랑_연한초록_연한옥_연한자주_연한노랑_밝은흰(16진수로 0~F)
void textcolor(int color_number)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_number);
}