#include "Triangle.h"
#include <iostream>

Triangle::Triangle(int x, int y, int height, std::string color) : x(x), y(y), height(height), color(color) {}

void Triangle::draw(std::vector<std::vector<char>>& board) const {
    for (int i = 0; i < height; ++i) {
        int leftX = x - i;
        int rightX = x + i;
        int currentY = y + i;

        if (currentY >= 0 && currentY < board.size()) {
            if (leftX >= 0 && leftX < board[0].size()) {
                board[currentY][leftX] = color[0];  // Use the first letter of the color
            }
            if (rightX >= 0 && rightX < board[0].size() && leftX != rightX) {
                board[currentY][rightX] = color[0];
            }
        }
    }

    int baseY = y + height - 1;
    if (baseY >= 0 && baseY < board.size()) {
        for (int i = -height + 1; i < height; ++i) {
            int drawX = x + i;
            if (drawX >= 0 && drawX < board[0].size()) {
                board[baseY][drawX] = color[0];
            }
        }
    }
}

void Triangle::print() const {
    std::cout << "Triangle at (" << x << ", " << y << ") with height " << height << " and color " << color << "\n";
}

void Triangle::edit(const std::vector<int>& newParams) {
    if (newParams.size() == 1) {
        height = newParams[0];
        std::cout << "Height changed to " << height << std::endl;
    } else {
        std::cout << "Invalid number of parameters for editing triangle." << std::endl;
    }
}

void Triangle::move(int newX, int newY) {
    x = newX;
    y = newY;
    std::cout << "Triangle moved to (" << x << ", " << y << ")" << std::endl;
}

void Triangle::paint(const std::string& newColor) {
    color = newColor;
    std::cout << "Triangle painted " << color << std::endl;
}
