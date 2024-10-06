#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.h"
#include <iostream>

class Triangle : public Shape {
private:
    int x, y, height;

public:
    Triangle(int x, int y, int height);
    void draw(std::vector<std::vector<char>>& board) const override;
    void print() const override;
};

#endif
