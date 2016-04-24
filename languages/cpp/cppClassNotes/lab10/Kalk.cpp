//**************************************************************************************************
// FILE:        Kalk.cpp
//
// DESCRIPTION: Implementation of the Kalk class that is declared in Kalk.hpp.
//
// AUTHORS:     Paul Ronquillo           (pronquil@asu.edu)
//               
//
// COURSE:      CSE100 Principles of Programming with C++, Fall 2015
//
// LAB INFO:    Lab 10   Date/Time: Wed 10:30am-11:20am   Lab TA: Chetan Patil
//**************************************************************************************************

#include <cstdlib>                  // For exit()
#include <cmath>                  // For sqrt(), pow()
#include <iostream>                  // For cin, cout, endl
#include <string>                  // For string class declaration
#include "Kalk.hpp"
//--------------------------------------------------------------------------------------------------------------
// CTOR: Kalk::Kalk()
//
// DESCRIPTION
// Default ctor. Initializes registers a, b, and c to 0.
//
// PSEUDOCODE
// mRegA <- 0
// mRegB <- 0
// mRegC <- 0
//--------------------------------------------------------------------------------------------------------------
Kalk::Kalk(){
    mRegA = 0;
    mRegB = 0;
    mRegC = 0;
}

//--------------------------------------------------------------------------------------------------------------
// FUNCTION: Kalk::add()
//
// DESCRIPTION
// Adds registers a + b and writes the result to register a.
//
// OPERATOR: +
//
// PSEUDOCODE
// mRegA <- mRegA + mRegB
//--------------------------------------------------------------------------------------------------------------
void Kalk::add(){
    mRegA += mRegB;
}

//--------------------------------------------------------------------------------------------------------------
// FUNCTION: Kalk::atob()
//
// DESCRIPTION
// Copies the value of register a to register b.
//
// OPERATOR: b<-a
//
// PSEUDOCODE
// mRegB <- mRegA
//--------------------------------------------------------------------------------------------------------------
void Kalk::atob(){
    mRegB = mRegA;
}

//--------------------------------------------------------------------------------------------------------------
// FUNCTION: Kalk::atoc()
//
// DESCRIPTION
// Copies the value of register a to register c.
//
// OPERATOR: c<-a
//
// PSEUDOCODE
// mRegC <- mRegA
//--------------------------------------------------------------------------------------------------------------
void Kalk::atoc(){
    mRegC = mRegA;
}

//--------------------------------------------------------------------------------------------------------------
// FUNCTION: Kalk::btoa()
//
// DESCRIPTION
// Copies the value of register b to register a.
//
// OPERATOR: a<-b
//
// PSEUDOCODE
// mRegA <- mRegB
//--------------------------------------------------------------------------------------------------------------
void Kalk::btoa(){
    mRegA = mRegB;
}

//--------------------------------------------------------------------------------------------------------------
// FUNCTION: Kalk::btoc()
//
// DESCRIPTION
// Copies the value of register b to register c.
//
// OPERATOR: c<-b
//
// PSEUDOCODE
// mRegC <- mRegB
//--------------------------------------------------------------------------------------------------------------
void Kalk::btoc(){
    mRegC = mRegB;
}

//--------------------------------------------------------------------------------------------------------------
// FUNCTION: Kalk::ctoa()
//
// DESCRIPTION
// Copies the value of register c to register a.
//
// OPERATOR: a<-c
//
// PSEUDOCODE
// mRegA <- mRegC
//--------------------------------------------------------------------------------------------------------------
void Kalk::ctoa(){
    mRegA = mRegC;
}

//--------------------------------------------------------------------------------------------------------------
// FUNCTION: Kalk::ctob()
//
// DESCRIPTION
// Copies the value of register c to register b.
//
// OPERATOR: b<-c
//
// PSEUDOCODE
// mRegB <- mRegC
//--------------------------------------------------------------------------------------------------------------
void Kalk::ctob(){
    mRegB = mRegC;
}

//--------------------------------------------------------------------------------------------------------------
// FUNCTION: Kalk::display()
//
// DESCRIPTION
// Displays the specified register.
//
// OPERATOR: d reg
//
// PSEUDOCODE
// If reg is "a" Then
//     Send mRegA followed by endl to cout
// ElseIf reg is "b" Then
//     Send mRegB followed by endl to cout
// ElseIf reg is "c" Then
//     Send mRegC followed by endl to cout
// Else
//     Call error("Invalid register operand")
// End IF
//--------------------------------------------------------------------------------------------------------------
void Kalk::display(){
    string reg;
    cin >> reg;
    if(reg == "a"){
        cout << mRegA << endl;
    }
    else if(reg == "b"){
        cout << mRegB << endl;
    }
    else if(reg == "c"){
        cout << mRegC << endl;
    }
    else{
        error("Invalid register operand");
    }
}

//--------------------------------------------------------------------------------------------------------------
// FUNCTION: Kalk::div()
//
// DESCRIPTION
// Divides registers a / b and writes the result to register a.
//
// OPERATOR: /
//
// PSEUDOCODE
// mRegA <- mRegA / mRegB
//--------------------------------------------------------------------------------------------------------------
void Kalk::div(){
    mRegA /= mRegB;
}

//--------------------------------------------------------------------------------------------------------------
// FUNCTION: Kalk::error()
//
// DESCRIPTION
// Displays an error message and terminates the program by calling exit().
//
// PSEUDOCODE
// Send pErrorMsg followed by ", terminating..." followed by endl to cout
// Call exit(-1)
//--------------------------------------------------------------------------------------------------------------
void Kalk::error(string pErrorMsg){
    cout << pErrorMsg << ", terminating...\n";
    exit(-1);
}

