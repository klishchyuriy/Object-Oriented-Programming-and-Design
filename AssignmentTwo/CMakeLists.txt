cmake_minimum_required(VERSION 3.28)
project(AssignmentTwo)

set(CMAKE_CXX_STANDARD 26)

add_executable(AssignmentTwo main.cpp
        Board.cpp
        Board.h
        Circle.cpp
        Circle.h
        Rectangle.cpp
        Rectangle.h
        Shape.h
        Triangle.cpp
        Triangle.h
        Line.cpp
        Line.h
        Square.cpp
        Square.h)
