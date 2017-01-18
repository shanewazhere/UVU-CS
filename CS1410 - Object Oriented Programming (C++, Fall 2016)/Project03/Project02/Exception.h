// Author: Maxwell Nelson
// Assignment: Project 03
// Instructor: David Wagstaff
// Class: CS 1410 section 01
// Date Written: 9/23/2016
// Description: header file for exception
//
//I declare that the following source code was written solely by me.
//I understand that copying any source code, in whole or in part, 
// constitutes cheating, and that I will receive a zero on this project
// if I am found in violation of this policy. 
#pragma once

#include <string>
using namespace std;

class Exception
{
private: 
	string message;
	
public:
	// Default Constructor
	// Purpose: default
	// Parameters: none
	// Returns: none
	Exception();

	// Paramatarized Constructor
	// Purpose: sets the error message
	// Parameters: none
	// Returns: none
	Exception(const string& error);

	// getMessage
	// Purpose: returns exception message to tell user
	// Parameters: none
	// Returns: the exception message
	string getMessage() const;
};