#pragma once
#include <bits/stdc++.h>
#include "Flight.h"
#include "Booking.h"
#include "Globals.h"
#include "InputValidator.h"
using namespace std;



//// ================================================= BOOKING SERVICE CLASS ================================ ////


// Handles flight booking operations, including seat selection and booking cancellation.
class BookingService {

public:

    //// ================== Create Booking ================== ////

    // Creates a new booking for a passenger by selecting a flight and an available seat.
    static void createBooking(int passengerId) {

        if (flights.empty()) {
            cout << "No flights available.\n";
            return;
        }

        
        // Displays all available flights along with their schedules, prices, and seat availability.
        cout << "Available Flights:\n";


        // Iterates through all registered flights to display their details.
        for (auto& [id, f] : flights) {

            int availableSeats = 0;

            //// Count available seats ////
        // Counts the seats that are not currently booked.
            for (bool s : f->seats)
                if (!s) availableSeats++;


            // Displays the flight number, route, schedule, price, and number of available seats.
            cout << "FlightNo: " << f->flightNo

                 << " | " << f->from << " -> " << f->to

                 << " | Date: " << f->date

                 << " | Time: " << f->time

                 << " | Price: $" << f->price

                 << " | Available Seats: " << availableSeats;


            // Lists the available seat numbers when at least one seat is free.
            if (availableSeats > 0) {

                cout << " | Seats: ";



            // Iterates through the seats and displays available seats using one-based numbering.
                for (int i = 0; i < f->seats.size(); i++) {

                    if (!f->seats[i]) {

                        cout << (i + 1) << " ";   // one-based numbering
                    }
                }
            }


            // Indicates when the flight has no remaining available seats.
            else {
                cout << " | No seats available";
            }

            cout << endl;
        }


        //// ================== Flight Selection ================== ////


    
        // Prompts the passenger to enter the flight number.
        cout << "Enter Flight Number: ";

        string fno; cin >> fno;


        // Validates that the selected flight exists.
        if ( !flights.count(fno) ) {

            cout << "Flight not found.\n";

            return;
        }

        // Retrieves the selected flight.
        Flight* f = flights[fno];


        //// ================== Seat Selection ================== ////

        // Prompts the passenger to select a seat within the valid seat range.        
        cout << "Enter Seat Number ( 1 - " << f->seats.size()  << "): ";


                // Reads and validates the seat number, then converts it to zero-based indexing.
        int seat = InputValidator::readInt(1 , f->seats.size() );

        seat--;


                // Attempts to reserve the selected seat.
        if ( !f->bookSeat( seat ) ) {

            // Rejects the booking if the selected seat is already occupied.
            cout << "Seat already taken.\n";

            return ;
        }


        //// ================== Booking Record Creation ================== ////

        
        // Creates a new booking record.
        Booking* b = new Booking();


    // Assigns a unique booking ID based on the current number of bookings. 
        b->bookingId = bookings.size() + 1;

        
        // Associates the booking with the passenger who initiated the request.
        b->passengerId = passengerId;
        
        // Stores the selected flight number in the booking record.
        b->flightNo = fno;


        // Stores the selected seat using zero-based indexing.
        b->seat = seat;


     // Registers the new booking in the global bookings container.
        bookings[b->bookingId] = b;


             // Confirms successful booking creation and displays the booking ID.   
        cout << "Booking successful. ID: " << b->bookingId << "\n";

    }


    //// ================== Cancel Booking ================== ////


    // Cancels an existing booking and releases its reserved seat.
    static void cancelBooking(int bookingId) {


     // Checks whether the specified booking exists.
        if (!bookings.count(bookingId)) {

            cout << "Booking not found.\n";

            return;
        }


              // Retrieves the booking record using its unique ID.  
        Booking* b = bookings[bookingId];


                // Retrieves the flight associated with the booking.
        Flight* f = flights[b->flightNo];

        

        //// ================== Release Reserved Seat ================== ////

        
        //// Free the seat ////

        f->seats[b->seat] = false ;

        
        //// ================== Remove Booking Record ================== ////


                // Releases the memory allocated for the booking record.
        delete b;

                // Removes the cancelled booking from the global bookings container.
        bookings.erase(bookingId);


                // Confirms successful cancellation.
        cout << "Booking cancelled successfully.\n";
    }


};

