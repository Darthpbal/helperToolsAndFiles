#include <iostream>
using namespace std;

char mapIntToChar(int someInt);

int main(){
  char var;
  while(var != '0'){
    cout << "What's the input for the switch case?\n";
    cin >> var;
    switch (var) {
      case '1':
        cout << "case 1 run\n";
        break;

      case '2':
        cout << "case 2 run\n";
        break;

      case '3':
        cout << "case 3 run\n";
        // break;//hmmm... wonder what happens...

      case '4':
        cout << "case 4 run\n";
        break;

      case '5':
        cout << "case 5 run\n";
        break;

      case '6':
        cout << "case 6 run\n";
        // break;//hmmm... wonder what happens...

      default:
        cout << "default run\n";
    }
  }
  return 0;
}


// char mapIntToChar(int someInt){
//   switch (someInt) {
//     case 1:
//       break;
//     default:
//       cout << "out of maptoInt range!!!\n";
//       return 0;
//   }
// }
