#include "Board.h"
#include <iostream>
#include <memory>
#include "Circle.h"

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
            } else {
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
