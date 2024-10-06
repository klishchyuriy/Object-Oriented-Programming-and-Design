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
                board.addShape(std::make_shared<Circle>(x, y, radius));
            }else if (shapeType == "rectangle") {
                int x, y, width, height;
                std::cin >> x >> y >> width >> height;
                board.addShape(std::make_shared<Rectangle>(x, y, width, height));
            } else if (shapeType == "triangle") {
                int x, y, height;
                std::cin >> x >> y >> height;
                board.addShape(std::make_shared<Triangle>(x, y, height));
            } else if (shapeType == "square") {
                int x, y, size;
                std::cin >> x >> y >> size;
                board.addShape(std::make_shared<Square>(x, y, size));
            }else if (shapeType == "line") {
                int x1, y1, x2, y2;
                std::cin >> x1 >> y1 >> x2 >> y2;
                board.addShape(std::make_shared<Line>(x1, y1, x2, y2));
            }else {
                std::cout << "Unknown shape type.\n";
            }
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
