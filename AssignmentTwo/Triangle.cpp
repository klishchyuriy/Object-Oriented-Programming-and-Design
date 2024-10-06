#include "Triangle.h"

Triangle::Triangle(int x, int y, int height) : x(x), y(y), height(height) {}

void Triangle::draw(std::vector<std::vector<char>>& board) const {
    for (int i = 0; i < height; ++i) {
        int leftX = x - i;
        int rightX = x + i;
        int currentY = y + i;

        if (currentY >= 0 && currentY < board.size()) {
            if (leftX >= 0 && leftX < board[0].size()) {
                board[currentY][leftX] = '*';
            }
            if (rightX >= 0 && rightX < board[0].size() && leftX != rightX) {
                board[currentY][rightX] = '*';
            }
        }
    }

    int baseY = y + height - 1;
    if (baseY >= 0 && baseY < board.size()) {
        for (int i = -height + 1; i < height; ++i) {
            int drawX = x + i;
            if (drawX >= 0 && drawX < board[0].size()) {
                board[baseY][drawX] = '*';
            }
        }
    }
}

void Triangle::print() const {
    std::cout << "Triangle at (" << x << ", " << y << ") with height " << height << "\n";
}
