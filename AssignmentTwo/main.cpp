#include "Board.h"
#include <iostream>


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
