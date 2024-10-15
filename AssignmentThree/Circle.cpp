#include "Circle.h"
#include <cmath>
#include <iostream>

Circle::Circle(int x, int y, int radius, std::string color) : x(x), y(y), radius(radius), color(color) {}

void Circle::draw(std::vector<std::vector<char>>& board) const {
    for (int i = -radius; i <= radius; ++i) {
        for (int j = -radius; j <= radius; ++j) {
            if (std::round(std::sqrt(i * i + j * j)) == radius) {
                int drawX = x + j * 2;
                int drawY = y + i;
                if (drawX >= 0 && drawX < board[0].size() && drawY >= 0 && drawY < board.size()) {
                    board[drawY][drawX] = color[0];
                }
            }
        }
    }
}

void Circle::print() const {
    std::cout << "Circle at (" << x << ", " << y << ") with radius " << radius << " and color " << color << std::endl;
}

void Circle::edit(const std::vector<int>& newParams) {
    if (newParams.size() == 1) {
        radius = newParams[0];
        std::cout << "Radius changed to " << radius << std::endl;
    } else {
        std::cout << "Invalid number of parameters for editing circle." << std::endl;
    }
}

void Circle::move(int newX, int newY) {
    x = newX;
    y = newY;
    std::cout << "Circle moved to (" << x << ", " << y << ")" << std::endl;
}

void Circle::paint(const std::string& newColor) {
    color = newColor;
    std::cout << "Circle painted " << color << std::endl;
}
