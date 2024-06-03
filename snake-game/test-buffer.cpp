/*
OneLoneCoder.com - Command Line Snake
"Give me a break, I'm on holiday..." - @Javidx9

License
~~~~~~~
Copyright (C) 2018  Javidx9
This program comes with ABSOLUTELY NO WARRANTY.
This is free software, and you are welcome to redistribute it
under certain conditions; See license for details.
Original works located at:
https://www.github.com/onelonecoder
https://www.onelonecoder.com
https://www.youtube.com/javidx9

GNU GPLv3
https://github.com/OneLoneCoder/videos/blob/master/LICENSE

From Javidx9 :)
~~~~~~~~~~~~~~~
Hello! Ultimately I don't care what you use this for. It's intended to be
educational, and perhaps to the oddly minded - a little bit of fun.
Please hack this, change it and use it in any way you see fit. You acknowledge
that I am not responsible for anything bad that happens as a result of
your actions. However this code is protected by GNU GPLv3, see the license in the
github repo. This means you must attribute me if you use it. You can view this
license here: https://github.com/OneLoneCoder/videos/blob/master/LICENSE
Cheers!


Background
~~~~~~~~~~
Classic Snake! Controls are Arrow keys Left & Right, eat food, grow larger, avoid self!


Author
~~~~~~
Twitter: @javidx9
Blog: www.onelonecoder.com

Video:
~~~~~~
https://youtu.be/e8lYLYlrGLg

Last Updated: 24/06/2017
*/

#include <iostream>
#include <list>
#include <thread>
using namespace std;

#include <Windows.h>
/*
int nScreenWidth = 120;
int nScreenHeight = 30;

struct sSnakeSegment
{
	int x;
	int y;
};

int main()
{
	// Create Screen Buffer
	wchar_t* screen = new wchar_t[nScreenWidth * nScreenHeight];
	for (int i = 0; i < nScreenWidth * nScreenHeight; i++) screen[i] = L' ';
	HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleActiveScreenBuffer(hConsole);
	DWORD dwBytesWritten = 0;

	while (1)
	{
		// Reset to known state
		list<sSnakeSegment> snake = { {60,15},{61,15} };
		int nFoodX = 30;
		int nFoodY = 15;
		int nScore = 0;
		int nSnakeDirection = 3;
		bool bDead = false;


		while (!bDead)
		{
			
			
			// ==== Presentation

			// Clear Screen
			for (int i = 0; i < nScreenWidth * nScreenHeight; i++) screen[i] = L' ';

			// Draw Stats & Border
			for (int i = 0; i < nScreenWidth; i++)
			{
				screen[i] = L'=';
				screen[2 * nScreenWidth + i] = L'=';
			}
			wsprintf(&screen[nScreenWidth + 5], L"www.OneLoneCoder.com - S N A K E ! !                SCORE: %d", nScore);

			// Draw Snake Body
			for ( auto s : snake)
				screen[s.y * nScreenWidth + s.x] = bDead ? L'+' : L'O';

			// Draw Snake Head
			screen[snake.front().y * nScreenWidth + snake.front().x] = bDead ? L'X' : L'@';

			// Draw Food
			screen[nFoodY * nScreenWidth + nFoodX] = L'%';

			// Display Frame
			WriteConsoleOutputCharacter(hConsole, screen, nScreenWidth * nScreenHeight, { 0,0 }, &dwBytesWritten);
		}

		
	}

	return 0;
}*/


