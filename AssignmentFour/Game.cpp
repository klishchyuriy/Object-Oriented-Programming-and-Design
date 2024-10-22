#include "Game.h"

Game::Game()
{
    isRunning = true;
    currentScore = 0;
}

void Game::render()
{
    apple.render();
    snake.render();
}
