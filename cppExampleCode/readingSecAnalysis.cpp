#include <iostream>
#include <iomanip>

using namespace std;

const int GRAPH_SIZE = 20;
const int RANGE = 100;

void graph2DArray(char p2DArray[GRAPH_SIZE][GRAPH_SIZE],int);

int main(){

    // ============empty data array contruction========================
    char someInts[GRAPH_SIZE][GRAPH_SIZE];
    for(int r = 0;r < GRAPH_SIZE; r++){
        for(int c = 0;c < GRAPH_SIZE; c++){
            someInts[r][c] = ' ';
        }
    }
    // ============empty data array contruction========================
    bool countUp = true;
    int disCount = 0;
    for(int i = 0;i < GRAPH_SIZE;i++){
        someInts[disCount][i] = '*';
        if(disCount < GRAPH_SIZE) disCount *= disCount;
        else break;
        // disCount = (countUp)? disCount + 2:disCount - 2;
        // if(disCount == 10 || disCount == 0) countUp = (countUp)? false: true;
    }

    graph2DArray(someInts, GRAPH_SIZE);
    return 0;
}

void graph2DArray(char p2DArray[GRAPH_SIZE][GRAPH_SIZE], int pArraySize){
    const int STEP_SIZE = RANGE / pArraySize;
    const int MARGIN = 8;
    cout << endl << endl;
    //=============Top frame construction=====================================
    int count = RANGE;
    cout << setw(MARGIN + 1) << right;
    for(int i = 0;i < pArraySize + 1; i++){
        cout << "-";
        if((i + 1) != pArraySize) cout << "-";
    }
    cout << endl;
    //=============Top frame construction=====================================
    for(int r = pArraySize - 1;r >= 0; r--){
        cout << setw(MARGIN) << right << count << "|";// left side frame construction with values
        //current row is known at this point as well as row value along y axis
        // ===========Data fill in=====================================
        for(int c = 0; c < pArraySize; c++){
            // cout << "*";//if you wish to highlight this position, star here, empty should be space
            cout << p2DArray[r][c];
            if((c + 1) != pArraySize) cout << " ";
        }
        // ===========Data fill in=====================================
        cout << "|" << endl;//right side frame construction
        count -= STEP_SIZE;
    }
    // =============Bottom frame construction=====================================
    cout << setw(MARGIN + 1) << right;
    for(int i = 0;i < pArraySize + 1; i++){
        cout << "-";
        if((i + 1) != pArraySize) cout << "-";
    }
    cout << endl << setw(MARGIN + 1);
    for(int i = 0; i < pArraySize; i++){
        cout << " ";
        if((i) != pArraySize) cout << "|";
    }
    // =============Bottom frame construction=====================================
    cout << endl << endl;
}
