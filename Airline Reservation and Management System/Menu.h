

#pragma once
#include <bits/stdc++.h>
#include "InputValidator.h"
using namespace std;

class Menu {

public:
    static int show (const string & title , const vector<string> &opitions ) {


        cout<<"\n================= "<< title << "================="<< endl ;

        for (int i = 0; i < opitions.size(); ++i) {

            cout<<i<<"."<<opitions[i]<<endl ;

        }
        cout << "Choose:" ;

        return InputValidator::readInt(0 , (int) opitions.size()-1 ) ;


    }

};

