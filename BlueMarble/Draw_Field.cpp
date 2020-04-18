#include "Scene.h"
#include "Draw_Field.h"

void DrawField(struct fields *f, struct PLAYER *a, struct PLAYER *b, struct PLAYER *c, struct PLAYER *d)
{
	system("cls");
	system("mode con:cols=120 lines=41");

	////////////////////* (°íÁ¤µÇ¾îÀÖ´Â) °ÔÀÓ ÇÊµå ±×¸®±â *///////////////////////

	/* À±°û¼± */
	//°¡·Î¼±
	
	Draw(0, 0, BG_WHITE, "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡");
	Draw(0, 4, BG_WHITE, "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡");
	Draw(0, 36, BG_WHITE, "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡");
	Draw(0, 40, BG_WHITE, "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡");
	for (int i = 2; i < 7; i += 2) {
		Draw(i, 8, BG_WHITE, "¡¡"); Draw(i, 12, BG_WHITE, "¡¡"); Draw(i, 16, BG_WHITE, "¡¡"); Draw(i, 20, BG_WHITE, "¡¡");
		Draw(i, 24, BG_WHITE, "¡¡"); Draw(i, 28, BG_WHITE, "¡¡"); Draw(i, 32, BG_WHITE, "¡¡");
	}
	for (int i = 72; i < 81; i += 2) {
		Draw(i, 8, BG_WHITE, "¡¡"); Draw(i, 12, BG_WHITE, "¡¡"); Draw(i, 16, BG_WHITE, "¡¡"); Draw(i, 20, BG_WHITE, "¡¡");
		Draw(i, 24, BG_WHITE, "¡¡"); Draw(i, 28, BG_WHITE, "¡¡"); Draw(i, 32, BG_WHITE, "¡¡");
	}
	//¼¼·Î¼±
	for (int i = 0; i < 41; i++) {
		Draw(0, i, BG_WHITE, "¡¡"); Draw(8, i, BG_WHITE, "¡¡"); Draw(72, i, BG_WHITE, "¡¡"); Draw(80, i, BG_WHITE, "¡¡");
	}
	for (int i = 1; i < 4; i++) {
		Draw(16, i, BG_WHITE, "¡¡"); Draw(24, i, BG_WHITE, "¡¡"); Draw(32, i, BG_WHITE, "¡¡"); Draw(40, i, BG_WHITE, "¡¡");
		Draw(48, i, BG_WHITE, "¡¡"); Draw(56, i, BG_WHITE, "¡¡"); Draw(64, i, BG_WHITE, "¡¡");
	}
	for (int i = 37; i < 40; i++) {
		Draw(16, i, BG_WHITE, "¡¡"); Draw(24, i, BG_WHITE, "¡¡"); Draw(32, i, BG_WHITE, "¡¡"); Draw(40, i, BG_WHITE, "¡¡");
		Draw(48, i, BG_WHITE, "¡¡"); Draw(56, i, BG_WHITE, "¡¡"); Draw(64, i, BG_WHITE, "¡¡");
	}

	/* ¶¥ ÀÌ¸§ ³Ö±â */
	Draw(10, 1, WHITE, "%s", f[1].region_name);
	Draw(18, 1, WHITE, "%s", f[2].region_name);
	Draw(34, 1, WHITE, "%s", f[4].region_name);
	Draw(42, 1, WHITE, "%s", f[5].region_name);
	Draw(58, 1, WHITE, "%s", f[7].region_name);
	Draw(66, 1, WHITE, "%s", f[8].region_name);

	Draw(74, 5, WHITE, "%s", f[10].region_name);
	Draw(74, 9, WHITE, "%s", f[11].region_name);
	Draw(74, 17, WHITE, "%s", f[13].region_name);
	Draw(74, 21, WHITE, "%s", f[14].region_name);
	Draw(74, 29, WHITE, "%s", f[16].region_name);
	Draw(74, 33, WHITE, "%s", f[17].region_name);

	Draw(66, 37, WHITE, "%s", f[19].region_name);
	Draw(58, 37, WHITE, "%s", f[20].region_name);
	Draw(42, 37, WHITE, "%s", f[22].region_name);
	Draw(34, 37, WHITE, "%s", f[23].region_name);
	Draw(18, 37, WHITE, "%s", f[25].region_name);
	Draw(10, 37, WHITE, "%s", f[26].region_name);
	
	Draw(2, 33, WHITE, "%s", f[28].region_name);
	Draw(2, 29, WHITE, "%s", f[29].region_name);
	Draw(2, 21, WHITE, "%s", f[31].region_name);
	Draw(2, 17, WHITE, "%s", f[32].region_name);
	Draw(2, 9, WHITE, "%s", f[34].region_name);
	Draw(2, 5, WHITE, "%s", f[35].region_name);


	/* Âù½º Ä­ */
	Draw(26, 0, BG_YELLOW, "¡¡¡¡¡¡");		Draw(50, 0, BG_YELLOW, "¡¡¡¡¡¡");
	Draw(26, 1, BG_YELLOW, "¡¡¡¡¡¡");		Draw(50, 1, BG_YELLOW, "¡¡¡¡¡¡");
	Draw(26, 3, BG_YELLOW, "¡¡¡¡¡¡");		Draw(50, 3, BG_YELLOW, "¡¡¡¡¡¡");
	Draw(26, 4, BG_YELLOW, "¡¡¡¡¡¡");		Draw(50, 4, BG_YELLOW, "¡¡¡¡¡¡");

	Draw(26, 36, BG_YELLOW, "¡¡¡¡¡¡");		Draw(50, 36, BG_YELLOW, "¡¡¡¡¡¡");
	Draw(26, 37, BG_YELLOW, "¡¡¡¡¡¡");		Draw(50, 37, BG_YELLOW, "¡¡¡¡¡¡");
	Draw(26, 39, BG_YELLOW, "¡¡¡¡¡¡");		Draw(50, 39, BG_YELLOW, "¡¡¡¡¡¡");
	Draw(26, 40, BG_YELLOW, "¡¡¡¡¡¡");		Draw(50, 40, BG_YELLOW, "¡¡¡¡¡¡");

	Draw(0, 13, BG_YELLOW, "¡¡¡¡"); Draw(6, 13, BG_YELLOW, "¡¡¡¡");
	Draw(0, 14, BG_YELLOW, "¡¡¡¡"); Draw(6, 14, BG_YELLOW, "¡¡¡¡");
	Draw(0, 15, BG_YELLOW, "¡¡¡¡"); Draw(6, 15, BG_YELLOW, "¡¡¡¡");
	Draw(72, 13, BG_YELLOW, "¡¡¡¡"); Draw(78, 13, BG_YELLOW, "¡¡¡¡");
	Draw(72, 14, BG_YELLOW, "¡¡¡¡"); Draw(78, 14, BG_YELLOW, "¡¡¡¡");
	Draw(72, 15, BG_YELLOW, "¡¡¡¡"); Draw(78, 15, BG_YELLOW, "¡¡¡¡");

	Draw(0, 25, BG_YELLOW, "¡¡¡¡"); Draw(6, 25, BG_YELLOW, "¡¡¡¡");
	Draw(0, 26, BG_YELLOW, "¡¡¡¡"); Draw(6, 26, BG_YELLOW, "¡¡¡¡");
	Draw(0, 27, BG_YELLOW, "¡¡¡¡"); Draw(6, 27, BG_YELLOW, "¡¡¡¡");
	Draw(72, 25, BG_YELLOW, "¡¡¡¡"); Draw(78, 25, BG_YELLOW, "¡¡¡¡");
	Draw(72, 26, BG_YELLOW, "¡¡¡¡"); Draw(78, 26, BG_YELLOW, "¡¡¡¡");
	Draw(72, 27, BG_YELLOW, "¡¡¡¡"); Draw(78, 27, BG_YELLOW, "¡¡¡¡");


	//Å×µÎ¸®?
	/*
	Draw(0, 0, WHITE, "");
	textcolor(23);
	printf("¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á");
	Draw(0, 40, WHITE, "");
	textcolor(23);
	printf("¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á");
	*/


	/* Ãâ¹ß, ¿ï¸ªµµ, toÃâ¹ß, »õ¿ìÀâÀÌ */
	//Ãâ¹ß

	for (int i = 0; i < 5; i++) {
		Draw(0, i, BG_PURPLE, "¡¡¡¡¡¡¡¡¡¡");
		Draw(72, i, BG_PURPLE, "¡¡¡¡¡¡¡¡¡¡");
	}
	for (int i = 36; i < 41; i++) {
		Draw(0, i, BG_PURPLE, "¡¡¡¡¡¡¡¡¡¡");
		Draw(72, i, BG_PURPLE, "¡¡¡¡¡¡¡¡¡¡");
	}

	Draw(1, 1, BG_PURPLE, "START ¡æ");
	Draw(73, 1, BG_PURPLE, "¿ï ¸ª µµ");
	Draw(0, 37, BG_PURPLE, "¿ÀÂ¡¾îÀâÀÌ");
	Draw(0, 39, BG_PURPLE, "(¿ï¸ªµµ·Î)");
	Draw(73, 37, BG_PURPLE, "Ãâ¹ßÁö·Î");





	////////////////////* UIÅÇ ±×¸®±â *///////////////////////

	/* ÇÃ·¹ÀÌ¾î Á¤º¸ ÅÇ */

	// Player_1
	Draw(86, 1, BG_WHITE, "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"); // 15°³
	for (int i = 2; i < 9; i++) {
		Draw(86, i, BG_WHITE, "¡¡"); Draw(114, i, BG_WHITE, "¡¡");
	}
	Draw(86, 9, BG_WHITE, "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"); // 15°³
	Draw(90, 3, WHITE, "%s", a->name); Draw(110, 3, WHITE, "%d", a->around); // ÀÌ¸§ , ¹ÙÄû ¼ö Ãâ·Â
	Draw(90, 5, WHITE, "¼ÒÁö±Ý : %d ¾ï¿ø", a->money);
	Draw(90, 6, WHITE, "ÃÑÀÚ»ê : %d ¾ï¿ø", a->all_money);
	Draw(86, 1, BG_RED, "¡¡¡¡"); // À¯Àú »ö Ç¥½Ã
	Draw(86, 2, BG_RED, "¡¡¡¡");


	// Player_2
	Draw(86, 11, BG_WHITE, "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"); // 15°³
	for (int i = 12; i < 19; i++) {
		Draw(86, i, BG_WHITE, "¡¡"); Draw(114, i, BG_WHITE, "¡¡");
	}
	Draw(86, 19, BG_WHITE, "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"); // 15°³
	Draw(90, 13, WHITE, "%s", b->name); Draw(110, 13, WHITE, "%d", b->around); // ÀÌ¸§ , ¹ÙÄû ¼ö Ãâ·Â
	Draw(90, 15, WHITE, "¼ÒÁö±Ý : %d ¾ï¿ø", b->money);
	Draw(90, 16, WHITE, "ÃÑÀÚ»ê : %d ¾ï¿ø", b->all_money);
	Draw(86, 11, BG_BLUE, "¡¡¡¡"); // À¯Àú »ö Ç¥½Ã
	Draw(86, 12, BG_BLUE, "¡¡¡¡");

	// Player_3
	Draw(86, 21, BG_WHITE, "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"); // 15°³
	for (int i = 22; i < 29; i++) {
		Draw(86, i, BG_WHITE, "¡¡"); Draw(114, i, BG_WHITE, "¡¡");
	}
	Draw(86, 29, BG_WHITE, "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"); // 15°³
	Draw(90, 23, WHITE, "%s", c->name); Draw(110, 23, WHITE, "%d", c->around); // ÀÌ¸§ , ¹ÙÄû ¼ö Ãâ·Â
	Draw(90, 25, WHITE, "¼ÒÁö±Ý : %d ¾ï¿ø", c->money);
	Draw(90, 26, WHITE, "ÃÑÀÚ»ê : %d ¾ï¿ø", c->all_money);
	Draw(86, 21, BG_SKYBLUE, "¡¡¡¡"); // À¯Àú »ö Ç¥½Ã
	Draw(86, 22, BG_SKYBLUE, "¡¡¡¡");

	// Player_4
	Draw(86, 31, BG_WHITE, "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"); // 15°³
	for (int i = 32; i < 39; i++) {
		Draw(86, i, BG_WHITE, "¡¡"); Draw(114, i, BG_WHITE, "¡¡");
	}
	Draw(86, 39, BG_WHITE, "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"); // 15°³
	Draw(90, 33, WHITE, "%s", d->name); Draw(110, 33, WHITE, "%d", d->around); // ÀÌ¸§ , ¹ÙÄû ¼ö Ãâ·Â
	Draw(90, 35, WHITE, "¼ÒÁö±Ý : %d ¾ï¿ø", d->money);
	Draw(90, 36, WHITE, "ÃÑÀÚ»ê : %d ¾ï¿ø", d->all_money);
	Draw(86, 31, BG_GREEN, "¡¡¡¡"); // À¯Àú »ö Ç¥½Ã
	Draw(86, 32, BG_GREEN, "¡¡¡¡");

	/* Ãß°¡ ±â´É ÅÇ 
	Draw(120, 2, BG_WHITE, "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡");
	Draw(120, 3, BG_WHITE, "¡¡");										Draw(140, 3, BG_WHITE, "¡¡");
	Draw(120, 4, BG_WHITE, "¡¡"); Draw(128, 4, WHITE, "µ¹¾Æ°¡±â");		Draw(140, 4, BG_WHITE, "¡¡");
	Draw(120, 5, BG_WHITE, "¡¡");										Draw(140, 5, BG_WHITE, "¡¡");
	Draw(120, 6, BG_WHITE, "¡¡"); Draw(128, 6, WHITE, "¶¥ Á¤º¸");		Draw(140, 6, BG_WHITE, "¡¡");
	Draw(120, 7, BG_WHITE, "¡¡");										Draw(140, 7, BG_WHITE, "¡¡");
	Draw(120, 8, BG_WHITE, "¡¡"); Draw(128, 8, WHITE, "ÀÚµ¿ ÁøÇà");		Draw(140, 8, BG_WHITE, "¡¡");
	Draw(120, 9, BG_WHITE, "¡¡");										Draw(140, 9, BG_WHITE, "¡¡");
	Draw(120, 10, BG_WHITE, "¡¡"); Draw(128, 10, WHITE, "°ÔÀÓ Á¾·á");	Draw(140, 10, BG_WHITE, "¡¡");
	Draw(120, 11, BG_WHITE, "¡¡");										Draw(140, 11, BG_WHITE, "¡¡");
	Draw(120, 12, BG_WHITE, "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡");
*/
}


