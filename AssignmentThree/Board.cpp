#include "Board.h"
#include <fstream>
#include <iostream>

const int BOARD_WIDTH = 80;
const int BOARD_HEIGHT = 25;

Board::Board() : grid(BOARD_HEIGHT, std::vector<char>(BOARD_WIDTH, ' ')), selectedShapeIndex(-1) {}

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
        shape->print();  // Modify this if you want to serialize shapes to a file
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

    shapes.clear();  // Modify this to load actual shape data
    file.close();
    std::cout << "Board loaded from " << filePath << "\n";
}

void Board::editShape(int shapeIndex, const std::vector<int>& newParams) {
    if (shapeIndex >= 0 && shapeIndex < shapes.size()) {
        shapes[shapeIndex]->edit(newParams);
        std::cout << "Shape edited successfully.\n";
    } else {
        std::cout << "Invalid shape index.\n";
    }
}

void Board::moveShape(int shapeIndex, int newX, int newY) {
    if (shapeIndex >= 0 && shapeIndex < shapes.size()) {
        shapes[shapeIndex]->move(newX, newY);
        std::cout << "Shape moved successfully.\n";
    } else {
        std::cout << "Invalid shape index.\n";
    }
}

void Board::paintShape(int shapeIndex, const std::string& newColor) {
    if (shapeIndex >= 0 && shapeIndex < shapes.size()) {
        shapes[shapeIndex]->paint(newColor);
        std::cout << "Shape painted successfully.\n";
    } else {
        std::cout << "Invalid shape index.\n";
    }
}

void Board::removeShape(int shapeIndex) {
    if (shapeIndex >= 0 && shapeIndex < shapes.size()) {
        shapes.erase(shapes.begin() + shapeIndex);
        std::cout << "Shape " << shapeIndex + 1 << " removed.\n";
    } else {
        std::cout << "Shape was not found\n";
    }
}

void Board::selectShape(int shapeIndex) {
    if (shapeIndex >= 0 && shapeIndex < shapes.size()) {
        selectedShapeIndex = shapeIndex;
        std::cout << "Shape " << shapeIndex + 1 << " selected.\n";
    } else {
        std::cout << "Shape was not found\n";
    }
}
