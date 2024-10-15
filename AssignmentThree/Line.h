#ifndef LINE_H
#define LINE_H

#include "Shape.h"
#include <string>

class Line : public Shape {
private:
    int x1, y1, x2, y2;
    std::string color;

public:
    Line(int x1, int y1, int x2, int y2, std::string color);
    void draw(std::vector<std::vector<char>>& board) const override;
    void print() const override;
    void edit(const std::vector<int>& newParams) override;
    void move(int newX, int newY) override;
    void paint(const std::string& newColor) override;
};

#endif
