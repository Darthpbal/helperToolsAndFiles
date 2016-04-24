//**************************************************************************************************
// FILE:        Kalk.hpp
//
// DESCRIPTION: Class declaration for the Kalk interpreter.
//
// AUTHORS:     Paul Ronquillo           (pronquil@asu.edu)
// 
//
// COURSE:      CSE100 Principles of Programming with C++, Fall 2015
//
// LAB INFO:    Lab 10   Date/Time: Wed 10:30am-11:20am   Lab TA: Chetan Patil
//**************************************************************************************************

#ifndef KALK_HPP
#define KALK_HPP
#include <string>
using namespace std;

class Kalk{
    public:
        Kalk();
        void interpret();

    private:
        double mRegA;
        double mRegB;
        double mRegC;
        void add();
        void atob();
        void atoc();
        void btoa();
        void btoc();
        void ctoa();
        void ctob();
        void display();
        void div();
        void error(string pErrorMsg);
        void load();
        void mul();
        void power();
        string readString(string pPrompt);
        void sqrt();
        void sub();
};

#endif
