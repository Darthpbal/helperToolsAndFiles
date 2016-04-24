//**************************************************************************************************************
// FILE:        Point.cpp
//
// DESCRIPTION: Implementation of the Point class. See Point.hpp for the class declaration.
//
// AUTHORS:     Paul Ronquillo            (pronquil@asu.edu)

//
// COURSE:      CSE100 Principles of Programming with C++, Fall 2015
//
// LAB INFO:    Lab 8   Date/Time: Wed 10:30am   TA: Chetan
//**************************************************************************************************************
#include <cmath>      // For sqrt()
#include <sstream>    // For stringstream class
#include "Point.hpp"  // For Point class declaration

//--------------------------------------------------------------------------------------------------------------
// CTOR: Point()
//
// DESCRIPTION
// Default constructor. Initializes the point to be at the origin (0, 0).
//
// PSEUDOCODE
// Call init() and pass 0 and 0 as the parameters.
//--------------------------------------------------------------------------------------------------------------
Point::Point(){
    init(0,0);
}

//--------------------------------------------------------------------------------------------------------------
// CTOR: Point(int, int)
//
// DESCRIPTION
// Secondary constructor. Initializes the mX and mY data members to the input params.
//
// PSEUDOCODE
// Call init() and pass pInitX and pInitY as the params.
//--------------------------------------------------------------------------------------------------------------
Point::Point(int pInitX, int pInitY){
    init(pInitX,pInitY);
}

//--------------------------------------------------------------------------------------------------------------
// FUNCTION: distance(Point)
//
// DESCRIPTION
// Calculates distance from this Point to pAnotherPoint.
//
// PSEUDOCODE
// deltaX <- GetX() - pAnotherPoint.GetX()
// deltaY <- GetY() - pAnotherPoint.GetY()
// Return the square root of deltaX * deltaX + deltaY * deltaY
//--------------------------------------------------------------------------------------------------------------
double Point::distance(Point pAnotherPoint){
    int deltaX = getX() - pAnotherPoint.getX();
    int deltaY = getY() - pAnotherPoint.getY();
    return sqrt(deltaX * deltaX + deltaY * deltaY);
}

//--------------------------------------------------------------------------------------------------------------
// FUNCTION: getX()
//
// DESCRIPTION
// Accessor function for the mX data member.
//
// PSEUDOCODE
// Return mX.
//--------------------------------------------------------------------------------------------------------------
int Point::getX(){
    return mX;
}

//--------------------------------------------------------------------------------------------------------------
// FUNCTION: getY()
//
// DESCRIPTION
// Accessor function for the mY data member.
//
// PSEUDOCODE
// Return mY
//--------------------------------------------------------------------------------------------------------------
int Point::getY(){
    return mY;
}

//--------------------------------------------------------------------------------------------------------------
// FUNCTION: init(int, int)
//
// DESCRIPTION
// Initializes mX and mY to pInitX and pInitY.
//
// PSEUDOCODE
// Call setX() and pass pInitX as the parameter
// Call setY() and pass pInitY as the parameter
//--------------------------------------------------------------------------------------------------------------
void Point::init(int pInitX, int pInitY){
    setX(pInitX);
    setY(pInitY);
}

//--------------------------------------------------------------------------------------------------------------
// FUNCTION: move(int, int)
//
// DESCRIPTIONm
// Moves the point to the new (x, y) coordinates specified by the input params.
//
// PSEUDOCODE
// Call init() passing  and  as the params
//--------------------------------------------------------------------------------------------------------------
void Point::move(int pNewX, int pNewY){
    init(pNewX, pNewY);
}

//--------------------------------------------------------------------------------------------------------------
// FUNCTION: setX(int)
//
// DESCRIPTION
// Mutator function for the mX data member.
//
// PSEUDOCODE
// mX <- pNewX
//--------------------------------------------------------------------------------------------------------------
void Point::setX(int pNewX){
    mX = pNewX;
}

//--------------------------------------------------------------------------------------------------------------
// FUNCTION: setY(int)
//
// DESCRIPTION
// Mutator function for the mY data member.
//
// PSEUDOCODE
// mY <- pNewY
//--------------------------------------------------------------------------------------------------------------
void Point::setY(int pNewY){
    mY = pNewY;
}

//--------------------------------------------------------------------------------------------------------------
// FUNCTION: toString()
//
// DESCRIPTION
// Returns a string representation of the Point, e.g., if mX is 10 and mY is -130, then this function will
// return the string "(10, -130)".
//
// REMARKS
// The C++ Standard Library stringstream class is a stream class which is similar in functionality  to the
// ostream class (the class of the cout object that we use to send output to the output window). The difference
// between a stringstream object and cout is that for the stringstream object, the "output" is sent to a string
// object which is encapsulated within the stringstream object. For example,
//
//     stringstream sout;                 -- sout is a stringstream object which encapsulates a string.
//     sout << fixed << setprecision(3);  -- sout is configured so real numbers will be formatted in fixed notation
//                                           with 3 digits after the decimal pt.
//     sout << "Fred";                    -- The string in sout now contains "Fred".
//     int x = 123;
//     sout << ' ' << x;                  -- The string in sout now contains "Fred 123".
//     double y = 3.14159265828;
//     sout << endl << y;                 -- The string in sout now contains "Fred 123\n3.142".
//     cout << sout.str();                -- The str() function returns the string, i.e., "Fred 123\n3.142".
//
// Ref: http://cplusplus.com/reference/sstream/stringstream
//
// PSEUDOCODE
// Define a stringstream object named sout calling the default ctor.
// Send to sout "(" followed by the return value from getX() followed by ", " followed by getY() followed by ")".
// Return sout.str().
//--------------------------------------------------------------------------------------------------------------
string Point::toString(){
    stringstream sout;
    sout << "(" << getX() << ", " << getY() << ")";
    return sout.str();
}
