#include "Scene.h"
#include "Set_User.h"
#include <string.h>

//char get_name_safe;


void Set_User(struct PLAYER *a, struct PLAYER *b, struct PLAYER *c, struct PLAYER *d)
{
	system("cls");
	Draw(38, 6, WHITE, "■■■■■■■■■■■■");
	Draw(42, 7, WHITE, "이름을 입력하시오");
	Draw(38, 10, WHITE, "■■■■■■■■■■■■");
	Draw(44, 11, RED, "최대 4글자");

	Draw(47, 9, WHITE, "");
	textcolor(7);
	for (int i = 0; i < 10; i++)
		a->name[i] = NULL;
	scanf("%s", a->name);
	a->name[9] = NULL;

	pSystem->playSound(FMOD_CHANNEL_REUSE, pSound[Enter], false, &pChannel[1]); // 엔터효과음

	a->money = 1500;
	a->all_money = 1500;
	a->who = 1; // 1번 플레이어
	a->color = RED;

	strcpy(b->name, "AI_1");
	b->money = 1500;
	b->all_money = 1500;
	b->who = 2; // 2번 플레이어
	b->color = BLUE;

	strcpy(c->name, "AI_2");
	c->money = 1500;
	c->all_money = 1500;
	c->who = 3; // 3번 플레이어
	c->color = SKYBLUE;

	strcpy(d->name, "AI_3");
	d->money =1500;
	d->all_money = 1500;
	d->who = 4; // 4번 플레이어
	d->color = GREEN;
}