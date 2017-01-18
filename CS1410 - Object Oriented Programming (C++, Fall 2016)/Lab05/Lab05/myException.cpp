
// Author: Maxwell Nelson
// Assignment: lab 06
// Instructor: David Wagstaff
// Class: CS 1410 section 01
// Date Written: 9/22/2016
// Description: class that stores value and exception type if an exception is run
// ---------------------------

//I declare that the following source code was written solely by me.
//I understand that copying any source code, in whole or in part, 
// constitutes cheating, and that I will receive a zero on this project
// if I am found in violation of this policy. 


#include "myException.h";
#include <string>;


myException::myException()
{
	value = "";
	errorType = "";
};

myException::myException(string v, string eT)
{
	value = v;
	errorType = eT;
}