
// Author: Max Nelson
// Assignment: lab11
// Instructor: David Wagstaff
// Class: CS1410 001
// Date Written: 11/2/2016
// Description  Money Class header
// -----------
//I declare that the following source code was written solely by me.
//I understand that copying any source code, in whole or in part, 
// constitutes cheating, and that I will receive a zero on this project
// if I am found in violation of this policy.

//Money implementation file
#include "Money.h"
#include <iostream>
using namespace std;
Money::Money()
{
	dollars = 0;
	cents = 0;
}

Money::Money(int d, int c)
{
	dollars = d;
	cents = c;
}


int Money::getDollars() const
{
	return dollars;
}

int Money::getCents() const
{
	return cents;
}


void Money::setDollars(int d)
{
	dollars = d;
}

void Money::setCents(int c)
{
	cents = c;
}



Money Money::operator+(const Money& first)
{
	cout << cents;

	int firstDollars = first.getDollars();
	int firstCents = first.getCents();

	int newDollars = firstDollars + dollars;

	int newCents = firstCents + cents;

	const int dollarInCents = 100;
	if (newCents >= dollarInCents) {
		newDollars += 1;
		newCents -= dollarInCents;
	}
	
	Money newObj;
	newObj = Money(newDollars, newCents);

	return newObj;
}

Money Money::operator-(const Money& first)
{
	int firstDollars = first.getDollars();
	int firstCents = first.getCents();

	int newDollars = firstDollars - dollars;
	int newCents = firstCents - cents;

	const int dollarInCents = 100;
	if (first.getCents() < cents)
	{
		newDollars -= 1;
		newCents += dollarInCents;
	}

	if (newCents >= dollarInCents) {
		newDollars += 1;
		newCents -= dollarInCents;
	}

	Money newObj;
	newObj = Money(newDollars, newCents);

	return newObj;
}


