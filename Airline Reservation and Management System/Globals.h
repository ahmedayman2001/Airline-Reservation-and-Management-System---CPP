
#pragma once
#include <bits/stdc++.h>
using namespace std;


//// ===================== GLOBAL STL CONTAINERS ===================== ///

class User;
class Passenger;
class Flight;
class Booking;
class Aircraft;

extern unordered_map<int, User*> users;
extern unordered_map<string, Passenger*> passengers;
extern unordered_map<string, Flight*> flights;
extern unordered_map<int, Booking*> bookings;
extern vector<Aircraft> fleet;