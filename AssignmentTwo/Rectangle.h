#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"
#include <iostream>

class Rectangle : public Shape {
private:
    int x, y, width, height;

public:
    Rectangle(int x, int y, int width, int height);
    void draw(std::vector<std::vector<char>>& board) const override;
    void print() const override;
};

#endif