void print_area_ui(void)
{
	Draw(120, 2, WHITE, "¡á¡á¡á¡¡¡á¡á¡¡¡á¡á¡á");
	Draw(126, 2, YELLOW, "¡á"); Draw(132, 2, YELLOW, "¡á");
	Draw(120, 3, WHITE, "¡á");										Draw(138, 3, WHITE, "¡á");
	Draw(120, 4, WHITE, "¡á");										Draw(138, 4, WHITE, "¡á");
	Draw(120, 5, YELLOW, "¡á");										Draw(138, 5, YELLOW, "¡á");
	Draw(120, 6, WHITE, "¡á");										Draw(138, 6, WHITE, "¡á");
	Draw(120, 7, WHITE, "¡á");										Draw(138, 7, WHITE, "¡á");
	Draw(120, 8, YELLOW, "¡á");										Draw(138, 8, YELLOW, "¡á");
	Draw(120, 9, WHITE, "¡á");										Draw(138, 9, WHITE, "¡á");
	Draw(120, 10, WHITE, "¡á");										Draw(138, 10, WHITE, "¡á");
	Draw(120, 11, WHITE, "¡á¡á¡á¡¡¡á¡á¡¡¡á¡á¡á");
	Draw(126, 11, YELLOW, "¡á"); Draw(132, 11, YELLOW, "¡á");
}

