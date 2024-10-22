#pragma once
#include "Snake.h"
#include "Apple.h"

class Game
{
public:
    Snake snake;
    Apple apple;
    BonusApple bonusApple;
    bool running;
    int score;
    int maxSnakeSize;
    bool gameWon;
    double winDisplayTime;

    Game();
    void Draw() const;
    void Update();
    void HandleAppleCollision();
    void HandleBonusAppleCollision();
    void HandleEdgeCollision();
    void HandleTailCollision();
    void EvaluateWinCondition();
    void GameOver();
};
