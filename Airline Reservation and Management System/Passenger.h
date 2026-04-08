

#pragma once
#include <bits/stdc++.h>
#include "User.h"
#include "Menu.h"
#include "BookingService.h"
#include "CheckInService.h"
#include "Globals.h"
using namespace std;


//// ======================================== (PASSENGER CLASS (Child Class) ================================////


class Passenger : public User {

public:
    //// Constructor ////

    Passenger( int i , string u , string p ) :  User(i , u , p ) { }

    string role() override {


        return "Passenger" ;
    }

    void menu() override {

        while (true){

            int c = Menu::show("Passenger Menu", {"Logout from Passenger list to another list ", "Book Flight", "Check-in","Cancel Booking" , "Exit System"}) ;

            if (c == 0 )
                break ;
            if (c == 4 )
            {

                cout << "Exiting system...\n";
                exit(0);
            }
            if (c == 1 ){

                BookingService::createBooking(id);
            }
            if (c == 2 ) {

                cout << "Enter Booking ID: ";
                int bId; cin >> bId;
                CheckInService::checkIn(bId);

            }
            if (c == 3) {

                cout << "Enter Booking ID: ";

                int bId ;

                cin >> bId ;

                BookingService::cancelBooking(bId);
            }


        }

    }
};


