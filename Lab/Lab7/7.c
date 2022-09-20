#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<time.h>

const int Star_Left = 10, Star_Right = 70;
const int Star_Bottom = 5, Star_Top = 2;
// Environment
void setcolor(int fg, int bg) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, bg * 16 + fg);
}

struct Star_Pos {
	int x, y;
}star[20];

void draw_Star(int star_total) {
	srand(time(NULL));
	for (int i = 1; i <= star_total; i++) {
		star[i].x = (rand() % (Star_Right - Star_Left + 1)) + Star_Left;
		star[i].y = (rand() % (Star_Bottom - Star_Top + 1)) + Star_Top;
		COORD c = { star[i].x,star[i].y};
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
		printf("*");
	}
}
void erase_Star(int x,int y) {
	COORD c = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
	setcolor(0, 0);
}

// Ship
void draw_ship(int x, int y) {
	COORD c = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
	setcolor(2, 4);
	printf("<-0->");
}
void erase_ship(int x, int y) {
	COORD c = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
	setcolor(7, 0);
	printf("     ");
}

// Cursor
void setcursor(bool visible)
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO lpCursor;
	lpCursor.bVisible = visible;
	lpCursor.dwSize = 20;
	SetConsoleCursorInfo(console, &lpCursor);
}

char cursor(int x, int y) {
	HANDLE hStd = GetStdHandle(STD_OUTPUT_HANDLE);
	char buf[2]; COORD c = { x,y }; DWORD num_read;
	if (
		!ReadConsoleOutputCharacter(hStd, (LPTSTR)buf, 1, c, (LPDWORD)&num_read))
		return '\0';
	else
		return buf[0];
}

// Bullet
void draw_bullet(int x, int y) {
	COORD c = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
	setcolor(7, 1);
	printf("^");
}
void erase_bullet(int x, int y) {
	COORD c = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
	setcolor(7, 0);
	printf(" ");
}

void ScoreBoard(int x, int y, int score) {
	COORD c = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
	setcolor(7, 0);
	printf("Current Score : %d",score);
}

void Tutorial(int x, int y) {
	COORD c = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
	setcolor(7, 0);
	printf("Press R to reload");
}
// Main Function
int main() {
	int score = 0;
	draw_Star(20);
	ScoreBoard(90,2,0);
	Tutorial(90, 3);
	char ch = ' ';
	char direction = '0';
	bool bullet_check[6];
	int x = 38, y = 20;
	int bullet_x[6], bullet_y[6];
	int bullet_total = 5, bullet = 0;
	int Star_Now=20;
	setcursor(0);
	draw_ship(x, y);

	do {

		if (_kbhit()) {
			ch = _getch();
			if (ch == 'a') {
				direction = 'L';
			}
			if (ch == 'd') {
				direction = 'R';
			}
			if (ch == 's') {
				direction = 'S';
			}

			// Bullet Motion
			if (ch == ' ') { // press spacebar to shoot
				if (bullet <= bullet_total) {
					bullet += 1;
					bullet_x[bullet] = x; //  initial x bullet
					bullet_y[bullet] = 19; // initial y bullet
					bullet_check[bullet] = TRUE;
					Sleep(10);
				}
			}
			if (ch == 'r') { // press r to reload
				bullet = 0;
				Sleep(10);
			}
			fflush(stdin);
		}

		// Ship Logic
		if (direction == 'L' && x != 0) {
			erase_ship(x, y);
			draw_ship(--x, y);
		}
		if (direction == 'R' && x != 110) {
			erase_ship(x, y);
			draw_ship(++x, y);
		}
		if (direction == 'S' || x == 0 || x == 110) {
			draw_ship(x, y);
		}
		
		// Bullet Logic
		for (int i = 1; i <= bullet_total; i++) {
			if (bullet_check[i] == TRUE) {
				erase_bullet(bullet_x[i], bullet_y[i]);
				if (bullet_y[i] > 0) {
					erase_bullet(bullet_x[i], bullet_y[i]);
					draw_bullet(bullet_x[i], --bullet_y[i]);
					if (cursor(bullet_x[i], bullet_y[i]-1) == '*') {
						erase_bullet(bullet_x[i], bullet_y[i]-1);
						erase_bullet(bullet_x[i], bullet_y[i]);
						bullet_y[i] = 0;
						Beep(2000, 400);
						score++;
						Star_Now--;
						if (Star_Now != 20) {
							draw_Star(1);
						}
					}
					ScoreBoard(90, 2, score);
				}
				else {
					bullet_check[i] = FALSE;
				}
			}
		}
		Sleep(30);

	} while (ch != 'x');
}