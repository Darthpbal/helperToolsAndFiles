//**************************************************************************************************************
// FILE:        Lab07.cpp
//
// DESCRIPTION: Calculates a person's lucky number using Zelda's Even Better Lucky Number formula
//
//              Illustrates the following C++ concepts:
//              1. Concepts covered in Labs 1-6.
//              2. Writing if statements to alter flow of control.
//              3. Writing programs involving multiple functions.
//              4. Calling functions and passing paramters by value.
//              5. Returning values from functions..
//
// AUTHORS:     your-name            (your-email-address)
//              your-partner's-name  (your-partners-email-address)
//
// COURSE:      CSE100 Principles of Programming with C++, Fall 2015
//
// LAB INFO:    Lab 7   Date/Time: Wed 10:30am   TA: your-lab-ta
//
// -------------------------------------------------------------------------------------------------------------
// TEST CASE 1:
// -------------------------------------------------------------------------------------------------------------
// DESCRIPTION:
// Tests that the correct lucky number is calculated and displayed.
//
// TEST CASE INPUT DATA:
// Customer name          = Cletus
// Birthdate month        = 8
// Birthdate day          = 31
// Birthdate year         = 1961
// Height in inches       = 70
// Weight in pounds       = 190
// Eye color              = brown (e will be 5)
// Index finger in inches = 3.1
// Ring finger in inches  = 3.8 (f will be -1)
//
// EXPECTED OUTPUT GIVEN THE INPUT:
// "Cletus, your lucky number is 10. Thank you, that will be $25."
//
// OBSERVED OUTPUT:
// "Cletus, your lucky number is 10. Thank you, that will be $25."
//
// TEST CASE RESULT: <PASSED>
//
// -------------------------------------------------------------------------------------------------------------
// TEST CASE 2:
// -------------------------------------------------------------------------------------------------------------
// DESCRIPTION:
// Tests that the correct lucky number is calculated and displayed.
//
// TEST CASE INPUT DATA:
// Customer name          = Paul
// Birthdate month        = 9
// Birthdate day          = 27
// Birthdate year         = 1991
// Height in inches       = 70
// Weight in pounds       = 135
// Eye color              = Brown (e will be 5)
// Index finger in inches = 4
// Ring finger in inches  = 3 (f will be 1)
//
// EXPECTED OUTPUT GIVEN THE INPUT:
// "Paul, your lucky number is 2 Thank you, that will be $25."
//
// OBSERVED OUTPUT:
// "Paul, your lucky number is 1 Thank you, that will be $25."
//
// TEST CASE RESULT: <FAILED>
//
// -------------------------------------------------------------------------------------------------------------
// TEST CASE 3:
// -------------------------------------------------------------------------------------------------------------
// DESCRIPTION:
// Tests that the correct lucky number is calculated and displayed.
//
// TEST CASE INPUT DATA:
// Customer name          = Foo
// Birthdate month        = 1
// Birthdate day          = 2
// Birthdate year         = 2000
// Height in inches       = 50
// Weight in pounds       = 150
// Eye color              = option 55 (e will be undefined )
// Index finger in inches = 6
// Ring finger in inches  = 6 (f will be undefined ) //I think this would be a condition where the program would do something strange or fail or something since the instructions didn't specify using a <= or >= comparison.
//
// EXPECTED OUTPUT GIVEN THE INPUT:
// "An invalid eye color was selected. The program is terminating..."
//
// OBSERVED OUTPUT:
// "An invalid eye color was selected. The program is terminating..."
//
// TEST CASE RESULT: <PASSED>
//**************************************************************************************************************
#include <cstdlib>  // For abs() and exit()

// What header file must be included to access the pow() and sqrt() functions?
#include <cmath>

// What header file must be included to access cin, cout, and endl?
#include <iostream>
// What header file must be included to use the string class?
#include <string>

using namespace std;

// Constants for converting inch to cm and lb to kg.
const double CM_PER_INCH =       2.54;
const double LB_PER_KG   = 2.20462262;

// Eye color menu constants.
const int MENU_BLACK   = 1;
const int MENU_BLUE    = 2;
const int MENU_GREEN   = 3;
const int MENU_BROWN   = 4;
const int MENU_GRAY    = 5;
const int MENU_HAZEL   = 6;
const int MENU_RED     = 7;
const int MENU_PINK    = 8;
const int MENU_VIOLET  = 9;

// This is a prototype (or function declaration) and is necessary because the function definition of
// ValidateEyeColor() appears in the source code file below the point where it is called. Remember, the rule
// in C++ is that a function must be defined or declared before it is called.
void ValidateEyeColor(int pChoice);

// GetInt() also has to be declared because it is called from GetEyeColor() which is defined above GetInt().
int GetInt(string);

