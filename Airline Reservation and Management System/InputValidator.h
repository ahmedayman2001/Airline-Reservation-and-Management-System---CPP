

#pragma once
#include <bits/stdc++.h>
using namespace std;

/// ======================================== INPUT VALIDATOR CLASS ======================================== ///


// Provides reusable input validation utilities for user-entered data.
class InputValidator {

public:


    //// ================== Integer Input Validation ================== ////

    // Reads an integer value and ensures that it falls within the specified range.
    static int readInt(int minV ,int maxV ){


        int x ;

        // Continues reading input until a valid integer within the required range is provided.
        while (true ){

            cin>> x ;

            
        // Returns the input when it is successfully read and within the allowed range.
            if (!cin.fail() && x >= minV && x<= maxV )

                return x ;

            
            // Clears the input stream error state after invalid input.
            cin.clear() ;

        // Removes the remaining invalid characters from the input buffer.
            cin.ignore(numeric_limits<streamsize>::max(),'\n') ;


        // Prompts the user to enter a valid value.
            cout << "Invalid input. Try again: ";

        }
    }
};


