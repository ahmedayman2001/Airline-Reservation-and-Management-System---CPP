

#pragma once
#include <bits/stdc++.h>
#include "InputValidator.h"
using namespace std;

/// ======================================== MENU CLASS ======================================== ///


// Provides a reusable menu system for displaying options and handling user selections.
class Menu {

public:

    //// ================== Display Menu ================== ////


    // Displays a menu with a title and a list of options, then returns the selected option index.
    static int show (const string & title , const vector<string> &opitions ) {


                // Displays the menu title.
        cout<<"\n================= "<< title << "================="<< endl ;


                // Iterates through the available options and displays each with its corresponding index.
        for (int i = 0; i < opitions.size(); ++i) {

            cout<<i<<"."<<opitions[i]<<endl ;

        }

                // Prompts the user to select an option.
        cout << "Choose:" ;


                // Reads and validates the user's selection within the valid option range.
        return InputValidator::readInt(0 , (int) opitions.size()-1 ) ;


    }

};

