// Author: Maxwell Nelson
// Assignment: Project 05f
// Instructor: David Wagstaff
// Class: CS 1410 section 01
// Date Written: 9/7/2016 modified: 9/26/2016 modified 10/24/16
// Description: Header for author class
//
//I declare that the following source code was written solely by me.
//I understand that copying any source code, in whole or in part, 
// constitutes cheating, and that I will receive a zero on this project
// if I am found in violation of this policy. 
#pragma once
#include <string>
#include <fstream>
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

	// read data 
	// Purpose: reads title and price and pages from file. calls read data for author object
	// Parameters: none
	// Returns:none
	void readData(ifstream&);

	// read data 
	// Purpose: writes title price and pages to file. calls write data for author object
	// Parameters: none
	// Returns:none
	void writeData(ofstream&);

};
