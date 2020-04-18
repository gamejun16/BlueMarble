#include "Scene.h"
#include "Set_User.h"

struct fields field[36]; // ��
struct PLAYER user, com1, com2, com3;


char username[10];

int TURN = 1; // ����
int dice1, dice2; // �ֻ���
int jail_count[5]; // ���� ( == �︪�� ). 1~4���÷��̾� �ε��� �� = ���� 1~4. 0�ε����� ��� x

bool Sn_Inform = false; //�ش� �Լ� ȣ��� �Լ�


//bool GameOver = true; // false�� �Ǹ� ���� ����

//�������(Scene Example) �ʱ�ȭ �Լ�
void Scene_Ingame_Init()
{	

	////////////�����غ�///////////
	//�������� �Է�
	Set_User(&user, &com1, &com2, &com3);


	//�� ���� ȣ��
	//Set_Area(field);

	//�ε�â
	loading();



	//�ʵ带 �׷���
	DrawField(field, &user, &com1, &com2, &com3);
	
	inform_choice = 4; // inform�� ������
	Sn_Inform = false; // inform�� ��¿���

	//�������� ���� ��ġ
	user.where = 0;
	com1.where = 0;
	com2.where = 0;
	com3.where = 0;

	// ���� ��
	user.around = 0;
	com1.around = 0;
	com2.around = 0;
	com3.around = 0;

	// ���� ī��Ʈ
	jail_count[1] = 0;
	jail_count[2] = 0;
	jail_count[3] = 0;
	jail_count[4] = 0;

	field[0].on = 4; // ù ���۽� 4���� �ö� ����

	TURN = 1; // ����. 1 ~ 4

	user_pos(field);

}

