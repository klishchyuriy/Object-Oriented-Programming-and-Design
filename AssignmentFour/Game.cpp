#include "Game.h"

Game::Game() : running(true), score(0), maxSnakeSize(100), gameWon(false), winDisplayTime(0)
{
    apple = Apple(snake.body);
    bonusApple = BonusApple(snake.body);
}

void Game::Draw() const
{
    apple.Draw();
    bonusApple.Draw();
    snake.Draw();
}

void Game::Update()
{
    snake.ProcessGameUpdate();
}

