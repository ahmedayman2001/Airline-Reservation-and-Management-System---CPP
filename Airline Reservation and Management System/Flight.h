
#pragma once
#include <bits/stdc++.h>
#include "Aircraft.h"
using namespace std;



//// ========================================= (FLIGHT CLASS (Association with Aircraft Class )) ==========================================////


// Represents a flight and maintains its schedule, pricing, assigned aircraft, and seat availability.
class Flight {

public:


    // Unique flight identifier.
    string flightNo ;

    // Departure location.
    string from ;

    // Arrival location.
    string to ;

    // Scheduled departure time.
    string time ;

    // Scheduled flight date.
    string date ;

    // Ticket price for the flight.
    double price ;

    // Pointer to the aircraft assigned to this flight.
    Aircraft *aircraft ;


   // Stores the booking status of each seat.
    // false = available, true = booked.
    vector<bool> seats ;  /// Status of Seats (free or complete (0 ,or 1 )) ///


    //// ================== Constructor ================== ////


    // Initializes a flight with its schedule, price, and assigned aircraft.
    Flight(string f ,string o , string d , string t ,string dt , double pr ,  Aircraft * a ) {

        flightNo = f ;
        from = o ;
        to = d ;
        time = t ;
        date = dt ;
        price = pr ;
        aircraft = a ;

        // Initializes all seats as available based on the aircraft capacity.
        seats.assign(a->capacity , false ) ;  /// All Seats are free now ////
    }


    //// ================== Seat Booking ================== ////


   // Attempts to reserve the specified seat.
    // Returns true if the seat is successfully booked; otherwise, returns false.
    bool  bookSeat (int seat) {


    // Rejects seat numbers outside the valid range.
        if (seat  < 0  || seat >= seats.size() )
            return false ;


    // Books the seat only if it is currently available.
        if (!seats[seat]){

            seats[seat] = true ;
            return true ;
        }

        
    // Returns false when the seat is already booked.
        return false ;
    }


};
