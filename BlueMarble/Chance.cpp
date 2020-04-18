#include "Scene.h"
#include "Chance.h"

/*
Draw(20,25, ~~, "~~"); 부터 텍스트 작성 !!
*/


// 찬스 획득 함수
void Chance(struct fields *field, struct PLAYER *who)
{
	struct PLAYER *a;
	struct PLAYER *b;
	struct PLAYER *c;
	struct PLAYER *d;

	a = &user;
	b = &com1;
	c = &com2;
	d = &com3;

	int chance;
	chance = rand() % 4 + 1; // 1~4

	Draw(14, 7, YELLOW,  "▨▤▤▤▤▤▤▤▤▤▤▤▧");
	Draw(14, 8, YELLOW,  "▥　　　　　　　　　　　▥");
	Draw(14, 9, YELLOW,  "▥　　　　　　　　　　　▥");
	Draw(14, 10, YELLOW, "▥　　　　　　　　　　　▥");
	Draw(14, 11, YELLOW, "▥　　　　　　　　　　　▥");
	Draw(14, 12, YELLOW, "▥　　　　　　　　　　　▥");
	Draw(14, 13, YELLOW, "▥　　　　　　　　　　　▥");
	Draw(14, 14, YELLOW, "▥　　　　　　　　　　　▥");
	Draw(14, 15, YELLOW, "▥　　　　　　　　　　　▥");
	Draw(14, 16, YELLOW, "▥　　　　　　　　　　　▥");
	Draw(14, 17, YELLOW, "▥　　　　　　　　　　　▥");
	Draw(14, 18, YELLOW, "▧▤▤▤▤▤▤▤▤▤▤▤▨");
	/****** 22칸 (한글로 11칸)  ******/
	switch (chance) {
	case 1:
		// TEXT 문구 출력 //
		Draw(18, 10, YELLOW, "<대회 입상>");

		Draw(18, 12, YELLOW, "세계 코딩대회에서");
		Draw(18, 13, YELLOW, "우승했다!");

		Draw(18, 15, YELLOW, "소지금 100억 증가");

		// 게임 내 반영 //
		who->money += 100;
		who->all_money += 100;

		erase_pos(field);
		// 소지금 변동 표기
		user_pos(field);
		break;
	case 2:
		// TEXT 문구 출력 //
		Draw(18, 10, YELLOW, "<지갑 분실>");

		Draw(18, 12, YELLOW, "지갑을 잃어버렸다.");

		Draw(18, 14, YELLOW, "소지금 100억 감소");

		// 게임 내 반영 //
		who->money -= 100;
		who->all_money -= 100;

		erase_pos(field);
		// 소지금 변동 표기
		user_pos(field);
		break;

	case 3:
		// TEXT 문구 출력 //
		Draw(18, 9, YELLOW, "< 기부 천사 >");

		Draw(18, 11, YELLOW, "모든 사람에게 기부");
		Draw(18, 12, YELLOW, "를 하기로 했다.");

		Draw(18, 14, YELLOW, "소지금 300억 감소");
		Draw(18, 15, YELLOW, "타 유저는 100억씩");
		Draw(18, 16, YELLOW, "증가");

		// 게임 내 반영 //
		who->money -= 300;
		who->all_money -= 300;

		if (who->who != a->who) {
			a->money += 100;
			a->all_money += 100;
		}
		if (who->who != b->who) {
			b->money += 100;
			b->all_money += 100;
		}
		if (who->who != c->who) {
			c->money += 100;
			c->all_money += 100;
		}
		if (who->who != d->who) {
			d->money += 100;
			d->all_money += 100;
		}

		erase_pos(field);
		// 소지금 변동 표기
		user_pos(field);
		break;
	case 4:
		// TEXT 문구 출력 //
		Draw(18, 11, YELLOW, "<괴한에게 납치>");

		Draw(18, 13, YELLOW, "어딘가로 끌려갔다.");

		Draw(18, 15, YELLOW, "울릉도로 이동");

		// TIME초 딜레이 //
		Timer(TIME);

		// 게임 내 반영 //
		pSystem->playSound(FMOD_CHANNEL_REUSE, pSound[Oops], false, &pChannel[1]); // 허무 효과음
		field[who->where].on--; // 기존 땅에서 유저를 빼냄
		who->where = 9;
		field[who->where].on++; // 울릉도에 유저 추가
		erase_pos(field);
		// 소지금 변동 표기
		user_pos(field); // 이동한 좌표 출력
		jail_count[who->who] = 3; // 체류 시작
		break;
	}
}