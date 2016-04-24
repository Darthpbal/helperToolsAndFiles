//**************************************************************************************************
// FILE:        Lab04.cpp
//
// DESCRIPTION: Illustrates the following C++ concepts:
//
//              1. Define and use local variables.
//              2. Use cout to display string literals and variables.
//              3. Use cin to read values from the keyboard into variables.
//              4. Use the arithmetic operators.
//              5. Call math functions from the C++ standard library.
//              6. Define and use string objects.
//              7. Functions. Function calls. Pass parameters by-value. Return values.
//
// AUTHORS:     Paul Ronquillo           pronquil@asu.edu
//
// COURSE:      CSE100 Principles of Programming with C++, Fall 2015
//
// LAB INFO:    Lab 4   Date/Time: Wednesday 10:30am   TA: Chetan
//--------------------------------------------------------------------------------------------------
// TESTING:
//
// Test Case 1:
// ------------
// DESCRIPTION:
// Tests that the program computes and displays the correct lucky number.
//
// TEST CASE INPUT DATA:
// Customer name    = Cletus
// Birthdate month  = 3
// Birthdate day    = 13
// Birthdate year   = 1970
// Height in inches = 80
// Weight in lbs    = 120
//
// EXPECTED OUTPUT GIVEN THE INPUT:
// "Cletus, your lucky number is 5 Thank you, that will be $25."
//
// OBSERVED OUTPUT:
// "Cletus, your lucky number is 5 Thank you, that will be $25."
//
// TEST CASE RESULT:
// <PASSED>
//
// Test Case 2:
// ------------
// DESCRIPTION:
// Tests that the program computes and displays the correct lucky number.
//
// TEST CASE INPUT DATA:
// Customer name    = Paul
// Birthdate month  = 9
// Birthdate day    = 27
// Birthdate year   = 1991
// Height in inches = 70
// Weight in lbs    = 130
//
// EXPECTED OUTPUT GIVEN THE INPUT:
// "Paul, your lucky number is 8 Thank you, that will be $25."
//
// OBSERVED OUTPUT:
// "Paul, your lucky number is 9 Thank you, that will be $25."
//
// TEST CASE RESULT:
// <FAILED>
//**************************************************************************************************


#include <cmath>
#include <iostream>
#include <string>
// #include <stdlib.h>

using namespace std;
const double CM_PER_INCH = 2.54;
const double LB_PER_KG = 2.20462262;
int CalcLucky(int pDate, double pHeight, int pMonth, double pWeight, int pYear)
{
    int term1 = 100 * pMonth * pMonth;
    int term2 = static_cast<int>(10 * pow(pDate,3));
    int term3 = (term1 + term2) / pYear;
    double term4 = static_cast<double>(pow(pWeight,6)) / pHeight;
    return static_cast<int>(term3 + sqrt(term4)) % 10 + 1;
}
double ConvertInchToCm(double pInches)
{
    return pInches * CM_PER_INCH;//CM_PER_INCH 2.51
}
double ConvertLbToKg(double pLbs)
{
    return pLbs / LB_PER_KG;// LB_PER_KG 2.20462262;
}
int GetInt(string pPrompt)
{
    cout << pPrompt;
    int n;
    cin >> n;
    return n;
}
string GetString(string pPrompt)
{
    string s;
    cout << pPrompt;
    cin >> s;
    return s;
}
int main()
{
    cout << "\nZelda's Lucky Number Calculator\n" << endl;
    string name = GetString("What is your first name? ");
    int month = GetInt("In what month were you born? ");
    int date = GetInt("What was the date? ");
    int year = GetInt("What was the year (yyyy)? ");
    int heightInch = GetInt("What is your height (inches)? ");
    int weightLb = GetInt("What is your weight (lbs)? ");
    double heightCm = ConvertInchToCm(heightInch);
    double weightKg = ConvertLbToKg(weightLb);
    int lucky = CalcLucky(date, heightCm, month, weightKg, year);
    cout << name << ", Your lucky number is " << lucky << ". Thank you, that will be $25.\n" << endl;
    return 0;
}





cout << "What's your Birthdate? (mm/dd/yyyy)";
string birthdate;
std::cin >> birthdate;
int month = static_cast<int>( strtod(birthdate.substr(0,2)) );
int date = static_cast<int>( strtod(birthdate.substr(3,2)) );
int year = static_cast<int>( strtod(birthdate.substr(6,4)) );
cout << "\nmonth = " << month << "\ndate = " << date << "\nyear = " << year << endl;