#include <iostream>
using namespace std;

int fact(int input){
  return (input < 1)? 1: input * fact(input - 1);
}

int main(){
    cout << "Hello World\n";
    int someNum;
    while(someNum != -1){
      cout << "num=";
      cin >> someNum;
      cout << fact(someNum) << endl;
    }
  return 0;
}
