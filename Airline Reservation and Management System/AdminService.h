
#pragma once
#include <bits/stdc++.h>
#include "Aircraft.h"
#include "Flight.h"
#include "Booking.h"
#include "Passenger.h"
#include "Globals.h"
#include "InputValidator.h"
using namespace std;



//// ====================================== ADMIN SERVICE CLASS( Dependency with ADMIN CLASS  ) ====================================== ////


class AdminService {
public:



    /// Add Aircraft to Airline System ///
    static void addAircraft(){

        Aircraft a ;
        cout << "Aircraft ID: "; cin >> a.id;
        cout << "Model: "; cin >> a.model;
        cout << "Capacity: "; cin >> a.capacity;
        fleet.push_back(a);
        cout << "Aircraft added successfully.\n";

    }




    /// Add Flight to Airline System ///
    static void addFlight() {


        if (fleet.empty()) {


            cout << "No aircraft available. Add aircraft first.\n";
            return ;

        }

        string fn , o , d  , t , dt  ;
        double pr ;
        cout << "Flight Number: ";
        cin >> fn;
        cout << "From: ";
        cin >> o;
        cout << "To: ";
        cin >> d;
        cout << "Time: ";
        cin >> t;
        cout << "Date: ";
        cin >> dt;
        cout << "Price: ";
        cin >> pr;

        //// Select aircraft ////

        cout << "Select Aircraft (1 - " << fleet.size()  << "): " ;

        int acIndex = InputValidator::readInt(1, fleet.size() );
        acIndex--;

        flights[fn] = new Flight(fn, o, d, t,dt , pr, &fleet[acIndex]) ;

        cout << "Flight added successfully.\n";

    }




    /// Remove Flight From Airline System ///
    static void removeFlight() {


        if (flights.empty()) {

            cout << "No flights to remove.\n";

            return ;
        }

        cout << "Enter Flight Number to remove: " ;

        string fn ;
        cin >> fn;

        if (!flights.count(fn)) {

            cout << "Flight not found.\n";

            return ;

        }


        /// Remove all Bookings related to this Flight ///

        for (auto it = bookings.begin(); it != bookings.end();it++ ) {

            if ( it->second->flightNo == fn ) {

                delete it->second ;
                it = bookings.erase(it);

            }
        }

        delete flights[fn];
        flights.erase(fn);

        cout << "Flight " << fn << " removed successfully.\n";


    }




    /// Remove Aircraft from Airline System ////
    static void removeAircraft(){


        if ( fleet.empty() ) {

            cout << "No aircraft to remove.\n" ;

            return;
        }

        cout << "Select Aircraft to remove (1 - " << fleet.size() << "): " ;

        int acIndex = InputValidator::readInt(1, fleet.size()) - 1 ;

        //// Check if any flight is using this aircraft ////

        for (auto& [fn, f] : flights) {

            if ( f->aircraft == &fleet[acIndex] ) {

                cout << "Cannot remove. Aircraft is assigned to flight " << fn << "\n";

                return ;
            }
        }

        fleet.erase(fleet.begin() + acIndex) ;

        cout << "Aircraft removed successfully.\n" ;

    }



/// Remove Passenger Account ///
    static void removePassenger() {

        if (passengers.empty()) {

            cout << "No passengers to remove.\n";

            return;
        }

        cout << "Enter Passenger Username to remove: " ;

        string uname; cin >> uname ;


        if (!passengers.count(uname)) {

            cout << "Passenger not found.\n" ;

            return ;
        }


        int pid = passengers[uname]->getId();


        //// Delete passenger's bookings ////
        for (auto it = bookings.begin(); it != bookings.end(); it++ ) {

            if ( it->second->passengerId == pid ) {

                delete it->second ;

                it = bookings.erase(it);
            }

        }

        delete passengers[uname];
        passengers.erase(uname);

        cout << "Passenger account removed successfully.\n";

    }






    ////  Update Price of any Flight  ///
    static void updateFlightPrice(){

        if (flights.empty()) {
            cout << "No flights available.\n";
            return;
        }

        cout << "Enter Flight Number to update price: ";
        string fn; cin >> fn;

        if (!flights.count(fn)) {
            cout << "Flight not found.\n";
            return;
        }

        cout << "Enter new price: $";
        double newPrice; cin >> newPrice;

        flights[fn]->price = newPrice;
        cout << "Price updated successfully.\n";

    }




    //// Generate Reports ///
    static void generateReports(){

        cout << "\n===== Flights Report =====\n";

        for (auto& [fn, f] : flights) {

            int booked = 0;

            for (bool s : f->seats)
                if (s)
                    booked++ ;


            cout << "Flight: " << fn

                 << " | From: " << f->from

                 << " | To: " << f->to

                 << " | Booked Seats: " << booked

                 << " | Total Seats: " << f->seats.size()

                 << " | Price: $" << f->price

                 << " | Revenue: $" << booked * f->price

                 << endl;

        }

    }
};

