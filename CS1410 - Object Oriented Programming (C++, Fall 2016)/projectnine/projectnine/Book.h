// Author: Maxwell Nelson
// Assignment: Project 09
// Instructor: David Wagstaff
// Class: CS 1410 section 01
// Date Written: 12/8/2016
// Description: Book header file.
//
//I declare that the following source code was written solely by me.
//I understand that copying any source code, in whole or in part, 
// constitutes cheating, and that I will receive a zero on this project
// if I am found in violation of this policy. 
#pragma once
#include <string> 
using namespace std;

class Book
{
private:                              
	string title;
	string author;
	double price;
public:
	// Purpose: default constructor
	// Parameters:none
	// Returns: none
	// Pre-conditions: none
	Book();

	// Purpose: paramatarized constructor
	// Parameters:string title, string author, double price
	// Returns: none
	// Pre-conditions: none
	Book(string t, string a, double p);

	// Purpose: returns book title
	// Parameters: none
	// Returns: none
	// Pre-conditions: none
	string getTitle() const;

	// Purpose: returns book author
	// Parameters: none
	// Returns: none
	// Pre-conditions: none
	string getAuthor() const;

	// Purpose: returns book price
	// Parameters: none
	// Returns: none
	// Pre-conditions: none
	double getPrice() const;
};

