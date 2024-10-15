#include "Board.h"
#include <iostream>
#include <memory>
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Square.h"
#include "Line.h"

int main() {
    Board board;
    std::string command;

    while (true) {
        std::cout << "> ";
        std::cin >> command;

        if (command == "draw") {
            board.draw();
        } else if (command == "list") {
            board.list();
        } else if (command == "add") {
            std::string shapeType;
            std::cin >> shapeType;

            if (shapeType == "circle") {
                int x, y, radius;
                std::cin >> x >> y >> radius;
                std::string color;
                std::cin >> color;
                board.addShape(std::make_shared<Circle>(x, y, radius, color));
            } else if (shapeType == "rectangle") {
                int x, y, width, height;
                std::cin >> x >> y >> width >> height;
                std::string color;
                std::cin >> color;
                board.addShape(std::make_shared<Rectangle>(x, y, width, height, color));
            } else if (shapeType == "triangle") {
                int x, y, height;
                std::cin >> x >> y >> height;
                std::string color;
                std::cin >> color;
                board.addShape(std::make_shared<Triangle>(x, y, height, color));
            } else if (shapeType == "square") {
                int x, y, size;
                std::cin >> x >> y >> size;
                std::string color;
                std::cin >> color;
                board.addShape(std::make_shared<Square>(x, y, size, color));
            } else if (shapeType == "line") {
                int x1, y1, x2, y2;
                std::cin >> x1 >> y1 >> x2 >> y2;
                std::string color;
                std::cin >> color;
                board.addShape(std::make_shared<Line>(x1, y1, x2, y2, color));
            } else {
                std::cout << "Unknown shape type.\n";
            }
        } else if (command == "edit") {
            int shapeIndex;
            std::cin >> shapeIndex;
            std::string shapeType;
            std::cin >> shapeType;

            if (shapeType == "circle") {
                int newRadius;
                std::cin >> newRadius;
                board.editShape(shapeIndex - 1, {newRadius});
            } else if (shapeType == "rectangle") {
                int newWidth, newHeight;
                std::cin >> newWidth >> newHeight;
                board.editShape(shapeIndex - 1, {newWidth, newHeight});
            } else if (shapeType == "triangle") {
                int newHeight;
                std::cin >> newHeight;
                board.editShape(shapeIndex - 1, {newHeight});
            } else if (shapeType == "square") {
                int newSize;
                std::cin >> newSize;
                board.editShape(shapeIndex - 1, {newSize});
            } else if (shapeType == "line") {
                int newX1, newY1, newX2, newY2;
                std::cin >> newX1 >> newY1 >> newX2 >> newY2;
                board.editShape(shapeIndex - 1, {newX1, newY1, newX2, newY2});
            } else {
                std::cout << "Unknown shape type.\n";
            }
        } else if (command == "move") {
            int shapeIndex, newX, newY;
            std::cin >> shapeIndex >> newX >> newY;

            board.moveShape(shapeIndex - 1, newX, newY);
        } else if (command == "undo") {
            board.undo();
        } else if (command == "clear") {
            board.clear();
        } else if (command == "save") {
            std::string filePath;
            std::cin >> filePath;
            board.save(filePath);
        } else if (command == "load") {
            std::string filePath;
            std::cin >> filePath;
            board.load(filePath);
        } else if (command == "exit") {
            break;
        } else {
            std::cout << "Unknown command. Please try again!!!\n";
        }
    }

    return 0;
}
