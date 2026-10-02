
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


// Provides administrative operations for managing aircraft, flights, passengers, and reports.
class AdminService {
public:

    //// ================== Add Aircraft ================== ////


    // Registers a new aircraft in the airline fleet.
    /// Add Aircraft to Airline System ///
    static void addAircraft(){

        // Creates an aircraft object to store the entered details.
        Aircraft a ;

        // Collects the aircraft identification and specifications.
        cout << "Aircraft ID: "; cin >> a.id;
        cout << "Model: "; cin >> a.model;
        cout << "Capacity: "; cin >> a.capacity;

        // Adds the new aircraft to the fleet.
        fleet.push_back(a);

            // Confirms successful aircraft registration.    
        cout << "Aircraft added successfully.\n";

    }


    //// ================== Add Flight ================== ////


    // Creates a new flight and assigns an aircraft from the available fleet.
    /// Add Flight to Airline System ///
    static void addFlight() {

        
        // Ensures that at least one aircraft is available before creating a flight.
        if (fleet.empty()) {


            cout << "No aircraft available. Add aircraft first.\n";
            return ;

        }


        // Stores the flight details entered by the administrator.
        string fn , o , d  , t , dt  ;
        double pr ;

    // Collects the flight number, route, schedule, and ticket price.
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


                //// ================== Aircraft Selection ================== ////
        //// Select aircraft ////

                // Prompts the administrator to select an aircraft from the fleet.
        cout << "Select Aircraft (1 - " << fleet.size()  << "): " ;

        
        // Validates the selected aircraft index and converts it to zero-based indexing.
        int acIndex = InputValidator::readInt(1, fleet.size() );
        acIndex--;
        
 // Creates the flight and stores it in the global flights container.
        // The flight maintains a pointer to the selected aircraft.
        flights[fn] = new Flight(fn, o, d, t,dt , pr, &fleet[acIndex]) ;


                // Confirms successful flight creation.
        cout << "Flight added successfully.\n";

    }


    //// ================== Remove Flight ================== ////


    // Removes a flight and deletes all bookings associated with it.
    /// Remove Flight From Airline System ///
    static void removeFlight() {

        
        // Checks whether any flights are registered in the system.
        if (flights.empty()) {

        // Requests the flight number to be removed.
            cout << "No flights to remove.\n";

            return ;
        }

        cout << "Enter Flight Number to remove: " ;

        string fn ;
        cin >> fn;


        // Verifies that the specified flight exists.
        if (!flights.count(fn)) {

            cout << "Flight not found.\n";

            return ;

        }


                //// ================== Remove Related Bookings ================== ////

        

        /// Remove all Bookings related to this Flight ///
        // Iterates through all bookings and removes those associated with the selected flight.
        for (auto it = bookings.begin(); it != bookings.end();it++ ) {

            if ( it->second->flightNo == fn ) {


                // Releases the memory allocated for the booking record.
                delete it->second ;


            // Erases the booking and updates the iterator to the next valid position.   
                it = bookings.erase(it);

            }
        }


                //// ================== Delete Flight ================== ////

        
        // Releases the memory allocated for the flight object.
        delete flights[fn];


        // Removes the flight from the global flights container.
        flights.erase(fn);


                // Confirms successful flight removal.
        cout << "Flight " << fn << " removed successfully.\n";


    }


    //// ================== Remove Aircraft ================== ////
    /// Remove Aircraft from Airline System ////


    // Removes an aircraft from the fleet if it is not assigned to any flight.
    static void removeAircraft(){

        
        // Checks whether the fleet contains any aircraft.
        if ( fleet.empty() ) {

            cout << "No aircraft to remove.\n" ;

            return;
        }

        
        // Requests the index of the aircraft to be removed.
        cout << "Select Aircraft to remove (1 - " << fleet.size() << "): " ;


                // Validates the selected index and converts it to zero-based indexing.
        int acIndex = InputValidator::readInt(1, fleet.size()) - 1 ;


        
                //// ================== Check Aircraft Assignments ================== ////
        //// Check if any flight is using this aircraft ////


                // Checks whether the selected aircraft is currently assigned to any flight.
        for (auto& [fn, f] : flights) {


                        // Prevents the removal of an aircraft that is still referenced by a flight.
            if ( f->aircraft == &fleet[acIndex] ) {

                cout << "Cannot remove. Aircraft is assigned to flight " << fn << "\n";

                return ;
            }
        }


        //// ================== Remove Aircraft from Fleet ================== ////

        
        // Removes the selected aircraft from the fleet.
        fleet.erase(fleet.begin() + acIndex) ;


             // Confirms successful aircraft removal.   
        cout << "Aircraft removed successfully.\n" ;

    }


    //// ================== Remove Passenger ================== ////
/// Remove Passenger Account ///


    // Deletes a passenger account and all bookings associated with that passenger.
    static void removePassenger() {


                // Checks whether any passenger accounts are registered.
        if (passengers.empty()) {

            cout << "No passengers to remove.\n";

            return;
        }


                // Requests the username of the passenger whose account should be removed.
        cout << "Enter Passenger Username to remove: " ;


        
        string uname; cin >> uname ;

        // Verifies that the specified passenger account exists.
        if (!passengers.count(uname)) {

            cout << "Passenger not found.\n" ;

            return ;
        }


        // Retrieves the unique ID of the selected passenger.
        int pid = passengers[uname]->getId();


        //// ================== Remove Passenger Bookings ================== ////
        //// Delete passenger's bookings ////


                // Iterates through all bookings and identifies those belonging to the selected passenger.
        for (auto it = bookings.begin(); it != bookings.end(); it++ ) {

            if ( it->second->passengerId == pid ) {

                
                // Releases the memory allocated for the booking record.
                delete it->second ;


                // Removes the booking from the global bookings container.
                it = bookings.erase(it);
            }

        }


        //// ================== Delete Passenger Account ================== ////

        
                // Releases the memory allocated for the passenger object.
        delete passengers[uname];

                // Removes the passenger account from the global passengers container.
        passengers.erase(uname);


                // Confirms successful passenger account removal.
        cout << "Passenger account removed successfully.\n";

    }



    //// ================== Update Flight Price ================== ////
    ////  Update Price of any Flight  ///


    // Updates the ticket price of an existing flight.
    static void updateFlightPrice(){


                // Checks whether any flights are registered in the system.
        if (flights.empty()) {
            cout << "No flights available.\n";
            return;
        }

                // Requests the flight number whose price should be updated.
        cout << "Enter Flight Number to update price: ";
        string fn; cin >> fn;



             // Verifies that the specified flight exists.   
        if (!flights.count(fn)) {
            cout << "Flight not found.\n";
            return;
        }


                // Requests the new ticket price.
        cout << "Enter new price: $";
        double newPrice; cin >> newPrice;


                // Updates the price of the selected flight.
        flights[fn]->price = newPrice;


                // Confirms successful price modification.
        cout << "Price updated successfully.\n";

    }


    //// ================== Generate Reports ================== ////
    //// Generate Reports ///


    // Generates a report containing flight details, seat occupancy, and revenue.
    static void generateReports(){

        cout << "\n===== Flights Report =====\n";

                // Iterates through all registered flights to generate their individual reports.
        for (auto& [fn, f] : flights) {

            int booked = 0;

                        // Counts the number of seats currently booked on the flight.
            for (bool s : f->seats)
                if (s)
                    booked++ ;



                      // Displays the flight details and calculates its total revenue.  
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

