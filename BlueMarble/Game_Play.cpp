#include "Scene.h"
#include "Game_Play.h"


/*************************************************************

< 본 .cpp에 구현 된 함수 목록 >

void Timer(float) -> 타이머 함수
void Game_Play(field, user, com1, com2, com3, option) -> 유저의 플레이. user가 주체
void AI_Play(field, user, com1, com2, com3, option) -> Ai의 플레이. com1가 주체

****************************************************************/


const float TIME = 3.0;

bool choose = true;


void Timer(float t_1) {
	float t_2 = clock()*0.001; // 타이머 호출시 시간
	float t_3;
	while(1){
		t_3 = clock()*0.001 - t_2;
		if (t_3 > t_1)
			break;
	}
}


////////////**   user가 진행의 주체!!   **/////////////
void Game_Play(struct fields *field, struct PLAYER *user, struct PLAYER *com1, struct PLAYER *com2, struct PLAYER *com3, int option)
{
	move_pos(field, user); // 점을 옮김

		// 해당 위치 땅의 정보를 보여줌
	Area_stat(field, user);

	//땅 판별
	if (field[user->where].anyhas >= 0 && field[user->where].anyhas <= 4) { // 0=아무도 소유x, 1~4 = 해당 플레이어의 땅
		if (field[user->where].anyhas == 0 && user->money - field[user->where].area_pay >= 0) { // 아무도 소유하고 있지 않고 잔액이 남는다면
			InputLateUpdate(); // 엔터버퍼 초기화

			Draw(20, 25, WHITE, "%s을 구매하시겠습니까?", field[user->where].region_name);
			Draw(20, 26, WHITE, "예"); Draw(30, 26, WHITE, "아니오");

			while (1) {
				InputUpdate(); // 입력을 받음
				if (KeyDown(KEY_RIGHT) || KeyDown(KEY_LEFT)) {
					if (choose == true) {
						Draw(17, 26, WHITE, "　");
						choose = false;
					}
					else if (choose == false) {
						Draw(27, 26, WHITE, "　");
						choose = true;
					}
				}
				else if (KeyDown(KEY_ENTER)) break;

				if (choose == true)
					Draw(17, 26, WHITE, "▶");
				else if (choose == false)
					Draw(27, 26, WHITE, "▶");
				InputLateUpdate();
			}

			if (choose == true) {
				pSystem->playSound(FMOD_CHANNEL_REUSE, pSound[Money], false, &pChannel[1]); // 돈소리

				user->money -= field[user->where].area_pay; // 소지금 감소
				//user->all_money += field[user->where].area_pay; // 총 자산 변동 X
				field[user->where].anyhas = user->who; // 소유권 get
													 // DrawField(field, &user, &com1, &com2, &com3); // 맵 다시 그림. 및 함수 종료 -> 턴 넘김
				erase_pos(field);
				user_pos(field); // 가격변동을 그려줌
				Check_Whose_Area(field, user); // 유저가 구매한 땅을 표시

				Draw(20, 27, WHITE, "%s님이 %s을 구매하셨습니다.", user->name, field[user->where].region_name);
			}
		}
		//빈땅인데 잔액이 부족하다면
		else if (field[user->where].anyhas == 0 && user->money - field[user->where].area_pay < 0) {
			Draw(20, 25, WHITE, "소지금이 부족해 %s을", field[user->where].region_name);
			Draw(20, 26, WHITE, "구매할 수 없습니다!");
		}

		else if (field[user->where].anyhas == user->who) { // 본인땅

			Draw(20, 25, WHITE, "%s님이 자신의땅에 도착했습니다.", user->name);
			int choose_2 = 1;

			/********** 업그레이드 부 ***********/

			//업그레이드 조건:
			//게임 필드 전체를 한 바퀴씩 돈 횟수를 n으로 두었을 때
			//최대 +n까지 업그레이드 가능

			if (user->money - field[user->where].upgrade_pay >= 0) { // 업그레이드 할 잔액이 있다면
				while (field[user->where].upgrade_data < user->around && field[user->where].upgrade_data < 4) {
					Draw(20, 26, WHITE, "현재 +%d 입니다.", field[user->where].upgrade_data);
					Draw(20, 27, WHITE, "빌딩을 세우시겠습니까?");
					Draw(23, 28, WHITE, "YES　　　　NO");
					if (choose_2 == 1) {
						Draw(20, 28, WHITE, "▶");
						Draw(31, 28, WHITE, "　");
					}
					else if (choose_2 == 2) {
						Draw(20, 28, WHITE, "　");
						Draw(31, 28, WHITE, "▶");
					}

					InputUpdate(); // 키입력 받음

					if (KeyDown(KEY_RIGHT) || KeyDown(KEY_LEFT)) {
						if (choose_2 == 1) choose_2 = 2;
						else if (choose_2 == 2) choose_2 = 1;
						InputLateUpdate();
						continue;
					}
					else if (KeyDown(KEY_ENTER)) {
						if (choose_2 == 1) { // 강화를 하겠다면
							pSystem->playSound(FMOD_CHANNEL_REUSE, pSound[Money], false, &pChannel[1]); // 돈 효과음

											 //////////////// 업그레이드 관련 변동사항 설정 ////////////////
											 //업그레이드 비용
							int PAY = field[user->where].area_pay / 6;

							user->money -= PAY; // n 업그레이드를 원한다면. 해당 비용만큼 차감
							// user->all_money += PAY; // 총자산 변동 X
							field[user->where].upgrade_data++; // 해당 땅 업그레이드 사항 변동

							erase_pos(field);
							user_pos(field); // 가격변동을 그려줌

							Check_Whose_Area(field, user); // 유저가 구매한 땅(업그레이드 사항)을 표시

							Draw(20, 26, WHITE, "현재 +%d 입니다!", field[user->where].upgrade_data);

							if (user->money - field[user->where].upgrade_pay < 0) { // 업그레이드 할 잔액이 없다면
								Draw(20, 27, WHITE, "잔액이 부족해 업그레이드를 종료합니다.");
								break;
							}

							Draw(20, 29, WHITE, "최대 %d까지 업그레이드가 가능합니다.", user->around < 4 ? user->around : 4);
							InputLateUpdate();
							continue;
						}
						else if (choose_2 == 2) { // 강화를 그만하겠다면
							Draw(20, 29, WHITE, "　　　　　　　　　　　　　　　　　　　");
							Draw(20, 29, WHITE, "업그레이드를 종료합니다!");
							break;
						}
					}
				}
			}
			else { // 업그레이드 할 잔액이 없다면
				Draw(20, 26, WHITE, "현재 +%d 입니다.", field[user->where].upgrade_data);
			}
			InputLateUpdate();

			/************************UPGRADEUPGRADEUPGRADE***********************/

			/************************UPGRADEUPGRADEUPGRADE***********************/

		}
		else if (field[user->where].anyhas == com1->who) { // com1(타 플레이어) 땅
			Draw(20, 25, WHITE, "%s님이 %s님의 땅에 도착했습니다.", user->name, com1->name);

			//업그레이드 상태에 따른 통행료 측정
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
			pSystem->playSound(FMOD_CHANNEL_REUSE, pSound[Money], false, &pChannel[1]); // 돈 효과음
			user->money -= PAY; user->all_money -= PAY;
			com1->money += PAY; com1->all_money += PAY;
			Draw(20, 26, WHITE, "통행료로 %d억원을 지불합니다.", PAY);
			erase_pos(field);

			user_pos(field); // 가격변동을 그려줌
			Timer(TIME);

			if (Over_Check(user, com1, com2, com3)) // 게임 종료. 자꾸인수를 하는 버그가 있어서 미리 게임오버 체크.
				goto END;

			//////////////인수//////////////
			/*
			for (int i = 24; i < 33; i++)
			Draw(17, i, WHITE, "　　　　　　　　　　　　　　　　　　　　　　　　");
			*/
			if (user->money - PAY > 0) { // 인수할 만큼의 돈이 남아있다면
				Draw(20, 27, WHITE, "%s을 인수하시겠습니까?", field[user->where].region_name);
				// 인수비용 = (땅값 + 업그레이드 비용) * 2
				PAY = (field[user->where].area_pay + (field[user->where].upgrade_data*field[user->where].upgrade_pay)) * 2;

				Draw(20, 28, WHITE, "인수 비용은 %d억원 입니다.", PAY);
				Draw(20, 29, WHITE, "예"); Draw(30, 29, WHITE, "아니오");

				while (1) {
					InputUpdate();

					if (KeyDown(KEY_RIGHT) || KeyDown(KEY_LEFT)) {
						if (choose == true) {
							Draw(17, 29, WHITE, "　");
							choose = false;
						}
						else if (choose == false) {
							Draw(27, 29, WHITE, "　");
							choose = true;
						}
					}
					else if (KeyDown(KEY_ENTER)) {
						Draw(17, 29, WHITE, "　"); Draw(27, 29, WHITE, "　");
						break;
					}
					if (choose == true)
						Draw(17, 29, WHITE, "▶");
					else if (choose == false)
						Draw(27, 29, WHITE, "▶");
					InputLateUpdate();
				}

				if (choose == true && user->money - PAY >= 0) { // 인수를 하겠다면 ( 금액이 -가 되지 않을 때 )
					pSystem->playSound(FMOD_CHANNEL_REUSE, pSound[Money], false, &pChannel[1]); // 돈 효과음
					field[user->where].anyhas = user->who; // 소유권 양도
					user->money -= PAY;
					// user->all_money += PAY; // 총 자산 변동 X
					com1->money += PAY;
					// com1->all_money -= PAY; // 총 자산 변동 X

					Draw(20, 30, WHITE, "%s님이 %s를 인수하셨습니다.", user->name, field[user->where].region_name);
					erase_pos(field);
					user_pos(field); // 가격변동을 그려줌
					Check_Whose_Area(field, user); // 유저가 구매한 땅을 표시
				}
				else if (choose == true && user->money - PAY < 0) {
					Draw(20, 30, WHITE, "소지금이 부족합니다!");
				}
			}

			else if (field[user->where].anyhas == com2->who) { // com2의 땅
				Draw(20, 25, WHITE, "%s님이 %s님의 땅에 도착했습니다.", user->name, com2->name);

				//업그레이드 상태에 따른 통행료 측정
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
				// 통행료 지불 //
				pSystem->playSound(FMOD_CHANNEL_REUSE, pSound[Money], false, &pChannel[1]); // 돈 효과음
				user->money -= PAY; user->all_money -= PAY;
				com2->money += PAY; com2->all_money += PAY;
				Draw(20, 26, WHITE, "통행료로 %d억원을 지불합니다.", PAY);
				erase_pos(field);
				user_pos(field); // 가격변동을 그려줌
				Timer(TIME);

				if (Over_Check(user, com1, com2, com3)) // 게임 종료. 자꾸인수를 하는 버그가 있어서 미리 게임오버 체크.
					goto END;

				//////////////인수//////////////
				/*
				for (int i = 24; i < 33; i++)
				Draw(17, i, WHITE, "　　　　　　　　　　　　　　　　　　　　　　　　");
				*/
				if (user->money - PAY > 0) { // 인수할 만큼의 돈이 남아있다면

					Draw(20, 27, WHITE, "%s을 인수하시겠습니까?", field[user->where].region_name);
					// 인수비용 = (땅값 + 업그레이드 비용) * 2
					PAY = (field[user->where].area_pay + (field[user->where].upgrade_data*field[user->where].upgrade_pay)) * 2;
					Draw(20, 28, WHITE, "인수 비용은 %d억원 입니다.", PAY);
					Draw(20, 29, WHITE, "예"); Draw(30, 29, WHITE, "아니오");

					while (1) {
						InputUpdate();

						if (KeyDown(KEY_RIGHT) || KeyDown(KEY_LEFT)) {
							if (choose == true) {
								Draw(17, 29, WHITE, "　");
								choose = false;
							}
							else if (choose == false) {
								Draw(27, 29, WHITE, "　");
								choose = true;
							}
						}
						else if (KeyDown(KEY_ENTER)) {
							Draw(17, 29, WHITE, "　"); Draw(27, 29, WHITE, "　");
							break;
						}
						if (choose == true)
							Draw(17, 29, WHITE, "▶");
						else if (choose == false)
							Draw(27, 29, WHITE, "▶");
						InputLateUpdate();
					}
					if (choose == true && user->money - PAY >= 0) { // 인수를 하겠다면 ( 금액이 -가 되지 않을 때 )
						pSystem->playSound(FMOD_CHANNEL_REUSE, pSound[Money], false, &pChannel[1]); // 돈 효과음
						field[user->where].anyhas = user->who;
						user->money -= PAY;
						// user->all_money += PAY; // 총 자산 변동 X
						com2->money += PAY;
						// com2->all_money -= PAY; // 총 자산 변동 X

						Draw(20, 30, WHITE, "%s님이 %s를 인수하셨습니다.", user->name, field[user->where].region_name);
						erase_pos(field);
						user_pos(field); // 가격변동을 그려줌
						Check_Whose_Area(field, user); // 유저가 구매한 땅을 표시
					}
					else if (choose == true && user->money - PAY < 0) {
						Draw(20, 30, WHITE, "소지금이 부족합니다!");
					}
				}
			}
			else if (field[user->where].anyhas == com3->who) { // com3(타 플레이어) 땅
				Draw(20, 25, WHITE, "%s님이 %s님의 땅에 도착했습니다.", user->name, com3->name);

				//업그레이드 상태에 따른 통행료 측정
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
				// 통행료 지불 //
				pSystem->playSound(FMOD_CHANNEL_REUSE, pSound[Money], false, &pChannel[1]); // 돈 효과음
				user->money -= PAY; user->all_money -= PAY;
				com3->money += PAY; com3->all_money += PAY;
				Draw(20, 26, WHITE, "통행료로 %d억원을 지불합니다.", PAY);
				erase_pos(field);

				user_pos(field); // 가격변동을 그려줌
				Timer(TIME);

				if (Over_Check(user, com1, com2, com3)) // 게임 종료. 자꾸인수를 하는 버그가 있어서 미리 게임오버 체크.
					goto END;

				//////////////인수//////////////
				/*
				for (int i = 24; i < 33; i++)
				Draw(17, i, WHITE, "　　　　　　　　　　　　　　　　　　　　　　　　");
				*/
				if (user->money - PAY > 0) { // 인수할 만큼의 돈이 남아있다면
					Draw(20, 27, WHITE, "%s을 인수하시겠습니까?", field[user->where].region_name);
					// 인수비용 = (땅값 + 업그레이드 비용) * 2
					PAY = (field[user->where].area_pay + (field[user->where].upgrade_data*field[user->where].upgrade_pay)) * 2;
					Draw(20, 28, WHITE, "인수 비용은 %d억원 입니다.", PAY);
					Draw(20, 29, WHITE, "예"); Draw(30, 29, WHITE, "아니오");

					while (1) {
						InputUpdate();

						if (KeyDown(KEY_RIGHT) || KeyDown(KEY_LEFT)) {
							if (choose == true) {
								Draw(17, 29, WHITE, "　");
								choose = false;
							}
							else if (choose == false) {
								Draw(27, 29, WHITE, "　");
								choose = true;
							}
						}
						else if (KeyDown(KEY_ENTER)) {
							Draw(17, 29, WHITE, "　"); Draw(27, 29, WHITE, "　");
							break;
						}
						if (choose == true)
							Draw(17, 29, WHITE, "▶");
						else if (choose == false)
							Draw(27, 29, WHITE, "▶");
						InputLateUpdate();
					}

					if (choose == true && user->money - PAY >= 0) { // 인수를 하겠다면 ( 금액이 -가 되지 않을 때 )
						pSystem->playSound(FMOD_CHANNEL_REUSE, pSound[Money], false, &pChannel[1]); // 돈 효과음
						field[user->where].anyhas = user->who;
						user->money -= PAY;
						// user->all_money += PAY; // 총 자산 변동 X
						com3->money += PAY;
						// com3->all_money -= PAY; // 총 자산 변동 X

						Draw(20, 30, WHITE, "%s님이 %s를 인수하셨습니다.", user->name, field[user->where].region_name);
						erase_pos(field);
						user_pos(field); // 가격변동을 그려줌
						Check_Whose_Area(field, user); // 유저가 구매한 땅을 표시
					}
					else if (choose == true && user->money - PAY < 0) {
						Draw(20, 30, WHITE, "소지금이 부족합니다!");
					}
				}
			}
		}
	}
	else if (field[user->where].anyhas == 5)
		Draw(20, 25, WHITE, "%s님이 시작지점에 도착했습니다.", user->name);

	else if (field[user->where].anyhas == 6) {
		pSystem->playSound(FMOD_CHANNEL_REUSE, pSound[Oops], false, &pChannel[1]); // 허무 효과음
		Draw(20, 25, WHITE, "%s님이 울릉도에 표류되었습니다.", user->name);
		jail_count[user->who] = 3;
	}
	else if (field[user->where].anyhas == 7) {
		Draw(20, 25, WHITE, "%s님이 시작지점으로 이동합니다.", user->name);
		Timer(TIME); // TIME초 딜레이 후 시작지점으로 이동함을 보여줌
		field[user->where].on--; // 기존 땅에서 유저를 빼냄
		user->where = 0;
		user->around++; // 한 바퀴 돈 것으로 계산
		field[user->where].on++; // 시작지점에 유저 추가
		erase_pos(field);
		user_pos(field); // 이동한 모습 출력
	}
	else if (field[user->where].anyhas == 8) {
		Draw(20, 25, WHITE, "%s님이 울릉도로 이동합니다.", user->name);
		Timer(TIME); // TIME초 딜레이 후 울릉도로 이동함을 보여줌
		field[user->where].on--; // 기존 땅에서 유저를 빼냄
		user->where = 9;
		field[user->where].on++; // 울릉도에 유저 추가
		pSystem->playSound(FMOD_CHANNEL_REUSE, pSound[Oops], false, &pChannel[1]); // 허무 효과음
		erase_pos(field);
		user_pos(field); // 이동한 모습 출력
		jail_count[user->who] = 3; // 체류시작
	}

	else if (field[user->where].anyhas == 9) {
		Draw(20, 25, WHITE, "%s님이 찬스를 획득하셨습니다.", user->name);

		Chance(field, user); // 찬스함수 호출
	}

END:

	Timer(TIME);


	erase_text(); // 알림문구삭제

	InputLateUpdate();


}


