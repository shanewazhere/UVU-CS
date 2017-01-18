// CS 1410 Programming Project #2
// Copyright 2014, Utah Valley University
//Author: Roger deBry
// Date last modified: October 2015
// Header file for main - constants and function prologues
// =================================================
// Author: Maxwell Nelson
// Assignment: Project 05
// Instructor: David Wagstaff
// Class: CS 1410 section 01
// Date Written: 9/7/2016 Date Modified: 10/24/2016
// Description: driver header file for project 05
//
//I declare that the following source code was written solely by me.
//I understand that copying any source code, in whole or in part, 
// constitutes cheating, and that I will receive a zero on this project
// if I am found in violation of this policy. 
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Book.h" 
#include "AudioBook.h"
#include "DigitalBook.h"
// the file name for your classes may be different
using namespace std;

// The displayBooks function
// Purpose: Display all of the data about a book
// Parameters: A vector of Book objects
// Returns: none
void displayBooks(const vector<Book>&);

// The createTestFile function
// Purpose: Create a test file using the book data
// Parameters: none
// Returns: none
void createTestFile();

// The readTestFile function
// Purpose: Read the test file and display the results
// Parameters: none
// Returns: none
void readTestFile( );

// The openFile function
// Purpose: Open a file for reading
// Parameters: an istream object and a file name
// Returns: none
// Throws a FileException if the file cannot be opened
void openFile(ifstream&, const string&);