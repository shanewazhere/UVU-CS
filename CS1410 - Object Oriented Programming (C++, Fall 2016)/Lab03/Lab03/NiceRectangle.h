// Author: Maxwell Nelson
// Assignment: lab 03
// Instructor: David Wagstaff
// Class: CS 1410 section 01
// Date Written: 9/7/2016
// Description: header file for NiceRectangle class
//
//I declare that the following source code was written solely by me.
//I understand that copying any source code, in whole or in part, 
// constitutes cheating, and that I will receive a zero on this project
// if I am found in violation of this policy. 
#pragma once

// Class prologue
// This class models a rectangle
class NiceRectangle
{
private:
	int height;
	int width;
	int area;
public:
	// Default Constructor
	// Purpose: default
	// Parameters: none
	// Returns: none
	NiceRectangle();

	// Parameterized Constructor
	// Purpose: Initializes the nice rectangle
	// Parameters: a height and width
	// Returns: none
	NiceRectangle(int, int);

	// getHeight 
	// Purpose: returns the height of the rectangle
	// Parameters: none
	// Returns: an int with the height of the rectangle
	int getHeight() const;

	// getWidth 
	// Purpose: returns the width of the rectangle
	// Parameters: none
	// Returns: an int with the width of the rectangle
	int getWidth() const;

	// getArea 
	// Purpose: returns the area of the rectangle
	// Parameters: none
	// Returns: an int with the area of the rectangle
	int getArea() const;

};
