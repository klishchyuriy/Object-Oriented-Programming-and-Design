#include "Line.h"
#include <cmath>

Line::Line(int x1, int y1, int x2, int y2) : x1(x1), y1(y1), x2(x2), y2(y2) {}

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
            board[y][x] = '*';
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
    std::cout << "Line from (" << x1 << ", " << y1 << ") to (" << x2 << ", " << y2 << ")\n";
}
