

#pragma once
#include <bits/stdc++.h>
#include "User.h"
#include "Menu.h"
#include "AdminService.h"
using namespace std;



//// ====================================== ADMIN CLASS( Child Class ) ====================================== ////


// Represents an administrator who inherits common attributes and behaviors from the User base class.
class Admin : public User {

public:

        //// ================== Constructor ================== ////


    // Initializes an administrator using the inherited User constructor.
    Admin(int i , string u , string p ) : User( i , u , p ) { } ;


    //// ================== Role Identification ================== ////


    // Returns the role associated with the administrator.
    string role () override {

        return "Admin";
    }


    //// ================== Admin Menu ================== ////


    // Displays the administrator menu and handles administrative operations.
    void menu()override {


    // Keeps the administrator menu active until logout or system termination.
        while (true){



            // Displays the available administrative operations and retrieves the selected option.  
            int c = Menu::show("Admin Menu",{

                    " Logout from Admin list to another list ",
                    "Add Aircraft",
                    "Add Flight",
                    "Remove Flight",
                    "Remove Aircraft",
                    "Remove Passenger Account",
                    "Update Flight Price",
                    "Generate Reports",
                    "Exit System"

            }) ;


        // Returns to the main menu and ends the current administrator session.  
            if ( c == 0 )
                break ;


            // Terminates the entire application.
            if (c == 8 )
            {
                cout << "Exiting system...\n";
                exit(0) ;
            }


            //// ================== Aircraft Management ================== ////

            // Adds a new aircraft to the airline fleet.
            if (c == 1 ){

                AdminService::addAircraft();
            }

            
            //// ================== Flight Management ================== ////

            
            // Creates a new flight and assigns an aircraft.
            if (c == 2 ){

                AdminService::addFlight() ;
            }


         // Removes an existing flight and its associated bookings.  
            if (c == 3 ){

                AdminService::removeFlight() ;

            }


            //// ================== Aircraft Removal ================== ////

            // Removes an aircraft from the fleet if it is not assigned to a flight.            
            if (c == 4 ){

                AdminService::removeAircraft() ;
            }

                        //// ================== Passenger Management ================== ////

            
            // Removes a passenger account and its associated bookings.
            if ( c== 5 ){

                AdminService::removePassenger() ;

            }


            //// ================== Flight Price Management ================== ////

            
            // Updates the ticket price of an existing flight.
            if (c == 6) {

                AdminService::updateFlightPrice() ;
            }

            
            //// ================== Reporting ================== ////

            
    // Generates a report containing flight details, seat occupancy, and revenue.
            if (c == 7 ){

                AdminService::generateReports() ;

            }

        }

    }

};


