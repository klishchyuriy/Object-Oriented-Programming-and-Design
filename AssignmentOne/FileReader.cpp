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
        int seatsPerRow;

        if (!(iss >> date >> flightNumber >> seatsPerRow)) {
            std::cerr << "Error: Incorrect file format!" << std::endl;
            continue;
        }

        std::vector<std::pair<std::string, std::string>> pricing;
        std::string rowRange, price;

        while (iss >> rowRange >> price) {
            pricing.push_back({rowRange, price});
        }

        Airplane airplane(flightNumber, date, seatsPerRow, pricing);
        airplanes.push_back(airplane);
    }

    return airplanes;
}
