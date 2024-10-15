#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.h"
#include <string>

class Triangle : public Shape {
private:
    int x, y, height;
    std::string color;

public:
    Triangle(int x, int y, int height, std::string color);
    void draw(std::vector<std::vector<char>>& board) const override;
    void print() const override;
    void edit(const std::vector<int>& newParams) override;
    void move(int newX, int newY) override;
    void paint(const std::string& newColor) override;
};

#endif
