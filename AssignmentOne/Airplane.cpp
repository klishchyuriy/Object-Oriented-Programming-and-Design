#include "Airplane.h"
#include <iostream>

Airplane::Airplane(const std::string &flightNumber, const std::string &date, int rows, int seatsPerRow)
        : flightNumber(flightNumber), date(date), rows(rows), seatsPerRow(seatsPerRow) {
    seatAvailability = std::vector<std::vector<bool>>(rows, std::vector<bool>(seatsPerRow, false));
}

bool Airplane::isSeatAvailable(int row, int seat) const {
    if (row < 0 || row >= rows || seat < 0 || seat >= seatsPerRow) {
        std::cerr << "Error: Invalid seat number!" << std::endl;
        return false;
    }
    return !seatAvailability[row][seat];
}

bool Airplane::bookSeat(int row, int seat, const std::string &passengerName) {
    if (isSeatAvailable(row, seat)) {
        seatAvailability[row][seat] = true;
        Ticket ticket(passengerName, flightNumber, date, row, seat);
        bookedTickets.push_back(ticket);
        return true;
    }
    std::cerr << "Error: Seat is not available!" << std::endl;
    return false;
}

bool Airplane::returnSeat(int row, int seat) {
    if (row >= 0 && row < rows && seat >= 0 && seat < seatsPerRow && seatAvailability[row][seat]) {
        seatAvailability[row][seat] = false;
        return true;
    }
    std::cerr << "Error: Invalid seat number or seat not booked!" << std::endl;
    return false;
}

void Airplane::displayAvailableSeats() const {
    std::cout << "Available seats for flight " << flightNumber << " on " << date << ":" << std::endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < seatsPerRow; ++j) {
            std::cout << (seatAvailability[i][j] ? "X" : "O") << " "; // X for booked, O for available
        }
        std::cout << std::endl;
    }
}

std::string Airplane::getFlightNumber() const {
    return flightNumber;
}

std::string Airplane::getDate() const {
    return date;
}
