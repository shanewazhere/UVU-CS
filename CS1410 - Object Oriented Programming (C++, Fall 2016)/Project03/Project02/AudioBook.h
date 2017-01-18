// Author: Maxwell Nelson
// Assignment: Project 05
// Instructor: David Wagstaff
// Class: CS 1410 section 01
// Date Written: 10/23/2016
// Description: Header for Audio Book
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
// This class models an AudioBook
class AudioBook : public Book
{
private:
	int length;

public:
	// Default Constructor
	// Purpose: default
	// Parameters: none
	// Returns: none
	AudioBook(); 

	// Parameterized Constructor
	// Purpose: Initializes the length
	// Parameters: length int
	// Returns: none
	AudioBook(Author*, string, int, double, int);

	// setLength 
	// Purpose: sets the length
	// Parameters: none
	// Returns: none
	void setLength(int);

	// getLength 
	// Purpose: returns the length
	// Parameters: none
	// Returns: returns the length int
	int getLength() const;

	// read data 
	// Purpose: reads the length in, calls parent class to read parent data
	// Parameters: none
	// Returns:none
	void readData(ifstream&);

	// write data
	// Purpose: writes the length out, calls parent class to write parent data
	// Parameters: none
	// Returns:none
	void writeData(ofstream&);

};
