#include<iostream>
#include<conio.h>
using namespace std;
int wallX = 75 , wallY = 17;	// WallX = 4X-1 (min = 2 ) && WallY = 2Y+1 (min = 2) || Recommended = (75,17)    ++ you should edit to system command in main function too.
int BALL, ballX = wallX / 2 +1, ballY = wallY / 2 +1, p1X = 2, p1Y = wallY / 2 +1, p2X = wallX - 1, p2Y = wallY / 2 +1, score1 = 0, score2 = 0 , save = wallY / 2 +1 , saveR = BALL;
int RIGHT = 1, UPRIGHT = 2, UPLEFT = 3, LEFT = 4, DOWNLEFT = 5, DOWNRIGHT = 6;
bool game = 1;
void input() {
	if (_kbhit()) {
		switch (_getch()) {
		case 'w':
			if (p1Y != 3)
			p1Y--;
			break;
		case 's':
			if (p1Y != wallY -2)
			p1Y++;
			break;
		case '8':
			if (p2Y != 3)
			p2Y--;
			break;
		case '5':
			if (p2Y != wallY -2)
			p2Y++;
			break;
		}
	}
}
void hit() {
	if (ballX == wallX / 2 + 1) {
		save = ballY;
		saveR = BALL;
	}
	if (ballX >= wallX) {
		ballX = wallX / 2 + 1;
		ballY = save;
		BALL = saveR;
		score1++;
	}
	if (ballX <= 1) {
		ballX = wallX / 2 + 1;
		ballY = save;
		BALL = saveR;
		score2++;
	}
	if (ballX == p1X && ballY == p1Y - 1) {
		BALL = UPRIGHT;
	}
	if (ballX == p1X && ballY == p1Y) {
		BALL = RIGHT;
	}
	if (ballX == p1X && ballY == p1Y + 1) {
		BALL = DOWNRIGHT;
	}
	if (ballX == p2X && ballY == p2Y - 1) {
		BALL = UPLEFT;
	}
	if (ballX == p2X && ballY == p2Y) {
		BALL = LEFT;
	}
	if (ballX == p2X && ballY == p2Y + 1) {
		BALL = DOWNLEFT;
	}
	if (BALL == DOWNRIGHT && ballY == wallY-1) {
		BALL = UPRIGHT;
	}
	if (BALL == DOWNLEFT && ballY == wallY-1) {
		BALL = UPLEFT;
	}
	if (BALL == UPRIGHT && ballY == 2) {
		BALL = DOWNRIGHT;
	}
	if (BALL == UPLEFT && ballY == 2) {
		BALL = DOWNLEFT;
	}
}
void ball() {
	if (BALL == RIGHT) {
		ballX += 2;
	}
	if (BALL == UPRIGHT) {
		ballX++; ballY--;
	}
	if (BALL == UPLEFT) {
		ballX--; ballY--;
	}
	if (BALL == LEFT) {
		ballX -= 2;
	}
	if (BALL == DOWNLEFT) {
		ballX--; ballY++;
	}
	if (BALL == DOWNRIGHT) {
		ballX++; ballY++;
	}
}
void screen() {
	system("cls");
	for (int i = 1; i <= wallY-1; i++) {
		for (int j = 1; j <= wallX; j++) {
			if (wallX == j || i == 1 || j == 1)
				cout << "#";
			else if (ballX == j && ballY == i) {
				cout << "o";
			}
			else if (wallX / 2 + 1 == j) {
				cout << "|";
			}
			else if (p1X == j && p1Y + 1 == i) {
				cout << "|";
			}
			else if (p1X == j && p1Y == i) {
				cout << "|";
			}
			else if (p1X == j && p1Y - 1 == i) {
				cout << "|";
			}
			else if (p2X == j && p2Y + 1 == i) {
				cout << "|";
			}
			else if (p2X == j && p2Y == i) {
				cout << "|";
			}
			else if (p2X == j && p2Y - 1 == i) {
				cout << "|";
			}
			else cout << " ";
		}
		cout << endl;
	}
}
void score() {
	
	if (score1 == 10 || score2 == 10) {
		game = 0;
		if (score1 > score2) 
			cout << "PLAYER 1 WON THE GAME!!";
		
		else 
			cout << "PLAYER 2 WON THE GAME!!";

			for (int j = 1; j <= wallX - 37; j++)
				cout << "#";
			cout << "// RESTART : R";
		
	}
	else {
		for (int j = 1; j <= wallX - 24; j++) {
			if (j == 1)
				cout << "Player 1 : " << score1;
			else if (j == wallX / 2 - 9)
				cout << "Player 2 : " << score2;
			else
				cout << "#";
		}
		cout << "##";
	}
}
int main() {
	system("color c");
	system("mode con:cols=75 lines=17");  // mode con:cols=wallX lines=wallY
	while (game) {
		if (rand() % 2 == 0)
			BALL = RIGHT;
		else
			BALL = LEFT;
		while (game) {
			input();
			ball();
			hit();
			screen();
			score();
		}
		if (_getch() == 'r' || _getch() == 'R') {
			game = 1;
			score1 = 0;
			score2 = 0;
			p1Y = wallY / 2 + 1;
			p2Y = wallY / 2 + 1;
		}
	}
	return 0;
}