//--------------------------------------------------------------------------------------------------------------
// FUNCTION: CalcLucky()
//
// DESCRIPTION
// Calculates and returns the customer's lucky number using the Even Better Lucky Number Formula(tm).
//
// PARAMS:
// pDate    int     d in the formula
// pHeight  int     h in the formula
// pMonth   int     m in the formula
// pWeight  int     w in the formula
// pYear    int     y in the formula
// pEye     int     e in the formula
// pFinger  double  f in the formula
//--------------------------------------------------------------------------------------------------------------
// Write the header for this function and the opening left brace for the body.
int CalcLucky( int pDate,  int pHeight,  int pMonth,  int pWeight,  int pYear,  int pEye, double pFinger)
{    // Define double variable term1 and assign to it: 2m^2.2 + 3d^3.3 + 5sqrt(y).
    double term1 = 2 * pow( pMonth , 2.2) + 3 * pow( pDate, 3.3) + 5 * sqrt( pYear );

    // Define an int variable term2 and assign to it: ( eh) / 3. The division is to performed as integer division.
    int term2 = ( pEye * pHeight) / 3;

    // Define an int variable term3 and assign to it: ( 11w) / 5. Integer divison.
    int term3 = ( 11 * pWeight) / 5;

    // Define a double variable term4 and assign to it: term1 + f( term2 + term3).
    double term4 = term1 + ( pFinger * (term2 + term3));

    // Calculate and return the lucky number using term4 and the lucky number formula.
    return (static_cast<int>(abs(term4)) % 10) + 1;
}

//--------------------------------------------------------------------------------------------------------------
// FUNCTION: ConvertInchToCm()
//
// DESCRIPTION
// Converts inches to centimeters.
//--------------------------------------------------------------------------------------------------------------
double ConvertInchToCm(double pInches)
{
    return pInches * CM_PER_INCH;
}

//--------------------------------------------------------------------------------------------------------------
// FUNCTION: ConvertLbToKg()
//
// DESCRIPTION
// Converts pounds to kilograms.
//--------------------------------------------------------------------------------------------------------------
double ConvertLbToKg(double pLbs)
{
    return pLbs / LB_PER_KG;
}

//--------------------------------------------------------------------------------------------------------------
// FUNCTION: GetDouble()
//
// DESCRIPTION
// Display a prompt and read a number (as a double) from the keyboard. Return the number.
//--------------------------------------------------------------------------------------------------------------
double GetDouble(string pPrompt)
{
    double n;
    cout << pPrompt;
    cin >> n;
    return n;
}

//--------------------------------------------------------------------------------------------------------------
// FUNCTION: GetEyeColor()
//
// DESCRIPTION
// Displays a menu of eye colors and asks the user to select one. Returns e based on the table in the lab
// project document.
//--------------------------------------------------------------------------------------------------------------
// Write the header for this function and the opening left brace for the body.
int GetEyeColor(){
    // Write cout statements to display the eye color menu per the project document.
    cout << "What color are your eyes?\n1.  Black\n2.  Blue\n3.  Green\n4.  Brown\n5.  Gray\n6.  Hazel\n7.  Red\n8.  Pink\n9.  Violet\n ";

    // Define an int variable named 'choice'. Call GetInt() and pass "Select Eye Color: " as the parameter
    // string. Assign the value returned by GetInt() to variable choice.
    int choice;
    choice = GetInt("Select Eye Color: ");

    // Call ValidateEyeColor() and pass choice as a parameter. If the user's menu choice was invalid (less than
    // 1 or greater than 9) then ValidateEyeColor() will display an error message and terminate the program.
    ValidateEyeColor(choice);

    // Define an int variable named e.
    int e;

    // Write an if-elseif-elseif-... statement to set e to the correct value depending on the value of choice.
    // That is, you must check to see if choice is MENU_BLACK. If it is, then set e to 3. Otherwise, check to
    // see if choice is MENU_BLUE. If it is, then set e to -2. Otherwise, check to see if choice is MENU_GREEN.
    // If it is, then set e to 17. Otherwise...
    bool stepGameUp = false;

    if(stepGameUp){
        switch(choice){
            case MENU_BLACK:
                e =  3;
                break;
            case MENU_BLUE:
                e = -2;
                break;
            case MENU_GREEN:
                e = 17;
                break;
            case MENU_BROWN:
                e =  5;
                break;
            case MENU_GRAY:
                e = 12;
                break;
            case MENU_HAZEL:
                e = -8;
                break;
            case MENU_RED:
                e =  4;
                break;
            case MENU_PINK:
                e =  0;
                break;
            case MENU_VIOLET:
                e = 11;
                break;
        }
    }
    else{
        if(choice == MENU_BLACK){ e = 3;}
        else if(choice == MENU_BLUE){ e = -2;}
        else if(choice == MENU_GREEN){ e = 17;}
        else if(choice == MENU_BROWN){ e = 5;}
        else if(choice == MENU_GRAY){ e = 12;}
        else if(choice == MENU_HAZEL){ e = -8;}
        else if(choice == MENU_RED){ e = 4;}
        else if(choice == MENU_PINK){ e = 0;}
        else if(choice == MENU_VIOLET){ e = 11;}
    }

    // Return e.
    return e;
}

