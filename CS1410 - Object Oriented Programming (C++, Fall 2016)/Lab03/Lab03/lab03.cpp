
// Author: Maxwell Nelson
// Assignment: lab 03
// Instructor: David Wagstaff
// Class: CS 1410 section 01
// Date Written: 9/7/2016
// Description: This file creates a new NiceRectangle object and returns the dimenssions and area.
// --------------------------- #include "NiceRectangle.h" 

//I declare that the following source code was written solely by me.
//I understand that copying any source code, in whole or in part, 
// constitutes cheating, and that I will receive a zero on this project
// if I am found in violation of this policy. 

using namespace std;
#include <iostream>
#include "NiceRectangle.h"

int main()
{
	const int HEIGHT = 4;
	const int WIDTH = 7;

	NiceRectangle rectangle(HEIGHT, WIDTH);
	
	int rectangleHeight = rectangle.getHeight();
	int rectangleWidth = rectangle.getWidth();
	int rectangleArea = rectangle.getArea();

	cout << "The size of our rectangle is " << rectangleHeight << " by " << rectangleWidth << endl;
	cout << "The area of our rectangle is " << rectangleArea << endl;

	system("PAUSE");
	
	return 0;
}