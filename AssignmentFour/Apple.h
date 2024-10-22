#pragma once
#include <raylib.h>
#include <deque>
#include "Snake.h"

class Apple
{
public:
    Vector2 position;
    Color appleColor;

    Apple(std::deque<Vector2> snakeBody);
    virtual void Draw() const;
    Vector2 GenerateRandomCell() const;
    Vector2 GenerateRandomPos(std::deque<Vector2> snakeBody) const;
};

class BonusApple : public Apple
{
public:
    Color bonusAppleColor;

    BonusApple(std::deque<Vector2> snakeBody);
    void Draw() const override;
};
