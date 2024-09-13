#include "Ticket.h"

Ticket::Ticket(const std::string &passengerName, const std::string &flightNumber, const std::string &date, int row, int seat, const std::string &ticketID)
        : passengerName(passengerName), flightNumber(flightNumber), date(date), row(row), seat(seat), ticketID(ticketID), isBooked(true) {}

std::string Ticket::getPassengerName() const {
    return passengerName;
}

std::string Ticket::getFlightNumber() const {
    return flightNumber;
}

std::string Ticket::getDate() const {
    return date;
}

int Ticket::getRow() const {
    return row;
}

int Ticket::getSeat() const {
    return seat;
}

std::string Ticket::getTicketID() const {
    return ticketID;
}

bool Ticket::getBookingStatus() const {
    return isBooked;
}

void Ticket::setBookingStatus(bool status) {
    isBooked = status;
}