//À¯ÀúÀÇ À§Ä¡ . ¼ÒÁö±Ý º¯µ¿ . ¾÷±×·¹ÀÌµå »óÅÂ
void user_pos(struct fields *f)
{
	struct PLAYER *a;
	struct PLAYER *b;
	struct PLAYER *c;
	struct PLAYER *d;

	a = &user;
	b = &com1;
	c = &com2;
	d = &com3;
	

	//¶¥ À§Ä¡ Å½»ö
	for (int i = 0; i < 36; i++) {
		//À¯Àú Á¡ Âï±â

		//user1
		if (a->where == i) {
			if (i >= 0 && i <= 8) {
				Draw(4 + (i * 8), 2, a->color, "¡á");
			}
			else if (i >= 9 && i <= 17) {
				Draw(76, 1 + (1 + (i - 9) * 4), a->color, "¡á");
			}
			else if (i >= 18 && i <= 26) {
				Draw(76 - ((i - 18) * 8), 38, a->color, "¡á");
			}
			else if (i >= 27 && i <= 35) {
				Draw(4, 38 - (i - 27) * 4, a->color, "¡á");
			}
		}

		//user2
		if (b->where == i) {
			if (i >= 0 && i <= 8) {
				switch (f[i].on) {
				case 1:
					Draw(4 + (i * 8), 2, b->color, "¡á");
					break;
				default:
					Draw(2 + (i * 8), 2, b->color, "¡á");
					break;
				}

			}
			else if (i >= 9 && i <= 17) {
				switch (f[i].on) {
				case 1:
					Draw(76, 1 + (1 + (i - 9) * 4), b->color, "¡á");
					break;
				default:
					if (i == 12 || i == 15)
						Draw(76, (1 + (i - 9) * 4), b->color, "¡á");
					else
						Draw(74, 1 + (1 + (i - 9) * 4), b->color, "¡á");
					break;
				}
			}

			else if (i >= 18 && i <= 26) {
				switch (f[i].on) {
				case 1:
					Draw(76 - ((i - 18) * 8), 38, b->color, "¡á");
					break;
				default:
					Draw(74 - ((i - 18) * 8), 38, b->color, "¡á");
					break;
				}
			}
			else if (i >= 27 && i <= 35) {
				switch (f[i].on) {
				case 1:
					Draw(4, 38 - (i - 27) * 4, b->color, "¡á");
					break;
				default:
					if (i == 30 || i == 33)
						Draw(4, 37 - (i - 27) * 4, b->color, "¡á");
					else
						Draw(2, 38 - (i - 27) * 4, b->color, "¡á");
					break;
				}

			}
		}


		//user3
		if (c->where == i) {
			if (i >= 0 && i <= 8) {
				switch (f[i].on) {
				case 1:
					Draw(4 + (i * 8), 2, c->color, "¡á");
					break;
				case 2:
					if (a->where == c->where) // ÇÃ·¹ÀÌ¾î1°ú À§Ä¡°¡ °°´Ù¸é
						Draw(2 + (i * 8), 2, c->color, "¡á");
					else // if ( b->where==c->where) // ÇÃ·¹ÀÌ¾î2~3¿Í À§Ä¡°¡ °°´Ù¸é
						Draw(4 + (i * 8), 2, c->color, "¡á");
					break;
				default: // ¼Â ÀÌ»óÀÌ¸é.
					Draw(6 + (i * 8), 2, c->color, "¡á");
					break;
				}

			}
			else if (i >= 9 && i <= 17) {
				switch (f[i].on) {
				case 1:
					Draw(76, 1 + (1 + (i - 9) * 4), c->color, "¡á");
					break;
				case 2:
					if (i == 12 || i == 15) { // Âù½º
						if (a->where == c->where) // ÇÃ·¹ÀÌ¾î1°ú ÀÚ¸®°¡ °°´Ù¸é
							Draw(76, (1 + (i - 9) * 4), c->color, "¡á");
						else // if ( b->where == c->where) // ÇÃ·¹ÀÌ¾î2¿Í ÀÚ¸®°¡ °°´Ù¸é
							Draw(76, 1 + (1 + (i - 9) * 4), c->color, "¡á");
					}
					else {
						if (a->where == c->where) // ÇÃ·¹ÀÌ¾î1°ú ÀÚ¸®°¡ °°´Ù¸é
							Draw(74, 1 + (1 + (i - 9) * 4), c->color, "¡á");
						else // if (b->where == c->where) // ÇÃ·¹ÀÌ¾î2¿Í ÀÚ¸®°¡ °°´Ù¸é
							Draw(76, 1 + (1 + (i - 9) * 4), c->color, "¡á");
					}
					break;
				default:
					if (i == 12 || i == 15)
						Draw(76, 2 + (1 + (i - 9) * 4), c->color, "¡á");
					else
						Draw(78, 1 + (1 + (i - 9) * 4), c->color, "¡á");
					break;
				}
			}

			else if (i >= 18 && i <= 26) {
				switch (f[i].on) {
				case 1:
					Draw(76 - ((i - 18) * 8), 38, c->color, "¡á");
					break;
				case 2:
					if (a->where == c->where)
						Draw(74 - ((i - 18) * 8), 38, c->color, "¡á");
					else // if ( b->where == c->where)
						Draw(76 - ((i - 18) * 8), 38, c->color, "¡á");
					break;
				default:
					Draw(78 - ((i - 18) * 8), 38, c->color, "¡á");
					break;
				}
			}
			else if (i >= 27 && i <= 35) {
				switch (f[i].on) {
				case 1:
					Draw(4, 38 - (i - 27) * 4, c->color, "¡á");
					break;
				case 2:
					if (i == 30 || i == 33) { // Âù½º
						if (a->where == c->where)
							Draw(4, 37 - (i - 27) * 4, c->color, "¡á");
						else // if (b->where == c->where)
							Draw(4, 38 - (i - 27) * 4, c->color, "¡á");
					}
					else {
						if (a->where == c->where)
							Draw(2, 38 - (i - 27) * 4, c->color, "¡á");
						else // if (b->where == c->where)
							Draw(4, 38 - (i - 27) * 4, c->color, "¡á");
					}
					break;
				default:
					if (i == 30 || i == 33) // Âù½º
						Draw(4, 39 - (i - 27) * 4, c->color, "¡á");
					else
						Draw(6, 38 - (i - 27) * 4, c->color, "¡á");
					break;
				}

			}
		}


		//user4
		if (d->where == i) {
			if (i >= 0 && i <= 8) {
				switch (f[i].on) {
				case 1:
					Draw(4 + (i * 8), 2, d->color, "¡á");
					break;
				case 2:
					if (d->where == a->where) // ÇÃ·¹ÀÌ¾î1°ú À§Ä¡°¡ °°´Ù¸é
						Draw(2 + (i * 8), 2, d->color, "¡á");
					else if (d->where == b->where) // ÇÃ·¹ÀÌ¾î2¿Í À§Ä¡°¡ °°´Ù¸é
						Draw(4 + (i * 8), 2, d->color, "¡á");
					else if (d->where == c->where) // ÇÃ·¹ÀÌ¾î3°ú À§Ä¡°¡ °°´Ù¸é
						Draw(2 + (i * 8), 2, d->color, "¡á");

					break;
				case 3:
					if (d->where != a->where)
						Draw(4 + (i * 8), 2, d->color, "¡á");
					else if (d->where != b->where)
						Draw(2 + (i * 8), 2, d->color, "¡á");
					else if (d->where != c->where)
						Draw(6 + (i * 8), 2, d->color, "¡á");
					break;
				case 4: // 4¸íÀÌ ºÙ¾îÀÖÀ¸¸é. ±Ø´ÜÀûÀ¸·Î À¯ÀúµéÀ» Âï¾î³¿.
					Draw(2 + (i * 8), 2, RED, "¡á");
					Draw(4 + (i * 8), 2, BG_BLUE, " ");
					Draw(5 + (i * 8), 2, BG_GREEN, " ");
					Draw(6 + (i * 8), 2, SKYBLUE, "¡á");
					break;
				}
			}

			else if (i >= 9 && i <= 17) {
				switch (f[i].on) {
				case 1:
					Draw(76, 1 + (1 + (i - 9) * 4), d->color, "¡á");
					break;
				case 2:
					if (i == 12 || i == 15) { // Âù½º
						if (a->where == d->where) // ÇÃ·¹ÀÌ¾î1°ú ÀÚ¸®°¡ °°´Ù¸é
							Draw(76, (1 + (i - 9) * 4), d->color, "¡á");
						else if (b->where == d->where) // ÇÃ·¹ÀÌ¾î2¿Í ÀÚ¸®°¡ °°´Ù¸é
							Draw(76, 1 + (1 + (i - 9) * 4), d->color, "¡á");
						else if (c->where == d->where) // ÇÃ·¹ÀÌ¾î3°ú ÀÚ¸®°¡ °°´Ù¸é
							Draw(76, (1 + (i - 9) * 4), d->color, "¡á");
					}
					else {
						if (a->where == d->where) // ÇÃ·¹ÀÌ¾î1°ú ÀÚ¸®°¡ °°´Ù¸é
							Draw(74, 1 + (1 + (i - 9) * 4), d->color, "¡á");
						else if (b->where == d->where) // ÇÃ·¹ÀÌ¾î2¿Í ÀÚ¸®°¡ °°´Ù¸é
							Draw(76, 1 + (1 + (i - 9) * 4), d->color, "¡á");
						else if (c->where == d->where) // ÇÃ·¹ÀÌ¾î3°ú ÀÚ¸®°¡ °°´Ù¸é
							Draw(74, 1 + (1 + (i - 9) * 4), d->color, "¡á");
					}
					break;

				case 3:
					if (i == 12 || i == 15) {
						if (d->where != a->where)
							Draw(76, 1 + (1 + (i - 9) * 4), d->color, "¡á");
						else if (d->where != b->where)
							Draw(76, (1 + (i - 9) * 4), d->color, "¡á");
						else if (d->where != c->where)
							Draw(76, 2 + (1 + (i - 9) * 4), d->color, "¡á");
					}
					else {
						if (d->where != a->where)
							Draw(76, 1 + (1 + (i - 9) * 4), d->color, "¡á");
						else if (d->where != b->where)
							Draw(74, 1 + (1 + (i - 9) * 4), d->color, "¡á");
						else if (d->where != c->where)
							Draw(78, 1 + (1 + (i - 9) * 4), d->color, "¡á");
					}
					break;

				case 4:
					if (i == 12 || i == 15) { // Âù½º
							Draw(76, (1 + (i - 9) * 4), RED, "¡á");
							Draw(76, 1 + (1 + (i - 9) * 4), BG_BLUE, " ");
							Draw(77, 1 + (1 + (i - 9) * 4), BG_GREEN, " ");
							Draw(76, 2 + (1 + (i - 9) * 4), SKYBLUE, "¡á");
					}
					else {
							Draw(74, 1 + (1 + (i - 9) * 4), RED, "¡á");
							Draw(76, 1 + (1 + (i - 9) * 4), BG_BLUE, " ");
							Draw(77, 1 + (1 + (i - 9) * 4), BG_GREEN, " ");
							Draw(78, 1 + (1 + (i - 9) * 4), SKYBLUE, "¡á");
					}
					break;
				}
			}

			else if (i >= 18 && i <= 26) {
				switch (f[i].on) {
				case 1:
					Draw(76 - ((i - 18) * 8), 38, d->color, "¡á");
					break;
				case 2:
					if (d->where == a->where)
						Draw(74 - ((i - 18) * 8), 38, d->color, "¡á");
					else if (d->where == b->where)
						Draw(76 - ((i - 18) * 8), 38, d->color, "¡á");
					else if (d->where == c->where)
						Draw(74 - ((i - 18) * 8), 38, d->color, "¡á");
					break;
				case 3:
					if (d->where != a->where)
						Draw(76 - ((i - 18) * 8), 38, d->color, "¡á");
					else if (d->where != b->where)
						Draw(74 - ((i - 18) * 8), 38, d->color, "¡á");
					else if (d->where != c->where)
						Draw(78 - ((i - 18) * 8), 38, d->color, "¡á");
					break;
				case 4:
					Draw(74 - ((i - 18) * 8), 38, RED, "¡á");
					Draw(76 - ((i - 18) * 8), 38, BG_BLUE, " ");
					Draw(77 - ((i - 18) * 8), 38, BG_GREEN, " ");
					Draw(78 - ((i - 18) * 8), 38, SKYBLUE, "¡á");
				}
			}
			else if (i >= 27 && i <= 35) {
				switch (f[i].on) {
				case 1:
					Draw(4, 38 - (i - 27) * 4, d->color, "¡á");
					break;
				case 2:
					if (i == 30 || i == 33) { // Âù½º
						if (a->where == d->where)
							Draw(4, 37 - (i - 27) * 4, d->color, "¡á");
						else if (b->where == d->where)
							Draw(4, 38 - (i - 27) * 4, d->color, "¡á");
						else if (c->where == d->where)
							Draw(4, 37 - (i - 27) * 4, d->color, "¡á");
					}
					else {
						if (d->where == a->where)
							Draw(2, 38 - (i - 27) * 4, d->color, "¡á");
						else if (d->where == b->where)
							Draw(4, 38 - (i - 27) * 4, d->color, "¡á");
						else if (d->where == c->where)
							Draw(2, 38 - (i - 27) * 4, d->color, "¡á");
					}
					break;
				case 3: // 3¸íÀÌ °ãÄ¡¸é
					if (i == 30 || i == 33) { // Âù½º
						if (d->where != a->where)
							Draw(4, 38 - (i - 27) * 4, d->color, "¡á");
						else if (d->where != b->where)
							Draw(4, 37 - (i - 27) * 4, d->color, "¡á");
						else if (d->where != c->where)
							Draw(4, 39 - (i - 27) * 4, d->color, "¡á");
					}
					else {
						if (d->where != a->where)
							Draw(4, 38 - (i - 27) * 4, d->color, "¡á");
						else if (d->where != b->where)
							Draw(2, 38 - (i - 27) * 4, d->color, "¡á");
						else if (d->where != c->where)
							Draw(6, 38 - (i - 27) * 4, d->color, "¡á");
					}
					break;
				case 4:
					if (i == 30 || i == 33) { // Âù½º
						Draw(4, 37 - (i - 27) * 4, RED, "¡á");
						Draw(4, 38 - (i - 27) * 4, BG_BLUE, " ");
						Draw(5, 38 - (i - 27) * 4, BG_GREEN, " ");
						Draw(4, 39 - (i - 27) * 4, SKYBLUE, "¡á");
					}
					else {
						Draw(2, 38 - (i - 27) * 4, RED, "¡á");
						Draw(4, 38 - (i - 27) * 4, BG_BLUE, " ");
						Draw(5, 38 - (i - 27) * 4, BG_GREEN, " ");
						Draw(6, 38 - (i - 27) * 4, SKYBLUE, "¡á");
					}
				}

			}
		}
	}

	//////////////////// ¼ÒÁö±Ý º¯µ¿ Ãâ·Â /////////////////////
	// player 1
	Draw(110, 3, WHITE, "%d", a->around); // ¸î ¹ÙÄû µ¹¾Ò´Â°¡
	Draw(90, 5, WHITE, "¼ÒÁö±Ý : %d ¾ï¿ø", a->money);
	Draw(90, 6, WHITE, "ÃÑÀÚ»ê : %d ¾ï¿ø", a->all_money);
	// player 2
	Draw(110, 13, WHITE, "%d", b->around); // ¸î ¹ÙÄû µ¹¾Ò´Â°¡
	Draw(90, 15, WHITE, "¼ÒÁö±Ý : %d ¾ï¿ø", b->money);
	Draw(90, 16, WHITE, "ÃÑÀÚ»ê : %d ¾ï¿ø", b->all_money);
	// player 3
	Draw(110, 23, WHITE, "%d", c->around); // ¸î ¹ÙÄû µ¹¾Ò´Â°¡
	Draw(90, 25, WHITE, "¼ÒÁö±Ý : %d ¾ï¿ø", c->money);
	Draw(90, 26, WHITE, "ÃÑÀÚ»ê : %d ¾ï¿ø", c->all_money);
	// player 4
	Draw(110, 33, WHITE, "%d", d->around); // ¸î ¹ÙÄû µ¹¾Ò´Â°¡
	Draw(90, 35, WHITE, "¼ÒÁö±Ý : %d ¾ï¿ø", d->money);
	Draw(90, 36, WHITE, "ÃÑÀÚ»ê : %d ¾ï¿ø", d->all_money);

}

