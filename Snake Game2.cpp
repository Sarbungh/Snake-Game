//Snake Game
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string>
using namespace std;

//height and width of boundary
const int width = 80;
const int height = 20;

//snake head coordinates 
int x, y;
//fruit coordinates
int fruitCordX, fruitCordY;
//score of player
int playerScore;
//array to store the coordinates of snake tail
int snakeTailX[100], snakeTailY[100];
//tail length
int snakeTailLen;
//movement direction of snake
enum direction {STOP = 0, LEFT, RIGHT, UP, DOWN};
direction sDir; 
//game over condition
bool isGameOver;

void GameInt(){
    isGameOver = false;
    sDir = STOP;
    x = width / 2;
    y = height / 2;
    fruitCordX = rand() % width;
    fruitCordY = rand() % height;
    playerScore = 0;
}

void GameRender(string playerName){
    system("cls");
    //top boundary
    for(int i = 0; i < width + 2; i++)
        cout << "-";
    cout << endl;

    //side boundaries
    for(int i - 0; i < height; i++){
        for(int j = 0; j <= width; j++){
            //side walls
            if(i == 0 || i == width)
                cout << "|";
            //snake head
            if(i == y && j == x)
                cout << "O";
            //fruit
            else if(i == fruitCordY && j == fruitCordX)
                cout << "#";
            else{
                bool printTail = false;
                for(int k = 0; k < snakeTailLen; k++){
                    if(snakeTailX[k] == j && snakeTailY[k] == i){
                        cout << "o";
                        printTail = true;
                    }
                }
                if(!printTail)
                    cout << " ";
            }
        }
        cout << endl;
    }
    //bottom boundary
    for(int i = 0; i < width + 2; i++)
        cout << "-";
    cout << endl;

    //player score
    cout << playerName << "'s Score: " << playerScore << endl;    
}

void UpdateGame(){
    int prevX = snakeTailX[0];
    int prevY = snakeTailY[0];
    int prev2X, prev2Y;
    snakeTailX[0] = x; 
    snakeTailY[0] = y;

    for(int i = 1; i < snakeTailLen; i++){
        prev2X = snakeTailX[i];
        prev2Y = snakeTailY[i];
        snakeTailX[i] = prevX;
        snakeTailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    switch(sDir){
        case STOP:
            break;
        case LEFT:
            x--;
            break;
        case RIGHT:
            x++;
            break;
        case UP:
            y--;
            break;
        case DOWN:
            y++;
            break;
    }
    //collision with wall
    if(x >= width || x < 0 || y >= height || y < 0)
        isGameOver = true;
    //collision with tail
    for(int i = 0; i < snakeTailLen; i++){
        if(snakeTailX[i] == x && snakeTailY[i] == y)
            isGameOver = true;
    }
    //eating fruit
    if(x == fruitCordX&& y == fruitCordY){
        playerScore += 10;
        fruitCordX = rand() % width;
        fruitCordY = rand() % height;
        snakeTailLen++;
    }
}