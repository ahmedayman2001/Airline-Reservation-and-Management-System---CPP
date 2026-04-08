
#pragma once
#include <bits/stdc++.h>
#include "Aircraft.h"
using namespace std;



//// ========================================= (FLIGHT CLASS (Association with Aircraft Class )) ==========================================////


class Flight {

public:

    string flightNo ;
    string from ;
    string to ;
    string time ;
    string date ;
    double price ;
    Aircraft *aircraft ;
    vector<bool> seats ;  /// Status of Seats (free or complete (0 ,or 1 )) ///

    //// Constructor ////

    Flight(string f ,string o , string d , string t ,string dt , double pr ,  Aircraft * a ) {

        flightNo = f ;
        from = o ;
        to = d ;
        time = t ;
        date = dt ;
        price = pr ;
        aircraft = a ;
        seats.assign(a->capacity , false ) ;  /// All Seats are free now ////
    }

    bool  bookSeat (int seat) {

        if (seat  < 0  || seat >= seats.size() )
            return false ;

        if (!seats[seat]){

            seats[seat] = true ;
            return true ;
        }
        return false ;
    }


};
