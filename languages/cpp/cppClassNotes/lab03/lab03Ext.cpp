#include <iostream> // access to cout, cin, endl,
#include <iomanip>  //
#include <cmath>


using namespace std;
int NUM_STUDENTS = 3;

int main(){
	int exam1, exam2, exam3;
	double exam_avg, exam_stddev, exam_variance;

	cout << fixed << setprecision(2);
	cout << "something , give me your exams!!!!" << somevar;
	// cout << "Enter exam score for Homer: ";
	// cin >> exam1;
	//
	// cout << "Enter exam score for Lisa: ";
	// cin >> exam2;
	//
	// cout << "Enter exam score for Ralph: ";
	// cin >> exam3;
	//
	// exam_avg = (exam1 + exam2 + exam3)/static_cast<double>(NUM_STUDENTS);
	//
	// cout << endl; // Send empty line to cout
	//
	// cout << "The average exam score is:      " << exam_avg << "%" << endl;
	//
	// exam_variance = (pow(exam1 - exam_avg, 2) + pow(exam2 - exam_avg, 2) + pow(exam3 - exam_avg, 2))/(NUM_STUDENTS - 1);
	// exam_stddev = sqrt(exam_variance);
	//
	// cout << "The exam standard deviation is: " << exam_stddev << endl;

	return 0;
}


int getExams(){
	cout << "getExams accessed" << endl;
	return 0;
}

//**************************************************************************************************
// FILE:        lab03.cpp
//
// DESCRIPTION: short DESCRIPTION
//
// AUTHORS:     Paul Ronquillo           (pronquil@asu.edu)
//                
//
// COURSE:      CSE100 Principles of Programming with C++, Fall 2015
//
// LAB INFO:    Lab 3   Date/Time: jfjdfjfjfj   Lab TA: Chetan Patil
//**************************************************************************************************
