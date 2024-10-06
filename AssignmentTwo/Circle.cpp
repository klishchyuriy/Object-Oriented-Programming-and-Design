#include "Circle.h"

Circle::Circle(int x, int y, int radius) : x(x), y(y), radius(radius) {}

void Circle::draw(std::vector<std::vector<char>>& board) const {
    for (int i = -radius; i <= radius; ++i) {
        for (int j = -radius; j <= radius; ++j) {
            if (i * i + j * j <= radius * radius) {
                int drawX = x + j;
                int drawY = y + i;
                if (drawX >= 0 && drawX < board[0].size() && drawY >= 0 && drawY < board.size()) {
                    board[drawY][drawX] = '*';
                }
            }
        }
    }
}

void Circle::print() const {
    std::cout << "Circle at (" << x << ", " << y << ") with radius " << radius << "\n";
}
