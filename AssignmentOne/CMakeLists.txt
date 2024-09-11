cmake_minimum_required(VERSION 3.28)
project(AssignmentOne)

set(CMAKE_CXX_STANDARD 26)

add_executable(AssignmentOne main.cpp
        Airplane.cpp
        Airplane.h
        Ticket.cpp
        Ticket.h
        FileReader.cpp
        FileReader.h)
