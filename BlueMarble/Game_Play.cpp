#include "Scene.h"
#include "Game_Play.h"


/*************************************************************

< �� .cpp�� ���� �� �Լ� ��� >

void Timer(float) -> Ÿ�̸� �Լ�
void Game_Play(field, user, com1, com2, com3, option) -> ������ �÷���. user�� ��ü
void AI_Play(field, user, com1, com2, com3, option) -> Ai�� �÷���. com1�� ��ü

****************************************************************/


const float TIME = 3.0;

bool choose = true;


void Timer(float t_1) {
	float t_2 = clock()*0.001; // Ÿ�̸� ȣ��� �ð�
	float t_3;
	while(1){
		t_3 = clock()*0.001 - t_2;
		if (t_3 > t_1)
			break;
	}
}


////////////**   user�� ������ ��ü!!   **/////////////
void Game_Play(struct fields *field, struct PLAYER *user, struct PLAYER *com1, struct PLAYER *com2, struct PLAYER *com3, int option)
{
	move_pos(field, user); // ���� �ű�

		// �ش� ��ġ ���� ������ ������
	Area_stat(field, user);

	//�� �Ǻ�
	if (field[user->where].anyhas >= 0 && field[user->where].anyhas <= 4) { // 0=�ƹ��� ����x, 1~4 = �ش� �÷��̾��� ��
		if (field[user->where].anyhas == 0 && user->money - field[user->where].area_pay >= 0) { // �ƹ��� �����ϰ� ���� �ʰ� �ܾ��� ���´ٸ�
			InputLateUpdate(); // ���͹��� �ʱ�ȭ

			Draw(20, 25, WHITE, "%s�� �����Ͻðڽ��ϱ�?", field[user->where].region_name);
			Draw(20, 26, WHITE, "��"); Draw(30, 26, WHITE, "�ƴϿ�");

			while (1) {
				InputUpdate(); // �Է��� ����
				if (KeyDown(KEY_RIGHT) || KeyDown(KEY_LEFT)) {
					if (choose == true) {
						Draw(17, 26, WHITE, "��");
						choose = false;
					}
					else if (choose == false) {
						Draw(27, 26, WHITE, "��");
						choose = true;
					}
				}
				else if (KeyDown(KEY_ENTER)) break;

				if (choose == true)
					Draw(17, 26, WHITE, "��");
				else if (choose == false)
					Draw(27, 26, WHITE, "��");
				InputLateUpdate();
			}

			if (choose == true) {
				pSystem->playSound(FMOD_CHANNEL_REUSE, pSound[Money], false, &pChannel[1]); // ���Ҹ�

				user->money -= field[user->where].area_pay; // ������ ����
				//user->all_money += field[user->where].area_pay; // �� �ڻ� ���� X
				field[user->where].anyhas = user->who; // ������ get
													 // DrawField(field, &user, &com1, &com2, &com3); // �� �ٽ� �׸�. �� �Լ� ���� -> �� �ѱ�
				erase_pos(field);
				user_pos(field); // ���ݺ����� �׷���
				Check_Whose_Area(field, user); // ������ ������ ���� ǥ��

				Draw(20, 27, WHITE, "%s���� %s�� �����ϼ̽��ϴ�.", user->name, field[user->where].region_name);
			}
		}
		//���ε� �ܾ��� �����ϴٸ�
		else if (field[user->where].anyhas == 0 && user->money - field[user->where].area_pay < 0) {
			Draw(20, 25, WHITE, "�������� ������ %s��", field[user->where].region_name);
			Draw(20, 26, WHITE, "������ �� �����ϴ�!");
		}

		else if (field[user->where].anyhas == user->who) { // ���ζ�

			Draw(20, 25, WHITE, "%s���� �ڽ��Ƕ��� �����߽��ϴ�.", user->name);
			int choose_2 = 1;

			/********** ���׷��̵� �� ***********/

			//���׷��̵� ����:
			//���� �ʵ� ��ü�� �� ������ �� Ƚ���� n���� �ξ��� ��
			//�ִ� +n���� ���׷��̵� ����

			if (user->money - field[user->where].upgrade_pay >= 0) { // ���׷��̵� �� �ܾ��� �ִٸ�
				while (field[user->where].upgrade_data < user->around && field[user->where].upgrade_data < 4) {
					Draw(20, 26, WHITE, "���� +%d �Դϴ�.", field[user->where].upgrade_data);
					Draw(20, 27, WHITE, "������ ����ðڽ��ϱ�?");
					Draw(23, 28, WHITE, "YES��������NO");
					if (choose_2 == 1) {
						Draw(20, 28, WHITE, "��");
						Draw(31, 28, WHITE, "��");
					}
					else if (choose_2 == 2) {
						Draw(20, 28, WHITE, "��");
						Draw(31, 28, WHITE, "��");
					}

					InputUpdate(); // Ű�Է� ����

					if (KeyDown(KEY_RIGHT) || KeyDown(KEY_LEFT)) {
						if (choose_2 == 1) choose_2 = 2;
						else if (choose_2 == 2) choose_2 = 1;
						InputLateUpdate();
						continue;
					}
					else if (KeyDown(KEY_ENTER)) {
						if (choose_2 == 1) { // ��ȭ�� �ϰڴٸ�
							pSystem->playSound(FMOD_CHANNEL_REUSE, pSound[Money], false, &pChannel[1]); // �� ȿ����

											 //////////////// ���׷��̵� ���� �������� ���� ////////////////
											 //���׷��̵� ���
							int PAY = field[user->where].area_pay / 6;

							user->money -= PAY; // n ���׷��̵带 ���Ѵٸ�. �ش� ��븸ŭ ����
							// user->all_money += PAY; // ���ڻ� ���� X
							field[user->where].upgrade_data++; // �ش� �� ���׷��̵� ���� ����

							erase_pos(field);
							user_pos(field); // ���ݺ����� �׷���

							Check_Whose_Area(field, user); // ������ ������ ��(���׷��̵� ����)�� ǥ��

							Draw(20, 26, WHITE, "���� +%d �Դϴ�!", field[user->where].upgrade_data);

							if (user->money - field[user->where].upgrade_pay < 0) { // ���׷��̵� �� �ܾ��� ���ٸ�
								Draw(20, 27, WHITE, "�ܾ��� ������ ���׷��̵带 �����մϴ�.");
								break;
							}

							Draw(20, 29, WHITE, "�ִ� %d���� ���׷��̵尡 �����մϴ�.", user->around < 4 ? user->around : 4);
							InputLateUpdate();
							continue;
						}
						else if (choose_2 == 2) { // ��ȭ�� �׸��ϰڴٸ�
							Draw(20, 29, WHITE, "��������������������������������������");
							Draw(20, 29, WHITE, "���׷��̵带 �����մϴ�!");
							break;
						}
					}
				}
			}
			else { // ���׷��̵� �� �ܾ��� ���ٸ�
				Draw(20, 26, WHITE, "���� +%d �Դϴ�.", field[user->where].upgrade_data);
			}
			InputLateUpdate();

			/************************UPGRADEUPGRADEUPGRADE***********************/

			/************************UPGRADEUPGRADEUPGRADE***********************/

		}
		else if (field[user->where].anyhas == com1->who) { // com1(Ÿ �÷��̾�) ��
			Draw(20, 25, WHITE, "%s���� %s���� ���� �����߽��ϴ�.", user->name, com1->name);

			//���׷��̵� ���¿� ���� ����� ����
			unsigned int PAY;
			switch (field[user->where].upgrade_data) {
			case 0:
				PAY = field[user->where].area_pay / 5;
				break;
			case 1:
				PAY = field[user->where].area_pay / 2;
				break;
			case 2:
				PAY = field[user->where].area_pay *1.5;
				break;
			case 3:
				PAY = field[user->where].area_pay * 2;
				break;
			case 4:
				PAY = field[user->where].area_pay * 4;
				break;
			}
			pSystem->playSound(FMOD_CHANNEL_REUSE, pSound[Money], false, &pChannel[1]); // �� ȿ����
			user->money -= PAY; user->all_money -= PAY;
			com1->money += PAY; com1->all_money += PAY;
			Draw(20, 26, WHITE, "������ %d����� �����մϴ�.", PAY);
			erase_pos(field);

			user_pos(field); // ���ݺ����� �׷���
			Timer(TIME);

			if (Over_Check(user, com1, com2, com3)) // ���� ����. �ڲ��μ��� �ϴ� ���װ� �־ �̸� ���ӿ��� üũ.
				goto END;

			//////////////�μ�//////////////
			/*
			for (int i = 24; i < 33; i++)
			Draw(17, i, WHITE, "������������������������������������������������");
			*/
			if (user->money - PAY > 0) { // �μ��� ��ŭ�� ���� �����ִٸ�
				Draw(20, 27, WHITE, "%s�� �μ��Ͻðڽ��ϱ�?", field[user->where].region_name);
				// �μ���� = (���� + ���׷��̵� ���) * 2
				PAY = (field[user->where].area_pay + (field[user->where].upgrade_data*field[user->where].upgrade_pay)) * 2;

				Draw(20, 28, WHITE, "�μ� ����� %d��� �Դϴ�.", PAY);
				Draw(20, 29, WHITE, "��"); Draw(30, 29, WHITE, "�ƴϿ�");

				while (1) {
					InputUpdate();

					if (KeyDown(KEY_RIGHT) || KeyDown(KEY_LEFT)) {
						if (choose == true) {
							Draw(17, 29, WHITE, "��");
							choose = false;
						}
						else if (choose == false) {
							Draw(27, 29, WHITE, "��");
							choose = true;
						}
					}
					else if (KeyDown(KEY_ENTER)) {
						Draw(17, 29, WHITE, "��"); Draw(27, 29, WHITE, "��");
						break;
					}
					if (choose == true)
						Draw(17, 29, WHITE, "��");
					else if (choose == false)
						Draw(27, 29, WHITE, "��");
					InputLateUpdate();
				}

				if (choose == true && user->money - PAY >= 0) { // �μ��� �ϰڴٸ� ( �ݾ��� -�� ���� ���� �� )
					pSystem->playSound(FMOD_CHANNEL_REUSE, pSound[Money], false, &pChannel[1]); // �� ȿ����
					field[user->where].anyhas = user->who; // ������ �絵
					user->money -= PAY;
					// user->all_money += PAY; // �� �ڻ� ���� X
					com1->money += PAY;
					// com1->all_money -= PAY; // �� �ڻ� ���� X

					Draw(20, 30, WHITE, "%s���� %s�� �μ��ϼ̽��ϴ�.", user->name, field[user->where].region_name);
					erase_pos(field);
					user_pos(field); // ���ݺ����� �׷���
					Check_Whose_Area(field, user); // ������ ������ ���� ǥ��
				}
				else if (choose == true && user->money - PAY < 0) {
					Draw(20, 30, WHITE, "�������� �����մϴ�!");
				}
			}

			else if (field[user->where].anyhas == com2->who) { // com2�� ��
				Draw(20, 25, WHITE, "%s���� %s���� ���� �����߽��ϴ�.", user->name, com2->name);

				//���׷��̵� ���¿� ���� ����� ����
				unsigned int PAY;
				switch (field[user->where].upgrade_data) {
				case 0:
					PAY = field[user->where].area_pay / 5;
					break;
				case 1:
					PAY = field[user->where].area_pay / 2;
					break;
				case 2:
					PAY = field[user->where].area_pay *1.5;
					break;
				case 3:
					PAY = field[user->where].area_pay * 2;
					break;
				case 4:
					PAY = field[user->where].area_pay * 4;
					break;
				}
				// ����� ���� //
				pSystem->playSound(FMOD_CHANNEL_REUSE, pSound[Money], false, &pChannel[1]); // �� ȿ����
				user->money -= PAY; user->all_money -= PAY;
				com2->money += PAY; com2->all_money += PAY;
				Draw(20, 26, WHITE, "������ %d����� �����մϴ�.", PAY);
				erase_pos(field);
				user_pos(field); // ���ݺ����� �׷���
				Timer(TIME);

				if (Over_Check(user, com1, com2, com3)) // ���� ����. �ڲ��μ��� �ϴ� ���װ� �־ �̸� ���ӿ��� üũ.
					goto END;

				//////////////�μ�//////////////
				/*
				for (int i = 24; i < 33; i++)
				Draw(17, i, WHITE, "������������������������������������������������");
				*/
				if (user->money - PAY > 0) { // �μ��� ��ŭ�� ���� �����ִٸ�

					Draw(20, 27, WHITE, "%s�� �μ��Ͻðڽ��ϱ�?", field[user->where].region_name);
					// �μ���� = (���� + ���׷��̵� ���) * 2
					PAY = (field[user->where].area_pay + (field[user->where].upgrade_data*field[user->where].upgrade_pay)) * 2;
					Draw(20, 28, WHITE, "�μ� ����� %d��� �Դϴ�.", PAY);
					Draw(20, 29, WHITE, "��"); Draw(30, 29, WHITE, "�ƴϿ�");

					while (1) {
						InputUpdate();

						if (KeyDown(KEY_RIGHT) || KeyDown(KEY_LEFT)) {
							if (choose == true) {
								Draw(17, 29, WHITE, "��");
								choose = false;
							}
							else if (choose == false) {
								Draw(27, 29, WHITE, "��");
								choose = true;
							}
						}
						else if (KeyDown(KEY_ENTER)) {
							Draw(17, 29, WHITE, "��"); Draw(27, 29, WHITE, "��");
							break;
						}
						if (choose == true)
							Draw(17, 29, WHITE, "��");
						else if (choose == false)
							Draw(27, 29, WHITE, "��");
						InputLateUpdate();
					}
					if (choose == true && user->money - PAY >= 0) { // �μ��� �ϰڴٸ� ( �ݾ��� -�� ���� ���� �� )
						pSystem->playSound(FMOD_CHANNEL_REUSE, pSound[Money], false, &pChannel[1]); // �� ȿ����
						field[user->where].anyhas = user->who;
						user->money -= PAY;
						// user->all_money += PAY; // �� �ڻ� ���� X
						com2->money += PAY;
						// com2->all_money -= PAY; // �� �ڻ� ���� X

						Draw(20, 30, WHITE, "%s���� %s�� �μ��ϼ̽��ϴ�.", user->name, field[user->where].region_name);
						erase_pos(field);
						user_pos(field); // ���ݺ����� �׷���
						Check_Whose_Area(field, user); // ������ ������ ���� ǥ��
					}
					else if (choose == true && user->money - PAY < 0) {
						Draw(20, 30, WHITE, "�������� �����մϴ�!");
					}
				}
			}
			else if (field[user->where].anyhas == com3->who) { // com3(Ÿ �÷��̾�) ��
				Draw(20, 25, WHITE, "%s���� %s���� ���� �����߽��ϴ�.", user->name, com3->name);

				//���׷��̵� ���¿� ���� ����� ����
				unsigned int PAY;
				switch (field[user->where].upgrade_data) {
				case 0:
					PAY = field[user->where].area_pay / 5;
					break;
				case 1:
					PAY = field[user->where].area_pay / 2;
					break;
				case 2:
					PAY = field[user->where].area_pay *1.5;
					break;
				case 3:
					PAY = field[user->where].area_pay * 2;
					break;
				case 4:
					PAY = field[user->where].area_pay * 4;
					break;
				}
				// ����� ���� //
				pSystem->playSound(FMOD_CHANNEL_REUSE, pSound[Money], false, &pChannel[1]); // �� ȿ����
				user->money -= PAY; user->all_money -= PAY;
				com3->money += PAY; com3->all_money += PAY;
				Draw(20, 26, WHITE, "������ %d����� �����մϴ�.", PAY);
				erase_pos(field);

				user_pos(field); // ���ݺ����� �׷���
				Timer(TIME);

				if (Over_Check(user, com1, com2, com3)) // ���� ����. �ڲ��μ��� �ϴ� ���װ� �־ �̸� ���ӿ��� üũ.
					goto END;

				//////////////�μ�//////////////
				/*
				for (int i = 24; i < 33; i++)
				Draw(17, i, WHITE, "������������������������������������������������");
				*/
				if (user->money - PAY > 0) { // �μ��� ��ŭ�� ���� �����ִٸ�
					Draw(20, 27, WHITE, "%s�� �μ��Ͻðڽ��ϱ�?", field[user->where].region_name);
					// �μ���� = (���� + ���׷��̵� ���) * 2
					PAY = (field[user->where].area_pay + (field[user->where].upgrade_data*field[user->where].upgrade_pay)) * 2;
					Draw(20, 28, WHITE, "�μ� ����� %d��� �Դϴ�.", PAY);
					Draw(20, 29, WHITE, "��"); Draw(30, 29, WHITE, "�ƴϿ�");

					while (1) {
						InputUpdate();

						if (KeyDown(KEY_RIGHT) || KeyDown(KEY_LEFT)) {
							if (choose == true) {
								Draw(17, 29, WHITE, "��");
								choose = false;
							}
							else if (choose == false) {
								Draw(27, 29, WHITE, "��");
								choose = true;
							}
						}
						else if (KeyDown(KEY_ENTER)) {
							Draw(17, 29, WHITE, "��"); Draw(27, 29, WHITE, "��");
							break;
						}
						if (choose == true)
							Draw(17, 29, WHITE, "��");
						else if (choose == false)
							Draw(27, 29, WHITE, "��");
						InputLateUpdate();
					}

					if (choose == true && user->money - PAY >= 0) { // �μ��� �ϰڴٸ� ( �ݾ��� -�� ���� ���� �� )
						pSystem->playSound(FMOD_CHANNEL_REUSE, pSound[Money], false, &pChannel[1]); // �� ȿ����
						field[user->where].anyhas = user->who;
						user->money -= PAY;
						// user->all_money += PAY; // �� �ڻ� ���� X
						com3->money += PAY;
						// com3->all_money -= PAY; // �� �ڻ� ���� X

						Draw(20, 30, WHITE, "%s���� %s�� �μ��ϼ̽��ϴ�.", user->name, field[user->where].region_name);
						erase_pos(field);
						user_pos(field); // ���ݺ����� �׷���
						Check_Whose_Area(field, user); // ������ ������ ���� ǥ��
					}
					else if (choose == true && user->money - PAY < 0) {
						Draw(20, 30, WHITE, "�������� �����մϴ�!");
					}
				}
			}
		}
	}
	else if (field[user->where].anyhas == 5)
		Draw(20, 25, WHITE, "%s���� ���������� �����߽��ϴ�.", user->name);

	else if (field[user->where].anyhas == 6) {
		pSystem->playSound(FMOD_CHANNEL_REUSE, pSound[Oops], false, &pChannel[1]); // �㹫 ȿ����
		Draw(20, 25, WHITE, "%s���� �︪���� ǥ���Ǿ����ϴ�.", user->name);
		jail_count[user->who] = 3;
	}
	else if (field[user->where].anyhas == 7) {
		Draw(20, 25, WHITE, "%s���� ������������ �̵��մϴ�.", user->name);
		Timer(TIME); // TIME�� ������ �� ������������ �̵����� ������
		field[user->where].on--; // ���� ������ ������ ����
		user->where = 0;
		user->around++; // �� ���� �� ������ ���
		field[user->where].on++; // ���������� ���� �߰�
		erase_pos(field);
		user_pos(field); // �̵��� ��� ���
	}
	else if (field[user->where].anyhas == 8) {
		Draw(20, 25, WHITE, "%s���� �︪���� �̵��մϴ�.", user->name);
		Timer(TIME); // TIME�� ������ �� �︪���� �̵����� ������
		field[user->where].on--; // ���� ������ ������ ����
		user->where = 9;
		field[user->where].on++; // �︪���� ���� �߰�
		pSystem->playSound(FMOD_CHANNEL_REUSE, pSound[Oops], false, &pChannel[1]); // �㹫 ȿ����
		erase_pos(field);
		user_pos(field); // �̵��� ��� ���
		jail_count[user->who] = 3; // ü������
	}

	else if (field[user->where].anyhas == 9) {
		Draw(20, 25, WHITE, "%s���� ������ ȹ���ϼ̽��ϴ�.", user->name);

		Chance(field, user); // �����Լ� ȣ��
	}

END:

	Timer(TIME);


	erase_text(); // �˸���������

	InputLateUpdate();


}


