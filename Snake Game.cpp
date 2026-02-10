//Snake Game
#include <iostream>
#include <windows.h>
#include <conio.h>

//height and width of boundary
const int width = 80;
const int height = 20;

//snake head coordinates 
int x, y;
//food coordinates
int foodX, foodY;
//score of player
int score;
//array to store the coordinates of snake tail
int tailX[100], tailY[100];
//tail length
int tailLength;
