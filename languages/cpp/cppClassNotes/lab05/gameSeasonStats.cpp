//**************************************************************************************************
// FILE:        Lab_05.cpp
//
// DESCRIPTION: Reads season statistics for basketball players from an input file, computes per-game
//              statistics, and writes the per-game statistics to an output file.
//
// AUTHORS:     Paul Ronquillo           (pronquil@asu.edu)
//               
//
// COURSE:      CSE100 Principles of Programming with C++, Fall 2015
//
// LAB INFO:    Lab 5   Date/Time: Wed 10:30am-11:20am   Lab TA: Chetan Patil
//**************************************************************************************************

#include <iostream>	//endl, fixed, left, right
#include <cstdlib>	//for exit() function
#include <iomanip>	//setprecision(), setw()
#include <fstream>	//for ifstream, ofstream
using namespace std;


void ReadHeader(ifstream&);
void PrintHeader(ofstream& outputFile);
void PrintStats(ifstream&, ofstream&);


int main(){

	ifstream fin("stats-season.txt");

	if(!fin){
		cout << "Could not open 'stats-season.txt' for reading. Terminating program." << endl;
		exit(-1);
	}

	ofstream fout("stats-game.txt");
	fout << fixed;

	ReadHeader(fin);
	PrintHeader(fout);
	PrintStats(fin, fout);

	fin.close();
	fout.close();

    return 0;
}

// takes in a file object to write to
//prints the header to the output file
void PrintHeader(ofstream& outputFile){

	outputFile << left << setw(16) << "Name";
	outputFile << right << setw(4) << "GP";
	outputFile << setw(6) << "PPG";
	outputFile << setw(6) << "RPG";
	outputFile << setw(7) << "FG%";
	outputFile << setw(7) << "FT%";
	outputFile << setw(7) << "3P%";
	outputFile << endl;
}

//reads game stats form readFile, calculates game stats and writes to outputFile
void PrintStats(ifstream& readFile, ofstream& outputFile){

    for(int i=0; i<11 ; i++){
		string name;
		readFile >> name;

		//decalre values to read from readFile
		int gp, fgm, fga, ftm, fta, thrm, thra, pts, reb;

		//read values
		readFile >> gp;
		readFile >> fgm;
		readFile >> fga;
		readFile >> ftm;
		readFile >> fta;
		readFile >> thrm;
		readFile >> thra;
		readFile >> pts;
		readFile >> reb;

		// vars to calc PPG, RPG, FG%, FT%, 3P%
		//Calculate game stats
		double ppg = pts / static_cast<double>(gp);
		double rpg = reb / static_cast<double>(gp);
		double fgp = fgm / static_cast<double>(fga);
		double ftp = ftm / static_cast<double>(fta);
		double threep = thrm / static_cast<double>(thra);

		//write values to outputFile
		outputFile << left << setw(16) << name;
		outputFile << right << setprecision(1) << setw(4) << gp;
		outputFile << setw(6) << ppg;
		outputFile << setw(6) << rpg;
		outputFile << setprecision(3) << setw(7) << fgp;
		outputFile << setw(7) << ftp;
		outputFile << setw(7) << threep;
		outputFile << endl;
	}
}

void ReadHeader(ifstream& readFile){
    string header;
	getline(readFile, header);
}
