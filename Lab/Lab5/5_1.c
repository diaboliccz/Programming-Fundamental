#include <stdio.h>
#include <windows.h>
#include <conio.h>

#define WIDTH 50
#define HEIGHT 50

void draw_ship(int x, int y) {
    printf("<-O-> ");
    COORD c = { x,y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void draw_rect() {
    //int width = 10,height = 10;
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (i == 0 || i == HEIGHT - 1 || j == 0 || j == WIDTH - 1) {
                printf("*");
            }
            else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void erase_ship() {

}

int main() {
    char ch = ' ';
    int x = 5, y = 5;
    draw_rect();
    draw_ship(x, y);
    do {
        if (_kbhit()) {
            ch = _getch();
            if (x < WIDTH-6) {
                if (ch == 'd') { draw_ship(x+=1, y); }
            }
            else {
                if (ch == 'd') { draw_ship(x, y); }
            }
            if (y < HEIGHT - 2) {
                if (ch == 's') { draw_ship(x, y += 1); }
            }
            else {
                if (ch == 's') { draw_ship(x, y); }
            }
            if (x > 1) {
                if (ch == 'a') { draw_ship(x -= 1, y); }
            }
            else {
                if (ch == 'a') { draw_ship(x, y); }
            }
            if (y > 1) {
                if (ch == 'w') { draw_ship(x, y -= 1); }
            }
            else {
                if (ch == 'w') { draw_ship(x, y); }
            }
            
            
            fflush(stdin);
        }
    } while (ch != 'x');
    return 0;
}