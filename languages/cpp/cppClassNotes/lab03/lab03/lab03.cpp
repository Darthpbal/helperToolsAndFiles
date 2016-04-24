//**************************************************************************************************
// FILE:         Lab03.cpp
//
// DESCRIPTION:  Reads three exam scores for three students, calculates and displays the average
//               exam score and the standard deviation of the exam scores.
//
// AUTHORS:      Paul Ronquillo (pronquil@asu.edu)
//
//
// COURSE:       CSE100 Principles of Programming with C++, Fall 2015
//
// LAB INFO:     Lab 3   Date/Time: Wed 10:30am - 11:20am   Lab TA: Chetan
//**************************************************************************************************


/*some description of
 * this
 * function
*/
#include <iostream> // access to cout, cin, endl,
#include <iomanip>  //give access to iomanipulation library
#include <cmath>		// math library


using namespace std;

int NUM_STUDENTS = 3;

int main(){

	int exam1, exam2, exam3, exams;
	double exam_avg, exam_stddev, exam_variance;

	cout << fixed << setprecision(2);

	std::getExams();

	cout << "Enter exam score for Homer: ";
	cin >> exam1;

	cout << "Enter exam score for Lisa: ";
	cin >> exam2;

	cout << "Enter exam score for Ralph: ";
	cin >> exam3;

	exam_avg = (exam1 + exam2 + exam3)/static_cast<double>(NUM_STUDENTS);

	cout << endl; // Send empty line to cout

	cout << "The average exam score is:      " << exam_avg << "%" << endl;

	exam_variance = (pow(exam1 - exam_avg, 2) + pow(exam2 - exam_avg, 2) + pow(exam3 - exam_avg, 2))/(NUM_STUDENTS - 1);
	exam_stddev = sqrt(exam_variance);

	cout << "The exam standard deviation is: " << exam_stddev << endl;
	return 0;
}


int getExams(){
	cout << "getExams accessed" << endl;
	return 0;
}
