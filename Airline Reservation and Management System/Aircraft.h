
#pragma once
#include <bits/stdc++.h>
using namespace std;


////====================================( AIRCRAFT CLASS ) ======================================= ////


// Represents an aircraft and stores its identification, specifications, and maintenance status.
class Aircraft {

public:

    // Unique identifier assigned to the aircraft.
    string id;

    // Model or type of the aircraft.
    string model;

    // Maximum number of passengers the aircraft can accommodate.
    int capacity;


  // Indicates whether the aircraft is currently under maintenance.
    // Defaults to false when a new aircraft is created.
    bool underMaintenance{false};

};
