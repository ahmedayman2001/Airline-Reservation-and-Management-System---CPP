
#include <bits/stdc++.h>
using namespace std;

////  ================== Include Headers ================== ////
#include "Globals.h"
#include "InputValidator.h"
#include "Menu.h"
#include "User.h"
#include "Passenger.h"
#include "Admin.h"
#include "Aircraft.h"
#include "Flight.h"
#include "Booking.h"
#include "BookingService.h"
#include "CheckInService.h"
#include "AdminService.h"


//// ================== Define Global Containers ================== ///

// Stores all registered users, indexed by their unique IDs.
unordered_map<int, User*> users;

// Stores passenger accounts, indexed by their usernames.
unordered_map<string, Passenger*> passengers;

// Stores flight records, indexed by their unique flight identifiers.
unordered_map<string, Flight*> flights;

// Stores booking records, indexed by their unique booking IDs.
unordered_map<int, Booking*> bookings;

// Stores the aircraft available in the airline fleet.
vector<Aircraft> fleet;

// Enables faster input and output operations.
#define FastIO ios::sync_with_stdio(false) , cin.tie(nullptr);


// Defines commonly used type and output shortcuts.
#define ll long long
#define el endl
#define ld long double
//#define MOD 1073741824

// أن تكون حيا فقط لاتكفى ! يجب أن تمتلك ضوءشمس ، حرية , أو زهرة صغيرة داخل قلبك  )) ;

//const int N = 1e5+ 5    ;
//const int mod = 1e9+7 ;
//const ll mod = 1000000007LL;


     ////  ================== Airline System Function ================== ////

// Handles user authentication, account registration, and menu navigation.
void runAirlineSystem() {


    //// ================== Initialize Admin Account ================== ////

    // Creates the default administrator account.
    //// Admin Account  ////
    Admin* admin = new Admin(1, "admin", "1234");


    // Tracks the number of registered passengers during the current session.
    int passengerCounter = 0;


    //// ================== Main Application Loop ================== ////


    while (true) {

        // Displays the main welcome screen.
        cout << "\n================== Welcome to Airline Reservation and Management System ==================\n";

        // Stores the selected user type or exit command.
        string userType;

        // Prompts the user to select an account type or terminate the application.
        cout << "Are you Admin or Passenger? (A/P) or type ' exit ' : [ to quit close Airline System ] : ";

        cin >> userType;

        // Terminates the application when the exit command is entered.
        if (userType == "exit")
            break;



        //// ================== Admin Authentication ================== ////


        if (userType == "A") {

            // Stores the administrator's login credentials.
            string u, p;

            cout << "Username: " ;

            cin >> u ;

            cout << "Password: " ;

            cin >> p;

            // Verifies the administrator's credentials before granting access.
            if (admin->authenticate(u, p)) {

                cout << "Welcome, Admin!\n" ;

                // Opens the administrator's management menu.
                admin->menu() ;

            } else

                // Notifies the user when authentication fails.
                cout << "Invalid Admin credentials!\n";
        }

            //// ================== Passenger Authentication and Registration ================== ////


        else if (userType == "P") {

            // Determines whether the passenger already has an account.
            string hasAccount ;

            cout << "Do you have an account? (yes/no): "; cin >> hasAccount;


            //// ================== Existing Passenger Login ================== ////


            if (hasAccount == "yes") {

                // Stores the passenger's login credentials.
                string u , p ;

                cout << "Username: " ;

                cin >> u ;

                cout << "Password: " ;

                cin >> p ;

                // Checks whether the account exists and validates its credentials.
                if (passengers.count(u) && passengers[u]->authenticate(u, p)) {

                    cout << "Welcome, " << u << "!\n" ;

                    // Opens the authenticated passenger's menu.
                    passengers[u]->menu() ;

                } else

                    // Displays an error message for invalid login attempts.
                    cout << "Invalid credentials!\n";
            }


                //// ================== New Passenger Registration ================== ////


            else if (hasAccount == "no") {

                // Stores the username selected during registration.
                string u ;

                // Ensures that each passenger has a unique username.
                while (true) {

                    cout << "Enter Username: " ;

                    cin >> u ;

                    // Accepts the username if it is not already registered.
                    if ( !passengers.count(u) )
                        break ;

                    // Requests another username when a duplicate is detected.
                    cout << "Username already exists. Try another.\n";
                }


                // Stores the password for the new passenger account.
                string p ;

                cout << "Enter Password: " ;

                cin >> p ;

                // Creates a new passenger with a unique session-based ID.
                Passenger* newP = new Passenger(++passengerCounter, u, p) ;

                // Registers the newly created passenger using their username.
                passengers[u] = newP ;

                cout << "Account created successfully!\n" ;

                // Opens the newly registered passenger's menu.
                newP->menu() ;

            }
        }


            //// ================== Invalid User Type Handling ================== ////


            // Displays an error message when the selected user type is invalid.
        else cout << "Invalid choice!\n";
    }


       //// ================== Resource Cleanup ================== ////


    //// Cleanup ////

    // Releases the administrator object.
    delete admin;

    // Releases all dynamically allocated passenger objects.
    for (auto& it : passengers) delete it.second;

    // Releases all dynamically allocated flight objects.
    for (auto& it : flights) delete it.second;

    // Releases all dynamically allocated booking objects.
    for (auto& it : bookings) delete it.second;

}


//// ================== Application Entry Point ================== ////

int main() {


    // Starts the airline reservation and management system.
    runAirlineSystem();


    // Indicates successful program termination.

    return 0 ;
}





