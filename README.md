# 📊 UML Class Diagram – Airline Reservation System

```text
                                     ┌────────────────────┐
                                     │      User          │   <<abstract>>
                                     ├────────────────────┤
                                     │ - id : int         │
                                     │ - username : string│
                                     │ - password : string│
                                     ├────────────────────┤
                                     │ + User(i,u,p)      │
                                     │ + menu() : void    │ <<abstract>>
                                     │ + role() : string  │ <<abstract>>
                                     │ + authenticate(u,p):bool │
                                     │ + getId():int      │
                                     │ + ~User()          │ <<virtual>>
                                     └─────────────▲──────┘
                                                   │
                             ┌─────────────────────┴───────────────────┐
                             │                                         │
                     ┌──────────────┐                     ┌──────────────┐
                     │    Admin     │                     │  Passenger   │
                     ├──────────────┤                     ├──────────────┤
                     │ + Admin(i,u,p)│                   │ + Passenger(i,u,p)│
                     │ + menu()      │                   │ + menu()      │
                     │ + role()      │                   │ + role()      │
                     └───────┬──────┘                   └───────┬──────┘
                             │ uses                              │ uses
                             ▼                                   ▼
                     ┌──────────────┐                   ┌──────────────┐
                     │ AdminService │                   │ BookingService│
                     ├──────────────┤                   ├──────────────┤
                     │ + addAircraft()│ <<static>>      │ + createBooking() <<static>> │
                     │ + addFlight()  │ <<static>>      │ + cancelBooking() <<static>> │
                     │ + removeFlight()│ <<static>>     └───────┬───────┘
                     │ + removeAircraft()│ <<static>>           │ uses
                     │ + removePassenger()│ <<static>>          ▼
                     │ + updateFlightPrice()│ <<static>> ┌──────────────┐
                     │ + generateReports() │ <<static>>  │   Booking    │
                     └───────┬────────────┘              ├──────────────┤
                             │ uses                      │ + bookingId  │
                             ▼                           │ + passengerId│
                     ┌──────────────┐                    │ + flightNo   │
                     │   Aircraft   │◄────association────│ + seat       │
                     ├──────────────┤                    │ + checkedIn  │
                     │ + id         │                    └──────────────┘
                     │ + model      │
                     │ + capacity   │
                     │ + underMaintenance │
                     └──────────────┘
                             ▲
                             │
                             │ used in
                             ▼
                     ┌──────────────┐
                     │    Flight    │
                     ├──────────────┤
                     │ + flightNo   │
                     │ + from       │
                     │ + to         │
                     │ + date       │
                     │ + time       │
                     │ + price      │
                     │ + seats:vector<bool> │
                     │ + aircraft*:Aircraft │
                     ├──────────────┤
                     │ + Flight(fn,o,d,t,dt,pr,a)│
                     │ + bookSeat(seat:int):bool │
                     └──────────────┘


        ┌────────────────────────────────────────────┐
        │          GlobalDataStore                   │ <<static>>
        ├────────────────────────────────────────────┤
        │ + users : unordered_map<int,User*>        │
        │ + passengers : unordered_map<string,Passenger*> │
        │ + flights : unordered_map<string,Flight*> │
        │ + bookings : unordered_map<int,Booking*>  │
        │ + fleet : vector<Aircraft>                │
        └───────────────▲────────────────────────────┘
                        │ used by
         ┌──────────────┼─────────────────────────────┐
         │              │             │               │
         ▼              ▼             ▼               ▼
  AdminService  BookingService  Passenger      CheckInService


        ┌────────────────────┐
        │ CheckInService     │
        ├────────────────────┤
        │ + checkIn(bookingId:int) : void <<static>> │
        └─────────▲──────────┘
                  │ uses
                  ▼
               Booking


     ┌────────────────────┐
     │ InputValidator     │
     ├────────────────────┤
     │ + readInt(min:int,max:int) : int <<static>> │
     └─────────▲──────────┘
               │ used by
               ▼
         ┌──────────────┐
         │     Menu     │
         ├──────────────┤
         │ + show(title:string,options:vector<string>): int <<static>> │
         └──────────────┘
               ▲
        ┌──────┴──────┐
        ▼             ▼
      Admin        Passenger



  ✅ Relationships

1- Inheritance

Admin → User  
Passenger → User  

2- Association

Flight → Aircraft (aircraft*)  
Booking → Flight (uses flightNo)  

3- Dependency

Admin → AdminService  
Passenger → BookingService  
Passenger → CheckInService  
Menu → InputValidator  

4- Global STL

All services and user classes depend on GlobalDataStore
