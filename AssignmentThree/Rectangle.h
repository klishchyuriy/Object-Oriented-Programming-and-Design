#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"
#include <string>

class Rectangle : public Shape {
private:
    int x, y, width, height;
    std::string color;

public:
    Rectangle(int x, int y, int width, int height, std::string color);
    void draw(std::vector<std::vector<char>>& board) const override;
    void print() const override;
    void edit(const std::vector<int>& newParams) override;
    void move(int newX, int newY) override;
    void paint(const std::string& newColor) override;
};

#endif
