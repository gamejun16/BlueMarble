#ifndef __Draw_Field__
#define __Draw_Field__

//���� �׸�
void DrawField(struct fields *f, struct PLAYER *a, struct PLAYER *b, struct PLAYER *c, struct PLAYER *d);
//ui '�� ����' ���� �׸�
void print_area_ui(void);

//�ʵ�� ������ ��ġ�� ���, ������ ���� ǥ��
void user_pos(struct fields *f);

//�ʵ�� ��µ� ������ ����
void erase_pos(struct fields *f);

//��ĭ�� ������ �̵���Ŵ
void move_pos(struct fields *f, struct PLAYER *who);


//�ʵ�� ������ ������ ���� ǥ��
void Check_Whose_Area(struct fields *f, struct PLAYER *who);

//���� ���� ���(����, ����� ��)
void Area_stat(struct fields *f, struct PLAYER *who);

//�ֻ����� ����
void throw_dice(int d1, int d2);

//�˸����� ��ü����
void erase_text(void);

//�ε�â
void loading(void);

#endif
