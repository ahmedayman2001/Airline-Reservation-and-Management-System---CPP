#pragma once
#include <bits/stdc++.h>
#include "Flight.h"
#include "Booking.h"
#include "Globals.h"
#include "InputValidator.h"
using namespace std;



//// ================================================= BOOKING SERVICE CLASS ================================ ////


class BookingService {

public:

    static void createBooking(int passengerId) {

        if (flights.empty()) {
            cout << "No flights available.\n";
            return;
        }


        cout << "Available Flights:\n";

        for (auto& [id, f] : flights) {

            int availableSeats = 0;

            //// Count available seats ////

            for (bool s : f->seats)
                if (!s) availableSeats++;

            cout << "FlightNo: " << f->flightNo

                 << " | " << f->from << " -> " << f->to

                 << " | Date: " << f->date

                 << " | Time: " << f->time

                 << " | Price: $" << f->price

                 << " | Available Seats: " << availableSeats;

            if (availableSeats > 0) {

                cout << " | Seats: ";

                for (int i = 0; i < f->seats.size(); i++) {

                    if (!f->seats[i]) {

                        cout << (i + 1) << " ";   // one-based numbering
                    }
                }
            }

            else {
                cout << " | No seats available";
            }

            cout << endl;
        }




        cout << "Enter Flight Number: ";

        string fno; cin >> fno;

        if ( !flights.count(fno) ) {

            cout << "Flight not found.\n";

            return;
        }


        Flight* f = flights[fno];

        cout << "Enter Seat Number ( 1 - " << f->seats.size()  << "): ";

        int seat = InputValidator::readInt(1 , f->seats.size() );

        seat--;

        if ( !f->bookSeat( seat ) ) {

            cout << "Seat already taken.\n";

            return ;
        }

        Booking* b = new Booking();

        b->bookingId = bookings.size() + 1;

        b->passengerId = passengerId;

        b->flightNo = fno;

        b->seat = seat;

        bookings[b->bookingId] = b;

        cout << "Booking successful. ID: " << b->bookingId << "\n";

    }

    static void cancelBooking(int bookingId) {

        if (!bookings.count(bookingId)) {

            cout << "Booking not found.\n";

            return;
        }

        Booking* b = bookings[bookingId];

        Flight* f = flights[b->flightNo];

        //// Free the seat ////

        f->seats[b->seat] = false ;

        delete b;
        bookings.erase(bookingId);

        cout << "Booking cancelled successfully.\n";
    }


};

