#include <iostream>
#include <conio.h>
#include <Windows.h>
using namespace std;
bool gameOver;
const int width = 20;
const int height = 20;
int x, y, fruitX, fruitY, score;
int tailX[100], tailY[100];
int nTail;
enum eDirection { stop = 0,LEFT,RIGHT,UP, DOWN};
eDirection dr;
void setup()
{
	gameOver = false;
	dr = stop;
	x = width / 2;
	y = height / 2;
	fruitX = rand() % width;
	fruitY = rand() % height;
	score = 0;
}
void draw()
{

	system("cls");
	for (int i = 0; i < width+1; i++)
	{
		cout << "#";
	}
	cout << endl;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width+1; j++)
		{
			if (j == 0)
			{
				cout << "#";
			}
			if (i == y && j == x)
			{
				cout << "O";
			}
			else if (i == fruitY && j == fruitX)
			{
				cout << "F";
			}
			else
			{
				bool print=false;
				for (int k = 0; k < nTail; k++)
				{
					if (tailX[k] == j && tailY[k] == i)
					{
						cout << "O";
						print = true;
					}
				}
				if (!print)
					cout << " ";
			}
			
			if (j == width - 1)
			{
				cout << "#";
			}
			
		}
		cout << "\n";
	}
	for (int i = 0; i < width+1; i++)
	{
		cout << "#";
	}
	cout << endl;
	cout << score << endl;
}
void input()
{

	if (_kbhit())
	{


		switch (_getch())
		{
		case 'a':
			dr = LEFT;
			
			break;
		case 'd':
			dr = RIGHT;
			break;
		case 's':
			dr = DOWN;
			break;
		case 'w':
			dr = UP;
			break;
		case 'x':
			gameOver = true;
			break;
		}
	}

}
void Logic()
{
	int prevTailX = tailX[0];
	int prevTailY = tailY[0];
	int prev2X, prev2Y;
	tailX[0] = x;
	tailY[0] = y;
	for (int i = 1; i < nTail; i++)
	{
		prev2X = tailX[i];
		prev2Y = tailY[i];
		tailX[i] = prevTailX;
		tailY[i] = prevTailY;
		prevTailX = prev2X;
		prevTailY = prev2Y;
	}
	switch(dr)
	{
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	case RIGHT:
		x++;
		break;
	case LEFT:
		x--;
		break;
	default:
		break;
	}
	if (x > width || x<0 || y>height || y < 0)
	{
		gameOver = true;
	}
	if (x == fruitX && y == fruitY)
	{
		nTail++;
		score++;
		fruitX = rand() % width;
		fruitY = rand() % height;
	}
	for (int i = 0; i < nTail; i++)
	{
		if (tailX[i] == x && tailY[i] == y)
			gameOver=true;
	}
}

int main()
{


	setup();
	while (!gameOver)
	{
		draw();
		input();
		Logic();
	}
	Sleep(40);
	return 0;
}