////////////**   com1이 진행의 주체!!   **/////////////
void AI_Play(struct fields *field, struct PLAYER *user, struct PLAYER *com1, struct PLAYER *com2, struct PLAYER *com3, int option)
{
	//한칸씩 이동시킴
	move_pos(field, com1);

	//해당 땅의 정보를 출력
	Area_stat(field, com1);

	//땅 판별
	if (field[com1->where].anyhas >= 0 && field[com1->where].anyhas <= 4) { // 0=아무도 소유x, 1~4 = 해당 플레이어의 땅
		if (field[com1->where].anyhas == 0) { // 아무도 소유하고 있지 않다면
											 // 자산이 남는다면 바로 구매하도록 설정
			if (com1->money - field[com1->where].area_pay >= 0){
				pSystem->playSound(FMOD_CHANNEL_REUSE, pSound[Money], false, &pChannel[1]); // 돈 효과음
				com1->money -= field[com1->where].area_pay; // 소지금 감소
				// com1->all_money += field[com1->where].area_pay; // 총 자산 변동 X
				field[com1->where].anyhas = com1->who; // 소유권 get
													 // DrawField(field, &user, &com1, &com2, &com3); // 맵 다시 그림. 및 함수 종료 -> 턴 넘김
				erase_pos(field);
				user_pos(field); // 가격변동을 그려줌
				Check_Whose_Area(field, com1); // com1가 구매한 땅을 표시

				Draw(20, 25, WHITE, "%s님이 %s을 구매하셨습니다.", com1->name, field[com1->where].region_name);
			}
			else {
				Draw(20, 25, WHITE, "소지금이 부족해 %s을", field[com1->where].region_name);
				Draw(20, 26, WHITE, "구매할 수 없습니다!");
			}
		}

		// 본인땅이라면
		else if (field[com1->where].anyhas == com1->who) {
			Draw(20, 25, WHITE, "%s님이 자신의땅에 도착했습니다.", com1->name);

			while (field[com1->where].upgrade_data < com1->around && field[com1->where].upgrade_data < 4) {

				int PAY = field[com1->where].area_pay / 6;

				if (com1->money - PAY >= 0) { // 돈이 남으면. 무조건 강화.

										  //////////////// 업그레이드 관련 변동사항 설정 ////////////////
										  //업그레이드 비용

					pSystem->playSound(FMOD_CHANNEL_REUSE, pSound[Money], false, &pChannel[1]); // 돈 효과음
					com1->money -= PAY; // n 업그레이드를 원한다면. 해당 비용만큼 차감
					// com1->all_money += PAY; // 총자산 변동 X
					field[com1->where].upgrade_data++; // 해당 땅 업그레이드 사항 변동

					erase_pos(field);
					user_pos(field); // 가격변동을 그려줌

					Check_Whose_Area(field, com1); // 유저가 구매한 땅(업그레이드 사항)을 표시
					Draw(20, 26, WHITE, "+%d가 되었습니다!", field[com1->where].upgrade_data);

					InputLateUpdate();
					continue;
				}
				else { // 돈이 모자란다면.
					Draw(20, 26, WHITE, "현재 +%d입니다.", field[com1->where].upgrade_data);
					break;
				}

			}
		}

		else if (field[com1->where].anyhas == user->who) { // user의땅
			Draw(20, 25, WHITE, "%s님이 %s님의 땅에 도착했습니다.", com1->name, user->name);

			//업그레이드 상태에 따른 통행료 측정
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

			pSystem->playSound(FMOD_CHANNEL_REUSE, pSound[Money], false, &pChannel[1]); // 돈 효과음
			com1->money -= PAY; com1->all_money -= PAY;
			user->money += PAY; user->all_money += PAY;
			Draw(20, 26, WHITE, "통행료로 %d억원을 지불합니다.", PAY);
			erase_pos(field);
			user_pos(field); // 가격변동을 그려줌
			Timer(TIME);

			
			if (Over_Check(user, com1, com2, com3)) // 게임 종료. 자꾸인수를 하는 버그가 있어서 미리 게임오버 체크.
				goto AI_END;
			
			//////////////인수//////////////
			// 인수비용 = (땅값 + 업그레이드 비용) * 2

			PAY = (field[com1->where].area_pay + (field[com1->where].upgrade_data*field[com1->where].upgrade_pay)) * 2;

			if (com1->money - PAY >= 0) { // 인수를 하겠다면
				Draw(20, 27, WHITE, "%s님이 %d억원을 지불하고", com1->name, PAY);
				Draw(20, 28, WHITE, "%s를 인수합니다.", field[com1->where].region_name);
				pSystem->playSound(FMOD_CHANNEL_REUSE, pSound[Money], false, &pChannel[1]); // 돈 효과음
				field[com1->where].anyhas = com1->who;
				com1->money -= PAY;
				// com1->all_money += PAY; // 총 자산 변동 X
				user->money += PAY;
				// user->all_money -= PAY; // 총 자산 변동 X

				erase_pos(field);
				user_pos(field); // 가격변동을 그려줌
				Check_Whose_Area(field, com1); // 유저가 구매한 땅을 표시
			}


		}
		else if (field[com1->where].anyhas == com2->who) { // com2의 땅
			Draw(20, 25, WHITE, "%s님이 %s님의 땅에 도착했습니다.", com1->name, com2->name);

			//업그레이드 상태에 따른 통행료 측정
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

			pSystem->playSound(FMOD_CHANNEL_REUSE, pSound[Money], false, &pChannel[1]); // 돈 효과음
			com1->money -= PAY; com1->all_money -= PAY;
			com2->money += PAY; com2->all_money += PAY;
			Draw(20, 26, WHITE, "통행료로 %d억원을 지불합니다.", PAY);
			erase_pos(field);
			user_pos(field); // 가격변동을 그려줌
			Timer(TIME);

			if (Over_Check(user, com1, com2, com3)) // 게임 종료. 자꾸인수를 하는 버그가 있어서 미리 게임오버 체크.
				goto AI_END;

			//////////////인수//////////////
			// 인수비용 = (땅값 + 업그레이드 비용) * 2
			PAY = (field[com1->where].area_pay + (field[com1->where].upgrade_data*field[com1->where].upgrade_pay)) * 2;

			if (com1->money - PAY >= 0) {
				/*choose = true; // 돈이 남으면 무조건 인수
			else choose = false;
			*/
			 // 인수를 하겠다면
				Draw(20, 27, WHITE, "%s님이 %d억원을 지불하고", com1->name, PAY);
				Draw(20, 28, WHITE, "%s를 인수합니다.", field[com1->where].region_name);
				pSystem->playSound(FMOD_CHANNEL_REUSE, pSound[Money], false, &pChannel[1]); // 돈 효과음
				field[com1->where].anyhas = com1->who;
				com1->money -= PAY;
				// com1->all_money += PAY; // 총 자산 변동 X
				com2->money += PAY;
				// com2->all_money -= PAY; // 총 자산 변동 X

				erase_pos(field);
				user_pos(field); // 가격변동을 그려줌
				Check_Whose_Area(field, com1); // 유저가 구매한 땅을 표시
			}
		}
		else if (field[com1->where].anyhas == com3->who) { // com3의 땅
			Draw(20, 25, WHITE, "%s님이 %s님의 땅에 도착했습니다.", com1->name, com3->name);

			//업그레이드 상태에 따른 통행료 측정
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

			pSystem->playSound(FMOD_CHANNEL_REUSE, pSound[Money], false, &pChannel[1]); // 돈 효과음
			com1->money -= PAY; com1->all_money -= PAY;
			com3->money += PAY; com3->all_money += PAY;
			Draw(20, 26, WHITE, "통행료로 %d억원을 지불합니다.", PAY);
			erase_pos(field);
			user_pos(field); // 가격변동을 그려줌
			Timer(TIME);

			if (Over_Check(user, com1, com2, com3)) // 게임 종료. 자꾸인수를 하는 버그가 있어서 미리 게임오버 체크.
				goto AI_END;

			//////////////인수//////////////
			// 인수비용 = (땅값 + 업그레이드 비용) * 2
			PAY = (field[com1->where].area_pay + (field[com1->where].upgrade_data*field[com1->where].upgrade_pay)) * 2;

			if (com1->money - PAY >= 0) { // 인수를 하겠다면

				pSystem->playSound(FMOD_CHANNEL_REUSE, pSound[Money], false, &pChannel[1]); // 돈 효과음
				Draw(20, 27, WHITE, "%s님이 %d억원을 지불하고", com1->name, PAY);
				Draw(20, 28, WHITE, "%s를 인수합니다.", field[com1->where].region_name);
				field[com1->where].anyhas = com1->who;
				com1->money -= PAY;
				// com1->all_money += PAY; // 총 자산 변동 X
				com3->money += PAY;
				// com3->all_money -= PAY; // 총 자산 변동 X

				erase_pos(field);
				user_pos(field); // 가격변동을 그려줌
				Check_Whose_Area(field, com1); // 유저가 구매한 땅을 표시
			}
		}
		// 시작지점. 찬스. 울릉도. to시작. to울릉 의 조건식도 모두 ㄱ
	}

	else if (field[com1->where].anyhas == 5)
		Draw(20, 25, WHITE, "%s님이 시작지점에 도착했습니다.", com1->name);
	else if (field[com1->where].anyhas == 6) {
		Draw(20, 25, WHITE, "%s님이 울릉도에 표류되었습니다.", com1->name);
		pSystem->playSound(FMOD_CHANNEL_REUSE, pSound[Oops], false, &pChannel[1]); // 허무 효과음
		jail_count[com1->who] = 3;

	}
	else if (field[com1->where].anyhas == 7) {
		Draw(20, 25, WHITE, "%s님이 시작지점으로 이동합니다.", com1->name);
		Timer(TIME); // TIME초 딜레이 후 시작지점으로 이동함을 보여줌
		field[com1->where].on--; // 기존 땅에서 유저를 빼냄
		com1->where = 0;
		com1->around++; // 한 바퀴 돈 것으로 계산
		field[com1->where].on++; // 시작지점에 유저 추가
		erase_pos(field);
		user_pos(field); // 이동한 모습 출력
	}
	else if (field[com1->where].anyhas == 8) {
		Draw(20, 25, WHITE, "%s님이 울릉도로 이동합니다.", com1->name);
		Timer(TIME); // TIME초 딜레이 후 울릉도로 이동함을 보여줌
		pSystem->playSound(FMOD_CHANNEL_REUSE, pSound[Oops], false, &pChannel[1]); // 허무 효과음
		field[com1->where].on--; // 기존 땅에서 유저를 빼냄
		com1->where = 9;
		field[com1->where].on++; // 울릉도에 유저 추가
		erase_pos(field);
		user_pos(field); // 이동한 모습 출력
		jail_count[com1->who] = 3; // 체류 시작
	}
	else if (field[com1->where].anyhas == 9) {
		Draw(20, 25, WHITE, "%s님이 찬스를 획득하셨습니다.", com1->name);
		
		Chance(field, com1); // 찬스함수 호출

		erase_pos(field);
		user_pos(field); // 이동한 모습(+땅업그레이드 변동) 출력
	}

AI_END:

	Timer(TIME);


	erase_text(); // 알림문구삭제

	InputLateUpdate();
		

}

// 총자산 체크 //
bool Over_Check(struct PLAYER *user, struct PLAYER *com1, struct PLAYER *com2, struct PLAYER *com3)
{

	// 게임 종료시
	if (user->all_money < 0 || com1->all_money < 0 || com2->all_money < 0 || com3->all_money < 0) // 한명이라도 총자산이 음수가 됬다면
	{
		//씬 전환
		Scene_Gameover_Init(); // Init 함수 호출
		SceneNumber = GAMEOVER; // 씬번호 넘김
		return true; // true반환시 바로 Ingame함수를 종료
	}

	return false;
}
