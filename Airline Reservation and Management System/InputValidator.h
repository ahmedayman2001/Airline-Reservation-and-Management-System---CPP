

#pragma once
#include <bits/stdc++.h>
using namespace std;

class InputValidator {

public:
    static int readInt(int minV ,int maxV ){


        int x ;
        while (true ){

            cin>> x ;
            if (!cin.fail() && x >= minV && x<= maxV )

                return x ;

            cin.clear() ;
            cin.ignore(numeric_limits<streamsize>::max(),'\n') ;

            cout << "Invalid input. Try again: ";

        }
    }
};


