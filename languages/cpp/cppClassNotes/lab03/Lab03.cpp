//**************************************************************************************************
// FILE:         Lab03.cpp
//
// DESCRIPTION:  Reads three exam scores for three students, calculates and displays the average
//               exam score and the standard deviation of the exam scores.
//
// AUTHORS:      your-name (your-email-addr)
//               your-partners-name (your-partners-email-addr)
//
// COURSE:       CSE100 Principles of Programming with C++, Fall 2015
//
// LAB INFO:     Lab 3   Date/Time: day-and-time-of-your-lab-session   Lab TA: <your-lab-ta's-name>
//**************************************************************************************************
// Include the necessary header files. Hint: there are three. Hint Hint: one is so we can access and
// use the pow() and sqrt() functions from the C++ Standard library; one is so we can access and use
// cin, cout, endl, and fixed; and one is so we can access setprecision().
#include <iostream>
#include <iomanip>
#include  <cmath>

// using... what? This line is necessary so that we can refer to C++ Standard Library components by
// what I call their "short name" rather than their "full name". For example, in the C++ Std Lib,
// cout is defined to be part of the std namespace, so the full name of cout is really std::cout.
// To be able to refer to std::cout as simply cout (it's short name), we write the line below.
using namespace std;

// Define an int constant named NUM_STUDENTS and initialize it to 3. Constants are normally defined
// outside and above main(). The scope of a constant is the locations in the code where the constant
// is accessible, i.e., can be used. A constant defined outside of main() has scope from the line
// where the constant is defined to the end of the source code file. This means NUM_STUDENTS is
// accessible within main().
int NUM_STUDENTS = 3;


//--------------------------------------------------------------------------------------------------
// FUNCTION: main()
//--------------------------------------------------------------------------------------------------
int main()
{
    // Define three int variables named: exam1, exam2, exam3.
    int exam1, exam2, exam3;

    // Define three double variables named exam_avg, exam_stddev, and exam_variance.
    double exam_avg, exam_stddev, exam_variance;

    // Configure the cout stream so real numbers are printed in fixed notation with two digits after
    // the decimal point.
    ???

    // Display message prompting the user to enter the exam score for Homer.
    ???

    // Read the score from the keyboard into exam1.
    ???

    // Display message prompting the user to enter the exam score for Lisa.
    ???

    // Read the score from the keyboard into exam2.
    ???

    // Display message prompting the user to enter the exam score for Ralph.
    ???

    // Read the score from the keyboard into exam3.
    ???

    // Calculate the exam_avg as the sum of the three exam scores divided by NUM_STUDENTS. Hint: to
    // get the correct answer, you must type cast NUM_STUDENTS to act as a double using the static_
    // cast<double> operator.
    ???

    // Display a newline or blank line by sending endl to cout.
    ???

    // Display the average exam score.
    ???

    // Calculate exam_variance using the formula from the lab project document. Hint: because the
    // numerator of the division operator will be a double, it is not necessary to type cast NUM_
    // STUDENTS to double using the static_cast<> operator.
    ???

    // Calculate exam_stddev using the formula from the lab project document.
    ???

    // Display the exam standard deviation.
    ???

    // What does main() return to indicate that the program finished successfully? Hint: main()
    // returns an int.
    ???
}
