#include "Scene.h"
#include "Set_User.h"

struct fields field[36]; // 땅
struct PLAYER user, com1, com2, com3;


char username[10];

int TURN = 1; // 순서
int dice1, dice2; // 주사위
int jail_count[5]; // 감옥 ( == 울릉도 ). 1~4번플레이어 인덱스 값 = 각각 1~4. 0인덱스는 사용 x

bool Sn_Inform = false; //해당 함수 호출용 함수


//bool GameOver = true; // false가 되면 게임 종료

//예제장면(Scene Example) 초기화 함수
void Scene_Ingame_Init()
{	

	////////////게임준비///////////
	//유저정보 입력
	Set_User(&user, &com1, &com2, &com3);


	//땅 정보 호출
	//Set_Area(field);

	//로딩창
	loading();



	//필드를 그려냄
	DrawField(field, &user, &com1, &com2, &com3);
	
	inform_choice = 4; // inform탭 선택지
	Sn_Inform = false; // inform탭 출력여부

	//유저들의 시작 위치
	user.where = 0;
	com1.where = 0;
	com2.where = 0;
	com3.where = 0;

	// 바퀴 수
	user.around = 0;
	com1.around = 0;
	com2.around = 0;
	com3.around = 0;

	// 감옥 카운트
	jail_count[1] = 0;
	jail_count[2] = 0;
	jail_count[3] = 0;
	jail_count[4] = 0;

	field[0].on = 4; // 첫 시작시 4명이 올라서 있음

	TURN = 1; // 순서. 1 ~ 4

	user_pos(field);

}

