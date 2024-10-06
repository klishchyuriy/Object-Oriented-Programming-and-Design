#ifndef SQUARE_H
#define SQUARE_H

#include "Shape.h"
#include <iostream>

class Square : public Shape {
private:
    int x, y, size;

public:
    Square(int x, int y, int size);
    void draw(std::vector<std::vector<char>>& board) const override;
    void print() const override;
};

#endif
