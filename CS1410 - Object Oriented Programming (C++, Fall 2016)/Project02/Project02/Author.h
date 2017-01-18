// Author: Maxwell Nelson
// Assignment: Project 01
// Instructor: David Wagstaff
// Class: CS 1410 section 01
// Date Written: 9/7/2016
// Description: Header for author class
//
//I declare that the following source code was written solely by me.
//I understand that copying any source code, in whole or in part, 
// constitutes cheating, and that I will receive a zero on this project
// if I am found in violation of this policy. 
#pragma once
#include <string>
using namespace std;

// Class prologue
// This class models an author
class Author
{
private:
	string name;
	string address;
public:
	// Default Constructor
	// Purpose: default
	// Parameters: none
	// Returns: none
	Author();

	// Parameterized Constructor
	// Purpose: Initializes the name and address
	// Parameters: name string and address string
	// Returns: none
	Author(string, string);

	// setName 
	// Purpose: sets the name string
	// Parameters: none
	// Returns: none
	void setName(string);

	// getName 
	// Purpose: returns the name
	// Parameters: none
	// Returns: returns the name string
	string getName() const;

	// setAddress 
	// Purpose: sets the address string
	// Parameters: none
	// Returns: none
	void setAddress(string);

	// getAddress 
	// Purpose: returns the address
	// Parameters: none
	// Returns: returns the address string
	string getAddress() const;

};
