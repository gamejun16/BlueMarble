#include "Draw.h"

void Draw(int x, int y, int color, char *text, ...)
{
	//�ܼ� �� Ŀ����ġ ����
	COORD cur;
	cur.X = x;
	cur.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cur);
	//"..."�� ���� ���� �������� ���ڿ��� ó���ϱ� ���� ���
	va_list va_ptr;
	char msg[512] = { NULL, };
	va_start(va_ptr, text);
	vsprintf(msg, text, va_ptr);
	va_end(va_ptr);
	//��������
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	//�׸���
	printf("%s", msg);
	//���� ������� ����
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
}


//���� ���� ���Ƿ� ��������

//0������ ���ʷ� ����_�Ķ�_�ʷ�_��_����_����_���_��_ȸ_�����Ķ�_�����ʷ�_���ѿ�_��������_���ѳ��_������(16������ 0~F)
void textcolor(int color_number)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_number);
}