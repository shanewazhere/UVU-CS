// Author: Maxwell Nelson
// Assignment: Project 01
// Instructor: David Wagstaff
// Class: CS 1410 section 01
// Date Written: 9/7/2016
// Description: Header for author class
//
//I declare that the following source code was written solely by me.
//I understand that copying any source code, in whole or in part, 
// constitutes cheating, and that I will receive a zero on this project
// if I am found in violation of this policy. 
#include "Author.h"
using namespace std;


Author::Author()
{
	name = "";
	address = "";
};

Author::Author(string n, string a)
{
	name = n;
	address = a;
}

void Author::setName(string newName)
{
	name = newName;
}

string Author::getName() const
{
	return name;
}

void Author::setAddress(string newAddress)
{
	address = newAddress;
}

string Author::getAddress() const
{
	return address;
}
