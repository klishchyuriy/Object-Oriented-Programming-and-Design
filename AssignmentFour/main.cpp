#include "Game.h"

int main()
{
    InitWindow(800, 600, "Snake Game");
    SetTargetFPS(60);

    Game game;

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        game.updateLogic();
        game.render();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
