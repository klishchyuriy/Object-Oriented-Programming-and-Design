#include "Game.h"
#include <iostream>

Game::Game() : running(true), score(0), maxSnakeSize(100), gameWon(false), winDisplayTime(0),
               snake(), apple(snake.body), bonusApple(snake.body)
{
}

void Game::Draw() const
{
    snake.Draw();
    apple.Draw();
    bonusApple.Draw();
    if (gameWon) {
        DrawText("You Win!", 190, 200, 20, GREEN);
    }
}

void Game::Update()
{
    if (!gameWon && running) {
        snake.ProcessGameUpdate();
        HandleAppleCollision();
        HandleBonusAppleCollision();
        HandleEdgeCollision();
        HandleTailCollision();
        EvaluateWinCondition();
    }
}

void Game::HandleAppleCollision()
{
    if (snake.body.front() == apple.position) {
        score++;
        apple.position = apple.GenerateRandomPos(snake.body);
        snake.addSegment = true;
    }
}

void Game::HandleBonusAppleCollision()
{
    if (snake.body.front() == bonusApple.position) {
        score += 3;
        bonusApple.position = bonusApple.GenerateRandomPos(snake.body);
        snake.bonusSegmentCount += 2;
    }
}

void Game::HandleEdgeCollision()
{
    Vector2& head = snake.body.front();
    if (head.x < 0 || head.x >= 10 || head.y < 0 || head.y >= 10) {
        GameOver();
    }
}

void Game::HandleTailCollision()
{
    const Vector2& head = snake.body.front();
    for (auto it = snake.body.begin() + 1; it != snake.body.end(); ++it) {
        if (head == *it) {
            GameOver();
            break;
        }
    }
}

void Game::EvaluateWinCondition()
{
    if (snake.body.size() >= maxSnakeSize) {
        gameWon = true;
        running = false;
    }
}

void Game::GameOver()
{
    std::cout << "Game Over! Score: " << score << std::endl;
    running = false;
    gameWon = false;
    snake.Reset();
    apple.position = apple.GenerateRandomPos(snake.body);
    bonusApple.position = bonusApple.GenerateRandomPos(snake.body);
}
