#include "passturn.h" /*tabe barresi shart pass*/
#include <stdio.h>
#include <stdlib.h>
#include "graphics.h"

int passturn(char cells[9][9], int turn, int pass[1], int end[1]) {
	int a, b, c, d, e, f, g, h, i, j, k, l; /*moteghayyer haye marboot be harekat dar 8 jahat baraye khane entekhabi va teedad khane mojaz be taghyir jadval bazi dar har yek az 8 jahat*/
	int ch[8] = { 0,0,0,0,0,0,0,0 }; /*moteghayyer haye fahmidan anjam shodan har yek az shart haye harekhat dar 8 jahat*/
	char x, y; /*moteghayyer haye jagozari b va w ba tavajjoh be nobat*/
	int m = 0, n = 0; /*moteghayyer haye marboot be satr va sotoon adad voroodi tavassot bazikon*/
	if (turn == 1) { /*jagozari x va y ba tavajjoh be nobat*/
		x = 'b', y = 'w';
	}
	else if (turn == 2) {
		x = 'w', y = 'b';
	}
	if (end[0] == 1) { /*barresi shart pass dar halat da jaryan boodan bazi*/
		for (m = 1; m < 9; m++) { /*halghe jagozari meghdar m va n be ezaye har 64 khane jadval*/
			for (n = 1; n < 9; n++) {
				if (pass[0] == 1) { /*halat khonsa shart pass*/
					pass[0] = 0; /*rad shoodan yek bar nobat yek bazikon*/
				}
				if ((cells[m][n] != 'b') && (cells[m][n] != 'w')) { /*barresi khali boodan khane m n*/
					{
						for (a = n - 1; 0 < a; a--) { /*halghe barresi teedad khane mojaz be taghyir dar jhat 1*/
							if ((cells[m][a] != '.') && (cells[m][a] == y)) {
								ch[0] = 1; /*fahmidan sahih boodan shart aval harekat dar jahat 1*/
								continue;
							}

							else if ((cells[m][a] == x) && (ch[0] == 1)) {
								pass[0] = 1; /*mojaz be entekhab harekat baraye bazikon marboote*/
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
							else if ((cells[m][b] == x) && (ch[1] == 1)) {
								pass[0] = 1; /*mojaz be entekhab harekat baraye bazikon marboote*/
								break;
							}
							else
							{
								b = -100;
								break; /*dadan adad part dar soorat mojaz be taghyir naboodan khane haye jadval bazi dar in jahat*/
							}
						}
					}

					{
						for (c = m + 1; c < 9; c++) { /*halghe barresi teedad khane mojaz be taghyir dar jhat 3*/
							if ((cells[c][n] != '.') && (cells[c][n] == y)) {
								ch[2] = 1; /*fahmidan sahih boodan shart aval harekat dar jahat 3*/
								continue;
							}
							else if ((cells[c][n] == x) && (ch[2] == 1)) {
								pass[0] = 1; /*mojaz be entekhab harekat baraye bazikon marboote*/
								break;
							}
							else
							{
								c = -100;
								break; /*dadan adad part dar soorat mojaz be taghyir naboodan khane haye jadval bazi dar in jahat*/
							}
						}
					}

					{
						for (d = m - 1; 0 < d; d--) { /*halghe barresi teedad khane mojaz be taghyir dar jhat 4*/
							if ((cells[d][n] != '.') && (cells[d][n] == y)) {
								ch[3] = 1; /*fahmidan sahih boodan shart aval harekat dar jahat 4*/
								continue;
							}
							else if ((cells[d][n] == x) && (ch[3] == 1)) {
								pass[0] = 1; /*mojaz be entekhab harekat baraye bazikon marboote*/
								break;
							}
							else {
								d = 100;
								break; /*dadan adad part dar soorat mojaz be taghyir naboodan khane haye jadval bazi dar in jahat*/
							}
						}
					}

					{
						for (e = n - 1, f = m + 1; 0 < e, f < 9; f++, e--) { /*halghe barresi teedad khane mojaz be taghyir dar jhat 5*/
							if ((cells[f][e] != '.') && (cells[f][e] == y)) {
								ch[4] = 1; /*fahmidan sahih boodan shart aval harekat dar jahat 5*/
								continue;
							}
							else if ((cells[f][e] == x) && (ch[4] == 1)) {
								pass[0] = 1; /*mojaz be entekhab harekat baraye bazikon marboote*/
								break;
							}
							else {
								e = 100;
								f = -100;
								break; /*dadan adad part dar soorat mojaz be taghyir naboodan khane haye jadval bazi dar in jahat*/
							}
						}
					}

					{
						for (g = n + 1, h = m - 1; 0 < h, g < 9; g++, h--) { /*halghe barresi teedad khane mojaz be taghyir dar jhat 6*/
							if ((cells[h][g] != '.') && (cells[h][g] == y)) {
								ch[5] = 1; /*fahmidan sahih boodan shart aval harekat dar jahat 6*/
								continue;
							}
							else if ((cells[h][g] == x) && (ch[5] == 1)) {
								pass[0] = 1; /*mojaz be entekhab harekat baraye bazikon marboote*/
								break;
							}
							else {
								h = 100;
								g = -100;
								break; /*dadan adad part dar soorat mojaz be taghyir naboodan khane haye jadval bazi dar in jahat*/
							}
						}
					}

					{
						for (i = n - 1, j = m - 1; 0 < i, 0 < j; j--, i--) { /*halghe barresi teedad khane mojaz be taghyir dar jhat 7*/
							if ((cells[j][i] != '.') && (cells[j][i] == y)) {
								ch[6] = 1; /*fahmidan sahih boodan shart aval harekat dar jahat 7*/
								continue;
							}
							else if ((cells[j][i] == x) && (ch[6] == 1)) {
								pass[0] = 1; /*mojaz be entekhab harekat baraye bazikon marboote*/
								break;
							}
							else {
								i = 100;
								j = 100;
								break; /*dadan adad part dar soorat mojaz be taghyir naboodan khane haye jadval bazi dar in jahat*/
							}
						}
					}

					{
						for (k = n + 1, l = m + 1; k < 9, l < 9; l++, k++) { /*halghe barresi teedad khane mojaz be taghyir dar jhat 8*/
							if ((cells[l][k] != '.') && (cells[l][k] == y)) {
								ch[7] = 1; /*fahmidan sahih boodan shart aval harekat dar jahat 8*/
								continue;
							}
							else if ((cells[l][k] == x) && (ch[7] == 1)) {
								pass[0] = 1; /*mojaz be entekhab harekat baraye bazikon marboote*/
								break;
							}
							else {
								k = -100;
								l = -100;
								break; /*dadan adad part dar soorat mojaz be taghyir naboodan khane haye jadval bazi dar in jahat*/
							}
						}
					}

					cells[m][n] = '.'; /*bargardandan khane m n be halat khali*/
					if (pass[0] == 1) { /*mojaz be entekhab harekat boodan baraye bazikon marboote*/
						break; /*khorooj az shart pass*/
					}
				}
				for (int u = 0;u < 8;u++) { /*bargardandan moteghayyer haye fahmidan anjam shodan har yek az shart haye harekhat dar 8 jahat be halat avvalieh*/
					ch[u] = 0;
				}

				if (pass[0] == 1) { /*mojaz be entekhab harekat boodan baraye bazikon marboote*/
					break; /*khorooj az shart pass*/
				}
			}
			if (pass[0] == 1) { /*mojaz be entekhab harekat boodan baraye bazikon marboote*/
				break; /*khorooj az shart pass*/
			}
		}
	}

	if ((pass[0] == 0) || (pass[0] == (-1))) { /*kam kardan meghdar moteghayyer pass dar soorat mojaz be entekhab harekat naboodan*/
		pass[0]--;
	}

	if (pass[0] == (-2)) { /*rad shoodan yek bar nobat har yek az do bazikon*/
		end[0] = 0; /*mojaz be entekhab naboodan baraye har yak az do bazikon va payan yek dor bazi*/
	}

	if (pass[0] == (-1) || (pass[0] == (-2))) { /*namayesh peygham monaseb ba tavajjoh be shart pass dar halat mojaz be entekhab naboodan*/
		if (turn == 1) {
			printf("\nBLACK player's\nYou can't choose any number\n");
		}
		else if (turn == 2) {
			printf("\nWHITE player's\nYou can't choose any number\n");
		}
	}

	a = 0, b = 0, c = 0, d = 0, e = 0, f = 0, g = 0, h = 0, i = 0, j = 0, k = 0, l = 0;  /*bargardandan moteghayyer haye dakhel shart pass be halat avvalieh*/
	for (int t = 0;t < 8;t++) { 
		ch[t] = 0;
	}
	m = 0, n = 0;

	return 0;
}