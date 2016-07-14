#include <iostream>
using namespace std;
bool gameOver;
const int width = 20;
const int height = 20;
int x, y; fruitX, fruitY, score;
enum eDirection {STOP = 0, LEFT, RIGHT, UP, DOWN};
eDirection dir;

void setup()
{
	gameOver = false;
}
void draw()
{

}
void input()
{

}
void logic()
{

}

int main()
{
	setup();
	while (!gameOver)
	{
		draw();
		input();
		logic();
	}
	return 0;
}