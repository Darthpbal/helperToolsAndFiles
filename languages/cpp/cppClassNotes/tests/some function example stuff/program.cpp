#include <iostream>

using namespace std;

// this line only declares "someFunction" but without a body. 
// This is to make sure that "someFunction" can be seen by main()
void someFunction(/*int input1, double input2*/);

// Here, functionName is being decalred along with it's body.
// function names area also commonly called a prototype
void functionName(/*bool input1, float input2*/){ 
	cout << endl << "Hello from functionName!!!" << endl;
}



//////////////////////   main function  ////////////////////////////////////
int main(){
	functionName(); // this line calls the function called "functionName"
	someFunction();
	return 0;
}





void someFunction(){
	cout << endl << "Hello from someFunction!!!" << endl << endl;
}


/*
Some example variables with their types

literal				type
___________________________________

"some words"		string

1, 2, 4, 7			integers

1.0, 2.00, 3.14 	float/double

only 1 or 0         bool	(boolean value)

'A'                 char	(character)

*/
