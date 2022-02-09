#include "endgame.h" /*tabe barresi payan yaftan bazi*/
#include <stdio.h>
#include <stdlib.h>
#include "graphics.h"
#include "board.h" /*tabe namayesh jadval gerafiki bazi*/

int endgame(int end[1], int black[1], int white[1], int pass[1], char cells[9][9], int playgame[1], int squarei[1], int squarej[1]) {
	if (end[0] == 0) { /*barresi payan yaftan yek dor bazi*/
		if (black[0] > white[0]) { /*moghayese emtiyaz har bazikon va namayesh peyam monaseb baraye barande */
			printf("\nThe BLACK player has won!\n");
			printf("Black: %d\nWhite: %d\n", black[0], white[0]);
		}
		if (black[0] < white[0]) {
			printf("\nThe White player has won!\n");
			printf("Black: %d\nWhite: %d\n", black[0], white[0]);
		}
		if (black[0] == white[0]) { /*halat mosavi shodan bazi va namayesh peyam marbote*/
			printf("\n The game is over!\n No one has won the game.\n");
			printf("Black: %d\nWhite: %d\n", black[0], white[0]);
		}
	}

	if (end[0] == 0) { /*barresi darkhast bazi jadid ya khorooj az barname*/
		printf("\nPress 1 if you want to start a new game. Otherwise press 2. \n");
		int q;
		scanf_s("%d", &q);
		if (q == 1) { /*darkhast bazi jadid*/
			end[0] = 1; /*bargardandan moteghayyer haye lazem baraye bazi jadid be halat avalieh*/
			pass[0] = 1;
			black[0] = 2, white[0] = 2;
			for (int i = 1;i < 9;i++) {
				for (int j = 1;j < 9;j++) {
					cells[i][j] = '.';
				}
			}
			cells[4][4] = 'w';
			cells[4][5] = 'b';
			cells[5][4] = 'b';
			cells[5][5] = 'w';
			
			for (int j = 1;j < 9;j++) { /*khali kardan jadval bazi az dayere ha*/
				for (int k = 1;k < 9;k++) {
					if (cells[k][j] == '.') {
						setcolor(COLOR(40, 110, 10));
						circle(50 + 100 * (j - 1), 50 + 100 * (k - 1), 49);
						setfillstyle(SOLID_FILL, COLOR(40, 110, 10));
						floodfill(50 + 100 * (j - 1), 50 + 100 * (k - 1), COLOR(40, 110, 10));
					}
				}
			}
			squarej[0] = 1;
			squarei[0] = 1;
			printf("\t\tOthello\n"); /*chap jadval bazi jadid*/
			printboard(cells, squarei, squarej);
		}
		if (q == 2) { /*darkhast khorooj az barname*/
			playgame[0] = 0;
		}
	}
	return 0;
}