void erase_pos(struct fields *f)
{
	struct PLAYER *a;
	struct PLAYER *b;
	struct PLAYER *c;
	struct PLAYER *d;

	a = &user;
	b = &com1;
	c = &com2;
	d = &com3;

	//¶¥ À§Ä¡ Å½»ö
	for (int i = 0; i < 36; i++) {

		//user1

		if (i == 0)
			Draw(2 + (i * 8), 2, BG_PURPLE, "¡¡¡¡¡¡");

		else if ((i > 0 && i <= 8)) {
			Draw(2 + (i * 8), 2, RED, "¡¡¡¡¡¡");
		}

		else if (i == 9)
			Draw(74, 1 + (1 + (i - 9) * 4), BG_PURPLE, "¡¡¡¡¡¡");

		else if (i >= 10 && i <= 11) {
			Draw(74, 1 + (1 + (i - 9) * 4), RED, "¡¡¡¡¡¡");
		}

		else if (i == 12) {
			Draw(76, (1 + (i - 9) * 4), RED, "¡¡");
			Draw(76, 1 + (1 + (i - 9) * 4), RED, "¡¡");
			Draw(76, 2 + (1 + (i - 9) * 4), RED, "¡¡");
		}

		else if (i >= 13 && i <= 14) {
			Draw(74, 1 + (1 + (i - 9) * 4), RED, "¡¡¡¡¡¡");
		}

		else if (i == 15) {
			Draw(76, (1 + (i - 9) * 4), RED, "¡¡");
			Draw(76, 1 + (1 + (i - 9) * 4), RED, "¡¡");
			Draw(76, 2 + (1 + (i - 9) * 4), RED, "¡¡");
		}

		else if (i >= 16 && i <= 17) {
			Draw(74, 1 + (1 + (i - 9) * 4), RED, "¡¡¡¡¡¡");
		}
		else if (i == 18)
			Draw(74, 1 + (1 + (i - 9) * 4), BG_PURPLE, "¡¡¡¡¡¡");

		else if (i > 18 && i <= 26) {
			Draw(66 - ((i - 19) * 8), 38, GREEN, "¡¡¡¡¡¡");
		}

		else if (i == 27)
			Draw(66 - ((i - 19) * 8), 38, BG_PURPLE, "¡¡¡¡¡¡");

		else if (i == 30 || i == 33) {
			Draw(4, 35 - (i - 28) * 4, RED, "¡¡");
			Draw(4, 34 - (i - 28) * 4, RED, "¡¡");
			Draw(4, 33 - (i - 28) * 4, RED, "¡¡");
		}
		else if (i > 27 && i <= 35) {
			Draw(2, 34 - (i - 28) * 4, RED, "¡¡¡¡¡¡");
		}
	}




	////////////////////////// ¼ÒÁö±Ý Á¶Á¤À» À§ÇØ ±âÁ¸Ãâ·ÂµÈ ¼ÒÁö±Ý »èÁ¦ //////////////////////////////
	Draw(88, 5, WHITE, "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡");
	Draw(88, 6, WHITE, "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡");
	// player 2
	Draw(88, 15, WHITE, "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡");
	Draw(88, 16, WHITE, "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡");
	// player 3
	Draw(88, 25, WHITE, "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡");
	Draw(88, 26, WHITE, "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡");
	// player 4
	Draw(88, 35, WHITE, "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡");
	Draw(88, 36, WHITE, "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡");
}


