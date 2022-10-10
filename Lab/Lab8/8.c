#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<time.h>

#define screen_x 80
#define screen_y 25
#define scount 80

int Health = 10;
bool Game_Status = true;
int color = 7, pos[2] = {screen_x/2,screen_y-1};

HANDLE wHnd;
HANDLE rHnd;
DWORD fdwMode;
COORD bufferSize = { screen_x,screen_y };
CHAR_INFO consoleBuffer[screen_x * screen_y];
COORD characterPos = { 0,0 };
SMALL_RECT windowSize = { 0,0,screen_x - 1,screen_y - 1 };
COORD star[scount];
COORD ship;

int setMode() {
	rHnd = GetStdHandle(STD_INPUT_HANDLE);
	fdwMode = ENABLE_EXTENDED_FLAGS | ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT;
	SetConsoleMode(rHnd, fdwMode);
	return 0;
}

int setConsole(int x, int y) {
	wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleWindowInfo(wHnd, TRUE, &windowSize);
	SetConsoleScreenBufferSize(wHnd, bufferSize);
	return 0;
}

void clear_Buffer() {
	for (int y = 0; y < screen_y; y++) {
		for (int x = 0; x < screen_x; x++) {
			consoleBuffer[x + screen_x * y].Char.AsciiChar = ' ';
			consoleBuffer[x + screen_x * y].Attributes = 7;
		}
	}
}

void fill_buffer_to_console() {
	WriteConsoleOutputA(wHnd, consoleBuffer, bufferSize, characterPos, &windowSize);
}

void init_star() {
	for (int i = 0; i < scount; i++) {
		star[i] = { (SHORT)(rand() % screen_x),(SHORT)(rand() % screen_y) };
	}
}

void star_fall() {
	for (int i = 0; i < scount; i++) {
		if (star[i].Y > screen_y) {
			star[i].X = rand() % screen_x;
			star[i].Y = 1;
		}
		else {
			star[i].Y += 1;
		}
	}
}

void fill_star_to_buffer() {
	for (int i = 0; i < scount; i++) {
		consoleBuffer[star[i].X + screen_x * star[i].Y].Char.AsciiChar = '*';
		consoleBuffer[star[i].X + screen_x * star[i].Y].Attributes = 7;
	}
}

void fill_ship_to_buffer(int x, int y) {
	ship = { (SHORT)x,(SHORT)y };
	consoleBuffer[ship.X + screen_x * ship.Y].Char.AsciiChar = '<';
	consoleBuffer[ship.X + 1 + screen_x * ship.Y].Char.AsciiChar = '-';
	consoleBuffer[ship.X + 2 + screen_x * ship.Y].Char.AsciiChar = '>';
	consoleBuffer[ship.X + screen_x * ship.Y].Attributes = 7;
	consoleBuffer[ship.X + 1 + screen_x * ship.Y].Attributes = 7;
	consoleBuffer[ship.X + 2 + screen_x * ship.Y].Attributes = 7;
}

void check_collide() {
	for (int i = 0; i < scount; i++) {
		if ((star[i].X >= ship.X-1 && star[i].X <= ship.X+1) && (star[i].Y == ship.Y)) {
			Health -= 1;
			star[i].X = rand() % screen_x;
			star[i].Y = rand() % screen_y;
		}
		if (Health == 0) {
			Game_Status = false;
		}
	}
}


// Main Function
int main() {
	DWORD numEvents = 0;
	DWORD numEventsRead = 0;
	srand(time(NULL));
	setConsole(screen_x, screen_y);
	setMode();
	init_star();
	while (Game_Status) {
		GetNumberOfConsoleInputEvents(rHnd, &numEvents);
		if (numEvents != 0) {
			INPUT_RECORD* eventBuffer = new INPUT_RECORD[numEvents];
			ReadConsoleInput(rHnd, eventBuffer, numEvents, &numEventsRead);
			for (DWORD i = 0; i < numEventsRead; i++)
			{
				if (eventBuffer[i].EventType == KEY_EVENT && eventBuffer[i].Event.KeyEvent.bKeyDown == true){
					if (eventBuffer[i].Event.KeyEvent.wVirtualKeyCode == VK_ESCAPE) {
						Game_Status = false;
					}
					if (eventBuffer[i].Event.KeyEvent.uChar.AsciiChar == 99) {
						color = 1 + rand() % 9;
					}
				}
				else if (eventBuffer[i].EventType == MOUSE_EVENT)
				{
					int posx = eventBuffer[i].Event.MouseEvent.dwMousePosition.X;
					int posy = eventBuffer[i].Event.MouseEvent.dwMousePosition.Y;

					if (eventBuffer[i].Event.MouseEvent.dwButtonState &&
						FROM_LEFT_1ST_BUTTON_PRESSED) {
						color = 1 + rand() % 9;
					}
					else if (eventBuffer[i].Event.MouseEvent.dwEventFlags && MOUSE_MOVED) {
						pos[0] = posx;
						pos[1] = posy;
					}
				}
			}
			delete[] eventBuffer;
		}
		star_fall();
		check_collide();
		clear_Buffer();
		fill_star_to_buffer();
		fill_ship_to_buffer(pos[0], pos[1]);
		fill_buffer_to_console();
		Sleep(50);
	}
}