////////////**   com1�� ������ ��ü!!   **/////////////
void AI_Play(struct fields *field, struct PLAYER *user, struct PLAYER *com1, struct PLAYER *com2, struct PLAYER *com3, int option)
{
	//��ĭ�� �̵���Ŵ
	move_pos(field, com1);

	//�ش� ���� ������ ���
	Area_stat(field, com1);

	//�� �Ǻ�
	if (field[com1->where].anyhas >= 0 && field[com1->where].anyhas <= 4) { // 0=�ƹ��� ����x, 1~4 = �ش� �÷��̾��� ��
		if (field[com1->where].anyhas == 0) { // �ƹ��� �����ϰ� ���� �ʴٸ�
											 // �ڻ��� ���´ٸ� �ٷ� �����ϵ��� ����
			if (com1->money - field[com1->where].area_pay >= 0){
				pSystem->playSound(FMOD_CHANNEL_REUSE, pSound[Money], false, &pChannel[1]); // �� ȿ����
				com1->money -= field[com1->where].area_pay; // ������ ����
				// com1->all_money += field[com1->where].area_pay; // �� �ڻ� ���� X
				field[com1->where].anyhas = com1->who; // ������ get
													 // DrawField(field, &user, &com1, &com2, &com3); // �� �ٽ� �׸�. �� �Լ� ���� -> �� �ѱ�
				erase_pos(field);
				user_pos(field); // ���ݺ����� �׷���
				Check_Whose_Area(field, com1); // com1�� ������ ���� ǥ��

				Draw(20, 25, WHITE, "%s���� %s�� �����ϼ̽��ϴ�.", com1->name, field[com1->where].region_name);
			}
			else {
				Draw(20, 25, WHITE, "�������� ������ %s��", field[com1->where].region_name);
				Draw(20, 26, WHITE, "������ �� �����ϴ�!");
			}
		}

		// ���ζ��̶��
		else if (field[com1->where].anyhas == com1->who) {
			Draw(20, 25, WHITE, "%s���� �ڽ��Ƕ��� �����߽��ϴ�.", com1->name);

			while (field[com1->where].upgrade_data < com1->around && field[com1->where].upgrade_data < 4) {

				int PAY = field[com1->where].area_pay / 6;

				if (com1->money - PAY >= 0) { // ���� ������. ������ ��ȭ.

										  //////////////// ���׷��̵� ���� �������� ���� ////////////////
										  //���׷��̵� ���

					pSystem->playSound(FMOD_CHANNEL_REUSE, pSound[Money], false, &pChannel[1]); // �� ȿ����
					com1->money -= PAY; // n ���׷��̵带 ���Ѵٸ�. �ش� ��븸ŭ ����
					// com1->all_money += PAY; // ���ڻ� ���� X
					field[com1->where].upgrade_data++; // �ش� �� ���׷��̵� ���� ����

					erase_pos(field);
					user_pos(field); // ���ݺ����� �׷���

					Check_Whose_Area(field, com1); // ������ ������ ��(���׷��̵� ����)�� ǥ��
					Draw(20, 26, WHITE, "+%d�� �Ǿ����ϴ�!", field[com1->where].upgrade_data);

					InputLateUpdate();
					continue;
				}
				else { // ���� ���ڶ��ٸ�.
					Draw(20, 26, WHITE, "���� +%d�Դϴ�.", field[com1->where].upgrade_data);
					break;
				}

			}
		}

		else if (field[com1->where].anyhas == user->who) { // user�Ƕ�
			Draw(20, 25, WHITE, "%s���� %s���� ���� �����߽��ϴ�.", com1->name, user->name);

			//���׷��̵� ���¿� ���� ����� ����
			unsigned int PAY;
			switch (field[com1->where].upgrade_data) {
			case 0:
				PAY = field[com1->where].area_pay / 5;
				break;
			case 1:
				PAY = field[com1->where].area_pay / 2;
				break;
			case 2:
				PAY = field[com1->where].area_pay *1.5;
				break;
			case 3:
				PAY = field[com1->where].area_pay * 2;
				break;
			case 4:
				PAY = field[com1->where].area_pay * 4;
				break;
			}

			pSystem->playSound(FMOD_CHANNEL_REUSE, pSound[Money], false, &pChannel[1]); // �� ȿ����
			com1->money -= PAY; com1->all_money -= PAY;
			user->money += PAY; user->all_money += PAY;
			Draw(20, 26, WHITE, "������ %d����� �����մϴ�.", PAY);
			erase_pos(field);
			user_pos(field); // ���ݺ����� �׷���
			Timer(TIME);

			
			if (Over_Check(user, com1, com2, com3)) // ���� ����. �ڲ��μ��� �ϴ� ���װ� �־ �̸� ���ӿ��� üũ.
				goto AI_END;
			
			//////////////�μ�//////////////
			// �μ���� = (���� + ���׷��̵� ���) * 2

			PAY = (field[com1->where].area_pay + (field[com1->where].upgrade_data*field[com1->where].upgrade_pay)) * 2;

			if (com1->money - PAY >= 0) { // �μ��� �ϰڴٸ�
				Draw(20, 27, WHITE, "%s���� %d����� �����ϰ�", com1->name, PAY);
				Draw(20, 28, WHITE, "%s�� �μ��մϴ�.", field[com1->where].region_name);
				pSystem->playSound(FMOD_CHANNEL_REUSE, pSound[Money], false, &pChannel[1]); // �� ȿ����
				field[com1->where].anyhas = com1->who;
				com1->money -= PAY;
				// com1->all_money += PAY; // �� �ڻ� ���� X
				user->money += PAY;
				// user->all_money -= PAY; // �� �ڻ� ���� X

				erase_pos(field);
				user_pos(field); // ���ݺ����� �׷���
				Check_Whose_Area(field, com1); // ������ ������ ���� ǥ��
			}


		}
		else if (field[com1->where].anyhas == com2->who) { // com2�� ��
			Draw(20, 25, WHITE, "%s���� %s���� ���� �����߽��ϴ�.", com1->name, com2->name);

			//���׷��̵� ���¿� ���� ����� ����
			unsigned int PAY;
			switch (field[com1->where].upgrade_data) {
			case 0:
				PAY = field[com1->where].area_pay / 5;
				break;
			case 1:
				PAY = field[com1->where].area_pay / 2;
				break;
			case 2:
				PAY = field[com1->where].area_pay *1.5;
				break;
			case 3:
				PAY = field[com1->where].area_pay * 2;
				break;
			case 4:
				PAY = field[com1->where].area_pay * 4;
				break;
			}

			pSystem->playSound(FMOD_CHANNEL_REUSE, pSound[Money], false, &pChannel[1]); // �� ȿ����
			com1->money -= PAY; com1->all_money -= PAY;
			com2->money += PAY; com2->all_money += PAY;
			Draw(20, 26, WHITE, "������ %d����� �����մϴ�.", PAY);
			erase_pos(field);
			user_pos(field); // ���ݺ����� �׷���
			Timer(TIME);

			if (Over_Check(user, com1, com2, com3)) // ���� ����. �ڲ��μ��� �ϴ� ���װ� �־ �̸� ���ӿ��� üũ.
				goto AI_END;

			//////////////�μ�//////////////
			// �μ���� = (���� + ���׷��̵� ���) * 2
			PAY = (field[com1->where].area_pay + (field[com1->where].upgrade_data*field[com1->where].upgrade_pay)) * 2;

			if (com1->money - PAY >= 0) {
				/*choose = true; // ���� ������ ������ �μ�
			else choose = false;
			*/
			 // �μ��� �ϰڴٸ�
				Draw(20, 27, WHITE, "%s���� %d����� �����ϰ�", com1->name, PAY);
				Draw(20, 28, WHITE, "%s�� �μ��մϴ�.", field[com1->where].region_name);
				pSystem->playSound(FMOD_CHANNEL_REUSE, pSound[Money], false, &pChannel[1]); // �� ȿ����
				field[com1->where].anyhas = com1->who;
				com1->money -= PAY;
				// com1->all_money += PAY; // �� �ڻ� ���� X
				com2->money += PAY;
				// com2->all_money -= PAY; // �� �ڻ� ���� X

				erase_pos(field);
				user_pos(field); // ���ݺ����� �׷���
				Check_Whose_Area(field, com1); // ������ ������ ���� ǥ��
			}
		}
		else if (field[com1->where].anyhas == com3->who) { // com3�� ��
			Draw(20, 25, WHITE, "%s���� %s���� ���� �����߽��ϴ�.", com1->name, com3->name);

			//���׷��̵� ���¿� ���� ����� ����
			unsigned int PAY;
			switch (field[com1->where].upgrade_data) {
			case 0:
				PAY = field[com1->where].area_pay / 5;
				break;
			case 1:
				PAY = field[com1->where].area_pay / 2;
				break;
			case 2:
				PAY = field[com1->where].area_pay *1.5;
				break;
			case 3:
				PAY = field[com1->where].area_pay * 2;
				break;
			case 4:
				PAY = field[com1->where].area_pay * 4;
				break;
			}

			pSystem->playSound(FMOD_CHANNEL_REUSE, pSound[Money], false, &pChannel[1]); // �� ȿ����
			com1->money -= PAY; com1->all_money -= PAY;
			com3->money += PAY; com3->all_money += PAY;
			Draw(20, 26, WHITE, "������ %d����� �����մϴ�.", PAY);
			erase_pos(field);
			user_pos(field); // ���ݺ����� �׷���
			Timer(TIME);

			if (Over_Check(user, com1, com2, com3)) // ���� ����. �ڲ��μ��� �ϴ� ���װ� �־ �̸� ���ӿ��� üũ.
				goto AI_END;

			//////////////�μ�//////////////
			// �μ���� = (���� + ���׷��̵� ���) * 2
			PAY = (field[com1->where].area_pay + (field[com1->where].upgrade_data*field[com1->where].upgrade_pay)) * 2;

			if (com1->money - PAY >= 0) { // �μ��� �ϰڴٸ�

				pSystem->playSound(FMOD_CHANNEL_REUSE, pSound[Money], false, &pChannel[1]); // �� ȿ����
				Draw(20, 27, WHITE, "%s���� %d����� �����ϰ�", com1->name, PAY);
				Draw(20, 28, WHITE, "%s�� �μ��մϴ�.", field[com1->where].region_name);
				field[com1->where].anyhas = com1->who;
				com1->money -= PAY;
				// com1->all_money += PAY; // �� �ڻ� ���� X
				com3->money += PAY;
				// com3->all_money -= PAY; // �� �ڻ� ���� X

				erase_pos(field);
				user_pos(field); // ���ݺ����� �׷���
				Check_Whose_Area(field, com1); // ������ ������ ���� ǥ��
			}
		}
		// ��������. ����. �︪��. to����. to�︪ �� ���ǽĵ� ��� ��
	}

	else if (field[com1->where].anyhas == 5)
		Draw(20, 25, WHITE, "%s���� ���������� �����߽��ϴ�.", com1->name);
	else if (field[com1->where].anyhas == 6) {
		Draw(20, 25, WHITE, "%s���� �︪���� ǥ���Ǿ����ϴ�.", com1->name);
		pSystem->playSound(FMOD_CHANNEL_REUSE, pSound[Oops], false, &pChannel[1]); // �㹫 ȿ����
		jail_count[com1->who] = 3;

	}
	else if (field[com1->where].anyhas == 7) {
		Draw(20, 25, WHITE, "%s���� ������������ �̵��մϴ�.", com1->name);
		Timer(TIME); // TIME�� ������ �� ������������ �̵����� ������
		field[com1->where].on--; // ���� ������ ������ ����
		com1->where = 0;
		com1->around++; // �� ���� �� ������ ���
		field[com1->where].on++; // ���������� ���� �߰�
		erase_pos(field);
		user_pos(field); // �̵��� ��� ���
	}
	else if (field[com1->where].anyhas == 8) {
		Draw(20, 25, WHITE, "%s���� �︪���� �̵��մϴ�.", com1->name);
		Timer(TIME); // TIME�� ������ �� �︪���� �̵����� ������
		pSystem->playSound(FMOD_CHANNEL_REUSE, pSound[Oops], false, &pChannel[1]); // �㹫 ȿ����
		field[com1->where].on--; // ���� ������ ������ ����
		com1->where = 9;
		field[com1->where].on++; // �︪���� ���� �߰�
		erase_pos(field);
		user_pos(field); // �̵��� ��� ���
		jail_count[com1->who] = 3; // ü�� ����
	}
	else if (field[com1->where].anyhas == 9) {
		Draw(20, 25, WHITE, "%s���� ������ ȹ���ϼ̽��ϴ�.", com1->name);
		
		Chance(field, com1); // �����Լ� ȣ��

		erase_pos(field);
		user_pos(field); // �̵��� ���(+�����׷��̵� ����) ���
	}

AI_END:

	Timer(TIME);


	erase_text(); // �˸���������

	InputLateUpdate();
		

}

// ���ڻ� üũ //
bool Over_Check(struct PLAYER *user, struct PLAYER *com1, struct PLAYER *com2, struct PLAYER *com3)
{

	// ���� �����
	if (user->all_money < 0 || com1->all_money < 0 || com2->all_money < 0 || com3->all_money < 0) // �Ѹ��̶� ���ڻ��� ������ ��ٸ�
	{
		//�� ��ȯ
		Scene_Gameover_Init(); // Init �Լ� ȣ��
		SceneNumber = GAMEOVER; // ����ȣ �ѱ�
		return true; // true��ȯ�� �ٷ� Ingame�Լ��� ����
	}

	return false;
}
