
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

unordered_map<int, User*> users;
unordered_map<string, Passenger*> passengers;
unordered_map<string, Flight*> flights;
unordered_map<int, Booking*> bookings;
vector<Aircraft> fleet;


#define FastIO ios::sync_with_stdio(false) , cin.tie(nullptr);

#define ll long long
#define el endl
#define ld long double
//#define MOD 1073741824

// أن تكون حيا فقط لاتكفى ! يجب أن تمتلك ضوءشمس ، حرية , أو زهرة صغيرة داخل قلبك  )) ;

//const int N = 1e5+ 5    ;
//const int mod = 1e9+7 ;
//const ll mod = 1000000007LL;


////  ================== Airline System Function ================== ////

void runAirlineSystem() {

    //// Admin Account  ////
    Admin* admin = new Admin(1, "admin", "1234");

    int passengerCounter = 0;

    while (true) {

        cout << "\n================== Welcome to Airline Reservation and Management System ==================\n";

        string userType;

        cout << "Are you Admin or Passenger? (A/P) or type ' exit ' : [ to quit close Airline System ] : ";

        cin >> userType;

        if (userType == "exit")
            break;

        if (userType == "A") {

            string u, p;

            cout << "Username: " ;

            cin >> u ;

            cout << "Password: " ;

            cin >> p;

            if (admin->authenticate(u, p)) {

                cout << "Welcome, Admin!\n" ;

                admin->menu() ;

            } else

                cout << "Invalid Admin credentials!\n";
        }

        else if (userType == "P") {

            string hasAccount ;

            cout << "Do you have an account? (yes/no): "; cin >> hasAccount;

            if (hasAccount == "yes") {

                string u , p ;

                cout << "Username: " ;

                cin >> u ;

                cout << "Password: " ;

                cin >> p ;

                if (passengers.count(u) && passengers[u]->authenticate(u, p)) {

                    cout << "Welcome, " << u << "!\n" ;

                    passengers[u]->menu() ;

                } else

                    cout << "Invalid credentials!\n";
            }

            else if (hasAccount == "no") {

                string u ;

                while (true) {

                    cout << "Enter Username: " ;

                    cin >> u ;

                    if ( !passengers.count(u) )
                        break ;

                    cout << "Username already exists. Try another.\n";
                }


                string p ;

                cout << "Enter Password: " ;

                cin >> p ;

                Passenger* newP = new Passenger(++passengerCounter, u, p) ;

                passengers[u] = newP ;

                cout << "Account created successfully!\n" ;

                newP->menu() ;

            }
        }

        else cout << "Invalid choice!\n";
    }

    //// Cleanup ////
    delete admin;
    for (auto& it : passengers) delete it.second;
    for (auto& it : flights) delete it.second;
    for (auto& it : bookings) delete it.second;

}



int main() {



    runAirlineSystem();



    return 0 ;
}





