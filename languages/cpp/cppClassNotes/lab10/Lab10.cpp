//**************************************************************************************************
// FILE:        Lab10.cpp
//
// DESCRIPTION: Implements an interpreter for a simple calcuator-based language named Kalk.
//
// AUTHORS:     Paul Ronquillo           (pronquil@asu.edu)
//               
//
// COURSE:      CSE100 Principles of Programming with C++, Fall 2015
//
// LAB INFO:    Lab 10   Date/Time: Wed 10:30am-11:20am   Lab TA: Chetan Patil
//**************************************************************************************************

#include "Kalk.hpp"
#include <string>
using namespace std;

int main()
{
    Kalk interp;
    interp.interpret();
    return 0;
}
