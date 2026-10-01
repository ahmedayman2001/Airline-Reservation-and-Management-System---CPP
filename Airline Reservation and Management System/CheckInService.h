#pragma once
#include <bits/stdc++.h>
#include "Booking.h"
#include "Globals.h"
using namespace std;


////======================================== CHICK IN SERVICE CLASS ===========================================////


// Provides operations related to passenger flight check-in.
class CheckInService {

public:

    //// ================== Check-in Operation ================== ////


    // Checks in a passenger using the specified booking ID.
    static void checkIn(int bookingId) {

    // Verifies that the requested booking exists.
        if ( !bookings.count(bookingId) ) {

            cout << "Booking not found.\n" ;

            return ;
        }

        // Marks the booking as checked in.
        bookings[bookingId]->checkedIn = true;


        // Confirms successful completion of the check-in process.
        cout << "Check-in completed. Booking ID: " << bookingId << "\n" ;

    }
};

