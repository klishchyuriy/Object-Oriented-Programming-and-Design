#include "Square.h"

Square::Square(int x, int y, int size) : x(x), y(y), size(size) {}

void Square::draw(std::vector<std::vector<char>>& board) const {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            int drawX = x + j * 2;
            int drawY = y + i;

            if (i == 0 || i == size - 1 || j == 0 || j == size - 1) {
                if (drawX >= 0 && drawX < board[0].size() && drawY >= 0 && drawY < board.size()) {
                    board[drawY][drawX] = '*';
                }
            }
        }
    }
}

void Square::print() const {
    std::cout << "Square at (" << x << ", " << y << ") with side length " << size << std::endl;
}