//--------------------------------------------------------------------------------------------------------------
// FUNCTION: Kalk::interpret()
//
// DESCRIPTION
// The main interpreter loop. Reads the operator string and calls the appropriate function to perform the
// requested operation. Stop looping when "q" is entered.
//
// PSEUDOCODE (Note: you are writing a sentinel loop where the sentinel is an operation of "q")
// Define string object oper <- readString("? ")
// While oper != "Q" Do
//     If oper is "+" Then
//         Call add()
//     ElseIf oper is "b<-a" Then
//         Call atob()
//     ElseIf oper is "b<-c" Then
//         Call ctob()
//
//     ... and so on for each of the operators, you should be able to figure this out
//
//     Else
//         error("Invalid operator")
//     End If
//     oper <- readString("? ")
// End While
//--------------------------------------------------------------------------------------------------------------
void Kalk::interpret(){
    string oper = readString("? ");
    while(oper != "Q"){
         if(oper == "a<-b"){
            btoa();}
         else if(oper == "a<-c"){
            ctoa();}
         else if(oper == "b<-a"){
            atob();}
         else if(oper == "b<-c"){
            ctob();}
         else if(oper == "c<-a"){
            atoc();}
         else if(oper == "c<-b"){
            btoc();}
         else if(oper == "+"){
            add();}
         else if(oper == "-"){
            sub();}
         else if(oper == "*"){
            mul();}
         else if(oper == "/"){
            div();}
         else if(oper == "^"){
            power();}
         else if(oper == "&"){
            sqrt();}
         else if(oper == "l"){
            load();}
         else if(oper == "q"){
            exit(0);}
         else if(oper == "d"){
            display();}
        else{
            error("Invalid operator");
        }
        oper = readString("? ");
    }
}

//--------------------------------------------------------------------------------------------------------------
// FUNCTION: Kalk::load()
//
// DESCRIPTION
// Loads a register with a double value.
//
// OPERATOR: l reg value
//
// PSEUDOCODE
// Read char from keyboard into chReg
// If chReg is "a" Then
//     Read double from keyboard into mRegA
// ElseIf chReg is "b" Then
//     Read double from keyboard into mRegB
// ElseIf chReg is "c" Then
//     Read double from keyboard into mRegC
// Else
//     Call error("Invalid register operand")
// End If
//--------------------------------------------------------------------------------------------------------------
void Kalk::load(){
    char chReg;
    cin >> chReg;
    if(chReg == 'a'){
        cin >> mRegA;
    }
    else if(chReg == 'b'){
        cin >> mRegB;
    }
    else if(chReg == 'c'){
        cin >> mRegC;
    }
    else{
        error("Invalid register operand");
    }
}

//--------------------------------------------------------------------------------------------------------------
// FUNCTION: Kalk::mul()
//
// DESCRIPTION
// Multiplies registers a * b and writes the result to register a.
//
// OPERATOR: *
//
// PSEUDOCODE
// mRegA <- mRegA * mRegB
//--------------------------------------------------------------------------------------------------------------
void Kalk::mul(){
    mRegA *= mRegB;
}

//--------------------------------------------------------------------------------------------------------------
// FUNCTION: Kalk::power()
//
// DESCRIPTION
// Writes a^b to a.
//
// OPERATOR: ^
//
// PSEUDOCODE
// mRegA <- pow(mRegA, mRegB)
//--------------------------------------------------------------------------------------------------------------
void Kalk::power(){
    mRegA = pow(mRegA, mRegB);
}

//--------------------------------------------------------------------------------------------------------------
// FUNCTION: Kalk::readString()
//
// DESCRIPTION
// Display the prompt string pPrompt, read a string from the keyboard, and return the string.
//
// PSEUDOCODE
// Send pPrompt to cout
// Read a string from the keyboard into s
// Return s
//--------------------------------------------------------------------------------------------------------------
string Kalk::readString(string pPrompt){
    cout << pPrompt;
    string s;
    cin >> s;
    return s;
}

//--------------------------------------------------------------------------------------------------------------
// FUNCTION: Kalk::sqrt()
//
// DESCRIPTION
// Writes the sqrt of register a to a.
//
// OPERATOR: &
//
// PSEUDOCODE
// mRegA <- ::sqrt(mRegA)
//
// REMARKS
// Note, the name of this function is the same as the name of the sqrt() function defined in the C++ math
// library. If we wrote,
//
//     mRegA = sqrt(mRegA);
//
// Then the compiler would interpret this as if we meant to call this sqrt() function again... which we
// don"t. We want to call the one in the C++ math library. To do that, we precede the sqrt() function by
// two colons, i.e., ::sqrt(mRegA) which tells the compiler to call the sqrt() function from the math
// library.
//--------------------------------------------------------------------------------------------------------------
void Kalk::sqrt(){
    mRegA = ::sqrt(mRegA);
}

//--------------------------------------------------------------------------------------------------------------
// FUNCTION: Kalk::sub()
//
// DESCRIPTION
// Subtracts registers a - b and writes the result to register a.
//
// OPERATOR: -
//
// PSEUDOCODE
// mRegA = mRegA - mRegB
//--------------------------------------------------------------------------------------------------------------
void Kalk::sub(){
    mRegA = mRegA - mRegB;
}
