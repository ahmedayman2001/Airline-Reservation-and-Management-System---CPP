
#pragma once
#include <bits/stdc++.h>
using namespace std;

//// =========================================== BOOKING CLASS ===============================================////

// Represents a flight booking and stores its associated passenger, flight, and seat details.
class Booking {

public:

    // Unique identifier assigned to the booking.
    int bookingId;

    // Identifier of the passenger who made the booking.
    int passengerId;

    // Identifier of the flight associated with the booking.
    string flightNo;

    // Reserved seat number using zero-based indexing.
    int seat ;


   // Indicates whether the passenger has completed the check-in process.
    // Defaults to false when a new booking is created.
    bool checkedIn{false} ;

};
