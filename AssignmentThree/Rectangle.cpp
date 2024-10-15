#include "Rectangle.h"
#include <iostream>

Rectangle::Rectangle(int x, int y, int width, int height, std::string color)
        : x(x), y(y), width(width), height(height), color(color) {}

void Rectangle::draw(std::vector<std::vector<char>>& board) const {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            int drawX = x + j * 2;
            int drawY = y + i;
            if (i == 0 || i == height - 1 || j == 0 || j == width - 1) {
                if (drawX >= 0 && drawX < board[0].size() && drawY >= 0 && drawY < board.size()) {
                    board[drawY][drawX] = color[0];  // Use the first letter of the color
                }
            }
        }
    }
}

void Rectangle::print() const {
    std::cout << "Rectangle at (" << x << ", " << y << ") with width " << width
              << " and height " << height << " and color " << color << std::endl;
}

void Rectangle::edit(const std::vector<int>& newParams) {
    if (newParams.size() == 2) {
        width = newParams[0];
        height = newParams[1];
        std::cout << "Rectangle resized to width " << width << " and height " << height << std::endl;
    } else {
        std::cout << "Invalid number of parameters for editing rectangle." << std::endl;
    }
}

void Rectangle::move(int newX, int newY) {
    x = newX;
    y = newY;
    std::cout << "Rectangle moved to (" << x << ", " << y << ")" << std::endl;
}

void Rectangle::paint(const std::string& newColor) {
    color = newColor;
    std::cout << "Rectangle painted " << color << std::endl;
}
