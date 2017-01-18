
// Author: Maxwell Nelson
// Assignment: lab 03
// Instructor: David Wagstaff
// Class: CS 1410 section 01
// Date Written: 9/7/2016
// Description: Contains functions to return the height area and width
// --------------------------- #include "NiceRectangle.h" 

//I declare that the following source code was written solely by me.
//I understand that copying any source code, in whole or in part, 
// constitutes cheating, and that I will receive a zero on this project
// if I am found in violation of this policy. 
#include "NiceRectangle.h"

NiceRectangle::NiceRectangle()
{
	height = 0;
	width = 0;
	area = 0;
};

NiceRectangle::NiceRectangle(int h, int w)
{
	height = h;
	width = w;
	area = height * width;
}

int NiceRectangle::getHeight() const
{
	return height;
}

int NiceRectangle::getWidth() const
{
	return width;
}

int NiceRectangle::getArea() const
{
	return area;
}
