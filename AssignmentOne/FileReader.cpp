#include "FileReader.h"
#include <fstream>
#include <iostream>
#include <sstream>

std::vector<Airplane> FileReader::readConfigFile(const std::string &filePath) {
    std::vector<Airplane> airplanes;
    std::ifstream file(filePath);

    if (!file) {
        std::cerr << "Error: File not found!" << std::endl;
        return airplanes;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string date, flightNumber;
        int rows, seatsPerRow;

        if (!(iss >> date >> flightNumber >> seatsPerRow >> rows)) {
            std::cerr << "Error: Incorrect file format!" << std::endl;
            continue;
        }

        Airplane airplane(flightNumber, date, rows, seatsPerRow);
        airplanes.push_back(airplane);
    }

    return airplanes;
}
