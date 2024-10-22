#include "raylib.h"
#include "Game.h"

int main() {
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Snake Game");

    Game game;
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        if (game.running) {
            game.Update();
        }

        game.Draw();

        EndDrawing();
    }

    CloseWindow();

    return 0;
}