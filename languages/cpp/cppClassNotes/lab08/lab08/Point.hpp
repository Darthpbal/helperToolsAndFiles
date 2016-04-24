//**************************************************************************************************************
// FILE:        Point.hpp
//
// DESCRIPTION: Declares a class to represent a point in the Cartesian plane. A point is represented by an
//              (x, y) coordinate, where both x and y are integers.
//
// AUTHORS:     Paul Ronquillo            (pronquil@asu.edu)

// 
// COURSE:      CSE100 Principles of Programming with C++, Fall 2015
//
// LAB INFO:    Lab 8   Date/Time: Wed 10:30am   TA: Chetan
//**************************************************************************************************************
#ifndef POINT_HPP  // This line, the line below it, and the #endif form what is called a preprocessor guard.
#define POINT_HPP  // Preprocessor guards are a hack to ensure a header file is not included multiple times.

#include <string>  // For string class

using namespace std;

class Point {
public:
	Point();                               // Default constructor
	Point(int pInitX, int pInitY);         // Second constructor
	double distance(Point pAnotherPoint);  // Calculates distance from this Point to pAnotherPoint
	int getX();                            // Accessor function for mX data member
	int getY();                            // Accessor function for mY data member
	void move(int pNewX, int pNewY);       // Moves the point to a new coordinate
	void setX(int pNewX);                  // Mutator function for mX data member
	void setY(int pNewY);                  // Mutator function for mY data member
	string toString();                     // Returns a string representation of the Point
private:
	void init(int pInitX, int pInitY);     // Initializes mX and mY to the params pInitX and pInitY
	int mX;                                // The x coordinate of the Point
	int mY;                                // The y coordinate of the Point
};

#endif // POINT_HPP