//�������(Scene Example) ������ �Լ�
bool Scene_Ingame_Render(float timeDelta)
{

	/*
	//���� �� ��� �Լ�
	if (KeyDown(KEY_SPACE))
		if(Sn_Inform == false) Sn_Inform = true;
	if (Sn_Inform) Scene_Inform(); // Sn_Inform �� true��� �ش� �� ���
	*/

	//////////////////////���ӽ���/////////////////////////////

	bool choose = true;

	//************1�� �÷��̾�********************************

	if (TURN == 1) {
		TURN = 2;
		
		Draw(46, 13, WHITE, "���͸� ����");
		Draw(46, 14, WHITE, "�ֻ����� �����ʽÿ�");
		Draw(46, 15, WHITE, "# - �ɼ�");
		Draw(46, 16, WHITE, ""); textcolor(8); printf("; - �����ڸ��");

		while (1) {
			char Cc = NULL;
			Cc = _getch();
			if (Cc == KEY_ENTER) break; // �ֻ�������. �����Է��� �Ѿ
			else if (Cc == '#') { // �ɼ�â ȣ��
				TURN = 1; // ������ �ٽ� �ڽ��� ���� �����ϰ� ��
				Scene_Ingame_Option_Init();
				SceneNumber = INGAME_OPTION;
				Cc = NULL;

				Draw(46, 13, WHITE, "������������");
				Draw(46, 14, WHITE, "��������������������"); // test_ver
				Draw(46, 15, WHITE, "��������");
				Draw(46, 16, WHITE, "��������������");
				return true; // ingame_render�� ����. -> Ingame_Option_Render �� �Ѿ
			}
			else if (Cc == ';') { // ��Ȱ�� �߰�, ���� ��ǥ�� ���� �� ���� ����
				//TURN = 1; // ������ �ٽ� �ڽ��� ���� �����ϰ� ��
				user.around = 4; com1.around = 1; com2.around = 2; com3.around = 3; // ������ ����

				user.money = 1500; user.all_money = 1500;
				com1.money = 0; com1.all_money = 0;
				com2.money = 0; com2.all_money = 0;
				com3.money = 0; com3.all_money = 0;

				/** �� ������ ���� **/
				for (int i = 1; i <= 35; (i + 1) % 3 == 0 ? i+=2 : i++) {
					user.where = i;
					field[user.where].anyhas =1; // user�� ������ �Ҵ�
					Check_Whose_Area(field, &user); // ��ǥ��

					user_pos(field); // �����ݺ���
				}
				user.where = 0;

			}
			Cc = NULL;
		}
		
		Draw(46, 13, WHITE, "������������");
		Draw(46, 14, WHITE, "��������������������"); // test_ver
		Draw(46, 15, WHITE, "��������");
		Draw(46, 16, WHITE, "��������������");

		dice1 = rand() % 6 + 1; dice2 = rand() % 6 + 1; // �ֻ��� �ΰ� ����
		//Draw(20, 24, WHITE, "%d %d", dice1, dice2);
		throw_dice(dice1, dice2);
		//������ ���� �ȳ����� �տ� �����
		Draw(16, 25, BG_RED, "��");
		Draw(16, 26, BG_RED, "��");
		Draw(16, 27, BG_RED, "��");
		
		//�÷���!


		// �︪���� ���� ���� //
		if (jail_count[1] != 0) { // jail_count�� 0�� �ƴ϶�� (�︪���� ü�����̶��)	
			Draw(20, 25, RED, "%s���� �︪���� ǥ�����Դϴ�..", user.name);

			Area_stat(field, &user);

			Timer(TIME); // Ÿ�̸�

			if (dice1 == dice2) { // �����̸�?
				jail_count[1] = 0; // �︪ ü�� ����
				Draw(20, 26, RED, "����! Ż�⿡ �����߽��ϴ�!");
				Timer(TIME);
				Draw(20, 25, RED, "����������������������������������������");
				Draw(20, 26, RED, "��������������������������");
				Game_Play(field, &user, &com1, &com2, &com3, 0); // �̵�
				//AI_Play(field, &com1, &user, &com2, &com3, 0); // text_ver
			}
			else { // ������ �ƴ϶��
				jail_count[1]--; // ü��Ƚ�� 1 ����
				jail_count[1] != 0 ? Draw(20, 26, RED, "�� %d�� �� �����˴ϴ� ��", jail_count[1]) : Draw(20, 26, RED, "�����Ǿ����ϴ�!");
				Timer(TIME);

				//erase_text(); // �˸���������
			}

			erase_text(); // �˸���������

		}


		else { // jail_count�� 0�̿��ٸ� (���� �÷���)
			Game_Play(field, &user, &com1, &com2, &com3, 0);
			//AI_Play(field, &com1, &user, &com2, &com3, 0); // test_ver
		}
	}
	
	if (Over_Check(&user, &com1, &com2, &com3)) // true��ȯ�� ���� ����
		return true;


	//*********2�� �÷��̾� ( ai )********************************
	
	if (TURN == 2) {
		TURN = 3;
		dice1 = rand() % 6 + 1; dice2 = rand() % 6 + 1; // �ֻ��� �ΰ� ����
		//Draw(20, 24, WHITE, "%d %d", dice1, dice2);
		throw_dice(dice1, dice2);

		//������ ���� �����
		Draw(16, 25, BG_BLUE, "��");
		Draw(16, 26, BG_BLUE, "��");
		Draw(16, 27, BG_BLUE, "��");

		// �︪���� ���� ���� //
		if (jail_count[2] != 0) { // jail_count�� 0�� �ƴ϶�� (�︪���� ü�����̶��)	
			Draw(20, 25, RED, "%s���� �︪���� ǥ�����Դϴ�..", com1.name);

			Area_stat(field, &com1);

			Timer(TIME); // Ÿ�̸�

			if (dice1 == dice2) { // �����̸�?
				jail_count[2] = 0; // �︪ ü�� ����
				Draw(20, 26, RED, "����! Ż�⿡ �����߽��ϴ�!");
				Timer(TIME);
				Draw(20, 25, RED, "����������������������������������������");
				Draw(20, 26, RED, "��������������������������");
				AI_Play(field, &user, &com1, &com2, &com3, 0); // �̵�
			}
			else { // ������ �ƴ϶��
				jail_count[2]--; // ü��Ƚ�� 1 ����
				jail_count[2] != 0 ? Draw(20, 26, RED, "�� %d�� �� �����˴ϴ� ��", jail_count[2]) : Draw(20, 26, RED, "�����Ǿ����ϴ�!");
				Timer(TIME);
			}

			erase_text(); // �˸���������

		}
		else // jail_count�� 0�̿��ٸ� (���� �÷���)
			AI_Play(field, &user, &com1, &com2, &com3, 0);
		
	}
	
	if (Over_Check(&user, &com1, &com2, &com3)) // true��ȯ�� ���� ����
		return true;

	//***************3�� �÷��̾� ( ai )********************************

	if (TURN == 3) {
		TURN = 4;
		dice1 = rand() % 6 + 1; dice2 = rand() % 6 + 1; // �ֻ��� �ΰ� ����
		//Draw(20, 24, WHITE, "%d %d", dice1, dice2);
		throw_dice(dice1, dice2);

		//������ ���� �����
		Draw(16, 25, BG_SKYBLUE, "��");
		Draw(16, 26, BG_SKYBLUE, "��");
		Draw(16, 27, BG_SKYBLUE, "��");

		//�÷���!
		// �︪���� ���� ���� //
		if (jail_count[3] != 0) { // jail_count�� 0�� �ƴ϶�� (�︪���� ü�����̶��)	
			Draw(20, 25, RED, "%s���� �︪���� ǥ�����Դϴ�..", com2.name);

			Area_stat(field, &com2);

			Timer(TIME); // Ÿ�̸�

			if (dice1 == dice2) { // �����̸�?
				jail_count[3] = 0; // �︪ ü�� ����
				Draw(20, 26, RED, "����! Ż�⿡ �����߽��ϴ�!");
				Timer(TIME);
				Draw(20, 25, RED, "����������������������������������������");
				Draw(20, 26, RED, "��������������������������");
				AI_Play(field, &user, &com2, &com1, &com3, 0); // �̵�
			}
			else { // ������ �ƴ϶��
				jail_count[3]--; // ü��Ƚ�� 1 ����
				jail_count[3] != 0 ? Draw(20, 26, RED, "�� %d�� �� �����˴ϴ� ��", jail_count[3]) : Draw(20, 26, RED, "�����Ǿ����ϴ�!");
				Timer(TIME);
			}

			erase_text(); // �˸���������

		}
		else // jail_count�� 0�̿��ٸ� (���� �÷���)
			AI_Play(field, &user, &com2, &com1, &com3, 1);
	}

	if (Over_Check(&user, &com1, &com2, &com3)) // true��ȯ�� ���� ����
		return true;

	//***************4�� �÷��̾� ( ai )********************************

	if (TURN == 4) {
		TURN = 1;
		dice1 = rand() % 6 + 1; dice2 = rand() % 6 + 1; // �ֻ��� �ΰ� ����
		//Draw(20, 24, WHITE, "%d %d", dice1, dice2);
		throw_dice(dice1, dice2);

		//������ ���� �����
		Draw(16, 25, BG_GREEN, "��");
		Draw(16, 26, BG_GREEN, "��");
		Draw(16, 27, BG_GREEN, "��");

		//�÷���!
		// �︪���� ���� ���� //
		if (jail_count[4] != 0) { // jail_count�� 0�� �ƴ϶�� (�︪���� ü�����̶��)	
			Draw(20, 25, RED, "%s���� �︪���� ǥ�����Դϴ�..", com3.name);

			Area_stat(field, &com3);

			Timer(TIME); // Ÿ�̸�

			if (dice1 == dice2) { // �����̸�?
				jail_count[4] = 0; // �︪ ü�� ����
				Draw(20, 26, RED, "����! Ż�⿡ �����߽��ϴ�!");
				Timer(TIME);
				Draw(20, 25, RED, "����������������������������������������");
				Draw(20, 26, RED, "��������������������������");
				AI_Play(field, &user, &com3, &com1, &com2, 0); // �̵�
			}
			else { // ������ �ƴ϶��
				jail_count[4]--; // ü��Ƚ�� 1 ����
				jail_count[4] != 0 ? Draw(20, 26, RED, "�� %d�� �� �����˴ϴ� ��", jail_count[4]) : Draw(20, 26, RED, "�����Ǿ����ϴ�!");
				Timer(TIME);
			}

			erase_text(); // �˸���������
		}
		else // jail_count�� 0�̿��ٸ� (���� �÷���)
			AI_Play(field, &user, &com3, &com1, &com2, 0);
	}

	if (Over_Check(&user, &com1, &com2, &com3)) // true��ȯ�� ���� ����
		return true;

	END:

	return true;
}


