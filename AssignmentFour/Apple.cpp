#include "Apple.h"
#include "Snake.h"

Apple::Apple(std::deque<Vector2> snakeBody) : appleColor(RED)
{
    position = GenerateRandomPos(snakeBody);
}

void Apple::Draw() const
{
    Rectangle rect = {position.x * 30 + 75, position.y * 30 + 75, 30, 30};
    DrawRectangleRec(rect, appleColor);
}

Vector2 Apple::GenerateRandomCell() const
{
    return {GetRandomValue(0, 9), GetRandomValue(0, 9)};
}

Vector2 Apple::GenerateRandomPos(std::deque<Vector2> snakeBody) const
{
    Vector2 newPos;
    do
    {
        newPos = GenerateRandomCell();
    } while (std::find(snakeBody.begin(), snakeBody.end(), newPos) != snakeBody.end());
    return newPos;
}

BonusApple::BonusApple(std::deque<Vector2> snakeBody) : Apple(snakeBody), bonusAppleColor(YELLOW)
{
}

void BonusApple::Draw() const
{
    Rectangle rect = {position.x * 30 + 75, position.y * 30 + 75, 30, 30};
    DrawRectangleRec(rect, bonusAppleColor);
}
