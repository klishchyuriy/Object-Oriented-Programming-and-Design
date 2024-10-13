#ifndef LINE_H
#define LINE_H

#include "Shape.h"
#include <iostream>

class Line : public Shape {
private:
    int x1, y1, x2, y2;

public:
    Line(int x1, int y1, int x2, int y2);
    void draw(std::vector<std::vector<char>>& board) const override;
    void print() const override;
};

#endif