//--------------------------------------------------------------------------------------------------------------
// FUNCTION: GetInt()
//
// DESCRIPTION
// Display a prompt and read a number (as an int) from the keyboard. Return the number.
//--------------------------------------------------------------------------------------------------------------
int GetInt(string pPrompt)
{
    int n;
    cout << pPrompt;
    cin >> n;
    return n;
}

//--------------------------------------------------------------------------------------------------------------
// FUNCTION: GetString()
//
// DESCRIPTION
// Display a prompt and read a string from the keyboard. Return the string.
//--------------------------------------------------------------------------------------------------------------
string GetString(string pPrompt)
{
    string s;
    cout << pPrompt;
    cin >> s;
    return s;
}

//--------------------------------------------------------------------------------------------------------------
// FUNCTION: Round
//
// DESCRIPTION
// Rounds pDouble up or down and returns the result as an int. This function is called to convert the weight
// in kg and the height in cm to integers.
//--------------------------------------------------------------------------------------------------------------
int Round(double pDouble)
{
    if (pDouble >= 0) {
        return static_cast<int>(pDouble + 0.5);
    } else {
        return static_cast<int>(pDouble - 0.5);
    }
}

//--------------------------------------------------------------------------------------------------------------
// FUNCTION: ValidateEyeColor()
//
// DESCRIPTION
// Validates that the user selects an eye color menu item in the range 1-9. If so, this function simply returns.
// If not, we display an error message and terminate the program.
//--------------------------------------------------------------------------------------------------------------
void ValidateEyeColor(int pChoice)
{
    if (pChoice < MENU_BLACK || pChoice > MENU_VIOLET) {
        cout << "An invalid eye color was selected. The program is terminating..." << endl;
        exit(-1);
    }
}

//--------------------------------------------------------------------------------------------------------------
// FUNCTION: main()
//--------------------------------------------------------------------------------------------------------------
int main()
{
    cout << "Zelda's Lucky Number Calculator" << endl << endl;

    // Define int local variables: date, e, heightCm, heightIn, lucky, month, weightKg, weightLb, year.
    int date, e, heightCm, heightIn, lucky, month, weightKg, weightLb, year;

    // Define double local variables: f, index, ring.
    double f, index, ring;

    // Define string object: name.
    string name;

    // Call GetString() asking for the customer's first name. Assign the return value to name.
    name = GetString("What is your name? ");

    // Call GetInt() asking for the month of the customer's birthdate. Assign the return value to variable month.
    month = GetInt("In what month were you born? ");

    // Call GetInt() asking for the date of the customer's birthdate. Assign the return value to variable date.
    date = GetInt("What was the date? ");

    // Call GetInt() asking for the year of the customer's birthdate. Assign the return value to variable year.
    year = GetInt("What was the year? ");

    // Call GetIt() asking for the customer's height in inches. Assign the return value to heightIn.
    heightIn = GetInt("What is your height (inches)? ");

    // Call GetInt() asking for the customer's weight in lbs. Assign the return value to weightLb.
    weightLb = GetInt("What is your weight (lbs)? ");

    // Call ConvertInchToCm() passing heightIn as the parameter. Pass the return value from ConvertInchToCm()
    // as the input parameter to Round(). Assign the return value from Round() to heightCm.
    heightCm = Round(ConvertInchToCm(heightIn));

    // Call ConvertLbToKg() passing weightLb as the parameter. Pass the return value from ConvertLbToKg() as
    // the input parameter to Round(). Assign the return value from Round() to weightKg.
    weightKg = Round(ConvertLbToKg(weightLb));

    // Call GetEyeColor() to display the eye color menu and get the value of e. Assign the return value to e.
    e = GetEyeColor();

    // Call GetDouble() asking for the length of the customer's index finger. Assign the return value to
    // variable index.
    index = GetDouble("How long is your index finger? ");

    // Call GetDouble() asking for the length of the customer's ring finger. Assign the return value to
    // variable ring.
    ring = GetDouble("How long is your ring finger? ");

    // Assign 0 to f.
    f = 0;

    // Set f to -1 if index is less than ring or +1 if index is greater than ring.
    if(index < ring){
        f = -1;
    }
    else if(index > ring){
        f = 1;
    }

    // Call CalcLucky() passing date, heightCm, month, weightKg, year, e, and f as parameters. Assign the
    // return value to lucky.
    lucky = CalcLucky(date, heightCm, month, weightKg, year, e, f);

    // Display the  lucky number and return from main().
    cout << name << ", your lucky number is " << lucky << ". Thank you, that will be $25." << endl;

    return 0;
}
