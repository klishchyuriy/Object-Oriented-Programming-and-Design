#include "Rectangle.h"

void Rectangle::draw(std::vector<std::vector<char>>& board) const {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            int drawX = x + j * 2;
            int drawY = y + i;

            if (i == 0 || i == height - 1 || j == 0 || j == width - 1) {
                if (drawX >= 0 && drawX < board[0].size() && drawY >= 0 && drawY < board.size()) {
                    board[drawY][drawX] = color[0];
                }
            }
        }
    }
}

void Rectangle::print() const {
    std::cout << "Rectangle at (" << x << ", " << y << ") with width " << width
              << " and height " << height << " and color " << color
              << (filled ? " (filled)" : " (framed)") << std::endl;
}
