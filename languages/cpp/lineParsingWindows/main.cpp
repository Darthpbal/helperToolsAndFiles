/*
This file is an example of line parsing. 
The substring portions are there because of the different
end of line symbols used for windows vs linux
*/




#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
using namespace std;

int main(){
    cout << "Hello World\n";

    ifstream inputFile("fileToParse");
    if(!inputFile){
        cout << "unable to open file" << endl;
        exit(-1);
    }else cout << "opened file\n";

    string motherFuckingCunt, line;
    while(!inputFile.eof()) {
        getline(inputFile, motherFuckingCunt);
        line += motherFuckingCunt.substr(0, motherFuckingCunt.size() - 1);
        line += ",";
        getline(inputFile, motherFuckingCunt);
        line += motherFuckingCunt.substr(0, motherFuckingCunt.size() - 1);
        line += ",";
        getline(inputFile, motherFuckingCunt);
        line += motherFuckingCunt.substr(0, motherFuckingCunt.size() - 1);
        cout << line + "\n";
        line.clear();
    }

    inputFile.close();
    return 0;
}


/*
original file to parse
Hello World
Hello WorldHello World
Hello WorldHello WorldHello World
Hello WorldHello WorldHello WorldHello World
Hello WorldHello WorldHello WorldHello WorldHello World
Hello WorldHello WorldHello WorldHello WorldHello WorldHello World
Hello WorldHello WorldHello WorldHello WorldHello WorldHello WorldHello World
Hello WorldHello WorldHello WorldHello WorldHello WorldHello WorldHello WorldHello World
Hello WorldHello WorldHello WorldHello WorldHello WorldHello WorldHello WorldHello WorldHello World
Hello WorldHello WorldHello WorldHello WorldHello WorldHello WorldHello WorldHello WorldHello World
Hello WorldHello WorldHello WorldHello WorldHello WorldHello WorldHello WorldHello World
Hello WorldHello WorldHello WorldHello WorldHello WorldHello WorldHello World
Hello WorldHello WorldHello WorldHello WorldHello WorldHello World
Hello WorldHello WorldHello WorldHello WorldHello World
Hello WorldHello WorldHello WorldHello World
Hello WorldHello WorldHello World
Hello WorldHello World
Hello World
*/

