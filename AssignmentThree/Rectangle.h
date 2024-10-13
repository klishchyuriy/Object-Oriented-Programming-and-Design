#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"

class Rectangle : public Shape {
    int width, height;

public:
    Rectangle(int x, int y, int width, int height, const std::string& color, bool filled)
            : Shape(x, y, color, filled), width(width), height(height) {}

    void draw(std::vector<std::vector<char>>& board) const override;
    void print() const override;
};

#endif
