#include "get.h" /*tabe daryaft voroodi va jagozari aan va taghyir monaseb jadval ya    neshan dadan peyam haye marboot be sahih nabodan voroodi ya mojaz be entekhab naboodan*/
#include <stdio.h>
#include <stdlib.h>
#include "graphics.h"
#include "board.h" /*tabe namayesh jadval gerafiki bazi*/

int getinput(char cells[9][9], int turn, int pass[1], int black[1], int white[1], int squarei[1], int squarej[1])
{
	char move = NULL; /*moteghayyer makane voroodi bazikon*/
	int change = 1; /*moteghayyer fahmidan taghyir yaftan jadval*/
	int a, b, c, d, e, f, g, h, i, j, k, l; /*moteghayyer haye marboot be harekat dar 8 jahat baraye khane entekhabi va teedad khane mojaz be taghyir jadval bazi dar har yek az 8 jahat*/
	int ch[8] = { 0,0,0,0,0,0,0,0 }; /*moteghayyer haye fahmidan anjam shodan har yek az shart haye harekhat dar 8 jahat*/
	char x, y; /*moteghayyer haye jagozari b va w ba tavajjoh be nobat*/
	int m = 0, n = 0; /*moteghayyer haye marboot be satr va sotoon makane voroodi tavassot bazikon*/
	while (pass[0] == 1) /*halghe kolli daryaft voroodi az bzikon va taghyir jadval*/
	{
		if ((move != '\n') && (pass[0] == 1)) {
			printf("\n[b=%d w=%d] \n", black[0], white[0]); /*namayesh emtiyaz haye har bazikon*/
			if (turn == 1) { /*jagozari x va y ba tavajjoh be nobat*/
				printf("BLACK player's turn:\n"); /*namayeshe peyghame monaseb baraye daryfte voroodi */
				x = 'b', y = 'w';
			}
			else if (turn == 2) {
				printf("WHITE player's turn:\n");
				x = 'w', y = 'b';
			}
		}
		move = getchar(); /*daryafte makane morede nazar az bazikon*/
		if (move != 'd'&& move != 's' && move != 'w' && move != 'a' && move != ' ' && move != '\n') { /*barresi sahih boodan makane voroodi*/
			printf("Invalid choice\n");
			continue;
		}
		if ( move == '\n') { 
			continue;
		}
		if (move == 'd') {
			setcolor(COLOR(40, 110, 10)); /*pak kardan makane morabbae ghabli*/
			rectangle(30 + 100 * (squarej[0] - 1), 30 + 100 * (squarei[0] - 1), 70 + 100 * (squarej[0] - 1), 70 + 100 * (squarei[0] - 1));
			setfillstyle(SOLID_FILL, COLOR(40, 110, 10));
			floodfill(35 + 100 * (squarej[0] - 1), 35 + 100 * (squarei[0] - 1), COLOR(40, 110, 10));
			squarej[0]++;
			if (squarej[0] == 9) { /*halati ke morabbae az safhe bazi kharej mishavad*/
				squarej[0] = 1;
			}
			change = 1;
			printboard(cells, squarei, squarej); /*chape jadval bazi*/
			continue;
		}
		if (move == 'a') {
			setcolor(COLOR(40, 110, 10)); /*pak kardan makane morabbae ghabli*/
			rectangle(30 + 100 * (squarej[0] - 1), 30 + 100 * (squarei[0] - 1), 70 + 100 * (squarej[0] - 1), 70 + 100 * (squarei[0] - 1));
			setfillstyle(SOLID_FILL, COLOR(40, 110, 10));
			floodfill(35 + 100 * (squarej[0] - 1), 35 + 100 * (squarei[0] - 1), COLOR(40, 110, 10));
			squarej[0]--;
			if (squarej[0] == 0) { /*halati ke morabbae az safhe bazi kharej mishavad*/
				squarej[0] = 8;
			}
			change = 1;
			printboard(cells, squarei, squarej); /*chape jadval bazi*/
			continue;
		}
		if (move == 'w') {
			setcolor(COLOR(40, 110, 10)); /*pak kardan makane morabbae ghabli*/
			rectangle(30 + 100 * (squarej[0] - 1), 30 + 100 * (squarei[0] - 1), 70 + 100 * (squarej[0] - 1), 70 + 100 * (squarei[0] - 1));
			setfillstyle(SOLID_FILL, COLOR(40, 110, 10));
			floodfill(35 + 100 * (squarej[0] - 1), 35 + 100 * (squarei[0] - 1), COLOR(40, 110, 10));
			squarei[0]--;
			if (squarei[0] == 0) { /*halati ke morabbae az safhe bazi kharej mishavad*/
				squarei[0] = 8;
			}
			change = 1;
			printboard(cells, squarei, squarej); /*chape jadval bazi*/
			continue;
		}
		if (move == 's') {
			setcolor(COLOR(40, 110, 10)); /*pak kardan makane morabbae ghabli*/
			rectangle(30 + 100 * (squarej[0] - 1), 30 + 100 * (squarei[0] - 1), 70 + 100 * (squarej[0] - 1), 70 + 100 * (squarei[0] - 1));
			setfillstyle(SOLID_FILL, COLOR(40, 110, 10));
			floodfill(35 + 100 * (squarej[0] - 1), 35 + 100 * (squarei[0] - 1), COLOR(40, 110, 10));
			squarei[0]++;
			if (squarei[0] == 9) { /*halati ke morabbae az safhe bazi kharej mishavad*/
				squarei[0] = 1;
			}
			change = 1;
			printboard(cells, squarei, squarej); /*chape jadval bazi*/
			continue;
		}
		if (move == ' ') { /*gharar dadane makane feeli baraye gozashtane dayere sefid ya meshki*/
			m = squarei[0]; /*gharar dadane makane feeli morabbae baraye gozashtane dayere sefid ya meshki*/
			n = squarej[0];
			change = 1;
			printboard(cells, squarei, squarej); /*chape jadval bazi*/
		}

		if ((cells[m][n] == 'b') || (cells[m][n] == 'w')) { /*barresi khali boodan khane mored nazar*/
			printf("Your number is choosen\n ");
			continue;
		}

		{
			for (a = n - 1; 0 < a; a--) { /*halghe barresi teedad khane mojaz be taghyir dar jhat 1*/
				if ((cells[m][a] != '.') && (cells[m][a] == y)) {
					ch[0] = 1; /*fahmidan sahih boodan shart aval harekat dar jahat 1*/
					continue;
				}
				else if ((cells[m][a] == x) && (ch[0] == 1)) { /*shart dovvom mojaz be harekat va taghyir jadval dar jahat 1 */
					break;
				}
				else {
					a = 100; /*dadan adad part dar soorat mojaz be taghyir naboodan khane haye jadval bazi dar in jahat*/
					break;
				}
			}
		}

		{
			for (b = n + 1; b < 9; b++) { /*halghe barresi teedad khane mojaz be taghyir dar jhat 2*/
				if ((cells[m][b] != '.') && (cells[m][b] == y)) {
					ch[1] = 1; /*fahmidan sahih boodan shart aval harekat dar jahat 2*/
					continue;
				}
				else if ((cells[m][b] == x) && (ch[1] == 1)) { /*shart dovvom mojaz be harekat va taghyir jadval dar jahat 2 */
					break;
				}
				else
				{
					b = -100; /*dadan adad part dar soorat mojaz be taghyir naboodan khane haye jadval bazi dar in jahat*/
					break;
				}
			}
		}

		{
			for (c = m + 1; c < 9; c++) { /*halghe barresi teedad khane mojaz be taghyir dar jhat 3*/
				if ((cells[c][n] != '.') && (cells[c][n] == y)) {
					ch[2] = 1; /*fahmidan sahih boodan shart aval harekat dar jahat 3*/
					continue;
				}
				else if ((cells[c][n] == x) && (ch[2] == 1)) { /*shart dovvom mojaz be harekat va taghyir jadval dar jahat 3 */
					break;
				}
				else
				{
					c = -100; /*dadan adad part dar soorat mojaz be taghyir naboodan khane haye jadval bazi dar in jahat*/
					break;
				}
			}
		}

		{
			for (d = m - 1; 0 < d; d--) { /*halghe barresi teedad khane mojaz be taghyir dar jhat 4*/
				if ((cells[d][n] != '.') && (cells[d][n] == y)) {
					ch[3] = 1; /*fahmidan sahih boodan shart aval harekat dar jahat 4*/
					continue;
				}
				else if ((cells[d][n] == x) && (ch[3] == 1)) { /*shart dovvom mojaz be harekat va taghyir jadval dar jahat 4 */
					break;
				}
				else {
					d = 100; /*dadan adad part dar soorat mojaz be taghyir naboodan khane haye jadval bazi dar in jahat*/
					break;
				}
			}
		}

		{
			for (e = n - 1, f = m + 1; 0 < e, f < 9; f++, e--) { /*halghe barresi teedad khane mojaz be taghyir dar jhat 5*/
				if ((cells[f][e] != '.') && (cells[f][e] == y)) {
					ch[4] = 1; /*fahmidan sahih boodan shart aval harekat dar jahat 5*/
					continue;
				}
				else if ((cells[f][e] == x) && (ch[4] == 1)) { /*shart dovvom mojaz be harekat va taghyir jadval dar jahat 5 */
					break;
				}
				else {
					e = 100; /*dadan adad part dar soorat mojaz be taghyir naboodan khane haye jadval bazi dar in jahat*/
					f = -100; /*dadan adad part dar soorat mojaz be taghyir naboodan khane haye jadval bazi dar in jahat*/
					break;
				}
			}
		}

		{
			for (g = n + 1, h = m - 1; 0 < h, g < 9; g++, h--) { /*halghe barresi teedad khane mojaz be taghyir dar jhat 6*/
				if ((cells[h][g] != '.') && (cells[h][g] == y)) {
					ch[5] = 1; /*fahmidan sahih boodan shart aval harekat dar jahat 6*/
					continue;
				}
				else if ((cells[h][g] == x) && (ch[5] == 1)) { /*shart dovvom mojaz be harekat va taghyir jadval dar jahat 6 */
					break;
				}
				else {
					h = 100; /*dadan adad part dar soorat mojaz be taghyir naboodan khane haye jadval bazi dar in jahat*/
					g = -100; /*dadan adad part dar soorat mojaz be taghyir naboodan khane haye jadval bazi dar in jahat*/
					break;
				}
			}
		}

		{
			for (i = n - 1, j = m - 1; 0 < i, 0 < j; j--, i--) { /*halghe barresi teedad khane mojaz be taghyir dar jhat 7*/
				if ((cells[j][i] != '.') && (cells[j][i] == y)) {
					ch[6] = 1; /*fahmidan sahih boodan shart aval harekat dar jahat 7*/
					continue;
				}
				else if ((cells[j][i] == x) && (ch[6] == 1)) { /*shart dovvom mojaz be harekat va taghyir jadval dar jahat 7 */
					break;
				}
				else {
					i = 100;/*dadan adad part dar soorat mojaz be taghyir naboodan khane haye jadval bazi dar in jahat*/
					j = 100;
					break;
				}
			}
		}

		{
			for (k = n + 1, l = m + 1; k < 9, l < 9; l++, k++) { /*halghe barresi teedad khane mojaz be taghyir dar jhat 8*/
				if ((cells[l][k] != '.') && (cells[l][k] == y)) {
					ch[7] = 1; /*fahmidan sahih boodan shart aval harekat dar jahat 8*/
					continue;
				}
				else if ((cells[l][k] == x) && (ch[7] == 1)) { /*shart dovvom mojaz be harekat va taghyir jadval dar jahat 8 */
					break;
				}
				else {
					k = -100;/*dadan adad part dar soorat mojaz be taghyir naboodan khane haye jadval bazi dar in jahat*/
					l = -100;
					break;
				}
			}
		}

		{
			for (a; (a <= n) && (a > 0) && (a < 9); a++) { /*taghyir khane haye jadval bazi ba tavajjoh be nobat dar jahat 1*/
				cells[m][a] = x;
				change = 0; /*natije anjam shodan taghyirat dar jadval*/
			}
			for (b; (n <= b) && (b > 0) && (b < 9); b--) { /*taghyir khane haye jadval bazi ba tavajjoh be nobat dar jahat 2*/
				cells[m][b] = x;
				change = 0; /*natije anjam shodan taghyirat dar jadval*/
			}
			for (c; (m <= c) && (c > 0) && (c < 9); c--) { /*taghyir khane haye jadval bazi ba tavajjoh be nobat dar jahat 3*/
				cells[c][n] = x;
				change = 0; /*natije anjam shodan taghyirat dar jadval*/
			}
			for (d; (d <= m) && (d > 0) && (d < 9); d++) { /*taghyir khane haye jadval bazi ba tavajjoh be nobat dar jahat 4*/
				cells[d][n] = x;
				change = 0; /*natije anjam shodan taghyirat dar jadval*/
			}
			for (e, f; (e <= n, m <= f) && (e > 0) && (e < 9) && (f > 0) && (f < 9); f--, e++) { /*taghyir khane haye jadval bazi ba tavajjoh be nobat dar jahat 5*/
				cells[f][e] = x;
				change = 0; /*natije anjam shodan taghyirat dar jadval*/
			}
			for (g, h; (n <= g, h <= m) && (g > 0) && (g < 9) && (h > 0) && (h < 9); g--, h++) { /*taghyir khane haye jadval bazi ba tavajjoh be nobat dar jahat 6*/
				cells[h][g] = x;
				change = 0; /*natije anjam shodan taghyirat dar jadval*/
			}
			for (i, j; (i <= n, j <= m) && (i > 0) && (i < 9) && (j > 0) && (j < 9); j++, i++) { /*taghyir khane haye jadval bazi ba tavajjoh be nobat dar jahat 7*/
				cells[j][i] = x;
				change = 0; /*natije anjam shodan taghyirat dar jadval*/
			}
			for (k, l; (n <= k, m <= l) && (l > 0) && (l< 9) && (k > 0) && (k < 9); l--, k--) { /*taghyir khane haye jadval bazi ba tavajjoh be nobat dar jahat 8*/
				cells[l][k] = x;
				change = 0; /*natije anjam shodan taghyirat dar jadval*/
			}
		}

		if (change == 0) { /*khorooj az tabe ba tavajjoh be natije anjam shodan taghyirat dar jadval*/
			break;
		}
		if (change == 1) {
			printf("Invalid move\n");/*entekhab khane bedon ghabeliyat taghyir dar har yek az 8 jahat */
			continue;
		}

		if (move == 'd' || move == 's' || move == 'w' || move == 'a' || move == ' ') {/*halate gheyre ghabele taghyir boodane mekane morede nazar*/
			continue;
		}

	}

	return 0;
}