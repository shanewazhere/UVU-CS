
// Author: Maxwell Nelson
// Assignment: lab 05
// Instructor: David Wagstaff
// Class: CS 1410 section 01
// Date Written: 9/22/2016
// Description: header file for myException class
//
//I declare that the following source code was written solely by me.
//I understand that copying any source code, in whole or in part, 
// constitutes cheating, and that I will receive a zero on this project
// if I am found in violation of this policy. 
#pragma once
#include <string>;
using namespace std;

//You will have to create an exception class capable of storing informaton about what the
//error was, and the value passed to the function. 

// Class prologue
class myException
{
private:
	string value;
	string errorType;

public:
	// Default Constructor
	// Purpose: default
	// Parameters: none
	// Returns: none
	myException();

	// Parameterized Constructor
	// Purpose: Initializes the myException
	// Parameters: two strings
	// Returns: none
	myException(string, string);

};
