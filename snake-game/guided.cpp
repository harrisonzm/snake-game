#include<windows.h>
#include<thread>
#include<list>
using namespace std;

/*
int nScreenWidth = 120;
int nScreenHeight = 30 ;

struct body
{
	int x;
	int y;
};

int main() {

	wchar_t* screen = new wchar_t[nScreenWidth * nScreenHeight];
	for (int i = 0; i < nScreenWidth * nScreenHeight; i++) screen[i] = L' ';
	HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleActiveScreenBuffer(hConsole);
	DWORD dwBytesWritten = 0;

	list<body> snake = { {60,15}, {60,15} };
	int nFoodX = 30;
	int nFoodY = 15;
	int nScore = 0;
	int direction = 3;
	bool bDead = false;

	while (1) {
		//timing and input

		//game logic

			//display to player
			for (int i = 0 ; i < nScreenWidth * nScreenHeight ; i++) screen[i] = L' ';

			//draw stats & border
			for (int i = 0; i < nScreenWidth; i++) 
			{
				screen[i] = L'=';
				screen[2 * nScreenWidth + i] = L'=';
			}
			wsprintf(&screen[nScreenWidth + 5], L"SNAKE GAME                      SCORE:%d",nScore);
			
			//draw body
			for (auto s : snake)
				screen[s.y * nScreenWidth + s.x] = bDead ? L'+' : L'O';
		
			//draw head
			screen[snake.front().y * nScreenWidth + snake.front().x] = bDead ? L'X' : L'@';

			//draw food 
			screen[nFoodY * nScreenWidth + nFoodX] = L'%';

			//display frame
			WriteConsoleOutputCharacter(hConsole, screen, nScreenWidth * nScreenHeight, { 0,0 }, &dwBytesWritten);
	}


	return 0;
}*/