//예제장면(Scene Example) 렌더링 함수
bool Scene_Ingame_Render(float timeDelta)
{

	/*
	//정보 탭 출력 함수
	if (KeyDown(KEY_SPACE))
		if(Sn_Inform == false) Sn_Inform = true;
	if (Sn_Inform) Scene_Inform(); // Sn_Inform 이 true라면 해당 탭 출력
	*/

	//////////////////////게임시작/////////////////////////////

	bool choose = true;

	//************1번 플레이어********************************

	if (TURN == 1) {
		TURN = 2;
		
		Draw(46, 13, WHITE, "엔터를 눌러");
		Draw(46, 14, WHITE, "주사위를 굴리십시오");
		Draw(46, 15, WHITE, "# - 옵션");
		Draw(46, 16, WHITE, ""); textcolor(8); printf("; - 관리자모드");

		while (1) {
			char Cc = NULL;
			Cc = _getch();
			if (Cc == KEY_ENTER) break; // 주사위던짐. 엔터입력후 넘어감
			else if (Cc == '#') { // 옵션창 호출
				TURN = 1; // 유저가 다시 자신의 턴을 진행하게 함
				Scene_Ingame_Option_Init();
				SceneNumber = INGAME_OPTION;
				Cc = NULL;

				Draw(46, 13, WHITE, "　　　　　　");
				Draw(46, 14, WHITE, "　　　　　　　　　　"); // test_ver
				Draw(46, 15, WHITE, "　　　　");
				Draw(46, 16, WHITE, "　　　　　　　");
				return true; // ingame_render를 종료. -> Ingame_Option_Render 로 넘어감
			}
			else if (Cc == ';') { // 원활한 중간, 최종 발표를 위한 맵 세팅 과정
				//TURN = 1; // 유저가 다시 자신의 턴을 진행하게 함
				user.around = 4; com1.around = 1; com2.around = 2; com3.around = 3; // 바퀴수 설정

				user.money = 1500; user.all_money = 1500;
				com1.money = 0; com1.all_money = 0;
				com2.money = 0; com2.all_money = 0;
				com3.money = 0; com3.all_money = 0;

				/** 땅 소유권 설정 **/
				for (int i = 1; i <= 35; (i + 1) % 3 == 0 ? i+=2 : i++) {
					user.where = i;
					field[user.where].anyhas =1; // user의 땅으로 할당
					Check_Whose_Area(field, &user); // 땅표시

					user_pos(field); // 소지금변동
				}
				user.where = 0;

			}
			Cc = NULL;
		}
		
		Draw(46, 13, WHITE, "　　　　　　");
		Draw(46, 14, WHITE, "　　　　　　　　　　"); // test_ver
		Draw(46, 15, WHITE, "　　　　");
		Draw(46, 16, WHITE, "　　　　　　　");

		dice1 = rand() % 6 + 1; dice2 = rand() % 6 + 1; // 주사위 두개 굴림
		//Draw(20, 24, WHITE, "%d %d", dice1, dice2);
		throw_dice(dice1, dice2);
		//유저의 색을 안내문구 앞에 출력함
		Draw(16, 25, BG_RED, "　");
		Draw(16, 26, BG_RED, "　");
		Draw(16, 27, BG_RED, "　");
		
		//플레이!


		// 울릉도에 갇힘 여부 //
		if (jail_count[1] != 0) { // jail_count가 0이 아니라면 (울릉도에 체류중이라면)	
			Draw(20, 25, RED, "%s님이 울릉도에 표류중입니다..", user.name);

			Area_stat(field, &user);

			Timer(TIME); // 타이머

			if (dice1 == dice2) { // 더블이면?
				jail_count[1] = 0; // 울릉 체류 종료
				Draw(20, 26, RED, "더블! 탈출에 성공했습니다!");
				Timer(TIME);
				Draw(20, 25, RED, "　　　　　　　　　　　　　　　　　　　　");
				Draw(20, 26, RED, "　　　　　　　　　　　　　");
				Game_Play(field, &user, &com1, &com2, &com3, 0); // 이동
				//AI_Play(field, &com1, &user, &com2, &com3, 0); // text_ver
			}
			else { // 더블이 아니라면
				jail_count[1]--; // 체류횟수 1 감소
				jail_count[1] != 0 ? Draw(20, 26, RED, "「 %d턴 후 구조됩니다 」", jail_count[1]) : Draw(20, 26, RED, "구조되었습니다!");
				Timer(TIME);

				//erase_text(); // 알림문구삭제
			}

			erase_text(); // 알림문구삭제

		}


		else { // jail_count가 0이였다면 (정상 플레이)
			Game_Play(field, &user, &com1, &com2, &com3, 0);
			//AI_Play(field, &com1, &user, &com2, &com3, 0); // test_ver
		}
	}
	
	if (Over_Check(&user, &com1, &com2, &com3)) // true반환시 게임 종료
		return true;


	//*********2번 플레이어 ( ai )********************************
	
	if (TURN == 2) {
		TURN = 3;
		dice1 = rand() % 6 + 1; dice2 = rand() % 6 + 1; // 주사위 두개 굴림
		//Draw(20, 24, WHITE, "%d %d", dice1, dice2);
		throw_dice(dice1, dice2);

		//유저의 색을 출력함
		Draw(16, 25, BG_BLUE, "　");
		Draw(16, 26, BG_BLUE, "　");
		Draw(16, 27, BG_BLUE, "　");

		// 울릉도에 갇힘 여부 //
		if (jail_count[2] != 0) { // jail_count가 0이 아니라면 (울릉도에 체류중이라면)	
			Draw(20, 25, RED, "%s님이 울릉도에 표류중입니다..", com1.name);

			Area_stat(field, &com1);

			Timer(TIME); // 타이머

			if (dice1 == dice2) { // 더블이면?
				jail_count[2] = 0; // 울릉 체류 종료
				Draw(20, 26, RED, "더블! 탈출에 성공했습니다!");
				Timer(TIME);
				Draw(20, 25, RED, "　　　　　　　　　　　　　　　　　　　　");
				Draw(20, 26, RED, "　　　　　　　　　　　　　");
				AI_Play(field, &user, &com1, &com2, &com3, 0); // 이동
			}
			else { // 더블이 아니라면
				jail_count[2]--; // 체류횟수 1 감소
				jail_count[2] != 0 ? Draw(20, 26, RED, "「 %d턴 후 구조됩니다 」", jail_count[2]) : Draw(20, 26, RED, "구조되었습니다!");
				Timer(TIME);
			}

			erase_text(); // 알림문구삭제

		}
		else // jail_count가 0이였다면 (정상 플레이)
			AI_Play(field, &user, &com1, &com2, &com3, 0);
		
	}
	
	if (Over_Check(&user, &com1, &com2, &com3)) // true반환시 게임 종료
		return true;

	//***************3번 플레이어 ( ai )********************************

	if (TURN == 3) {
		TURN = 4;
		dice1 = rand() % 6 + 1; dice2 = rand() % 6 + 1; // 주사위 두개 굴림
		//Draw(20, 24, WHITE, "%d %d", dice1, dice2);
		throw_dice(dice1, dice2);

		//유저의 색을 출력함
		Draw(16, 25, BG_SKYBLUE, "　");
		Draw(16, 26, BG_SKYBLUE, "　");
		Draw(16, 27, BG_SKYBLUE, "　");

		//플레이!
		// 울릉도에 갇힘 여부 //
		if (jail_count[3] != 0) { // jail_count가 0이 아니라면 (울릉도에 체류중이라면)	
			Draw(20, 25, RED, "%s님이 울릉도에 표류중입니다..", com2.name);

			Area_stat(field, &com2);

			Timer(TIME); // 타이머

			if (dice1 == dice2) { // 더블이면?
				jail_count[3] = 0; // 울릉 체류 종료
				Draw(20, 26, RED, "더블! 탈출에 성공했습니다!");
				Timer(TIME);
				Draw(20, 25, RED, "　　　　　　　　　　　　　　　　　　　　");
				Draw(20, 26, RED, "　　　　　　　　　　　　　");
				AI_Play(field, &user, &com2, &com1, &com3, 0); // 이동
			}
			else { // 더블이 아니라면
				jail_count[3]--; // 체류횟수 1 감소
				jail_count[3] != 0 ? Draw(20, 26, RED, "「 %d턴 후 구조됩니다 」", jail_count[3]) : Draw(20, 26, RED, "구조되었습니다!");
				Timer(TIME);
			}

			erase_text(); // 알림문구삭제

		}
		else // jail_count가 0이였다면 (정상 플레이)
			AI_Play(field, &user, &com2, &com1, &com3, 1);
	}

	if (Over_Check(&user, &com1, &com2, &com3)) // true반환시 게임 종료
		return true;

	//***************4번 플레이어 ( ai )********************************

	if (TURN == 4) {
		TURN = 1;
		dice1 = rand() % 6 + 1; dice2 = rand() % 6 + 1; // 주사위 두개 굴림
		//Draw(20, 24, WHITE, "%d %d", dice1, dice2);
		throw_dice(dice1, dice2);

		//유저의 색을 출력함
		Draw(16, 25, BG_GREEN, "　");
		Draw(16, 26, BG_GREEN, "　");
		Draw(16, 27, BG_GREEN, "　");

		//플레이!
		// 울릉도에 갇힘 여부 //
		if (jail_count[4] != 0) { // jail_count가 0이 아니라면 (울릉도에 체류중이라면)	
			Draw(20, 25, RED, "%s님이 울릉도에 표류중입니다..", com3.name);

			Area_stat(field, &com3);

			Timer(TIME); // 타이머

			if (dice1 == dice2) { // 더블이면?
				jail_count[4] = 0; // 울릉 체류 종료
				Draw(20, 26, RED, "더블! 탈출에 성공했습니다!");
				Timer(TIME);
				Draw(20, 25, RED, "　　　　　　　　　　　　　　　　　　　　");
				Draw(20, 26, RED, "　　　　　　　　　　　　　");
				AI_Play(field, &user, &com3, &com1, &com2, 0); // 이동
			}
			else { // 더블이 아니라면
				jail_count[4]--; // 체류횟수 1 감소
				jail_count[4] != 0 ? Draw(20, 26, RED, "「 %d턴 후 구조됩니다 」", jail_count[4]) : Draw(20, 26, RED, "구조되었습니다!");
				Timer(TIME);
			}

			erase_text(); // 알림문구삭제
		}
		else // jail_count가 0이였다면 (정상 플레이)
			AI_Play(field, &user, &com3, &com1, &com2, 0);
	}

	if (Over_Check(&user, &com1, &com2, &com3)) // true반환시 게임 종료
		return true;

	END:

	return true;
}


