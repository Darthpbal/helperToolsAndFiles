//**************************************************************************************************************
// FILE:        PointTest.cpp
//
// DESCRIPTION: Implementation of the PointTest class. See PointTest.hpp for more info.
//
// AUTHORS:     Paul Ronquillo            (pronquil@asu.edu)

//
// COURSE:      CSE100 Principles of Programming with C++, Fall 2015
//
// LAB INFO:    Lab 8   Date/Time: Wed 10:30am   TA: Chetan
//**************************************************************************************************************
#include <iomanip>        // For setprecision()
#include <iostream>       // For cout, endl, fixed
#include "PointTest.hpp"  // For the PointTest class declaration
#include "Point.hpp"      // For the Point class declaration

using namespace std;

//--------------------------------------------------------------------------------------------------------------
// FUNCTION: getInt()
//
// DESCRIPTION
// Display a prompt and read a number (as an int) from the keyboard. Return the number.
//--------------------------------------------------------------------------------------------------------------
int getInt(string pPrompt)
{
    cout << pPrompt;
    int n;
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
PointTest::PointTest()
{
}

//--------------------------------------------------------------------------------------------------------------
// FUNCTION: run()
//
// DESCRIPTION
// Tests the implementation of the Point class.
//
// PSEUDOCODE
// Define x and y as int variables.
// Configure cout so real numbers are displayed in fixed notation with 3 digits after the decimal pt.
// x <- getInt("Enter point p1 x? ").
// y <- getInt("Enter point p1 y? ").
// Define and instantiate a Point object named p1 passing x and y as the params to the ctor.
// x <- getInt("Enter point p2 x? ").
// y <- getInt("Enter point p2 y? ").
// Define and instantiate a Point object named p2 passing x and y as the params to the ctor.
// Send to cout "The point p1 is " followed by p1.toString() followed by endl.
// Send to cout "The point p2 is " followed by p2.toString() followed by endl.
// Send to cout "The distance between the points is " followed by p1.distance(p2) followed by endl.
// Send to cout "Moving point p1...".
// Call p1.move(100, 200).
// Send to cout "The point p1 is now at " followed by p1.toString() followed by endl.
// Send to cout "The distance between the points is " followed by p2.distance(p1) followed by endl.
// Send to cout "Moving point p2...".
// Call p2.move(300, 400).
// Send to cout "The point p2 is now at " followed by p2.toString() followed by endl.
// Send to cout "The distance between the points is " followed by p1.distance(p2) followed by endl.
//--------------------------------------------------------------------------------------------------------------
void PointTest::run(){
    int x, y;
    cout << fixed << setprecision(3);
    x = getInt("Enter point p1 x? ");
    y = getInt("Enter point p1 y? ");
    Point p1(x,y);
    x = getInt("Enter point p2 x? ");
    y = getInt("Enter point p2 y? ");
    Point p2(x,y);
    cout << "The point p1 is " << p1.toString() << endl;
    cout << "The point p2 is " << p2.toString() << endl;
    cout << "The distance between the points is " << p1.distance(p2) << endl;
    cout << "Moving point p1...";
    p1.move(100,200);
    cout << "The point p1 is now at " << p1.toString() << endl;
    cout << "The distance between the points is " << p2.distance(p1) << endl;
    cout << "Moving point p2...";
    p2.move(300,400);
    cout << "The point p2 is now at " << p2.toString() << endl;
    cout << "The distance between the points is " << p1.distance(p2) << endl;
}
