#ifndef ASSIGNMENTONE_AIRPLANE_H
#define ASSIGNMENTONE_AIRPLANE_H

#include <string>
#include <vector>
#include "Ticket.h"

class Airplane {
private:
    std::string flightNumber;
    std::string date;
    int rows;
    int seatsPerRow;
    std::vector<std::vector<bool>> seatAvailability;
    std::vector<Ticket> bookedTickets;
    std::vector<std::pair<std::string, std::string>> pricing;

public:
    Airplane(const std::string &flightNumber, const std::string &date, int seatsPerRow, const std::vector<std::pair<std::string, std::string>> &pricing);

    bool isSeatAvailable(int row, int seat) const;
    bool bookSeat(int row, int seat, const std::string &passengerName);
    bool returnSeat(int row, int seat);
    void displayAvailableSeats() const;
    void viewTickets() const;

    std::string getFlightNumber() const;
    std::string getDate() const;
};

#endif
