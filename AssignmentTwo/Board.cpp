#include "Board.h"
#include <fstream>
#include <iostream>

const int BOARD_WIDTH = 80;
const int BOARD_HEIGHT = 25;

Board::Board() : grid(BOARD_HEIGHT, std::vector<char>(BOARD_WIDTH, ' ')) {}

void Board::draw() {
    grid.assign(BOARD_HEIGHT, std::vector<char>(BOARD_WIDTH, ' '));
    for (const auto& shape : shapes) {
        shape->draw(grid);
    }

    for (const auto& row : grid) {
        for (char c : row) {
            std::cout << c;
        }
        std::cout << "\n";
    }
}

void Board::list() {
    if (shapes.empty()) {
        std::cout << "No shapes added.\n";
    } else {
        for (size_t i = 0; i < shapes.size(); ++i) {
            std::cout << "Shape " << i + 1 << ": ";
            shapes[i]->print();
        }
    }
}

void Board::addShape(std::shared_ptr<Shape> shape) {
    shapes.push_back(shape);
}

void Board::undo() {
    if (!shapes.empty()) {
        shapes.pop_back();
        std::cout << "Last shape removed.\n";
    } else {
        std::cout << "No shapes to remove.\n";
    }
}

void Board::clear() {
    shapes.clear();
    std::cout << "Board cleared.\n";
}

void Board::save(const std::string& filePath) {
    std::ofstream file(filePath);
    if (!file) {
        std::cerr << "Failed to save the file.\n";
        return;
    }

    for (const auto& shape : shapes) {
        shape->print();
    }
    file.close();
    std::cout << "Board saved to " << filePath << "\n";
}

void Board::load(const std::string& filePath) {
    std::ifstream file(filePath);
    if (!file) {
        std::cerr << "Failed to load the file.\n";
        return;
    }

    shapes.clear();
    file.close();
    std::cout << "Board loaded from " << filePath << "\n";
}
