// Author: Maxwell Nelson
// Assignment: Project 05
// Instructor: David Wagstaff
// Class: CS 1410 section 01
// Date Written: 10/23/2016
// Description: Header for Digital Book
//
//I declare that the following source code was written solely by me.
//I understand that copying any source code, in whole or in part, 
// constitutes cheating, and that I will receive a zero on this project
// if I am found in violation of this policy. 
#pragma once

#include "Book.h"
#include <string>
#include <fstream>
using namespace std;

// Class prologue
// This class models a Digital Book
class DigitalBook : public Book
{
private:
	string format;

public:
	// Default Constructor
	// Purpose: default
	// Parameters: none
	// Returns: none
	DigitalBook();

	// Parameterized Constructor
	// Purpose: Initializes the format
	// Parameters: length int
	// Returns: none
	DigitalBook(Author*, string, int, double, string);

	// setFormat 
	// Purpose: sets the length
	// Parameters: none
	// Returns: none
	void setFormat(string);

	// getFormat 
	// Purpose: returns the format
	// Parameters: none
	// Returns: returns the format string
	string getFormat() const;

	// read data 
	// Purpose: reads the format in, calls parent class to read parent data
	// Parameters: none
	// Returns:none
	void readData(ifstream&);

	// write data
	// Purpose: writes the format out, calls parent class to write parent data
	// Parameters: none
	// Returns:none
	void writeData(ofstream&);

};
