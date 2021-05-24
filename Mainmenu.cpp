#pragma once

#include "Mainmenu.h"
#include <iostream>

using namespace std;

void Mainmenu::print_menu() {
	system("cls");

	char b0[4] = { "　" }; //0
	char b1[4] = { "＝" }; //-1

	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 31; j++) {
			menu[j][i] = 0;
		}
	}

	//TETRIS 越松
	int t[10][2] = { {1, 1}, {2, 1}, {3, 1}, {4, 1}, {5, 1}, {3, 2}, {3, 3}, {3, 4}, {3, 5}, {3, 6} };
	int e[15][2] = { {7, 1}, {8, 1}, {9, 1}, {10, 1}, {7, 2}, {7, 3}, {8, 3}, {9, 3}, {10, 3}, {7, 4}, {7, 5}, {7, 6}, {8, 6}, {9, 6}, {10, 6} };
	int r[16][2] = { {18, 1}, {19, 1}, {20, 1}, {21, 1}, {18, 2}, {21, 2}, {18, 3}, {19, 3}, {20, 3}, {21, 3}, {18, 4}, {20, 4}, {18, 5}, {21, 5}, {18, 6}, {21, 6} };
	int I[10][2] = { {23, 1}, {24, 1}, {25, 1}, {24, 2}, {24, 3}, {24, 4}, {24, 5}, {23, 6}, {24, 6}, {25, 6} };
	int s[15][2] = { {27, 1}, {28, 1}, {29, 1}, {30, 1}, {27, 2}, {27, 3}, {28, 3}, {29, 3}, {30, 3}, {30, 4}, {30, 5}, {27, 6}, {28, 6}, {29, 6}, {30, 6} };

	for (int i = 0; i < 10; i++) {
		menu[t[i][0]][t[i][1]] = -1;
		menu[t[i][0] + 11][t[i][1]] = -1;
	}

	for (int i = 0; i < 15; i++) {
		menu[e[i][0]][e[i][1]] = -1;
	}

	for (int i = 0; i < 16; i++) {
		menu[r[i][0]][r[i][1]] = -1;
	}

	for (int i = 0; i < 10; i++) {
		menu[I[i][0]][I[i][1]] = -1;
	}

	for (int i = 0; i < 15; i++) {
		menu[s[i][0]][s[i][1]] = -1;
	}


	//窒径
	cout << endl;
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 31; j++) {
			if (menu[j][i] == 0) {
				cout << b0;
			}
			else {
				cout << b1;
			}
		}
		cout << endl;
	}

	cout << endl << endl;
	cout << "　------------------------------------------------------------" << endl;
	cout << endl << endl;
	cout << "　　　　　　　　　　　　　1. 獣拙" << endl << endl;
	cout << "　　　　　　　　　　　　　2. 巽鍵走" << endl << endl;
	cout << "　　　　　　　　　　　　　3. 蟹亜奄" << endl;
	cout << endl << endl;
	cout << "　------------------------------------------------------------" << endl;
}