// Author: Maxwell Nelson
// Assignment: Project 03
// Instructor: David Wagstaff
// Class: CS 1410 section 01
// Date Written: 9/7/2016 Date Modified: 9/26/2016
// Description: Header for book class
//
//I declare that the following source code was written solely by me.
//I understand that copying any source code, in whole or in part, 
// constitutes cheating, and that I will receive a zero on this project
// if I am found in violation of this policy. 
#pragma once
using namespace std;
#include "Author.h"
#include <fstream>
// Class prologue
// This class models a book
class Book
{
private:
	Author author;
	string title;
	int pages;
	double price;
public:
	// Default Constructor
	// Purpose: default
	// Parameters: none
	// Returns: none
	Book();

	// Parameterized Constructor
	// Purpose: Initializes the author, title, pages, and price of the book
	// Parameters: author object, string, int, and double
	// Returns: none
	Book(Author*, string, int, double);

//
	// setAuthor 
	// Purpose: sets the author Author
	// Parameters: none
	// Returns: none
	void setAuthor(Author);

	// getAuthor 
	// Purpose: returns the author
	// Parameters: none
	// Returns: returns the author Author 
	Author getAuthor() const;
//
	// setTitle 
	// Purpose: sets the title string
	// Parameters: none
	// Returns: none
	void setTitle(string);

	// getTitle 
	// Purpose: returns the title
	// Parameters: none
	// Returns: returns the title string
	string getTitle() const;
//
	// setPages 
	// Purpose: sets the pages int
	// Parameters: none
	// Returns: none
	void setPages(int);

	// getPages 
	// Purpose: returns the address
	// Parameters: none
	// Returns: returns the pages int
	int getPages() const;
//
	// setPrice 
	// Purpose: sets the price double
	// Parameters: none
	// Returns: none
	void setPrice(double);

	// getPrice 
	// Purpose: returns the price
	// Parameters: none
	// Returns: returns the price double
	double getPrice() const;
//
	// read data 
	// Purpose: reads name and address from file
	// Parameters: none
	// Returns:none
	virtual void readData(ifstream&);

	// read data 
	// Purpose: writes name and address to file
	// Parameters: none
	// Returns:none
	virtual void writeData(ofstream&);
};
