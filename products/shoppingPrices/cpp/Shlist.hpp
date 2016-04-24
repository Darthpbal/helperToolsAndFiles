#ifndef SHLIST_HPP
#define SHLIST_HPP

#include <string>             // For string class
#include <fstream>

using namespace std;

class Shlist{
public:
    Shlist();
    void makeRow(string name, int quantity, double lineTot);
    void openFile();
    void closeFile();
    void printSubtot();
    void finishTable();
private:
    ofstream outputFile;
    string header;
    string topOfFile;
    string endOfFile;
    double subTotal;
};

#endif // SHLIST_HPP
