#include <stdio.h>
#include <windows.h>
#include <conio.h>

#define WIDTH 50
#define HEIGHT 20

void draw_ship(int x, int y) {
    COORD c = { x,y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
    printf(" <-O-> ");
    
}

void draw_rect() {
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

void erase_ship(int x, int y) {
    COORD c = {x,y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
    printf("      ");
    
}

int main() {
    char ch = ' ';
    int x = 5, y = 5;
    draw_rect();
    draw_ship(x, y);
    do {
        if (_kbhit()) {
            ch = _getch();
            //X
            if (x < WIDTH-8) {
                if (ch == 'd') {   
                    draw_ship(++x, y);
                    
                }
            }

            if (x > 1) {
                if (ch == 'a') { 
                    draw_ship(--x, y);
                    
                }
            }

            //y
            if (y < HEIGHT - 2) {
                if (ch == 's') { 
                    erase_ship(x, y);
                    draw_ship(x, ++y);
                    
                }
            }

            if (y > 1) {
                if (ch == 'w') { 
                    erase_ship(x, y);
                    draw_ship(x, --y);
                    
                }
            }
            fflush(stdin);
        }
    } while (ch != 'x');
    return 0;
}