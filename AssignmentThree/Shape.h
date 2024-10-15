#ifndef SHAPE_H
#define SHAPE_H

#include <vector>
#include <string>

class Shape {
public:
    virtual ~Shape() = default;
    virtual void draw(std::vector<std::vector<char>>& board) const = 0;
    virtual void print() const = 0;
    virtual void edit(const std::vector<int>& newParams) = 0;
    virtual void move(int newX, int newY) = 0;
    virtual void paint(const std::string& newColor) = 0;
};

#endif
