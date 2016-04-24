#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Section{
    private:
        int size;
        int startPage;
        int endPage;
        string name;
    public:
        void buildSection(string pName, int pStartPage, int pEndPage){
            name = pName;
            startPage = pStartPage;
            endPage = pEndPage;
            if(pStartPage > pEndPage){size = pStartPage - pEndPage;}
            else if(pEndPage > pStartPage){size = pEndPage - pStartPage;}
            else{size = 0;}

        }
        string getName(){
            return name;
        }
        int getSize(){
            return size;
        }
        int getStartPage(){
            return startPage;
        }
        int getEndPage(){
            return endPage;
        }
        void summary(){
            cout << "\n-------------\nname: " << name << "\nsize: " << size << "\nstartPage: " << startPage << "\nendPage: " << endPage << "\n-------------" ;
        }
        void graph(){
            cout << "\nSection " << fixed << setw(15) << right << name << ": ";
            for(int i = 0; i < getSize(); i++){
                cout << "*";
            }
        }
};

// class Menu{
//     private:
//         int options = 1;
//     public:
//         void getOptions(){
//             return options;
//         }
// }

void getNewSectionData(string& pName, int& pStartPage, int& pEndPage){
    cout << "Add new section info:\nName: ";
    cin >> pName;
    cout << "Start page: ";
    cin >> pStartPage;
    cout << "End page: ";
    cin >> pEndPage;
}

void readingSectionAnalysis(){
    string addSection = "y", name;
    int startPage, endPage, sectionCount = 0, maxSectionCount = 10;
    Section readingSections[maxSectionCount];
    cout << "===Reading Section Analysis===\n\n";

    while(addSection == "y"){
        getNewSectionData(name, startPage, endPage);
        readingSections[sectionCount].buildSection(name, startPage, endPage);
        sectionCount++;
        cout << (sectionCount) << " sections made so far...\n" << "Add new section? (type \"y\" for yes): ";
        cin >> addSection;
    }
    for(int i = 0; i < sectionCount; i++){
        readingSections[i].summary();
    }
    cout << endl;
    for(int i = 0; i < sectionCount; i++){
        readingSections[i].graph();
    }
    cout << "\n\n";
}

int main(){
    int programChoice;
    cout << "===Workflow Analysis Tool===\n\n";
    // cout << (sizeof(programChoice)/sizeof(*programChoice));
    cout << "Choose what sub-program to run...\n0. Reading Section Analysis\nYour choice: ";
    cin >> programChoice;
    switch(programChoice){
        case 0:
            readingSectionAnalysis();
            break;
        default:
            cout << "Invalid choice!!!\n\n";
            break;
    }
    return 0;
}
