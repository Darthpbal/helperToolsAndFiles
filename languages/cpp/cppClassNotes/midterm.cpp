#include <iostream>
#include <string>

using namespace std;

void chapterTwo();
void chapterThree();
void chapterFour();

int main(){

    chapterTwo();
    chapterThree();
    chapterFour();

    return 1;
}


void chapterTwo(){

    int a = 1, c = 2;
    cout << "Start Ch 2\n\n" << "a = " << a << "\nc = " << c << endl;
    bool b = (a < 5) && (c > 2);
    cout << "b = " << b << endl;
    bool d = true;
    cout << "d = " << d << "\n\nEnd Ch 2\n\n";
}

void chapterThree(){
    cout << "Start Ch 3\n\n";

    char a = 'a';
    cout << "a = " << a << "\nGive me a character...";
    char b;
    cin >> b;
    cout << "\nYou entered " << b << "\nNow give me a string...";
    string str;
    cin >> str;
    cout << "\nYou entered " << str << endl;

    cout << "\nEnd Ch 3\n\n";
}

void chapterFour(){
    cout << "Start Ch 4\n\n";

    int a = 1,b = 2,c = 2,d = 3;

    if( b > a){
        cout << "passed 1 of 6\n";
    }

    if(a < b){
        cout << "passed 2 of 6\n";
    }

    if( c >= a && c>= b){
        cout << "passed 3 of 6\n";
    }

    if( b <= d && b <= c ){
        cout << "passed 4 of 6\n";
    }

    if( b == c ){
        cout << "passed 5 of 6\n";
    }

    if( a != d){
        cout << "passed 6 of 6\n";
    }


    cout << "\nEnd Ch 4\n\n";
}
