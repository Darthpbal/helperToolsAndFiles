#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>// for the exit function
#include <iomanip>// for setw
using namespace std;

int getCommaPos(string line);
void printHeader(ofstream& outputFile);

int main(){
    //Open input/output files
    ifstream indexFile("index");
    ofstream outputFile("options");
    if(!indexFile){
        cout << "unable to open the index file\n";
        exit(-1);
    }
    if(!outputFile){
        cout << "unable to open the output file\n";
        exit(-1);
    }

    //print the options header
    printHeader(outputFile);
    while(!indexFile.eof()){
        //extract line from source file
        string line;
        getline(indexFile, line);
        //if the line isn't empty, like the common empty line @ end of file
        if(line.size()){
            //print line option label
            outputFile << left << setw(15) << line.substr(0, getCommaPos(line));
            //print option unit price
            outputFile << right << setw(7) << line.substr(getCommaPos(line) + 1, line.length()) << endl;
        }
    }

    //cleanup files and terminal
	indexFile.close();
    outputFile.close();
	cout << endl;
	return 0;
}

int getCommaPos(string line){
    for(int i = 0; i < line.size(); i++){
        if(line[i] == ',') return i;
    }
    return 0;
}

void printHeader(ofstream& outputFile){
    outputFile << left << setw(15) << "Line name";
    outputFile << right << setw(7) << "Price" << endl;
    outputFile << "======================\n";
}
