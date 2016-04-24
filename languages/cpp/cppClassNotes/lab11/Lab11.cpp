//**************************************************************************************************************
// FILE:        Lab11.cpp
//
// DESCRIPTION: Implements a simple substitution cipher to encrypt secret messages.
//
// AUTHORS:     Paul Ronquillo            (pronquil@asu.edu)
//
// COURSE:      CSE100 Principles of Programming with C++, Fall 2015
//
// LAB INFO:    Lab 11   Date/Time: 10:30am   TA: Chetan
//**************************************************************************************************************
#include <cstdlib>                   // For exit()
#include <fstream>                   // For ifstream, ofstream
#include <iostream>                   // For cout, endl

using namespace std;

// Define an int constant named MAX_MSG_LEN which is the maximum number of characters in the plaintext message.
// Initialize MAX_MSG_LEN to 50.
const int MAX_MSG_LEN = 50;

//--------------------------------------------------------------------------------------------------------------
// FUNCTION: error()
//
// DESCRIPTION
// This function is called when an non-recoverable error occurs. We display the message in p_err_msg on the out-
// put window and terminate the program with an exit code of -1.
//
// PSEUDOCODE
// Function error(In: p_err_msg : string) Returns Nothing
//     Send to cout p_err_msg followed by ". Terminating..." followed by endl
//     Call exit(-1)
// End Function
//--------------------------------------------------------------------------------------------------------------
void error(string p_err_msg){
	cout << p_err_msg << ". Terminating..." << endl;
	exit(-1);
}

//--------------------------------------------------------------------------------------------------------------
// FUNCTION: encrypt_plain_char()
//
// DESCRIPTION
// This function has two parameters,
//
// p_plain_char - is a plaintext character that is being encrypted.
// p_index      - is the index of p_plain_char in the plaintext character array.
//
// This function determines what the encrypted character should be and returns it. Because our plaintext charac-
// ter set is limited to uppercase letters, which have ASCII values 65 (A), 66 (B), 67 (C), ... 90 (Z), we can
// subtract 65 from p_plain_char to form the index of the substitution character in either sub_even or sub_odd.
// It may seem weird that we are subtracting an integer from a character variable, but remember that the values
// of character variables are in fact integers, so something like p_plain_char - 'A' is perfectly legal since
// 'A' evaluates to 65.
//
// PSEUDOCODE
// Function encrypt_plain_char(In: p_plain_char : char; In: p_index : int) Returns char
//     Define and initialize sub_even array as discussed in the lab project document
//     Define and initialize sub_odd  array as discussed in the lab project document
//
//     Define int sub_index = p_plain_char - 'A'
//     Define char cipher_char
//
//     If p_index is even Then
//         cipher_char = sub_even[sub_index]
//     Else
//         cipher_char = sub_odd[sub_index]
//     End If
//
//     Return cipher_char
// End Function
//--------------------------------------------------------------------------------------------------------------
char encrypt_plain_char(char p_plain_char, int p_index){
	char sub_even[] = {
		'K','H','J','N','O','L','M','P','D','Q',
		'R','V','W','T','U','Z','A','X','Y','C',
		'F','G','E','I','B','D'
	};
	char sub_odd[] = {
		'P','R','V','X','S','U','B','D','Y','A',
		'E','J','F','I','G','H','K','O','N','M',
		'Q','L','W','T','C','Z',
	};
	int sub_index = p_plain_char - 'A';
	char cipher_char;
	if((p_index % 2) == 0){
		cipher_char = sub_even[sub_index];
	}else{
		cipher_char = sub_odd[sub_index];
	}
	return cipher_char;
}

//--------------------------------------------------------------------------------------------------------------
// FUNCTION: encrypt()
//
// DESCRIPTION
// This function has two parameters,
//
// p_plain  - a C-string (an array of characters with a null character at the end) containing the plaintext
//            message. This is an input parameter.
// p_cipher - a C-string containing the ciphertext. This is an output parameter.

// Given the plaintext message p_plain, this function encrypts it (character by character) and returns the
// ciphertext message in p_cipher.
//
// PSEUDOCODE
// Function encrypt(In: p_plain : char[]; Out: p_cipher : char[]) Returns Nothing
//     Define int index
//
//     -- This is a vary loop where we are varying the value of index so we can access the characters of p_plain
//     -- in order. Note the conditional expression: we continue looping until index has been advanced to point
//     -- to the null character that follows the last valid character of p_plain.
//     For index = 0; p_plain[index] != '\0'; ++index Do
//         Define char plain_char = p_plain[index]
//         Define cipher_char = encrypt_plain_char(plain_char, index)
//         p_cipher[index] = cipher_char
//     End For
//
//     -- Note, we have to place the null character at the end of p_cipher in order to form a valid C-string.
//     p_cipher[index] = '\0'
// End Function
//--------------------------------------------------------------------------------------------------------------
void encrypt(char p_plain[], char (&p_cipher)[MAX_MSG_LEN]){
	for(int i = 0; p_plain[i] != '\0'; ++i){
		char plain_char = p_plain[i];
		char cipher_char = encrypt_plain_char(plain_char, i);
		p_cipher[i] = cipher_char;
		if(p_plain[i + 1] == '\0') p_cipher[i + 1] = '\0';
	}
}

//--------------------------------------------------------------------------------------------------------------
// FUNCTION: main()
//
// DESCRIPTION
// This is where execution begins. We open "plain.txt" for reading and "cipher.txt" for writing. For each plain-
// text message in "plain.txt" we encrypt it to form a ciphertext message, which is written to "cipher.txt".
//
// PSEUDOCODE
// Function main() Returns int
//     Open "plain.txt"  for reading using an ifstream object named fin
//     Open "cipher.txt" for writing using an ofstream object named fout
//
//     If "plain.txt" could not be opened for reading Then
//         Call error("Could not open plain.txt for reading")
//     Else If "cipher.txt" could not be opened for writing Then
//         Call error("Could not open cipher.txt for writing")
//     End If
//
//     Define char arrays plain and cipher, both of size MAX_MSG_LEN
//
//     -- This is an EOF loop. We read strings from fin until fin fails because we have reached the end of file.
//     While fin >> plain Do
//         Call encrypt(plain, cipher)
//         Send cipher to fout followed by endl
//     End While
//
//     Close fin
//     Close fout
// End Function
//--------------------------------------------------------------------------------------------------------------
int main(){
	ifstream fin("plain.txt");
	ofstream fout("cipher.txt");
	if(!fin){ error("Could not open plain.txt for reading");}
	else if(!fout){ error("Could not open cipher.txt for writing");}
	char plain[MAX_MSG_LEN];
	char cipher[MAX_MSG_LEN];
	while(fin >> plain){
		encrypt(plain, cipher);
		fout << cipher << endl;
	}
	fin.close();
	fout.close();
	return 0;
}
