#ifndef __Draw_Field__
#define __Draw_Field__

//맵을 그림
void DrawField(struct fields *f, struct PLAYER *a, struct PLAYER *b, struct PLAYER *c, struct PLAYER *d);
//ui '땅 설명' 탭을 그림
void print_area_ui(void);

//필드상에 유저의 위치를 출력, 소지금 변동 표기
void user_pos(struct fields *f);

//필드상에 출력된 유저를 지움
void erase_pos(struct fields *f);

//한칸씩 유저를 이동시킴
void move_pos(struct fields *f, struct PLAYER *who);


//필드상에 유저가 구매한 땅을 표시
void Check_Whose_Area(struct fields *f, struct PLAYER *who);

//땅의 정보 출력(땅값, 통행료 등)
void Area_stat(struct fields *f, struct PLAYER *who);

//주사위를 던짐
void throw_dice(int d1, int d2);

//알림문구 전체삭제
void erase_text(void);

//로딩창
void loading(void);

#endif
