#include "Snake.h"

Snake::Snake()
{
    body = {Vector2{6, 9}, Vector2{5, 9}, Vector2{4, 9}};
    movementDirection = {1, 0};
}

void Snake::render()
{
    for (unsigned int i = 0; i < body.size(); i++)
    {
        DrawRectangle(body[i].x * 20, body[i].y * 20, 20, 20, DARKGREEN);
    }
}
