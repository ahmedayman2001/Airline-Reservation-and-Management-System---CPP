
#pragma once
#include <bits/stdc++.h>
using namespace std;


//// ===================== GLOBAL STL CONTAINERS ===================== ///


// Forward declarations for classes referenced by the global containers.
class User;
class Passenger;
class Flight;
class Booking;
class Aircraft;

// Global container storing users indexed by their unique IDs.
extern unordered_map<int, User*> users;

// Global container storing passengers indexed by their usernames.
extern unordered_map<string, Passenger*> passengers;

// Global container storing flights indexed by their unique flight identifiers.
extern unordered_map<string, Flight*> flights;

// Global container storing bookings indexed by their unique booking IDs.
extern unordered_map<int, Booking*> bookings;

// Global container storing all aircraft available in the airline fleet.
extern vector<Aircraft> fleet;
