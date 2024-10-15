#include "Line.h"
#include <iostream>

Line::Line(int x1, int y1, int x2, int y2, std::string color)
        : x1(x1), y1(y1), x2(x2), y2(y2), color(color) {}

void Line::draw(std::vector<std::vector<char>>& board) const {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;

    int x = x1;
    int y = y1;

    while (true) {
        if (x >= 0 && x < board[0].size() && y >= 0 && y < board.size()) {
            board[y][x * 2] = color[0];  // Use the first letter of the color
        }

        if (x == x2 && y == y2) break;

        int e2 = 2 * err;
        if (e2 > -dy) {
            err -= dy;
            x += sx;
        }
        if (e2 < dx) {
            err += dx;
            y += sy;
        }
    }
}

void Line::print() const {
    std::cout << "Line from (" << x1 << ", " << y1 << ") to (" << x2 << ", " << y2 << ") and color " << color << std::endl;
}

void Line::edit(const std::vector<int>& newParams) {
    if (newParams.size() == 4) {
        x1 = newParams[0];
        y1 = newParams[1];
        x2 = newParams[2];
        y2 = newParams[3];
        std::cout << "Line endpoints changed to (" << x1 << ", " << y1 << ") and (" << x2 << ", " << y2 << ")" << std::endl;
    } else {
        std::cout << "Invalid number of parameters for editing line." << std::endl;
    }
}

void Line::move(int newX, int newY) {
    int dx = newX - x1;
    int dy = newY - y1;
    x1 = newX;
    y1 = newY;
    x2 += dx;
    y2 += dy;
    std::cout << "Line moved to new start (" << x1 << ", " << y1 << ") and end (" << x2 << ", " << y2 << ")" << std::endl;
}

void Line::paint(const std::string& newColor) {
    color = newColor;
    std::cout << "Line painted " << color << std::endl;
}