void move_pos(struct fields *f, struct PLAYER *who)
{
	int move_c = dice1 + dice2; // ÁÖ»çÀ§ ´«±ÝÀÇ ÇÕÀ» ÀÐ¾î¿È

	for (int i = 0; i < move_c; i++) { //
		erase_pos(f); // ±âÁ¸ Á¡À» Áö¿ò
		
		f[who->where].on--; // ±âÁ¸¿¡ ÀÖ´ø ¶¥¿¡¼­ À¯Àú¸¦ »©³¿
		who->where++; // ´ÙÀ½¹øÂ° Ä­À¸·Î À¯ÀúÀÇ À§Ä¡¸¦ ÀÌµ¿

		if (who->where > 35) {
			who->around++;
			who->where -= 36;
			Draw(20, 22, YELLOW, "%s´ÔÀÌ ÇÑ ¹ÙÄû¸¦ µ¹¾Æ", who->name);
			Draw(20, 23, YELLOW, "100¾ï¿øÀÌ Áö±ÞµË´Ï´Ù.");
			who->money += 100;
			who->all_money += 100;
			f[who->where].on++; // »õ·Î¿î ¶¥¿¡ À¯Àú°¡ Á¸ÀçÇÔÀ» ¾Ë¸²
			user_pos(f); // °¡°Ý º¯µ¿À» Ãâ·Â (+Á¡µµ »õ·ÎÀÌ ÂïÀ½)
			Timer(3.0);
			continue;
		}
		f[who->where].on++; // »õ·Î¿î ¶¥¿¡ À¯Àú°¡ Á¸ÀçÇÔÀ» ¾Ë¸²

		user_pos(f); // »õ·ÎÀÌ Á¡À» ÂïÀ½
		
		Timer(0.2);
	}
}


