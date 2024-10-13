#ifndef SHAPE_H
#define SHAPE_H

#include <vector>

class Shape {
public:
    virtual void draw(std::vector<std::vector<char>>& board) const = 0;
    virtual void print() const = 0;
    virtual ~Shape() = default;
};

#endif
