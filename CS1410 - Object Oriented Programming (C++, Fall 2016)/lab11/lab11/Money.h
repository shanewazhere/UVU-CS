// Author: Max Nelson
// Assignment: lab11
// Instructor: David Wagstaff
// Class: CS1410 001
// Date Written: 11/2/2016
// Description: Money class
// -----------
//I declare that the following source code was written solely by me.
//I understand that copying any source code, in whole or in part, 
// constitutes cheating, and that I will receive a zero on this project
// if I am found in violation of this policy.

//header for Money class
#pragma once
#include <ostream>
using namespace std;

class Money
{
private:
	int dollars;
	int cents;
public:
	// Purpose: A default constructor, instatiates dollars and cents
	// Parameters: none
	// Returns: none
	// Pre-conditions: none
	// Post-conditions: none
	Money();

	// Purpose: A paramaterized constructor, instatiates dollars and cents
	// Parameters: none
	// Returns: none
	// Pre-conditions: none
	// Post-conditions: none
	Money(int, int);

	// Purpose: returns the objects dollars
	// Parameters: none
	// Returns: dollars
	// Pre-conditions: none
	// Post-conditions: none
	int getDollars() const;

	// Purpose: returns the objects cents
	// Parameters: none
	// Returns: cents
	// Pre-conditions: none
	// Post-conditions: none
	int getCents() const;

	// Purpose: sets the objects dollars
	// Parameters: dollars:int
	// Returns: none
	// Pre-conditions: none
	// Post-conditions: none
	void setDollars(int);

	// Purpose: sets the objects cents
	// Parameters: cents:int
	// Returns: none
	// Pre-conditions: none
	// Post-conditions: none
	void setCents(int);

	// Purpose: overloaded + operator method
	// Parameters: none
	// Returns: none
	// Pre-conditions: none
	// Post-conditions: none
	Money operator+(const Money&);

	// Purpose: overloaded - operator method
	// Parameters: dollars:int
	// Returns: none
	// Pre-conditions: none
	// Post-conditions: none
	Money operator-(const Money&);

	// Purpose: 
	// Parameters: dollars:int
	// Returns: none
	// Pre-conditions: none
	// Post-conditions: none
	friend ostream& operator<<(ostream& out, const Money& moneyObj);
};




