#include "Line.h"
#include <cmath>

void Line::draw(std::vector<std::vector<char>>& board) const {
    int dx = std::abs(x2 - x);
    int dy = std::abs(y2 - y);
    int sx = (x < x2) ? 1 : -1;
    int sy = (y < y2) ? 1 : -1;
    int err = dx - dy;

    int xPos = x, yPos = y;

    while (true) {
        int drawX = xPos * 2;
        if (drawX >= 0 && drawX < board[0].size() && yPos >= 0 && yPos < board.size()) {
            board[yPos][drawX] = color[0];
        }
        if (xPos == x2 && yPos == y2) break;

        int e2 = 2 * err;
        if (e2 > -dy) {
            err -= dy;
            xPos += sx;
        }
        if (e2 < dx) {
            err += dx;
            yPos += sy;
        }
    }
}

void Line::print() const {
    std::cout << "Line from (" << x << ", " << y << ") to (" << x2 << ", " << y2 << ") with color "
              << color << std::endl;
}
