

#pragma once
#include <bits/stdc++.h>
#include "User.h"
#include "Menu.h"
#include "AdminService.h"
using namespace std;



//// ====================================== ADMIN CLASS( Child Class ) ====================================== ////


class Admin : public User {

public:

    /// Constructor ////

    Admin(int i , string u , string p ) : User( i , u , p ) { } ;

    string role () override {

        return "Admin";
    }

    void menu()override {

        while (true){

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


            if ( c == 0 )
                break ;
            if (c == 8 )
            {
                cout << "Exiting system...\n";
                exit(0) ;
            }

            if (c == 1 ){

                AdminService::addAircraft();
            }

            if (c == 2 ){

                AdminService::addFlight() ;
            }

            if (c == 3 ){

                AdminService::removeFlight() ;

            }
            if (c == 4 ){

                AdminService::removeAircraft() ;
            }
            if ( c== 5 ){

                AdminService::removePassenger() ;

            }
            if (c == 6) {

                AdminService::updateFlightPrice() ;
            }
            if (c == 7 ){

                AdminService::generateReports() ;

            }

        }

    }

};


