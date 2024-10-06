#include "Rectangle.h"

Rectangle::Rectangle(int x, int y, int width, int height) : x(x), y(y), width(width), height(height) {}

void Rectangle::draw(std::vector<std::vector<char>>& board) const {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            int drawX = x + j;
            int drawY = y + i;
            if (drawX >= 0 && drawX < board[0].size() && drawY >= 0 && drawY < board.size()) {
                board[drawY][drawX] = '*';
            }
        }
    }
}

void Rectangle::print() const {
    std::cout << "Rectangle at (" << x << ", " << y << ") with width " << width << " and height " << height << "\n";
}
