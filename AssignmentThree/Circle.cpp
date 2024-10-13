#include "Circle.h"
#include <cmath>

void Circle::draw(std::vector<std::vector<char>>& board) const {
    for (int i = -radius; i <= radius; ++i) {
        for (int j = -radius; j <= radius; ++j) {
            if (std::round(std::sqrt(i * i + j * j)) == radius) {
                int drawX = x + j * 2;
                int drawY = y + i;
                if (drawX >= 0 && drawX < board[0].size() && drawY >= 0 && drawY < board.size()) {
                    board[drawY][drawX] = color[0];  // Use color's first letter
                }
            }
        }
    }
}

void Circle::print() const {
    std::cout << "Circle at (" << x << ", " << y << ") with radius " << radius
              << " and color " << color << (filled ? " (filled)" : " (framed)") << std::endl;
}
