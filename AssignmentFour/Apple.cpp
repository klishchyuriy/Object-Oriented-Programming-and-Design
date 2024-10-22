#include "Apple.h"

Apple::Apple()
{
    position = {5, 5};
}

void Apple::render()
{
    DrawRectangle(position.x * 20, position.y * 20, 20, 20, RED);
}
