#include "Square.h"
#include <iostream>

Square::Square(int x, int y, int size, std::string color)
        : x(x), y(y), size(size), color(color) {}

void Square::draw(std::vector<std::vector<char>>& board) const {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            int drawX = x + j * 2;
            int drawY = y + i;
            if (i == 0 || i == size - 1 || j == 0 || j == size - 1) {
                if (drawX >= 0 && drawX < board[0].size() && drawY >= 0 && drawY < board.size()) {
                    board[drawY][drawX] = color[0];  // Use the first letter of the color
                }
            }
        }
    }
}

void Square::print() const {
    std::cout << "Square at (" << x << ", " << y << ") with size " << size << " and color " << color << std::endl;
}

void Square::edit(const std::vector<int>& newParams) {
    if (newParams.size() == 1) {
        size = newParams[0];
        std::cout << "Size changed to " << size << std::endl;
    } else {
        std::cout << "Invalid number of parameters for editing square." << std::endl;
    }
}

void Square::move(int newX, int newY) {
    x = newX;
    y = newY;
    std::cout << "Square moved to (" << x << ", " << y << ")" << std::endl;
}

void Square::paint(const std::string& newColor) {
    color = newColor;
    std::cout << "Square painted " << color << std::endl;
}
