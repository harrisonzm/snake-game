#include<Windows.h>
#include<list>
#include<cctype>
#include<thread>
#define ms std::chrono::milliseconds

int WScreen = 120;
int HScreen = 30;


/*int WINAPI WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow) */


int main()
{	// Create Screen Buffer
	wchar_t* screen = new wchar_t[WScreen * HScreen];
	for (int i = 0; i < WScreen * HScreen; i++) screen[i] = L' ';
	HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleActiveScreenBuffer(hConsole);
	DWORD dwBytesWritten = 0;


	while (true) {


		//Game Logic
			//player
		int PlayerX = 50;
		int PlayerY = 15;
		std::list<std::pair<int, int>> snake = { {50,15},{51,15} };
		int direction = 3;
		bool bGameOver = false;

		//food
		int FoodX = 10;
		int FoodY = 10;
		int score = 0;



		while (!bGameOver) {
			std::this_thread::sleep_for(ms(200));
			//timing and input
			if (GetAsyncKeyState((unsigned short)'A') & 0x8000) {
				direction--;
				if (direction == -1) direction = 3;
			}
			if (GetAsyncKeyState((unsigned short)'W') & 0x8000)direction = 0;

			if (GetAsyncKeyState((unsigned short)'S') & 0x8000)direction = 2;

			if (GetAsyncKeyState((unsigned short)'D') & 0x8000) {
				direction++;
				if (direction == 4) direction = 0;
			}

			//move player
			switch (direction) {
			case 0: //up
				snake.push_front({ PlayerX ,  PlayerY-- }); break;

			case 1://right
				snake.push_front({PlayerX++ ,  PlayerY  }); break;

			case 2://down
				snake.push_front({ PlayerX ,  PlayerY++ }); break;

			case 3://left
				snake.push_front({ PlayerX-- ,  PlayerY }); break;
			}

			if (PlayerX == FoodX && PlayerY == FoodY) {
				score++;
				while (screen[FoodY * WScreen + FoodX] != L' ') {
					FoodX = rand() % WScreen;
					FoodY = rand() % HScreen;
				}
				snake.push_back({ snake.back().first, snake.back().second });
			}

			for (std::list<std::pair<int, int>>::iterator i = snake.begin(); i != snake.end(); i++) 
			{
				if (i->second == PlayerY && i->first == PlayerX) bGameOver = true;
			}

			if (PlayerY >= HScreen || PlayerY < 0 || PlayerX >= WScreen || PlayerX <= 0) bGameOver = true;



			if (GetAsyncKeyState((unsigned short)'P') & 0x8000) bGameOver = true;

			snake.pop_back();

			
			//display to the user


			//clear screen
			for (int i = 0; i < WScreen * HScreen; i++) screen[i] = L' ';

			//draw field
			for (int i = 0; i < WScreen; i++) {
				screen[i] = L'=';
				screen[2 * WScreen + i] = L'=';
			}
			wsprintf(&screen[WScreen + 5], L"SNAKE GAME              SCORE: %d", score);

			//draw snake
			for (std::list<std::pair<int, int>>::iterator i = snake.begin(); i != snake.end(); i++) {

				screen[i->second * WScreen + i->first] = bGameOver ? L'+' : L'O';
			}

			//draw snake head
			screen[PlayerY * WScreen + PlayerX] = bGameOver ? L'X' : L'@';

			//draw food
			screen[FoodY * WScreen + FoodX] = L'%';
			if (bGameOver) wsprintf(&screen[WScreen / 2 * HScreen / 2 ], L"GAME OVER! PRESS SPACE TO PLAY AGAIN");

			//display frame
			WriteConsoleOutputCharacter(hConsole, screen, WScreen * HScreen, { 0,0 }, &dwBytesWritten);
		}
		while ((GetAsyncKeyState((unsigned short)VK_SPACE) & 0x8000) == 0);
	}


	return 0;
}