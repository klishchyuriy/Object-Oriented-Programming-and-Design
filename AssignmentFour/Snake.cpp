#include "Snake.h"

Snake::Snake() : direction({1, 0}), addSegment(false), bonusSegmentCount(0)
{
    body.push_back({6, 9});
    body.push_back({5, 9});
    body.push_back({4, 9});
}

void Snake::Draw() const
{
    for (auto &segment : body)
    {
        Rectangle rect = {segment.x * 30 + 75, segment.y * 30 + 75, 30, 30};
        DrawRectangleRec(rect, GREEN);
    }
}

void Snake::ProcessGameUpdate()
{
    Vector2 nextPosition = {body.front().x + direction.x, body.front().y + direction.y};
    body.push_front(nextPosition);

    if (!addSegment)
    {
        body.pop_back();
    }
    addSegment = false;
}

void Snake::Reset()
{
    body.clear();
    body.push_back({6, 9});
    body.push_back({5, 9});
    body.push_back({4, 9});
    direction = {1, 0};
    addSegment = false;
    bonusSegmentCount = 0;
}
