#ifndef LINE_H
#define LINE_H

#include "Shape.h"

class Line : public Shape {
    int x2, y2;

public:
    Line(int x1, int y1, int x2, int y2, const std::string& color)
            : Shape(x1, y1, color, false), x2(x2), y2(y2) {}

    void draw(std::vector<std::vector<char>>& board) const override;
    void print() const override;
};

#endif
