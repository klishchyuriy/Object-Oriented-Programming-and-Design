#include <iostream>
#include <raylib.h>
#include <deque>

using namespace std;

static bool allowMove = false;
Color green = {173, 204, 96, 255};
Color darkGreen = {43, 51, 24, 255};

int cellSize = 30;
int cellCount = 10;
int offset = 75;

double lastUpdateTime = 0;

bool ElementInDeque(Vector2 element, deque<Vector2> deque)
{
    for (unsigned int i = 0; i < deque.size(); i++)
    {
        if (element.x == deque[i].x && element.y == deque[i].y)
        {
            return true;
        }
    }
    return false;
}

bool EventTriggered(double interval)
{
    double currentTime = GetTime();
    if (currentTime - lastUpdateTime >= interval)
    {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}

Vector2 AddVectors(Vector2 v1, Vector2 v2)
{
    return Vector2{v1.x + v2.x, v1.y + v2.y};
}

bool EqualsVectors(Vector2 v1, Vector2 v2)
{
    return (v1.x == v2.x && v1.y == v2.y);
}

class Snake
{
public:
    deque<Vector2> body = {Vector2{6, 9}, Vector2{5, 9}, Vector2{4, 9}};
    Vector2 direction = {1, 0};
    bool addSegment = false;
    int bonusSegmentCount = 0;

    void Draw()
    {
        for (unsigned int i = 0; i < body.size(); i++)
        {
            float x = body[i].x;
            float y = body[i].y;
            Rectangle segment = Rectangle{offset + x * cellSize, offset + y * cellSize, (float)cellSize, (float)cellSize};
            DrawRectangleRounded(segment, 0.5, 6, darkGreen);
        }
    }

    void Update()
    {
        body.push_front(AddVectors(body[0], direction));

        if (addSegment == true)
        {
            addSegment = false;
        }
        else if (bonusSegmentCount > 0)
        {
            bonusSegmentCount--;
        }
        else
        {
            body.pop_back();
        }
    }

    void Reset()
    {
        body = {Vector2{6, 9}, Vector2{5, 9}, Vector2{4, 9}};
        direction = {1, 0};
        bonusSegmentCount = 0;
    }
};

class Apple
{
public:
    Vector2 position;

    Apple(deque<Vector2> snakeBody)
    {
        position = GenerateRandomPos(snakeBody);
    }

    void Draw()
    {
        DrawRectangle(offset + position.x * cellSize, offset + position.y * cellSize, cellSize, cellSize, GREEN);
    }

    Vector2 GenerateRandomCell()
    {
        float x = GetRandomValue(0, cellCount - 1);
        float y = GetRandomValue(0, cellCount - 1);
        return Vector2{x, y};
    }

    Vector2 GenerateRandomPos(deque<Vector2> snakeBody)
    {
        Vector2 position = GenerateRandomCell();
        while (ElementInDeque(position, snakeBody))
        {
            position = GenerateRandomCell();
        }
        return position;
    }
};

class BonusApple : public Apple
{
public:
    BonusApple(deque<Vector2> snakeBody) : Apple(snakeBody) {}

    void Draw()
    {
        DrawRectangle(offset + position.x * cellSize, offset + position.y * cellSize, cellSize, cellSize, RED);
    }
};

class Game
{
public:
    Snake snake = Snake();
    Apple apple = Apple(snake.body);
    BonusApple bonusApple = BonusApple(snake.body);
    bool running = true;
    int score = 0;
    int maxSnakeSize = cellCount * cellCount;
    bool gameWon = false;
    double winDisplayTime = 0;

    void Draw()
    {
        apple.Draw();
        bonusApple.Draw();
        snake.Draw();

        if (gameWon)
        {
            int winTextWidth = MeasureText("You Win!", 60);
            DrawText("You Win!", (GetScreenWidth() - winTextWidth) / 2, (GetScreenHeight() - 60) / 2, 60, RED);
        }
    }

    void Update()
    {
        if (running && !gameWon)
        {
            snake.Update();
            CheckCollisionWithApple();
            CheckCollisionWithBonusApple();
            CheckCollisionWithEdges();
            CheckCollisionWithTail();
            CheckWinCondition();
        }
    }

    void CheckCollisionWithApple()
    {
        if (EqualsVectors(snake.body[0], apple.position))
        {
            apple.position = apple.GenerateRandomPos(snake.body);
            snake.addSegment = true;
            score++;
        }
    }

    void CheckCollisionWithBonusApple()
    {
        if (EqualsVectors(snake.body[0], bonusApple.position))
        {
            bonusApple.position = bonusApple.GenerateRandomPos(snake.body);
            snake.bonusSegmentCount += 50;
            score += 3;
        }
    }

    void CheckCollisionWithEdges()
    {
        if (snake.body[0].x == cellCount || snake.body[0].x == -1)
        {
            GameOver();
        }
        if (snake.body[0].y == cellCount || snake.body[0].y == -1)
        {
            GameOver();
        }
    }

    void CheckCollisionWithTail()
    {
        deque<Vector2> headlessBody = snake.body;
        headlessBody.pop_front();
        if (ElementInDeque(snake.body[0], headlessBody))
        {
            GameOver();
        }
    }

    void CheckWinCondition()
    {
        if (snake.body.size() >= maxSnakeSize)
        {
            gameWon = true;
            running = false;
            winDisplayTime = GetTime();
        }
    }

    void GameOver()
    {
        snake.Reset();
        apple.position = apple.GenerateRandomPos(snake.body);
        bonusApple.position = bonusApple.GenerateRandomPos(snake.body);
        running = false;
        score = 0;
    }
};

int main()
{
    cout << "Starting the game..." << endl;
    InitWindow(2 * offset + cellSize * cellCount, 2 * offset + cellSize * cellCount, "Game Snake");
    SetTargetFPS(60);

    Game game = Game();

    while (WindowShouldClose() == false)
    {
        BeginDrawing();

        if (EventTriggered(0.2))
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

        ClearBackground(green);
        DrawRectangleLinesEx(Rectangle{(float)offset - 5, (float)offset - 5, (float)cellSize * cellCount + 10, (float)cellSize * cellCount + 10}, 5, darkGreen);
        DrawText("Game Snake", offset - 5, 20, 40, darkGreen);
        DrawText(TextFormat("%i", game.score), offset - 5, offset + cellSize * cellCount + 10, 40, darkGreen);
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
