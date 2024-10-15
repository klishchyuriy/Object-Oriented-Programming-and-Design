#ifndef SQUARE_H
#define SQUARE_H

#include "Shape.h"
#include <string>

class Square : public Shape {
private:
    int x, y, size;
    std::string color;

public:
    Square(int x, int y, int size, std::string color);
    void draw(std::vector<std::vector<char>>& board) const override;
    void print() const override;
    void edit(const std::vector<int>& newParams) override;
    void move(int newX, int newY) override;
    void paint(const std::string& newColor) override;
};

#endif
