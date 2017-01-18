// CS 1410 Programming Project #2
// Copyright 2014, Utah Valley University
//Author: Roger deBry
// Date last modified: October 2015
// Header file for main - constants and function prologues
// =================================================
//
// Author: Maxwell Nelson
// Assignment: Project 02
// Instructor: David Wagstaff
// Class: CS 1410 section 01
// Date Written: 9/7/2016
// Description: driver header file
//
//I declare that the following source code was written solely by me.
//I understand that copying any source code, in whole or in part, 
// constitutes cheating, and that I will receive a zero on this project
// if I am found in violation of this policy.
#include <iostream>
#include <string>
#include <vector>
#include "Book.h"
using namespace std;

// The displayBooks function
// Purpose: Display all of the data about a book
// Parameters: A vector of Book objects
// Returns: none
void displayBooks(const vector<Book>&);