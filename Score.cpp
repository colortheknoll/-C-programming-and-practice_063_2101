#pragma once

#include "Score.h"
#include "func.h"

#include <iostream>

using namespace std;

namespace SPEED {
	enum {
		LEVEL1 = 7, LEVEL2 = 6, LEVEL3 = 5, LEVEL4 = 4, LEVEL5 = 3, LEVEL6 = 2, LEVEL7 = 1
	};
}

void Score::score_up() { 
	score += 200 / *speed;
}

void Score::print_score_speed() {
	//테두리
	gotoxy(13, 52);
	cout << "□□□□□□";
	for (int i = 0; i <= 8; i++) {
		gotoxy(14 + i, 52);
		cout << "□　　　　□";
	}
	gotoxy(22, 52);
	cout << "□□□□□□";

	//내용
	gotoxy(16, 53);
	cout << " Level: " << *level;
	gotoxy(18, 53);
	cout << " Score: " << score;
	//gotoxy(20, 53); //나중에 삭제할 부분 게임하면서 스피드 확인하려고 잠깐 넣어둠
	//cout << " Speed: " << *speed;
}

void Score::change_speed(int* level) {
	if (*level == 1) {
		*speed = SPEED::LEVEL1;
	}
	if (*level == 2) {
		*speed = SPEED::LEVEL2;
	}
	if (*level == 3) {
		*speed = SPEED::LEVEL3;
	}
	if (*level == 4) {
		*speed = SPEED::LEVEL4;
	}
	if (*level == 5) {
		*speed = SPEED::LEVEL5;
	}
	if (*level == 6) {
		*speed = SPEED::LEVEL6;
	}
	if (*level == 7) {
		*speed = SPEED::LEVEL7;
	}
}