#include <stdio.h>
#include <stdlib.h>
#include "graphics.h"
#include "board.h" /*tabe namayesh jadval gerafiki bazi*/
#include "get.h" /*tabe daryaft voroodi va jagozari aan va taghyir monaseb jadval ya    neshan dadan peyam haye marboot be sahih nabodan voroodi ya mojaz be entekhab naboodan*/
#include "endgame.h" /*tabe barresi payan yaftan bazi*/
#include "passturn.h" /*tabe barresi shart pass*/

int main()
{
	printf("\t\tOthello\n");
	int turn = 1; /*moteghayyer nobat*/
	int end[1] = { 1 }; /*moteghayyer payan yaftan bazi*/
	int playgame[1] = { 1 }; /*moteghayyer dar ejra bodan bazi*/
	int pass[1] = { 1 }; /*moteghayyer barresi shart pass*/
	int black[1] = { 2 }, white[1] = { 2 }; /*moteghayyer shomaresh emtiyaz har bazikon*/
	char cells[9][9]; /*moteghayyer haye khane haye jadval bazi*/
	for (int i = 0;i < 9;i++) { /*meghdar dehi avvaliyyeh moteghayyer haye khane haye jadval bazi */
		for (int j = 0;j < 9;j++) {
			cells[i][j] = '.';
		}
	}
	cells[4][4] = 'w';
	cells[4][5] = 'b';
	cells[5][4] = 'b';
	cells[5][5] = 'w';
	int squarei[1] = { 1 }; /*moteghayyer haye marboot be makane morabbaee abi*/
	int squarej[1] = { 1 };

	initwindow(810, 810, "Othello"); /*chape safheye gerafiki bazi*/
	setfillstyle(SOLID_FILL, COLOR(40, 110, 10));
	floodfill(150, 150, 1);

	while (playgame[0] == 1) { /*halghe jaryan bazi*/
		printboard(cells, squarei, squarej); /*tabe namayesh jadval bazi*/
		passturn(cells, turn, pass, end); /*tabe barresi shart pass*/
		endgame(end, black, white, pass, cells, playgame, squarei, squarej); /*tabe barresi payan yaftan bazi*/
		if (playgame[0] == 0) { /*dar jaryan nabodan bazi va darkhast khorooj az bazi*/
			break;
		}
		getinput(cells, turn, pass,black,white, squarei, squarej); /*tabe daryaft voroodi va jagozari aan va taghyir monaseb jadval ya    neshan dadan peyam haye marboot be sahih nabodan voroodi ya mojaz be entekhab naboodan*/

		black[0] = 0;
		white[0] = 0;
		for (int i = 1; i < 9; i++) { /*halghe shomaresh emtiaz haye har bazikon*/
			for (int j = 1; j < 9; j++) {
				if (cells[i][j] == 'b') {
					black[0] += 1;
				}
				else if (cells[i][j] == 'w') {
					white[0]++;
				}
			}
		}

		if ((black[0] + white[0]) == 64) { /*barresi payan yaftan yek dor bazi*/
			end[0] = 0;
		}

		if (turn == 1) /*taghyir nobat*/
			turn = 2;
		else
			turn = 1;

		if (end[0] == 0) { /*taghyir nobat dar halat payan yaftan yek dor bazi*/
			turn = 1;
		}
	}
	return 0;
}