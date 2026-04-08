#pragma once
#include <bits/stdc++.h>
#include "Booking.h"
#include "Globals.h"
using namespace std;


////======================================== CHICK IN SERVICE CLASS ===========================================////



class CheckInService {

public:

    static void checkIn(int bookingId) {

        if ( !bookings.count(bookingId) ) {

            cout << "Booking not found.\n" ;

            return ;
        }

        bookings[bookingId]->checkedIn = true;

        cout << "Check-in completed. Booking ID: " << bookingId << "\n" ;

    }
};

