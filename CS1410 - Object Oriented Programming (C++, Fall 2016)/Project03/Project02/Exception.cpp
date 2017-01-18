// Author: Maxwell Nelson
// Assignment: Project 03
// Instructor: David Wagstaff
// Class: CS 1410 section 01
// Date Written: 9/23/2016
// Description: implementation file for exception
//
//I declare that the following source code was written solely by me.
//I understand that copying any source code, in whole or in part, 
// constitutes cheating, and that I will receive a zero on this project
// if I am found in violation of this policy. 
#include "Exception.h";
using namespace std;

Exception::Exception()
{
	//default constructor
}

Exception::Exception(const string& error)
{
	//sets the error message
	message = error;
}

string Exception::getMessage() const
{
	//returns the error
	return message;
}

