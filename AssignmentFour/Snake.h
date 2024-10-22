#pragma once
#include <raylib.h>
#include <deque>

class Snake
{
public:
    std::deque<Vector2> body;
    Vector2 direction;
    bool addSegment;
    int bonusSegmentCount;

    Snake();
    void Draw() const;
    void ProcessGameUpdate();
    void Reset();
};
