#pragma once
#include <bits/stdc++.h>
using namespace std;



//// =================================== USER ABSTRACT CLASS (Base Class) ================================ ////


 // Defines the common attributes and behaviors shared by all user types.
class User {

protected:

    // Stores the unique identifier of the user.
    int id ;

    // Stores the user's login username.
    string username ;

    // Stores the user's login password.
    string password ;

public :


    //// ================== Constructor ================== ////
    //// Constructor ////

    // Initializes a user with an ID, username, and password.
    User(int i , string u , string p){

        id = i ;
        username = u ;
        password = p ;

    }


    //// ================== Abstract Methods ================== ////


    //// Pure virtual function for menu ( Abstract method ) ////
    // Defines the interface for displaying the menu of each derived user class.
    virtual void menu() = 0 ;

    //// Pure virtual function to return Role ////

    // Defines the interface for retrieving the role of each derived user class.
    virtual string role()  = 0 ;

    //// ================== Authentication ================== ////

    // Validates the provided credentials against the stored username and password.
    bool authenticate (string& u , string& p ) {


        return u==username && p == password ;

    }

    //// ================== Getter Methods ================== ////

    // Returns the unique identifier of the user.
    int getId(){

        return id ;
    }

    //// ================== Virtual Destructor ================== ////
    //// Virtual destructor ////


    // Ensures proper destruction of derived objects through a base-class pointer.
    virtual ~User() = default;

};
