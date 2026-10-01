

#pragma once
#include <bits/stdc++.h>
#include "User.h"
#include "Menu.h"
#include "BookingService.h"
#include "CheckInService.h"
#include "Globals.h"
using namespace std;


//// ======================================== (PASSENGER CLASS (Child Class) ================================////

// Represents a passenger who inherits common attributes and behaviors from the User base class.
class Passenger : public User {

public:


    //// ================== Constructor ================== ////
    //// Constructor ////


    // Initializes a passenger using the inherited User constructor.
    Passenger( int i , string u , string p ) :  User(i , u , p ) { }


    //// ================== Role Identification ================== ////


    // Returns the role associated with the passenger.
    string role() override {


        return "Passenger" ;
    }


    //// ================== Passenger Menu ================== ////

    // Displays the passenger menu and handles passenger operations.
    void menu() override {

    // Keeps the passenger menu active until logout or system termination.
        while (true){

         // Displays the available passenger operations and retrieves the selected option.
            int c = Menu::show("Passenger Menu", {"Logout from Passenger list to another list ", "Book Flight", "Check-in","Cancel Booking" , "Exit System"}) ;

            // Returns to the main menu and ends the current passenger session.
            if (c == 0 )
                break ;

            // Terminates the entire application.
            if (c == 4 )
            {

                cout << "Exiting system...\n";
                exit(0);
            }

     //// ================== Flight Booking ================== ////

    // Initiates the flight booking process for the current passenger.     
            if (c == 1 ){

                BookingService::createBooking(id);
            }


            //// ================== Flight Check-in ================== ////

        // Requests a booking ID and initiates the check-in process.
            if (c == 2 ) {

                cout << "Enter Booking ID: ";
                int bId; cin >> bId;
                CheckInService::checkIn(bId);

            }


        //// ================== Booking Cancellation ================== ////


        // Requests a booking ID and initiates the booking cancellation process.
            if (c == 3) {

                cout << "Enter Booking ID: ";

                int bId ;

                cin >> bId ;

                BookingService::cancelBooking(bId);
            }


        }

    }
};


