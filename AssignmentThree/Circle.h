#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"

class Circle : public Shape {
    int radius;

public:
    Circle(int x, int y, int radius, const std::string& color, bool filled)
            : Shape(x, y, color, filled), radius(radius) {}

    void draw(std::vector<std::vector<char>>& board) const override;
    void print() const override;
};

#endif
