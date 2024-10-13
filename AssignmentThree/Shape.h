#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
#include <string>
#include <vector>

class Shape {
protected:
    int x, y;
    std::string color;
    bool filled;

public:
    Shape(int x, int y, const std::string& color, bool filled)
            : x(x), y(y), color(color), filled(filled) {}

    virtual void draw(std::vector<std::vector<char>>& board) const = 0;
    virtual void print() const = 0;
    void setColor(const std::string& newColor) { color = newColor; }
    void setFilled(bool isFilled) { filled = isFilled; }

    virtual ~Shape() = default;
};

#endif