void Check_Whose_Area(struct fields *f, struct PLAYER *who)
{
	// ÇØ´ç ¶¥ÀÇ ¼ÒÀ¯±Ç Ç¥½Ã
	int color;
	if (who->who == 1) color = BG_RED;
	else if (who->who == 2) color = BG_BLUE;
	else if (who->who == 3) color = BG_SKYBLUE;
	else if (who->who == 4) color = BG_GREEN;

	int i = who->where;

	if ((i > 0 && i <= 8)) {
		Draw(2 + (i * 8), 4, color, "¡¡¡¡¡¡");
	}

	else if (i >= 10 && i <= 17) {
		Draw(72, (1 + (i - 9) * 4), color, "¡¡");
		Draw(72, 1 + (1 + (i - 9) * 4), color, "¡¡");
		Draw(72, 2 + (1 + (i - 9) * 4), color, "¡¡");
	}

	else if (i > 18 && i <= 26) {
		Draw(66 - ((i - 19) * 8), 36, color, "¡¡¡¡¡¡");
	}

	else if (i > 27 && i <= 35) {
		Draw(8, 35 - (i - 28) * 4, color, "¡¡");
		Draw(8, 34 - (i - 28) * 4, color, "¡¡");
		Draw(8, 33 - (i - 28) * 4, color, "¡¡");
	}



	//ÇØ´ç ¶¥ÀÇ ¾÷±×·¹ÀÌµå »çÇ× Ç¥½Ã
	switch (f[who->where].upgrade_data) {

	case 3:

		if ((i > 0 && i <= 8)) {
			Draw(6 + (i * 8), 3, GREEN, "¡ã");
		}

		else if (i >= 10 && i <= 17) {
			Draw(78, 2 + (1 + (i - 9) * 4), GREEN, "¡ã");
		}

		else if (i > 18 && i <= 26) {
			Draw(70 - ((i - 19) * 8), 39, GREEN, "¡ã");
		}

		else if (i > 27 && i <= 35) {
			Draw(6, 35 - (i - 28) * 4, GREEN, "¡ã");
		}
	

	case 2:

		if ((i > 0 && i <= 8)) {
			Draw(4+(i * 8), 3, GREEN, "¡ã");
		}

		else if (i >= 10 && i <= 17) {
			Draw(76, 2 + (1 + (i - 9) * 4), GREEN, "¡ã");
		}

		else if (i > 18 && i <= 26) {
			Draw(68 - ((i - 19) * 8), 39, GREEN, "¡ã");
		}

		else if (i > 27 && i <= 35) {
			Draw(4, 35 - (i - 28) * 4, GREEN, "¡ã");
		}

	case 1:

		if ((i > 0 && i <= 8)) {
			Draw(2+(i * 8), 3, GREEN, "¡ã");
		}

		else if (i >= 10 && i <= 17) {
			Draw(74, 2 + (1 + (i - 9) * 4), GREEN, "¡ã");
		}

		else if (i > 18 && i <= 26) {
			Draw(66 - ((i - 19) * 8), 39, GREEN, "¡ã");
		}

		else if (i > 27 && i <= 35) {
			Draw(2, 35 - (i - 28) * 4, GREEN, "¡ã");
		}
		break;

	case 4:
		if ((i > 0 && i <= 8)) {
			Draw(2+(i * 8), 3, YELLOW, "¡Ú¡Ú¡Ú");
		}

		else if (i >= 10 && i <= 17) {
			Draw(74, 2 + (1 + (i - 9) * 4), YELLOW, "¡Ú¡Ú¡Ú");
		}

		else if (i > 18 && i <= 26) {
			Draw(66 - ((i - 19) * 8), 39, YELLOW, "¡Ú¡Ú¡Ú");
		}

		else if (i > 27 && i <= 35) {
			Draw(2, 35 - (i - 28) * 4, YELLOW, "¡Ú¡Ú¡Ú");
		}
	}
	
	
}

