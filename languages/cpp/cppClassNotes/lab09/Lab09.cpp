//**************************************************************************************************************
// FILE:        Lab09.cpp
//
// DESCRIPTION: Contains the main() function. Instantiates a PointTest object which tests the Point class.
//
// AUTHORS:     Paul ROnquillo            (pronquil@asu.edu)
//
//
// COURSE:      CSE100 Principles of Programming with C++, Fall 2015
//
// LAB INFO:    Lab 9   Date/Time: WED 10:30am   TA: Chetan
//--------------------------------------------------------------------------------------------------------------
// TESTING:
//
// TEST CASE 1:
// ------------
// TEST CASE INPUT DATA:
// Point p2 x     =   22
// Point p2 y     =  -22
// Point p3 x     =   33
// Point p3 y     =  -33
// Point p3 red   =   50
// Point p3 green =  100
// Point p3 blue  =  200
// Point p4 x     =  -44
// Point p4 y     =   44
// Point p4 red   =  255
// Point p4 green =  127
// Point p4 blue  =    0
//
// EXPECTED OUTPUT GIVEN THE INPUT:
// The point p1 is (x, y) = (0, 0) and color = (0, 0, 0)
// The point p2 is (x, y) = (22, -22) and color = (0, 0, 0)
// The point p3 is (x, y) = (33, -33) and color = (50, 100, 200)
// The point p4 is (x, y) = (-44, 44) and color = (255, 127, 0)
//
// OBSERVED OUTPUT:
// The point p1 is (x, y) = (0, 0) and color = (0, 0, 0)
// The point p2 is (x, y) = (22, -22) and color = (0, 0, 0)
// The point p3 is (x, y) = (33, -33) and color = (50, 100, 200)
// The point p4 is (x, y) = (-44, 44) and color = (255, 127, 0)
//
// TEST CASE RESULT: PASS
//
// TEST CASE 2:
// ------------
// TEST CASE INPUT DATA:
// Point p2 x     = 25
// Point p2 y     = 52
// Point p3 x     = 30
// Point p3 y     = 60
// Point p3 red   = 255
// Point p3 green = 255
// Point p3 blue  = 255
// Point p4 x     = 40
// Point p4 y     = -20
// Point p4 red   = 0
// Point p4 green = 0
// Point p4 blue  = 127
//
// EXPECTED OUTPUT GIVEN THE INPUT:
// The point p1 is (x, y) = (0, 0) and color = (0, 0, 0)
// The point p2 is (x, y) = (25, 52) and color = (0, 0, 0)
// The point p3 is (x, y) = (30, 60) and color = (255, 255, 255)
// The point p4 is (x, y) = (40, -20) and color = (0, 0, 127)
//
// OBSERVED OUTPUT:
// The point p1 is (x, y) = (0, 0) and color = (0, 0, 0)
// The point p2 is (x, y) = (25, 52) and color = (0, 0, 0)
// The point p3 is (x, y) = (30, 60) and color = (255, 255, 255)
// The point p4 is (x, y) = (40, -20) and color = (0, 0, 127)
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
int main()
{
    PointTest pointTest;
    pointTest.run();
    return 0;
}
