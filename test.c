
#include<stdio.h>
#include<conio.h>
#include<Windows.h>
#include<stdbool.h>

void setcolor(int fg, int bg) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, bg * 16 + fg);
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
	setcolor(2, 0);
	printf("     ");
}

void setcursor(bool visible)
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO lpCursor;
	lpCursor.bVisible = visible;
	lpCursor.dwSize = 20;
	SetConsoleCursorInfo(console, &lpCursor);
}

// Bullet
void draw_bullet(int x, int y) {
	COORD c = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
	setcolor(7, 1);
	printf(" * ");
}
void erase_bullet(int x, int y) {
	COORD c = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
	setcolor(7, 0);
	printf("   ");
}


// Main Function
void main() {
	char ch = ' ';
	char direction = '0';
	bool bullet_check[6];
	bool spacebar_check = TRUE;
	int x = 38, y = 20;
	int bullet_x[6], bullet_y[6], bullet_total = 5, bullet = 0;
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
			if (ch == ' ') {
				if (spacebar_check == TRUE) {
					if (bullet < bullet_total) {
						bullet += 1;
						bullet_x[bullet] = x; //  initial x bullet
						bullet_y[bullet] = 20; // initial y bullet
						bullet_check[bullet] = TRUE;
						Sleep(10);
					}
					else {
						spacebar_check = FALSE;
						Sleep(10);
					}
				}
			}
			fflush(stdin);
		}

		// Ship Logic
		if (direction == 'L' && x != 0) {
			erase_ship(x, y);
			draw_ship(--x, y);
		}
		if (direction == 'R' && x != 80) {
			erase_ship(x, y);
			draw_ship(++x, y);
		}
		if (direction == 'S' || x == 0 || x == 80) {
			draw_ship(x, y);
		}

		// Bullet Logic
		for (int i = 1; i <= bullet_total; i++) {
			if (bullet_check[i] == TRUE) {
				erase_bullet(bullet_x[i], bullet_y[i]);
				if (bullet_y[i] > 0) {
					draw_bullet(bullet_x[i], --bullet_y[i]); // bullet go to +y
				}
				else {
					bullet_check[i] = FALSE;
				}
			}
		}
		Sleep(30);
	} while (ch != 'x');

}
