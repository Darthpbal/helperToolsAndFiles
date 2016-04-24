//**************************************************************************************************************
// FILE:        Color.cpp
//
// DESCRIPTION: Contains the class implementation for the Color class. See Color.hpp for the class declaration.
//
// AUTHORS:     Paul ROnquillo            (pronquil@asu.edu)
//
//
// COURSE:      CSE100 Principles of Programming with C++, Fall 2015
//
// LAB INFO:    Lab 9   Date/Time: WED 10:30am   TA: Chetan
//**************************************************************************************************************
#include <sstream>             // For stringstream class
#include "Color.hpp"             // For Color class

// Write the function definitions for each of the function members of the Color class.

//--------------------------------------------------------------------------------------------------------------
// CTOR: Color::Color()
//
// DESCRIPTION:
// Initializes the color to black by initializing mRed, mGreen, and mBlue to 0, 0, and 0.
//
// PSEUDOCODE:
// Call init() passing 0, 0, 0 as the arguments.
//--------------------------------------------------------------------------------------------------------------
Color::Color(){
    init(0,0,0);
}

//--------------------------------------------------------------------------------------------------------------
// CTOR: Color::Color()
//
// DESCRIPTION:
// Initializes the color initializing mRed, mGreen, and mBlue to pInitRed, pInitGreen, and pInitBlue.
//
// PSEUDOCODE:
// Call init() passing pInitRed, pInitGreen, and pInitBlue as the arguments.
//--------------------------------------------------------------------------------------------------------------
Color::Color(int pInitRed, int pInitGreen, int pInitBlue){
    init(pInitRed,pInitGreen,pInitBlue);
}

//--------------------------------------------------------------------------------------------------------------
// FUNCTION: getBlue()
//
// DESCRIPTION:
// Accessor function for the mBlue data member.
//
// PSEUDOCODE:
// Return mBlue
//--------------------------------------------------------------------------------------------------------------
int Color::getBlue(){
    return mBlue;
}

//--------------------------------------------------------------------------------------------------------------
// FUNCTION: getGreen()
//
// DESCRIPTION:
// Accessor function for the mGreen data member.
//
// PSEUDOCODE:
// Return mGreen
//--------------------------------------------------------------------------------------------------------------
int Color::getGreen(){
    return mGreen;
}

//--------------------------------------------------------------------------------------------------------------
// FUNCTION: getRed()
//
// DESCRIPTION:
// Accessor function for the mRed data member.
//
// PSEUDOCODE:
// Return mRed
//--------------------------------------------------------------------------------------------------------------
int Color::getRed(){
    return mRed;
}

//--------------------------------------------------------------------------------------------------------------
// FUNCTION: setBlue()
//
// DESCRIPTION:
// Mutator function for the mBlue data member.
//
// PSEUDOCODE:
// mBlue <- pNewBlue
//--------------------------------------------------------------------------------------------------------------
void Color::setBlue(int pNewBlue){
    mBlue = pNewBlue;
}

//--------------------------------------------------------------------------------------------------------------
// FUNCTION: setGreen()
//
// DESCRIPTION:
// Mutator function for the mGreen data member.
//
// PSEUDOCODE:
// mGreen <- pNewGreen
//--------------------------------------------------------------------------------------------------------------
void Color ::setGreen(int pNewGreen){
    mGreen = pNewGreen;
}

//--------------------------------------------------------------------------------------------------------------
// FUNCTION: setRed()
//
// DESCRIPTION:
// Mutator function for the mRed data member.
//
// PSEUDOCODE:
// mRed <- pNewRed
//--------------------------------------------------------------------------------------------------------------
void Color::setRed(int pNewRed){
    mRed = pNewRed;
}

//--------------------------------------------------------------------------------------------------------------
// FUNCTION: toString()
//
// DESCRIPTION:
// Returns a string representation of this Color in the form "(mRed, mGreen, mBlue)". For example, if mRed = 12,
// mGreen = 100, and mBlue = 212, then this function would return the string "(12, 100, 212)".
//
// PSEUDOCODE:
// Define a stringstream object named sout
// Send to sout "(" getRed() ", " getGreen() ", " getBlue() ")"
// Return sout.str()
//--------------------------------------------------------------------------------------------------------------
string Color::toString(){
    stringstream sout;
    sout << "(" << getRed() << "," << getGreen() << "," << getBlue() << ")";
    return sout.str();
}

//--------------------------------------------------------------------------------------------------------------
// FUNCTION: init()
//
// DESCRIPTION:
// Initializes the data members to the parameters by calling the mutator functions.
//
// PSEUDOCODE:
// setRed(pInitRed)
// setGreen(pInitGreen)
// setBlue(pInitBlue)
//--------------------------------------------------------------------------------------------------------------
void Color::init(int pInitRed, int pInitGreen, int pInitBlue){
    setRed(pInitRed);
    setGreen(pInitGreen);
    setBlue(pInitBlue);
}
