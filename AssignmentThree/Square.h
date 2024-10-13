#ifndef SQUARE_H
#define SQUARE_H

#include "Shape.h"

class Square : public Shape {
    int size;

public:
    Square(int x, int y, int size, const std::string& color, bool filled)
            : Shape(x, y, color, filled), size(size) {}

    void draw(std::vector<std::vector<char>>& board) const override;
    void print() const override;
};

#endif
