#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"
#include <string>

class Circle : public Shape {
private:
    int x, y, radius;
    std::string color;

public:
    Circle(int x, int y, int radius, std::string color);
    void draw(std::vector<std::vector<char>>& board) const override;
    void print() const override;
    void edit(const std::vector<int>& newParams) override;
    void move(int newX, int newY) override;
    void paint(const std::string& newColor) override;
};

#endif
