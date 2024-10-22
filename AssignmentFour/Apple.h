#ifndef APPLE_H
#define APPLE_H

#include <raylib.h>
#include <deque>

class Apple
{
public:
    Vector2 position;

    Apple();
    void render();
    Vector2 randomPosition(std::deque<Vector2> snakeBody);
};

#endif