//¶¥ÀÇ Á¤º¸µéÀ» º¸¿©ÁÜ. ( °¡°Ý, ÅëÇà·á µî)
void Area_stat(struct fields *f, struct PLAYER *who)
{


	///////////////////////// ÇöÀç ¶¥¿¡ ´ëÇÑ Á¤º¸ ///////////////////////////

	// ¶¥ÀÌ¸§, ¶¥°ª, ÅëÇà·á(+0, +1, +2, +3, +4), ¾÷±×·¹ÀÌµåºñ¿ë, ÀÎ¼öºñ¿ë, ÇÑÁÙ¼³¸í?

	Draw(14, 7, WHITE, "¦Ç¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦Á");
	Draw(14, 8, WHITE, "¦­"); Draw(21, 8, WHITE, "< %s >", f[who->where].region_name); Draw(38, 8, WHITE, "¦­");
	Draw(14, 9, WHITE, "¦­"); Draw(16, 9, WHITE, "¶¥ °ª: %d¾ï¿ø", f[who->where].area_pay); Draw(38, 9, WHITE, "¦­");
	Draw(14, 10, WHITE, "¦­"); Draw(21, 11, WHITE, "< ÅëÇà·á >"); Draw(38, 10, WHITE, "¦­");
	Draw(14, 11, WHITE, "¦­"); Draw(16, 12, WHITE, "+0: %d¾ï¿ø", f[who->where].area_pay / 5);  Draw(38, 11, WHITE, "¦­");
	Draw(14, 12, WHITE, "¦­"); Draw(16, 13, WHITE, "+1: %d¾ï¿ø", f[who->where].area_pay / 2); Draw(38, 12, WHITE, "¦­");
	Draw(14, 13, WHITE, "¦­"); Draw(16, 14, WHITE, "+2: %.0f¾ï¿ø", f[who->where].area_pay * 1.5); Draw(38, 13, WHITE, "¦­");
	Draw(14, 14, WHITE, "¦­"); Draw(16, 15, WHITE, "+3: %d¾ï¿ø", f[who->where].area_pay * 2); Draw(38, 14, WHITE, "¦­");
	Draw(14, 15, WHITE, "¦­"); Draw(16, 16, WHITE, "+4: %d¾ï¿ø", f[who->where].area_pay * 4); Draw(38, 15, WHITE, "¦­");
	Draw(14, 16, WHITE, "¦­"); Draw(16, 17, WHITE, "¾÷±×·¹ÀÌµå ºñ¿ë: %d¾ï¿ø", f[who->where].area_pay / 6); Draw(38, 16, WHITE, "¦­");
	Draw(14, 17, WHITE, "¦­");Draw(38, 17, WHITE, "¦­");
	Draw(14, 18, WHITE, "¦Å¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦Ã");
}

void throw_dice(int d1, int d2) {
	// x ÁÂÇ¥ - 54 ~ 80
	// y ÁÂÇ¥ - 5 ~

	//Draw(46, 6, BG_WHITE, "¡¡"); Draw(56, 6, BG_WHITE, "¡¡");
	//Timer(0.05);
	//Draw(46, 6, WHITE, "¡¡"); Draw(56, 6, WHITE, "¡¡");



	Draw(45, 9, BG_WHITE, "¡¡"); 
	Timer(0.1);
	pSystem->playSound(FMOD_CHANNEL_REUSE, pSound[Dice], false, &pChannel[1]);

	Draw(45, 9, WHITE, "¡¡"); Draw(64, 9, BG_WHITE, "¡¡"); 
	Draw(46, 12, BG_WHITE, "¡¡"); 
	Timer(0.1);

	Draw(46, 12, WHITE, "¡¡"); Draw(64, 9, WHITE, "¡¡");
	Draw(47, 15, BG_WHITE, "¡¡");  Draw(63, 12, BG_WHITE, "¡¡");
	Timer(0.1);
	Draw(47, 15, WHITE, "¡¡"); Draw(63, 12, WHITE, "¡¡");
	Draw(48, 13, BG_WHITE, "¡¡");  Draw(62, 15, BG_WHITE, "¡¡");
	Timer(0.1);


	Draw(48, 13, WHITE, "¡¡"); Draw(62, 15, WHITE, "¡¡"); 
	Draw(49, 14, BG_WHITE, "¡¡"); Draw(61, 13, BG_WHITE, "¡¡");
	Timer(0.1);
	Draw(49, 14, WHITE, "¡¡"); Draw(61, 13, WHITE, "¡¡");
	Draw(50, 15, BG_WHITE, "¡¡");  Draw(60, 14, BG_WHITE, "¡¡");
	Timer(0.1);
	Draw(50, 15, WHITE, "¡¡");  Draw(60, 14, WHITE, "¡¡");
	Draw(51, 14, BG_WHITE, "¡¡");  Draw(59, 15, BG_WHITE, "¡¡");
	Timer(0.1);
	Draw(51, 14, WHITE, "¡¡"); Draw(59, 15, WHITE, "¡¡");
	Draw(52, 15, BG_WHITE, "¡¡");  Draw(58, 14, BG_WHITE, "¡¡");
	Timer(0.1);
	Draw(58, 14, WHITE, "¡¡"); Draw(57, 15, BG_WHITE, "¡¡");
	Timer(0.3);
	Draw(50, 14, BG_WHITE, "¡¡¡¡");
	Draw(50, 15, BG_WHITE, "¡¡¡¡");

	Draw(57, 14, BG_WHITE, "¡¡¡¡");
	Draw(57, 15, BG_WHITE, "¡¡¡¡");
	Timer(0.1);
	Draw(48, 13, BG_WHITE, "¡¡¡¡¡¡");
	Draw(48, 14, BG_WHITE, "¡¡¡¡¡¡");
	Draw(48, 15, BG_WHITE, "¡¡¡¡¡¡");

	Draw(57, 13, BG_WHITE, "¡¡¡¡¡¡");
	Draw(57, 14, BG_WHITE, "¡¡¡¡¡¡");
	Draw(57, 15, BG_WHITE, "¡¡¡¡¡¡");
	Timer(0.1);
	Draw(46, 12, BG_WHITE, "¡¡¡¡¡¡¡¡");
	Draw(46, 13, BG_WHITE, "¡¡¡¡¡¡¡¡");
	Draw(46, 14, BG_WHITE, "¡¡¡¡¡¡¡¡");
	Draw(46, 15, BG_WHITE, "¡¡¡¡¡¡¡¡");

	Draw(57, 12, BG_WHITE, "¡¡¡¡¡¡¡¡");
	Draw(57, 13, BG_WHITE, "¡¡¡¡¡¡¡¡");
	Draw(57, 14, BG_WHITE, "¡¡¡¡¡¡¡¡");
	Draw(57, 15, BG_WHITE, "¡¡¡¡¡¡¡¡");
	Timer(0.1);
	Draw(44, 11, BG_WHITE, "¡¡¡¡¡¡¡¡¡¡");
	Draw(44, 12, BG_WHITE, "¡¡¡¡¡¡¡¡¡¡");
	Draw(44, 13, BG_WHITE, "¡¡¡¡¡¡¡¡¡¡");
	Draw(44, 14, BG_WHITE, "¡¡¡¡¡¡¡¡¡¡");
	Draw(44, 15, BG_WHITE, "¡¡¡¡¡¡¡¡¡¡");

	Draw(57, 11, BG_WHITE, "¡¡¡¡¡¡¡¡¡¡");
	Draw(57, 12, BG_WHITE, "¡¡¡¡¡¡¡¡¡¡");
	Draw(57, 13, BG_WHITE, "¡¡¡¡¡¡¡¡¡¡");
	Draw(57, 14, BG_WHITE, "¡¡¡¡¡¡¡¡¡¡");
	Draw(57, 15, BG_WHITE, "¡¡¡¡¡¡¡¡¡¡");

	switch (d1) {
	case 1:
		Draw(48, 13, BG_WHITE, "¡Ü");
		break;
	case 2:
		Draw(46, 13, BG_WHITE, "¡Ü");
		Draw(50, 13, BG_WHITE, "¡Ü");
		break;
	case 3:
		Draw(46, 12, BG_WHITE, "¡Ü");
		Draw(48, 13, BG_WHITE, "¡Ü");
		Draw(50, 14, BG_WHITE, "¡Ü");
		break;
	case 4:
		Draw(46, 12, BG_WHITE, "¡Ü");
		Draw(50, 12, BG_WHITE, "¡Ü");
		Draw(46, 14, BG_WHITE, "¡Ü");
		Draw(50, 14, BG_WHITE, "¡Ü");
		break;
	case 5:
		Draw(46, 12, BG_WHITE, "¡Ü");
		Draw(50, 12, BG_WHITE, "¡Ü");
		Draw(48, 13, BG_WHITE, "¡Ü");
		Draw(46, 14, BG_WHITE, "¡Ü");
		Draw(50, 14, BG_WHITE, "¡Ü");
		break;
	case 6:
		Draw(46, 12, BG_WHITE, "¡Ü");
		Draw(50, 12, BG_WHITE, "¡Ü");
		Draw(46, 13, BG_WHITE, "¡Ü");
		Draw(50, 13, BG_WHITE, "¡Ü");
		Draw(46, 14, BG_WHITE, "¡Ü");
		Draw(50, 14, BG_WHITE, "¡Ü");
		break;
	}

	switch (d2) {
	case 1:
		Draw(61, 13, BG_WHITE, "¡Ü");
		break;
	case 2:
		Draw(59, 13, BG_WHITE, "¡Ü");
		Draw(63, 13, BG_WHITE, "¡Ü");
		break;
	case 3:
		Draw(59, 12, BG_WHITE, "¡Ü");
		Draw(61, 13, BG_WHITE, "¡Ü");
		Draw(63, 14, BG_WHITE, "¡Ü");
		break;
	case 4:
		Draw(59, 12, BG_WHITE, "¡Ü");
		Draw(63, 12, BG_WHITE, "¡Ü");
		Draw(59, 14, BG_WHITE, "¡Ü");
		Draw(63, 14, BG_WHITE, "¡Ü");
		break;
	case 5:
		Draw(59, 12, BG_WHITE, "¡Ü");
		Draw(63, 12, BG_WHITE, "¡Ü");
		Draw(61, 13, BG_WHITE, "¡Ü");
		Draw(59, 14, BG_WHITE, "¡Ü");
		Draw(63, 14, BG_WHITE, "¡Ü");
		break;
	case 6:
		Draw(59, 12, BG_WHITE, "¡Ü");
		Draw(63, 12, BG_WHITE, "¡Ü");
		Draw(59, 13, BG_WHITE, "¡Ü");
		Draw(63, 13, BG_WHITE, "¡Ü");
		Draw(59, 14, BG_WHITE, "¡Ü");
		Draw(63, 14, BG_WHITE, "¡Ü");
		break;
	}


}

