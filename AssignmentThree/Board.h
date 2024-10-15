#ifndef BOARD_H
#define BOARD_H

#include "Shape.h"
#include <vector>
#include <memory>
#include <string>

class Board {
private:
    std::vector<std::vector<char>> grid;
    std::vector<std::shared_ptr<Shape>> shapes;

public:
    Board();
    void draw();
    void list();
    void addShape(std::shared_ptr<Shape> shape);
    void undo();
    void clear();
    void save(const std::string& filePath);
    void load(const std::string& filePath);
    void editShape(int shapeIndex, const std::vector<int>& newParams);
    void moveShape(int shapeIndex, int newX, int newY);
    void paintShape(int shapeIndex, const std::string& newColor);
};

#endif
