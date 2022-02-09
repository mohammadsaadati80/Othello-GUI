#include "board.h" /*tabe namayesh jadval gerafiki bazi*/
#include <stdio.h>
#include <stdlib.h>
#include "graphics.h"

void printboard(char cells[9][9], int squarei[1], int squarej[1])
{
	setcolor(BLUE); /*chape khat haye sotoon va satre bazi*/
	for (int i = 1;i < 8;i++) {
		line(i * 100, 0, i * 100, 800);
		line(0, i * 100, 800, i * 100);
	}

	for (int j = 1;j < 9;j++) { /*chape dayere haye meshki*/
		for (int k = 1;k < 9;k++) {
			if (cells[k][j] == 'b') {
				setcolor(BLACK);
				circle(50 + 100 * (j - 1), 50 + 100 * (k - 1), 49);
				setfillstyle(SOLID_FILL, BLACK);
				floodfill(50 + 100 * (j - 1), 50 + 100 * (k - 1), BLACK);
			}
		}
	}
	for (int j = 1;j < 9;j++) { /*chape dayere haye sefid*/
		for (int k = 1;k < 9;k++) {
			if (cells[k][j] == 'w') {
				setcolor(WHITE);
				circle(50 + 100 * (j - 1), 50 + 100 * (k - 1), 49);
				setfillstyle(SOLID_FILL, WHITE);
				floodfill(50 + 100 * (j - 1), 50 + 100 * (k - 1), WHITE);
			}
		}
	}

	setcolor(BLUE); /*chape morabbae abi*/
	rectangle(30 + 100 * (squarej[0] - 1), 30 + 100 * (squarei[0] - 1), 70 + 100 * (squarej[0] - 1), 70 + 100 * (squarei[0] - 1));
	setfillstyle(SOLID_FILL, BLUE);
	floodfill(35 + 100 * (squarej[0] - 1), 35 + 100 * (squarei[0] - 1), BLUE);
}