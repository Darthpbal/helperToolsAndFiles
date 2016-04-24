//**************************************************************************************************************
// FILE:        Lab08.cpp
//
// DESCRIPTION: Contains the main() function. Instantiates a PointTest object which tests the Point class.
//
// AUTHORS:     Paul Ronquillo            (pronquil@asu.edu)

//
// COURSE:      CSE100 Principles of Programming with C++, Fall 2015
//
// LAB INFO:    Lab 8   Date/Time: Wed 10:30am   TA: Chetan
//--------------------------------------------------------------------------------------------------------------
// TESTING:
//
// TEST CASE 1:
// ------------
// TEST CASE INPUT DATA:
// Point p1 x =  11
// Point p1 y =  22
// Point p2 x = -33
// Point p2 y = -44
//
// EXPECTED OUTPUT GIVEN THE INPUT:
// The point p1 is (11, 22)
// The point p2 is (-33, -44)
// The distance between the points is 79.322
// Moving point p1...The point p1 is now at (100, 200)
// The distance between the points is 277.894
// Moving point p2...The point p2 is now at (300, 400)
// The distance between the points is 282.843
//
// OBSERVED OUTPUT:
// The point p1 is (11, 22)
// The point p2 is (-33, -44)
// The distance between the points is 79.322
// Moving point p1...The point p1 is now at (100, 200)
// The distance between the points is 277.894
// Moving point p2...The point p2 is now at (300, 400)
// The distance between the points is 282.843
//
// TEST CASE RESULT: PASS
//
// TEST CASE 2:
// ------------
// TEST CASE INPUT DATA:
// Point p1 x = 4
// Point p1 y = 20
// Point p2 x = 0
// Point p2 y = 0
//
// EXPECTED OUTPUT GIVEN THE INPUT:
// The point p1 is (4, 20)
// The point p2 is (0, 0)
// The distance between the points is 20.396
// Moving point p1...The point p1 is now at (100, 200)
// The distance between the points is 223.607
// Moving point p2...The point p2 is now at (300, 400)
// The distance between the points is 282.843
//
// OBSERVED OUTPUT:
// The point p1 is (4, 20)
// The point p2 is (0, 0)
// The distance between the points is 20.396
// Moving point p1...The point p1 is now at (100, 200)
// The distance between the points is 223.607
// Moving point p2...The point p2 is now at (300, 400)
// The distance between the points is 282.843
//
// TEST CASE RESULT: PASS
//**************************************************************************************************************
#include "PointTest.hpp"

//--------------------------------------------------------------------------------------------------------------
// FUNCTION: main()
//
// DESCRIPTION
// Starting point for the program.
//
// PSEUDOCODE
// Define a PointTest object named pointTest calling the default ctor.
// Call run() on the pointTest object.
// Return 0.
//--------------------------------------------------------------------------------------------------------------
int main() {
    PointTest pointTest;
    pointTest.run();
    return 0;
}
