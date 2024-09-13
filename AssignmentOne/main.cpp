#include <iostream>
#include <vector>
#include "Airplane.h"
#include "FileReader.h"

int main() {
    std::vector<Airplane> airplanes = FileReader::readConfigFile("/Users/klishchyuriy/Desktop/OOP/Object-Oriented-Programming-and-Design/AssignmentOne/flights.txt");

    std::string command;
    while (true) {
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
                    airplane.bookSeat(row, seat, passengerName);
                }
            }
        } else if (command == "return") {
            std::string date, flightNumber;
            int row, seat;
            std::cin >> date >> flightNumber >> row >> seat;

            for (auto &airplane: airplanes) {
                if (airplane.getDate() == date && airplane.getFlightNumber() == flightNumber) {
                    airplane.returnSeat(row, seat);
                }
            }
        } else if (command == "view") {
            std::string date, flightNumber;
            std::cin >> date >> flightNumber;

            for (const auto &airplane : airplanes) {
                if (airplane.getDate() == date && airplane.getFlightNumber() == flightNumber) {
                    airplane.viewTickets();
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
