#pragma once
#include <bits/stdc++.h>
using namespace std;



//// =================================== USER ABSTRACT CLASS (Base Class) ================================ ////


class User {

protected:
    int id ;
    string username ;
    string password ;

public :

    //// Constructor ////
    User(int i , string u , string p){

        id = i ;
        username = u ;
        password = p ;

    }

    //// Pure virtual function for menu ( Abstract method ) ////

    virtual void menu() = 0 ;

    //// Pure virtual function to return Role ////

    virtual string role()  = 0 ;

    bool authenticate (string& u , string& p ) {


        return u==username && p == password ;

    }

    int getId(){

        return id ;
    }

    //// Virtual destructor ////

    virtual ~User() = default;

};
