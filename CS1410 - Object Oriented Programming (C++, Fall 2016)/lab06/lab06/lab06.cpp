// Author: Max Nelson
// Assignment: Lab06
// Instructor: David Wagstaff
// Class: CS1410
// Date Written: Sep 29, 2016
// Description: reverses a c-string
// -----------
//I declare that the following source code was written solely by me.
//I understand that copying any source code, in whole or in part, 
// constitutes cheating, and that I will receive a zero on this project
// if I am found in violation of this policy.

// Main class.
#include <string>;
#include <array>;
#include <iostream>;

using namespace std;

// Purpose: reverses c-string using pointers
// Parameters: pointer to a c-string
// Returns: none
// Pre-conditions: none
// Post-conditions: none
void reverser(char *myString);

int main()
{
	// declare a c-string to reverse
	char myString[] = "Hello world!";

	// call the reverser function
	reverser(myString);

	// output the result
	cout << myString << endl;

	system("PAUSE");
	return 0;
}

// Purpose: reverses c-string using pointers
// Parameters: pointer to a c-string
// Returns: none
// Pre-conditions: none
// Post-conditions: none
void reverser(char *myString)
{
	//get that length boi
	int length = strlen(myString);

	for (int i = 0; i != length/2; ++i) {
		char *first = myString + i;    
		char *second = myString + length - i - 1;	
		//pointers for days son
		const char TEMP = *first;
		*first = *second;
		*second = TEMP;
	}
}

//1.Using a loop, determine the size of the string by counting characters until you encounter the null terminating character at the end of the string.
//2.Establish a pointer that points to the beginning character of the string.
//3.Establish a pointer that points to the last character in the string, this is the character just before the null terminating character.
//4.Using the pointers, swap the first character in the string and the last character in the string.
//5.Move the pointers so that the first pointer points to the 2nd character in the string and the second pointer points to the next to last character in the string.Swap these two characters.
//6.Repeat this process until all of the characters have been swapped.The string should now be reversed.Add this driver code to your program :
//those instructions tho boi