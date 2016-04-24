//**************************************************************************************************************
// FILE:        Point.hpp
//
// DESCRIPTION: Declares a class to represent a point in the Cartesian plane. A point is represented by an
//              (x, y) coordinate, where both x and y are integers.
//
// AUTHORS:     Paul ROnquillo            (pronquil@asu.edu)
//
//
// COURSE:      CSE100 Principles of Programming with C++, Fall 2015
//
// LAB INFO:    Lab 9   Date/Time: WED 10:30am   TA: Chetan
//**************************************************************************************************************
#ifndef POINT_HPP
#define POINT_HPP

#include <string>             // For string class
#include "Color.hpp"             // For Color class

using namespace std;

class Point {
public:
    Point();                                                                        // Default ctor
    Point(int pInitX, int pInitY);                                                  // Second ctor
    Point(int pInitX, int pInitY, int pInitRed, int pInitGreen, int pInitBlue);                                                                             // Third ctor
    Point(int pInitX, int pInitY, Color pInitColor);                                                                             // Fourth ctor
    double distance(Point pAnotherPoint);                                           // Calculates distance
    Color getColor();                                                                             // Accessor funct for mColor
    int getX();                                                                   // Accessor funct for mX
    int getY();                                                                     // Accessor funct for mY
    void move(int pNewX, int pNewY);                                                // Moves the point
    void setColor(Color pNewColor);                                                                             // Mutator funct for mColor
    void setX(int pNewX);                                                           // Mutator funct for mX
    void setY(int pNewY);                                                           // Mutator funct for mY
    string toString();                                                              // String rep. of this Point
private:
    void init(int pInitX, int pInitY);                                              // Initializes this Point
    Color mColor;                                                                             // Initializes this Point
    void init(int pInitX, int pInitY, int pInitRed, int pInitGreen, int pInitBlue);                                                                             // Initializes this Point
    void init(int pInitX, int pInitY, Color pInitColor);                                                                             // The color of the Point
    int mX;                                                                         // The x coord of the Point
    int mY;                                                                         // The y coord of the Point
};

#endif // POINT_HPP
