//**************************************************************************************************************
// FILE:        PointTest.cpp
//
// DESCRIPTION: Implementation of the PointTest class. See PointTest.hpp for more info.
//
// AUTHORS:     Paul ROnquillo            (pronquil@asu.edu)
//
//
// COURSE:      CSE100 Principles of Programming with C++, Fall 2015
//
// LAB INFO:    Lab 9   Date/Time: WED 10:30am   TA: Chetan
//**************************************************************************************************************
#include <iomanip>              // For setprecision()
#include <iostream>              // For cout, endl, fixed
#include "Color.hpp"              // For the Color class declaration
#include "Point.hpp"              // For the Point class declaration
#include "PointTest.hpp"              // For the PointTest class declaration

using namespace std;

//--------------------------------------------------------------------------------------------------------------
// FUNCTION: getInt()
//
// DESCRIPTION
// Display a prompt and read a number (as an int) from the keyboard. Return the number.
//--------------------------------------------------------------------------------------------------------------
int getInt(string pPrompt)
{
    int n;
    cout << pPrompt;
    cin >> n;
    return n;
}

//--------------------------------------------------------------------------------------------------------------
// CTOR: PointTest()
//
// DESCRIPTION
// Default constructor. Does nothing.
//
// REMARKS
// Every class must have at least one ctor, because when an object is instantiated, a ctor must be called. If
// there are no data members to initialize, then we just provide a default ctor that does nothing.
//--------------------------------------------------------------------------------------------------------------
PointTest::PointTest(){

}

//--------------------------------------------------------------------------------------------------------------
// FUNCTION: run()
//
// DESCRIPTION
// Tests the implementation of the Point class.
//
// PSEUDOCODE
// Define x, y, r, g, and b as int variables.
// Configure cout so real numbers are displayed in fixed notation with 3 digits after the decimal pt.
//
// Comment: Test that the default ctor works correctly.
// Define and instantiate a Point object named p1 calling the default ctor.
//
// Comment: Test that the second ctor works correctly.
// x <- getInt("Enter point p2 x? ").
// y <- getInt("Enter point p2 y? ").
// Define and instantiate a Point object named p2 passing x, y as the params to the ctor.
//
// Comment: Test that the third ctor works correctly.
// x <- getInt("Enter point p3 x? ").
// y <- getInt("Enter point p3 y? ").
// r <- getInt("Enter point p3 red? ").
// g <- getInt("Enter point p3 green? ").
// b <- getInt("Enter point p3 blue? ").
// Define and instantiate a Point object named p3 passing x, y, r, g, and b as the params to the ctor.
//
// Comment: Test that the fourth ctor works correctly.
// x <- getInt("Enter point p4 x? ").
// y <- getInt("Enter point p4 y? ").
// r <- getInt("Enter point p4 red? ").
// g <- getInt("Enter point p4 green? ").
// b <- getInt("Enter point p4 blue? ").
// Define and instantiate a Color object named color passing r, g, and b as the params to the ctor.
// Define and instantiate a Point object named p4 passing x, y, and color as the params to the ctor.
//
// Send to cout "The point p1 is " followed by p1.toString() followed by endl.
// Send to cout "The point p2 is " followed by p2.toString() followed by endl.
// Send to cout "The point p3 is " followed by p3.toString() followed by endl.
// Send to cout "The point p4 is " followed by p4.toString() followed by endl.
//--------------------------------------------------------------------------------------------------------------
void PointTest::run(){
    int x,y,r,g,b;
    cout << fixed << setprecision(3);
    Point p1;
    x = getInt("Enter point p2 x? ");
    y = getInt("Enter point p2 y? ");
    Point p2(x,y);
    x = getInt("Enter point p3 x? ");
    y = getInt("Enter point p3 y? ");
    r = getInt("Enter point p3 red? ");
    g = getInt("Enter point p3 green? ");
    b = getInt("Enter point p3 blue? ");
    Point p3(x,y,r,g,b);
    x = getInt("Enter point p4 x? ");
    y = getInt("Enter point p4 y? ");
    r = getInt("Enter point p4 red? ");
    g = getInt("Enter point p4 green? ");
    b = getInt("Enter point p4 blue? ");
    Color color(r,g,b);
    Point p4(x, y, color);

    cout << "The point p1 is " << p1.toString() << endl;
    cout << "The point p2 is " << p2.toString() << endl;
    cout << "The point p3 is " << p3.toString() << endl;
    cout << "The point p4 is " << p4.toString() << endl;
}
