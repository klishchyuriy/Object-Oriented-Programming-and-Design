#ifndef ASSIGNMENTONE_TICKET_H
#define ASSIGNMENTONE_TICKET_H

#include <string>

class Ticket {
private:
    std::string passengerName;
    std::string flightNumber;
    std::string date;
    int row;
    int seat;
    std::string ticketID;
    bool isBooked;

public:
    Ticket(const std::string &passengerName, const std::string &flightNumber, const std::string &date, int row, int seat, const std::string &ticketID);

    std::string getPassengerName() const;
    std::string getFlightNumber() const;
    std::string getDate() const;
    int getRow() const;
    int getSeat() const;
    std::string getTicketID() const;
    bool getBookingStatus() const;
    void setBookingStatus(bool status);
};

#endif
