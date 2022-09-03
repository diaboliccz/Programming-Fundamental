#include <stdio.h>
#include <windows.h>
void gotoxy(int x, int y) {
    COORD c = { x,y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void draw_ship() {
    printf("<-O->");
}

int main() {
    char ch = ' ';
    int x = 0, y = 0;
    draw_ship(x, y);
    do {
        if (_kbhit()) {
            ch = _getch();
            if (x>60) {
                draw_ship(0,0);
            }
            if (ch == 'a') { draw_ship(--x, y); }
            if (ch == 'd') { draw_ship(++x, y); }
            fflush(stdin);
        }
        Sleep(100);
    } while (ch != 'x');
    return 0;
}