void erase_text(void) // ¾Ë¸²Ã¢ »èÁ¦
{
	// ¾Ë¸²Ã¢ »èÁ¦
	/// Âù½ººÎ »èÁ¦ ///
	Draw(14, 7, YELLOW, "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡");
	Draw(14, 8, YELLOW, "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡");
	Draw(14, 9, YELLOW, "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡");
	Draw(14, 10, YELLOW, "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡");
	Draw(14, 11, YELLOW, "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡");
	Draw(14, 12, YELLOW, "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡");
	Draw(14, 13, YELLOW, "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡");
	Draw(14, 14, YELLOW, "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡");
	Draw(14, 15, YELLOW, "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡");
	Draw(14, 16, YELLOW, "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡");
	Draw(14, 17, YELLOW, "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡");
	Draw(14, 18, YELLOW, "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡");

	/// ÁÖ»çÀ§ »èÁ¦ ///
	Draw(44, 11, WHITE, "¡¡¡¡¡¡¡¡¡¡");
	Draw(44, 12, WHITE, "¡¡¡¡¡¡¡¡¡¡");
	Draw(44, 13, WHITE, "¡¡¡¡¡¡¡¡¡¡");
	Draw(44, 14, WHITE, "¡¡¡¡¡¡¡¡¡¡");
	Draw(44, 15, WHITE, "¡¡¡¡¡¡¡¡¡¡");

	Draw(57, 11, WHITE, "¡¡¡¡¡¡¡¡¡¡");
	Draw(57, 12, WHITE, "¡¡¡¡¡¡¡¡¡¡");
	Draw(57, 13, WHITE, "¡¡¡¡¡¡¡¡¡¡");
	Draw(57, 14, WHITE, "¡¡¡¡¡¡¡¡¡¡");
	Draw(57, 15, WHITE, "¡¡¡¡¡¡¡¡¡¡");

	///////////// ÇÃ·¹ÀÌ ÁøÇà ¼³¸í ¹®±¸µéÀ» ¸ðµÎ »èÁ¦ÇÔ ///////////////
	for (int i = 20; i < 33; i++) // 20~22 = Æ¯¼ö¹®±¸, 23 = ¾È³»¹®±¸ 24~32 = ÁøÇà¹®±¸
		Draw(13, i, WHITE, "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡");
}


void loading(void)
{
	system("cls"); // ÀÏ´ÜÈ­¸é Áö¿ì°í
	int k;


	Draw(36,14,WHITE,"B¡¡L¡¡U¡¡E¡¡¡¡M¡¡A¡¡R¡¡B¡¡L¡¡E");

	Draw(28, 16, WHITE, "¦®¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¯");
	
	Draw(28, 18, WHITE, "¦±¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦°");

	for (int i = 29; i <= 70;) {

		k = rand() % 2; // 0,1
		if (k == 0) {
			i++;
			Draw(i, 17, BG_GREEN, " ");
		}
		//Draw(29, 18, WHITE, ""); textcolor(0); printf(" ");
		Timer(0.03);
		//Timer(0.07);
	}
}