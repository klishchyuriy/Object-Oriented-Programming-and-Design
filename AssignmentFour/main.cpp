#include "raylib.h"
#include "Game.h"
#include <iostream>

using namespace std;

// Global variables for game layout
const int cellSize = 30;
const int cellCount = 20; // Adjust the cell count as needed for your game size
const int offset = 75;
Color backgroundColor = {15, 15, 15, 255}; // Dark gray background
Color borderColor = {255, 255, 255, 255}; // White border

static bool allowMove = false;

// Function to check if enough time has passed for the next move
bool TimeIntervalPassed(double interval) {
    static double lastUpdateTime = 0;
    double currentTime = GetTime();
    if (currentTime - lastUpdateTime >= interval) {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}

int main()
{
    cout << "Starting the game..." << endl;
    InitWindow(2 * offset + cellSize * cellCount, 2 * offset + cellSize * cellCount, "Game Snake");
    SetTargetFPS(60);

    Game game = Game();

    while (!WindowShouldClose())
    {
        BeginDrawing();

        if (TimeIntervalPassed(0.2))
        {
            allowMove = true;
            game.Update();
        }

        if (IsKeyPressed(KEY_UP) && game.snake.direction.y != 1 && allowMove)
        {
            game.snake.direction = {0, -1};
            game.running = true;
            allowMove = false;
        }
        if (IsKeyPressed(KEY_DOWN) && game.snake.direction.y != -1 && allowMove)
        {
            game.snake.direction = {0, 1};
            game.running = true;
            allowMove = false;
        }
        if (IsKeyPressed(KEY_LEFT) && game.snake.direction.x != 1 && allowMove)
        {
            game.snake.direction = {-1, 0};
            game.running = true;
            allowMove = false;
        }
        if (IsKeyPressed(KEY_RIGHT) && game.snake.direction.x != -1 && allowMove)
        {
            game.snake.direction = {1, 0};
            game.running = true;
            allowMove = false;
        }

        ClearBackground(backgroundColor);
        DrawRectangleLinesEx(Rectangle{(float)offset - 5, (float)offset - 5, (float)cellSize * cellCount + 10, (float)cellSize * cellCount + 10}, 5, borderColor);
        DrawText("Game Snake", offset - 5, 20, 40, borderColor);
        DrawText(TextFormat("%i", game.score), offset - 5, offset + cellSize * cellCount + 10, 40, borderColor);
        game.Draw();

        if (game.gameWon && (GetTime() - game.winDisplayTime >= 3))
        {
            break;
        }

        EndDrawing();
    }
    CloseWindow();
    return 0;
}
