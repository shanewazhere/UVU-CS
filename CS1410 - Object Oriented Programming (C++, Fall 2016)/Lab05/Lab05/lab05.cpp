
// Author: Maxwell Nelson
// Assignment: lab 05
// Instructor: David Wagstaff
// Class: CS 1410 section 01
// Date Written: 9/22/2016
// Description: squares a number. uses exceptions to handle input
// ---------------------------

//I declare that the following source code was written solely by me.
//I understand that copying any source code, in whole or in part, 
// constitutes cheating, and that I will receive a zero on this project
// if I am found in violation of this policy. 

#include <iostream>;
#include <array>;
#include <fstream>;
#include <string>;
using namespace std;


/*1.Declare an integer value to store the user's input. 
2.Prompt the user to enter a positive, non-zero integer value. 
3.Pass this value to a function named calculateSquare. This function will only work on positive, non-zero values. 
Since the function has no idea where the data came from it has no way to recover if the parameter 
it receives is invalid. If the value passed is zero or negative the function will throw an exception that (1)
indicates what the error was, and (2) what the value of the offending parameter is.
If the parameter is okay, it calculates and returns the square of the number. 
*/

#include "myException.h";
void calculateSquare(int userInput);

int main() {
	int userInput;

	cout << "Please enter a positive, non-zero integer value: ";
	cin >> userInput;
	

	calculateSquare(userInput);

	system("PAUSE");
	return 0;
}

void calculateSquare(int userInput)
{
	try
	{
		if (userInput <= 0)
		{
			//negative number throw error message
			//store the datas in an exception object
			myException exception(to_string(userInput), "int");
			throw "You did not enter a non-zero positive integer";
		}
		cout << "The square of " << userInput << " is " << userInput * userInput << endl;
	}
	
	catch (const char* exc) // catch exceptions of type const char*
	{
		cerr << "Error: " << exc << endl;
	}

}

