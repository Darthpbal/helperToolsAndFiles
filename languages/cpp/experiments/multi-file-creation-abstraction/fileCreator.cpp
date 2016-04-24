#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
using namespace std;

void createTextFiles(string file1, string file2, string file3, ofstream& sourceFile1, ofstream& sourceFile2, ofstream& sourceFile3);
void printToTextFiles(string file1, string file2, string file3, ofstream& sourceFile1, ofstream& sourceFile2, ofstream& sourceFile3);
void closeTextFiles(ofstream& sourceFile1, ofstream& sourceFile2, ofstream& sourceFile3);

int main(){
    string  file1 = "foo", file2 = "bar", file3 = "bash";
	ofstream sourceFile1, sourceFile2, sourceFile3;
	createTextFiles(file1, file2, file3, sourceFile1, sourceFile2, sourceFile3);
	printToTextFiles("file1", "file2", "file3", sourceFile1, sourceFile2, sourceFile3);
	closeTextFiles(sourceFile1, sourceFile2, sourceFile3);
	return 0;
}

void createTextFiles(string file1, string file2, string file3, ofstream& sourceFile1, ofstream& sourceFile2, ofstream& sourceFile3){
	sourceFile1.open(file1.c_str());
	sourceFile2.open(file2.c_str());
	sourceFile3.open(file3.c_str());
	if(!sourceFile1 || !sourceFile2 || !sourceFile3){
        cout << "unable to open one of the files\n";
        exit(-1);
    }
}

void printToTextFiles(string file1, string file2, string file3, ofstream& sourceFile1, ofstream& sourceFile2, ofstream& sourceFile3){
	sourceFile1 << file1 << endl;
	sourceFile2 << file2 << endl;
	sourceFile3 << file3 << endl;
}

void closeTextFiles(ofstream& sourceFile1, ofstream& sourceFile2, ofstream& sourceFile3){
	sourceFile1.close();
	sourceFile2.close();
	sourceFile3.close();
}
