#ifndef GAME_H
#define GAME_H

#include "Snake.h"
#include "Apple.h"

class Game
{
public:
    Snake snake;
    Apple apple;
    bool isRunning;
    int currentScore;

    Game();
    void render();
    void updateLogic();
    void snakeEatsApple();
    void snakeHitsWall();
    void snakeHitsSelf();
    void endGame();
};

#endif
