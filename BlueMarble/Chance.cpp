#include "Scene.h"
#include "Chance.h"

/*
Draw(20,25, ~~, "~~"); ���� �ؽ�Ʈ �ۼ� !!
*/


// ���� ȹ�� �Լ�
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

	Draw(14, 7, YELLOW,  "�ɢǢǢǢǢǢǢǢǢǢǢǢ�");
	Draw(14, 8, YELLOW,  "�ȡ�����������������������");
	Draw(14, 9, YELLOW,  "�ȡ�����������������������");
	Draw(14, 10, YELLOW, "�ȡ�����������������������");
	Draw(14, 11, YELLOW, "�ȡ�����������������������");
	Draw(14, 12, YELLOW, "�ȡ�����������������������");
	Draw(14, 13, YELLOW, "�ȡ�����������������������");
	Draw(14, 14, YELLOW, "�ȡ�����������������������");
	Draw(14, 15, YELLOW, "�ȡ�����������������������");
	Draw(14, 16, YELLOW, "�ȡ�����������������������");
	Draw(14, 17, YELLOW, "�ȡ�����������������������");
	Draw(14, 18, YELLOW, "�ʢǢǢǢǢǢǢǢǢǢǢǢ�");
	/****** 22ĭ (�ѱ۷� 11ĭ)  ******/
	switch (chance) {
	case 1:
		// TEXT ���� ��� //
		Draw(18, 10, YELLOW, "<��ȸ �Ի�>");

		Draw(18, 12, YELLOW, "���� �ڵ���ȸ����");
		Draw(18, 13, YELLOW, "����ߴ�!");

		Draw(18, 15, YELLOW, "������ 100�� ����");

		// ���� �� �ݿ� //
		who->money += 100;
		who->all_money += 100;

		erase_pos(field);
		// ������ ���� ǥ��
		user_pos(field);
		break;
	case 2:
		// TEXT ���� ��� //
		Draw(18, 10, YELLOW, "<���� �н�>");

		Draw(18, 12, YELLOW, "������ �Ҿ���ȴ�.");

		Draw(18, 14, YELLOW, "������ 100�� ����");

		// ���� �� �ݿ� //
		who->money -= 100;
		who->all_money -= 100;

		erase_pos(field);
		// ������ ���� ǥ��
		user_pos(field);
		break;

	case 3:
		// TEXT ���� ��� //
		Draw(18, 9, YELLOW, "< ��� õ�� >");

		Draw(18, 11, YELLOW, "��� ������� ���");
		Draw(18, 12, YELLOW, "�� �ϱ�� �ߴ�.");

		Draw(18, 14, YELLOW, "������ 300�� ����");
		Draw(18, 15, YELLOW, "Ÿ ������ 100�﾿");
		Draw(18, 16, YELLOW, "����");

		// ���� �� �ݿ� //
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
		// ������ ���� ǥ��
		user_pos(field);
		break;
	case 4:
		// TEXT ���� ��� //
		Draw(18, 11, YELLOW, "<���ѿ��� ��ġ>");

		Draw(18, 13, YELLOW, "��򰡷� ��������.");

		Draw(18, 15, YELLOW, "�︪���� �̵�");

		// TIME�� ������ //
		Timer(TIME);

		// ���� �� �ݿ� //
		pSystem->playSound(FMOD_CHANNEL_REUSE, pSound[Oops], false, &pChannel[1]); // �㹫 ȿ����
		field[who->where].on--; // ���� ������ ������ ����
		who->where = 9;
		field[who->where].on++; // �︪���� ���� �߰�
		erase_pos(field);
		// ������ ���� ǥ��
		user_pos(field); // �̵��� ��ǥ ���
		jail_count[who->who] = 3; // ü�� ����
		break;
	}
}