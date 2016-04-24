//**************************************************************************************************************
// FILE:        Color.hpp
//
// DESCRIPTION: Contains the class declaration for the Color class.
//
// AUTHORS:     Paul ROnquillo            (pronquil@asu.edu)
//
//
// COURSE:      CSE100 Principles of Programming with C++, Fall 2015
//
// LAB INFO:    Lab 9   Date/Time: WED 10:30am   TA: Chetan
//**************************************************************************************************************
#ifndef COLOR_HPP
#define COLOR_HPP

#include <string>
using namespace std;

// Write the class declaration for the Color class using the UML class diagram in the lab document as a guide.
class Color{
	private:
		int mBlue, mGreen, mRed;
		void init(int pInitRed, int pInitGreen, int pInitBlue);
	public:
		Color();
		Color(int pInitRed, int pInitGreen, int pInitBlue);
		int getRed();
		int getGreen();
		int getBlue();
		void setRed(int pNewRed);
		void setGreen(int pNewGreen);
		void setBlue(int pNewBlue);
		string toString();
};

#endif // COLOR_HPP
