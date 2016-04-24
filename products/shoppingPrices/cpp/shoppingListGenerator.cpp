#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include "Shlist.hpp"
using namespace std;

int getCommaPos(string line);
int countOptions(ifstream& indexFile);
void constructPriceItemArray(ifstream& indexFile, string items[], double prices[]);
int searchArrItems(string needle, string hayStack[], int hayStackSize);
void addNewItem(Shlist& myShList,string response);

int main(){
    ifstream indexFile("index");
    if(!indexFile){
        cout << "unable to open index file\n";
        exit(-1);
    }

    int optionsCount = countOptions(indexFile);
    string items[optionsCount];
    double prices[optionsCount];
    //reset fstream flags and reading position to start reading the file from beginning
    indexFile.clear();
    indexFile.seekg(0, indexFile.beg);
    constructPriceItemArray(indexFile, items, prices);
    indexFile.close();

    Shlist myShList;
    cout << "\nWhat are you thinking about buying? Item followed by quantity\n\n";
    string response = "";
    cin >> response;
    while(response != "exit"){
        int itemPos = searchArrItems(response, items, optionsCount);
        if(itemPos > -1){
            int quantity;
            cin >> quantity;
            myShList.makeRow(items[itemPos], quantity, prices[itemPos] * quantity);
        }else{
            cout << "Item not found... Add new item? (yes/no)\n";
            string confirmation;
            cin >> confirmation;
            if(confirmation == "yes") addNewItem(myShList, response);
        }
        cin >> response;
    }
    myShList.closeFile();

    cout << "\nTerminating...\n";
	return 0;
}


void addNewItem(Shlist& myShList,string response){
    double unitPrice;
    int quantity;
    cout << "What's the unit price? ";
    cin >> unitPrice;
    cout << "How many? ";
    cin >> quantity;
    ofstream indexFile("index", ios::app);
    indexFile << response << "," << unitPrice << endl;
    indexFile.close();
    myShList.makeRow(response, quantity, unitPrice * quantity);
}


int getCommaPos(string line){
    for(int i = 0; i < line.size(); i++){
        if(line[i] == ',') return i;
    }
    return 0;
}


int countOptions(ifstream& indexFile){
    int i = 0;
    while(!indexFile.eof()){
        string line;
        getline(indexFile, line);
        if(line.size()){
            i++;
        }
    }
    return i;
}


void constructPriceItemArray(ifstream& indexFile, string items[], double prices[]){
    int i = 0;
    while(!indexFile.eof()){
        string line;
        getline(indexFile, line);
        if(line.size()){
            items[i] = line.substr(0, getCommaPos(line));
            line = line.substr(getCommaPos(line) + 1, line.length());
            prices[i] = strtod(line.c_str(), NULL);
            i++;
        }
    }
}


int searchArrItems(string needle, string hayStack[], int hayStackSize){
    for(int i = 0; i < hayStackSize; i++){
        if(needle == hayStack[i]){
            return i;
        }else{
        }
    }
    return -1;
}
