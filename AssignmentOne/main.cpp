#include <iostream>
#include <vector>
#include "Airplane.h"
#include "FileReader.h"

int main() {
    std::vector<Airplane> airplanes = FileReader::readConfigFile("/Users/klishchyuriy/Desktop/OOP/Object-Oriented-Programming-and-Design/AssignmentOne/flights.txt");

    while (true) {
        std::string command;
        std::cout << "> ";
        std::cin >> command;

        if (command == "check") {
            std::string date, flightNumber;
            std::cin >> date >> flightNumber;

            for (const auto &airplane : airplanes) {
                if (airplane.getDate() == date && airplane.getFlightNumber() == flightNumber) {
                    airplane.displayAvailableSeats();
                }
            }
        } else if (command == "book") {
            std::string date, flightNumber, passengerName;
            int row, seat;
            std::cin >> date >> flightNumber >> row >> seat >> passengerName;

            for (auto &airplane : airplanes) {
                if (airplane.getDate() == date && airplane.getFlightNumber() == flightNumber) {
                    if (airplane.bookSeat(row, seat, passengerName)) {
                        std::cout << "Seat booked successfully for " << passengerName << std::endl;
                    } else {
                        std::cout << "Seat not available!" << std::endl;
                    }
                }
            }
        } else if (command == "return") {
            std::string date, flightNumber;
            int row, seat;
            std::cin >> date >> flightNumber >> row >> seat;

            for (auto &airplane : airplanes) {
                if (airplane.getDate() == date && airplane.getFlightNumber() == flightNumber) {
                    if (airplane.returnSeat(row, seat)) {
                        std::cout << "Ticket returned successfully!" << std::endl;
                    } else {
                        std::cout << "Seat not found or not booked!" << std::endl;
                    }
                }
            }
        } else if (command == "exit") {
            break;
        } else {
            std::cout << "Unknown command!" << std::endl;
        }
    }

    return 0;
}
