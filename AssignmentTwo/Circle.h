#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"
#include <iostream>

class Circle : public Shape {
private:
    int x, y, radius;

public:
    Circle(int x, int y, int radius);
    void draw(std::vector<std::vector<char>>& board) const override;
    void print() const override;
};

#endif
